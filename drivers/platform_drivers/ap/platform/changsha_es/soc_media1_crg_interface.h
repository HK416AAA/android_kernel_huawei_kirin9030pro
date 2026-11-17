#ifndef __SOC_MEDIA1_CRG_INTERFACE_H__
#define __SOC_MEDIA1_CRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MEDIA1_CRG_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_MEDIA1_CRG_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_MEDIA1_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_MEDIA1_CRG_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_MEDIA1_CRG_PEREN1_ADDR(base) ((base) + (0x010UL))
#define SOC_MEDIA1_CRG_PERDIS1_ADDR(base) ((base) + (0x014UL))
#define SOC_MEDIA1_CRG_PERCLKEN1_ADDR(base) ((base) + (0x018UL))
#define SOC_MEDIA1_CRG_PERSTAT1_ADDR(base) ((base) + (0x01CUL))
#define SOC_MEDIA1_CRG_PERRSTEN0_ADDR(base) ((base) + (0x030UL))
#define SOC_MEDIA1_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x034UL))
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x038UL))
#define SOC_MEDIA1_CRG_PERRSTEN1_ADDR(base) ((base) + (0x040UL))
#define SOC_MEDIA1_CRG_PERRSTDIS1_ADDR(base) ((base) + (0x044UL))
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ADDR(base) ((base) + (0x048UL))
#define SOC_MEDIA1_CRG_CLKDIV0_ADDR(base) ((base) + (0x060UL))
#define SOC_MEDIA1_CRG_CLKDIV1_ADDR(base) ((base) + (0x064UL))
#define SOC_MEDIA1_CRG_CLKDIV2_ADDR(base) ((base) + (0x068UL))
#define SOC_MEDIA1_CRG_CLKDIV3_ADDR(base) ((base) + (0x06CUL))
#define SOC_MEDIA1_CRG_CLKDIV4_ADDR(base) ((base) + (0x070UL))
#define SOC_MEDIA1_CRG_CLKDIV5_ADDR(base) ((base) + (0x078UL))
#define SOC_MEDIA1_CRG_CLKDIV6_ADDR(base) ((base) + (0x07CUL))
#define SOC_MEDIA1_CRG_CLKDIV7_ADDR(base) ((base) + (0x080UL))
#define SOC_MEDIA1_CRG_CLKDIV8_ADDR(base) ((base) + (0x084UL))
#define SOC_MEDIA1_CRG_CLKDIV9_ADDR(base) ((base) + (0x088UL))
#define SOC_MEDIA1_CRG_PERI_STAT0_ADDR(base) ((base) + (0x0A0UL))
#define SOC_MEDIA1_CRG_PERI_STAT1_ADDR(base) ((base) + (0x0A4UL))
#define SOC_MEDIA1_CRG_PERI_STAT2_ADDR(base) ((base) + (0x0A8UL))
#define SOC_MEDIA1_CRG_DSS_DVFS_ADDR(base) ((base) + (0x100UL))
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_ADDR(base) ((base) + (0x104UL))
#define SOC_MEDIA1_CRG_IPCLKRST_BYPASS_ADDR(base) ((base) + (0x130UL))
#define SOC_MEDIA1_CRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x160UL))
#define SOC_MEDIA1_CRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x164UL))
#define SOC_MEDIA1_CRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x168UL))
#define SOC_MEDIA1_CRG_PERI_AUTODIV3_ADDR(base) ((base) + (0x16cUL))
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_ADDR(base) ((base) + (0x170UL))
#define SOC_MEDIA1_CRG_QIC_BUS_DSS_NOPENDING_GRP_BYPASS_ADDR(base) ((base) + (0x174UL))
#define SOC_MEDIA1_CRG_QIC_BUS_VDEC_NOPENDING_GRP_BYPASS_ADDR(base) ((base) + (0x178UL))
#define SOC_MEDIA1_CRG_QIC_BUS_VENC_NOPENDING_GRP_BYPASS_ADDR(base) ((base) + (0x17cUL))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_BYPASS_ADDR(base) ((base) + (0x180UL))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_BYPASS_ADDR(base) ((base) + (0x184UL))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_BYPASS_ADDR(base) ((base) + (0x188UL))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_BYPASS_ADDR(base) ((base) + (0x18CUL))
#define SOC_MEDIA1_CRG_PERI_AUTODIV5_ADDR(base) ((base) + (0x190UL))
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_ADDR(base) ((base) + (0x194UL))
#define SOC_MEDIA1_CRG_QIC_BUS_DSS_NOPENDING_GRP_DSS_AUTODIV_BYPASS_ADDR(base) ((base) + (0x198UL))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_DSS_AUTODIV_BYPASS_ADDR(base) ((base) + (0x19CUL))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_DSS_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1A0UL))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_DSS_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1A4UL))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_DSS_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1A8UL))
#define SOC_MEDIA1_CRG_QIC_BUS_AAE_NOPENDING_GRP_BYPASS_ADDR(base) ((base) + (0x1ACUL))
#define SOC_MEDIA1_CRG_PERI_AUTODIV7_ADDR(base) ((base) + (0x1B0UL))
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_ADDR(base) ((base) + (0x1B4UL))
#define SOC_MEDIA1_CRG_QIC_BUS_AAE_NOPENDING_GRP_AAE_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1B8UL))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_AAE_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1BCUL))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_AAE_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1C0UL))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_AAE_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1C4UL))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_AAE_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1C8UL))
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_ADDR(base) ((base) + (0x1CCUL))
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D0UL))
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D4UL))
#define SOC_MEDIA1_CRG_HPM_CFG_ADDR(base) ((base) + (0x200UL))
#define SOC_MEDIA1_CRG_HPM_READ_BACK_ADDR(base) ((base) + (0x204UL))
#define SOC_MEDIA1_CRG_HPMX_CFG_ADDR(base) ((base) + (0x208UL))
#define SOC_MEDIA1_CRG_HPMX_READ_BACK_ADDR(base) ((base) + (0x20CUL))
#define SOC_MEDIA1_CRG_WRAP_HPM0_CFG_ADDR(base) ((base) + (0x210UL))
#define SOC_MEDIA1_CRG_WRAP_HPM0_READ_BACK_ADDR(base) ((base) + (0x214UL))
#define SOC_MEDIA1_CRG_WRAP_HPMX0_CFG_ADDR(base) ((base) + (0x218UL))
#define SOC_MEDIA1_CRG_WRAP_HPMX0_READ_BACK_ADDR(base) ((base) + (0x21CUL))
#define SOC_MEDIA1_CRG_WRAP_HPM1_CFG_ADDR(base) ((base) + (0x220UL))
#define SOC_MEDIA1_CRG_WRAP_HPM1_READ_BACK_ADDR(base) ((base) + (0x224UL))
#define SOC_MEDIA1_CRG_WRAP_HPMX1_CFG_ADDR(base) ((base) + (0x228UL))
#define SOC_MEDIA1_CRG_WRAP_HPMX1_READ_BACK_ADDR(base) ((base) + (0x22CUL))
#define SOC_MEDIA1_CRG_VENC_DBG0_ADDR(base) ((base) + (0x300UL))
#define SOC_MEDIA1_CRG_VENC_DBG1_ADDR(base) ((base) + (0x304UL))
#define SOC_MEDIA1_CRG_VENC_DBG2_ADDR(base) ((base) + (0x308UL))
#define SOC_MEDIA1_CRG_VENC_DBG3_ADDR(base) ((base) + (0x30CUL))
#define SOC_MEDIA1_CRG_VDEC_IDLE_READ_BACK_ADDR(base) ((base) + (0x400UL))
#define SOC_MEDIA1_CRG_VENC_IDLE_READ_BACK_ADDR(base) ((base) + (0x404UL))
#define SOC_MEDIA1_CRG_HIMINIBUS_DLOCK_CLR_ADDR(base) ((base) + (0x408UL))
#define SOC_MEDIA1_CRG_VENC_CKG_EN_ADDR(base) ((base) + (0x500UL))
#define SOC_MEDIA1_CRG_VDEC_CLK_EN_ADDR(base) ((base) + (0x600UL))
#define SOC_MEDIA1_CRG_DECPROT0SET_ADDR(base) ((base) + (0xF00UL))
#else
#define SOC_MEDIA1_CRG_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_MEDIA1_CRG_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_MEDIA1_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_MEDIA1_CRG_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_MEDIA1_CRG_PEREN1_ADDR(base) ((base) + (0x010))
#define SOC_MEDIA1_CRG_PERDIS1_ADDR(base) ((base) + (0x014))
#define SOC_MEDIA1_CRG_PERCLKEN1_ADDR(base) ((base) + (0x018))
#define SOC_MEDIA1_CRG_PERSTAT1_ADDR(base) ((base) + (0x01C))
#define SOC_MEDIA1_CRG_PERRSTEN0_ADDR(base) ((base) + (0x030))
#define SOC_MEDIA1_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x034))
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x038))
#define SOC_MEDIA1_CRG_PERRSTEN1_ADDR(base) ((base) + (0x040))
#define SOC_MEDIA1_CRG_PERRSTDIS1_ADDR(base) ((base) + (0x044))
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ADDR(base) ((base) + (0x048))
#define SOC_MEDIA1_CRG_CLKDIV0_ADDR(base) ((base) + (0x060))
#define SOC_MEDIA1_CRG_CLKDIV1_ADDR(base) ((base) + (0x064))
#define SOC_MEDIA1_CRG_CLKDIV2_ADDR(base) ((base) + (0x068))
#define SOC_MEDIA1_CRG_CLKDIV3_ADDR(base) ((base) + (0x06C))
#define SOC_MEDIA1_CRG_CLKDIV4_ADDR(base) ((base) + (0x070))
#define SOC_MEDIA1_CRG_CLKDIV5_ADDR(base) ((base) + (0x078))
#define SOC_MEDIA1_CRG_CLKDIV6_ADDR(base) ((base) + (0x07C))
#define SOC_MEDIA1_CRG_CLKDIV7_ADDR(base) ((base) + (0x080))
#define SOC_MEDIA1_CRG_CLKDIV8_ADDR(base) ((base) + (0x084))
#define SOC_MEDIA1_CRG_CLKDIV9_ADDR(base) ((base) + (0x088))
#define SOC_MEDIA1_CRG_PERI_STAT0_ADDR(base) ((base) + (0x0A0))
#define SOC_MEDIA1_CRG_PERI_STAT1_ADDR(base) ((base) + (0x0A4))
#define SOC_MEDIA1_CRG_PERI_STAT2_ADDR(base) ((base) + (0x0A8))
#define SOC_MEDIA1_CRG_DSS_DVFS_ADDR(base) ((base) + (0x100))
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_ADDR(base) ((base) + (0x104))
#define SOC_MEDIA1_CRG_IPCLKRST_BYPASS_ADDR(base) ((base) + (0x130))
#define SOC_MEDIA1_CRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x160))
#define SOC_MEDIA1_CRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x164))
#define SOC_MEDIA1_CRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x168))
#define SOC_MEDIA1_CRG_PERI_AUTODIV3_ADDR(base) ((base) + (0x16c))
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_ADDR(base) ((base) + (0x170))
#define SOC_MEDIA1_CRG_QIC_BUS_DSS_NOPENDING_GRP_BYPASS_ADDR(base) ((base) + (0x174))
#define SOC_MEDIA1_CRG_QIC_BUS_VDEC_NOPENDING_GRP_BYPASS_ADDR(base) ((base) + (0x178))
#define SOC_MEDIA1_CRG_QIC_BUS_VENC_NOPENDING_GRP_BYPASS_ADDR(base) ((base) + (0x17c))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_BYPASS_ADDR(base) ((base) + (0x180))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_BYPASS_ADDR(base) ((base) + (0x184))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_BYPASS_ADDR(base) ((base) + (0x188))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_BYPASS_ADDR(base) ((base) + (0x18C))
#define SOC_MEDIA1_CRG_PERI_AUTODIV5_ADDR(base) ((base) + (0x190))
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_ADDR(base) ((base) + (0x194))
#define SOC_MEDIA1_CRG_QIC_BUS_DSS_NOPENDING_GRP_DSS_AUTODIV_BYPASS_ADDR(base) ((base) + (0x198))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_DSS_AUTODIV_BYPASS_ADDR(base) ((base) + (0x19C))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_DSS_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1A0))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_DSS_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1A4))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_DSS_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1A8))
#define SOC_MEDIA1_CRG_QIC_BUS_AAE_NOPENDING_GRP_BYPASS_ADDR(base) ((base) + (0x1AC))
#define SOC_MEDIA1_CRG_PERI_AUTODIV7_ADDR(base) ((base) + (0x1B0))
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_ADDR(base) ((base) + (0x1B4))
#define SOC_MEDIA1_CRG_QIC_BUS_AAE_NOPENDING_GRP_AAE_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1B8))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_AAE_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1BC))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_AAE_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1C0))
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_AAE_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1C4))
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_AAE_AUTODIV_BYPASS_ADDR(base) ((base) + (0x1C8))
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_ADDR(base) ((base) + (0x1CC))
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D0))
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D4))
#define SOC_MEDIA1_CRG_HPM_CFG_ADDR(base) ((base) + (0x200))
#define SOC_MEDIA1_CRG_HPM_READ_BACK_ADDR(base) ((base) + (0x204))
#define SOC_MEDIA1_CRG_HPMX_CFG_ADDR(base) ((base) + (0x208))
#define SOC_MEDIA1_CRG_HPMX_READ_BACK_ADDR(base) ((base) + (0x20C))
#define SOC_MEDIA1_CRG_WRAP_HPM0_CFG_ADDR(base) ((base) + (0x210))
#define SOC_MEDIA1_CRG_WRAP_HPM0_READ_BACK_ADDR(base) ((base) + (0x214))
#define SOC_MEDIA1_CRG_WRAP_HPMX0_CFG_ADDR(base) ((base) + (0x218))
#define SOC_MEDIA1_CRG_WRAP_HPMX0_READ_BACK_ADDR(base) ((base) + (0x21C))
#define SOC_MEDIA1_CRG_WRAP_HPM1_CFG_ADDR(base) ((base) + (0x220))
#define SOC_MEDIA1_CRG_WRAP_HPM1_READ_BACK_ADDR(base) ((base) + (0x224))
#define SOC_MEDIA1_CRG_WRAP_HPMX1_CFG_ADDR(base) ((base) + (0x228))
#define SOC_MEDIA1_CRG_WRAP_HPMX1_READ_BACK_ADDR(base) ((base) + (0x22C))
#define SOC_MEDIA1_CRG_VENC_DBG0_ADDR(base) ((base) + (0x300))
#define SOC_MEDIA1_CRG_VENC_DBG1_ADDR(base) ((base) + (0x304))
#define SOC_MEDIA1_CRG_VENC_DBG2_ADDR(base) ((base) + (0x308))
#define SOC_MEDIA1_CRG_VENC_DBG3_ADDR(base) ((base) + (0x30C))
#define SOC_MEDIA1_CRG_VDEC_IDLE_READ_BACK_ADDR(base) ((base) + (0x400))
#define SOC_MEDIA1_CRG_VENC_IDLE_READ_BACK_ADDR(base) ((base) + (0x404))
#define SOC_MEDIA1_CRG_HIMINIBUS_DLOCK_CLR_ADDR(base) ((base) + (0x408))
#define SOC_MEDIA1_CRG_VENC_CKG_EN_ADDR(base) ((base) + (0x500))
#define SOC_MEDIA1_CRG_VDEC_CLK_EN_ADDR(base) ((base) + (0x600))
#define SOC_MEDIA1_CRG_DECPROT0SET_ADDR(base) ((base) + (0xF00))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_aclk_vdec : 1;
        unsigned int gt_pclk_vdec : 1;
        unsigned int gt_clk_vdec : 1;
        unsigned int gt_clk_vdec_sys : 1;
        unsigned int gt_clk_vdec_pxpc : 1;
        unsigned int gt_clk_venc_sys : 1;
        unsigned int gt_aclk_venc : 1;
        unsigned int gt_pclk_venc : 1;
        unsigned int gt_clk_venc : 1;
        unsigned int gt_clk_qic_m1 : 1;
        unsigned int gt_aclk_tcu_m1 : 1;
        unsigned int gt_clk_qice_data : 1;
        unsigned int gt_clk_qic_dss_data : 1;
        unsigned int gt_clk_dss_core_part : 1;
        unsigned int gt_clk_dss_core_disp1_div3 : 1;
        unsigned int gt_clk_dss_core_disp1 : 1;
        unsigned int gt_clk_dss_core_disp0_div3 : 1;
        unsigned int gt_clk_dss_core_disp0 : 1;
        unsigned int gt_clk_vivobus_disp_ini : 1;
        unsigned int gt_clk_dss_tcxo : 1;
        unsigned int gt_pclk_dbg_cs : 1;
        unsigned int gt_pclk_atgm_vdec : 1;
        unsigned int gt_pclk_atgm_dss : 1;
        unsigned int gt_clk_dss_dti_brg_ini : 1;
        unsigned int gt_clk_dss_dti_brg : 1;
        unsigned int gt_pclk_atgm_venc : 1;
        unsigned int gt_pclk_tcu : 1;
        unsigned int gt_clk_aclk_vcodec_tcu : 1;
        unsigned int gt_clk_cfgbus_media1_wrap : 1;
        unsigned int gt_clk_dss_occ_root : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_MEDIA1_CRG_PEREN0_UNION;
#endif
#define SOC_MEDIA1_CRG_PEREN0_gt_aclk_vdec_START (0)
#define SOC_MEDIA1_CRG_PEREN0_gt_aclk_vdec_END (0)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_vdec_START (1)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_vdec_END (1)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_vdec_START (2)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_vdec_END (2)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_vdec_sys_START (3)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_vdec_sys_END (3)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_vdec_pxpc_START (4)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_vdec_pxpc_END (4)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_venc_sys_START (5)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_venc_sys_END (5)
#define SOC_MEDIA1_CRG_PEREN0_gt_aclk_venc_START (6)
#define SOC_MEDIA1_CRG_PEREN0_gt_aclk_venc_END (6)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_venc_START (7)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_venc_END (7)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_venc_START (8)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_venc_END (8)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_qic_m1_START (9)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_qic_m1_END (9)
#define SOC_MEDIA1_CRG_PEREN0_gt_aclk_tcu_m1_START (10)
#define SOC_MEDIA1_CRG_PEREN0_gt_aclk_tcu_m1_END (10)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_qice_data_START (11)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_qice_data_END (11)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_qic_dss_data_START (12)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_qic_dss_data_END (12)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_core_part_START (13)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_core_part_END (13)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_core_disp1_div3_START (14)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_core_disp1_div3_END (14)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_core_disp1_START (15)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_core_disp1_END (15)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_core_disp0_div3_START (16)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_core_disp0_div3_END (16)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_core_disp0_START (17)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_core_disp0_END (17)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_vivobus_disp_ini_START (18)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_vivobus_disp_ini_END (18)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_tcxo_START (19)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_tcxo_END (19)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_dbg_cs_START (20)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_dbg_cs_END (20)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_atgm_vdec_START (21)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_atgm_vdec_END (21)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_atgm_dss_START (22)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_atgm_dss_END (22)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_dti_brg_ini_START (23)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_dti_brg_ini_END (23)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_dti_brg_START (24)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_dti_brg_END (24)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_atgm_venc_START (25)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_atgm_venc_END (25)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_tcu_START (26)
#define SOC_MEDIA1_CRG_PEREN0_gt_pclk_tcu_END (26)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_aclk_vcodec_tcu_START (27)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_aclk_vcodec_tcu_END (27)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_cfgbus_media1_wrap_START (28)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_cfgbus_media1_wrap_END (28)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_occ_root_START (29)
#define SOC_MEDIA1_CRG_PEREN0_gt_clk_dss_occ_root_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_aclk_vdec : 1;
        unsigned int gt_pclk_vdec : 1;
        unsigned int gt_clk_vdec : 1;
        unsigned int gt_clk_vdec_tcxo : 1;
        unsigned int gt_clk_vdec_pxpc : 1;
        unsigned int gt_clk_venc_tcxo : 1;
        unsigned int gt_aclk_venc : 1;
        unsigned int gt_pclk_venc : 1;
        unsigned int gt_clk_venc : 1;
        unsigned int gt_clk_qic_m1 : 1;
        unsigned int gt_aclk_tcu_m1 : 1;
        unsigned int gt_clk_qice_data : 1;
        unsigned int gt_clk_qic_dss_data : 1;
        unsigned int gt_clk_dss_core_part : 1;
        unsigned int gt_clk_dss_core_disp1_div3 : 1;
        unsigned int gt_clk_dss_core_disp1 : 1;
        unsigned int gt_clk_dss_core_disp0_div3 : 1;
        unsigned int gt_clk_dss_core_disp0 : 1;
        unsigned int gt_clk_vivobus_disp_ini : 1;
        unsigned int gt_clk_dss_tcxo : 1;
        unsigned int gt_pclk_dbg_cs : 1;
        unsigned int gt_pclk_atgm_vdec : 1;
        unsigned int gt_pclk_atgm_dss : 1;
        unsigned int gt_clk_dss_dti_brg_ini : 1;
        unsigned int gt_clk_dss_dti_brg : 1;
        unsigned int gt_pclk_atgm_venc : 1;
        unsigned int gt_pclk_tcu : 1;
        unsigned int gt_clk_aclk_vcodec_tcu : 1;
        unsigned int gt_clk_cfgbus_media1_wrap : 1;
        unsigned int gt_clk_dss_occ_root : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_MEDIA1_CRG_PERDIS0_UNION;
#endif
#define SOC_MEDIA1_CRG_PERDIS0_gt_aclk_vdec_START (0)
#define SOC_MEDIA1_CRG_PERDIS0_gt_aclk_vdec_END (0)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_vdec_START (1)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_vdec_END (1)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_vdec_START (2)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_vdec_END (2)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_vdec_tcxo_START (3)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_vdec_tcxo_END (3)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_vdec_pxpc_START (4)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_vdec_pxpc_END (4)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_venc_tcxo_START (5)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_venc_tcxo_END (5)
#define SOC_MEDIA1_CRG_PERDIS0_gt_aclk_venc_START (6)
#define SOC_MEDIA1_CRG_PERDIS0_gt_aclk_venc_END (6)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_venc_START (7)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_venc_END (7)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_venc_START (8)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_venc_END (8)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_qic_m1_START (9)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_qic_m1_END (9)
#define SOC_MEDIA1_CRG_PERDIS0_gt_aclk_tcu_m1_START (10)
#define SOC_MEDIA1_CRG_PERDIS0_gt_aclk_tcu_m1_END (10)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_qice_data_START (11)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_qice_data_END (11)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_qic_dss_data_START (12)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_qic_dss_data_END (12)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_core_part_START (13)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_core_part_END (13)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_core_disp1_div3_START (14)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_core_disp1_div3_END (14)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_core_disp1_START (15)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_core_disp1_END (15)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_core_disp0_div3_START (16)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_core_disp0_div3_END (16)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_core_disp0_START (17)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_core_disp0_END (17)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_vivobus_disp_ini_START (18)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_vivobus_disp_ini_END (18)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_tcxo_START (19)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_tcxo_END (19)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_dbg_cs_START (20)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_dbg_cs_END (20)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_atgm_vdec_START (21)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_atgm_vdec_END (21)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_atgm_dss_START (22)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_atgm_dss_END (22)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_dti_brg_ini_START (23)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_dti_brg_ini_END (23)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_dti_brg_START (24)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_dti_brg_END (24)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_atgm_venc_START (25)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_atgm_venc_END (25)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_tcu_START (26)
#define SOC_MEDIA1_CRG_PERDIS0_gt_pclk_tcu_END (26)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_aclk_vcodec_tcu_START (27)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_aclk_vcodec_tcu_END (27)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_cfgbus_media1_wrap_START (28)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_cfgbus_media1_wrap_END (28)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_occ_root_START (29)
#define SOC_MEDIA1_CRG_PERDIS0_gt_clk_dss_occ_root_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_aclk_vdec : 1;
        unsigned int gt_pclk_vdec : 1;
        unsigned int gt_clk_vdec : 1;
        unsigned int gt_clk_vdec_tcxo : 1;
        unsigned int gt_clk_vdec_pxpc : 1;
        unsigned int gt_clk_venc_tcxo : 1;
        unsigned int gt_aclk_venc : 1;
        unsigned int gt_pclk_venc : 1;
        unsigned int gt_clk_venc : 1;
        unsigned int gt_clk_qic_m1 : 1;
        unsigned int gt_aclk_tcu_m1 : 1;
        unsigned int gt_clk_qice_data : 1;
        unsigned int gt_clk_qic_dss_data : 1;
        unsigned int gt_clk_dss_core_part : 1;
        unsigned int gt_clk_dss_core_disp1_div3 : 1;
        unsigned int gt_clk_dss_core_disp1 : 1;
        unsigned int gt_clk_dss_core_disp0_div3 : 1;
        unsigned int gt_clk_dss_core_disp0 : 1;
        unsigned int gt_clk_vivobus_disp_ini : 1;
        unsigned int gt_clk_dss_tcxo : 1;
        unsigned int gt_pclk_dbg_cs : 1;
        unsigned int gt_pclk_atgm_vdec : 1;
        unsigned int gt_pclk_atgm_dss : 1;
        unsigned int gt_clk_dss_dti_brg_ini : 1;
        unsigned int gt_clk_dss_dti_brg : 1;
        unsigned int gt_pclk_atgm_venc : 1;
        unsigned int gt_pclk_tcu : 1;
        unsigned int gt_clk_aclk_vcodec_tcu : 1;
        unsigned int gt_clk_cfgbus_media1_wrap : 1;
        unsigned int gt_clk_dss_occ_root : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_MEDIA1_CRG_PERCLKEN0_UNION;
#endif
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_aclk_vdec_START (0)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_aclk_vdec_END (0)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_vdec_START (1)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_vdec_END (1)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_vdec_START (2)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_vdec_END (2)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_vdec_tcxo_START (3)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_vdec_tcxo_END (3)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_vdec_pxpc_START (4)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_vdec_pxpc_END (4)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_venc_tcxo_START (5)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_venc_tcxo_END (5)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_aclk_venc_START (6)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_aclk_venc_END (6)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_venc_START (7)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_venc_END (7)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_venc_START (8)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_venc_END (8)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_qic_m1_START (9)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_qic_m1_END (9)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_aclk_tcu_m1_START (10)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_aclk_tcu_m1_END (10)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_qice_data_START (11)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_qice_data_END (11)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_qic_dss_data_START (12)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_qic_dss_data_END (12)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_core_part_START (13)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_core_part_END (13)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_core_disp1_div3_START (14)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_core_disp1_div3_END (14)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_core_disp1_START (15)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_core_disp1_END (15)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_core_disp0_div3_START (16)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_core_disp0_div3_END (16)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_core_disp0_START (17)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_core_disp0_END (17)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_vivobus_disp_ini_START (18)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_vivobus_disp_ini_END (18)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_tcxo_START (19)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_tcxo_END (19)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_dbg_cs_START (20)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_dbg_cs_END (20)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_atgm_vdec_START (21)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_atgm_vdec_END (21)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_atgm_dss_START (22)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_atgm_dss_END (22)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_dti_brg_ini_START (23)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_dti_brg_ini_END (23)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_dti_brg_START (24)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_dti_brg_END (24)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_atgm_venc_START (25)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_atgm_venc_END (25)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_tcu_START (26)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_pclk_tcu_END (26)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_aclk_vcodec_tcu_START (27)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_aclk_vcodec_tcu_END (27)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_cfgbus_media1_wrap_START (28)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_cfgbus_media1_wrap_END (28)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_occ_root_START (29)
#define SOC_MEDIA1_CRG_PERCLKEN0_gt_clk_dss_occ_root_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_aclk_vdec : 1;
        unsigned int st_pclk_vdec : 1;
        unsigned int st_clk_vdec : 1;
        unsigned int st_clk_vdec_tcxo : 1;
        unsigned int st_clk_vdec_pxpc : 1;
        unsigned int st_clk_venc_tcxo : 1;
        unsigned int st_aclk_venc : 1;
        unsigned int st_pclk_venc : 1;
        unsigned int st_clk_venc : 1;
        unsigned int st_clk_qic_m1 : 1;
        unsigned int st_aclk_tcu_m1 : 1;
        unsigned int st_clk_qice_data : 1;
        unsigned int st_clk_qic_dss_data : 1;
        unsigned int st_clk_dss_core_part : 1;
        unsigned int st_clk_dss_core_disp1_div3 : 1;
        unsigned int st_clk_dss_core_disp1 : 1;
        unsigned int st_clk_dss_core_disp0_div3 : 1;
        unsigned int st_clk_dss_core_disp0 : 1;
        unsigned int st_clk_vivobus_disp_ini : 1;
        unsigned int st_clk_dss_tcxo : 1;
        unsigned int st_pclk_dbg_cs : 1;
        unsigned int st_pclk_atgm_vdec : 1;
        unsigned int st_pclk_atgm_dss : 1;
        unsigned int st_clk_dss_dti_brg_ini : 1;
        unsigned int st_clk_dss_dti_brg : 1;
        unsigned int st_pclk_atgm_venc : 1;
        unsigned int st_pclk_tcu : 1;
        unsigned int st_clk_aclk_vcodec_tcu : 1;
        unsigned int st_clk_cfgbus_media1_wrap : 1;
        unsigned int st_clk_dss_occ_root : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_MEDIA1_CRG_PERSTAT0_UNION;
#endif
#define SOC_MEDIA1_CRG_PERSTAT0_st_aclk_vdec_START (0)
#define SOC_MEDIA1_CRG_PERSTAT0_st_aclk_vdec_END (0)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_vdec_START (1)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_vdec_END (1)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_vdec_START (2)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_vdec_END (2)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_vdec_tcxo_START (3)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_vdec_tcxo_END (3)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_vdec_pxpc_START (4)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_vdec_pxpc_END (4)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_venc_tcxo_START (5)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_venc_tcxo_END (5)
#define SOC_MEDIA1_CRG_PERSTAT0_st_aclk_venc_START (6)
#define SOC_MEDIA1_CRG_PERSTAT0_st_aclk_venc_END (6)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_venc_START (7)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_venc_END (7)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_venc_START (8)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_venc_END (8)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_qic_m1_START (9)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_qic_m1_END (9)
#define SOC_MEDIA1_CRG_PERSTAT0_st_aclk_tcu_m1_START (10)
#define SOC_MEDIA1_CRG_PERSTAT0_st_aclk_tcu_m1_END (10)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_qice_data_START (11)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_qice_data_END (11)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_qic_dss_data_START (12)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_qic_dss_data_END (12)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_core_part_START (13)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_core_part_END (13)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_core_disp1_div3_START (14)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_core_disp1_div3_END (14)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_core_disp1_START (15)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_core_disp1_END (15)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_core_disp0_div3_START (16)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_core_disp0_div3_END (16)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_core_disp0_START (17)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_core_disp0_END (17)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_vivobus_disp_ini_START (18)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_vivobus_disp_ini_END (18)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_tcxo_START (19)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_tcxo_END (19)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_dbg_cs_START (20)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_dbg_cs_END (20)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_atgm_vdec_START (21)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_atgm_vdec_END (21)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_atgm_dss_START (22)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_atgm_dss_END (22)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_dti_brg_ini_START (23)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_dti_brg_ini_END (23)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_dti_brg_START (24)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_dti_brg_END (24)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_atgm_venc_START (25)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_atgm_venc_END (25)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_tcu_START (26)
#define SOC_MEDIA1_CRG_PERSTAT0_st_pclk_tcu_END (26)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_aclk_vcodec_tcu_START (27)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_aclk_vcodec_tcu_END (27)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_cfgbus_media1_wrap_START (28)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_cfgbus_media1_wrap_END (28)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_occ_root_START (29)
#define SOC_MEDIA1_CRG_PERSTAT0_st_clk_dss_occ_root_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_hpm : 1;
        unsigned int gt_pclk_autodiv_aclk_vcodec_tcu : 1;
        unsigned int gt_pclk_autodiv_vdec : 1;
        unsigned int gt_pclk_autodiv_venc : 1;
        unsigned int gt_pclk_autodiv_dss : 1;
        unsigned int gt_pclk_atgm_aae : 1;
        unsigned int gt_clk_aae_tcxo : 1;
        unsigned int gt_clk_aae_core : 1;
        unsigned int gt_clk_media1_lbist0 : 1;
        unsigned int gt_clk_media1_lbist1 : 1;
        unsigned int gt_pclk_media1_lbist0 : 1;
        unsigned int gt_pclk_media1_lbist1 : 1;
        unsigned int gt_clk_aae_dti_brg_ini : 1;
        unsigned int gt_clk_aae_dti_brg : 1;
        unsigned int gt_pclk_autodiv_aae : 1;
        unsigned int gt_clk_aae_qic : 1;
        unsigned int gt_clk_aae_part1 : 1;
        unsigned int gt_clk_aae_top : 1;
        unsigned int gt_clk_wrap_hpm : 1;
        unsigned int gt_clk_lat_mon_dss : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MEDIA1_CRG_PEREN1_UNION;
#endif
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_hpm_START (0)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_hpm_END (0)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_autodiv_aclk_vcodec_tcu_START (1)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_autodiv_aclk_vcodec_tcu_END (1)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_autodiv_vdec_START (2)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_autodiv_vdec_END (2)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_autodiv_venc_START (3)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_autodiv_venc_END (3)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_autodiv_dss_START (4)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_autodiv_dss_END (4)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_atgm_aae_START (5)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_atgm_aae_END (5)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_tcxo_START (6)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_tcxo_END (6)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_core_START (7)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_core_END (7)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_media1_lbist0_START (8)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_media1_lbist0_END (8)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_media1_lbist1_START (9)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_media1_lbist1_END (9)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_media1_lbist0_START (10)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_media1_lbist0_END (10)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_media1_lbist1_START (11)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_media1_lbist1_END (11)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_dti_brg_ini_START (12)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_dti_brg_ini_END (12)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_dti_brg_START (13)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_dti_brg_END (13)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_autodiv_aae_START (14)
#define SOC_MEDIA1_CRG_PEREN1_gt_pclk_autodiv_aae_END (14)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_qic_START (15)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_qic_END (15)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_part1_START (16)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_part1_END (16)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_top_START (17)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_aae_top_END (17)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_wrap_hpm_START (18)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_wrap_hpm_END (18)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_lat_mon_dss_START (19)
#define SOC_MEDIA1_CRG_PEREN1_gt_clk_lat_mon_dss_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_hpm : 1;
        unsigned int gt_pclk_autodiv_aclk_vcodec_tcu : 1;
        unsigned int gt_pclk_autodiv_vdec : 1;
        unsigned int gt_pclk_autodiv_venc : 1;
        unsigned int gt_pclk_autodiv_dss : 1;
        unsigned int gt_pclk_atgm_aae : 1;
        unsigned int gt_clk_aae_tcxo : 1;
        unsigned int gt_clk_aae_core : 1;
        unsigned int gt_clk_media1_lbist0 : 1;
        unsigned int gt_clk_media1_lbist1 : 1;
        unsigned int gt_pclk_media1_lbist0 : 1;
        unsigned int gt_pclk_media1_lbist1 : 1;
        unsigned int gt_clk_aae_dti_brg_ini : 1;
        unsigned int gt_clk_aae_dti_brg : 1;
        unsigned int gt_pclk_autodiv_aae : 1;
        unsigned int gt_clk_aae_qic : 1;
        unsigned int gt_clk_aae_part1 : 1;
        unsigned int gt_clk_aae_top : 1;
        unsigned int gt_clk_wrap_hpm : 1;
        unsigned int gt_clk_lat_mon_dss : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MEDIA1_CRG_PERDIS1_UNION;
#endif
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_hpm_START (0)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_hpm_END (0)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_autodiv_aclk_vcodec_tcu_START (1)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_autodiv_aclk_vcodec_tcu_END (1)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_autodiv_vdec_START (2)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_autodiv_vdec_END (2)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_autodiv_venc_START (3)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_autodiv_venc_END (3)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_autodiv_dss_START (4)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_autodiv_dss_END (4)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_atgm_aae_START (5)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_atgm_aae_END (5)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_tcxo_START (6)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_tcxo_END (6)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_core_START (7)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_core_END (7)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_media1_lbist0_START (8)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_media1_lbist0_END (8)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_media1_lbist1_START (9)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_media1_lbist1_END (9)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_media1_lbist0_START (10)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_media1_lbist0_END (10)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_media1_lbist1_START (11)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_media1_lbist1_END (11)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_dti_brg_ini_START (12)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_dti_brg_ini_END (12)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_dti_brg_START (13)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_dti_brg_END (13)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_autodiv_aae_START (14)
#define SOC_MEDIA1_CRG_PERDIS1_gt_pclk_autodiv_aae_END (14)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_qic_START (15)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_qic_END (15)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_part1_START (16)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_part1_END (16)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_top_START (17)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_aae_top_END (17)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_wrap_hpm_START (18)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_wrap_hpm_END (18)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_lat_mon_dss_START (19)
#define SOC_MEDIA1_CRG_PERDIS1_gt_clk_lat_mon_dss_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_hpm : 1;
        unsigned int gt_pclk_autodiv_aclk_vcodec_tcu : 1;
        unsigned int gt_pclk_autodiv_vdec : 1;
        unsigned int gt_pclk_autodiv_venc : 1;
        unsigned int gt_pclk_autodiv_dss : 1;
        unsigned int gt_pclk_atgm_aae : 1;
        unsigned int gt_clk_aae_tcxo : 1;
        unsigned int gt_clk_aae_core : 1;
        unsigned int gt_clk_media1_lbist0 : 1;
        unsigned int gt_clk_media1_lbist1 : 1;
        unsigned int gt_pclk_media1_lbist0 : 1;
        unsigned int gt_pclk_media1_lbist1 : 1;
        unsigned int gt_clk_aae_dti_brg_ini : 1;
        unsigned int gt_clk_aae_dti_brg : 1;
        unsigned int gt_pclk_autodiv_aae : 1;
        unsigned int gt_clk_aae_qic : 1;
        unsigned int gt_clk_aae_part1 : 1;
        unsigned int gt_clk_aae_top : 1;
        unsigned int gt_clk_wrap_hpm : 1;
        unsigned int gt_clk_lat_mon_dss : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MEDIA1_CRG_PERCLKEN1_UNION;
#endif
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_hpm_START (0)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_hpm_END (0)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_aclk_vcodec_tcu_START (1)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_aclk_vcodec_tcu_END (1)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_vdec_START (2)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_vdec_END (2)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_venc_START (3)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_venc_END (3)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_dss_START (4)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_dss_END (4)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_atgm_aae_START (5)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_atgm_aae_END (5)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_tcxo_START (6)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_tcxo_END (6)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_core_START (7)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_core_END (7)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_media1_lbist0_START (8)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_media1_lbist0_END (8)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_media1_lbist1_START (9)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_media1_lbist1_END (9)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_media1_lbist0_START (10)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_media1_lbist0_END (10)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_media1_lbist1_START (11)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_media1_lbist1_END (11)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_dti_brg_ini_START (12)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_dti_brg_ini_END (12)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_dti_brg_START (13)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_dti_brg_END (13)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_aae_START (14)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_aae_END (14)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_qic_START (15)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_qic_END (15)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_part1_START (16)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_part1_END (16)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_top_START (17)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_top_END (17)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_wrap_hpm_START (18)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_wrap_hpm_END (18)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_lat_mon_dss_START (19)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_lat_mon_dss_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_hpm : 1;
        unsigned int st_pclk_autodiv_aclk_vcodec_tcu : 1;
        unsigned int st_pclk_autodiv_vdec : 1;
        unsigned int st_pclk_autodiv_venc : 1;
        unsigned int st_pclk_autodiv_dss : 1;
        unsigned int st_pclk_atgm_aae : 1;
        unsigned int st_clk_aae_tcxo : 1;
        unsigned int st_clk_aae_core : 1;
        unsigned int st_clk_media1_lbist0 : 1;
        unsigned int st_clk_media1_lbist1 : 1;
        unsigned int st_pclk_media1_lbist0 : 1;
        unsigned int st_pclk_media1_lbist1 : 1;
        unsigned int st_clk_aae_dti_brg_ini : 1;
        unsigned int st_clk_aae_dti_brg : 1;
        unsigned int st_pclk_autodiv_aae : 1;
        unsigned int st_clk_aae_qic : 1;
        unsigned int st_clk_aae_part1 : 1;
        unsigned int st_clk_aae_top : 1;
        unsigned int st_clk_wrap_hpm : 1;
        unsigned int st_clk_lat_mon_dss : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MEDIA1_CRG_PERSTAT1_UNION;
#endif
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_hpm_START (0)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_hpm_END (0)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_autodiv_aclk_vcodec_tcu_START (1)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_autodiv_aclk_vcodec_tcu_END (1)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_autodiv_vdec_START (2)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_autodiv_vdec_END (2)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_autodiv_venc_START (3)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_autodiv_venc_END (3)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_autodiv_dss_START (4)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_autodiv_dss_END (4)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_atgm_aae_START (5)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_atgm_aae_END (5)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_tcxo_START (6)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_tcxo_END (6)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_core_START (7)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_core_END (7)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_media1_lbist0_START (8)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_media1_lbist0_END (8)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_media1_lbist1_START (9)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_media1_lbist1_END (9)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_media1_lbist0_START (10)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_media1_lbist0_END (10)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_media1_lbist1_START (11)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_media1_lbist1_END (11)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_dti_brg_ini_START (12)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_dti_brg_ini_END (12)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_dti_brg_START (13)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_dti_brg_END (13)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_autodiv_aae_START (14)
#define SOC_MEDIA1_CRG_PERSTAT1_st_pclk_autodiv_aae_END (14)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_qic_START (15)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_qic_END (15)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_part1_START (16)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_part1_END (16)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_top_START (17)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_aae_top_END (17)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_wrap_hpm_START (18)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_wrap_hpm_END (18)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_lat_mon_dss_START (19)
#define SOC_MEDIA1_CRG_PERSTAT1_st_clk_lat_mon_dss_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_dss_crg : 1;
        unsigned int ip_rst_dss : 1;
        unsigned int ip_prst_atgm_dss : 1;
        unsigned int ip_prst_atgm_vdec : 1;
        unsigned int ip_rst_tcu_m1 : 1;
        unsigned int ip_prst_apb_brg_tcu : 1;
        unsigned int ip_rst_vdec_pxpc : 1;
        unsigned int ip_rst_vdec : 1;
        unsigned int ip_arst_vdec : 1;
        unsigned int ip_prst_vdec : 1;
        unsigned int ip_prst_atgm_venc : 1;
        unsigned int ip_rst_dss_disp1_crg : 1;
        unsigned int ip_rst_dss_disp1 : 1;
        unsigned int ip_rst_media_qic_data : 1;
        unsigned int ip_rst_qice_data : 1;
        unsigned int ip_rst_cs_vdec : 1;
        unsigned int ip_rst_cs_venc : 1;
        unsigned int ip_rst_venc : 1;
        unsigned int ip_prst_venc : 1;
        unsigned int ip_arst_venc : 1;
        unsigned int ip_rst_hpm : 1;
        unsigned int ip_rst_dbg_cs : 1;
        unsigned int ip_rst_qic_dss : 1;
        unsigned int ip_rst_media1_wrap_crg : 1;
        unsigned int ip_rst_cs_dss : 1;
        unsigned int ip_rst_cs_aae : 1;
        unsigned int ip_rst_wrap_hpm0 : 1;
        unsigned int ip_rst_wrap_hpm1 : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_MEDIA1_CRG_PERRSTEN0_UNION;
#endif
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_dss_crg_START (0)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_dss_crg_END (0)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_dss_START (1)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_dss_END (1)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_atgm_dss_START (2)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_atgm_dss_END (2)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_atgm_vdec_START (3)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_atgm_vdec_END (3)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_tcu_m1_START (4)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_tcu_m1_END (4)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_apb_brg_tcu_START (5)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_apb_brg_tcu_END (5)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_vdec_pxpc_START (6)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_vdec_pxpc_END (6)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_vdec_START (7)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_vdec_END (7)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_arst_vdec_START (8)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_arst_vdec_END (8)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_vdec_START (9)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_vdec_END (9)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_atgm_venc_START (10)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_atgm_venc_END (10)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_dss_disp1_crg_START (11)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_dss_disp1_crg_END (11)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_dss_disp1_START (12)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_dss_disp1_END (12)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_media_qic_data_START (13)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_media_qic_data_END (13)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_qice_data_START (14)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_qice_data_END (14)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_cs_vdec_START (15)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_cs_vdec_END (15)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_cs_venc_START (16)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_cs_venc_END (16)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_venc_START (17)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_venc_END (17)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_venc_START (18)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_prst_venc_END (18)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_arst_venc_START (19)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_arst_venc_END (19)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_hpm_START (20)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_hpm_END (20)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_dbg_cs_START (21)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_dbg_cs_END (21)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_qic_dss_START (22)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_qic_dss_END (22)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_media1_wrap_crg_START (23)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_media1_wrap_crg_END (23)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_cs_dss_START (24)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_cs_dss_END (24)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_cs_aae_START (25)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_cs_aae_END (25)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_wrap_hpm0_START (26)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_wrap_hpm0_END (26)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_wrap_hpm1_START (27)
#define SOC_MEDIA1_CRG_PERRSTEN0_ip_rst_wrap_hpm1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_dss_crg : 1;
        unsigned int ip_rst_dss : 1;
        unsigned int ip_prst_atgm_dss : 1;
        unsigned int ip_prst_atgm_vdec : 1;
        unsigned int ip_rst_tcu_m1 : 1;
        unsigned int ip_prst_apb_brg_tcu : 1;
        unsigned int ip_rst_vdec_pxpc : 1;
        unsigned int ip_rst_vdec : 1;
        unsigned int ip_arst_vdec : 1;
        unsigned int ip_prst_vdec : 1;
        unsigned int ip_prst_atgm_venc : 1;
        unsigned int ip_rst_dss_disp1_crg : 1;
        unsigned int ip_rst_dss_disp1 : 1;
        unsigned int ip_rst_media_qic_data : 1;
        unsigned int ip_rst_qice_data : 1;
        unsigned int ip_rst_cs_vdec : 1;
        unsigned int ip_rst_cs_venc : 1;
        unsigned int ip_rst_venc : 1;
        unsigned int ip_prst_venc : 1;
        unsigned int ip_arst_venc : 1;
        unsigned int ip_rst_hpm : 1;
        unsigned int ip_rst_dbg_cs : 1;
        unsigned int ip_rst_qic_dss : 1;
        unsigned int ip_rst_media1_wrap_crg : 1;
        unsigned int ip_rst_cs_dss : 1;
        unsigned int ip_rst_cs_aae : 1;
        unsigned int ip_rst_wrap_hpm0 : 1;
        unsigned int ip_rst_wrap_hpm1 : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_MEDIA1_CRG_PERRSTDIS0_UNION;
#endif
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_dss_crg_START (0)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_dss_crg_END (0)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_dss_START (1)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_dss_END (1)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_atgm_dss_START (2)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_atgm_dss_END (2)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_atgm_vdec_START (3)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_atgm_vdec_END (3)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_tcu_m1_START (4)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_tcu_m1_END (4)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_apb_brg_tcu_START (5)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_apb_brg_tcu_END (5)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_vdec_pxpc_START (6)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_vdec_pxpc_END (6)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_vdec_START (7)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_vdec_END (7)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_arst_vdec_START (8)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_arst_vdec_END (8)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_vdec_START (9)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_vdec_END (9)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_atgm_venc_START (10)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_atgm_venc_END (10)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_dss_disp1_crg_START (11)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_dss_disp1_crg_END (11)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_dss_disp1_START (12)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_dss_disp1_END (12)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_media_qic_data_START (13)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_media_qic_data_END (13)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_qice_data_START (14)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_qice_data_END (14)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_cs_vdec_START (15)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_cs_vdec_END (15)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_cs_venc_START (16)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_cs_venc_END (16)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_venc_START (17)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_venc_END (17)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_venc_START (18)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_prst_venc_END (18)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_arst_venc_START (19)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_arst_venc_END (19)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_hpm_START (20)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_hpm_END (20)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_dbg_cs_START (21)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_dbg_cs_END (21)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_qic_dss_START (22)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_qic_dss_END (22)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_media1_wrap_crg_START (23)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_media1_wrap_crg_END (23)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_cs_dss_START (24)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_cs_dss_END (24)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_cs_aae_START (25)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_cs_aae_END (25)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_wrap_hpm0_START (26)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_wrap_hpm0_END (26)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_wrap_hpm1_START (27)
#define SOC_MEDIA1_CRG_PERRSTDIS0_ip_rst_wrap_hpm1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_dss_crg : 1;
        unsigned int ip_rst_dss : 1;
        unsigned int ip_prst_atgm_dss : 1;
        unsigned int ip_prst_atgm_vdec : 1;
        unsigned int ip_rst_tcu_m1 : 1;
        unsigned int ip_prst_apb_brg_tcu : 1;
        unsigned int ip_rst_vdec_pxpc : 1;
        unsigned int ip_rst_vdec : 1;
        unsigned int ip_arst_vdec : 1;
        unsigned int ip_prst_vdec : 1;
        unsigned int ip_prst_atgm_venc : 1;
        unsigned int ip_rst_dss_disp1_crg : 1;
        unsigned int ip_rst_dss_disp1 : 1;
        unsigned int ip_rst_media_qic_data : 1;
        unsigned int ip_rst_qice_data : 1;
        unsigned int ip_rst_cs_vdec : 1;
        unsigned int ip_rst_cs_venc : 1;
        unsigned int ip_rst_venc : 1;
        unsigned int ip_prst_venc : 1;
        unsigned int ip_arst_venc : 1;
        unsigned int ip_rst_hpm : 1;
        unsigned int ip_rst_dbg_cs : 1;
        unsigned int ip_rst_qic_dss : 1;
        unsigned int ip_rst_media1_wrap_crg : 1;
        unsigned int ip_rst_cs_dss : 1;
        unsigned int ip_rst_cs_aae : 1;
        unsigned int ip_rst_wrap_hpm0 : 1;
        unsigned int ip_rst_wrap_hpm1 : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_MEDIA1_CRG_PERRSTSTAT0_UNION;
#endif
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_crg_START (0)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_crg_END (0)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_START (1)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_END (1)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_dss_START (2)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_dss_END (2)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_vdec_START (3)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_vdec_END (3)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_tcu_m1_START (4)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_tcu_m1_END (4)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_apb_brg_tcu_START (5)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_apb_brg_tcu_END (5)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_vdec_pxpc_START (6)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_vdec_pxpc_END (6)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_vdec_START (7)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_vdec_END (7)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_arst_vdec_START (8)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_arst_vdec_END (8)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_vdec_START (9)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_vdec_END (9)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_venc_START (10)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_venc_END (10)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_disp1_crg_START (11)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_disp1_crg_END (11)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_disp1_START (12)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_disp1_END (12)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_media_qic_data_START (13)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_media_qic_data_END (13)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_qice_data_START (14)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_qice_data_END (14)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_vdec_START (15)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_vdec_END (15)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_venc_START (16)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_venc_END (16)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_venc_START (17)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_venc_END (17)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_venc_START (18)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_venc_END (18)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_arst_venc_START (19)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_arst_venc_END (19)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_hpm_START (20)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_hpm_END (20)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dbg_cs_START (21)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dbg_cs_END (21)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_qic_dss_START (22)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_qic_dss_END (22)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_media1_wrap_crg_START (23)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_media1_wrap_crg_END (23)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_dss_START (24)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_dss_END (24)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_aae_START (25)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_aae_END (25)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_wrap_hpm0_START (26)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_wrap_hpm0_END (26)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_wrap_hpm1_START (27)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_wrap_hpm1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_atgm_aae : 1;
        unsigned int ip_rst_lbist0 : 1;
        unsigned int ip_rst_lbist1 : 1;
        unsigned int ip_rst_lbist_cfg0 : 1;
        unsigned int ip_rst_lbist_cfg1 : 1;
        unsigned int ip_rst_aae : 1;
        unsigned int ip_rst_aae_crg : 1;
        unsigned int ip_rst_aae_part1 : 1;
        unsigned int ip_rst_aae_part1_crg : 1;
        unsigned int ip_rst_qic_aae : 1;
        unsigned int ip_rst_lat_mon_dss : 1;
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
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 8;
    } reg;
} SOC_MEDIA1_CRG_PERRSTEN1_UNION;
#endif
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_prst_atgm_aae_START (0)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_prst_atgm_aae_END (0)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_lbist0_START (1)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_lbist0_END (1)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_lbist1_START (2)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_lbist1_END (2)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_lbist_cfg0_START (3)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_lbist_cfg0_END (3)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_lbist_cfg1_START (4)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_lbist_cfg1_END (4)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_aae_START (5)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_aae_END (5)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_aae_crg_START (6)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_aae_crg_END (6)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_aae_part1_START (7)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_aae_part1_END (7)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_aae_part1_crg_START (8)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_aae_part1_crg_END (8)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_qic_aae_START (9)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_qic_aae_END (9)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_lat_mon_dss_START (10)
#define SOC_MEDIA1_CRG_PERRSTEN1_ip_rst_lat_mon_dss_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_atgm_aae : 1;
        unsigned int ip_rst_lbist0 : 1;
        unsigned int ip_rst_lbist1 : 1;
        unsigned int ip_rst_lbist_cfg0 : 1;
        unsigned int ip_rst_lbist_cfg1 : 1;
        unsigned int ip_rst_aae : 1;
        unsigned int ip_rst_aae_crg : 1;
        unsigned int ip_rst_aae_part1 : 1;
        unsigned int ip_rst_aae_part1_crg : 1;
        unsigned int ip_rst_qic_aae : 1;
        unsigned int ip_rst_lat_mon_dss : 1;
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
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 8;
    } reg;
} SOC_MEDIA1_CRG_PERRSTDIS1_UNION;
#endif
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_prst_atgm_aae_START (0)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_prst_atgm_aae_END (0)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_lbist0_START (1)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_lbist0_END (1)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_lbist1_START (2)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_lbist1_END (2)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_lbist_cfg0_START (3)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_lbist_cfg0_END (3)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_lbist_cfg1_START (4)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_lbist_cfg1_END (4)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_aae_START (5)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_aae_END (5)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_aae_crg_START (6)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_aae_crg_END (6)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_aae_part1_START (7)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_aae_part1_END (7)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_aae_part1_crg_START (8)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_aae_part1_crg_END (8)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_qic_aae_START (9)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_qic_aae_END (9)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_lat_mon_dss_START (10)
#define SOC_MEDIA1_CRG_PERRSTDIS1_ip_rst_lat_mon_dss_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_atgm_aae : 1;
        unsigned int ip_rst_lbist0 : 1;
        unsigned int ip_rst_lbist1 : 1;
        unsigned int ip_rst_lbist_cfg0 : 1;
        unsigned int ip_rst_lbist_cfg1 : 1;
        unsigned int ip_rst_aae : 1;
        unsigned int ip_rst_aae_crg : 1;
        unsigned int ip_rst_aae_part1 : 1;
        unsigned int ip_rst_aae_part1_crg : 1;
        unsigned int ip_rst_qic_aae : 1;
        unsigned int ip_rst_lat_mon_dss : 1;
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
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 8;
    } reg;
} SOC_MEDIA1_CRG_PERRSTSTAT1_UNION;
#endif
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_prst_atgm_aae_START (0)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_prst_atgm_aae_END (0)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_lbist0_START (1)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_lbist0_END (1)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_lbist1_START (2)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_lbist1_END (2)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_lbist_cfg0_START (3)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_lbist_cfg0_END (3)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_lbist_cfg1_START (4)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_lbist_cfg1_END (4)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_aae_START (5)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_aae_END (5)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_aae_crg_START (6)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_aae_crg_END (6)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_aae_part1_START (7)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_aae_part1_END (7)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_aae_part1_crg_START (8)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_aae_part1_crg_END (8)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_qic_aae_START (9)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_qic_aae_END (9)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_lat_mon_dss_START (10)
#define SOC_MEDIA1_CRG_PERRSTSTAT1_ip_rst_lat_mon_dss_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_dss_pll : 4;
        unsigned int sel_vdec_pll : 4;
        unsigned int sel_vcodec_axi_pll : 4;
        unsigned int reserved : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV0_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV0_sel_dss_pll_START (0)
#define SOC_MEDIA1_CRG_CLKDIV0_sel_dss_pll_END (3)
#define SOC_MEDIA1_CRG_CLKDIV0_sel_vdec_pll_START (4)
#define SOC_MEDIA1_CRG_CLKDIV0_sel_vdec_pll_END (7)
#define SOC_MEDIA1_CRG_CLKDIV0_sel_vcodec_axi_pll_START (8)
#define SOC_MEDIA1_CRG_CLKDIV0_sel_vcodec_axi_pll_END (11)
#define SOC_MEDIA1_CRG_CLKDIV0_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_vdec_pxpc_pll : 4;
        unsigned int sel_venc_pll : 4;
        unsigned int sel_hpm_pll : 4;
        unsigned int sel_aae_pll : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV1_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV1_sel_vdec_pxpc_pll_START (0)
#define SOC_MEDIA1_CRG_CLKDIV1_sel_vdec_pxpc_pll_END (3)
#define SOC_MEDIA1_CRG_CLKDIV1_sel_venc_pll_START (4)
#define SOC_MEDIA1_CRG_CLKDIV1_sel_venc_pll_END (7)
#define SOC_MEDIA1_CRG_CLKDIV1_sel_hpm_pll_START (8)
#define SOC_MEDIA1_CRG_CLKDIV1_sel_hpm_pll_END (11)
#define SOC_MEDIA1_CRG_CLKDIV1_sel_aae_pll_START (12)
#define SOC_MEDIA1_CRG_CLKDIV1_sel_aae_pll_END (15)
#define SOC_MEDIA1_CRG_CLKDIV1_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_dss : 6;
        unsigned int reserved_0: 2;
        unsigned int div_vdec : 6;
        unsigned int reserved_1: 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV2_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV2_div_dss_START (0)
#define SOC_MEDIA1_CRG_CLKDIV2_div_dss_END (5)
#define SOC_MEDIA1_CRG_CLKDIV2_div_vdec_START (8)
#define SOC_MEDIA1_CRG_CLKDIV2_div_vdec_END (13)
#define SOC_MEDIA1_CRG_CLKDIV2_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_vdec_pxpc : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_vcodec_axi : 6;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV3_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV3_div_vdec_pxpc_START (0)
#define SOC_MEDIA1_CRG_CLKDIV3_div_vdec_pxpc_END (5)
#define SOC_MEDIA1_CRG_CLKDIV3_div_vcodec_axi_START (8)
#define SOC_MEDIA1_CRG_CLKDIV3_div_vcodec_axi_END (13)
#define SOC_MEDIA1_CRG_CLKDIV3_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_venc : 6;
        unsigned int reserved_0: 2;
        unsigned int div_hpm : 6;
        unsigned int reserved_1: 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV4_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV4_div_venc_START (0)
#define SOC_MEDIA1_CRG_CLKDIV4_div_venc_END (5)
#define SOC_MEDIA1_CRG_CLKDIV4_div_hpm_START (8)
#define SOC_MEDIA1_CRG_CLKDIV4_div_hpm_END (13)
#define SOC_MEDIA1_CRG_CLKDIV4_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV4_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_aae : 6;
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV5_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV5_div_aae_START (0)
#define SOC_MEDIA1_CRG_CLKDIV5_div_aae_END (5)
#define SOC_MEDIA1_CRG_CLKDIV5_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV5_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 6;
        unsigned int reserved_2: 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV6_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV6_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV6_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 6;
        unsigned int reserved_2: 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV7_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV7_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV7_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_gt_clk_dss : 1;
        unsigned int sc_gt_aclk_vcodec : 1;
        unsigned int sc_gt_clk_venc : 1;
        unsigned int sc_gt_clk_vdec_pxpc : 1;
        unsigned int sc_gt_clk_vdec : 1;
        unsigned int sc_gt_clk_hpm : 1;
        unsigned int sc_gt_clk_aae : 1;
        unsigned int reserved : 9;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV8_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_dss_START (0)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_dss_END (0)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_aclk_vcodec_START (1)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_aclk_vcodec_END (1)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_venc_START (2)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_venc_END (2)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_vdec_pxpc_START (3)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_vdec_pxpc_END (3)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_vdec_START (4)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_vdec_END (4)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_hpm_START (5)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_hpm_END (5)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_aae_START (6)
#define SOC_MEDIA1_CRG_CLKDIV8_sc_gt_clk_aae_END (6)
#define SOC_MEDIA1_CRG_CLKDIV8_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV8_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 6;
        unsigned int reserved_2: 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV9_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV9_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV9_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int swdone_clk_dss_div : 1;
        unsigned int swdone_clk_vdec_pxpc_div : 1;
        unsigned int swdone_aclk_vcodec_div : 1;
        unsigned int swdone_clk_vdec_div : 1;
        unsigned int swdone_clk_venc_div : 1;
        unsigned int swdone_clk_hpm_div : 1;
        unsigned int swdone_clk_aae_div : 1;
        unsigned int reserved_0 : 9;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_MEDIA1_CRG_PERI_STAT0_UNION;
#endif
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_dss_div_START (0)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_dss_div_END (0)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_vdec_pxpc_div_START (1)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_vdec_pxpc_div_END (1)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_aclk_vcodec_div_START (2)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_aclk_vcodec_div_END (2)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_vdec_div_START (3)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_vdec_div_END (3)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_venc_div_START (4)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_venc_div_END (4)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_hpm_div_START (5)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_hpm_div_END (5)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_aae_div_START (6)
#define SOC_MEDIA1_CRG_PERI_STAT0_swdone_clk_aae_div_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_ack_clk_dss_sw : 4;
        unsigned int sw_ack_clk_vdec_pxpc_sw : 4;
        unsigned int sw_ack_clk_vcodec_axi_sw : 4;
        unsigned int sw_ack_clk_vdec_sw : 4;
        unsigned int sw_ack_clk_venc_sw : 4;
        unsigned int sw_ack_clk_hpm_sw : 4;
        unsigned int sw_ack_clk_aae_sw : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_MEDIA1_CRG_PERI_STAT1_UNION;
#endif
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_dss_sw_START (0)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_dss_sw_END (3)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_vdec_pxpc_sw_START (4)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_vdec_pxpc_sw_END (7)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_vcodec_axi_sw_START (8)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_vcodec_axi_sw_END (11)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_vdec_sw_START (12)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_vdec_sw_END (15)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_venc_sw_START (16)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_venc_sw_END (19)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_hpm_sw_START (20)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_hpm_sw_END (23)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_aae_sw_START (24)
#define SOC_MEDIA1_CRG_PERI_STAT1_sw_ack_clk_aae_sw_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 20;
        unsigned int reserved_1: 12;
    } reg;
} SOC_MEDIA1_CRG_PERI_STAT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hw_dvfs_en : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_MEDIA1_CRG_DSS_DVFS_UNION;
#endif
#define SOC_MEDIA1_CRG_DSS_DVFS_hw_dvfs_en_START (0)
#define SOC_MEDIA1_CRG_DSS_DVFS_hw_dvfs_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hw_sel_dss_pll : 4;
        unsigned int hw_div_dss : 6;
        unsigned int reserved : 22;
    } reg;
} SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_UNION;
#endif
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_hw_sel_dss_pll_START (0)
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_hw_sel_dss_pll_END (3)
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_hw_div_dss_START (4)
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_hw_div_dss_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_cfg_clkrst_bypass : 1;
        unsigned int media_lbist0_clkrst_bypass : 1;
        unsigned int media_lbist1_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 20;
    } reg;
} SOC_MEDIA1_CRG_IPCLKRST_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_IPCLKRST_BYPASS_tcu_cfg_clkrst_bypass_START (0)
#define SOC_MEDIA1_CRG_IPCLKRST_BYPASS_tcu_cfg_clkrst_bypass_END (0)
#define SOC_MEDIA1_CRG_IPCLKRST_BYPASS_media_lbist0_clkrst_bypass_START (1)
#define SOC_MEDIA1_CRG_IPCLKRST_BYPASS_media_lbist0_clkrst_bypass_END (1)
#define SOC_MEDIA1_CRG_IPCLKRST_BYPASS_media_lbist1_clkrst_bypass_START (2)
#define SOC_MEDIA1_CRG_IPCLKRST_BYPASS_media_lbist1_clkrst_bypass_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdec_div_auto_reduce_bypass : 1;
        unsigned int vdec_auto_waitcfg_in : 10;
        unsigned int vdec_auto_waitcfg_out : 10;
        unsigned int vdec_div_auto_cfg : 6;
        unsigned int reserved : 5;
    } reg;
} SOC_MEDIA1_CRG_PERI_AUTODIV0_UNION;
#endif
#define SOC_MEDIA1_CRG_PERI_AUTODIV0_vdec_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV0_vdec_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV0_vdec_auto_waitcfg_in_START (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV0_vdec_auto_waitcfg_in_END (10)
#define SOC_MEDIA1_CRG_PERI_AUTODIV0_vdec_auto_waitcfg_out_START (11)
#define SOC_MEDIA1_CRG_PERI_AUTODIV0_vdec_auto_waitcfg_out_END (20)
#define SOC_MEDIA1_CRG_PERI_AUTODIV0_vdec_div_auto_cfg_START (21)
#define SOC_MEDIA1_CRG_PERI_AUTODIV0_vdec_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdec_pxpc_div_auto_reduce_bypass : 1;
        unsigned int vdec_pxpc_auto_waitcfg_in : 10;
        unsigned int vdec_pxpc_auto_waitcfg_out : 10;
        unsigned int vdec_pxpc_auto_cfg : 6;
        unsigned int reserved : 5;
    } reg;
} SOC_MEDIA1_CRG_PERI_AUTODIV1_UNION;
#endif
#define SOC_MEDIA1_CRG_PERI_AUTODIV1_vdec_pxpc_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV1_vdec_pxpc_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV1_vdec_pxpc_auto_waitcfg_in_START (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV1_vdec_pxpc_auto_waitcfg_in_END (10)
#define SOC_MEDIA1_CRG_PERI_AUTODIV1_vdec_pxpc_auto_waitcfg_out_START (11)
#define SOC_MEDIA1_CRG_PERI_AUTODIV1_vdec_pxpc_auto_waitcfg_out_END (20)
#define SOC_MEDIA1_CRG_PERI_AUTODIV1_vdec_pxpc_auto_cfg_START (21)
#define SOC_MEDIA1_CRG_PERI_AUTODIV1_vdec_pxpc_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vcodec_axi_div_auto_reduce_bypass : 1;
        unsigned int vcodec_axi_auto_waitcfg_in : 10;
        unsigned int vcodec_axi_auto_waitcfg_out : 10;
        unsigned int vcodec_axi_div_auto_cfg : 6;
        unsigned int reserved : 5;
    } reg;
} SOC_MEDIA1_CRG_PERI_AUTODIV2_UNION;
#endif
#define SOC_MEDIA1_CRG_PERI_AUTODIV2_vcodec_axi_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV2_vcodec_axi_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV2_vcodec_axi_auto_waitcfg_in_START (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV2_vcodec_axi_auto_waitcfg_in_END (10)
#define SOC_MEDIA1_CRG_PERI_AUTODIV2_vcodec_axi_auto_waitcfg_out_START (11)
#define SOC_MEDIA1_CRG_PERI_AUTODIV2_vcodec_axi_auto_waitcfg_out_END (20)
#define SOC_MEDIA1_CRG_PERI_AUTODIV2_vcodec_axi_div_auto_cfg_START (21)
#define SOC_MEDIA1_CRG_PERI_AUTODIV2_vcodec_axi_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int venc_div_auto_reduce_bypass : 1;
        unsigned int venc_auto_waitcfg_in : 10;
        unsigned int venc_auto_waitcfg_out : 10;
        unsigned int venc_div_auto_cfg : 6;
        unsigned int reserved : 5;
    } reg;
} SOC_MEDIA1_CRG_PERI_AUTODIV3_UNION;
#endif
#define SOC_MEDIA1_CRG_PERI_AUTODIV3_venc_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV3_venc_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV3_venc_auto_waitcfg_in_START (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV3_venc_auto_waitcfg_in_END (10)
#define SOC_MEDIA1_CRG_PERI_AUTODIV3_venc_auto_waitcfg_out_START (11)
#define SOC_MEDIA1_CRG_PERI_AUTODIV3_venc_auto_waitcfg_out_END (20)
#define SOC_MEDIA1_CRG_PERI_AUTODIV3_venc_div_auto_cfg_START (21)
#define SOC_MEDIA1_CRG_PERI_AUTODIV3_venc_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdec_idle_flag_bypass : 1;
        unsigned int venc_idle_flag_bypass : 1;
        unsigned int tcu_idle_flag_bypass : 1;
        unsigned int dss_idle_flag_bypass : 1;
        unsigned int perf_idle_dss_0_bypass : 1;
        unsigned int perf_idle_dss_1_bypass : 1;
        unsigned int perf_idle_vdec_bypass : 1;
        unsigned int perf_idle_venc0_bypass : 1;
        unsigned int perf_idle_venc1_bypass : 1;
        unsigned int perf_idle_tcu_bypass : 1;
        unsigned int perf_idle_ibqe_bypass : 1;
        unsigned int perf_idle_aae_bypass : 1;
        unsigned int aae_idle_flag_bypass : 1;
        unsigned int qice_bus_media1_nopending_comb_bypass : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MEDIA1_CRG_PERI_AUTODIV4_UNION;
#endif
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_vdec_idle_flag_bypass_START (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_vdec_idle_flag_bypass_END (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_venc_idle_flag_bypass_START (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_venc_idle_flag_bypass_END (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_tcu_idle_flag_bypass_START (2)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_tcu_idle_flag_bypass_END (2)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_dss_idle_flag_bypass_START (3)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_dss_idle_flag_bypass_END (3)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_dss_0_bypass_START (4)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_dss_0_bypass_END (4)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_dss_1_bypass_START (5)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_dss_1_bypass_END (5)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_vdec_bypass_START (6)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_vdec_bypass_END (6)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_venc0_bypass_START (7)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_venc0_bypass_END (7)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_venc1_bypass_START (8)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_venc1_bypass_END (8)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_tcu_bypass_START (9)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_tcu_bypass_END (9)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_ibqe_bypass_START (10)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_ibqe_bypass_END (10)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_aae_bypass_START (11)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_perf_idle_aae_bypass_END (11)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_aae_idle_flag_bypass_START (12)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_aae_idle_flag_bypass_END (12)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_qice_bus_media1_nopending_comb_bypass_START (13)
#define SOC_MEDIA1_CRG_PERI_AUTODIV4_qice_bus_media1_nopending_comb_bypass_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_dss_nopending_grp_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_DSS_NOPENDING_GRP_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_DSS_NOPENDING_GRP_BYPASS_qic_bus_dss_nopending_grp_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_DSS_NOPENDING_GRP_BYPASS_qic_bus_dss_nopending_grp_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_vdec_nopending_grp_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_VDEC_NOPENDING_GRP_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_VDEC_NOPENDING_GRP_BYPASS_qic_bus_vdec_nopending_grp_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_VDEC_NOPENDING_GRP_BYPASS_qic_bus_vdec_nopending_grp_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_venc_nopending_grp_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_VENC_NOPENDING_GRP_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_VENC_NOPENDING_GRP_BYPASS_qic_bus_venc_nopending_grp_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_VENC_NOPENDING_GRP_BYPASS_qic_bus_venc_nopending_grp_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_tcu_nopending_grp0_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_BYPASS_qic_bus_tcu_nopending_grp0_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_BYPASS_qic_bus_tcu_nopending_grp0_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_media1_nopending_grp0_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_BYPASS_qic_bus_media1_nopending_grp0_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_BYPASS_qic_bus_media1_nopending_grp0_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_media1_nopending_grp1_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_BYPASS_qic_bus_media1_nopending_grp1_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_BYPASS_qic_bus_media1_nopending_grp1_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_tcu_nopending_grp1_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_BYPASS_qic_bus_tcu_nopending_grp1_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_BYPASS_qic_bus_tcu_nopending_grp1_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_div_auto_reduce_bypass : 1;
        unsigned int dss_auto_waitcfg_in : 10;
        unsigned int dss_auto_waitcfg_out : 10;
        unsigned int dss_div_auto_cfg : 6;
        unsigned int reserved : 5;
    } reg;
} SOC_MEDIA1_CRG_PERI_AUTODIV5_UNION;
#endif
#define SOC_MEDIA1_CRG_PERI_AUTODIV5_dss_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV5_dss_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV5_dss_auto_waitcfg_in_START (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV5_dss_auto_waitcfg_in_END (10)
#define SOC_MEDIA1_CRG_PERI_AUTODIV5_dss_auto_waitcfg_out_START (11)
#define SOC_MEDIA1_CRG_PERI_AUTODIV5_dss_auto_waitcfg_out_END (20)
#define SOC_MEDIA1_CRG_PERI_AUTODIV5_dss_div_auto_cfg_START (21)
#define SOC_MEDIA1_CRG_PERI_AUTODIV5_dss_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_idle_flag_dss_autodiv_bypass : 1;
        unsigned int dss_idle_flag_dss_autodiv_bypass : 1;
        unsigned int perf_idle_ibqe_dss_autodiv_bypass : 1;
        unsigned int perf_idle_tcu_dss_autodiv_bypass : 1;
        unsigned int perf_idle_dss_1_dss_autodiv_bypass : 1;
        unsigned int perf_idle_dss_0_dss_autodiv_bypass : 1;
        unsigned int qice_bus_media1_nopending_comb_dss_autodiv_bypass : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MEDIA1_CRG_PERI_AUTODIV6_UNION;
#endif
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_tcu_idle_flag_dss_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_tcu_idle_flag_dss_autodiv_bypass_END (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_dss_idle_flag_dss_autodiv_bypass_START (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_dss_idle_flag_dss_autodiv_bypass_END (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_perf_idle_ibqe_dss_autodiv_bypass_START (2)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_perf_idle_ibqe_dss_autodiv_bypass_END (2)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_perf_idle_tcu_dss_autodiv_bypass_START (3)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_perf_idle_tcu_dss_autodiv_bypass_END (3)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_perf_idle_dss_1_dss_autodiv_bypass_START (4)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_perf_idle_dss_1_dss_autodiv_bypass_END (4)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_perf_idle_dss_0_dss_autodiv_bypass_START (5)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_perf_idle_dss_0_dss_autodiv_bypass_END (5)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_qice_bus_media1_nopending_comb_dss_autodiv_bypass_START (6)
#define SOC_MEDIA1_CRG_PERI_AUTODIV6_qice_bus_media1_nopending_comb_dss_autodiv_bypass_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_dss_nopending_grp_dss_autodiv_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_DSS_NOPENDING_GRP_DSS_AUTODIV_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_DSS_NOPENDING_GRP_DSS_AUTODIV_BYPASS_qic_bus_dss_nopending_grp_dss_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_DSS_NOPENDING_GRP_DSS_AUTODIV_BYPASS_qic_bus_dss_nopending_grp_dss_autodiv_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_tcu_nopending_grp0_dss_autodiv_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_DSS_AUTODIV_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_DSS_AUTODIV_BYPASS_qic_bus_tcu_nopending_grp0_dss_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_DSS_AUTODIV_BYPASS_qic_bus_tcu_nopending_grp0_dss_autodiv_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_media1_nopending_grp0_dss_autodiv_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_DSS_AUTODIV_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_DSS_AUTODIV_BYPASS_qic_bus_media1_nopending_grp0_dss_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_DSS_AUTODIV_BYPASS_qic_bus_media1_nopending_grp0_dss_autodiv_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_media1_nopending_grp1_dss_autodiv_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_DSS_AUTODIV_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_DSS_AUTODIV_BYPASS_qic_bus_media1_nopending_grp1_dss_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_DSS_AUTODIV_BYPASS_qic_bus_media1_nopending_grp1_dss_autodiv_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_tcu_nopending_grp1_dss_autodiv_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_DSS_AUTODIV_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_DSS_AUTODIV_BYPASS_qic_bus_tcu_nopending_grp1_dss_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_DSS_AUTODIV_BYPASS_qic_bus_tcu_nopending_grp1_dss_autodiv_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_dss_nopending_grp_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_AAE_NOPENDING_GRP_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_AAE_NOPENDING_GRP_BYPASS_qic_bus_dss_nopending_grp_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_AAE_NOPENDING_GRP_BYPASS_qic_bus_dss_nopending_grp_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_div_auto_reduce_bypass : 1;
        unsigned int aae_auto_waitcfg_in : 10;
        unsigned int aae_auto_waitcfg_out : 10;
        unsigned int aae_div_auto_cfg : 6;
        unsigned int reserved : 5;
    } reg;
} SOC_MEDIA1_CRG_PERI_AUTODIV7_UNION;
#endif
#define SOC_MEDIA1_CRG_PERI_AUTODIV7_aae_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV7_aae_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV7_aae_auto_waitcfg_in_START (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV7_aae_auto_waitcfg_in_END (10)
#define SOC_MEDIA1_CRG_PERI_AUTODIV7_aae_auto_waitcfg_out_START (11)
#define SOC_MEDIA1_CRG_PERI_AUTODIV7_aae_auto_waitcfg_out_END (20)
#define SOC_MEDIA1_CRG_PERI_AUTODIV7_aae_div_auto_cfg_START (21)
#define SOC_MEDIA1_CRG_PERI_AUTODIV7_aae_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_idle_flag_aae_autodiv_bypass : 1;
        unsigned int aae_idle_flag_aae_autodiv_bypass : 1;
        unsigned int perf_idle_ibqe_aae_autodiv_bypass : 1;
        unsigned int perf_idle_tcu_aae_autodiv_bypass : 1;
        unsigned int perf_idle_aee_autodiv_bypass : 1;
        unsigned int qice_bus_media1_nopending_comb_aae_autodiv_bypass : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_MEDIA1_CRG_PERI_AUTODIV8_UNION;
#endif
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_tcu_idle_flag_aae_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_tcu_idle_flag_aae_autodiv_bypass_END (0)
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_aae_idle_flag_aae_autodiv_bypass_START (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_aae_idle_flag_aae_autodiv_bypass_END (1)
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_perf_idle_ibqe_aae_autodiv_bypass_START (2)
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_perf_idle_ibqe_aae_autodiv_bypass_END (2)
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_perf_idle_tcu_aae_autodiv_bypass_START (3)
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_perf_idle_tcu_aae_autodiv_bypass_END (3)
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_perf_idle_aee_autodiv_bypass_START (4)
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_perf_idle_aee_autodiv_bypass_END (4)
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_qice_bus_media1_nopending_comb_aae_autodiv_bypass_START (5)
#define SOC_MEDIA1_CRG_PERI_AUTODIV8_qice_bus_media1_nopending_comb_aae_autodiv_bypass_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_aae_nopending_grp_aee_autodiv_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_AAE_NOPENDING_GRP_AAE_AUTODIV_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_AAE_NOPENDING_GRP_AAE_AUTODIV_BYPASS_qic_bus_aae_nopending_grp_aee_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_AAE_NOPENDING_GRP_AAE_AUTODIV_BYPASS_qic_bus_aae_nopending_grp_aee_autodiv_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_tcu_nopending_grp0_aae_autodiv_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_AAE_AUTODIV_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_AAE_AUTODIV_BYPASS_qic_bus_tcu_nopending_grp0_aae_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP0_AAE_AUTODIV_BYPASS_qic_bus_tcu_nopending_grp0_aae_autodiv_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_media1_nopending_grp0_aae_autodiv_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_AAE_AUTODIV_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_AAE_AUTODIV_BYPASS_qic_bus_media1_nopending_grp0_aae_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP0_AAE_AUTODIV_BYPASS_qic_bus_media1_nopending_grp0_aae_autodiv_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_media1_nopending_grp1_aae_autodiv_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_AAE_AUTODIV_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_AAE_AUTODIV_BYPASS_qic_bus_media1_nopending_grp1_aae_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_MEDIA1_NOPENDING_GRP1_AAE_AUTODIV_BYPASS_qic_bus_media1_nopending_grp1_aae_autodiv_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_tcu_nopending_grp1_aae_autodiv_bypass : 32;
    } reg;
} SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_AAE_AUTODIV_BYPASS_UNION;
#endif
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_AAE_AUTODIV_BYPASS_qic_bus_tcu_nopending_grp1_aae_autodiv_bypass_START (0)
#define SOC_MEDIA1_CRG_QIC_BUS_TCU_NOPENDING_GRP1_AAE_AUTODIV_BYPASS_qic_bus_tcu_nopending_grp1_aae_autodiv_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int auto_div_venc_stat : 1;
        unsigned int auto_div_vcodec_axi_stat : 1;
        unsigned int auto_div_vdec_pxpc_stat : 1;
        unsigned int auto_div_vdec_stat : 1;
        unsigned int auto_div_dss_stat : 1;
        unsigned int auto_div_aae_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 24;
    } reg;
} SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_UNION;
#endif
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_venc_stat_START (0)
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_venc_stat_END (0)
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_vcodec_axi_stat_START (1)
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_vcodec_axi_stat_END (1)
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_vdec_pxpc_stat_START (2)
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_vdec_pxpc_stat_END (2)
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_vdec_stat_START (3)
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_vdec_stat_END (3)
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_dss_stat_START (4)
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_dss_stat_END (4)
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_aae_stat_START (5)
#define SOC_MEDIA1_CRG_MEDIA_AUTODIV_STAT_auto_div_aae_stat_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_clr_mediabus_nonidle_pend : 1;
        unsigned int intr_mask_qic_m1_nonidle_pend : 1;
        unsigned int intr_mask_vencbus_nonidle_pend : 1;
        unsigned int intr_mask_vdecbus_nonidle_pend : 1;
        unsigned int intr_mask_ibqe_nonidle_pend : 1;
        unsigned int intr_mask_dssbus_nonidle_pend : 1;
        unsigned int intr_mask_tcubus_nonidle_pend : 1;
        unsigned int intr_mask_aaebus_nonidle_pend : 1;
        unsigned int reserved : 8;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_clr_mediabus_nonidle_pend_START (0)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_clr_mediabus_nonidle_pend_END (0)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_qic_m1_nonidle_pend_START (1)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_qic_m1_nonidle_pend_END (1)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_vencbus_nonidle_pend_START (2)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_vencbus_nonidle_pend_END (2)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_vdecbus_nonidle_pend_START (3)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_vdecbus_nonidle_pend_END (3)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_ibqe_nonidle_pend_START (4)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_ibqe_nonidle_pend_END (4)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_dssbus_nonidle_pend_START (5)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_dssbus_nonidle_pend_END (5)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_tcubus_nonidle_pend_START (6)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_tcubus_nonidle_pend_END (6)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_aaebus_nonidle_pend_START (7)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_intr_mask_aaebus_nonidle_pend_END (7)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_MEDIA1_CRG_INTR_QIC_BUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_stat_qic_m1_nonidle_pend : 1;
        unsigned int intr_stat_vencbus_nonidle_pend : 1;
        unsigned int intr_stat_vdecbus_nonidle_pend : 1;
        unsigned int intr_stat_ibqe_nonidle_pend : 1;
        unsigned int intr_stat_dssbus_nonidle_pend : 1;
        unsigned int intr_stat_tcubus_nonidle_pend : 1;
        unsigned int intr_stat_aaebus_nonidle_pend : 1;
        unsigned int reserved : 9;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_qic_m1_nonidle_pend_START (0)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_qic_m1_nonidle_pend_END (0)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_vencbus_nonidle_pend_START (1)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_vencbus_nonidle_pend_END (1)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_vdecbus_nonidle_pend_START (2)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_vdecbus_nonidle_pend_END (2)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_ibqe_nonidle_pend_START (3)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_ibqe_nonidle_pend_END (3)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_dssbus_nonidle_pend_START (4)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_dssbus_nonidle_pend_END (4)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_tcubus_nonidle_pend_START (5)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_tcubus_nonidle_pend_END (5)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_aaebus_nonidle_pend_START (6)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_intr_stat_aaebus_nonidle_pend_END (6)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_MEDIA1_CRG_INTR_STAT_QIC_BUS_NONIDLE_PEND_bitmasken_END (31)
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
} SOC_MEDIA1_CRG_HPM_CFG_UNION;
#endif
#define SOC_MEDIA1_CRG_HPM_CFG_hpm_en_START (0)
#define SOC_MEDIA1_CRG_HPM_CFG_hpm_en_END (0)
#define SOC_MEDIA1_CRG_HPM_CFG_hpm_opc_min_en_START (1)
#define SOC_MEDIA1_CRG_HPM_CFG_hpm_opc_min_en_END (1)
#define SOC_MEDIA1_CRG_HPM_CFG_hpm_clk_div_START (4)
#define SOC_MEDIA1_CRG_HPM_CFG_hpm_clk_div_END (10)
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
} SOC_MEDIA1_CRG_HPM_READ_BACK_UNION;
#endif
#define SOC_MEDIA1_CRG_HPM_READ_BACK_hpm_opc_vld_START (0)
#define SOC_MEDIA1_CRG_HPM_READ_BACK_hpm_opc_vld_END (0)
#define SOC_MEDIA1_CRG_HPM_READ_BACK_hpm_opc_START (1)
#define SOC_MEDIA1_CRG_HPM_READ_BACK_hpm_opc_END (10)
#define SOC_MEDIA1_CRG_HPM_READ_BACK_hpm_opc_min_START (11)
#define SOC_MEDIA1_CRG_HPM_READ_BACK_hpm_opc_min_END (20)
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
} SOC_MEDIA1_CRG_HPMX_CFG_UNION;
#endif
#define SOC_MEDIA1_CRG_HPMX_CFG_hpmx_en_START (0)
#define SOC_MEDIA1_CRG_HPMX_CFG_hpmx_en_END (0)
#define SOC_MEDIA1_CRG_HPMX_CFG_hpmx_opc_min_en_START (1)
#define SOC_MEDIA1_CRG_HPMX_CFG_hpmx_opc_min_en_END (1)
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
} SOC_MEDIA1_CRG_HPMX_READ_BACK_UNION;
#endif
#define SOC_MEDIA1_CRG_HPMX_READ_BACK_hpmx_opc_vld_START (0)
#define SOC_MEDIA1_CRG_HPMX_READ_BACK_hpmx_opc_vld_END (0)
#define SOC_MEDIA1_CRG_HPMX_READ_BACK_hpmx_opc_START (1)
#define SOC_MEDIA1_CRG_HPMX_READ_BACK_hpmx_opc_END (10)
#define SOC_MEDIA1_CRG_HPMX_READ_BACK_hpmx_opc_min_START (11)
#define SOC_MEDIA1_CRG_HPMX_READ_BACK_hpmx_opc_min_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_hpm0_en : 1;
        unsigned int wrap_hpm0_opc_min_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int wrap_hpm0_clk_div : 7;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 16;
    } reg;
} SOC_MEDIA1_CRG_WRAP_HPM0_CFG_UNION;
#endif
#define SOC_MEDIA1_CRG_WRAP_HPM0_CFG_wrap_hpm0_en_START (0)
#define SOC_MEDIA1_CRG_WRAP_HPM0_CFG_wrap_hpm0_en_END (0)
#define SOC_MEDIA1_CRG_WRAP_HPM0_CFG_wrap_hpm0_opc_min_en_START (1)
#define SOC_MEDIA1_CRG_WRAP_HPM0_CFG_wrap_hpm0_opc_min_en_END (1)
#define SOC_MEDIA1_CRG_WRAP_HPM0_CFG_wrap_hpm0_clk_div_START (4)
#define SOC_MEDIA1_CRG_WRAP_HPM0_CFG_wrap_hpm0_clk_div_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_hpm0_opc_vld : 1;
        unsigned int wrap_hpm0_opc : 10;
        unsigned int wrap_hpm0_opc_min : 10;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MEDIA1_CRG_WRAP_HPM0_READ_BACK_UNION;
#endif
#define SOC_MEDIA1_CRG_WRAP_HPM0_READ_BACK_wrap_hpm0_opc_vld_START (0)
#define SOC_MEDIA1_CRG_WRAP_HPM0_READ_BACK_wrap_hpm0_opc_vld_END (0)
#define SOC_MEDIA1_CRG_WRAP_HPM0_READ_BACK_wrap_hpm0_opc_START (1)
#define SOC_MEDIA1_CRG_WRAP_HPM0_READ_BACK_wrap_hpm0_opc_END (10)
#define SOC_MEDIA1_CRG_WRAP_HPM0_READ_BACK_wrap_hpm0_opc_min_START (11)
#define SOC_MEDIA1_CRG_WRAP_HPM0_READ_BACK_wrap_hpm0_opc_min_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_hpmx0_en : 1;
        unsigned int wrap_hpmx0_opc_min_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 12;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_MEDIA1_CRG_WRAP_HPMX0_CFG_UNION;
#endif
#define SOC_MEDIA1_CRG_WRAP_HPMX0_CFG_wrap_hpmx0_en_START (0)
#define SOC_MEDIA1_CRG_WRAP_HPMX0_CFG_wrap_hpmx0_en_END (0)
#define SOC_MEDIA1_CRG_WRAP_HPMX0_CFG_wrap_hpmx0_opc_min_en_START (1)
#define SOC_MEDIA1_CRG_WRAP_HPMX0_CFG_wrap_hpmx0_opc_min_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_hpmx0_opc_vld : 1;
        unsigned int wrap_hpmx0_opc : 10;
        unsigned int wrap_hpmx0_opc_min : 10;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MEDIA1_CRG_WRAP_HPMX0_READ_BACK_UNION;
#endif
#define SOC_MEDIA1_CRG_WRAP_HPMX0_READ_BACK_wrap_hpmx0_opc_vld_START (0)
#define SOC_MEDIA1_CRG_WRAP_HPMX0_READ_BACK_wrap_hpmx0_opc_vld_END (0)
#define SOC_MEDIA1_CRG_WRAP_HPMX0_READ_BACK_wrap_hpmx0_opc_START (1)
#define SOC_MEDIA1_CRG_WRAP_HPMX0_READ_BACK_wrap_hpmx0_opc_END (10)
#define SOC_MEDIA1_CRG_WRAP_HPMX0_READ_BACK_wrap_hpmx0_opc_min_START (11)
#define SOC_MEDIA1_CRG_WRAP_HPMX0_READ_BACK_wrap_hpmx0_opc_min_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_hpm1_en : 1;
        unsigned int wrap_hpm1_opc_min_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int wrap_hpm1_clk_div : 7;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 16;
    } reg;
} SOC_MEDIA1_CRG_WRAP_HPM1_CFG_UNION;
#endif
#define SOC_MEDIA1_CRG_WRAP_HPM1_CFG_wrap_hpm1_en_START (0)
#define SOC_MEDIA1_CRG_WRAP_HPM1_CFG_wrap_hpm1_en_END (0)
#define SOC_MEDIA1_CRG_WRAP_HPM1_CFG_wrap_hpm1_opc_min_en_START (1)
#define SOC_MEDIA1_CRG_WRAP_HPM1_CFG_wrap_hpm1_opc_min_en_END (1)
#define SOC_MEDIA1_CRG_WRAP_HPM1_CFG_wrap_hpm1_clk_div_START (4)
#define SOC_MEDIA1_CRG_WRAP_HPM1_CFG_wrap_hpm1_clk_div_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_hpm1_opc_vld : 1;
        unsigned int wrap_hpm1_opc : 10;
        unsigned int wrap_hpm1_opc_min : 10;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MEDIA1_CRG_WRAP_HPM1_READ_BACK_UNION;
#endif
#define SOC_MEDIA1_CRG_WRAP_HPM1_READ_BACK_wrap_hpm1_opc_vld_START (0)
#define SOC_MEDIA1_CRG_WRAP_HPM1_READ_BACK_wrap_hpm1_opc_vld_END (0)
#define SOC_MEDIA1_CRG_WRAP_HPM1_READ_BACK_wrap_hpm1_opc_START (1)
#define SOC_MEDIA1_CRG_WRAP_HPM1_READ_BACK_wrap_hpm1_opc_END (10)
#define SOC_MEDIA1_CRG_WRAP_HPM1_READ_BACK_wrap_hpm1_opc_min_START (11)
#define SOC_MEDIA1_CRG_WRAP_HPM1_READ_BACK_wrap_hpm1_opc_min_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_hpmx1_en : 1;
        unsigned int wrap_hpmx1_opc_min_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 12;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_MEDIA1_CRG_WRAP_HPMX1_CFG_UNION;
#endif
#define SOC_MEDIA1_CRG_WRAP_HPMX1_CFG_wrap_hpmx1_en_START (0)
#define SOC_MEDIA1_CRG_WRAP_HPMX1_CFG_wrap_hpmx1_en_END (0)
#define SOC_MEDIA1_CRG_WRAP_HPMX1_CFG_wrap_hpmx1_opc_min_en_START (1)
#define SOC_MEDIA1_CRG_WRAP_HPMX1_CFG_wrap_hpmx1_opc_min_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_hpmx1_opc_vld : 1;
        unsigned int wrap_hpmx1_opc : 10;
        unsigned int wrap_hpmx1_opc_min : 10;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MEDIA1_CRG_WRAP_HPMX1_READ_BACK_UNION;
#endif
#define SOC_MEDIA1_CRG_WRAP_HPMX1_READ_BACK_wrap_hpmx1_opc_vld_START (0)
#define SOC_MEDIA1_CRG_WRAP_HPMX1_READ_BACK_wrap_hpmx1_opc_vld_END (0)
#define SOC_MEDIA1_CRG_WRAP_HPMX1_READ_BACK_wrap_hpmx1_opc_START (1)
#define SOC_MEDIA1_CRG_WRAP_HPMX1_READ_BACK_wrap_hpmx1_opc_END (10)
#define SOC_MEDIA1_CRG_WRAP_HPMX1_READ_BACK_wrap_hpmx1_opc_min_START (11)
#define SOC_MEDIA1_CRG_WRAP_HPMX1_READ_BACK_wrap_hpmx1_opc_min_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int venc2media_ro_dbg0 : 32;
    } reg;
} SOC_MEDIA1_CRG_VENC_DBG0_UNION;
#endif
#define SOC_MEDIA1_CRG_VENC_DBG0_venc2media_ro_dbg0_START (0)
#define SOC_MEDIA1_CRG_VENC_DBG0_venc2media_ro_dbg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int venc2media_ro_dbg1 : 32;
    } reg;
} SOC_MEDIA1_CRG_VENC_DBG1_UNION;
#endif
#define SOC_MEDIA1_CRG_VENC_DBG1_venc2media_ro_dbg1_START (0)
#define SOC_MEDIA1_CRG_VENC_DBG1_venc2media_ro_dbg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int venc2media_ro_dbg2 : 32;
    } reg;
} SOC_MEDIA1_CRG_VENC_DBG2_UNION;
#endif
#define SOC_MEDIA1_CRG_VENC_DBG2_venc2media_ro_dbg2_START (0)
#define SOC_MEDIA1_CRG_VENC_DBG2_venc2media_ro_dbg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int venc2media_ro_dbg3 : 32;
    } reg;
} SOC_MEDIA1_CRG_VENC_DBG3_UNION;
#endif
#define SOC_MEDIA1_CRG_VENC_DBG3_venc2media_ro_dbg3_START (0)
#define SOC_MEDIA1_CRG_VENC_DBG3_venc2media_ro_dbg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdec_idle_flag : 1;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 10;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_MEDIA1_CRG_VDEC_IDLE_READ_BACK_UNION;
#endif
#define SOC_MEDIA1_CRG_VDEC_IDLE_READ_BACK_vdec_idle_flag_START (0)
#define SOC_MEDIA1_CRG_VDEC_IDLE_READ_BACK_vdec_idle_flag_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int venc_idle_flag : 1;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 10;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_MEDIA1_CRG_VENC_IDLE_READ_BACK_UNION;
#endif
#define SOC_MEDIA1_CRG_VENC_IDLE_READ_BACK_venc_idle_flag_START (0)
#define SOC_MEDIA1_CRG_VENC_IDLE_READ_BACK_venc_idle_flag_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int venc_ahb_matrix_dlock_and_dbg_clr : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_MEDIA1_CRG_HIMINIBUS_DLOCK_CLR_UNION;
#endif
#define SOC_MEDIA1_CRG_HIMINIBUS_DLOCK_CLR_venc_ahb_matrix_dlock_and_dbg_clr_START (0)
#define SOC_MEDIA1_CRG_HIMINIBUS_DLOCK_CLR_venc_ahb_matrix_dlock_and_dbg_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int venc_ahb2apb_ckg_en : 1;
        unsigned int venc_ahb_matrix_ckg_en : 1;
        unsigned int venc_axi2ahb_ckg_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MEDIA1_CRG_VENC_CKG_EN_UNION;
#endif
#define SOC_MEDIA1_CRG_VENC_CKG_EN_venc_ahb2apb_ckg_en_START (0)
#define SOC_MEDIA1_CRG_VENC_CKG_EN_venc_ahb2apb_ckg_en_END (0)
#define SOC_MEDIA1_CRG_VENC_CKG_EN_venc_ahb_matrix_ckg_en_START (1)
#define SOC_MEDIA1_CRG_VENC_CKG_EN_venc_ahb_matrix_ckg_en_END (1)
#define SOC_MEDIA1_CRG_VENC_CKG_EN_venc_axi2ahb_ckg_en_START (2)
#define SOC_MEDIA1_CRG_VENC_CKG_EN_venc_axi2ahb_ckg_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdec_subctrl_cfg_clkgate_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 29;
    } reg;
} SOC_MEDIA1_CRG_VDEC_CLK_EN_UNION;
#endif
#define SOC_MEDIA1_CRG_VDEC_CLK_EN_vdec_subctrl_cfg_clkgate_en_START (0)
#define SOC_MEDIA1_CRG_VDEC_CLK_EN_vdec_subctrl_cfg_clkgate_en_END (0)
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
} SOC_MEDIA1_CRG_DECPROT0SET_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
