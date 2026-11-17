#ifndef __SOC_IPP_TOP_INTERFACE_H__
#define __SOC_IPP_TOP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IPP_TOP_DMA_CRG_CFG0_ADDR(base) ((base) + (0x0UL))
#define SOC_IPP_TOP_DMA_CRG_CFG1_ADDR(base) ((base) + (0x4UL))
#define SOC_IPP_TOP_DMA_CRG_CFG2_ADDR(base) ((base) + (0x8UL))
#define SOC_IPP_TOP_CVDR_IRQ_REG0_ADDR(base) ((base) + (0x10UL))
#define SOC_IPP_TOP_CVDR_IRQ_REG1_ADDR(base) ((base) + (0x14UL))
#define SOC_IPP_TOP_CVDR_IRQ_REG2_ADDR(base) ((base) + (0x18UL))
#define SOC_IPP_TOP_CVDR_MEM_CFG0_ADDR(base) ((base) + (0x20UL))
#define SOC_IPP_TOP_CVDR_MEM_CFG1_ADDR(base) ((base) + (0x24UL))
#define SOC_IPP_TOP_DPM_CTRL_ADDR(base) ((base) + (0x28UL))
#define SOC_IPP_TOP_IPP_RESERVED_ADDR(base) ((base) + (0x7CUL))
#define SOC_IPP_TOP_JPG_FLUX_CTRL0_0_ADDR(base) ((base) + (0x80UL))
#define SOC_IPP_TOP_JPG_FLUX_CTRL0_1_ADDR(base) ((base) + (0x84UL))
#define SOC_IPP_TOP_JPG_FLUX_CTRL1_0_ADDR(base) ((base) + (0x88UL))
#define SOC_IPP_TOP_JPG_FLUX_CTRL1_1_ADDR(base) ((base) + (0x8CUL))
#define SOC_IPP_TOP_JPG_BWC_CHN_AR_ADDR(base) ((base) + (0xF0UL))
#define SOC_IPP_TOP_JPG_RO_STATE_ADDR(base) ((base) + (0xFCUL))
#define SOC_IPP_TOP_JPGENC_CRG_CFG0_ADDR(base) ((base) + (0x100UL))
#define SOC_IPP_TOP_JPGENC_CRG_CFG1_ADDR(base) ((base) + (0x104UL))
#define SOC_IPP_TOP_JPGENC_MEM_CFG_ADDR(base) ((base) + (0x108UL))
#define SOC_IPP_TOP_JPGENC_IRQ_REG0_ADDR(base) ((base) + (0x110UL))
#define SOC_IPP_TOP_JPGENC_IRQ_REG1_ADDR(base) ((base) + (0x114UL))
#define SOC_IPP_TOP_JPGENC_IRQ_REG2_ADDR(base) ((base) + (0x118UL))
#define SOC_IPP_TOP_JPGDEC_CRG_CFG0_ADDR(base) ((base) + (0x180UL))
#define SOC_IPP_TOP_JPGDEC_CRG_CFG1_ADDR(base) ((base) + (0x184UL))
#define SOC_IPP_TOP_JPGDEC_MEM_CFG_ADDR(base) ((base) + (0x188UL))
#define SOC_IPP_TOP_JPGDEC_IRQ_REG0_ADDR(base) ((base) + (0x190UL))
#define SOC_IPP_TOP_JPGDEC_IRQ_REG1_ADDR(base) ((base) + (0x194UL))
#define SOC_IPP_TOP_JPGDEC_IRQ_REG2_ADDR(base) ((base) + (0x198UL))
#define SOC_IPP_TOP_GF_CRG_CFG0_ADDR(base) ((base) + (0x200UL))
#define SOC_IPP_TOP_GF_CRG_CFG1_ADDR(base) ((base) + (0x204UL))
#define SOC_IPP_TOP_GF_MEM_CFG_ADDR(base) ((base) + (0x208UL))
#define SOC_IPP_TOP_GF_IRQ_REG0_ADDR(base) ((base) + (0x210UL))
#define SOC_IPP_TOP_GF_IRQ_REG1_ADDR(base) ((base) + (0x214UL))
#define SOC_IPP_TOP_GF_IRQ_REG2_ADDR(base) ((base) + (0x218UL))
#define SOC_IPP_TOP_ORB_CRG_CFG0_ADDR(base) ((base) + (0x280UL))
#define SOC_IPP_TOP_ORB_CRG_CFG1_ADDR(base) ((base) + (0x284UL))
#define SOC_IPP_TOP_ORB_MEM_CFG_ADDR(base) ((base) + (0x288UL))
#define SOC_IPP_TOP_ORB_IRQ_REG0_ADDR(base) ((base) + (0x290UL))
#define SOC_IPP_TOP_ORB_IRQ_REG1_ADDR(base) ((base) + (0x294UL))
#define SOC_IPP_TOP_ORB_IRQ_REG2_ADDR(base) ((base) + (0x298UL))
#define SOC_IPP_TOP_RDR_CRG_CFG0_ADDR(base) ((base) + (0x300UL))
#define SOC_IPP_TOP_RDR_CRG_CFG1_ADDR(base) ((base) + (0x304UL))
#define SOC_IPP_TOP_RDR_MEM_CFG_ADDR(base) ((base) + (0x308UL))
#define SOC_IPP_TOP_RDR_IRQ_REG0_ADDR(base) ((base) + (0x310UL))
#define SOC_IPP_TOP_RDR_IRQ_REG1_ADDR(base) ((base) + (0x314UL))
#define SOC_IPP_TOP_RDR_IRQ_REG2_ADDR(base) ((base) + (0x318UL))
#define SOC_IPP_TOP_CMP_CRG_CFG0_ADDR(base) ((base) + (0x380UL))
#define SOC_IPP_TOP_CMP_CRG_CFG1_ADDR(base) ((base) + (0x384UL))
#define SOC_IPP_TOP_CMP_MEM_CFG_ADDR(base) ((base) + (0x388UL))
#define SOC_IPP_TOP_CMP_IRQ_REG0_ADDR(base) ((base) + (0x390UL))
#define SOC_IPP_TOP_CMP_IRQ_REG1_ADDR(base) ((base) + (0x394UL))
#define SOC_IPP_TOP_CMP_IRQ_REG2_ADDR(base) ((base) + (0x398UL))
#define SOC_IPP_TOP_ENH_CRG_CFG0_ADDR(base) ((base) + (0x400UL))
#define SOC_IPP_TOP_ENH_CRG_CFG1_ADDR(base) ((base) + (0x404UL))
#define SOC_IPP_TOP_ENH_MEM_CFG_ADDR(base) ((base) + (0x408UL))
#define SOC_IPP_TOP_ENH_VPB_CFG_ADDR(base) ((base) + (0x40CUL))
#define SOC_IPP_TOP_ENH_IRQ_REG0_ADDR(base) ((base) + (0x410UL))
#define SOC_IPP_TOP_ENH_IRQ_REG1_ADDR(base) ((base) + (0x414UL))
#define SOC_IPP_TOP_ENH_IRQ_REG2_ADDR(base) ((base) + (0x418UL))
#define SOC_IPP_TOP_VBK_CRG_CFG0_ADDR(base) ((base) + (0x480UL))
#define SOC_IPP_TOP_VBK_CRG_CFG1_ADDR(base) ((base) + (0x484UL))
#define SOC_IPP_TOP_VBK_MEM_CFG_ADDR(base) ((base) + (0x488UL))
#define SOC_IPP_TOP_VBK_IRQ_REG0_ADDR(base) ((base) + (0x48CUL))
#define SOC_IPP_TOP_VBK_IRQ_REG1_ADDR(base) ((base) + (0x490UL))
#define SOC_IPP_TOP_VBK_IRQ_REG2_ADDR(base) ((base) + (0x494UL))
#define SOC_IPP_TOP_VBK_IRQ_REG3_ADDR(base) ((base) + (0x498UL))
#define SOC_IPP_TOP_VBK_IRQ_REG4_ADDR(base) ((base) + (0x49CUL))
#define SOC_IPP_TOP_ANF_CRG_CFG0_ADDR(base) ((base) + (0x4C0UL))
#define SOC_IPP_TOP_ANF_CRG_CFG1_ADDR(base) ((base) + (0x4C4UL))
#define SOC_IPP_TOP_ANF_MEM_CFG_ADDR(base) ((base) + (0x4C8UL))
#define SOC_IPP_TOP_ANF_IRQ_REG0_ADDR(base) ((base) + (0x4CCUL))
#define SOC_IPP_TOP_ANF_IRQ_REG1_ADDR(base) ((base) + (0x4D0UL))
#define SOC_IPP_TOP_ANF_IRQ_REG2_ADDR(base) ((base) + (0x4D4UL))
#define SOC_IPP_TOP_ANF_IRQ_REG3_ADDR(base) ((base) + (0x4D8UL))
#define SOC_IPP_TOP_ANF_IRQ_REG4_ADDR(base) ((base) + (0x4DCUL))
#define SOC_IPP_TOP_CMDLST_CTRL_MAP_ADDR(base,Range16) ((base) + (0x500+0x10*(Range16)))
#define SOC_IPP_TOP_CMDLST_CTRL_PM_ADDR(base,Range16) ((base) + (0x504+0x10*(Range16)))
#define SOC_IPP_TOP_CMDLST_IRQ_CLR_ADDR(base,Range6) ((base) + (0x600+0x10*(Range6)))
#define SOC_IPP_TOP_CMDLST_IRQ_MSK_ADDR(base,Range6) ((base) + (0x604+0x10*(Range6)))
#define SOC_IPP_TOP_CMDLST_IRQ_STA_ADDR(base,Range6) ((base) + (0x608+0x10*(Range6)))
#define SOC_IPP_TOP_JPG_DEBUG_0_ADDR(base) ((base) + (0x700UL))
#define SOC_IPP_TOP_JPG_DEBUG_1_ADDR(base) ((base) + (0x704UL))
#define SOC_IPP_TOP_JPG_DEBUG_2_ADDR(base) ((base) + (0x708UL))
#define SOC_IPP_TOP_JPG_DEBUG_3_ADDR(base) ((base) + (0x70CUL))
#define SOC_IPP_TOP_JPG_SEC_CTRL_S_ADDR(base) ((base) + (0x800UL))
#else
#define SOC_IPP_TOP_DMA_CRG_CFG0_ADDR(base) ((base) + (0x0))
#define SOC_IPP_TOP_DMA_CRG_CFG1_ADDR(base) ((base) + (0x4))
#define SOC_IPP_TOP_DMA_CRG_CFG2_ADDR(base) ((base) + (0x8))
#define SOC_IPP_TOP_CVDR_IRQ_REG0_ADDR(base) ((base) + (0x10))
#define SOC_IPP_TOP_CVDR_IRQ_REG1_ADDR(base) ((base) + (0x14))
#define SOC_IPP_TOP_CVDR_IRQ_REG2_ADDR(base) ((base) + (0x18))
#define SOC_IPP_TOP_CVDR_MEM_CFG0_ADDR(base) ((base) + (0x20))
#define SOC_IPP_TOP_CVDR_MEM_CFG1_ADDR(base) ((base) + (0x24))
#define SOC_IPP_TOP_DPM_CTRL_ADDR(base) ((base) + (0x28))
#define SOC_IPP_TOP_IPP_RESERVED_ADDR(base) ((base) + (0x7C))
#define SOC_IPP_TOP_JPG_FLUX_CTRL0_0_ADDR(base) ((base) + (0x80))
#define SOC_IPP_TOP_JPG_FLUX_CTRL0_1_ADDR(base) ((base) + (0x84))
#define SOC_IPP_TOP_JPG_FLUX_CTRL1_0_ADDR(base) ((base) + (0x88))
#define SOC_IPP_TOP_JPG_FLUX_CTRL1_1_ADDR(base) ((base) + (0x8C))
#define SOC_IPP_TOP_JPG_BWC_CHN_AR_ADDR(base) ((base) + (0xF0))
#define SOC_IPP_TOP_JPG_RO_STATE_ADDR(base) ((base) + (0xFC))
#define SOC_IPP_TOP_JPGENC_CRG_CFG0_ADDR(base) ((base) + (0x100))
#define SOC_IPP_TOP_JPGENC_CRG_CFG1_ADDR(base) ((base) + (0x104))
#define SOC_IPP_TOP_JPGENC_MEM_CFG_ADDR(base) ((base) + (0x108))
#define SOC_IPP_TOP_JPGENC_IRQ_REG0_ADDR(base) ((base) + (0x110))
#define SOC_IPP_TOP_JPGENC_IRQ_REG1_ADDR(base) ((base) + (0x114))
#define SOC_IPP_TOP_JPGENC_IRQ_REG2_ADDR(base) ((base) + (0x118))
#define SOC_IPP_TOP_JPGDEC_CRG_CFG0_ADDR(base) ((base) + (0x180))
#define SOC_IPP_TOP_JPGDEC_CRG_CFG1_ADDR(base) ((base) + (0x184))
#define SOC_IPP_TOP_JPGDEC_MEM_CFG_ADDR(base) ((base) + (0x188))
#define SOC_IPP_TOP_JPGDEC_IRQ_REG0_ADDR(base) ((base) + (0x190))
#define SOC_IPP_TOP_JPGDEC_IRQ_REG1_ADDR(base) ((base) + (0x194))
#define SOC_IPP_TOP_JPGDEC_IRQ_REG2_ADDR(base) ((base) + (0x198))
#define SOC_IPP_TOP_GF_CRG_CFG0_ADDR(base) ((base) + (0x200))
#define SOC_IPP_TOP_GF_CRG_CFG1_ADDR(base) ((base) + (0x204))
#define SOC_IPP_TOP_GF_MEM_CFG_ADDR(base) ((base) + (0x208))
#define SOC_IPP_TOP_GF_IRQ_REG0_ADDR(base) ((base) + (0x210))
#define SOC_IPP_TOP_GF_IRQ_REG1_ADDR(base) ((base) + (0x214))
#define SOC_IPP_TOP_GF_IRQ_REG2_ADDR(base) ((base) + (0x218))
#define SOC_IPP_TOP_ORB_CRG_CFG0_ADDR(base) ((base) + (0x280))
#define SOC_IPP_TOP_ORB_CRG_CFG1_ADDR(base) ((base) + (0x284))
#define SOC_IPP_TOP_ORB_MEM_CFG_ADDR(base) ((base) + (0x288))
#define SOC_IPP_TOP_ORB_IRQ_REG0_ADDR(base) ((base) + (0x290))
#define SOC_IPP_TOP_ORB_IRQ_REG1_ADDR(base) ((base) + (0x294))
#define SOC_IPP_TOP_ORB_IRQ_REG2_ADDR(base) ((base) + (0x298))
#define SOC_IPP_TOP_RDR_CRG_CFG0_ADDR(base) ((base) + (0x300))
#define SOC_IPP_TOP_RDR_CRG_CFG1_ADDR(base) ((base) + (0x304))
#define SOC_IPP_TOP_RDR_MEM_CFG_ADDR(base) ((base) + (0x308))
#define SOC_IPP_TOP_RDR_IRQ_REG0_ADDR(base) ((base) + (0x310))
#define SOC_IPP_TOP_RDR_IRQ_REG1_ADDR(base) ((base) + (0x314))
#define SOC_IPP_TOP_RDR_IRQ_REG2_ADDR(base) ((base) + (0x318))
#define SOC_IPP_TOP_CMP_CRG_CFG0_ADDR(base) ((base) + (0x380))
#define SOC_IPP_TOP_CMP_CRG_CFG1_ADDR(base) ((base) + (0x384))
#define SOC_IPP_TOP_CMP_MEM_CFG_ADDR(base) ((base) + (0x388))
#define SOC_IPP_TOP_CMP_IRQ_REG0_ADDR(base) ((base) + (0x390))
#define SOC_IPP_TOP_CMP_IRQ_REG1_ADDR(base) ((base) + (0x394))
#define SOC_IPP_TOP_CMP_IRQ_REG2_ADDR(base) ((base) + (0x398))
#define SOC_IPP_TOP_ENH_CRG_CFG0_ADDR(base) ((base) + (0x400))
#define SOC_IPP_TOP_ENH_CRG_CFG1_ADDR(base) ((base) + (0x404))
#define SOC_IPP_TOP_ENH_MEM_CFG_ADDR(base) ((base) + (0x408))
#define SOC_IPP_TOP_ENH_VPB_CFG_ADDR(base) ((base) + (0x40C))
#define SOC_IPP_TOP_ENH_IRQ_REG0_ADDR(base) ((base) + (0x410))
#define SOC_IPP_TOP_ENH_IRQ_REG1_ADDR(base) ((base) + (0x414))
#define SOC_IPP_TOP_ENH_IRQ_REG2_ADDR(base) ((base) + (0x418))
#define SOC_IPP_TOP_VBK_CRG_CFG0_ADDR(base) ((base) + (0x480))
#define SOC_IPP_TOP_VBK_CRG_CFG1_ADDR(base) ((base) + (0x484))
#define SOC_IPP_TOP_VBK_MEM_CFG_ADDR(base) ((base) + (0x488))
#define SOC_IPP_TOP_VBK_IRQ_REG0_ADDR(base) ((base) + (0x48C))
#define SOC_IPP_TOP_VBK_IRQ_REG1_ADDR(base) ((base) + (0x490))
#define SOC_IPP_TOP_VBK_IRQ_REG2_ADDR(base) ((base) + (0x494))
#define SOC_IPP_TOP_VBK_IRQ_REG3_ADDR(base) ((base) + (0x498))
#define SOC_IPP_TOP_VBK_IRQ_REG4_ADDR(base) ((base) + (0x49C))
#define SOC_IPP_TOP_ANF_CRG_CFG0_ADDR(base) ((base) + (0x4C0))
#define SOC_IPP_TOP_ANF_CRG_CFG1_ADDR(base) ((base) + (0x4C4))
#define SOC_IPP_TOP_ANF_MEM_CFG_ADDR(base) ((base) + (0x4C8))
#define SOC_IPP_TOP_ANF_IRQ_REG0_ADDR(base) ((base) + (0x4CC))
#define SOC_IPP_TOP_ANF_IRQ_REG1_ADDR(base) ((base) + (0x4D0))
#define SOC_IPP_TOP_ANF_IRQ_REG2_ADDR(base) ((base) + (0x4D4))
#define SOC_IPP_TOP_ANF_IRQ_REG3_ADDR(base) ((base) + (0x4D8))
#define SOC_IPP_TOP_ANF_IRQ_REG4_ADDR(base) ((base) + (0x4DC))
#define SOC_IPP_TOP_CMDLST_CTRL_MAP_ADDR(base,Range16) ((base) + (0x500+0x10*(Range16)))
#define SOC_IPP_TOP_CMDLST_CTRL_PM_ADDR(base,Range16) ((base) + (0x504+0x10*(Range16)))
#define SOC_IPP_TOP_CMDLST_IRQ_CLR_ADDR(base,Range6) ((base) + (0x600+0x10*(Range6)))
#define SOC_IPP_TOP_CMDLST_IRQ_MSK_ADDR(base,Range6) ((base) + (0x604+0x10*(Range6)))
#define SOC_IPP_TOP_CMDLST_IRQ_STA_ADDR(base,Range6) ((base) + (0x608+0x10*(Range6)))
#define SOC_IPP_TOP_JPG_DEBUG_0_ADDR(base) ((base) + (0x700))
#define SOC_IPP_TOP_JPG_DEBUG_1_ADDR(base) ((base) + (0x704))
#define SOC_IPP_TOP_JPG_DEBUG_2_ADDR(base) ((base) + (0x708))
#define SOC_IPP_TOP_JPG_DEBUG_3_ADDR(base) ((base) + (0x70C))
#define SOC_IPP_TOP_JPG_SEC_CTRL_S_ADDR(base) ((base) + (0x800))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpg_dw_axi_gatedclock_en : 1;
        unsigned int reserved_0 : 15;
        unsigned int control_disable_axi_data_packing : 1;
        unsigned int mst_priority_cvdr : 2;
        unsigned int mst_priority_pac0 : 2;
        unsigned int mst_priority_pac1 : 2;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_IPP_TOP_DMA_CRG_CFG0_UNION;
#endif
#define SOC_IPP_TOP_DMA_CRG_CFG0_jpg_dw_axi_gatedclock_en_START (0)
#define SOC_IPP_TOP_DMA_CRG_CFG0_jpg_dw_axi_gatedclock_en_END (0)
#define SOC_IPP_TOP_DMA_CRG_CFG0_control_disable_axi_data_packing_START (16)
#define SOC_IPP_TOP_DMA_CRG_CFG0_control_disable_axi_data_packing_END (16)
#define SOC_IPP_TOP_DMA_CRG_CFG0_mst_priority_cvdr_START (17)
#define SOC_IPP_TOP_DMA_CRG_CFG0_mst_priority_cvdr_END (18)
#define SOC_IPP_TOP_DMA_CRG_CFG0_mst_priority_pac0_START (19)
#define SOC_IPP_TOP_DMA_CRG_CFG0_mst_priority_pac0_END (20)
#define SOC_IPP_TOP_DMA_CRG_CFG0_mst_priority_pac1_START (21)
#define SOC_IPP_TOP_DMA_CRG_CFG0_mst_priority_pac1_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_clken : 1;
        unsigned int tbu_cvdr_clken : 1;
        unsigned int reserved_0 : 1;
        unsigned int cmdlst_clken : 1;
        unsigned int dpm_clken : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_IPP_TOP_DMA_CRG_CFG1_UNION;
#endif
#define SOC_IPP_TOP_DMA_CRG_CFG1_cvdr_clken_START (0)
#define SOC_IPP_TOP_DMA_CRG_CFG1_cvdr_clken_END (0)
#define SOC_IPP_TOP_DMA_CRG_CFG1_tbu_cvdr_clken_START (1)
#define SOC_IPP_TOP_DMA_CRG_CFG1_tbu_cvdr_clken_END (1)
#define SOC_IPP_TOP_DMA_CRG_CFG1_cmdlst_clken_START (3)
#define SOC_IPP_TOP_DMA_CRG_CFG1_cmdlst_clken_END (3)
#define SOC_IPP_TOP_DMA_CRG_CFG1_dpm_clken_START (4)
#define SOC_IPP_TOP_DMA_CRG_CFG1_dpm_clken_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_soft_rst : 1;
        unsigned int tbu_cvdr_soft_rst : 1;
        unsigned int reserved_0 : 1;
        unsigned int cmdlst_soft_rst : 1;
        unsigned int dpm_soft_rst : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_IPP_TOP_DMA_CRG_CFG2_UNION;
#endif
#define SOC_IPP_TOP_DMA_CRG_CFG2_cvdr_soft_rst_START (0)
#define SOC_IPP_TOP_DMA_CRG_CFG2_cvdr_soft_rst_END (0)
#define SOC_IPP_TOP_DMA_CRG_CFG2_tbu_cvdr_soft_rst_START (1)
#define SOC_IPP_TOP_DMA_CRG_CFG2_tbu_cvdr_soft_rst_END (1)
#define SOC_IPP_TOP_DMA_CRG_CFG2_cmdlst_soft_rst_START (3)
#define SOC_IPP_TOP_DMA_CRG_CFG2_cmdlst_soft_rst_END (3)
#define SOC_IPP_TOP_DMA_CRG_CFG2_dpm_soft_rst_START (4)
#define SOC_IPP_TOP_DMA_CRG_CFG2_dpm_soft_rst_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_irq_clr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_IPP_TOP_CVDR_IRQ_REG0_UNION;
#endif
#define SOC_IPP_TOP_CVDR_IRQ_REG0_cvdr_irq_clr_START (0)
#define SOC_IPP_TOP_CVDR_IRQ_REG0_cvdr_irq_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_irq_mask : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_IPP_TOP_CVDR_IRQ_REG1_UNION;
#endif
#define SOC_IPP_TOP_CVDR_IRQ_REG1_cvdr_irq_mask_START (0)
#define SOC_IPP_TOP_CVDR_IRQ_REG1_cvdr_irq_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_irq_state_mask : 8;
        unsigned int reserved_0 : 8;
        unsigned int cvdr_irq_state_raw : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_IPP_TOP_CVDR_IRQ_REG2_UNION;
#endif
#define SOC_IPP_TOP_CVDR_IRQ_REG2_cvdr_irq_state_mask_START (0)
#define SOC_IPP_TOP_CVDR_IRQ_REG2_cvdr_irq_state_mask_END (7)
#define SOC_IPP_TOP_CVDR_IRQ_REG2_cvdr_irq_state_raw_START (16)
#define SOC_IPP_TOP_CVDR_IRQ_REG2_cvdr_irq_state_raw_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_mem_ctrl_sp : 3;
        unsigned int mem_ctrl_sp : 29;
    } reg;
} SOC_IPP_TOP_CVDR_MEM_CFG0_UNION;
#endif
#define SOC_IPP_TOP_CVDR_MEM_CFG0_cvdr_mem_ctrl_sp_START (0)
#define SOC_IPP_TOP_CVDR_MEM_CFG0_cvdr_mem_ctrl_sp_END (2)
#define SOC_IPP_TOP_CVDR_MEM_CFG0_mem_ctrl_sp_START (3)
#define SOC_IPP_TOP_CVDR_MEM_CFG0_mem_ctrl_sp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 3;
        unsigned int mem_ctrl_tp : 29;
    } reg;
} SOC_IPP_TOP_CVDR_MEM_CFG1_UNION;
#endif
#define SOC_IPP_TOP_CVDR_MEM_CFG1_mem_ctrl_tp_START (3)
#define SOC_IPP_TOP_CVDR_MEM_CFG1_mem_ctrl_tp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpm_freq_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IPP_TOP_DPM_CTRL_UNION;
#endif
#define SOC_IPP_TOP_DPM_CTRL_dpm_freq_sel_START (0)
#define SOC_IPP_TOP_DPM_CTRL_dpm_freq_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_IPP_TOP_IPP_RESERVED_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_cvdr_r : 32;
    } reg;
} SOC_IPP_TOP_JPG_FLUX_CTRL0_0_UNION;
#endif
#define SOC_IPP_TOP_JPG_FLUX_CTRL0_0_flux_ctrl0_cvdr_r_START (0)
#define SOC_IPP_TOP_JPG_FLUX_CTRL0_0_flux_ctrl0_cvdr_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_cvdr_r : 32;
    } reg;
} SOC_IPP_TOP_JPG_FLUX_CTRL0_1_UNION;
#endif
#define SOC_IPP_TOP_JPG_FLUX_CTRL0_1_flux_ctrl1_cvdr_r_START (0)
#define SOC_IPP_TOP_JPG_FLUX_CTRL0_1_flux_ctrl1_cvdr_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_cvdr_w : 32;
    } reg;
} SOC_IPP_TOP_JPG_FLUX_CTRL1_0_UNION;
#endif
#define SOC_IPP_TOP_JPG_FLUX_CTRL1_0_flux_ctrl0_cvdr_w_START (0)
#define SOC_IPP_TOP_JPG_FLUX_CTRL1_0_flux_ctrl0_cvdr_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_cvdr_w : 32;
    } reg;
} SOC_IPP_TOP_JPG_FLUX_CTRL1_1_UNION;
#endif
#define SOC_IPP_TOP_JPG_FLUX_CTRL1_1_flux_ctrl1_cvdr_w_START (0)
#define SOC_IPP_TOP_JPG_FLUX_CTRL1_1_flux_ctrl1_cvdr_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpg_bwc_cfg : 32;
    } reg;
} SOC_IPP_TOP_JPG_BWC_CHN_AR_UNION;
#endif
#define SOC_IPP_TOP_JPG_BWC_CHN_AR_jpg_bwc_cfg_START (0)
#define SOC_IPP_TOP_JPG_BWC_CHN_AR_jpg_bwc_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int jpg_axi_dlock_irq : 1;
        unsigned int jpg_axi_dlock_wr : 1;
        unsigned int jpg_axi_dlock_slv : 1;
        unsigned int jpg_axi_dlock_mst : 1;
        unsigned int jpg_axi_dlock_id : 8;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_IPP_TOP_JPG_RO_STATE_UNION;
#endif
#define SOC_IPP_TOP_JPG_RO_STATE_jpg_axi_dlock_irq_START (16)
#define SOC_IPP_TOP_JPG_RO_STATE_jpg_axi_dlock_irq_END (16)
#define SOC_IPP_TOP_JPG_RO_STATE_jpg_axi_dlock_wr_START (17)
#define SOC_IPP_TOP_JPG_RO_STATE_jpg_axi_dlock_wr_END (17)
#define SOC_IPP_TOP_JPG_RO_STATE_jpg_axi_dlock_slv_START (18)
#define SOC_IPP_TOP_JPG_RO_STATE_jpg_axi_dlock_slv_END (18)
#define SOC_IPP_TOP_JPG_RO_STATE_jpg_axi_dlock_mst_START (19)
#define SOC_IPP_TOP_JPG_RO_STATE_jpg_axi_dlock_mst_END (19)
#define SOC_IPP_TOP_JPG_RO_STATE_jpg_axi_dlock_id_START (20)
#define SOC_IPP_TOP_JPG_RO_STATE_jpg_axi_dlock_id_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgenc_clken : 1;
        unsigned int reserved_0 : 15;
        unsigned int jpgenc_force_clk_on : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_IPP_TOP_JPGENC_CRG_CFG0_UNION;
#endif
#define SOC_IPP_TOP_JPGENC_CRG_CFG0_jpgenc_clken_START (0)
#define SOC_IPP_TOP_JPGENC_CRG_CFG0_jpgenc_clken_END (0)
#define SOC_IPP_TOP_JPGENC_CRG_CFG0_jpgenc_force_clk_on_START (16)
#define SOC_IPP_TOP_JPGENC_CRG_CFG0_jpgenc_force_clk_on_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgenc_soft_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IPP_TOP_JPGENC_CRG_CFG1_UNION;
#endif
#define SOC_IPP_TOP_JPGENC_CRG_CFG1_jpgenc_soft_rst_START (0)
#define SOC_IPP_TOP_JPGENC_CRG_CFG1_jpgenc_soft_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgenc_mem_ctrl_sp : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IPP_TOP_JPGENC_MEM_CFG_UNION;
#endif
#define SOC_IPP_TOP_JPGENC_MEM_CFG_jpgenc_mem_ctrl_sp_START (0)
#define SOC_IPP_TOP_JPGENC_MEM_CFG_jpgenc_mem_ctrl_sp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgenc_irq_clr : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_IPP_TOP_JPGENC_IRQ_REG0_UNION;
#endif
#define SOC_IPP_TOP_JPGENC_IRQ_REG0_jpgenc_irq_clr_START (0)
#define SOC_IPP_TOP_JPGENC_IRQ_REG0_jpgenc_irq_clr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgenc_irq_mask : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_IPP_TOP_JPGENC_IRQ_REG1_UNION;
#endif
#define SOC_IPP_TOP_JPGENC_IRQ_REG1_jpgenc_irq_mask_START (0)
#define SOC_IPP_TOP_JPGENC_IRQ_REG1_jpgenc_irq_mask_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgenc_irq_state_mask : 5;
        unsigned int reserved_0 : 11;
        unsigned int jpgenc_irq_state_raw : 5;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_IPP_TOP_JPGENC_IRQ_REG2_UNION;
#endif
#define SOC_IPP_TOP_JPGENC_IRQ_REG2_jpgenc_irq_state_mask_START (0)
#define SOC_IPP_TOP_JPGENC_IRQ_REG2_jpgenc_irq_state_mask_END (4)
#define SOC_IPP_TOP_JPGENC_IRQ_REG2_jpgenc_irq_state_raw_START (16)
#define SOC_IPP_TOP_JPGENC_IRQ_REG2_jpgenc_irq_state_raw_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_clken : 1;
        unsigned int reserved_0 : 15;
        unsigned int jpgdec_force_clk_on : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_IPP_TOP_JPGDEC_CRG_CFG0_UNION;
#endif
#define SOC_IPP_TOP_JPGDEC_CRG_CFG0_jpgdec_clken_START (0)
#define SOC_IPP_TOP_JPGDEC_CRG_CFG0_jpgdec_clken_END (0)
#define SOC_IPP_TOP_JPGDEC_CRG_CFG0_jpgdec_force_clk_on_START (16)
#define SOC_IPP_TOP_JPGDEC_CRG_CFG0_jpgdec_force_clk_on_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_soft_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IPP_TOP_JPGDEC_CRG_CFG1_UNION;
#endif
#define SOC_IPP_TOP_JPGDEC_CRG_CFG1_jpgdec_soft_rst_START (0)
#define SOC_IPP_TOP_JPGDEC_CRG_CFG1_jpgdec_soft_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_mem_ctrl_sp : 3;
        unsigned int reserved_0 : 1;
        unsigned int jpgdec_mem_ctrl_tp : 3;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_IPP_TOP_JPGDEC_MEM_CFG_UNION;
#endif
#define SOC_IPP_TOP_JPGDEC_MEM_CFG_jpgdec_mem_ctrl_sp_START (0)
#define SOC_IPP_TOP_JPGDEC_MEM_CFG_jpgdec_mem_ctrl_sp_END (2)
#define SOC_IPP_TOP_JPGDEC_MEM_CFG_jpgdec_mem_ctrl_tp_START (4)
#define SOC_IPP_TOP_JPGDEC_MEM_CFG_jpgdec_mem_ctrl_tp_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_irq_clr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_IPP_TOP_JPGDEC_IRQ_REG0_UNION;
#endif
#define SOC_IPP_TOP_JPGDEC_IRQ_REG0_jpgdec_irq_clr_START (0)
#define SOC_IPP_TOP_JPGDEC_IRQ_REG0_jpgdec_irq_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_irq_mask : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_IPP_TOP_JPGDEC_IRQ_REG1_UNION;
#endif
#define SOC_IPP_TOP_JPGDEC_IRQ_REG1_jpgdec_irq_mask_START (0)
#define SOC_IPP_TOP_JPGDEC_IRQ_REG1_jpgdec_irq_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_irq_state_mask : 4;
        unsigned int reserved_0 : 12;
        unsigned int jpgdec_irq_state_raw : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_IPP_TOP_JPGDEC_IRQ_REG2_UNION;
#endif
#define SOC_IPP_TOP_JPGDEC_IRQ_REG2_jpgdec_irq_state_mask_START (0)
#define SOC_IPP_TOP_JPGDEC_IRQ_REG2_jpgdec_irq_state_mask_END (3)
#define SOC_IPP_TOP_JPGDEC_IRQ_REG2_jpgdec_irq_state_raw_START (16)
#define SOC_IPP_TOP_JPGDEC_IRQ_REG2_jpgdec_irq_state_raw_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gf_clken : 1;
        unsigned int reserved_0 : 15;
        unsigned int gf_force_clk_on : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_IPP_TOP_GF_CRG_CFG0_UNION;
#endif
#define SOC_IPP_TOP_GF_CRG_CFG0_gf_clken_START (0)
#define SOC_IPP_TOP_GF_CRG_CFG0_gf_clken_END (0)
#define SOC_IPP_TOP_GF_CRG_CFG0_gf_force_clk_on_START (16)
#define SOC_IPP_TOP_GF_CRG_CFG0_gf_force_clk_on_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gf_soft_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IPP_TOP_GF_CRG_CFG1_UNION;
#endif
#define SOC_IPP_TOP_GF_CRG_CFG1_gf_soft_rst_START (0)
#define SOC_IPP_TOP_GF_CRG_CFG1_gf_soft_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gf_mem_ctrl_sp : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IPP_TOP_GF_MEM_CFG_UNION;
#endif
#define SOC_IPP_TOP_GF_MEM_CFG_gf_mem_ctrl_sp_START (0)
#define SOC_IPP_TOP_GF_MEM_CFG_gf_mem_ctrl_sp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gf_irq_clr : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_IPP_TOP_GF_IRQ_REG0_UNION;
#endif
#define SOC_IPP_TOP_GF_IRQ_REG0_gf_irq_clr_START (0)
#define SOC_IPP_TOP_GF_IRQ_REG0_gf_irq_clr_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gf_irq_mask : 13;
        unsigned int reserved_0 : 3;
        unsigned int gf_irq_outen : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_IPP_TOP_GF_IRQ_REG1_UNION;
#endif
#define SOC_IPP_TOP_GF_IRQ_REG1_gf_irq_mask_START (0)
#define SOC_IPP_TOP_GF_IRQ_REG1_gf_irq_mask_END (12)
#define SOC_IPP_TOP_GF_IRQ_REG1_gf_irq_outen_START (16)
#define SOC_IPP_TOP_GF_IRQ_REG1_gf_irq_outen_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gf_irq_state_raw : 13;
        unsigned int reserved_0 : 3;
        unsigned int gf_irq_state_mask : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_IPP_TOP_GF_IRQ_REG2_UNION;
#endif
#define SOC_IPP_TOP_GF_IRQ_REG2_gf_irq_state_raw_START (0)
#define SOC_IPP_TOP_GF_IRQ_REG2_gf_irq_state_raw_END (12)
#define SOC_IPP_TOP_GF_IRQ_REG2_gf_irq_state_mask_START (16)
#define SOC_IPP_TOP_GF_IRQ_REG2_gf_irq_state_mask_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int orb_clken : 1;
        unsigned int reserved_0 : 15;
        unsigned int orb_force_clk_on : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_IPP_TOP_ORB_CRG_CFG0_UNION;
#endif
#define SOC_IPP_TOP_ORB_CRG_CFG0_orb_clken_START (0)
#define SOC_IPP_TOP_ORB_CRG_CFG0_orb_clken_END (0)
#define SOC_IPP_TOP_ORB_CRG_CFG0_orb_force_clk_on_START (16)
#define SOC_IPP_TOP_ORB_CRG_CFG0_orb_force_clk_on_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int orb_soft_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IPP_TOP_ORB_CRG_CFG1_UNION;
#endif
#define SOC_IPP_TOP_ORB_CRG_CFG1_orb_soft_rst_START (0)
#define SOC_IPP_TOP_ORB_CRG_CFG1_orb_soft_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int orb_mem_ctrl_sp : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IPP_TOP_ORB_MEM_CFG_UNION;
#endif
#define SOC_IPP_TOP_ORB_MEM_CFG_orb_mem_ctrl_sp_START (0)
#define SOC_IPP_TOP_ORB_MEM_CFG_orb_mem_ctrl_sp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int orb_irq_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IPP_TOP_ORB_IRQ_REG0_UNION;
#endif
#define SOC_IPP_TOP_ORB_IRQ_REG0_orb_irq_clr_START (0)
#define SOC_IPP_TOP_ORB_IRQ_REG0_orb_irq_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int orb_irq_mask : 16;
        unsigned int orb_irq_outen : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_IPP_TOP_ORB_IRQ_REG1_UNION;
#endif
#define SOC_IPP_TOP_ORB_IRQ_REG1_orb_irq_mask_START (0)
#define SOC_IPP_TOP_ORB_IRQ_REG1_orb_irq_mask_END (15)
#define SOC_IPP_TOP_ORB_IRQ_REG1_orb_irq_outen_START (16)
#define SOC_IPP_TOP_ORB_IRQ_REG1_orb_irq_outen_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int orb_irq_state_mask : 16;
        unsigned int orb_irq_state_raw : 16;
    } reg;
} SOC_IPP_TOP_ORB_IRQ_REG2_UNION;
#endif
#define SOC_IPP_TOP_ORB_IRQ_REG2_orb_irq_state_mask_START (0)
#define SOC_IPP_TOP_ORB_IRQ_REG2_orb_irq_state_mask_END (15)
#define SOC_IPP_TOP_ORB_IRQ_REG2_orb_irq_state_raw_START (16)
#define SOC_IPP_TOP_ORB_IRQ_REG2_orb_irq_state_raw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdr_clken : 1;
        unsigned int reserved_0 : 15;
        unsigned int rdr_force_clk_on : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_IPP_TOP_RDR_CRG_CFG0_UNION;
#endif
#define SOC_IPP_TOP_RDR_CRG_CFG0_rdr_clken_START (0)
#define SOC_IPP_TOP_RDR_CRG_CFG0_rdr_clken_END (0)
#define SOC_IPP_TOP_RDR_CRG_CFG0_rdr_force_clk_on_START (16)
#define SOC_IPP_TOP_RDR_CRG_CFG0_rdr_force_clk_on_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdr_soft_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IPP_TOP_RDR_CRG_CFG1_UNION;
#endif
#define SOC_IPP_TOP_RDR_CRG_CFG1_rdr_soft_rst_START (0)
#define SOC_IPP_TOP_RDR_CRG_CFG1_rdr_soft_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdr_mem_ctrl_sp : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IPP_TOP_RDR_MEM_CFG_UNION;
#endif
#define SOC_IPP_TOP_RDR_MEM_CFG_rdr_mem_ctrl_sp_START (0)
#define SOC_IPP_TOP_RDR_MEM_CFG_rdr_mem_ctrl_sp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdr_irq_clr : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_IPP_TOP_RDR_IRQ_REG0_UNION;
#endif
#define SOC_IPP_TOP_RDR_IRQ_REG0_rdr_irq_clr_START (0)
#define SOC_IPP_TOP_RDR_IRQ_REG0_rdr_irq_clr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdr_irq_mask : 5;
        unsigned int reserved_0 : 11;
        unsigned int rdr_irq_outen : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_IPP_TOP_RDR_IRQ_REG1_UNION;
#endif
#define SOC_IPP_TOP_RDR_IRQ_REG1_rdr_irq_mask_START (0)
#define SOC_IPP_TOP_RDR_IRQ_REG1_rdr_irq_mask_END (4)
#define SOC_IPP_TOP_RDR_IRQ_REG1_rdr_irq_outen_START (16)
#define SOC_IPP_TOP_RDR_IRQ_REG1_rdr_irq_outen_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdr_irq_state_mask : 5;
        unsigned int reserved_0 : 11;
        unsigned int rdr_irq_state_raw : 5;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_IPP_TOP_RDR_IRQ_REG2_UNION;
#endif
#define SOC_IPP_TOP_RDR_IRQ_REG2_rdr_irq_state_mask_START (0)
#define SOC_IPP_TOP_RDR_IRQ_REG2_rdr_irq_state_mask_END (4)
#define SOC_IPP_TOP_RDR_IRQ_REG2_rdr_irq_state_raw_START (16)
#define SOC_IPP_TOP_RDR_IRQ_REG2_rdr_irq_state_raw_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmp_clken : 1;
        unsigned int reserved_0 : 15;
        unsigned int cmp_force_clk_on : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_IPP_TOP_CMP_CRG_CFG0_UNION;
#endif
#define SOC_IPP_TOP_CMP_CRG_CFG0_cmp_clken_START (0)
#define SOC_IPP_TOP_CMP_CRG_CFG0_cmp_clken_END (0)
#define SOC_IPP_TOP_CMP_CRG_CFG0_cmp_force_clk_on_START (16)
#define SOC_IPP_TOP_CMP_CRG_CFG0_cmp_force_clk_on_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmp_soft_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IPP_TOP_CMP_CRG_CFG1_UNION;
#endif
#define SOC_IPP_TOP_CMP_CRG_CFG1_cmp_soft_rst_START (0)
#define SOC_IPP_TOP_CMP_CRG_CFG1_cmp_soft_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmp_mem_ctrl_sp : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IPP_TOP_CMP_MEM_CFG_UNION;
#endif
#define SOC_IPP_TOP_CMP_MEM_CFG_cmp_mem_ctrl_sp_START (0)
#define SOC_IPP_TOP_CMP_MEM_CFG_cmp_mem_ctrl_sp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmp_irq_clr : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_IPP_TOP_CMP_IRQ_REG0_UNION;
#endif
#define SOC_IPP_TOP_CMP_IRQ_REG0_cmp_irq_clr_START (0)
#define SOC_IPP_TOP_CMP_IRQ_REG0_cmp_irq_clr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmp_irq_mask : 5;
        unsigned int reserved_0 : 11;
        unsigned int cmp_irq_outen : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_IPP_TOP_CMP_IRQ_REG1_UNION;
#endif
#define SOC_IPP_TOP_CMP_IRQ_REG1_cmp_irq_mask_START (0)
#define SOC_IPP_TOP_CMP_IRQ_REG1_cmp_irq_mask_END (4)
#define SOC_IPP_TOP_CMP_IRQ_REG1_cmp_irq_outen_START (16)
#define SOC_IPP_TOP_CMP_IRQ_REG1_cmp_irq_outen_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmp_irq_state_mask : 5;
        unsigned int reserved_0 : 11;
        unsigned int cmp_irq_state_raw : 5;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_IPP_TOP_CMP_IRQ_REG2_UNION;
#endif
#define SOC_IPP_TOP_CMP_IRQ_REG2_cmp_irq_state_mask_START (0)
#define SOC_IPP_TOP_CMP_IRQ_REG2_cmp_irq_state_mask_END (4)
#define SOC_IPP_TOP_CMP_IRQ_REG2_cmp_irq_state_raw_START (16)
#define SOC_IPP_TOP_CMP_IRQ_REG2_cmp_irq_state_raw_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enh_clken : 1;
        unsigned int reserved_0 : 15;
        unsigned int enh_force_clk_on : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_IPP_TOP_ENH_CRG_CFG0_UNION;
#endif
#define SOC_IPP_TOP_ENH_CRG_CFG0_enh_clken_START (0)
#define SOC_IPP_TOP_ENH_CRG_CFG0_enh_clken_END (0)
#define SOC_IPP_TOP_ENH_CRG_CFG0_enh_force_clk_on_START (16)
#define SOC_IPP_TOP_ENH_CRG_CFG0_enh_force_clk_on_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enh_soft_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IPP_TOP_ENH_CRG_CFG1_UNION;
#endif
#define SOC_IPP_TOP_ENH_CRG_CFG1_enh_soft_rst_START (0)
#define SOC_IPP_TOP_ENH_CRG_CFG1_enh_soft_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enh_mem_ctrl_sp : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IPP_TOP_ENH_MEM_CFG_UNION;
#endif
#define SOC_IPP_TOP_ENH_MEM_CFG_enh_mem_ctrl_sp_START (0)
#define SOC_IPP_TOP_ENH_MEM_CFG_enh_mem_ctrl_sp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enh_vpbg_en : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IPP_TOP_ENH_VPB_CFG_UNION;
#endif
#define SOC_IPP_TOP_ENH_VPB_CFG_enh_vpbg_en_START (0)
#define SOC_IPP_TOP_ENH_VPB_CFG_enh_vpbg_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enh_irq_clr : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_IPP_TOP_ENH_IRQ_REG0_UNION;
#endif
#define SOC_IPP_TOP_ENH_IRQ_REG0_enh_irq_clr_START (0)
#define SOC_IPP_TOP_ENH_IRQ_REG0_enh_irq_clr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enh_irq_mask : 10;
        unsigned int reserved_0 : 6;
        unsigned int enh_irq_outen : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_IPP_TOP_ENH_IRQ_REG1_UNION;
#endif
#define SOC_IPP_TOP_ENH_IRQ_REG1_enh_irq_mask_START (0)
#define SOC_IPP_TOP_ENH_IRQ_REG1_enh_irq_mask_END (9)
#define SOC_IPP_TOP_ENH_IRQ_REG1_enh_irq_outen_START (16)
#define SOC_IPP_TOP_ENH_IRQ_REG1_enh_irq_outen_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enh_irq_state_mask : 10;
        unsigned int reserved_0 : 6;
        unsigned int enh_irq_state_raw : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_IPP_TOP_ENH_IRQ_REG2_UNION;
#endif
#define SOC_IPP_TOP_ENH_IRQ_REG2_enh_irq_state_mask_START (0)
#define SOC_IPP_TOP_ENH_IRQ_REG2_enh_irq_state_mask_END (9)
#define SOC_IPP_TOP_ENH_IRQ_REG2_enh_irq_state_raw_START (16)
#define SOC_IPP_TOP_ENH_IRQ_REG2_enh_irq_state_raw_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vbk_clken : 1;
        unsigned int reserved_0 : 15;
        unsigned int vbk_force_clk_on : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_IPP_TOP_VBK_CRG_CFG0_UNION;
#endif
#define SOC_IPP_TOP_VBK_CRG_CFG0_vbk_clken_START (0)
#define SOC_IPP_TOP_VBK_CRG_CFG0_vbk_clken_END (0)
#define SOC_IPP_TOP_VBK_CRG_CFG0_vbk_force_clk_on_START (16)
#define SOC_IPP_TOP_VBK_CRG_CFG0_vbk_force_clk_on_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vbk_soft_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IPP_TOP_VBK_CRG_CFG1_UNION;
#endif
#define SOC_IPP_TOP_VBK_CRG_CFG1_vbk_soft_rst_START (0)
#define SOC_IPP_TOP_VBK_CRG_CFG1_vbk_soft_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vbk_mem_ctrl_sp : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IPP_TOP_VBK_MEM_CFG_UNION;
#endif
#define SOC_IPP_TOP_VBK_MEM_CFG_vbk_mem_ctrl_sp_START (0)
#define SOC_IPP_TOP_VBK_MEM_CFG_vbk_mem_ctrl_sp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vbk_irq_clr : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IPP_TOP_VBK_IRQ_REG0_UNION;
#endif
#define SOC_IPP_TOP_VBK_IRQ_REG0_vbk_irq_clr_START (0)
#define SOC_IPP_TOP_VBK_IRQ_REG0_vbk_irq_clr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vbk_irq_mask : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IPP_TOP_VBK_IRQ_REG1_UNION;
#endif
#define SOC_IPP_TOP_VBK_IRQ_REG1_vbk_irq_mask_START (0)
#define SOC_IPP_TOP_VBK_IRQ_REG1_vbk_irq_mask_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vbk_irq_outen : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IPP_TOP_VBK_IRQ_REG2_UNION;
#endif
#define SOC_IPP_TOP_VBK_IRQ_REG2_vbk_irq_outen_START (0)
#define SOC_IPP_TOP_VBK_IRQ_REG2_vbk_irq_outen_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vbk_irq_state_mask : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IPP_TOP_VBK_IRQ_REG3_UNION;
#endif
#define SOC_IPP_TOP_VBK_IRQ_REG3_vbk_irq_state_mask_START (0)
#define SOC_IPP_TOP_VBK_IRQ_REG3_vbk_irq_state_mask_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vbk_irq_state_raw : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IPP_TOP_VBK_IRQ_REG4_UNION;
#endif
#define SOC_IPP_TOP_VBK_IRQ_REG4_vbk_irq_state_raw_START (0)
#define SOC_IPP_TOP_VBK_IRQ_REG4_vbk_irq_state_raw_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anf_clken : 1;
        unsigned int reserved_0 : 15;
        unsigned int anf_force_clk_on : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_IPP_TOP_ANF_CRG_CFG0_UNION;
#endif
#define SOC_IPP_TOP_ANF_CRG_CFG0_anf_clken_START (0)
#define SOC_IPP_TOP_ANF_CRG_CFG0_anf_clken_END (0)
#define SOC_IPP_TOP_ANF_CRG_CFG0_anf_force_clk_on_START (16)
#define SOC_IPP_TOP_ANF_CRG_CFG0_anf_force_clk_on_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anf_soft_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IPP_TOP_ANF_CRG_CFG1_UNION;
#endif
#define SOC_IPP_TOP_ANF_CRG_CFG1_anf_soft_rst_START (0)
#define SOC_IPP_TOP_ANF_CRG_CFG1_anf_soft_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anf_mem_ctrl_sp : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IPP_TOP_ANF_MEM_CFG_UNION;
#endif
#define SOC_IPP_TOP_ANF_MEM_CFG_anf_mem_ctrl_sp_START (0)
#define SOC_IPP_TOP_ANF_MEM_CFG_anf_mem_ctrl_sp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anf_irq_clr : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_IPP_TOP_ANF_IRQ_REG0_UNION;
#endif
#define SOC_IPP_TOP_ANF_IRQ_REG0_anf_irq_clr_START (0)
#define SOC_IPP_TOP_ANF_IRQ_REG0_anf_irq_clr_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anf_irq_mask : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_IPP_TOP_ANF_IRQ_REG1_UNION;
#endif
#define SOC_IPP_TOP_ANF_IRQ_REG1_anf_irq_mask_START (0)
#define SOC_IPP_TOP_ANF_IRQ_REG1_anf_irq_mask_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anf_irq_outen : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IPP_TOP_ANF_IRQ_REG2_UNION;
#endif
#define SOC_IPP_TOP_ANF_IRQ_REG2_anf_irq_outen_START (0)
#define SOC_IPP_TOP_ANF_IRQ_REG2_anf_irq_outen_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anf_irq_state_mask : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_IPP_TOP_ANF_IRQ_REG3_UNION;
#endif
#define SOC_IPP_TOP_ANF_IRQ_REG3_anf_irq_state_mask_START (0)
#define SOC_IPP_TOP_ANF_IRQ_REG3_anf_irq_state_mask_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anf_irq_state_raw : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_IPP_TOP_ANF_IRQ_REG4_UNION;
#endif
#define SOC_IPP_TOP_ANF_IRQ_REG4_anf_irq_state_raw_START (0)
#define SOC_IPP_TOP_ANF_IRQ_REG4_anf_irq_state_raw_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlst_ctrl_chn : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_IPP_TOP_CMDLST_CTRL_MAP_UNION;
#endif
#define SOC_IPP_TOP_CMDLST_CTRL_MAP_cmdlst_ctrl_chn_START (0)
#define SOC_IPP_TOP_CMDLST_CTRL_MAP_cmdlst_ctrl_chn_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlst_post_mask : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IPP_TOP_CMDLST_CTRL_PM_UNION;
#endif
#define SOC_IPP_TOP_CMDLST_CTRL_PM_cmdlst_post_mask_START (0)
#define SOC_IPP_TOP_CMDLST_CTRL_PM_cmdlst_post_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlst_irq_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IPP_TOP_CMDLST_IRQ_CLR_UNION;
#endif
#define SOC_IPP_TOP_CMDLST_IRQ_CLR_cmdlst_irq_clr_START (0)
#define SOC_IPP_TOP_CMDLST_IRQ_CLR_cmdlst_irq_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlst_irq_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IPP_TOP_CMDLST_IRQ_MSK_UNION;
#endif
#define SOC_IPP_TOP_CMDLST_IRQ_MSK_cmdlst_irq_mask_START (0)
#define SOC_IPP_TOP_CMDLST_IRQ_MSK_cmdlst_irq_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlst_irq_state_mask : 16;
        unsigned int cmdlst_irq_state_raw : 16;
    } reg;
} SOC_IPP_TOP_CMDLST_IRQ_STA_UNION;
#endif
#define SOC_IPP_TOP_CMDLST_IRQ_STA_cmdlst_irq_state_mask_START (0)
#define SOC_IPP_TOP_CMDLST_IRQ_STA_cmdlst_irq_state_mask_END (15)
#define SOC_IPP_TOP_CMDLST_IRQ_STA_cmdlst_irq_state_raw_START (16)
#define SOC_IPP_TOP_CMDLST_IRQ_STA_cmdlst_irq_state_raw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_info_0 : 32;
    } reg;
} SOC_IPP_TOP_JPG_DEBUG_0_UNION;
#endif
#define SOC_IPP_TOP_JPG_DEBUG_0_debug_info_0_START (0)
#define SOC_IPP_TOP_JPG_DEBUG_0_debug_info_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_info_1 : 32;
    } reg;
} SOC_IPP_TOP_JPG_DEBUG_1_UNION;
#endif
#define SOC_IPP_TOP_JPG_DEBUG_1_debug_info_1_START (0)
#define SOC_IPP_TOP_JPG_DEBUG_1_debug_info_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_info_2 : 32;
    } reg;
} SOC_IPP_TOP_JPG_DEBUG_2_UNION;
#endif
#define SOC_IPP_TOP_JPG_DEBUG_2_debug_info_2_START (0)
#define SOC_IPP_TOP_JPG_DEBUG_2_debug_info_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_info_3 : 32;
    } reg;
} SOC_IPP_TOP_JPG_DEBUG_3_UNION;
#endif
#define SOC_IPP_TOP_JPG_DEBUG_3_debug_info_3_START (0)
#define SOC_IPP_TOP_JPG_DEBUG_3_debug_info_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int top_tz_secure_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IPP_TOP_JPG_SEC_CTRL_S_UNION;
#endif
#define SOC_IPP_TOP_JPG_SEC_CTRL_S_top_tz_secure_n_START (0)
#define SOC_IPP_TOP_JPG_SEC_CTRL_S_top_tz_secure_n_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
