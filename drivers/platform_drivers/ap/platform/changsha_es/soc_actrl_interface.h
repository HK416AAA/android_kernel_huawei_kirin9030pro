#ifndef __SOC_ACTRL_INTERFACE_H__
#define __SOC_ACTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ACTRL_ISO_EN_GROUP0_PERI_ADDR(base) (base)
#define SOC_ACTRL_ISO_EN_GROUP1_PERI_ADDR(base) ((base) + 0x004UL)
#define SOC_ACTRL_ISO_EN_GROUP2_PERI_ADDR(base) ((base) + 0x008UL)
#define SOC_ACTRL_ISO_EN_AO_ADDR(base) ((base) + 0x00CUL)
#define SOC_ACTRL_MTCMOS_EN_GROUP0_PERI_ADDR(base) ((base) + 0x010UL)
#define SOC_ACTRL_MTCMOS_EN_GROUP1_PERI_ADDR(base) ((base) + 0x014UL)
#define SOC_ACTRL_MTCMOS_EN_GROUP2_PERI_ADDR(base) ((base) + 0x018UL)
#define SOC_ACTRL_MTCMOS_EN_AO_ADDR(base) ((base) + 0x01CUL)
#define SOC_ACTRL_MTCMOS_ACK0_PERI_ADDR(base) ((base) + 0x020UL)
#define SOC_ACTRL_MTCMOS_ACK1_PERI_ADDR(base) ((base) + 0x024UL)
#define SOC_ACTRL_MTCMOS_ACK_AO_ADDR(base) ((base) + 0x028UL)
#define SOC_ACTRL_ASPQIC_MUX_CTRL0_ADDR(base) ((base) + 0x02CUL)
#define SOC_ACTRL_NONSEC_STATUS0_ADDR(base) ((base) + 0x030UL)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_ADDR(base) ((base) + 0x038UL)
#define SOC_ACTRL_AO_SPI_TPSRAM_MEM_CTRL_ADDR(base) ((base) + 0x03CUL)
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS0_ADDR(base) ((base) + 0x040UL)
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS1_ADDR(base) ((base) + 0x044UL)
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS2_ADDR(base) ((base) + 0x048UL)
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS0_ADDR(base) ((base) + 0x04CUL)
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS1_ADDR(base) ((base) + 0x050UL)
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS2_ADDR(base) ((base) + 0x054UL)
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS0_ADDR(base) ((base) + 0x058UL)
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS1_ADDR(base) ((base) + 0x05CUL)
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS2_ADDR(base) ((base) + 0x060UL)
#define SOC_ACTRL_BISR_DBG_INFO_0_STAUS0_ADDR(base) ((base) + 0x064UL)
#define SOC_ACTRL_BISR_DBG_INFO_0_STAUS1_ADDR(base) ((base) + 0x068UL)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL2_ADDR(base) ((base) + 0x06CUL)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL3_ADDR(base) ((base) + 0x070UL)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL4_ADDR(base) ((base) + 0x074UL)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL5_ADDR(base) ((base) + 0x078UL)
#define SOC_ACTRL_NONSEC_STATUS1_ADDR(base) ((base) + 0x07CUL)
#define SOC_ACTRL_NONSEC_STATUS2_ADDR(base) ((base) + 0x080UL)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL6_ADDR(base) ((base) + 0x084UL)
#define SOC_ACTRL_NONSEC_STATUS3_ADDR(base) ((base) + 0x088UL)
#define SOC_ACTRL_NONSEC_CTRL0_ADDR(base) ((base) + 0x08CUL)
#define SOC_ACTRL_NONSEC_STATUS4_ADDR(base) ((base) + 0x090UL)
#define SOC_ACTRL_NONSEC_STATUS5_ADDR(base) ((base) + 0x094UL)
#define SOC_ACTRL_MWC_F_NONSEC0_ADDR(base) ((base) + 0x098UL)
#define SOC_ACTRL_MWC_F_NONSEC1_ADDR(base) ((base) + 0x09CUL)
#define SOC_ACTRL_MWC_F_NONSEC2_ADDR(base) ((base) + 0x0A0UL)
#define SOC_ACTRL_MWC_F_NONSEC3_ADDR(base) ((base) + 0x0A4UL)
#define SOC_ACTRL_NONSEC_CTRL1_ADDR(base) ((base) + 0x0A8UL)
#define SOC_ACTRL_NONSEC_CTRL2_ADDR(base) ((base) + 0x0ACUL)
#define SOC_ACTRL_NONSEC_CTRL3_ADDR(base) ((base) + 0x0B0UL)
#define SOC_ACTRL_NONSEC_CTRL4_ADDR(base) ((base) + 0x0B4UL)
#define SOC_ACTRL_NONSEC_CTRL5_ADDR(base) ((base) + 0x0B8UL)
#define SOC_ACTRL_NONSEC_CTRL6_ADDR(base) ((base) + 0x0BCUL)
#define SOC_ACTRL_NONSEC_CTRL7_ADDR(base) ((base) + 0x0C0UL)
#define SOC_ACTRL_MWC_F_NONSEC4_ADDR(base) ((base) + 0x0C4UL)
#define SOC_ACTRL_MWC_F_NONSEC5_ADDR(base) ((base) + 0x0C8UL)
#define SOC_ACTRL_MWC_F_NONSEC6_ADDR(base) ((base) + 0x0CCUL)
#define SOC_ACTRL_MWC_F_NONSEC7_ADDR(base) ((base) + 0x0D0UL)
#define SOC_ACTRL_MWC_F_NONSEC8_ADDR(base) ((base) + 0x0D4UL)
#define SOC_ACTRL_MWC_F_NONSEC9_ADDR(base) ((base) + 0x0D8UL)
#define SOC_ACTRL_MWC_F_NONSEC10_ADDR(base) ((base) + 0x0DCUL)
#define SOC_ACTRL_BISR_DBG_INFO_1_STAUS0_ADDR(base) ((base) + 0x0E0UL)
#define SOC_ACTRL_BISR_DBG_INFO_1_STAUS1_ADDR(base) ((base) + 0x0E4UL)
#define SOC_ACTRL_IOMCUQIC_IDLE_MUX_ADDR(base) ((base) + 0x0E8UL)
#define SOC_ACTRL_AOQIC_IDLE_MUX_ADDR(base) ((base) + 0x0ECUL)
#define SOC_ACTRL_AO_SPI_TPLSRAM_MEM_CTRL_ADDR(base) ((base) + 0x0F0UL)
#define SOC_ACTRL_NONSEC_STATUS6_ADDR(base) ((base) + 0x100UL)
#define SOC_ACTRL_NONSEC_STATUS7_ADDR(base) ((base) + 0x104UL)
#define SOC_ACTRL_NONSEC_STATUS8_ADDR(base) ((base) + 0x108UL)
#define SOC_ACTRL_NONSEC_STATUS9_ADDR(base) ((base) + 0x10CUL)
#define SOC_ACTRL_NONSEC_STATUS_IOMCU0_ADDR(base) ((base) + 0x110UL)
#define SOC_ACTRL_NONSEC_STATUS_IOMCU1_ADDR(base) ((base) + 0x114UL)
#define SOC_ACTRL_NONSEC_STATUS10_ADDR(base) ((base) + 0x118UL)
#define SOC_ACTRL_NONSEC_STATUS11_ADDR(base) ((base) + 0x11CUL)
#define SOC_ACTRL_NONSEC_STATUS12_ADDR(base) ((base) + 0x120UL)
#define SOC_ACTRL_NONSEC_STATUS13_ADDR(base) ((base) + 0x124UL)
#define SOC_ACTRL_NONSEC_STATUS14_ADDR(base) ((base) + 0x128UL)
#define SOC_ACTRL_NONSEC_STATUS15_ADDR(base) ((base) + 0x12CUL)
#define SOC_ACTRL_NONSEC_STATUS16_ADDR(base) ((base) + 0x130UL)
#define SOC_ACTRL_NONSEC_STATUS17_ADDR(base) ((base) + 0x134UL)
#define SOC_ACTRL_NONSEC_STATUS18_ADDR(base) ((base) + 0x138UL)
#define SOC_ACTRL_NONSEC_STATUS19_ADDR(base) ((base) + 0x13CUL)
#define SOC_ACTRL_NONSEC_STATUS20_ADDR(base) ((base) + 0x140UL)
#define SOC_ACTRL_NONSEC_STATUS21_ADDR(base) ((base) + 0x144UL)
#define SOC_ACTRL_NONSEC_STATUS22_ADDR(base) ((base) + 0x148UL)
#define SOC_ACTRL_NONSEC_STATUS23_ADDR(base) ((base) + 0x14CUL)
#define SOC_ACTRL_NONSEC_STATUS24_ADDR(base) ((base) + 0x150UL)
#define SOC_ACTRL_NONSEC_STATUS25_ADDR(base) ((base) + 0x154UL)
#define SOC_ACTRL_NONSEC_STATUS26_ADDR(base) ((base) + 0x158UL)
#define SOC_ACTRL_NONSEC_STATUS27_ADDR(base) ((base) + 0x15CUL)
#define SOC_ACTRL_NONSEC_STATUS28_ADDR(base) ((base) + 0x160UL)
#define SOC_ACTRL_NONSEC_STATUS29_ADDR(base) ((base) + 0x164UL)
#define SOC_ACTRL_NONSEC_STATUS30_ADDR(base) ((base) + 0x168UL)
#define SOC_ACTRL_NONSEC_STATUS31_ADDR(base) ((base) + 0x16CUL)
#define SOC_ACTRL_NONSEC_STATUS32_ADDR(base) ((base) + 0x170UL)
#define SOC_ACTRL_NONSEC_STATUS33_ADDR(base) ((base) + 0x174UL)
#define SOC_ACTRL_NONSEC_STATUS34_ADDR(base) ((base) + 0x178UL)
#define SOC_ACTRL_NONSEC_STATUS35_ADDR(base) ((base) + 0x17CUL)
#define SOC_ACTRL_NONSEC_STATUS36_ADDR(base) ((base) + 0x180UL)
#define SOC_ACTRL_NONSEC_STATUS37_ADDR(base) ((base) + 0x184UL)
#define SOC_ACTRL_NONSEC_STATUS38_ADDR(base) ((base) + 0x188UL)
#define SOC_ACTRL_NONSEC_STATUS39_ADDR(base) ((base) + 0x18CUL)
#define SOC_ACTRL_NONSEC_STATUS40_ADDR(base) ((base) + 0x190UL)
#define SOC_ACTRL_NONSEC_STATUS41_ADDR(base) ((base) + 0x194UL)
#define SOC_ACTRL_NONSEC_STATUS42_ADDR(base) ((base) + 0x198UL)
#define SOC_ACTRL_NONSEC_STATUS43_ADDR(base) ((base) + 0x19CUL)
#define SOC_ACTRL_NONSEC_STATUS44_ADDR(base) ((base) + 0x1A0UL)
#define SOC_ACTRL_NONSEC_STATUS45_ADDR(base) ((base) + 0x1A4UL)
#define SOC_ACTRL_NONSEC_STATUS46_ADDR(base) ((base) + 0x1A8UL)
#define SOC_ACTRL_NONSEC_STATUS47_ADDR(base) ((base) + 0x1ACUL)
#define SOC_ACTRL_NONSEC_STATUS48_ADDR(base) ((base) + 0x1B0UL)
#define SOC_ACTRL_NONSEC_STATUS49_ADDR(base) ((base) + 0x1B4UL)
#define SOC_ACTRL_NONSEC_STATUS50_ADDR(base) ((base) + 0x1B8UL)
#define SOC_ACTRL_NONSEC_STATUS51_ADDR(base) ((base) + 0x1BCUL)
#define SOC_ACTRL_NONSEC_STATUS52_ADDR(base) ((base) + 0x1C0UL)
#define SOC_ACTRL_NONSEC_STATUS53_ADDR(base) ((base) + 0x1C4UL)
#define SOC_ACTRL_NONSEC_STATUS54_ADDR(base) ((base) + 0x1C8UL)
#define SOC_ACTRL_NONSEC_STATUS55_ADDR(base) ((base) + 0x1CCUL)
#define SOC_ACTRL_IP_IDLE_STATUS_ADDR(base) ((base) + 0x1D0UL)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_ADDR(base) ((base) + 0x1D4UL)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_NPU_ADDR(base) ((base) + 0x1D8UL)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_MEDIA2_ADDR(base) ((base) + 0x1DCUL)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_MEDIA1_ADDR(base) ((base) + 0x1E0UL)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_GPU_ADDR(base) ((base) + 0x1E4UL)
#define SOC_ACTRL_ASPQIC_NOPENDING_MSK0_ADDR(base) ((base) + 0x1E8UL)
#define SOC_ACTRL_ASPQIC_NOPENDING_MSK1_ADDR(base) ((base) + 0x1ECUL)
#define SOC_ACTRL_IOMCUQIC_NOPENDING_MSK0_ADDR(base) ((base) + 0x1F0UL)
#define SOC_ACTRL_IOMCUQIC_NOPENDING_MSK1_ADDR(base) ((base) + 0x1F4UL)
#define SOC_ACTRL_AOQIC_NOPENDING_MSK0_ADDR(base) ((base) + 0x1F8UL)
#define SOC_ACTRL_AOQIC_NOPENDING_MSK1_ADDR(base) ((base) + 0x1FCUL)
#define SOC_ACTRL_IOMCUQIC_NOPENDING_PDMS_MSK_ADDR(base) ((base) + 0x200UL)
#define SOC_ACTRL_AOQIC_NOPENDING_PDMS_MSK_ADDR(base) ((base) + 0x204UL)
#define SOC_ACTRL_HIPHYIO_INTR_MSK_ADDR(base) ((base) + 0x208UL)
#define SOC_ACTRL_HIOSTS_GPIO_INTR_STATUS_ADDR(base) ((base) + 0x20CUL)
#define SOC_ACTRL_HSDT_MEM_STATUS_ADDR(base) ((base) + 0x210UL)
#define SOC_ACTRL_ASP_AUTOFS_BYP0_ADDR(base) ((base) + 0x214UL)
#define SOC_ACTRL_ASP_AUTOFS_BYP1_ADDR(base) ((base) + 0x218UL)
#define SOC_ACTRL_IOMCU_AUTOFS_BYP0_ADDR(base) ((base) + 0x21CUL)
#define SOC_ACTRL_IOMCU_AUTOFS_BYP1_ADDR(base) ((base) + 0x220UL)
#define SOC_ACTRL_AO_AUTOFS_BYP0_ADDR(base) ((base) + 0x224UL)
#define SOC_ACTRL_AO_AUTOFS_BYP1_ADDR(base) ((base) + 0x228UL)
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_LOW_ADDR(base) ((base) + 0x22CUL)
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_HIGH_ADDR(base) ((base) + 0x230UL)
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_LOW_ADDR(base) ((base) + 0x234UL)
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_HIGH_ADDR(base) ((base) + 0x238UL)
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_LOW_ADDR(base) ((base) + 0x23CUL)
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_HIGH_ADDR(base) ((base) + 0x240UL)
#define SOC_ACTRL_MWC_F_NONSEC11_ADDR(base) ((base) + 0x300UL)
#define SOC_ACTRL_MWC_F_NONSEC12_ADDR(base) ((base) + 0x304UL)
#define SOC_ACTRL_MWC_F_NONSEC13_ADDR(base) ((base) + 0x308UL)
#define SOC_ACTRL_MWC_F_NONSEC14_ADDR(base) ((base) + 0x30CUL)
#define SOC_ACTRL_MWC_F_NONSEC15_ADDR(base) ((base) + 0x310UL)
#define SOC_ACTRL_MWC_F_NONSEC16_ADDR(base) ((base) + 0x314UL)
#define SOC_ACTRL_MWC_F_NONSEC17_ADDR(base) ((base) + 0x318UL)
#define SOC_ACTRL_MWC_F_NONSEC18_ADDR(base) ((base) + 0x31CUL)
#define SOC_ACTRL_MWC_F_NONSEC19_ADDR(base) ((base) + 0x320UL)
#define SOC_ACTRL_MWC_F_NONSEC20_ADDR(base) ((base) + 0x324UL)
#define SOC_ACTRL_MWC_F_NONSEC21_ADDR(base) ((base) + 0x328UL)
#define SOC_ACTRL_MWC_F_NONSEC22_ADDR(base) ((base) + 0x32CUL)
#define SOC_ACTRL_MWC_F_NONSEC23_ADDR(base) ((base) + 0x330UL)
#define SOC_ACTRL_MWC_F_NONSEC24_ADDR(base) ((base) + 0x334UL)
#define SOC_ACTRL_MWC_F_NONSEC25_ADDR(base) ((base) + 0x338UL)
#define SOC_ACTRL_MWC_F_NONSEC26_ADDR(base) ((base) + 0x33CUL)
#define SOC_ACTRL_MWC_F_NONSEC27_ADDR(base) ((base) + 0x340UL)
#define SOC_ACTRL_MWC_F_NONSEC28_ADDR(base) ((base) + 0x344UL)
#define SOC_ACTRL_MWC_F_NONSEC29_ADDR(base) ((base) + 0x348UL)
#define SOC_ACTRL_MWC_F_NONSEC30_ADDR(base) ((base) + 0x34CUL)
#define SOC_ACTRL_MWC_F_NONSEC31_ADDR(base) ((base) + 0x350UL)
#define SOC_ACTRL_MWC_F_NONSEC32_ADDR(base) ((base) + 0x354UL)
#define SOC_ACTRL_MWC_F_NONSEC33_ADDR(base) ((base) + 0x358UL)
#define SOC_ACTRL_MWC_F_NONSEC34_ADDR(base) ((base) + 0x35CUL)
#define SOC_ACTRL_MWC_F_NONSEC35_ADDR(base) ((base) + 0x360UL)
#define SOC_ACTRL_MWC_F_NONSEC36_ADDR(base) ((base) + 0x364UL)
#define SOC_ACTRL_MWC_F_NONSEC37_ADDR(base) ((base) + 0x368UL)
#define SOC_ACTRL_MWC_F_NONSEC38_ADDR(base) ((base) + 0x36CUL)
#define SOC_ACTRL_MWC_F_NONSEC39_ADDR(base) ((base) + 0x370UL)
#define SOC_ACTRL_MWC_F_NONSEC40_ADDR(base) ((base) + 0x374UL)
#define SOC_ACTRL_MWC_F_NONSEC41_ADDR(base) ((base) + 0x378UL)
#define SOC_ACTRL_MWC_F_NONSEC42_ADDR(base) ((base) + 0x37CUL)
#define SOC_ACTRL_MWC_F_NONSEC43_ADDR(base) ((base) + 0x380UL)
#define SOC_ACTRL_MWC_F_NONSEC44_ADDR(base) ((base) + 0x384UL)
#define SOC_ACTRL_MWC_F_NONSEC45_ADDR(base) ((base) + 0x388UL)
#define SOC_ACTRL_MWC_F_NONSEC46_ADDR(base) ((base) + 0x38CUL)
#define SOC_ACTRL_MWC_F_NONSEC47_ADDR(base) ((base) + 0x390UL)
#define SOC_ACTRL_MWC_F_NONSEC48_ADDR(base) ((base) + 0x394UL)
#define SOC_ACTRL_MWC_F_NONSEC49_ADDR(base) ((base) + 0x398UL)
#define SOC_ACTRL_MWC_F_NONSEC50_ADDR(base) ((base) + 0x39CUL)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_ADDR(base) ((base) + 0x400UL)
#define SOC_ACTRL_NONSEC_CTRL8_BITMASK_ADDR(base) ((base) + 0x404UL)
#define SOC_ACTRL_NONSEC_CTRL9_ADDR(base) ((base) + 0x408UL)
#define SOC_ACTRL_NONSEC_CTRL10_ADDR(base) ((base) + 0x40CUL)
#define SOC_ACTRL_NONSEC_CTRL11_ADDR(base) ((base) + 0x410UL)
#define SOC_ACTRL_NONSEC_CTRL12_ADDR(base) ((base) + 0x414UL)
#define SOC_ACTRL_NONSEC_CTRL13_ADDR(base) ((base) + 0x418UL)
#define SOC_ACTRL_MDM_NS_RSV_CTRL0_ADDR(base) ((base) + 0x41CUL)
#define SOC_ACTRL_MDM_NS_RSV_CTRL1_ADDR(base) ((base) + 0x420UL)
#define SOC_ACTRL_MDM_NS_RSV_CTRL2_ADDR(base) ((base) + 0x424UL)
#define SOC_ACTRL_MDM_NS_RSV_CTRL3_ADDR(base) ((base) + 0x428UL)
#define SOC_ACTRL_MDM_NS_RSV_CTRL4_ADDR(base) ((base) + 0x42CUL)
#define SOC_ACTRL_MDM_NS_RSV_CTRL5_ADDR(base) ((base) + 0x430UL)
#define SOC_ACTRL_MDM_NS_RSV_CTRL6_ADDR(base) ((base) + 0x434UL)
#define SOC_ACTRL_MDM_NS_RSV_CTRL7_ADDR(base) ((base) + 0x438UL)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL0_ADDR(base) ((base) + 0x43CUL)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL1_ADDR(base) ((base) + 0x440UL)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL2_ADDR(base) ((base) + 0x444UL)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL3_ADDR(base) ((base) + 0x448UL)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL4_ADDR(base) ((base) + 0x44CUL)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL5_ADDR(base) ((base) + 0x450UL)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL6_ADDR(base) ((base) + 0x454UL)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL7_ADDR(base) ((base) + 0x458UL)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL7_ADDR(base) ((base) + 0x45CUL)
#define SOC_ACTRL_AUDIO_HAPTIC0_STATUS_ADDR(base) ((base) + 0x460UL)
#define SOC_ACTRL_HSDT_SDS_CTRL_ADDR(base) ((base) + 0x464UL)
#define SOC_ACTRL_AUDIO_HAPTIC1_STATUS_ADDR(base) ((base) + 0x468UL)
#define SOC_ACTRL_AO_MEM_CTRL3_ADDR(base) ((base) + 0x46CUL)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_ADDR(base) ((base) + 0x470UL)
#define SOC_ACTRL_HSDT1_MEM_CTRL0_ADDR(base) ((base) + 0x474UL)
#define SOC_ACTRL_HSDT0_MEM_CTRL0_ADDR(base) ((base) + 0x478UL)
#define SOC_ACTRL_UFS_LSS_OUT_ADDR(base) ((base) + 0x47CUL)
#define SOC_ACTRL_IOMCU_MEM_CTRL0_ADDR(base) ((base) + 0x800UL)
#define SOC_ACTRL_IOMCU_MEM_CTRL1_ADDR(base) ((base) + 0x804UL)
#define SOC_ACTRL_IOMCU_MEM_CTRL3_ADDR(base) ((base) + 0x808UL)
#define SOC_ACTRL_AO_MEM_CTRL0_ADDR(base) ((base) + 0x80CUL)
#define SOC_ACTRL_AO_MEM_CTRL1_ADDR(base) ((base) + 0x810UL)
#define SOC_ACTRL_AO_MEM_CTRL2_ADDR(base) ((base) + 0x814UL)
#define SOC_ACTRL_SEC_SC_CTRL_ADDR(base) ((base) + 0x818UL)
#define SOC_ACTRL_AO_MEM_CTRL4_ADDR(base) ((base) + 0x81CUL)
#define SOC_ACTRL_AO_MEM_CTRL5_ADDR(base) ((base) + 0x820UL)
#define SOC_ACTRL_AO_MEM_CTRL6_ADDR(base) ((base) + 0x824UL)
#define SOC_ACTRL_AO_MEM_CTRL7_ADDR(base) ((base) + 0x828UL)
#define SOC_ACTRL_AO_MEM_CTRL8_ADDR(base) ((base) + 0x82CUL)
#define SOC_ACTRL_AO_MEM_CTRL9_ADDR(base) ((base) + 0x830UL)
#define SOC_ACTRL_AO_MEM_STATUS_ADDR(base) ((base) + 0x834UL)
#define SOC_ACTRL_SEC_CTRL0_ADDR(base) ((base) + 0x838UL)
#define SOC_ACTRL_SEC_STATUS0_ADDR(base) ((base) + 0x844UL)
#define SOC_ACTRL_AO_MEM_CTRL10_ADDR(base) ((base) + 0x848UL)
#define SOC_ACTRL_BITMSK_SEC_CTRL1_ADDR(base) ((base) + 0x84CUL)
#define SOC_ACTRL_BITMSK_SEC_CTRL2_ADDR(base) ((base) + 0x850UL)
#define SOC_ACTRL_BITMSK_SEC_CTRL3_ADDR(base) ((base) + 0x854UL)
#define SOC_ACTRL_BITMSK_SEC_CTRL4_ADDR(base) ((base) + 0x858UL)
#define SOC_ACTRL_SEC_STATUS1_ADDR(base) ((base) + 0x85CUL)
#define SOC_ACTRL_SEC_STATUS2_ADDR(base) ((base) + 0x860UL)
#define SOC_ACTRL_FACTEST_SEL_SEC_ADDR(base) ((base) + 0x864UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP0_ADDR(base) ((base) + 0x868UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP1_ADDR(base) ((base) + 0x86CUL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP2_ADDR(base) ((base) + 0x870UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP3_ADDR(base) ((base) + 0x874UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP4_ADDR(base) ((base) + 0x878UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP5_ADDR(base) ((base) + 0x87CUL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP6_ADDR(base) ((base) + 0x880UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP7_ADDR(base) ((base) + 0x884UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP_CRC0_ADDR(base) ((base) + 0x888UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP0_ADDR(base) ((base) + 0x88CUL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP1_ADDR(base) ((base) + 0x890UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP2_ADDR(base) ((base) + 0x894UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP3_ADDR(base) ((base) + 0x898UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP4_ADDR(base) ((base) + 0x89CUL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP5_ADDR(base) ((base) + 0x8A0UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP6_ADDR(base) ((base) + 0x8A4UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP7_ADDR(base) ((base) + 0x8A8UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP_CRC0_ADDR(base) ((base) + 0x8ACUL)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP0_ADDR(base) ((base) + 0x8B0UL)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP1_ADDR(base) ((base) + 0x8B4UL)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP2_ADDR(base) ((base) + 0x8B8UL)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP3_ADDR(base) ((base) + 0x8BCUL)
#define SOC_ACTRL_HIEPS_COUNTERP_CRC1_ADDR(base) ((base) + 0x8C0UL)
#define SOC_ACTRL_MWC_F_SEC0_ADDR(base) ((base) + 0x8C4UL)
#define SOC_ACTRL_MWC_F_SEC1_ADDR(base) ((base) + 0x8C8UL)
#define SOC_ACTRL_MWC_F_SEC2_ADDR(base) ((base) + 0x8CCUL)
#define SOC_ACTRL_MWC_F_SEC3_ADDR(base) ((base) + 0x8D0UL)
#define SOC_ACTRL_MWC_F_SEC4_ADDR(base) ((base) + 0x8D4UL)
#define SOC_ACTRL_MWC_F_SEC5_ADDR(base) ((base) + 0x8D8UL)
#define SOC_ACTRL_MWC_F_SEC6_ADDR(base) ((base) + 0x8DCUL)
#define SOC_ACTRL_MWC_F_SEC7_ADDR(base) ((base) + 0x8E0UL)
#define SOC_ACTRL_MWC_F_SEC8_ADDR(base) ((base) + 0x8E4UL)
#define SOC_ACTRL_MWC_F_SEC9_ADDR(base) ((base) + 0x8E8UL)
#define SOC_ACTRL_MWC_F_SEC10_ADDR(base) ((base) + 0x8ECUL)
#define SOC_ACTRL_MWC_F_SEC11_ADDR(base) ((base) + 0x8F0UL)
#define SOC_ACTRL_MWC_F_SEC12_ADDR(base) ((base) + 0x8F4UL)
#define SOC_ACTRL_MWC_F_SEC13_ADDR(base) ((base) + 0x8F8UL)
#define SOC_ACTRL_MWC_F_SEC14_ADDR(base) ((base) + 0x8FCUL)
#define SOC_ACTRL_MWC_F_SEC15_ADDR(base) ((base) + 0x900UL)
#define SOC_ACTRL_MWC_F_SEC16_ADDR(base) ((base) + 0x904UL)
#define SOC_ACTRL_MWC_F_SEC17_ADDR(base) ((base) + 0x908UL)
#define SOC_ACTRL_MWC_F_SEC18_ADDR(base) ((base) + 0x90CUL)
#define SOC_ACTRL_MWC_F_SEC19_ADDR(base) ((base) + 0x910UL)
#define SOC_ACTRL_MWC_F_SEC20_ADDR(base) ((base) + 0x914UL)
#define SOC_ACTRL_MWC_F_SEC21_ADDR(base) ((base) + 0x918UL)
#define SOC_ACTRL_MWC_F_SEC22_ADDR(base) ((base) + 0x91CUL)
#define SOC_ACTRL_NSEC_LOCK_CTRL0_ADDR(base) ((base) + 0x920UL)
#define SOC_ACTRL_MWC_F_SEC23_ADDR(base) ((base) + 0x924UL)
#define SOC_ACTRL_MWC_F_SEC24_ADDR(base) ((base) + 0x928UL)
#define SOC_ACTRL_MWC_F_SEC25_ADDR(base) ((base) + 0x92CUL)
#define SOC_ACTRL_MWC_F_SEC26_ADDR(base) ((base) + 0x930UL)
#define SOC_ACTRL_MWC_F_SEC27_ADDR(base) ((base) + 0x934UL)
#define SOC_ACTRL_MWC_F_SEC28_ADDR(base) ((base) + 0x938UL)
#define SOC_ACTRL_MWC_F_SEC29_ADDR(base) ((base) + 0x93CUL)
#define SOC_ACTRL_MWC_F_SEC30_ADDR(base) ((base) + 0x940UL)
#define SOC_ACTRL_MWC_F_SEC31_ADDR(base) ((base) + 0x944UL)
#define SOC_ACTRL_MWC_F_SEC32_ADDR(base) ((base) + 0x948UL)
#define SOC_ACTRL_MWC_F_SEC33_ADDR(base) ((base) + 0x94CUL)
#define SOC_ACTRL_SEC_STATUS3_ADDR(base) ((base) + 0x950UL)
#define SOC_ACTRL_SEC_STATUS4_ADDR(base) ((base) + 0x954UL)
#define SOC_ACTRL_SEC_STATUS5_ADDR(base) ((base) + 0x958UL)
#define SOC_ACTRL_SEC_STATUS6_ADDR(base) ((base) + 0x95CUL)
#define SOC_ACTRL_SEC_STATUS7_ADDR(base) ((base) + 0x960UL)
#define SOC_ACTRL_SEC_STATUS8_ADDR(base) ((base) + 0x964UL)
#define SOC_ACTRL_SEC_STATUS9_ADDR(base) ((base) + 0x968UL)
#define SOC_ACTRL_SEC_STATUS10_ADDR(base) ((base) + 0x96CUL)
#define SOC_ACTRL_SEC_STATUS11_ADDR(base) ((base) + 0x970UL)
#define SOC_ACTRL_SEC_STATUS12_ADDR(base) ((base) + 0x974UL)
#define SOC_ACTRL_SEC_STATUS13_ADDR(base) ((base) + 0x978UL)
#define SOC_ACTRL_SEC_CTRL1_ADDR(base) ((base) + 0x97CUL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP0_ADDR(base) ((base) + 0x980UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP1_ADDR(base) ((base) + 0x984UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP2_ADDR(base) ((base) + 0x988UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP3_ADDR(base) ((base) + 0x98CUL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP4_ADDR(base) ((base) + 0x990UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP5_ADDR(base) ((base) + 0x994UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP6_ADDR(base) ((base) + 0x998UL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP7_ADDR(base) ((base) + 0x99CUL)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP_CRC0_ADDR(base) ((base) + 0x9A0UL)
#define SOC_ACTRL_QIC_GLOBAL_CFG_ADDR(base) ((base) + 0x9A4UL)
#define SOC_ACTRL_MEDIA_MEM_CTRL0_ADDR(base) ((base) + 0x9A8UL)
#define SOC_ACTRL_CPU_PIPE_STATUS0_ADDR(base) ((base) + 0x9ACUL)
#define SOC_ACTRL_MEDIA_MEM_STATUS_ADDR(base) ((base) + 0x9B0UL)
#define SOC_ACTRL_STS_HIO_SPI_CS_SEL_SEC_ADDR(base) ((base) + 0x9B4UL)
#define SOC_ACTRL_SEC_CTRL2_ADDR(base) ((base) + 0x9B8UL)
#define SOC_ACTRL_SEC_CTRL3_ADDR(base) ((base) + 0x9BCUL)
#define SOC_ACTRL_SEC_CTRL4_ADDR(base) ((base) + 0x9C0UL)
#define SOC_ACTRL_AO_QSPI_TPSRAM_MEM_CTRL_ADDR(base) ((base) + 0x9C4UL)
#define SOC_ACTRL_QIC_GLOBAL_CFG_NPU_ADDR(base) ((base) + 0x9C8UL)
#define SOC_ACTRL_QIC_GLOBAL_CFG_MEIDA2_ADDR(base) ((base) + 0x9CCUL)
#define SOC_ACTRL_QIC_GLOBAL_CFG_MEIDA1_ADDR(base) ((base) + 0x9D4UL)
#define SOC_ACTRL_QIC_GLOBAL_CFG_GPU_ADDR(base) ((base) + 0x9D8UL)
#define SOC_ACTRL_SEC_STATUS14_ADDR(base) ((base) + 0x9E0UL)
#define SOC_ACTRL_SEC_STATUS15_ADDR(base) ((base) + 0x9E4UL)
#define SOC_ACTRL_SEC_STATUS16_ADDR(base) ((base) + 0x9E8UL)
#define SOC_ACTRL_AUDIO_AW_DLOCK_ADDR(base) ((base) + 0x9ECUL)
#define SOC_ACTRL_STS_SEL_MUX_ADDR(base) ((base) + 0x9F0UL)
#define SOC_ACTRL_IOMUX_SEL_STS_ADDR(base) ((base) + 0x9F4UL)
#define SOC_ACTRL_IOMUX_SEL_HIPHY_ADDR(base) ((base) + 0x9F8UL)
#define SOC_ACTRL_IOMUX_SEL_1TO3_ADDR(base) ((base) + 0x9FCUL)
#define SOC_ACTRL_SEC_CTRL_MSPC_QIC_DBG_ADDR(base) ((base) + 0xA00UL)
#define SOC_ACTRL_IOMUX_SEL_STS1_ADDR(base) ((base) + 0xA04UL)
#define SOC_ACTRL_BITMSK_SEC_STS_CS_ADDR(base) ((base) + 0xA08UL)
#define SOC_ACTRL_BITMSK_SEC_STS_SEL_ADDR(base) ((base) + 0xA0CUL)
#define SOC_ACTRL_BITMSK_SEC_STS_XCTRL_SEL_ADDR(base) ((base) + 0xA10UL)
#define SOC_ACTRL_BITMSK_SEC_STS_CLK_CTRL_ADDR(base) ((base) + 0xA14UL)
#define SOC_ACTRL_BITMSK_SEC_CTRL0_ADDR(base) ((base) + 0xC00UL)
#define SOC_ACTRL_HSDT_SEC_CTRL0_ADDR(base) ((base) + 0xC04UL)
#define SOC_ACTRL_MODEM_SEC_CTRL0_ADDR(base) ((base) + 0xC08UL)
#define SOC_ACTRL_PDEA_BIT_MASK0_ADDR(base) ((base) + 0xC0CUL)
#define SOC_ACTRL_PDEA_BIT_MASK1_ADDR(base) ((base) + 0xC10UL)
#define SOC_ACTRL_TSP_BIT_MASK0_ADDR(base) ((base) + 0xC14UL)
#define SOC_ACTRL_TSP_BIT_MASK1_ADDR(base) ((base) + 0xC18UL)
#define SOC_ACTRL_MDM_S_RSV_CTRL0_ADDR(base) ((base) + 0xC1CUL)
#define SOC_ACTRL_MDM_S_RSV_CTRL1_ADDR(base) ((base) + 0xC20UL)
#define SOC_ACTRL_MSPCQIC_TIMEOUT_ST_MSK_ADDR(base) ((base) + 0xC24UL)
#define SOC_ACTRL_MSPC_AUTOFS_BYP0_ADDR(base) ((base) + 0xC28UL)
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_LOW_ADDR(base) ((base) + 0xC30UL)
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_HIGH_ADDR(base) ((base) + 0xC34UL)
#define SOC_ACTRL_ISO_EN_GROUP_SEC_ADDR(base) ((base) + 0xF00UL)
#define SOC_ACTRL_MTCMOS_EN_GROUP_SEC_ADDR(base) ((base) + 0xF04UL)
#define SOC_ACTRL_MTCMOS_ACK_GROUP_SEC_ADDR(base) ((base) + 0xF08UL)
#define SOC_ACTRL_HIEPS_CER_EN_ADDR(base) ((base) + 0xF0CUL)
#define SOC_ACTRL_HIEPS_CTRL_SEC_ADDR(base) ((base) + 0xF10UL)
#define SOC_ACTRL_MSPC_RAM_CTRL_ADDR(base) ((base) + 0xF14UL)
#define SOC_ACTRL_HIEPS_STATE_COUNTER_ADDR(base) ((base) + 0xF18UL)
#define SOC_ACTRL_ACTRL2EPS_REG0_ADDR(base) ((base) + 0xF5CUL)
#define SOC_ACTRL_ACTRL2EPS_REG1_ADDR(base) ((base) + 0xF60UL)
#define SOC_ACTRL_ACTRL2EPS_REG2_ADDR(base) ((base) + 0xF64UL)
#define SOC_ACTRL_ACTRL2EPS_REG3_ADDR(base) ((base) + 0xF68UL)
#define SOC_ACTRL_ACTRL2EPS_REG4_ADDR(base) ((base) + 0xF6CUL)
#define SOC_ACTRL_EPS2ACTRL_REG0_ADDR(base) ((base) + 0xF70UL)
#define SOC_ACTRL_EPS2ACTRL_REG1_ADDR(base) ((base) + 0xF74UL)
#define SOC_ACTRL_EPS2ACTRL_REG2_ADDR(base) ((base) + 0xF78UL)
#define SOC_ACTRL_EPS2ACTRL_REG3_ADDR(base) ((base) + 0xF7CUL)
#define SOC_ACTRL_EPS2ACTRL_REG4_ADDR(base) ((base) + 0xF80UL)
#define SOC_ACTRL_HIEPS_MEM_CTRL_ADDR(base) ((base) + 0xF84UL)
#define SOC_ACTRL_ABSSEC_CTRL0_ADDR(base) ((base) + 0xF88UL)
#define SOC_ACTRL_ABSSEC_CTRL1_ADDR(base) ((base) + 0xF8CUL)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_ADDR(base) ((base) + 0xF90UL)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_MUX_ADDR(base) ((base) + 0xF94UL)
#else
#define SOC_ACTRL_ISO_EN_GROUP0_PERI_ADDR(base) (base)
#define SOC_ACTRL_ISO_EN_GROUP1_PERI_ADDR(base) ((base) + 0x004)
#define SOC_ACTRL_ISO_EN_GROUP2_PERI_ADDR(base) ((base) + 0x008)
#define SOC_ACTRL_ISO_EN_AO_ADDR(base) ((base) + 0x00C)
#define SOC_ACTRL_MTCMOS_EN_GROUP0_PERI_ADDR(base) ((base) + 0x010)
#define SOC_ACTRL_MTCMOS_EN_GROUP1_PERI_ADDR(base) ((base) + 0x014)
#define SOC_ACTRL_MTCMOS_EN_GROUP2_PERI_ADDR(base) ((base) + 0x018)
#define SOC_ACTRL_MTCMOS_EN_AO_ADDR(base) ((base) + 0x01C)
#define SOC_ACTRL_MTCMOS_ACK0_PERI_ADDR(base) ((base) + 0x020)
#define SOC_ACTRL_MTCMOS_ACK1_PERI_ADDR(base) ((base) + 0x024)
#define SOC_ACTRL_MTCMOS_ACK_AO_ADDR(base) ((base) + 0x028)
#define SOC_ACTRL_ASPQIC_MUX_CTRL0_ADDR(base) ((base) + 0x02C)
#define SOC_ACTRL_NONSEC_STATUS0_ADDR(base) ((base) + 0x030)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_ADDR(base) ((base) + 0x038)
#define SOC_ACTRL_AO_SPI_TPSRAM_MEM_CTRL_ADDR(base) ((base) + 0x03C)
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS0_ADDR(base) ((base) + 0x040)
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS1_ADDR(base) ((base) + 0x044)
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS2_ADDR(base) ((base) + 0x048)
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS0_ADDR(base) ((base) + 0x04C)
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS1_ADDR(base) ((base) + 0x050)
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS2_ADDR(base) ((base) + 0x054)
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS0_ADDR(base) ((base) + 0x058)
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS1_ADDR(base) ((base) + 0x05C)
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS2_ADDR(base) ((base) + 0x060)
#define SOC_ACTRL_BISR_DBG_INFO_0_STAUS0_ADDR(base) ((base) + 0x064)
#define SOC_ACTRL_BISR_DBG_INFO_0_STAUS1_ADDR(base) ((base) + 0x068)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL2_ADDR(base) ((base) + 0x06C)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL3_ADDR(base) ((base) + 0x070)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL4_ADDR(base) ((base) + 0x074)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL5_ADDR(base) ((base) + 0x078)
#define SOC_ACTRL_NONSEC_STATUS1_ADDR(base) ((base) + 0x07C)
#define SOC_ACTRL_NONSEC_STATUS2_ADDR(base) ((base) + 0x080)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL6_ADDR(base) ((base) + 0x084)
#define SOC_ACTRL_NONSEC_STATUS3_ADDR(base) ((base) + 0x088)
#define SOC_ACTRL_NONSEC_CTRL0_ADDR(base) ((base) + 0x08C)
#define SOC_ACTRL_NONSEC_STATUS4_ADDR(base) ((base) + 0x090)
#define SOC_ACTRL_NONSEC_STATUS5_ADDR(base) ((base) + 0x094)
#define SOC_ACTRL_MWC_F_NONSEC0_ADDR(base) ((base) + 0x098)
#define SOC_ACTRL_MWC_F_NONSEC1_ADDR(base) ((base) + 0x09C)
#define SOC_ACTRL_MWC_F_NONSEC2_ADDR(base) ((base) + 0x0A0)
#define SOC_ACTRL_MWC_F_NONSEC3_ADDR(base) ((base) + 0x0A4)
#define SOC_ACTRL_NONSEC_CTRL1_ADDR(base) ((base) + 0x0A8)
#define SOC_ACTRL_NONSEC_CTRL2_ADDR(base) ((base) + 0x0AC)
#define SOC_ACTRL_NONSEC_CTRL3_ADDR(base) ((base) + 0x0B0)
#define SOC_ACTRL_NONSEC_CTRL4_ADDR(base) ((base) + 0x0B4)
#define SOC_ACTRL_NONSEC_CTRL5_ADDR(base) ((base) + 0x0B8)
#define SOC_ACTRL_NONSEC_CTRL6_ADDR(base) ((base) + 0x0BC)
#define SOC_ACTRL_NONSEC_CTRL7_ADDR(base) ((base) + 0x0C0)
#define SOC_ACTRL_MWC_F_NONSEC4_ADDR(base) ((base) + 0x0C4)
#define SOC_ACTRL_MWC_F_NONSEC5_ADDR(base) ((base) + 0x0C8)
#define SOC_ACTRL_MWC_F_NONSEC6_ADDR(base) ((base) + 0x0CC)
#define SOC_ACTRL_MWC_F_NONSEC7_ADDR(base) ((base) + 0x0D0)
#define SOC_ACTRL_MWC_F_NONSEC8_ADDR(base) ((base) + 0x0D4)
#define SOC_ACTRL_MWC_F_NONSEC9_ADDR(base) ((base) + 0x0D8)
#define SOC_ACTRL_MWC_F_NONSEC10_ADDR(base) ((base) + 0x0DC)
#define SOC_ACTRL_BISR_DBG_INFO_1_STAUS0_ADDR(base) ((base) + 0x0E0)
#define SOC_ACTRL_BISR_DBG_INFO_1_STAUS1_ADDR(base) ((base) + 0x0E4)
#define SOC_ACTRL_IOMCUQIC_IDLE_MUX_ADDR(base) ((base) + 0x0E8)
#define SOC_ACTRL_AOQIC_IDLE_MUX_ADDR(base) ((base) + 0x0EC)
#define SOC_ACTRL_AO_SPI_TPLSRAM_MEM_CTRL_ADDR(base) ((base) + 0x0F0)
#define SOC_ACTRL_NONSEC_STATUS6_ADDR(base) ((base) + 0x100)
#define SOC_ACTRL_NONSEC_STATUS7_ADDR(base) ((base) + 0x104)
#define SOC_ACTRL_NONSEC_STATUS8_ADDR(base) ((base) + 0x108)
#define SOC_ACTRL_NONSEC_STATUS9_ADDR(base) ((base) + 0x10C)
#define SOC_ACTRL_NONSEC_STATUS_IOMCU0_ADDR(base) ((base) + 0x110)
#define SOC_ACTRL_NONSEC_STATUS_IOMCU1_ADDR(base) ((base) + 0x114)
#define SOC_ACTRL_NONSEC_STATUS10_ADDR(base) ((base) + 0x118)
#define SOC_ACTRL_NONSEC_STATUS11_ADDR(base) ((base) + 0x11C)
#define SOC_ACTRL_NONSEC_STATUS12_ADDR(base) ((base) + 0x120)
#define SOC_ACTRL_NONSEC_STATUS13_ADDR(base) ((base) + 0x124)
#define SOC_ACTRL_NONSEC_STATUS14_ADDR(base) ((base) + 0x128)
#define SOC_ACTRL_NONSEC_STATUS15_ADDR(base) ((base) + 0x12C)
#define SOC_ACTRL_NONSEC_STATUS16_ADDR(base) ((base) + 0x130)
#define SOC_ACTRL_NONSEC_STATUS17_ADDR(base) ((base) + 0x134)
#define SOC_ACTRL_NONSEC_STATUS18_ADDR(base) ((base) + 0x138)
#define SOC_ACTRL_NONSEC_STATUS19_ADDR(base) ((base) + 0x13C)
#define SOC_ACTRL_NONSEC_STATUS20_ADDR(base) ((base) + 0x140)
#define SOC_ACTRL_NONSEC_STATUS21_ADDR(base) ((base) + 0x144)
#define SOC_ACTRL_NONSEC_STATUS22_ADDR(base) ((base) + 0x148)
#define SOC_ACTRL_NONSEC_STATUS23_ADDR(base) ((base) + 0x14C)
#define SOC_ACTRL_NONSEC_STATUS24_ADDR(base) ((base) + 0x150)
#define SOC_ACTRL_NONSEC_STATUS25_ADDR(base) ((base) + 0x154)
#define SOC_ACTRL_NONSEC_STATUS26_ADDR(base) ((base) + 0x158)
#define SOC_ACTRL_NONSEC_STATUS27_ADDR(base) ((base) + 0x15C)
#define SOC_ACTRL_NONSEC_STATUS28_ADDR(base) ((base) + 0x160)
#define SOC_ACTRL_NONSEC_STATUS29_ADDR(base) ((base) + 0x164)
#define SOC_ACTRL_NONSEC_STATUS30_ADDR(base) ((base) + 0x168)
#define SOC_ACTRL_NONSEC_STATUS31_ADDR(base) ((base) + 0x16C)
#define SOC_ACTRL_NONSEC_STATUS32_ADDR(base) ((base) + 0x170)
#define SOC_ACTRL_NONSEC_STATUS33_ADDR(base) ((base) + 0x174)
#define SOC_ACTRL_NONSEC_STATUS34_ADDR(base) ((base) + 0x178)
#define SOC_ACTRL_NONSEC_STATUS35_ADDR(base) ((base) + 0x17C)
#define SOC_ACTRL_NONSEC_STATUS36_ADDR(base) ((base) + 0x180)
#define SOC_ACTRL_NONSEC_STATUS37_ADDR(base) ((base) + 0x184)
#define SOC_ACTRL_NONSEC_STATUS38_ADDR(base) ((base) + 0x188)
#define SOC_ACTRL_NONSEC_STATUS39_ADDR(base) ((base) + 0x18C)
#define SOC_ACTRL_NONSEC_STATUS40_ADDR(base) ((base) + 0x190)
#define SOC_ACTRL_NONSEC_STATUS41_ADDR(base) ((base) + 0x194)
#define SOC_ACTRL_NONSEC_STATUS42_ADDR(base) ((base) + 0x198)
#define SOC_ACTRL_NONSEC_STATUS43_ADDR(base) ((base) + 0x19C)
#define SOC_ACTRL_NONSEC_STATUS44_ADDR(base) ((base) + 0x1A0)
#define SOC_ACTRL_NONSEC_STATUS45_ADDR(base) ((base) + 0x1A4)
#define SOC_ACTRL_NONSEC_STATUS46_ADDR(base) ((base) + 0x1A8)
#define SOC_ACTRL_NONSEC_STATUS47_ADDR(base) ((base) + 0x1AC)
#define SOC_ACTRL_NONSEC_STATUS48_ADDR(base) ((base) + 0x1B0)
#define SOC_ACTRL_NONSEC_STATUS49_ADDR(base) ((base) + 0x1B4)
#define SOC_ACTRL_NONSEC_STATUS50_ADDR(base) ((base) + 0x1B8)
#define SOC_ACTRL_NONSEC_STATUS51_ADDR(base) ((base) + 0x1BC)
#define SOC_ACTRL_NONSEC_STATUS52_ADDR(base) ((base) + 0x1C0)
#define SOC_ACTRL_NONSEC_STATUS53_ADDR(base) ((base) + 0x1C4)
#define SOC_ACTRL_NONSEC_STATUS54_ADDR(base) ((base) + 0x1C8)
#define SOC_ACTRL_NONSEC_STATUS55_ADDR(base) ((base) + 0x1CC)
#define SOC_ACTRL_IP_IDLE_STATUS_ADDR(base) ((base) + 0x1D0)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_ADDR(base) ((base) + 0x1D4)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_NPU_ADDR(base) ((base) + 0x1D8)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_MEDIA2_ADDR(base) ((base) + 0x1DC)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_MEDIA1_ADDR(base) ((base) + 0x1E0)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_GPU_ADDR(base) ((base) + 0x1E4)
#define SOC_ACTRL_ASPQIC_NOPENDING_MSK0_ADDR(base) ((base) + 0x1E8)
#define SOC_ACTRL_ASPQIC_NOPENDING_MSK1_ADDR(base) ((base) + 0x1EC)
#define SOC_ACTRL_IOMCUQIC_NOPENDING_MSK0_ADDR(base) ((base) + 0x1F0)
#define SOC_ACTRL_IOMCUQIC_NOPENDING_MSK1_ADDR(base) ((base) + 0x1F4)
#define SOC_ACTRL_AOQIC_NOPENDING_MSK0_ADDR(base) ((base) + 0x1F8)
#define SOC_ACTRL_AOQIC_NOPENDING_MSK1_ADDR(base) ((base) + 0x1FC)
#define SOC_ACTRL_IOMCUQIC_NOPENDING_PDMS_MSK_ADDR(base) ((base) + 0x200)
#define SOC_ACTRL_AOQIC_NOPENDING_PDMS_MSK_ADDR(base) ((base) + 0x204)
#define SOC_ACTRL_HIPHYIO_INTR_MSK_ADDR(base) ((base) + 0x208)
#define SOC_ACTRL_HIOSTS_GPIO_INTR_STATUS_ADDR(base) ((base) + 0x20C)
#define SOC_ACTRL_HSDT_MEM_STATUS_ADDR(base) ((base) + 0x210)
#define SOC_ACTRL_ASP_AUTOFS_BYP0_ADDR(base) ((base) + 0x214)
#define SOC_ACTRL_ASP_AUTOFS_BYP1_ADDR(base) ((base) + 0x218)
#define SOC_ACTRL_IOMCU_AUTOFS_BYP0_ADDR(base) ((base) + 0x21C)
#define SOC_ACTRL_IOMCU_AUTOFS_BYP1_ADDR(base) ((base) + 0x220)
#define SOC_ACTRL_AO_AUTOFS_BYP0_ADDR(base) ((base) + 0x224)
#define SOC_ACTRL_AO_AUTOFS_BYP1_ADDR(base) ((base) + 0x228)
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_LOW_ADDR(base) ((base) + 0x22C)
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_HIGH_ADDR(base) ((base) + 0x230)
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_LOW_ADDR(base) ((base) + 0x234)
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_HIGH_ADDR(base) ((base) + 0x238)
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_LOW_ADDR(base) ((base) + 0x23C)
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_HIGH_ADDR(base) ((base) + 0x240)
#define SOC_ACTRL_MWC_F_NONSEC11_ADDR(base) ((base) + 0x300)
#define SOC_ACTRL_MWC_F_NONSEC12_ADDR(base) ((base) + 0x304)
#define SOC_ACTRL_MWC_F_NONSEC13_ADDR(base) ((base) + 0x308)
#define SOC_ACTRL_MWC_F_NONSEC14_ADDR(base) ((base) + 0x30C)
#define SOC_ACTRL_MWC_F_NONSEC15_ADDR(base) ((base) + 0x310)
#define SOC_ACTRL_MWC_F_NONSEC16_ADDR(base) ((base) + 0x314)
#define SOC_ACTRL_MWC_F_NONSEC17_ADDR(base) ((base) + 0x318)
#define SOC_ACTRL_MWC_F_NONSEC18_ADDR(base) ((base) + 0x31C)
#define SOC_ACTRL_MWC_F_NONSEC19_ADDR(base) ((base) + 0x320)
#define SOC_ACTRL_MWC_F_NONSEC20_ADDR(base) ((base) + 0x324)
#define SOC_ACTRL_MWC_F_NONSEC21_ADDR(base) ((base) + 0x328)
#define SOC_ACTRL_MWC_F_NONSEC22_ADDR(base) ((base) + 0x32C)
#define SOC_ACTRL_MWC_F_NONSEC23_ADDR(base) ((base) + 0x330)
#define SOC_ACTRL_MWC_F_NONSEC24_ADDR(base) ((base) + 0x334)
#define SOC_ACTRL_MWC_F_NONSEC25_ADDR(base) ((base) + 0x338)
#define SOC_ACTRL_MWC_F_NONSEC26_ADDR(base) ((base) + 0x33C)
#define SOC_ACTRL_MWC_F_NONSEC27_ADDR(base) ((base) + 0x340)
#define SOC_ACTRL_MWC_F_NONSEC28_ADDR(base) ((base) + 0x344)
#define SOC_ACTRL_MWC_F_NONSEC29_ADDR(base) ((base) + 0x348)
#define SOC_ACTRL_MWC_F_NONSEC30_ADDR(base) ((base) + 0x34C)
#define SOC_ACTRL_MWC_F_NONSEC31_ADDR(base) ((base) + 0x350)
#define SOC_ACTRL_MWC_F_NONSEC32_ADDR(base) ((base) + 0x354)
#define SOC_ACTRL_MWC_F_NONSEC33_ADDR(base) ((base) + 0x358)
#define SOC_ACTRL_MWC_F_NONSEC34_ADDR(base) ((base) + 0x35C)
#define SOC_ACTRL_MWC_F_NONSEC35_ADDR(base) ((base) + 0x360)
#define SOC_ACTRL_MWC_F_NONSEC36_ADDR(base) ((base) + 0x364)
#define SOC_ACTRL_MWC_F_NONSEC37_ADDR(base) ((base) + 0x368)
#define SOC_ACTRL_MWC_F_NONSEC38_ADDR(base) ((base) + 0x36C)
#define SOC_ACTRL_MWC_F_NONSEC39_ADDR(base) ((base) + 0x370)
#define SOC_ACTRL_MWC_F_NONSEC40_ADDR(base) ((base) + 0x374)
#define SOC_ACTRL_MWC_F_NONSEC41_ADDR(base) ((base) + 0x378)
#define SOC_ACTRL_MWC_F_NONSEC42_ADDR(base) ((base) + 0x37C)
#define SOC_ACTRL_MWC_F_NONSEC43_ADDR(base) ((base) + 0x380)
#define SOC_ACTRL_MWC_F_NONSEC44_ADDR(base) ((base) + 0x384)
#define SOC_ACTRL_MWC_F_NONSEC45_ADDR(base) ((base) + 0x388)
#define SOC_ACTRL_MWC_F_NONSEC46_ADDR(base) ((base) + 0x38C)
#define SOC_ACTRL_MWC_F_NONSEC47_ADDR(base) ((base) + 0x390)
#define SOC_ACTRL_MWC_F_NONSEC48_ADDR(base) ((base) + 0x394)
#define SOC_ACTRL_MWC_F_NONSEC49_ADDR(base) ((base) + 0x398)
#define SOC_ACTRL_MWC_F_NONSEC50_ADDR(base) ((base) + 0x39C)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_ADDR(base) ((base) + 0x400)
#define SOC_ACTRL_NONSEC_CTRL8_BITMASK_ADDR(base) ((base) + 0x404)
#define SOC_ACTRL_NONSEC_CTRL9_ADDR(base) ((base) + 0x408)
#define SOC_ACTRL_NONSEC_CTRL10_ADDR(base) ((base) + 0x40C)
#define SOC_ACTRL_NONSEC_CTRL11_ADDR(base) ((base) + 0x410)
#define SOC_ACTRL_NONSEC_CTRL12_ADDR(base) ((base) + 0x414)
#define SOC_ACTRL_NONSEC_CTRL13_ADDR(base) ((base) + 0x418)
#define SOC_ACTRL_MDM_NS_RSV_CTRL0_ADDR(base) ((base) + 0x41C)
#define SOC_ACTRL_MDM_NS_RSV_CTRL1_ADDR(base) ((base) + 0x420)
#define SOC_ACTRL_MDM_NS_RSV_CTRL2_ADDR(base) ((base) + 0x424)
#define SOC_ACTRL_MDM_NS_RSV_CTRL3_ADDR(base) ((base) + 0x428)
#define SOC_ACTRL_MDM_NS_RSV_CTRL4_ADDR(base) ((base) + 0x42C)
#define SOC_ACTRL_MDM_NS_RSV_CTRL5_ADDR(base) ((base) + 0x430)
#define SOC_ACTRL_MDM_NS_RSV_CTRL6_ADDR(base) ((base) + 0x434)
#define SOC_ACTRL_MDM_NS_RSV_CTRL7_ADDR(base) ((base) + 0x438)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL0_ADDR(base) ((base) + 0x43C)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL1_ADDR(base) ((base) + 0x440)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL2_ADDR(base) ((base) + 0x444)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL3_ADDR(base) ((base) + 0x448)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL4_ADDR(base) ((base) + 0x44C)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL5_ADDR(base) ((base) + 0x450)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL6_ADDR(base) ((base) + 0x454)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL7_ADDR(base) ((base) + 0x458)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL7_ADDR(base) ((base) + 0x45C)
#define SOC_ACTRL_AUDIO_HAPTIC0_STATUS_ADDR(base) ((base) + 0x460)
#define SOC_ACTRL_HSDT_SDS_CTRL_ADDR(base) ((base) + 0x464)
#define SOC_ACTRL_AUDIO_HAPTIC1_STATUS_ADDR(base) ((base) + 0x468)
#define SOC_ACTRL_AO_MEM_CTRL3_ADDR(base) ((base) + 0x46C)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_ADDR(base) ((base) + 0x470)
#define SOC_ACTRL_HSDT1_MEM_CTRL0_ADDR(base) ((base) + 0x474)
#define SOC_ACTRL_HSDT0_MEM_CTRL0_ADDR(base) ((base) + 0x478)
#define SOC_ACTRL_UFS_LSS_OUT_ADDR(base) ((base) + 0x47C)
#define SOC_ACTRL_IOMCU_MEM_CTRL0_ADDR(base) ((base) + 0x800)
#define SOC_ACTRL_IOMCU_MEM_CTRL1_ADDR(base) ((base) + 0x804)
#define SOC_ACTRL_IOMCU_MEM_CTRL3_ADDR(base) ((base) + 0x808)
#define SOC_ACTRL_AO_MEM_CTRL0_ADDR(base) ((base) + 0x80C)
#define SOC_ACTRL_AO_MEM_CTRL1_ADDR(base) ((base) + 0x810)
#define SOC_ACTRL_AO_MEM_CTRL2_ADDR(base) ((base) + 0x814)
#define SOC_ACTRL_SEC_SC_CTRL_ADDR(base) ((base) + 0x818)
#define SOC_ACTRL_AO_MEM_CTRL4_ADDR(base) ((base) + 0x81C)
#define SOC_ACTRL_AO_MEM_CTRL5_ADDR(base) ((base) + 0x820)
#define SOC_ACTRL_AO_MEM_CTRL6_ADDR(base) ((base) + 0x824)
#define SOC_ACTRL_AO_MEM_CTRL7_ADDR(base) ((base) + 0x828)
#define SOC_ACTRL_AO_MEM_CTRL8_ADDR(base) ((base) + 0x82C)
#define SOC_ACTRL_AO_MEM_CTRL9_ADDR(base) ((base) + 0x830)
#define SOC_ACTRL_AO_MEM_STATUS_ADDR(base) ((base) + 0x834)
#define SOC_ACTRL_SEC_CTRL0_ADDR(base) ((base) + 0x838)
#define SOC_ACTRL_SEC_STATUS0_ADDR(base) ((base) + 0x844)
#define SOC_ACTRL_AO_MEM_CTRL10_ADDR(base) ((base) + 0x848)
#define SOC_ACTRL_BITMSK_SEC_CTRL1_ADDR(base) ((base) + 0x84C)
#define SOC_ACTRL_BITMSK_SEC_CTRL2_ADDR(base) ((base) + 0x850)
#define SOC_ACTRL_BITMSK_SEC_CTRL3_ADDR(base) ((base) + 0x854)
#define SOC_ACTRL_BITMSK_SEC_CTRL4_ADDR(base) ((base) + 0x858)
#define SOC_ACTRL_SEC_STATUS1_ADDR(base) ((base) + 0x85C)
#define SOC_ACTRL_SEC_STATUS2_ADDR(base) ((base) + 0x860)
#define SOC_ACTRL_FACTEST_SEL_SEC_ADDR(base) ((base) + 0x864)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP0_ADDR(base) ((base) + 0x868)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP1_ADDR(base) ((base) + 0x86C)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP2_ADDR(base) ((base) + 0x870)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP3_ADDR(base) ((base) + 0x874)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP4_ADDR(base) ((base) + 0x878)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP5_ADDR(base) ((base) + 0x87C)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP6_ADDR(base) ((base) + 0x880)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP7_ADDR(base) ((base) + 0x884)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP_CRC0_ADDR(base) ((base) + 0x888)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP0_ADDR(base) ((base) + 0x88C)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP1_ADDR(base) ((base) + 0x890)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP2_ADDR(base) ((base) + 0x894)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP3_ADDR(base) ((base) + 0x898)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP4_ADDR(base) ((base) + 0x89C)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP5_ADDR(base) ((base) + 0x8A0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP6_ADDR(base) ((base) + 0x8A4)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP7_ADDR(base) ((base) + 0x8A8)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP_CRC0_ADDR(base) ((base) + 0x8AC)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP0_ADDR(base) ((base) + 0x8B0)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP1_ADDR(base) ((base) + 0x8B4)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP2_ADDR(base) ((base) + 0x8B8)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP3_ADDR(base) ((base) + 0x8BC)
#define SOC_ACTRL_HIEPS_COUNTERP_CRC1_ADDR(base) ((base) + 0x8C0)
#define SOC_ACTRL_MWC_F_SEC0_ADDR(base) ((base) + 0x8C4)
#define SOC_ACTRL_MWC_F_SEC1_ADDR(base) ((base) + 0x8C8)
#define SOC_ACTRL_MWC_F_SEC2_ADDR(base) ((base) + 0x8CC)
#define SOC_ACTRL_MWC_F_SEC3_ADDR(base) ((base) + 0x8D0)
#define SOC_ACTRL_MWC_F_SEC4_ADDR(base) ((base) + 0x8D4)
#define SOC_ACTRL_MWC_F_SEC5_ADDR(base) ((base) + 0x8D8)
#define SOC_ACTRL_MWC_F_SEC6_ADDR(base) ((base) + 0x8DC)
#define SOC_ACTRL_MWC_F_SEC7_ADDR(base) ((base) + 0x8E0)
#define SOC_ACTRL_MWC_F_SEC8_ADDR(base) ((base) + 0x8E4)
#define SOC_ACTRL_MWC_F_SEC9_ADDR(base) ((base) + 0x8E8)
#define SOC_ACTRL_MWC_F_SEC10_ADDR(base) ((base) + 0x8EC)
#define SOC_ACTRL_MWC_F_SEC11_ADDR(base) ((base) + 0x8F0)
#define SOC_ACTRL_MWC_F_SEC12_ADDR(base) ((base) + 0x8F4)
#define SOC_ACTRL_MWC_F_SEC13_ADDR(base) ((base) + 0x8F8)
#define SOC_ACTRL_MWC_F_SEC14_ADDR(base) ((base) + 0x8FC)
#define SOC_ACTRL_MWC_F_SEC15_ADDR(base) ((base) + 0x900)
#define SOC_ACTRL_MWC_F_SEC16_ADDR(base) ((base) + 0x904)
#define SOC_ACTRL_MWC_F_SEC17_ADDR(base) ((base) + 0x908)
#define SOC_ACTRL_MWC_F_SEC18_ADDR(base) ((base) + 0x90C)
#define SOC_ACTRL_MWC_F_SEC19_ADDR(base) ((base) + 0x910)
#define SOC_ACTRL_MWC_F_SEC20_ADDR(base) ((base) + 0x914)
#define SOC_ACTRL_MWC_F_SEC21_ADDR(base) ((base) + 0x918)
#define SOC_ACTRL_MWC_F_SEC22_ADDR(base) ((base) + 0x91C)
#define SOC_ACTRL_NSEC_LOCK_CTRL0_ADDR(base) ((base) + 0x920)
#define SOC_ACTRL_MWC_F_SEC23_ADDR(base) ((base) + 0x924)
#define SOC_ACTRL_MWC_F_SEC24_ADDR(base) ((base) + 0x928)
#define SOC_ACTRL_MWC_F_SEC25_ADDR(base) ((base) + 0x92C)
#define SOC_ACTRL_MWC_F_SEC26_ADDR(base) ((base) + 0x930)
#define SOC_ACTRL_MWC_F_SEC27_ADDR(base) ((base) + 0x934)
#define SOC_ACTRL_MWC_F_SEC28_ADDR(base) ((base) + 0x938)
#define SOC_ACTRL_MWC_F_SEC29_ADDR(base) ((base) + 0x93C)
#define SOC_ACTRL_MWC_F_SEC30_ADDR(base) ((base) + 0x940)
#define SOC_ACTRL_MWC_F_SEC31_ADDR(base) ((base) + 0x944)
#define SOC_ACTRL_MWC_F_SEC32_ADDR(base) ((base) + 0x948)
#define SOC_ACTRL_MWC_F_SEC33_ADDR(base) ((base) + 0x94C)
#define SOC_ACTRL_SEC_STATUS3_ADDR(base) ((base) + 0x950)
#define SOC_ACTRL_SEC_STATUS4_ADDR(base) ((base) + 0x954)
#define SOC_ACTRL_SEC_STATUS5_ADDR(base) ((base) + 0x958)
#define SOC_ACTRL_SEC_STATUS6_ADDR(base) ((base) + 0x95C)
#define SOC_ACTRL_SEC_STATUS7_ADDR(base) ((base) + 0x960)
#define SOC_ACTRL_SEC_STATUS8_ADDR(base) ((base) + 0x964)
#define SOC_ACTRL_SEC_STATUS9_ADDR(base) ((base) + 0x968)
#define SOC_ACTRL_SEC_STATUS10_ADDR(base) ((base) + 0x96C)
#define SOC_ACTRL_SEC_STATUS11_ADDR(base) ((base) + 0x970)
#define SOC_ACTRL_SEC_STATUS12_ADDR(base) ((base) + 0x974)
#define SOC_ACTRL_SEC_STATUS13_ADDR(base) ((base) + 0x978)
#define SOC_ACTRL_SEC_CTRL1_ADDR(base) ((base) + 0x97C)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP0_ADDR(base) ((base) + 0x980)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP1_ADDR(base) ((base) + 0x984)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP2_ADDR(base) ((base) + 0x988)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP3_ADDR(base) ((base) + 0x98C)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP4_ADDR(base) ((base) + 0x990)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP5_ADDR(base) ((base) + 0x994)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP6_ADDR(base) ((base) + 0x998)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP7_ADDR(base) ((base) + 0x99C)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP_CRC0_ADDR(base) ((base) + 0x9A0)
#define SOC_ACTRL_QIC_GLOBAL_CFG_ADDR(base) ((base) + 0x9A4)
#define SOC_ACTRL_MEDIA_MEM_CTRL0_ADDR(base) ((base) + 0x9A8)
#define SOC_ACTRL_CPU_PIPE_STATUS0_ADDR(base) ((base) + 0x9AC)
#define SOC_ACTRL_MEDIA_MEM_STATUS_ADDR(base) ((base) + 0x9B0)
#define SOC_ACTRL_STS_HIO_SPI_CS_SEL_SEC_ADDR(base) ((base) + 0x9B4)
#define SOC_ACTRL_SEC_CTRL2_ADDR(base) ((base) + 0x9B8)
#define SOC_ACTRL_SEC_CTRL3_ADDR(base) ((base) + 0x9BC)
#define SOC_ACTRL_SEC_CTRL4_ADDR(base) ((base) + 0x9C0)
#define SOC_ACTRL_AO_QSPI_TPSRAM_MEM_CTRL_ADDR(base) ((base) + 0x9C4)
#define SOC_ACTRL_QIC_GLOBAL_CFG_NPU_ADDR(base) ((base) + 0x9C8)
#define SOC_ACTRL_QIC_GLOBAL_CFG_MEIDA2_ADDR(base) ((base) + 0x9CC)
#define SOC_ACTRL_QIC_GLOBAL_CFG_MEIDA1_ADDR(base) ((base) + 0x9D4)
#define SOC_ACTRL_QIC_GLOBAL_CFG_GPU_ADDR(base) ((base) + 0x9D8)
#define SOC_ACTRL_SEC_STATUS14_ADDR(base) ((base) + 0x9E0)
#define SOC_ACTRL_SEC_STATUS15_ADDR(base) ((base) + 0x9E4)
#define SOC_ACTRL_SEC_STATUS16_ADDR(base) ((base) + 0x9E8)
#define SOC_ACTRL_AUDIO_AW_DLOCK_ADDR(base) ((base) + 0x9EC)
#define SOC_ACTRL_STS_SEL_MUX_ADDR(base) ((base) + 0x9F0)
#define SOC_ACTRL_IOMUX_SEL_STS_ADDR(base) ((base) + 0x9F4)
#define SOC_ACTRL_IOMUX_SEL_HIPHY_ADDR(base) ((base) + 0x9F8)
#define SOC_ACTRL_IOMUX_SEL_1TO3_ADDR(base) ((base) + 0x9FC)
#define SOC_ACTRL_SEC_CTRL_MSPC_QIC_DBG_ADDR(base) ((base) + 0xA00)
#define SOC_ACTRL_IOMUX_SEL_STS1_ADDR(base) ((base) + 0xA04)
#define SOC_ACTRL_BITMSK_SEC_STS_CS_ADDR(base) ((base) + 0xA08)
#define SOC_ACTRL_BITMSK_SEC_STS_SEL_ADDR(base) ((base) + 0xA0C)
#define SOC_ACTRL_BITMSK_SEC_STS_XCTRL_SEL_ADDR(base) ((base) + 0xA10)
#define SOC_ACTRL_BITMSK_SEC_STS_CLK_CTRL_ADDR(base) ((base) + 0xA14)
#define SOC_ACTRL_BITMSK_SEC_CTRL0_ADDR(base) ((base) + 0xC00)
#define SOC_ACTRL_HSDT_SEC_CTRL0_ADDR(base) ((base) + 0xC04)
#define SOC_ACTRL_MODEM_SEC_CTRL0_ADDR(base) ((base) + 0xC08)
#define SOC_ACTRL_PDEA_BIT_MASK0_ADDR(base) ((base) + 0xC0C)
#define SOC_ACTRL_PDEA_BIT_MASK1_ADDR(base) ((base) + 0xC10)
#define SOC_ACTRL_TSP_BIT_MASK0_ADDR(base) ((base) + 0xC14)
#define SOC_ACTRL_TSP_BIT_MASK1_ADDR(base) ((base) + 0xC18)
#define SOC_ACTRL_MDM_S_RSV_CTRL0_ADDR(base) ((base) + 0xC1C)
#define SOC_ACTRL_MDM_S_RSV_CTRL1_ADDR(base) ((base) + 0xC20)
#define SOC_ACTRL_MSPCQIC_TIMEOUT_ST_MSK_ADDR(base) ((base) + 0xC24)
#define SOC_ACTRL_MSPC_AUTOFS_BYP0_ADDR(base) ((base) + 0xC28)
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_LOW_ADDR(base) ((base) + 0xC30)
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_HIGH_ADDR(base) ((base) + 0xC34)
#define SOC_ACTRL_ISO_EN_GROUP_SEC_ADDR(base) ((base) + 0xF00)
#define SOC_ACTRL_MTCMOS_EN_GROUP_SEC_ADDR(base) ((base) + 0xF04)
#define SOC_ACTRL_MTCMOS_ACK_GROUP_SEC_ADDR(base) ((base) + 0xF08)
#define SOC_ACTRL_HIEPS_CER_EN_ADDR(base) ((base) + 0xF0C)
#define SOC_ACTRL_HIEPS_CTRL_SEC_ADDR(base) ((base) + 0xF10)
#define SOC_ACTRL_MSPC_RAM_CTRL_ADDR(base) ((base) + 0xF14)
#define SOC_ACTRL_HIEPS_STATE_COUNTER_ADDR(base) ((base) + 0xF18)
#define SOC_ACTRL_ACTRL2EPS_REG0_ADDR(base) ((base) + 0xF5C)
#define SOC_ACTRL_ACTRL2EPS_REG1_ADDR(base) ((base) + 0xF60)
#define SOC_ACTRL_ACTRL2EPS_REG2_ADDR(base) ((base) + 0xF64)
#define SOC_ACTRL_ACTRL2EPS_REG3_ADDR(base) ((base) + 0xF68)
#define SOC_ACTRL_ACTRL2EPS_REG4_ADDR(base) ((base) + 0xF6C)
#define SOC_ACTRL_EPS2ACTRL_REG0_ADDR(base) ((base) + 0xF70)
#define SOC_ACTRL_EPS2ACTRL_REG1_ADDR(base) ((base) + 0xF74)
#define SOC_ACTRL_EPS2ACTRL_REG2_ADDR(base) ((base) + 0xF78)
#define SOC_ACTRL_EPS2ACTRL_REG3_ADDR(base) ((base) + 0xF7C)
#define SOC_ACTRL_EPS2ACTRL_REG4_ADDR(base) ((base) + 0xF80)
#define SOC_ACTRL_HIEPS_MEM_CTRL_ADDR(base) ((base) + 0xF84)
#define SOC_ACTRL_ABSSEC_CTRL0_ADDR(base) ((base) + 0xF88)
#define SOC_ACTRL_ABSSEC_CTRL1_ADDR(base) ((base) + 0xF8C)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_ADDR(base) ((base) + 0xF90)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_MUX_ADDR(base) ((base) + 0xF94)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2core_iso_en_group0 : 16;
        unsigned int iso_en_group0_peri_msk : 16;
    } reg;
} SOC_ACTRL_ISO_EN_GROUP0_PERI_UNION;
#endif
#define SOC_ACTRL_ISO_EN_GROUP0_PERI_actrl2core_iso_en_group0_START (0)
#define SOC_ACTRL_ISO_EN_GROUP0_PERI_actrl2core_iso_en_group0_END (15)
#define SOC_ACTRL_ISO_EN_GROUP0_PERI_iso_en_group0_peri_msk_START (16)
#define SOC_ACTRL_ISO_EN_GROUP0_PERI_iso_en_group0_peri_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2core_iso_en_group1 : 16;
        unsigned int iso_en_group1_peri_msk : 16;
    } reg;
} SOC_ACTRL_ISO_EN_GROUP1_PERI_UNION;
#endif
#define SOC_ACTRL_ISO_EN_GROUP1_PERI_actrl2core_iso_en_group1_START (0)
#define SOC_ACTRL_ISO_EN_GROUP1_PERI_actrl2core_iso_en_group1_END (15)
#define SOC_ACTRL_ISO_EN_GROUP1_PERI_iso_en_group1_peri_msk_START (16)
#define SOC_ACTRL_ISO_EN_GROUP1_PERI_iso_en_group1_peri_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2core_iso_en_group2 : 16;
        unsigned int iso_en_group2_peri_msk : 16;
    } reg;
} SOC_ACTRL_ISO_EN_GROUP2_PERI_UNION;
#endif
#define SOC_ACTRL_ISO_EN_GROUP2_PERI_actrl2core_iso_en_group2_START (0)
#define SOC_ACTRL_ISO_EN_GROUP2_PERI_actrl2core_iso_en_group2_END (15)
#define SOC_ACTRL_ISO_EN_GROUP2_PERI_iso_en_group2_peri_msk_START (16)
#define SOC_ACTRL_ISO_EN_GROUP2_PERI_iso_en_group2_peri_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_iso_en_ao : 16;
        unsigned int iso_en_ao_msk : 16;
    } reg;
} SOC_ACTRL_ISO_EN_AO_UNION;
#endif
#define SOC_ACTRL_ISO_EN_AO_actrl_iso_en_ao_START (0)
#define SOC_ACTRL_ISO_EN_AO_actrl_iso_en_ao_END (15)
#define SOC_ACTRL_ISO_EN_AO_iso_en_ao_msk_START (16)
#define SOC_ACTRL_ISO_EN_AO_iso_en_ao_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2core_mtcmos_en_group0 : 16;
        unsigned int mtcmos_en_group0_peri_msk : 16;
    } reg;
} SOC_ACTRL_MTCMOS_EN_GROUP0_PERI_UNION;
#endif
#define SOC_ACTRL_MTCMOS_EN_GROUP0_PERI_actrl2core_mtcmos_en_group0_START (0)
#define SOC_ACTRL_MTCMOS_EN_GROUP0_PERI_actrl2core_mtcmos_en_group0_END (15)
#define SOC_ACTRL_MTCMOS_EN_GROUP0_PERI_mtcmos_en_group0_peri_msk_START (16)
#define SOC_ACTRL_MTCMOS_EN_GROUP0_PERI_mtcmos_en_group0_peri_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2core_mtcmos_en_group1 : 16;
        unsigned int mtcmos_en_group1_peri_msk : 16;
    } reg;
} SOC_ACTRL_MTCMOS_EN_GROUP1_PERI_UNION;
#endif
#define SOC_ACTRL_MTCMOS_EN_GROUP1_PERI_actrl2core_mtcmos_en_group1_START (0)
#define SOC_ACTRL_MTCMOS_EN_GROUP1_PERI_actrl2core_mtcmos_en_group1_END (15)
#define SOC_ACTRL_MTCMOS_EN_GROUP1_PERI_mtcmos_en_group1_peri_msk_START (16)
#define SOC_ACTRL_MTCMOS_EN_GROUP1_PERI_mtcmos_en_group1_peri_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2core_mtcmos_en_group2 : 16;
        unsigned int mtcmos_en_group2_peri_msk : 16;
    } reg;
} SOC_ACTRL_MTCMOS_EN_GROUP2_PERI_UNION;
#endif
#define SOC_ACTRL_MTCMOS_EN_GROUP2_PERI_actrl2core_mtcmos_en_group2_START (0)
#define SOC_ACTRL_MTCMOS_EN_GROUP2_PERI_actrl2core_mtcmos_en_group2_END (15)
#define SOC_ACTRL_MTCMOS_EN_GROUP2_PERI_mtcmos_en_group2_peri_msk_START (16)
#define SOC_ACTRL_MTCMOS_EN_GROUP2_PERI_mtcmos_en_group2_peri_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_mtcmos_en_ao : 16;
        unsigned int mtcmos_en_ao_msk : 16;
    } reg;
} SOC_ACTRL_MTCMOS_EN_AO_UNION;
#endif
#define SOC_ACTRL_MTCMOS_EN_AO_actrl_mtcmos_en_ao_START (0)
#define SOC_ACTRL_MTCMOS_EN_AO_actrl_mtcmos_en_ao_END (15)
#define SOC_ACTRL_MTCMOS_EN_AO_mtcmos_en_ao_msk_START (16)
#define SOC_ACTRL_MTCMOS_EN_AO_mtcmos_en_ao_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core2actrl_mtcmos_ack_group0 : 16;
        unsigned int core2actrl_mtcmos_ack_group1 : 16;
    } reg;
} SOC_ACTRL_MTCMOS_ACK0_PERI_UNION;
#endif
#define SOC_ACTRL_MTCMOS_ACK0_PERI_core2actrl_mtcmos_ack_group0_START (0)
#define SOC_ACTRL_MTCMOS_ACK0_PERI_core2actrl_mtcmos_ack_group0_END (15)
#define SOC_ACTRL_MTCMOS_ACK0_PERI_core2actrl_mtcmos_ack_group1_START (16)
#define SOC_ACTRL_MTCMOS_ACK0_PERI_core2actrl_mtcmos_ack_group1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core2actrl_mtcmos_ack_group2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ACTRL_MTCMOS_ACK1_PERI_UNION;
#endif
#define SOC_ACTRL_MTCMOS_ACK1_PERI_core2actrl_mtcmos_ack_group2_START (0)
#define SOC_ACTRL_MTCMOS_ACK1_PERI_core2actrl_mtcmos_ack_group2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_mtcmos_ack_ao : 32;
    } reg;
} SOC_ACTRL_MTCMOS_ACK_AO_UNION;
#endif
#define SOC_ACTRL_MTCMOS_ACK_AO_actrl_mtcmos_ack_ao_START (0)
#define SOC_ACTRL_MTCMOS_ACK_AO_actrl_mtcmos_ack_ao_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int qic_asp_intr_mux_sel : 5;
        unsigned int qic_asp_nopending_mux_sel0 : 5;
        unsigned int qic_asp_nopending_mux_sel1 : 5;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_ACTRL_ASPQIC_MUX_CTRL0_UNION;
#endif
#define SOC_ACTRL_ASPQIC_MUX_CTRL0_qic_asp_intr_mux_sel_START (5)
#define SOC_ACTRL_ASPQIC_MUX_CTRL0_qic_asp_intr_mux_sel_END (9)
#define SOC_ACTRL_ASPQIC_MUX_CTRL0_qic_asp_nopending_mux_sel0_START (10)
#define SOC_ACTRL_ASPQIC_MUX_CTRL0_qic_asp_nopending_mux_sel0_END (14)
#define SOC_ACTRL_ASPQIC_MUX_CTRL0_qic_asp_nopending_mux_sel1_START (15)
#define SOC_ACTRL_ASPQIC_MUX_CTRL0_qic_asp_nopending_mux_sel1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 12;
        unsigned int intr_repair_err_0 : 1;
        unsigned int intr_repair_err_1 : 1;
        unsigned int ipc_nsao_gt_clk_status : 1;
        unsigned int ipc_ao_gt_clk_status : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ACTRL_NONSEC_STATUS0_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS0_intr_repair_err_0_START (12)
#define SOC_ACTRL_NONSEC_STATUS0_intr_repair_err_0_END (12)
#define SOC_ACTRL_NONSEC_STATUS0_intr_repair_err_1_START (13)
#define SOC_ACTRL_NONSEC_STATUS0_intr_repair_err_1_END (13)
#define SOC_ACTRL_NONSEC_STATUS0_ipc_nsao_gt_clk_status_START (14)
#define SOC_ACTRL_NONSEC_STATUS0_ipc_nsao_gt_clk_status_END (14)
#define SOC_ACTRL_NONSEC_STATUS0_ipc_ao_gt_clk_status_START (15)
#define SOC_ACTRL_NONSEC_STATUS0_ipc_ao_gt_clk_status_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int qic_iomcu_intr_mux_sel : 5;
        unsigned int qic_iomcu_nopending_mux_sel0 : 5;
        unsigned int qic_iomcu_nopending_mux_sel1 : 5;
        unsigned int qic_iomcu_nopending_pdms_mux_sel : 3;
        unsigned int qic_iomcu_idlereq_mux_sel : 1;
        unsigned int qic_iomcu_idleack_mux_sel : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_ACTRL_IOMCUQIC_MUX_CTRL_UNION;
#endif
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_intr_mux_sel_START (5)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_intr_mux_sel_END (9)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_nopending_mux_sel0_START (10)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_nopending_mux_sel0_END (14)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_nopending_mux_sel1_START (15)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_nopending_mux_sel1_END (19)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_nopending_pdms_mux_sel_START (20)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_nopending_pdms_mux_sel_END (22)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_idlereq_mux_sel_START (23)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_idlereq_mux_sel_END (23)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_idleack_mux_sel_START (24)
#define SOC_ACTRL_IOMCUQIC_MUX_CTRL_qic_iomcu_idleack_mux_sel_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_spi_tpram_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ACTRL_AO_SPI_TPSRAM_MEM_CTRL_UNION;
#endif
#define SOC_ACTRL_AO_SPI_TPSRAM_MEM_CTRL_ao_spi_tpram_mem_ctrl_START (0)
#define SOC_ACTRL_AO_SPI_TPSRAM_MEM_CTRL_ao_spi_tpram_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_mrb_busy_flag_astatus0 : 32;
    } reg;
} SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS0_UNION;
#endif
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS0_bisr_mrb_busy_flag_astatus0_START (0)
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS0_bisr_mrb_busy_flag_astatus0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_mrb_busy_flag_astatus1 : 32;
    } reg;
} SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS1_UNION;
#endif
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS1_bisr_mrb_busy_flag_astatus1_START (0)
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS1_bisr_mrb_busy_flag_astatus1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_mrb_busy_flag_astatus2 : 32;
    } reg;
} SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS2_UNION;
#endif
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS2_bisr_mrb_busy_flag_astatus2_START (0)
#define SOC_ACTRL_BISR_MRB_BUSY_FLAG_STATUS2_bisr_mrb_busy_flag_astatus2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_repair_done_status0 : 32;
    } reg;
} SOC_ACTRL_BISR_REPAIR_DONE_STATUS0_UNION;
#endif
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS0_bisr_repair_done_status0_START (0)
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS0_bisr_repair_done_status0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_repair_done_status1 : 32;
    } reg;
} SOC_ACTRL_BISR_REPAIR_DONE_STATUS1_UNION;
#endif
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS1_bisr_repair_done_status1_START (0)
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS1_bisr_repair_done_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_repair_done_status2 : 32;
    } reg;
} SOC_ACTRL_BISR_REPAIR_DONE_STATUS2_UNION;
#endif
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS2_bisr_repair_done_status2_START (0)
#define SOC_ACTRL_BISR_REPAIR_DONE_STATUS2_bisr_repair_done_status2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_repair_ack_status0 : 32;
    } reg;
} SOC_ACTRL_BISR_REPAIR_ACK_STATUS0_UNION;
#endif
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS0_bisr_repair_ack_status0_START (0)
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS0_bisr_repair_ack_status0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_repair_ack_status1 : 32;
    } reg;
} SOC_ACTRL_BISR_REPAIR_ACK_STATUS1_UNION;
#endif
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS1_bisr_repair_ack_status1_START (0)
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS1_bisr_repair_ack_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_repair_ack_status2 : 32;
    } reg;
} SOC_ACTRL_BISR_REPAIR_ACK_STATUS2_UNION;
#endif
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS2_bisr_repair_ack_status2_START (0)
#define SOC_ACTRL_BISR_REPAIR_ACK_STATUS2_bisr_repair_ack_status2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_dbg_info_0_astatus0 : 32;
    } reg;
} SOC_ACTRL_BISR_DBG_INFO_0_STAUS0_UNION;
#endif
#define SOC_ACTRL_BISR_DBG_INFO_0_STAUS0_bisr_dbg_info_0_astatus0_START (0)
#define SOC_ACTRL_BISR_DBG_INFO_0_STAUS0_bisr_dbg_info_0_astatus0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_dbg_info_0_astatus1 : 32;
    } reg;
} SOC_ACTRL_BISR_DBG_INFO_0_STAUS1_UNION;
#endif
#define SOC_ACTRL_BISR_DBG_INFO_0_STAUS1_bisr_dbg_info_0_astatus1_START (0)
#define SOC_ACTRL_BISR_DBG_INFO_0_STAUS1_bisr_dbg_info_0_astatus1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_bitmsk_ctrl2 : 16;
        unsigned int bitmsk_nonsec_ctrl2_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_NONSEC_CTRL2_UNION;
#endif
#define SOC_ACTRL_BITMSK_NONSEC_CTRL2_actrl_bitmsk_ctrl2_START (0)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL2_actrl_bitmsk_ctrl2_END (15)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL2_bitmsk_nonsec_ctrl2_msk_START (16)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL2_bitmsk_nonsec_ctrl2_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_bitmsk_ctrl3 : 16;
        unsigned int bitmsk_nonsec_ctrl3_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_NONSEC_CTRL3_UNION;
#endif
#define SOC_ACTRL_BITMSK_NONSEC_CTRL3_actrl_bitmsk_ctrl3_START (0)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL3_actrl_bitmsk_ctrl3_END (15)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL3_bitmsk_nonsec_ctrl3_msk_START (16)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL3_bitmsk_nonsec_ctrl3_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_bitmsk_ctrl4 : 16;
        unsigned int bitmsk_nonsec_ctrl4_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_NONSEC_CTRL4_UNION;
#endif
#define SOC_ACTRL_BITMSK_NONSEC_CTRL4_actrl_bitmsk_ctrl4_START (0)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL4_actrl_bitmsk_ctrl4_END (15)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL4_bitmsk_nonsec_ctrl4_msk_START (16)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL4_bitmsk_nonsec_ctrl4_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_bitmsk_ctrl5 : 16;
        unsigned int bitmsk_nonsec_ctrl5_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_NONSEC_CTRL5_UNION;
#endif
#define SOC_ACTRL_BITMSK_NONSEC_CTRL5_actrl_bitmsk_ctrl5_START (0)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL5_actrl_bitmsk_ctrl5_END (15)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL5_bitmsk_nonsec_ctrl5_msk_START (16)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL5_bitmsk_nonsec_ctrl5_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_status1 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS1_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS1_actrl_status1_START (0)
#define SOC_ACTRL_NONSEC_STATUS1_actrl_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_status2 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS2_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS2_actrl_status2_START (0)
#define SOC_ACTRL_NONSEC_STATUS2_actrl_status2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tp_group_sel_ao : 4;
        unsigned int reserved_0 : 4;
        unsigned int intr_repair_err_msk_1 : 1;
        unsigned int reserved_1 : 7;
        unsigned int bitmsk_nonsec_ctrl6_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_NONSEC_CTRL6_UNION;
#endif
#define SOC_ACTRL_BITMSK_NONSEC_CTRL6_tp_group_sel_ao_START (0)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL6_tp_group_sel_ao_END (3)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL6_intr_repair_err_msk_1_START (8)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL6_intr_repair_err_msk_1_END (8)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL6_bitmsk_nonsec_ctrl6_msk_START (16)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL6_bitmsk_nonsec_ctrl6_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fac_test_tp : 10;
        unsigned int sc_asp_hiaxi_st : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_ACTRL_NONSEC_STATUS3_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS3_fac_test_tp_START (0)
#define SOC_ACTRL_NONSEC_STATUS3_fac_test_tp_END (9)
#define SOC_ACTRL_NONSEC_STATUS3_sc_asp_hiaxi_st_START (10)
#define SOC_ACTRL_NONSEC_STATUS3_sc_asp_hiaxi_st_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int hisee_jtag_sel : 1;
        unsigned int reserved_1 : 11;
        unsigned int ipc_nsao_gt_clk_bypass : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 13;
    } reg;
} SOC_ACTRL_NONSEC_CTRL0_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL0_hisee_jtag_sel_START (5)
#define SOC_ACTRL_NONSEC_CTRL0_hisee_jtag_sel_END (5)
#define SOC_ACTRL_NONSEC_CTRL0_ipc_nsao_gt_clk_bypass_START (17)
#define SOC_ACTRL_NONSEC_CTRL0_ipc_nsao_gt_clk_bypass_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 24;
        unsigned int mad_dbg_aw_dcdrerr_secerr_slverr_viserr_s0 : 4;
        unsigned int mad_dbg_ar_dcdrerr_secerr_slverr_viserr_s0 : 4;
    } reg;
} SOC_ACTRL_NONSEC_STATUS4_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS4_mad_dbg_aw_dcdrerr_secerr_slverr_viserr_s0_START (24)
#define SOC_ACTRL_NONSEC_STATUS4_mad_dbg_aw_dcdrerr_secerr_slverr_viserr_s0_END (27)
#define SOC_ACTRL_NONSEC_STATUS4_mad_dbg_ar_dcdrerr_secerr_slverr_viserr_s0_START (28)
#define SOC_ACTRL_NONSEC_STATUS4_mad_dbg_ar_dcdrerr_secerr_slverr_viserr_s0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int qic_ao_intr_mux_sel : 5;
        unsigned int qic_ao_nopending_mux_sel0 : 5;
        unsigned int qic_ao_nopending_mux_sel1 : 5;
        unsigned int qic_ao_nopending_pdms_mux_sel : 3;
        unsigned int qic_ao_idlereq_mux_sel : 1;
        unsigned int qic_ao_idleack_mux_sel : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_ACTRL_NONSEC_STATUS5_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_intr_mux_sel_START (5)
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_intr_mux_sel_END (9)
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_nopending_mux_sel0_START (10)
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_nopending_mux_sel0_END (14)
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_nopending_mux_sel1_START (15)
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_nopending_mux_sel1_END (19)
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_nopending_pdms_mux_sel_START (20)
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_nopending_pdms_mux_sel_END (22)
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_idlereq_mux_sel_START (23)
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_idlereq_mux_sel_END (23)
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_idleack_mux_sel_START (24)
#define SOC_ACTRL_NONSEC_STATUS5_qic_ao_idleack_mux_sel_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status0 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC0_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC0_actrl_lock_status0_START (0)
#define SOC_ACTRL_MWC_F_NONSEC0_actrl_lock_status0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status1 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC1_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC1_actrl_lock_status1_START (0)
#define SOC_ACTRL_MWC_F_NONSEC1_actrl_lock_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status2 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC2_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC2_actrl_lock_status2_START (0)
#define SOC_ACTRL_MWC_F_NONSEC2_actrl_lock_status2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status3 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC3_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC3_actrl_lock_status3_START (0)
#define SOC_ACTRL_MWC_F_NONSEC3_actrl_lock_status3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xctrl_cs_sel_ns : 16;
        unsigned int bitmsk_nonsec_cs_sel : 16;
    } reg;
} SOC_ACTRL_NONSEC_CTRL1_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL1_xctrl_cs_sel_ns_START (0)
#define SOC_ACTRL_NONSEC_CTRL1_xctrl_cs_sel_ns_END (15)
#define SOC_ACTRL_NONSEC_CTRL1_bitmsk_nonsec_cs_sel_START (16)
#define SOC_ACTRL_NONSEC_CTRL1_bitmsk_nonsec_cs_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dpa_wakeup_irqs_ao_en : 32;
    } reg;
} SOC_ACTRL_NONSEC_CTRL2_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL2_dpa_wakeup_irqs_ao_en_START (0)
#define SOC_ACTRL_NONSEC_CTRL2_dpa_wakeup_irqs_ao_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_nosec_spi_cs2_n_in : 16;
        unsigned int bitmsk_nosec_ctrl_sts_cs2 : 16;
    } reg;
} SOC_ACTRL_NONSEC_CTRL3_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL3_sts_nosec_spi_cs2_n_in_START (0)
#define SOC_ACTRL_NONSEC_CTRL3_sts_nosec_spi_cs2_n_in_END (15)
#define SOC_ACTRL_NONSEC_CTRL3_bitmsk_nosec_ctrl_sts_cs2_START (16)
#define SOC_ACTRL_NONSEC_CTRL3_bitmsk_nosec_ctrl_sts_cs2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_asp_intr_msk : 32;
    } reg;
} SOC_ACTRL_NONSEC_CTRL4_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL4_qic_asp_intr_msk_START (0)
#define SOC_ACTRL_NONSEC_CTRL4_qic_asp_intr_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_iomcu_intr_msk : 32;
    } reg;
} SOC_ACTRL_NONSEC_CTRL5_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL5_qic_iomcu_intr_msk_START (0)
#define SOC_ACTRL_NONSEC_CTRL5_qic_iomcu_intr_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_ao_intr_msk : 32;
    } reg;
} SOC_ACTRL_NONSEC_CTRL6_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL6_qic_ao_intr_msk_START (0)
#define SOC_ACTRL_NONSEC_CTRL6_qic_ao_intr_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_ack_dbg_en_ao : 1;
        unsigned int pwrd_ack_dbg_en_iomcu : 1;
        unsigned int reserved : 14;
        unsigned int qic_dbg_en_ns_msk : 16;
    } reg;
} SOC_ACTRL_NONSEC_CTRL7_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL7_pwrd_ack_dbg_en_ao_START (0)
#define SOC_ACTRL_NONSEC_CTRL7_pwrd_ack_dbg_en_ao_END (0)
#define SOC_ACTRL_NONSEC_CTRL7_pwrd_ack_dbg_en_iomcu_START (1)
#define SOC_ACTRL_NONSEC_CTRL7_pwrd_ack_dbg_en_iomcu_END (1)
#define SOC_ACTRL_NONSEC_CTRL7_qic_dbg_en_ns_msk_START (16)
#define SOC_ACTRL_NONSEC_CTRL7_qic_dbg_en_ns_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status4 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC4_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC4_actrl_lock_status4_START (0)
#define SOC_ACTRL_MWC_F_NONSEC4_actrl_lock_status4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status5 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC5_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC5_actrl_lock_status5_START (0)
#define SOC_ACTRL_MWC_F_NONSEC5_actrl_lock_status5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status6 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC6_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC6_actrl_lock_status6_START (0)
#define SOC_ACTRL_MWC_F_NONSEC6_actrl_lock_status6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status7 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC7_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC7_actrl_lock_status7_START (0)
#define SOC_ACTRL_MWC_F_NONSEC7_actrl_lock_status7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status8 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC8_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC8_actrl_lock_status8_START (0)
#define SOC_ACTRL_MWC_F_NONSEC8_actrl_lock_status8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status9 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC9_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC9_actrl_lock_status9_START (0)
#define SOC_ACTRL_MWC_F_NONSEC9_actrl_lock_status9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status10 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC10_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC10_actrl_lock_status10_START (0)
#define SOC_ACTRL_MWC_F_NONSEC10_actrl_lock_status10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_dbg_info_1_astatus0 : 32;
    } reg;
} SOC_ACTRL_BISR_DBG_INFO_1_STAUS0_UNION;
#endif
#define SOC_ACTRL_BISR_DBG_INFO_1_STAUS0_bisr_dbg_info_1_astatus0_START (0)
#define SOC_ACTRL_BISR_DBG_INFO_1_STAUS0_bisr_dbg_info_1_astatus0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_dbg_info_1_astatus1 : 32;
    } reg;
} SOC_ACTRL_BISR_DBG_INFO_1_STAUS1_UNION;
#endif
#define SOC_ACTRL_BISR_DBG_INFO_1_STAUS1_bisr_dbg_info_1_astatus1_START (0)
#define SOC_ACTRL_BISR_DBG_INFO_1_STAUS1_bisr_dbg_info_1_astatus1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_iomcu_idleack_msk : 16;
        unsigned int qic_iomcu_idlereq_msk : 16;
    } reg;
} SOC_ACTRL_IOMCUQIC_IDLE_MUX_UNION;
#endif
#define SOC_ACTRL_IOMCUQIC_IDLE_MUX_qic_iomcu_idleack_msk_START (0)
#define SOC_ACTRL_IOMCUQIC_IDLE_MUX_qic_iomcu_idleack_msk_END (15)
#define SOC_ACTRL_IOMCUQIC_IDLE_MUX_qic_iomcu_idlereq_msk_START (16)
#define SOC_ACTRL_IOMCUQIC_IDLE_MUX_qic_iomcu_idlereq_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_ao_idleack_msk : 16;
        unsigned int qic_ao_idlereq_msk : 16;
    } reg;
} SOC_ACTRL_AOQIC_IDLE_MUX_UNION;
#endif
#define SOC_ACTRL_AOQIC_IDLE_MUX_qic_ao_idleack_msk_START (0)
#define SOC_ACTRL_AOQIC_IDLE_MUX_qic_ao_idleack_msk_END (15)
#define SOC_ACTRL_AOQIC_IDLE_MUX_qic_ao_idlereq_msk_START (16)
#define SOC_ACTRL_AOQIC_IDLE_MUX_qic_ao_idlereq_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_spi_tplram_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ACTRL_AO_SPI_TPLSRAM_MEM_CTRL_UNION;
#endif
#define SOC_ACTRL_AO_SPI_TPLSRAM_MEM_CTRL_ao_spi_tplram_mem_ctrl_START (0)
#define SOC_ACTRL_AO_SPI_TPLSRAM_MEM_CTRL_ao_spi_tplram_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status6 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS6_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS6_actrl_nonsec_status6_START (0)
#define SOC_ACTRL_NONSEC_STATUS6_actrl_nonsec_status6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status7 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS7_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS7_actrl_nonsec_status7_START (0)
#define SOC_ACTRL_NONSEC_STATUS7_actrl_nonsec_status7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status8 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS8_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS8_actrl_nonsec_status8_START (0)
#define SOC_ACTRL_NONSEC_STATUS8_actrl_nonsec_status8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status9 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS9_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS9_actrl_nonsec_status9_START (0)
#define SOC_ACTRL_NONSEC_STATUS9_actrl_nonsec_status9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m7_ahb_dbg_info1 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS_IOMCU0_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS_IOMCU0_m7_ahb_dbg_info1_START (0)
#define SOC_ACTRL_NONSEC_STATUS_IOMCU0_m7_ahb_dbg_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m7_ahb_dbg_info2 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS_IOMCU1_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS_IOMCU1_m7_ahb_dbg_info2_START (0)
#define SOC_ACTRL_NONSEC_STATUS_IOMCU1_m7_ahb_dbg_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status10 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS10_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS10_actrl_nonsec_status10_START (0)
#define SOC_ACTRL_NONSEC_STATUS10_actrl_nonsec_status10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status11 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS11_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS11_actrl_nonsec_status11_START (0)
#define SOC_ACTRL_NONSEC_STATUS11_actrl_nonsec_status11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status12 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS12_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS12_actrl_nonsec_status12_START (0)
#define SOC_ACTRL_NONSEC_STATUS12_actrl_nonsec_status12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status13 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS13_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS13_actrl_nonsec_status13_START (0)
#define SOC_ACTRL_NONSEC_STATUS13_actrl_nonsec_status13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status14 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS14_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS14_actrl_nonsec_status14_START (0)
#define SOC_ACTRL_NONSEC_STATUS14_actrl_nonsec_status14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status15 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS15_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS15_actrl_nonsec_status15_START (0)
#define SOC_ACTRL_NONSEC_STATUS15_actrl_nonsec_status15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status16 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS16_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS16_actrl_nonsec_status16_START (0)
#define SOC_ACTRL_NONSEC_STATUS16_actrl_nonsec_status16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status17 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS17_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS17_actrl_nonsec_status17_START (0)
#define SOC_ACTRL_NONSEC_STATUS17_actrl_nonsec_status17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status18 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS18_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS18_actrl_nonsec_status18_START (0)
#define SOC_ACTRL_NONSEC_STATUS18_actrl_nonsec_status18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status19 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS19_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS19_actrl_nonsec_status19_START (0)
#define SOC_ACTRL_NONSEC_STATUS19_actrl_nonsec_status19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status20 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS20_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS20_actrl_nonsec_status20_START (0)
#define SOC_ACTRL_NONSEC_STATUS20_actrl_nonsec_status20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status21 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS21_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS21_actrl_nonsec_status21_START (0)
#define SOC_ACTRL_NONSEC_STATUS21_actrl_nonsec_status21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status22 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS22_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS22_actrl_nonsec_status22_START (0)
#define SOC_ACTRL_NONSEC_STATUS22_actrl_nonsec_status22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status23 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS23_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS23_actrl_nonsec_status23_START (0)
#define SOC_ACTRL_NONSEC_STATUS23_actrl_nonsec_status23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status24 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS24_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS24_actrl_nonsec_status24_START (0)
#define SOC_ACTRL_NONSEC_STATUS24_actrl_nonsec_status24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status25 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS25_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS25_actrl_nonsec_status25_START (0)
#define SOC_ACTRL_NONSEC_STATUS25_actrl_nonsec_status25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status26 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS26_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS26_actrl_nonsec_status26_START (0)
#define SOC_ACTRL_NONSEC_STATUS26_actrl_nonsec_status26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status27 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS27_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS27_actrl_nonsec_status27_START (0)
#define SOC_ACTRL_NONSEC_STATUS27_actrl_nonsec_status27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status28 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS28_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS28_actrl_nonsec_status28_START (0)
#define SOC_ACTRL_NONSEC_STATUS28_actrl_nonsec_status28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status29 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS29_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS29_actrl_nonsec_status29_START (0)
#define SOC_ACTRL_NONSEC_STATUS29_actrl_nonsec_status29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status30 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS30_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS30_actrl_nonsec_status30_START (0)
#define SOC_ACTRL_NONSEC_STATUS30_actrl_nonsec_status30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status31 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS31_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS31_actrl_nonsec_status31_START (0)
#define SOC_ACTRL_NONSEC_STATUS31_actrl_nonsec_status31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status32 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS32_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS32_actrl_nonsec_status32_START (0)
#define SOC_ACTRL_NONSEC_STATUS32_actrl_nonsec_status32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status33 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS33_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS33_actrl_nonsec_status33_START (0)
#define SOC_ACTRL_NONSEC_STATUS33_actrl_nonsec_status33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status34 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS34_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS34_actrl_nonsec_status34_START (0)
#define SOC_ACTRL_NONSEC_STATUS34_actrl_nonsec_status34_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status35 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS35_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS35_actrl_nonsec_status35_START (0)
#define SOC_ACTRL_NONSEC_STATUS35_actrl_nonsec_status35_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status36 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS36_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS36_actrl_nonsec_status36_START (0)
#define SOC_ACTRL_NONSEC_STATUS36_actrl_nonsec_status36_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status37 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS37_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS37_actrl_nonsec_status37_START (0)
#define SOC_ACTRL_NONSEC_STATUS37_actrl_nonsec_status37_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status38 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS38_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS38_actrl_nonsec_status38_START (0)
#define SOC_ACTRL_NONSEC_STATUS38_actrl_nonsec_status38_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status39 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS39_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS39_actrl_nonsec_status39_START (0)
#define SOC_ACTRL_NONSEC_STATUS39_actrl_nonsec_status39_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status40 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS40_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS40_actrl_nonsec_status40_START (0)
#define SOC_ACTRL_NONSEC_STATUS40_actrl_nonsec_status40_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status41 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS41_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS41_actrl_nonsec_status41_START (0)
#define SOC_ACTRL_NONSEC_STATUS41_actrl_nonsec_status41_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status42 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS42_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS42_actrl_nonsec_status42_START (0)
#define SOC_ACTRL_NONSEC_STATUS42_actrl_nonsec_status42_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status43 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS43_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS43_actrl_nonsec_status43_START (0)
#define SOC_ACTRL_NONSEC_STATUS43_actrl_nonsec_status43_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status44 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS44_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS44_actrl_nonsec_status44_START (0)
#define SOC_ACTRL_NONSEC_STATUS44_actrl_nonsec_status44_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status45 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS45_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS45_actrl_nonsec_status45_START (0)
#define SOC_ACTRL_NONSEC_STATUS45_actrl_nonsec_status45_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status46 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS46_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS46_actrl_nonsec_status46_START (0)
#define SOC_ACTRL_NONSEC_STATUS46_actrl_nonsec_status46_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status47 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS47_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS47_actrl_nonsec_status47_START (0)
#define SOC_ACTRL_NONSEC_STATUS47_actrl_nonsec_status47_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status48 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS48_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS48_actrl_nonsec_status48_START (0)
#define SOC_ACTRL_NONSEC_STATUS48_actrl_nonsec_status48_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status49 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS49_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS49_actrl_nonsec_status49_START (0)
#define SOC_ACTRL_NONSEC_STATUS49_actrl_nonsec_status49_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status50 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS50_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS50_actrl_nonsec_status50_START (0)
#define SOC_ACTRL_NONSEC_STATUS50_actrl_nonsec_status50_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status51 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS51_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS51_actrl_nonsec_status51_START (0)
#define SOC_ACTRL_NONSEC_STATUS51_actrl_nonsec_status51_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status52 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS52_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS52_actrl_nonsec_status52_START (0)
#define SOC_ACTRL_NONSEC_STATUS52_actrl_nonsec_status52_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status53 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS53_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS53_actrl_nonsec_status53_START (0)
#define SOC_ACTRL_NONSEC_STATUS53_actrl_nonsec_status53_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status54 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS54_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS54_actrl_nonsec_status54_START (0)
#define SOC_ACTRL_NONSEC_STATUS54_actrl_nonsec_status54_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_status55 : 32;
    } reg;
} SOC_ACTRL_NONSEC_STATUS55_UNION;
#endif
#define SOC_ACTRL_NONSEC_STATUS55_actrl_nonsec_status55_START (0)
#define SOC_ACTRL_NONSEC_STATUS55_actrl_nonsec_status55_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_idle : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ACTRL_IP_IDLE_STATUS_UNION;
#endif
#define SOC_ACTRL_IP_IDLE_STATUS_sts_idle_START (0)
#define SOC_ACTRL_IP_IDLE_STATUS_sts_idle_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_global_status : 32;
    } reg;
} SOC_ACTRL_QIC_GLOBAL_STATUS_UNION;
#endif
#define SOC_ACTRL_QIC_GLOBAL_STATUS_qic_global_status_START (0)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_qic_global_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_global_status_npu : 32;
    } reg;
} SOC_ACTRL_QIC_GLOBAL_STATUS_NPU_UNION;
#endif
#define SOC_ACTRL_QIC_GLOBAL_STATUS_NPU_qic_global_status_npu_START (0)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_NPU_qic_global_status_npu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_global_status_media2 : 32;
    } reg;
} SOC_ACTRL_QIC_GLOBAL_STATUS_MEDIA2_UNION;
#endif
#define SOC_ACTRL_QIC_GLOBAL_STATUS_MEDIA2_qic_global_status_media2_START (0)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_MEDIA2_qic_global_status_media2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_global_status_media1 : 32;
    } reg;
} SOC_ACTRL_QIC_GLOBAL_STATUS_MEDIA1_UNION;
#endif
#define SOC_ACTRL_QIC_GLOBAL_STATUS_MEDIA1_qic_global_status_media1_START (0)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_MEDIA1_qic_global_status_media1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_global_status_gpu : 32;
    } reg;
} SOC_ACTRL_QIC_GLOBAL_STATUS_GPU_UNION;
#endif
#define SOC_ACTRL_QIC_GLOBAL_STATUS_GPU_qic_global_status_gpu_START (0)
#define SOC_ACTRL_QIC_GLOBAL_STATUS_GPU_qic_global_status_gpu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_asp_nopending_msk0 : 32;
    } reg;
} SOC_ACTRL_ASPQIC_NOPENDING_MSK0_UNION;
#endif
#define SOC_ACTRL_ASPQIC_NOPENDING_MSK0_qic_asp_nopending_msk0_START (0)
#define SOC_ACTRL_ASPQIC_NOPENDING_MSK0_qic_asp_nopending_msk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_asp_nopending_msk1 : 32;
    } reg;
} SOC_ACTRL_ASPQIC_NOPENDING_MSK1_UNION;
#endif
#define SOC_ACTRL_ASPQIC_NOPENDING_MSK1_qic_asp_nopending_msk1_START (0)
#define SOC_ACTRL_ASPQIC_NOPENDING_MSK1_qic_asp_nopending_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_iomcu_nopending_msk0 : 32;
    } reg;
} SOC_ACTRL_IOMCUQIC_NOPENDING_MSK0_UNION;
#endif
#define SOC_ACTRL_IOMCUQIC_NOPENDING_MSK0_qic_iomcu_nopending_msk0_START (0)
#define SOC_ACTRL_IOMCUQIC_NOPENDING_MSK0_qic_iomcu_nopending_msk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_iomcu_nopending_msk1 : 32;
    } reg;
} SOC_ACTRL_IOMCUQIC_NOPENDING_MSK1_UNION;
#endif
#define SOC_ACTRL_IOMCUQIC_NOPENDING_MSK1_qic_iomcu_nopending_msk1_START (0)
#define SOC_ACTRL_IOMCUQIC_NOPENDING_MSK1_qic_iomcu_nopending_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_ao_nopending_msk0 : 32;
    } reg;
} SOC_ACTRL_AOQIC_NOPENDING_MSK0_UNION;
#endif
#define SOC_ACTRL_AOQIC_NOPENDING_MSK0_qic_ao_nopending_msk0_START (0)
#define SOC_ACTRL_AOQIC_NOPENDING_MSK0_qic_ao_nopending_msk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_ao_nopending_msk1 : 32;
    } reg;
} SOC_ACTRL_AOQIC_NOPENDING_MSK1_UNION;
#endif
#define SOC_ACTRL_AOQIC_NOPENDING_MSK1_qic_ao_nopending_msk1_START (0)
#define SOC_ACTRL_AOQIC_NOPENDING_MSK1_qic_ao_nopending_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_iomcu_nopengding_pdms_mask : 32;
    } reg;
} SOC_ACTRL_IOMCUQIC_NOPENDING_PDMS_MSK_UNION;
#endif
#define SOC_ACTRL_IOMCUQIC_NOPENDING_PDMS_MSK_qic_iomcu_nopengding_pdms_mask_START (0)
#define SOC_ACTRL_IOMCUQIC_NOPENDING_PDMS_MSK_qic_iomcu_nopengding_pdms_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_ao_nopengding_pdms_mask : 32;
    } reg;
} SOC_ACTRL_AOQIC_NOPENDING_PDMS_MSK_UNION;
#endif
#define SOC_ACTRL_AOQIC_NOPENDING_PDMS_MSK_qic_ao_nopengding_pdms_mask_START (0)
#define SOC_ACTRL_AOQIC_NOPENDING_PDMS_MSK_qic_ao_nopengding_pdms_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiphyio_gpio_intr_msk : 16;
        unsigned int hiphyio_gpio_intr_bit_msk : 16;
    } reg;
} SOC_ACTRL_HIPHYIO_INTR_MSK_UNION;
#endif
#define SOC_ACTRL_HIPHYIO_INTR_MSK_hiphyio_gpio_intr_msk_START (0)
#define SOC_ACTRL_HIPHYIO_INTR_MSK_hiphyio_gpio_intr_msk_END (15)
#define SOC_ACTRL_HIPHYIO_INTR_MSK_hiphyio_gpio_intr_bit_msk_START (16)
#define SOC_ACTRL_HIPHYIO_INTR_MSK_hiphyio_gpio_intr_bit_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiosts_gpio_intr_status : 32;
    } reg;
} SOC_ACTRL_HIOSTS_GPIO_INTR_STATUS_UNION;
#endif
#define SOC_ACTRL_HIOSTS_GPIO_INTR_STATUS_hiosts_gpio_intr_status_START (0)
#define SOC_ACTRL_HIOSTS_GPIO_INTR_STATUS_hiosts_gpio_intr_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_ufs_psw_ret_mem_sdo : 1;
        unsigned int actrl_ufs_psw_ret_mem_dso : 1;
        unsigned int actrl_hsdt1_ufs_ret_ram_sdo : 1;
        unsigned int actrl_hsdt1_ufs_ret_ram_dso : 1;
        unsigned int actrl_dfa_que_proc_ret_sdo : 1;
        unsigned int actrl_dfa_que_proc_ret_dso : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_ACTRL_HSDT_MEM_STATUS_UNION;
#endif
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_ufs_psw_ret_mem_sdo_START (0)
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_ufs_psw_ret_mem_sdo_END (0)
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_ufs_psw_ret_mem_dso_START (1)
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_ufs_psw_ret_mem_dso_END (1)
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_hsdt1_ufs_ret_ram_sdo_START (2)
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_hsdt1_ufs_ret_ram_sdo_END (2)
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_hsdt1_ufs_ret_ram_dso_START (3)
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_hsdt1_ufs_ret_ram_dso_END (3)
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_dfa_que_proc_ret_sdo_START (4)
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_dfa_que_proc_ret_sdo_END (4)
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_dfa_que_proc_ret_dso_START (5)
#define SOC_ACTRL_HSDT_MEM_STATUS_actrl_dfa_que_proc_ret_dso_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_autofs_byp0 : 32;
    } reg;
} SOC_ACTRL_ASP_AUTOFS_BYP0_UNION;
#endif
#define SOC_ACTRL_ASP_AUTOFS_BYP0_asp_autofs_byp0_START (0)
#define SOC_ACTRL_ASP_AUTOFS_BYP0_asp_autofs_byp0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_autofs_byp1 : 32;
    } reg;
} SOC_ACTRL_ASP_AUTOFS_BYP1_UNION;
#endif
#define SOC_ACTRL_ASP_AUTOFS_BYP1_asp_autofs_byp1_START (0)
#define SOC_ACTRL_ASP_AUTOFS_BYP1_asp_autofs_byp1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_autofs_byp0 : 32;
    } reg;
} SOC_ACTRL_IOMCU_AUTOFS_BYP0_UNION;
#endif
#define SOC_ACTRL_IOMCU_AUTOFS_BYP0_iomcu_autofs_byp0_START (0)
#define SOC_ACTRL_IOMCU_AUTOFS_BYP0_iomcu_autofs_byp0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_autofs_byp1 : 32;
    } reg;
} SOC_ACTRL_IOMCU_AUTOFS_BYP1_UNION;
#endif
#define SOC_ACTRL_IOMCU_AUTOFS_BYP1_iomcu_autofs_byp1_START (0)
#define SOC_ACTRL_IOMCU_AUTOFS_BYP1_iomcu_autofs_byp1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_autofs_byp0 : 32;
    } reg;
} SOC_ACTRL_AO_AUTOFS_BYP0_UNION;
#endif
#define SOC_ACTRL_AO_AUTOFS_BYP0_ao_autofs_byp0_START (0)
#define SOC_ACTRL_AO_AUTOFS_BYP0_ao_autofs_byp0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_autofs_byp1 : 32;
    } reg;
} SOC_ACTRL_AO_AUTOFS_BYP1_UNION;
#endif
#define SOC_ACTRL_AO_AUTOFS_BYP1_ao_autofs_byp1_START (0)
#define SOC_ACTRL_AO_AUTOFS_BYP1_ao_autofs_byp1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_ao_msk_low : 16;
        unsigned int qic_timeout_st_ao_msk_low_msk : 16;
    } reg;
} SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_LOW_UNION;
#endif
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_LOW_qic_timeout_st_ao_msk_low_START (0)
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_LOW_qic_timeout_st_ao_msk_low_END (15)
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_LOW_qic_timeout_st_ao_msk_low_msk_START (16)
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_LOW_qic_timeout_st_ao_msk_low_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_ao_msk_high : 16;
        unsigned int qic_timeout_st_ao_msk_high_msk : 16;
    } reg;
} SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_HIGH_UNION;
#endif
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_HIGH_qic_timeout_st_ao_msk_high_START (0)
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_HIGH_qic_timeout_st_ao_msk_high_END (15)
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_HIGH_qic_timeout_st_ao_msk_high_msk_START (16)
#define SOC_ACTRL_QIC_TIMEOUT_ST_AO_MSK_HIGH_qic_timeout_st_ao_msk_high_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_asp_msk_low : 16;
        unsigned int qic_timeout_st_asp_msk_low_msk : 16;
    } reg;
} SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_LOW_UNION;
#endif
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_LOW_qic_timeout_st_asp_msk_low_START (0)
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_LOW_qic_timeout_st_asp_msk_low_END (15)
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_LOW_qic_timeout_st_asp_msk_low_msk_START (16)
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_LOW_qic_timeout_st_asp_msk_low_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_asp_msk_high : 16;
        unsigned int qic_timeout_st_asp_msk_high_msk : 16;
    } reg;
} SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_HIGH_UNION;
#endif
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_HIGH_qic_timeout_st_asp_msk_high_START (0)
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_HIGH_qic_timeout_st_asp_msk_high_END (15)
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_HIGH_qic_timeout_st_asp_msk_high_msk_START (16)
#define SOC_ACTRL_QIC_TIMEOUT_ST_ASP_MSK_HIGH_qic_timeout_st_asp_msk_high_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_iomcu_msk_low : 16;
        unsigned int qic_timeout_st_iomcu_msk_low_msk : 16;
    } reg;
} SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_LOW_UNION;
#endif
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_LOW_qic_timeout_st_iomcu_msk_low_START (0)
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_LOW_qic_timeout_st_iomcu_msk_low_END (15)
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_LOW_qic_timeout_st_iomcu_msk_low_msk_START (16)
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_LOW_qic_timeout_st_iomcu_msk_low_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_iomcu_msk_high : 16;
        unsigned int qic_timeout_st_iomcu_msk_high_msk : 16;
    } reg;
} SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_HIGH_UNION;
#endif
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_HIGH_qic_timeout_st_iomcu_msk_high_START (0)
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_HIGH_qic_timeout_st_iomcu_msk_high_END (15)
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_HIGH_qic_timeout_st_iomcu_msk_high_msk_START (16)
#define SOC_ACTRL_QIC_TIMEOUT_ST_IOMCU_MSK_HIGH_qic_timeout_st_iomcu_msk_high_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status11 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC11_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC11_actrl_lock_status11_START (0)
#define SOC_ACTRL_MWC_F_NONSEC11_actrl_lock_status11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status12 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC12_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC12_actrl_lock_status12_START (0)
#define SOC_ACTRL_MWC_F_NONSEC12_actrl_lock_status12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status13 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC13_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC13_actrl_lock_status13_START (0)
#define SOC_ACTRL_MWC_F_NONSEC13_actrl_lock_status13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status14 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC14_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC14_actrl_lock_status14_START (0)
#define SOC_ACTRL_MWC_F_NONSEC14_actrl_lock_status14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status15 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC15_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC15_actrl_lock_status15_START (0)
#define SOC_ACTRL_MWC_F_NONSEC15_actrl_lock_status15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status16 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC16_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC16_actrl_lock_status16_START (0)
#define SOC_ACTRL_MWC_F_NONSEC16_actrl_lock_status16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status17 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC17_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC17_actrl_lock_status17_START (0)
#define SOC_ACTRL_MWC_F_NONSEC17_actrl_lock_status17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status18 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC18_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC18_actrl_lock_status18_START (0)
#define SOC_ACTRL_MWC_F_NONSEC18_actrl_lock_status18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status19 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC19_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC19_actrl_lock_status19_START (0)
#define SOC_ACTRL_MWC_F_NONSEC19_actrl_lock_status19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status20 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC20_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC20_actrl_lock_status20_START (0)
#define SOC_ACTRL_MWC_F_NONSEC20_actrl_lock_status20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status21 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC21_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC21_actrl_lock_status21_START (0)
#define SOC_ACTRL_MWC_F_NONSEC21_actrl_lock_status21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status22 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC22_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC22_actrl_lock_status22_START (0)
#define SOC_ACTRL_MWC_F_NONSEC22_actrl_lock_status22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status23 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC23_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC23_actrl_lock_status23_START (0)
#define SOC_ACTRL_MWC_F_NONSEC23_actrl_lock_status23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status24 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC24_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC24_actrl_lock_status24_START (0)
#define SOC_ACTRL_MWC_F_NONSEC24_actrl_lock_status24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status25 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC25_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC25_actrl_lock_status25_START (0)
#define SOC_ACTRL_MWC_F_NONSEC25_actrl_lock_status25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status26 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC26_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC26_actrl_lock_status26_START (0)
#define SOC_ACTRL_MWC_F_NONSEC26_actrl_lock_status26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status27 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC27_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC27_actrl_lock_status27_START (0)
#define SOC_ACTRL_MWC_F_NONSEC27_actrl_lock_status27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status28 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC28_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC28_actrl_lock_status28_START (0)
#define SOC_ACTRL_MWC_F_NONSEC28_actrl_lock_status28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status29 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC29_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC29_actrl_lock_status29_START (0)
#define SOC_ACTRL_MWC_F_NONSEC29_actrl_lock_status29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status30 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC30_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC30_actrl_lock_status30_START (0)
#define SOC_ACTRL_MWC_F_NONSEC30_actrl_lock_status30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status31 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC31_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC31_actrl_lock_status31_START (0)
#define SOC_ACTRL_MWC_F_NONSEC31_actrl_lock_status31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status32 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC32_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC32_actrl_lock_status32_START (0)
#define SOC_ACTRL_MWC_F_NONSEC32_actrl_lock_status32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status33 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC33_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC33_actrl_lock_status33_START (0)
#define SOC_ACTRL_MWC_F_NONSEC33_actrl_lock_status33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status34 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC34_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC34_actrl_lock_status34_START (0)
#define SOC_ACTRL_MWC_F_NONSEC34_actrl_lock_status34_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status35 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC35_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC35_actrl_lock_status35_START (0)
#define SOC_ACTRL_MWC_F_NONSEC35_actrl_lock_status35_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status36 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC36_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC36_actrl_lock_status36_START (0)
#define SOC_ACTRL_MWC_F_NONSEC36_actrl_lock_status36_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status37 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC37_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC37_actrl_lock_status37_START (0)
#define SOC_ACTRL_MWC_F_NONSEC37_actrl_lock_status37_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status38 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC38_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC38_actrl_lock_status38_START (0)
#define SOC_ACTRL_MWC_F_NONSEC38_actrl_lock_status38_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status39 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC39_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC39_actrl_lock_status39_START (0)
#define SOC_ACTRL_MWC_F_NONSEC39_actrl_lock_status39_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status40 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC40_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC40_actrl_lock_status40_START (0)
#define SOC_ACTRL_MWC_F_NONSEC40_actrl_lock_status40_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status41 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC41_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC41_actrl_lock_status41_START (0)
#define SOC_ACTRL_MWC_F_NONSEC41_actrl_lock_status41_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status42 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC42_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC42_actrl_lock_status42_START (0)
#define SOC_ACTRL_MWC_F_NONSEC42_actrl_lock_status42_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status43 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC43_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC43_actrl_lock_status43_START (0)
#define SOC_ACTRL_MWC_F_NONSEC43_actrl_lock_status43_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status44 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC44_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC44_actrl_lock_status44_START (0)
#define SOC_ACTRL_MWC_F_NONSEC44_actrl_lock_status44_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status45 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC45_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC45_actrl_lock_status45_START (0)
#define SOC_ACTRL_MWC_F_NONSEC45_actrl_lock_status45_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status46 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC46_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC46_actrl_lock_status46_START (0)
#define SOC_ACTRL_MWC_F_NONSEC46_actrl_lock_status46_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status47 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC47_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC47_actrl_lock_status47_START (0)
#define SOC_ACTRL_MWC_F_NONSEC47_actrl_lock_status47_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status48 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC48_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC48_actrl_lock_status48_START (0)
#define SOC_ACTRL_MWC_F_NONSEC48_actrl_lock_status48_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status49 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC49_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC49_actrl_lock_status49_START (0)
#define SOC_ACTRL_MWC_F_NONSEC49_actrl_lock_status49_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status50 : 32;
    } reg;
} SOC_ACTRL_MWC_F_NONSEC50_UNION;
#endif
#define SOC_ACTRL_MWC_F_NONSEC50_actrl_lock_status50_START (0)
#define SOC_ACTRL_MWC_F_NONSEC50_actrl_lock_status50_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sleep_mode_to_hsdt1_bypass : 1;
        unsigned int sc_spi3_cs : 2;
        unsigned int sc_spi11_cs : 2;
        unsigned int sc_spi5_cs : 4;
        unsigned int spi5_clr_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int sc_usim1_io_sel18 : 1;
        unsigned int sc_usim0_io_sel18 : 1;
        unsigned int bitmsk_nonsec_ctrl1_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_NONSEC_CTRL1_UNION;
#endif
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sleep_mode_to_hsdt1_bypass_START (0)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sleep_mode_to_hsdt1_bypass_END (0)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sc_spi3_cs_START (1)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sc_spi3_cs_END (2)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sc_spi11_cs_START (3)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sc_spi11_cs_END (4)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sc_spi5_cs_START (5)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sc_spi5_cs_END (8)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_spi5_clr_sel_START (9)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_spi5_clr_sel_END (9)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sc_usim1_io_sel18_START (14)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sc_usim1_io_sel18_END (14)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sc_usim0_io_sel18_START (15)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_sc_usim0_io_sel18_END (15)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_bitmsk_nonsec_ctrl1_msk_START (16)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL1_bitmsk_nonsec_ctrl1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nonsec_ctrl8_bitmask : 16;
        unsigned int nonsec_ctrl8_bitmask_msk : 16;
    } reg;
} SOC_ACTRL_NONSEC_CTRL8_BITMASK_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL8_BITMASK_nonsec_ctrl8_bitmask_START (0)
#define SOC_ACTRL_NONSEC_CTRL8_BITMASK_nonsec_ctrl8_bitmask_END (15)
#define SOC_ACTRL_NONSEC_CTRL8_BITMASK_nonsec_ctrl8_bitmask_msk_START (16)
#define SOC_ACTRL_NONSEC_CTRL8_BITMASK_nonsec_ctrl8_bitmask_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_ctrl9 : 32;
    } reg;
} SOC_ACTRL_NONSEC_CTRL9_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL9_actrl_nonsec_ctrl9_START (0)
#define SOC_ACTRL_NONSEC_CTRL9_actrl_nonsec_ctrl9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_ctrl10 : 32;
    } reg;
} SOC_ACTRL_NONSEC_CTRL10_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL10_actrl_nonsec_ctrl10_START (0)
#define SOC_ACTRL_NONSEC_CTRL10_actrl_nonsec_ctrl10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_ctrl11 : 32;
    } reg;
} SOC_ACTRL_NONSEC_CTRL11_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL11_actrl_nonsec_ctrl11_START (0)
#define SOC_ACTRL_NONSEC_CTRL11_actrl_nonsec_ctrl11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_ctrl12 : 32;
    } reg;
} SOC_ACTRL_NONSEC_CTRL12_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL12_actrl_nonsec_ctrl12_START (0)
#define SOC_ACTRL_NONSEC_CTRL12_actrl_nonsec_ctrl12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_nonsec_ctrl13 : 32;
    } reg;
} SOC_ACTRL_NONSEC_CTRL13_UNION;
#endif
#define SOC_ACTRL_NONSEC_CTRL13_actrl_nonsec_ctrl13_START (0)
#define SOC_ACTRL_NONSEC_CTRL13_actrl_nonsec_ctrl13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_ctrl0 : 32;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_CTRL0_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_CTRL0_mdm_ns_rsv_ctrl0_START (0)
#define SOC_ACTRL_MDM_NS_RSV_CTRL0_mdm_ns_rsv_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_ctrl1 : 32;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_CTRL1_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_CTRL1_mdm_ns_rsv_ctrl1_START (0)
#define SOC_ACTRL_MDM_NS_RSV_CTRL1_mdm_ns_rsv_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_ctrl2 : 32;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_CTRL2_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_CTRL2_mdm_ns_rsv_ctrl2_START (0)
#define SOC_ACTRL_MDM_NS_RSV_CTRL2_mdm_ns_rsv_ctrl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_ctrl3 : 32;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_CTRL3_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_CTRL3_mdm_ns_rsv_ctrl3_START (0)
#define SOC_ACTRL_MDM_NS_RSV_CTRL3_mdm_ns_rsv_ctrl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_ctrl4 : 32;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_CTRL4_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_CTRL4_mdm_ns_rsv_ctrl4_START (0)
#define SOC_ACTRL_MDM_NS_RSV_CTRL4_mdm_ns_rsv_ctrl4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_ctrl5 : 32;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_CTRL5_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_CTRL5_mdm_ns_rsv_ctrl5_START (0)
#define SOC_ACTRL_MDM_NS_RSV_CTRL5_mdm_ns_rsv_ctrl5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_ctrl6 : 32;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_CTRL6_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_CTRL6_mdm_ns_rsv_ctrl6_START (0)
#define SOC_ACTRL_MDM_NS_RSV_CTRL6_mdm_ns_rsv_ctrl6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_ctrl7 : 32;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_CTRL7_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_CTRL7_mdm_ns_rsv_ctrl7_START (0)
#define SOC_ACTRL_MDM_NS_RSV_CTRL7_mdm_ns_rsv_ctrl7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_mskctrl_bit0 : 16;
        unsigned int mdm_ns_rsv_mskctrl0 : 16;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_MSKCTRL0_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL0_mdm_ns_rsv_mskctrl_bit0_START (0)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL0_mdm_ns_rsv_mskctrl_bit0_END (15)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL0_mdm_ns_rsv_mskctrl0_START (16)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL0_mdm_ns_rsv_mskctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_mskctrl_bit1 : 16;
        unsigned int mdm_ns_rsv_mskctrl1 : 16;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_MSKCTRL1_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL1_mdm_ns_rsv_mskctrl_bit1_START (0)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL1_mdm_ns_rsv_mskctrl_bit1_END (15)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL1_mdm_ns_rsv_mskctrl1_START (16)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL1_mdm_ns_rsv_mskctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_mskctrl_bit2 : 16;
        unsigned int mdm_ns_rsv_mskctrl2 : 16;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_MSKCTRL2_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL2_mdm_ns_rsv_mskctrl_bit2_START (0)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL2_mdm_ns_rsv_mskctrl_bit2_END (15)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL2_mdm_ns_rsv_mskctrl2_START (16)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL2_mdm_ns_rsv_mskctrl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_mskctrl_bit3 : 16;
        unsigned int mdm_ns_rsv_mskctrl3 : 16;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_MSKCTRL3_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL3_mdm_ns_rsv_mskctrl_bit3_START (0)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL3_mdm_ns_rsv_mskctrl_bit3_END (15)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL3_mdm_ns_rsv_mskctrl3_START (16)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL3_mdm_ns_rsv_mskctrl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_mskctrl_bit4 : 16;
        unsigned int mdm_ns_rsv_mskctrl4 : 16;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_MSKCTRL4_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL4_mdm_ns_rsv_mskctrl_bit4_START (0)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL4_mdm_ns_rsv_mskctrl_bit4_END (15)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL4_mdm_ns_rsv_mskctrl4_START (16)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL4_mdm_ns_rsv_mskctrl4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_mskctrl_bit5 : 16;
        unsigned int mdm_ns_rsv_mskctrl5 : 16;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_MSKCTRL5_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL5_mdm_ns_rsv_mskctrl_bit5_START (0)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL5_mdm_ns_rsv_mskctrl_bit5_END (15)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL5_mdm_ns_rsv_mskctrl5_START (16)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL5_mdm_ns_rsv_mskctrl5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_mskctrl_bit6 : 16;
        unsigned int mdm_ns_rsv_mskctrl6 : 16;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_MSKCTRL6_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL6_mdm_ns_rsv_mskctrl_bit6_START (0)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL6_mdm_ns_rsv_mskctrl_bit6_END (15)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL6_mdm_ns_rsv_mskctrl6_START (16)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL6_mdm_ns_rsv_mskctrl6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_ns_rsv_mskctrl_bit7 : 16;
        unsigned int mdm_ns_rsv_mskctrl7 : 16;
    } reg;
} SOC_ACTRL_MDM_NS_RSV_MSKCTRL7_UNION;
#endif
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL7_mdm_ns_rsv_mskctrl_bit7_START (0)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL7_mdm_ns_rsv_mskctrl_bit7_END (15)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL7_mdm_ns_rsv_mskctrl7_START (16)
#define SOC_ACTRL_MDM_NS_RSV_MSKCTRL7_mdm_ns_rsv_mskctrl7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs0_rst_n_out : 1;
        unsigned int reserved : 15;
        unsigned int bitmsk_nonsec_ctrl7_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_NONSEC_CTRL7_UNION;
#endif
#define SOC_ACTRL_BITMSK_NONSEC_CTRL7_ufs0_rst_n_out_START (0)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL7_ufs0_rst_n_out_END (0)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL7_bitmsk_nonsec_ctrl7_msk_START (16)
#define SOC_ACTRL_BITMSK_NONSEC_CTRL7_bitmsk_nonsec_ctrl7_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audio_haptic_f0 : 32;
    } reg;
} SOC_ACTRL_AUDIO_HAPTIC0_STATUS_UNION;
#endif
#define SOC_ACTRL_AUDIO_HAPTIC0_STATUS_audio_haptic_f0_START (0)
#define SOC_ACTRL_AUDIO_HAPTIC0_STATUS_audio_haptic_f0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt0_sds_dsx_lvccldo_pwrdnb_dvddh8 : 1;
        unsigned int hsdt1_sds_dsx_lvccldo_pwrdnb_dvddh8 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ACTRL_HSDT_SDS_CTRL_UNION;
#endif
#define SOC_ACTRL_HSDT_SDS_CTRL_hsdt0_sds_dsx_lvccldo_pwrdnb_dvddh8_START (0)
#define SOC_ACTRL_HSDT_SDS_CTRL_hsdt0_sds_dsx_lvccldo_pwrdnb_dvddh8_END (0)
#define SOC_ACTRL_HSDT_SDS_CTRL_hsdt1_sds_dsx_lvccldo_pwrdnb_dvddh8_START (1)
#define SOC_ACTRL_HSDT_SDS_CTRL_hsdt1_sds_dsx_lvccldo_pwrdnb_dvddh8_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audio_haptic_f1 : 32;
    } reg;
} SOC_ACTRL_AUDIO_HAPTIC1_STATUS_UNION;
#endif
#define SOC_ACTRL_AUDIO_HAPTIC1_STATUS_audio_haptic_f1_START (0)
#define SOC_ACTRL_AUDIO_HAPTIC1_STATUS_audio_haptic_f1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dpa_ret_mem_ds_actrl : 1;
        unsigned int dpa_ret_mem_sd_actrl : 1;
        unsigned int mdmperi_ret_mem_ds_actrl : 1;
        unsigned int mdmperi_ret_mem_sd_actrl : 1;
        unsigned int reserved : 12;
        unsigned int ao_mem_ctrl3_msk : 16;
    } reg;
} SOC_ACTRL_AO_MEM_CTRL3_UNION;
#endif
#define SOC_ACTRL_AO_MEM_CTRL3_dpa_ret_mem_ds_actrl_START (0)
#define SOC_ACTRL_AO_MEM_CTRL3_dpa_ret_mem_ds_actrl_END (0)
#define SOC_ACTRL_AO_MEM_CTRL3_dpa_ret_mem_sd_actrl_START (1)
#define SOC_ACTRL_AO_MEM_CTRL3_dpa_ret_mem_sd_actrl_END (1)
#define SOC_ACTRL_AO_MEM_CTRL3_mdmperi_ret_mem_ds_actrl_START (2)
#define SOC_ACTRL_AO_MEM_CTRL3_mdmperi_ret_mem_ds_actrl_END (2)
#define SOC_ACTRL_AO_MEM_CTRL3_mdmperi_ret_mem_sd_actrl_START (3)
#define SOC_ACTRL_AO_MEM_CTRL3_mdmperi_ret_mem_sd_actrl_END (3)
#define SOC_ACTRL_AO_MEM_CTRL3_ao_mem_ctrl3_msk_START (16)
#define SOC_ACTRL_AO_MEM_CTRL3_ao_mem_ctrl3_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_mipi_src : 1;
        unsigned int gt_pclk_mipi : 1;
        unsigned int ip_rst_mipi_src : 1;
        unsigned int ip_prst_mipi : 1;
        unsigned int dlock_mipi_bypass : 1;
        unsigned int cpu_apb_ckg_bypass : 1;
        unsigned int reserved : 10;
        unsigned int mipi_ctrl_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_MIPI_CTRL_UNION;
#endif
#define SOC_ACTRL_BITMSK_MIPI_CTRL_gt_clk_mipi_src_START (0)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_gt_clk_mipi_src_END (0)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_gt_pclk_mipi_START (1)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_gt_pclk_mipi_END (1)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_ip_rst_mipi_src_START (2)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_ip_rst_mipi_src_END (2)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_ip_prst_mipi_START (3)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_ip_prst_mipi_END (3)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_dlock_mipi_bypass_START (4)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_dlock_mipi_bypass_END (4)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_cpu_apb_ckg_bypass_START (5)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_cpu_apb_ckg_bypass_END (5)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_mipi_ctrl_msk_START (16)
#define SOC_ACTRL_BITMSK_MIPI_CTRL_mipi_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt1_ufs_ret_ram_ds_from_actrl : 1;
        unsigned int hsdt1_ufs_ret_ram_sd_from_actrl : 1;
        unsigned int reserved : 14;
        unsigned int hsdt1_mem_ctrl0_msk : 16;
    } reg;
} SOC_ACTRL_HSDT1_MEM_CTRL0_UNION;
#endif
#define SOC_ACTRL_HSDT1_MEM_CTRL0_hsdt1_ufs_ret_ram_ds_from_actrl_START (0)
#define SOC_ACTRL_HSDT1_MEM_CTRL0_hsdt1_ufs_ret_ram_ds_from_actrl_END (0)
#define SOC_ACTRL_HSDT1_MEM_CTRL0_hsdt1_ufs_ret_ram_sd_from_actrl_START (1)
#define SOC_ACTRL_HSDT1_MEM_CTRL0_hsdt1_ufs_ret_ram_sd_from_actrl_END (1)
#define SOC_ACTRL_HSDT1_MEM_CTRL0_hsdt1_mem_ctrl0_msk_START (16)
#define SOC_ACTRL_HSDT1_MEM_CTRL0_hsdt1_mem_ctrl0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_ufs_psw_ret_mem_sd_in : 1;
        unsigned int actrl_ufs_psw_ret_mem_ds_in : 1;
        unsigned int actrl_dfa_que_proc_ret_sd : 1;
        unsigned int actrl_dfa_que_proc_ret_ds : 1;
        unsigned int reserved : 12;
        unsigned int hsdt0_mem_ctrl0_msk : 16;
    } reg;
} SOC_ACTRL_HSDT0_MEM_CTRL0_UNION;
#endif
#define SOC_ACTRL_HSDT0_MEM_CTRL0_actrl_ufs_psw_ret_mem_sd_in_START (0)
#define SOC_ACTRL_HSDT0_MEM_CTRL0_actrl_ufs_psw_ret_mem_sd_in_END (0)
#define SOC_ACTRL_HSDT0_MEM_CTRL0_actrl_ufs_psw_ret_mem_ds_in_START (1)
#define SOC_ACTRL_HSDT0_MEM_CTRL0_actrl_ufs_psw_ret_mem_ds_in_END (1)
#define SOC_ACTRL_HSDT0_MEM_CTRL0_actrl_dfa_que_proc_ret_sd_START (2)
#define SOC_ACTRL_HSDT0_MEM_CTRL0_actrl_dfa_que_proc_ret_sd_END (2)
#define SOC_ACTRL_HSDT0_MEM_CTRL0_actrl_dfa_que_proc_ret_ds_START (3)
#define SOC_ACTRL_HSDT0_MEM_CTRL0_actrl_dfa_que_proc_ret_ds_END (3)
#define SOC_ACTRL_HSDT0_MEM_CTRL0_hsdt0_mem_ctrl0_msk_START (16)
#define SOC_ACTRL_HSDT0_MEM_CTRL0_hsdt0_mem_ctrl0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs0_lss_out : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ACTRL_UFS_LSS_OUT_UNION;
#endif
#define SOC_ACTRL_UFS_LSS_OUT_ufs0_lss_out_START (0)
#define SOC_ACTRL_UFS_LSS_OUT_ufs0_lss_out_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_iomcu_mem_sd_in0 : 16;
        unsigned int iomcu_mem_ctrl0_msk : 16;
    } reg;
} SOC_ACTRL_IOMCU_MEM_CTRL0_UNION;
#endif
#define SOC_ACTRL_IOMCU_MEM_CTRL0_actrl_iomcu_mem_sd_in0_START (0)
#define SOC_ACTRL_IOMCU_MEM_CTRL0_actrl_iomcu_mem_sd_in0_END (15)
#define SOC_ACTRL_IOMCU_MEM_CTRL0_iomcu_mem_ctrl0_msk_START (16)
#define SOC_ACTRL_IOMCU_MEM_CTRL0_iomcu_mem_ctrl0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_iomcu_mem_ds_in0 : 16;
        unsigned int iomcu_mem_ctrl1_msk : 16;
    } reg;
} SOC_ACTRL_IOMCU_MEM_CTRL1_UNION;
#endif
#define SOC_ACTRL_IOMCU_MEM_CTRL1_actrl_iomcu_mem_ds_in0_START (0)
#define SOC_ACTRL_IOMCU_MEM_CTRL1_actrl_iomcu_mem_ds_in0_END (15)
#define SOC_ACTRL_IOMCU_MEM_CTRL1_iomcu_mem_ctrl1_msk_START (16)
#define SOC_ACTRL_IOMCU_MEM_CTRL1_iomcu_mem_ctrl1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_iomcu_mem_sd_in1 : 8;
        unsigned int actrl_iomcu_mem_ds_in1 : 8;
        unsigned int iomcu_mem_ctrl3_msk : 16;
    } reg;
} SOC_ACTRL_IOMCU_MEM_CTRL3_UNION;
#endif
#define SOC_ACTRL_IOMCU_MEM_CTRL3_actrl_iomcu_mem_sd_in1_START (0)
#define SOC_ACTRL_IOMCU_MEM_CTRL3_actrl_iomcu_mem_sd_in1_END (7)
#define SOC_ACTRL_IOMCU_MEM_CTRL3_actrl_iomcu_mem_ds_in1_START (8)
#define SOC_ACTRL_IOMCU_MEM_CTRL3_actrl_iomcu_mem_ds_in1_END (15)
#define SOC_ACTRL_IOMCU_MEM_CTRL3_iomcu_mem_ctrl3_msk_START (16)
#define SOC_ACTRL_IOMCU_MEM_CTRL3_iomcu_mem_ctrl3_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_asp_mem_ctrl_sd_in : 1;
        unsigned int actrl_asp_ret_mem_lp : 6;
        unsigned int actrl_ao_spi11_sd_in : 1;
        unsigned int actrl_media_xctrl_ret_mem_sd_in : 2;
        unsigned int actrl_ao_qspi_mem_sd_in : 1;
        unsigned int actrl_ao_spi3_sd_in : 1;
        unsigned int actrl_ao_spi5_sd_in : 1;
        unsigned int actrl_mad_sd_in : 1;
        unsigned int actrl_ddr_xctrl_ret_mem_sd_in : 2;
        unsigned int ao_mem_ctrl0_msk : 16;
    } reg;
} SOC_ACTRL_AO_MEM_CTRL0_UNION;
#endif
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_asp_mem_ctrl_sd_in_START (0)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_asp_mem_ctrl_sd_in_END (0)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_asp_ret_mem_lp_START (1)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_asp_ret_mem_lp_END (6)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_ao_spi11_sd_in_START (7)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_ao_spi11_sd_in_END (7)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_media_xctrl_ret_mem_sd_in_START (8)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_media_xctrl_ret_mem_sd_in_END (9)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_ao_qspi_mem_sd_in_START (10)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_ao_qspi_mem_sd_in_END (10)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_ao_spi3_sd_in_START (11)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_ao_spi3_sd_in_END (11)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_ao_spi5_sd_in_START (12)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_ao_spi5_sd_in_END (12)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_mad_sd_in_START (13)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_mad_sd_in_END (13)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_ddr_xctrl_ret_mem_sd_in_START (14)
#define SOC_ACTRL_AO_MEM_CTRL0_actrl_ddr_xctrl_ret_mem_sd_in_END (15)
#define SOC_ACTRL_AO_MEM_CTRL0_ao_mem_ctrl0_msk_START (16)
#define SOC_ACTRL_AO_MEM_CTRL0_ao_mem_ctrl0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_retmem_ctrl_sd_qice : 8;
        unsigned int actrl_dmc_a_ret_mem_sd_in : 1;
        unsigned int actrl_dmc_b_ret_mem_sd_in : 1;
        unsigned int actrl_dmc_c_ret_mem_sd_in : 1;
        unsigned int actrl_dmc_d_ret_mem_sd_in : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int ao_mem_ctrl1_msk : 16;
    } reg;
} SOC_ACTRL_AO_MEM_CTRL1_UNION;
#endif
#define SOC_ACTRL_AO_MEM_CTRL1_actrl_retmem_ctrl_sd_qice_START (0)
#define SOC_ACTRL_AO_MEM_CTRL1_actrl_retmem_ctrl_sd_qice_END (7)
#define SOC_ACTRL_AO_MEM_CTRL1_actrl_dmc_a_ret_mem_sd_in_START (8)
#define SOC_ACTRL_AO_MEM_CTRL1_actrl_dmc_a_ret_mem_sd_in_END (8)
#define SOC_ACTRL_AO_MEM_CTRL1_actrl_dmc_b_ret_mem_sd_in_START (9)
#define SOC_ACTRL_AO_MEM_CTRL1_actrl_dmc_b_ret_mem_sd_in_END (9)
#define SOC_ACTRL_AO_MEM_CTRL1_actrl_dmc_c_ret_mem_sd_in_START (10)
#define SOC_ACTRL_AO_MEM_CTRL1_actrl_dmc_c_ret_mem_sd_in_END (10)
#define SOC_ACTRL_AO_MEM_CTRL1_actrl_dmc_d_ret_mem_sd_in_START (11)
#define SOC_ACTRL_AO_MEM_CTRL1_actrl_dmc_d_ret_mem_sd_in_END (11)
#define SOC_ACTRL_AO_MEM_CTRL1_ao_mem_ctrl1_msk_START (16)
#define SOC_ACTRL_AO_MEM_CTRL1_ao_mem_ctrl1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int actrl_gpu_lp_ctrl_mem_sd : 1;
        unsigned int actrl_cpu_lp_ctrl_mem_sd : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 10;
        unsigned int ao_mem_ctrl2_msk : 16;
    } reg;
} SOC_ACTRL_AO_MEM_CTRL2_UNION;
#endif
#define SOC_ACTRL_AO_MEM_CTRL2_actrl_gpu_lp_ctrl_mem_sd_START (2)
#define SOC_ACTRL_AO_MEM_CTRL2_actrl_gpu_lp_ctrl_mem_sd_END (2)
#define SOC_ACTRL_AO_MEM_CTRL2_actrl_cpu_lp_ctrl_mem_sd_START (3)
#define SOC_ACTRL_AO_MEM_CTRL2_actrl_cpu_lp_ctrl_mem_sd_END (3)
#define SOC_ACTRL_AO_MEM_CTRL2_ao_mem_ctrl2_msk_START (16)
#define SOC_ACTRL_AO_MEM_CTRL2_ao_mem_ctrl2_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ret_mem_ctrl_sd_sca_actrl : 6;
        unsigned int ret_mem_ctrl_sd_scb_actrl : 6;
        unsigned int ret_mem_ctrl_sd_scc_actrl : 6;
        unsigned int ret_mem_ctrl_sd_scd_actrl : 6;
        unsigned int reserved : 8;
    } reg;
} SOC_ACTRL_SEC_SC_CTRL_UNION;
#endif
#define SOC_ACTRL_SEC_SC_CTRL_ret_mem_ctrl_sd_sca_actrl_START (0)
#define SOC_ACTRL_SEC_SC_CTRL_ret_mem_ctrl_sd_sca_actrl_END (5)
#define SOC_ACTRL_SEC_SC_CTRL_ret_mem_ctrl_sd_scb_actrl_START (6)
#define SOC_ACTRL_SEC_SC_CTRL_ret_mem_ctrl_sd_scb_actrl_END (11)
#define SOC_ACTRL_SEC_SC_CTRL_ret_mem_ctrl_sd_scc_actrl_START (12)
#define SOC_ACTRL_SEC_SC_CTRL_ret_mem_ctrl_sd_scc_actrl_END (17)
#define SOC_ACTRL_SEC_SC_CTRL_ret_mem_ctrl_sd_scd_actrl_START (18)
#define SOC_ACTRL_SEC_SC_CTRL_ret_mem_ctrl_sd_scd_actrl_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_mdm_ret_mem_ctrl0 : 16;
        unsigned int ao_mem_ctrl4_msk : 16;
    } reg;
} SOC_ACTRL_AO_MEM_CTRL4_UNION;
#endif
#define SOC_ACTRL_AO_MEM_CTRL4_actrl_mdm_ret_mem_ctrl0_START (0)
#define SOC_ACTRL_AO_MEM_CTRL4_actrl_mdm_ret_mem_ctrl0_END (15)
#define SOC_ACTRL_AO_MEM_CTRL4_ao_mem_ctrl4_msk_START (16)
#define SOC_ACTRL_AO_MEM_CTRL4_ao_mem_ctrl4_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_mdm_ret_mem_ctrl1 : 16;
        unsigned int ao_mem_ctrl5_msk : 16;
    } reg;
} SOC_ACTRL_AO_MEM_CTRL5_UNION;
#endif
#define SOC_ACTRL_AO_MEM_CTRL5_actrl_mdm_ret_mem_ctrl1_START (0)
#define SOC_ACTRL_AO_MEM_CTRL5_actrl_mdm_ret_mem_ctrl1_END (15)
#define SOC_ACTRL_AO_MEM_CTRL5_ao_mem_ctrl5_msk_START (16)
#define SOC_ACTRL_AO_MEM_CTRL5_ao_mem_ctrl5_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_ACTRL_AO_MEM_CTRL6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_hisec_ram_sd : 5;
        unsigned int actrl_hisec_ram_ds : 5;
        unsigned int reserved : 6;
        unsigned int ao_mem_ctrl7_msk : 16;
    } reg;
} SOC_ACTRL_AO_MEM_CTRL7_UNION;
#endif
#define SOC_ACTRL_AO_MEM_CTRL7_actrl_hisec_ram_sd_START (0)
#define SOC_ACTRL_AO_MEM_CTRL7_actrl_hisec_ram_sd_END (4)
#define SOC_ACTRL_AO_MEM_CTRL7_actrl_hisec_ram_ds_START (5)
#define SOC_ACTRL_AO_MEM_CTRL7_actrl_hisec_ram_ds_END (9)
#define SOC_ACTRL_AO_MEM_CTRL7_ao_mem_ctrl7_msk_START (16)
#define SOC_ACTRL_AO_MEM_CTRL7_ao_mem_ctrl7_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int ao_mem_ctrl8_msk : 16;
    } reg;
} SOC_ACTRL_AO_MEM_CTRL8_UNION;
#endif
#define SOC_ACTRL_AO_MEM_CTRL8_ao_mem_ctrl8_msk_START (16)
#define SOC_ACTRL_AO_MEM_CTRL8_ao_mem_ctrl8_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_mem_ctrl_reserved1 : 16;
        unsigned int ao_mem_ctrl9_msk : 16;
    } reg;
} SOC_ACTRL_AO_MEM_CTRL9_UNION;
#endif
#define SOC_ACTRL_AO_MEM_CTRL9_actrl_mem_ctrl_reserved1_START (0)
#define SOC_ACTRL_AO_MEM_CTRL9_actrl_mem_ctrl_reserved1_END (15)
#define SOC_ACTRL_AO_MEM_CTRL9_ao_mem_ctrl9_msk_START (16)
#define SOC_ACTRL_AO_MEM_CTRL9_ao_mem_ctrl9_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_sdo_astat : 1;
        unsigned int asp_dram_dso : 1;
        unsigned int asp_dram_sdo : 1;
        unsigned int asp_ocram_dso : 1;
        unsigned int asp_ocram_sdo : 1;
        unsigned int asp_iram_dso : 1;
        unsigned int asp_iram_sdo : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int mad_sd_out : 1;
        unsigned int iomcu_sd_out : 1;
        unsigned int hisec_ram_sdo : 5;
        unsigned int hisec_ram_dso : 5;
        unsigned int reserved_4 : 9;
    } reg;
} SOC_ACTRL_AO_MEM_STATUS_UNION;
#endif
#define SOC_ACTRL_AO_MEM_STATUS_asp_sdo_astat_START (0)
#define SOC_ACTRL_AO_MEM_STATUS_asp_sdo_astat_END (0)
#define SOC_ACTRL_AO_MEM_STATUS_asp_dram_dso_START (1)
#define SOC_ACTRL_AO_MEM_STATUS_asp_dram_dso_END (1)
#define SOC_ACTRL_AO_MEM_STATUS_asp_dram_sdo_START (2)
#define SOC_ACTRL_AO_MEM_STATUS_asp_dram_sdo_END (2)
#define SOC_ACTRL_AO_MEM_STATUS_asp_ocram_dso_START (3)
#define SOC_ACTRL_AO_MEM_STATUS_asp_ocram_dso_END (3)
#define SOC_ACTRL_AO_MEM_STATUS_asp_ocram_sdo_START (4)
#define SOC_ACTRL_AO_MEM_STATUS_asp_ocram_sdo_END (4)
#define SOC_ACTRL_AO_MEM_STATUS_asp_iram_dso_START (5)
#define SOC_ACTRL_AO_MEM_STATUS_asp_iram_dso_END (5)
#define SOC_ACTRL_AO_MEM_STATUS_asp_iram_sdo_START (6)
#define SOC_ACTRL_AO_MEM_STATUS_asp_iram_sdo_END (6)
#define SOC_ACTRL_AO_MEM_STATUS_mad_sd_out_START (11)
#define SOC_ACTRL_AO_MEM_STATUS_mad_sd_out_END (11)
#define SOC_ACTRL_AO_MEM_STATUS_iomcu_sd_out_START (12)
#define SOC_ACTRL_AO_MEM_STATUS_iomcu_sd_out_END (12)
#define SOC_ACTRL_AO_MEM_STATUS_hisec_ram_sdo_START (13)
#define SOC_ACTRL_AO_MEM_STATUS_hisec_ram_sdo_END (17)
#define SOC_ACTRL_AO_MEM_STATUS_hisec_ram_dso_START (18)
#define SOC_ACTRL_AO_MEM_STATUS_hisec_ram_dso_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bypass_mspc_fsm : 1;
        unsigned int mspc_fsm_st_clr : 1;
        unsigned int hieps_mon_cnt_adden : 1;
        unsigned int reserved_0 : 1;
        unsigned int sc_qic_timeout_en_sec : 1;
        unsigned int ipc_ao_gt_clk_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int jtag_dfx_disable_en : 1;
        unsigned int hisee_clk_19p2m : 1;
        unsigned int otp_trim_port : 5;
        unsigned int hisee_firewall_mainslv_sec_flag : 8;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 9;
    } reg;
} SOC_ACTRL_SEC_CTRL0_UNION;
#endif
#define SOC_ACTRL_SEC_CTRL0_bypass_mspc_fsm_START (0)
#define SOC_ACTRL_SEC_CTRL0_bypass_mspc_fsm_END (0)
#define SOC_ACTRL_SEC_CTRL0_mspc_fsm_st_clr_START (1)
#define SOC_ACTRL_SEC_CTRL0_mspc_fsm_st_clr_END (1)
#define SOC_ACTRL_SEC_CTRL0_hieps_mon_cnt_adden_START (2)
#define SOC_ACTRL_SEC_CTRL0_hieps_mon_cnt_adden_END (2)
#define SOC_ACTRL_SEC_CTRL0_sc_qic_timeout_en_sec_START (4)
#define SOC_ACTRL_SEC_CTRL0_sc_qic_timeout_en_sec_END (4)
#define SOC_ACTRL_SEC_CTRL0_ipc_ao_gt_clk_bypass_START (5)
#define SOC_ACTRL_SEC_CTRL0_ipc_ao_gt_clk_bypass_END (5)
#define SOC_ACTRL_SEC_CTRL0_jtag_dfx_disable_en_START (7)
#define SOC_ACTRL_SEC_CTRL0_jtag_dfx_disable_en_END (7)
#define SOC_ACTRL_SEC_CTRL0_hisee_clk_19p2m_START (8)
#define SOC_ACTRL_SEC_CTRL0_hisee_clk_19p2m_END (8)
#define SOC_ACTRL_SEC_CTRL0_otp_trim_port_START (9)
#define SOC_ACTRL_SEC_CTRL0_otp_trim_port_END (13)
#define SOC_ACTRL_SEC_CTRL0_hisee_firewall_mainslv_sec_flag_START (14)
#define SOC_ACTRL_SEC_CTRL0_hisee_firewall_mainslv_sec_flag_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_hifi_idle : 1;
        unsigned int jtag_dfx_disable : 1;
        unsigned int mspc_fsm_st : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ACTRL_SEC_STATUS0_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS0_asp_hifi_idle_START (0)
#define SOC_ACTRL_SEC_STATUS0_asp_hifi_idle_END (0)
#define SOC_ACTRL_SEC_STATUS0_jtag_dfx_disable_START (1)
#define SOC_ACTRL_SEC_STATUS0_jtag_dfx_disable_END (1)
#define SOC_ACTRL_SEC_STATUS0_mspc_fsm_st_START (2)
#define SOC_ACTRL_SEC_STATUS0_mspc_fsm_st_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 8;
        unsigned int ao_mem_ctrl10_msk : 16;
    } reg;
} SOC_ACTRL_AO_MEM_CTRL10_UNION;
#endif
#define SOC_ACTRL_AO_MEM_CTRL10_ao_mem_ctrl10_msk_START (16)
#define SOC_ACTRL_AO_MEM_CTRL10_ao_mem_ctrl10_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_bitmsk_sec_ctrl1 : 16;
        unsigned int bitmsk_sec_ctrl1_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_SEC_CTRL1_UNION;
#endif
#define SOC_ACTRL_BITMSK_SEC_CTRL1_actrl_bitmsk_sec_ctrl1_START (0)
#define SOC_ACTRL_BITMSK_SEC_CTRL1_actrl_bitmsk_sec_ctrl1_END (15)
#define SOC_ACTRL_BITMSK_SEC_CTRL1_bitmsk_sec_ctrl1_msk_START (16)
#define SOC_ACTRL_BITMSK_SEC_CTRL1_bitmsk_sec_ctrl1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_bitmsk_sec_ctrl2 : 16;
        unsigned int bitmsk_sec_ctrl2_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_SEC_CTRL2_UNION;
#endif
#define SOC_ACTRL_BITMSK_SEC_CTRL2_actrl_bitmsk_sec_ctrl2_START (0)
#define SOC_ACTRL_BITMSK_SEC_CTRL2_actrl_bitmsk_sec_ctrl2_END (15)
#define SOC_ACTRL_BITMSK_SEC_CTRL2_bitmsk_sec_ctrl2_msk_START (16)
#define SOC_ACTRL_BITMSK_SEC_CTRL2_bitmsk_sec_ctrl2_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_bitmsk_sec_ctrl3 : 16;
        unsigned int bitmsk_sec_ctrl3_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_SEC_CTRL3_UNION;
#endif
#define SOC_ACTRL_BITMSK_SEC_CTRL3_actrl_bitmsk_sec_ctrl3_START (0)
#define SOC_ACTRL_BITMSK_SEC_CTRL3_actrl_bitmsk_sec_ctrl3_END (15)
#define SOC_ACTRL_BITMSK_SEC_CTRL3_bitmsk_sec_ctrl3_msk_START (16)
#define SOC_ACTRL_BITMSK_SEC_CTRL3_bitmsk_sec_ctrl3_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_bitmsk_sec_ctrl4 : 16;
        unsigned int bitmsk_sec_ctrl4_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_SEC_CTRL4_UNION;
#endif
#define SOC_ACTRL_BITMSK_SEC_CTRL4_actrl_bitmsk_sec_ctrl4_START (0)
#define SOC_ACTRL_BITMSK_SEC_CTRL4_actrl_bitmsk_sec_ctrl4_END (15)
#define SOC_ACTRL_BITMSK_SEC_CTRL4_bitmsk_sec_ctrl4_msk_START (16)
#define SOC_ACTRL_BITMSK_SEC_CTRL4_bitmsk_sec_ctrl4_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status1 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS1_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS1_actrl_sec_status1_START (0)
#define SOC_ACTRL_SEC_STATUS1_actrl_sec_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status2 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS2_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS2_actrl_sec_status2_START (0)
#define SOC_ACTRL_SEC_STATUS2_actrl_sec_status2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_fac_test_sel : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ACTRL_FACTEST_SEL_SEC_UNION;
#endif
#define SOC_ACTRL_FACTEST_SEL_SEC_io_fac_test_sel_START (0)
#define SOC_ACTRL_FACTEST_SEL_SEC_io_fac_test_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_0 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP0_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP0_hieps_session_key_uncmp_eps_0_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP0_hieps_session_key_uncmp_eps_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_1 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP1_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP1_hieps_session_key_uncmp_eps_1_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP1_hieps_session_key_uncmp_eps_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_2 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP2_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP2_hieps_session_key_uncmp_eps_2_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP2_hieps_session_key_uncmp_eps_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_3 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP3_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP3_hieps_session_key_uncmp_eps_3_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP3_hieps_session_key_uncmp_eps_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_4 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP4_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP4_hieps_session_key_uncmp_eps_4_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP4_hieps_session_key_uncmp_eps_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_5 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP5_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP5_hieps_session_key_uncmp_eps_5_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP5_hieps_session_key_uncmp_eps_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_6 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP6_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP6_hieps_session_key_uncmp_eps_6_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP6_hieps_session_key_uncmp_eps_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_7 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP7_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP7_hieps_session_key_uncmp_eps_7_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP7_hieps_session_key_uncmp_eps_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_crc : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP_CRC0_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP_CRC0_hieps_session_key_uncmp_eps_crc_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_UNCMP_CRC0_hieps_session_key_uncmp_eps_crc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_ufs_0 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP0_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP0_hieps_session_key_uncmp_ufs_0_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP0_hieps_session_key_uncmp_ufs_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_ufs_1 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP1_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP1_hieps_session_key_uncmp_ufs_1_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP1_hieps_session_key_uncmp_ufs_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_ufs_2 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP2_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP2_hieps_session_key_uncmp_ufs_2_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP2_hieps_session_key_uncmp_ufs_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_ufs_3 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP3_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP3_hieps_session_key_uncmp_ufs_3_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP3_hieps_session_key_uncmp_ufs_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_ufs_4 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP4_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP4_hieps_session_key_uncmp_ufs_4_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP4_hieps_session_key_uncmp_ufs_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_ufs_5 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP5_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP5_hieps_session_key_uncmp_ufs_5_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP5_hieps_session_key_uncmp_ufs_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_ufs_6 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP6_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP6_hieps_session_key_uncmp_ufs_6_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP6_hieps_session_key_uncmp_ufs_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_ufs_7 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP7_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP7_hieps_session_key_uncmp_ufs_7_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP7_hieps_session_key_uncmp_ufs_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_ufs_crc : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP_CRC0_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP_CRC0_hieps_session_key_uncmp_ufs_crc_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_UFS_UNCMP_CRC0_hieps_session_key_uncmp_ufs_crc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps2km_counter_uncmp0 : 32;
    } reg;
} SOC_ACTRL_HIEPS_COUNTER_UNCMP0_UNION;
#endif
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP0_hieps2km_counter_uncmp0_START (0)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP0_hieps2km_counter_uncmp0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps2km_counter_uncmp1 : 32;
    } reg;
} SOC_ACTRL_HIEPS_COUNTER_UNCMP1_UNION;
#endif
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP1_hieps2km_counter_uncmp1_START (0)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP1_hieps2km_counter_uncmp1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps2km_counter_uncmp2 : 32;
    } reg;
} SOC_ACTRL_HIEPS_COUNTER_UNCMP2_UNION;
#endif
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP2_hieps2km_counter_uncmp2_START (0)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP2_hieps2km_counter_uncmp2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps2km_counter_uncmp3 : 32;
    } reg;
} SOC_ACTRL_HIEPS_COUNTER_UNCMP3_UNION;
#endif
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP3_hieps2km_counter_uncmp3_START (0)
#define SOC_ACTRL_HIEPS_COUNTER_UNCMP3_hieps2km_counter_uncmp3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps2km_counter_uncmp_crc : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ACTRL_HIEPS_COUNTERP_CRC1_UNION;
#endif
#define SOC_ACTRL_HIEPS_COUNTERP_CRC1_hieps2km_counter_uncmp_crc_START (0)
#define SOC_ACTRL_HIEPS_COUNTERP_CRC1_hieps2km_counter_uncmp_crc_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status0_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC0_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC0_actrl_lock_status0_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC0_actrl_lock_status0_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status1_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC1_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC1_actrl_lock_status1_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC1_actrl_lock_status1_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status2_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC2_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC2_actrl_lock_status2_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC2_actrl_lock_status2_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status3_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC3_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC3_actrl_lock_status3_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC3_actrl_lock_status3_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status4_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC4_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC4_actrl_lock_status4_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC4_actrl_lock_status4_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status5_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC5_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC5_actrl_lock_status5_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC5_actrl_lock_status5_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status6_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC6_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC6_actrl_lock_status6_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC6_actrl_lock_status6_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status7_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC7_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC7_actrl_lock_status7_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC7_actrl_lock_status7_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status8_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC8_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC8_actrl_lock_status8_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC8_actrl_lock_status8_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status9_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC9_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC9_actrl_lock_status9_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC9_actrl_lock_status9_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status10_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC10_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC10_actrl_lock_status10_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC10_actrl_lock_status10_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status11_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC11_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC11_actrl_lock_status11_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC11_actrl_lock_status11_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status12_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC12_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC12_actrl_lock_status12_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC12_actrl_lock_status12_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status13_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC13_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC13_actrl_lock_status13_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC13_actrl_lock_status13_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status14_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC14_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC14_actrl_lock_status14_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC14_actrl_lock_status14_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status15_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC15_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC15_actrl_lock_status15_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC15_actrl_lock_status15_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status16_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC16_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC16_actrl_lock_status16_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC16_actrl_lock_status16_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status17_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC17_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC17_actrl_lock_status17_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC17_actrl_lock_status17_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status18_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC18_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC18_actrl_lock_status18_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC18_actrl_lock_status18_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status19_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC19_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC19_actrl_lock_status19_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC19_actrl_lock_status19_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status20_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC20_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC20_actrl_lock_status20_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC20_actrl_lock_status20_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status21_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC21_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC21_actrl_lock_status21_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC21_actrl_lock_status21_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status22_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC22_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC22_actrl_lock_status22_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC22_actrl_lock_status22_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_soft_lock_dis : 1;
        unsigned int hisimc_data_disable : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ACTRL_NSEC_LOCK_CTRL0_UNION;
#endif
#define SOC_ACTRL_NSEC_LOCK_CTRL0_ao_soft_lock_dis_START (0)
#define SOC_ACTRL_NSEC_LOCK_CTRL0_ao_soft_lock_dis_END (0)
#define SOC_ACTRL_NSEC_LOCK_CTRL0_hisimc_data_disable_START (1)
#define SOC_ACTRL_NSEC_LOCK_CTRL0_hisimc_data_disable_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status23_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC23_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC23_actrl_lock_status23_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC23_actrl_lock_status23_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status24_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC24_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC24_actrl_lock_status24_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC24_actrl_lock_status24_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status25_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC25_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC25_actrl_lock_status25_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC25_actrl_lock_status25_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status26_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC26_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC26_actrl_lock_status26_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC26_actrl_lock_status26_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status27_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC27_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC27_actrl_lock_status27_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC27_actrl_lock_status27_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status28_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC28_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC28_actrl_lock_status28_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC28_actrl_lock_status28_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status29_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC29_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC29_actrl_lock_status29_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC29_actrl_lock_status29_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status30_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC30_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC30_actrl_lock_status30_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC30_actrl_lock_status30_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status31_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC31_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC31_actrl_lock_status31_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC31_actrl_lock_status31_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status32_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC32_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC32_actrl_lock_status32_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC32_actrl_lock_status32_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lock_status33_sec : 32;
    } reg;
} SOC_ACTRL_MWC_F_SEC33_UNION;
#endif
#define SOC_ACTRL_MWC_F_SEC33_actrl_lock_status33_sec_START (0)
#define SOC_ACTRL_MWC_F_SEC33_actrl_lock_status33_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status3 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS3_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS3_actrl_sec_status3_START (0)
#define SOC_ACTRL_SEC_STATUS3_actrl_sec_status3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status4 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS4_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS4_actrl_sec_status4_START (0)
#define SOC_ACTRL_SEC_STATUS4_actrl_sec_status4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status5 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS5_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS5_actrl_sec_status5_START (0)
#define SOC_ACTRL_SEC_STATUS5_actrl_sec_status5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status6 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS6_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS6_actrl_sec_status6_START (0)
#define SOC_ACTRL_SEC_STATUS6_actrl_sec_status6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status7 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS7_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS7_actrl_sec_status7_START (0)
#define SOC_ACTRL_SEC_STATUS7_actrl_sec_status7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status8 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS8_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS8_actrl_sec_status8_START (0)
#define SOC_ACTRL_SEC_STATUS8_actrl_sec_status8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status9 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS9_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS9_actrl_sec_status9_START (0)
#define SOC_ACTRL_SEC_STATUS9_actrl_sec_status9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status10 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS10_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS10_actrl_sec_status10_START (0)
#define SOC_ACTRL_SEC_STATUS10_actrl_sec_status10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status11 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS11_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS11_actrl_sec_status11_START (0)
#define SOC_ACTRL_SEC_STATUS11_actrl_sec_status11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status12 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS12_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS12_actrl_sec_status12_START (0)
#define SOC_ACTRL_SEC_STATUS12_actrl_sec_status12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status13 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS13_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS13_actrl_sec_status13_START (0)
#define SOC_ACTRL_SEC_STATUS13_actrl_sec_status13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi_dma_bypass_en : 1;
        unsigned int spi11_dma_bypass_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ACTRL_SEC_CTRL1_UNION;
#endif
#define SOC_ACTRL_SEC_CTRL1_spi_dma_bypass_en_START (0)
#define SOC_ACTRL_SEC_CTRL1_spi_dma_bypass_en_END (0)
#define SOC_ACTRL_SEC_CTRL1_spi11_dma_bypass_en_START (1)
#define SOC_ACTRL_SEC_CTRL1_spi11_dma_bypass_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_ree_0 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP0_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP0_hieps_session_key_uncmp_eps_ree_0_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP0_hieps_session_key_uncmp_eps_ree_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_ree_1 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP1_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP1_hieps_session_key_uncmp_eps_ree_1_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP1_hieps_session_key_uncmp_eps_ree_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_ree_2 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP2_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP2_hieps_session_key_uncmp_eps_ree_2_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP2_hieps_session_key_uncmp_eps_ree_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_ree_3 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP3_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP3_hieps_session_key_uncmp_eps_ree_3_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP3_hieps_session_key_uncmp_eps_ree_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_ree_4 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP4_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP4_hieps_session_key_uncmp_eps_ree_4_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP4_hieps_session_key_uncmp_eps_ree_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_ree_5 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP5_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP5_hieps_session_key_uncmp_eps_ree_5_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP5_hieps_session_key_uncmp_eps_ree_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_ree_6 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP6_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP6_hieps_session_key_uncmp_eps_ree_6_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP6_hieps_session_key_uncmp_eps_ree_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_ree_7 : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP7_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP7_hieps_session_key_uncmp_eps_ree_7_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP7_hieps_session_key_uncmp_eps_ree_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_uncmp_eps_ree_crc : 32;
    } reg;
} SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP_CRC0_UNION;
#endif
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP_CRC0_hieps_session_key_uncmp_eps_ree_crc_START (0)
#define SOC_ACTRL_HIEPS_SESSION_KEY_EPS_REE_UNCMP_CRC0_hieps_session_key_uncmp_eps_ree_crc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_global_cfg : 32;
    } reg;
} SOC_ACTRL_QIC_GLOBAL_CFG_UNION;
#endif
#define SOC_ACTRL_QIC_GLOBAL_CFG_qic_global_cfg_START (0)
#define SOC_ACTRL_QIC_GLOBAL_CFG_qic_global_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_sd_vdec_calc_top_ret_from_actrl : 1;
        unsigned int mem_ctrl_sd_venc_ret_from_actrl : 1;
        unsigned int mem_ctrl_sd_aae_ret_from_actrl : 1;
        unsigned int reserved : 13;
        unsigned int media_mem_ctrl0_msk : 16;
    } reg;
} SOC_ACTRL_MEDIA_MEM_CTRL0_UNION;
#endif
#define SOC_ACTRL_MEDIA_MEM_CTRL0_mem_ctrl_sd_vdec_calc_top_ret_from_actrl_START (0)
#define SOC_ACTRL_MEDIA_MEM_CTRL0_mem_ctrl_sd_vdec_calc_top_ret_from_actrl_END (0)
#define SOC_ACTRL_MEDIA_MEM_CTRL0_mem_ctrl_sd_venc_ret_from_actrl_START (1)
#define SOC_ACTRL_MEDIA_MEM_CTRL0_mem_ctrl_sd_venc_ret_from_actrl_END (1)
#define SOC_ACTRL_MEDIA_MEM_CTRL0_mem_ctrl_sd_aae_ret_from_actrl_START (2)
#define SOC_ACTRL_MEDIA_MEM_CTRL0_mem_ctrl_sd_aae_ret_from_actrl_END (2)
#define SOC_ACTRL_MEDIA_MEM_CTRL0_media_mem_ctrl0_msk_START (16)
#define SOC_ACTRL_MEDIA_MEM_CTRL0_media_mem_ctrl0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efuse_pipe_is_good : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ACTRL_CPU_PIPE_STATUS0_UNION;
#endif
#define SOC_ACTRL_CPU_PIPE_STATUS0_efuse_pipe_is_good_START (0)
#define SOC_ACTRL_CPU_PIPE_STATUS0_efuse_pipe_is_good_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_sdo_vdec_calc_top_ret_actrl : 1;
        unsigned int mem_ctrl_sdo_venc_ret_actrl : 1;
        unsigned int mem_ctrl_sdo_aae_ret_actrl : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ACTRL_MEDIA_MEM_STATUS_UNION;
#endif
#define SOC_ACTRL_MEDIA_MEM_STATUS_mem_ctrl_sdo_vdec_calc_top_ret_actrl_START (0)
#define SOC_ACTRL_MEDIA_MEM_STATUS_mem_ctrl_sdo_vdec_calc_top_ret_actrl_END (0)
#define SOC_ACTRL_MEDIA_MEM_STATUS_mem_ctrl_sdo_venc_ret_actrl_START (1)
#define SOC_ACTRL_MEDIA_MEM_STATUS_mem_ctrl_sdo_venc_ret_actrl_END (1)
#define SOC_ACTRL_MEDIA_MEM_STATUS_mem_ctrl_sdo_aae_ret_actrl_START (2)
#define SOC_ACTRL_MEDIA_MEM_STATUS_mem_ctrl_sdo_aae_ret_actrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xctrl_cs2_secure_sel : 32;
    } reg;
} SOC_ACTRL_STS_HIO_SPI_CS_SEL_SEC_UNION;
#endif
#define SOC_ACTRL_STS_HIO_SPI_CS_SEL_SEC_xctrl_cs2_secure_sel_START (0)
#define SOC_ACTRL_STS_HIO_SPI_CS_SEL_SEC_xctrl_cs2_secure_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_iomcu_dma_mst_icfg_arvcidx_ddr : 8;
        unsigned int ib_iomcu_dma_mst_icfg_awvcidx_ddr : 8;
        unsigned int ib_iomcu_dma_mst_icfg_arvcidx_device : 8;
        unsigned int ib_iomcu_dma_mst_icfg_awvcidx_device : 8;
    } reg;
} SOC_ACTRL_SEC_CTRL2_UNION;
#endif
#define SOC_ACTRL_SEC_CTRL2_ib_iomcu_dma_mst_icfg_arvcidx_ddr_START (0)
#define SOC_ACTRL_SEC_CTRL2_ib_iomcu_dma_mst_icfg_arvcidx_ddr_END (7)
#define SOC_ACTRL_SEC_CTRL2_ib_iomcu_dma_mst_icfg_awvcidx_ddr_START (8)
#define SOC_ACTRL_SEC_CTRL2_ib_iomcu_dma_mst_icfg_awvcidx_ddr_END (15)
#define SOC_ACTRL_SEC_CTRL2_ib_iomcu_dma_mst_icfg_arvcidx_device_START (16)
#define SOC_ACTRL_SEC_CTRL2_ib_iomcu_dma_mst_icfg_arvcidx_device_END (23)
#define SOC_ACTRL_SEC_CTRL2_ib_iomcu_dma_mst_icfg_awvcidx_device_START (24)
#define SOC_ACTRL_SEC_CTRL2_ib_iomcu_dma_mst_icfg_awvcidx_device_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_mspc_mst_icfg_arvcidx_ddr : 8;
        unsigned int ib_mspc_mst_icfg_awvcidx_ddr : 8;
        unsigned int ib_mspc_mst_icfg_arvcidx_device : 8;
        unsigned int ib_mspc_mst_icfg_awvcidx_device : 8;
    } reg;
} SOC_ACTRL_SEC_CTRL3_UNION;
#endif
#define SOC_ACTRL_SEC_CTRL3_ib_mspc_mst_icfg_arvcidx_ddr_START (0)
#define SOC_ACTRL_SEC_CTRL3_ib_mspc_mst_icfg_arvcidx_ddr_END (7)
#define SOC_ACTRL_SEC_CTRL3_ib_mspc_mst_icfg_awvcidx_ddr_START (8)
#define SOC_ACTRL_SEC_CTRL3_ib_mspc_mst_icfg_awvcidx_ddr_END (15)
#define SOC_ACTRL_SEC_CTRL3_ib_mspc_mst_icfg_arvcidx_device_START (16)
#define SOC_ACTRL_SEC_CTRL3_ib_mspc_mst_icfg_arvcidx_device_END (23)
#define SOC_ACTRL_SEC_CTRL3_ib_mspc_mst_icfg_awvcidx_device_START (24)
#define SOC_ACTRL_SEC_CTRL3_ib_mspc_mst_icfg_awvcidx_device_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_dsp_mst_icfg_arvcidx_ddr : 8;
        unsigned int ib_dsp_mst_icfg_awvcidx_ddr : 8;
        unsigned int ib_dsp_mst_icfg_arvcidx_device : 8;
        unsigned int ib_dsp_mst_icfg_awvcidx_device : 8;
    } reg;
} SOC_ACTRL_SEC_CTRL4_UNION;
#endif
#define SOC_ACTRL_SEC_CTRL4_ib_dsp_mst_icfg_arvcidx_ddr_START (0)
#define SOC_ACTRL_SEC_CTRL4_ib_dsp_mst_icfg_arvcidx_ddr_END (7)
#define SOC_ACTRL_SEC_CTRL4_ib_dsp_mst_icfg_awvcidx_ddr_START (8)
#define SOC_ACTRL_SEC_CTRL4_ib_dsp_mst_icfg_awvcidx_ddr_END (15)
#define SOC_ACTRL_SEC_CTRL4_ib_dsp_mst_icfg_arvcidx_device_START (16)
#define SOC_ACTRL_SEC_CTRL4_ib_dsp_mst_icfg_arvcidx_device_END (23)
#define SOC_ACTRL_SEC_CTRL4_ib_dsp_mst_icfg_awvcidx_device_START (24)
#define SOC_ACTRL_SEC_CTRL4_ib_dsp_mst_icfg_awvcidx_device_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_qspi_tpram_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ACTRL_AO_QSPI_TPSRAM_MEM_CTRL_UNION;
#endif
#define SOC_ACTRL_AO_QSPI_TPSRAM_MEM_CTRL_ao_qspi_tpram_mem_ctrl_START (0)
#define SOC_ACTRL_AO_QSPI_TPSRAM_MEM_CTRL_ao_qspi_tpram_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_global_cfg_npu : 32;
    } reg;
} SOC_ACTRL_QIC_GLOBAL_CFG_NPU_UNION;
#endif
#define SOC_ACTRL_QIC_GLOBAL_CFG_NPU_qic_global_cfg_npu_START (0)
#define SOC_ACTRL_QIC_GLOBAL_CFG_NPU_qic_global_cfg_npu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_global_cfg_media2 : 32;
    } reg;
} SOC_ACTRL_QIC_GLOBAL_CFG_MEIDA2_UNION;
#endif
#define SOC_ACTRL_QIC_GLOBAL_CFG_MEIDA2_qic_global_cfg_media2_START (0)
#define SOC_ACTRL_QIC_GLOBAL_CFG_MEIDA2_qic_global_cfg_media2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_global_cfg_media1 : 32;
    } reg;
} SOC_ACTRL_QIC_GLOBAL_CFG_MEIDA1_UNION;
#endif
#define SOC_ACTRL_QIC_GLOBAL_CFG_MEIDA1_qic_global_cfg_media1_START (0)
#define SOC_ACTRL_QIC_GLOBAL_CFG_MEIDA1_qic_global_cfg_media1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_global_cfg_gpu : 32;
    } reg;
} SOC_ACTRL_QIC_GLOBAL_CFG_GPU_UNION;
#endif
#define SOC_ACTRL_QIC_GLOBAL_CFG_GPU_qic_global_cfg_gpu_START (0)
#define SOC_ACTRL_QIC_GLOBAL_CFG_GPU_qic_global_cfg_gpu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status14 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS14_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS14_actrl_sec_status14_START (0)
#define SOC_ACTRL_SEC_STATUS14_actrl_sec_status14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status15 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS15_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS15_actrl_sec_status15_START (0)
#define SOC_ACTRL_SEC_STATUS15_actrl_sec_status15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_sec_status16 : 32;
    } reg;
} SOC_ACTRL_SEC_STATUS16_UNION;
#endif
#define SOC_ACTRL_SEC_STATUS16_actrl_sec_status16_START (0)
#define SOC_ACTRL_SEC_STATUS16_actrl_sec_status16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_mst : 2;
        unsigned int dlock_slv : 4;
        unsigned int dlock_irq : 1;
        unsigned int hiaxi_idle : 1;
        unsigned int dlock_and_dbg_clr : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_ACTRL_AUDIO_AW_DLOCK_UNION;
#endif
#define SOC_ACTRL_AUDIO_AW_DLOCK_dlock_mst_START (0)
#define SOC_ACTRL_AUDIO_AW_DLOCK_dlock_mst_END (1)
#define SOC_ACTRL_AUDIO_AW_DLOCK_dlock_slv_START (2)
#define SOC_ACTRL_AUDIO_AW_DLOCK_dlock_slv_END (5)
#define SOC_ACTRL_AUDIO_AW_DLOCK_dlock_irq_START (6)
#define SOC_ACTRL_AUDIO_AW_DLOCK_dlock_irq_END (6)
#define SOC_ACTRL_AUDIO_AW_DLOCK_hiaxi_idle_START (7)
#define SOC_ACTRL_AUDIO_AW_DLOCK_hiaxi_idle_END (7)
#define SOC_ACTRL_AUDIO_AW_DLOCK_dlock_and_dbg_clr_START (8)
#define SOC_ACTRL_AUDIO_AW_DLOCK_dlock_and_dbg_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_xctrl_sec_sel : 32;
    } reg;
} SOC_ACTRL_STS_SEL_MUX_UNION;
#endif
#define SOC_ACTRL_STS_SEL_MUX_sts_xctrl_sec_sel_START (0)
#define SOC_ACTRL_STS_SEL_MUX_sts_xctrl_sec_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomux_sel_sts : 32;
    } reg;
} SOC_ACTRL_IOMUX_SEL_STS_UNION;
#endif
#define SOC_ACTRL_IOMUX_SEL_STS_iomux_sel_sts_START (0)
#define SOC_ACTRL_IOMUX_SEL_STS_iomux_sel_sts_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomux_sel_hiphy : 32;
    } reg;
} SOC_ACTRL_IOMUX_SEL_HIPHY_UNION;
#endif
#define SOC_ACTRL_IOMUX_SEL_HIPHY_iomux_sel_hiphy_START (0)
#define SOC_ACTRL_IOMUX_SEL_HIPHY_iomux_sel_hiphy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomux_sel_1to3 : 32;
    } reg;
} SOC_ACTRL_IOMUX_SEL_1TO3_UNION;
#endif
#define SOC_ACTRL_IOMUX_SEL_1TO3_iomux_sel_1to3_START (0)
#define SOC_ACTRL_IOMUX_SEL_1TO3_iomux_sel_1to3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_ack_dbg_en_mspc : 1;
        unsigned int reserved : 15;
        unsigned int qic_dbg_en_s_msk : 16;
    } reg;
} SOC_ACTRL_SEC_CTRL_MSPC_QIC_DBG_UNION;
#endif
#define SOC_ACTRL_SEC_CTRL_MSPC_QIC_DBG_pwrd_ack_dbg_en_mspc_START (0)
#define SOC_ACTRL_SEC_CTRL_MSPC_QIC_DBG_pwrd_ack_dbg_en_mspc_END (0)
#define SOC_ACTRL_SEC_CTRL_MSPC_QIC_DBG_qic_dbg_en_s_msk_START (16)
#define SOC_ACTRL_SEC_CTRL_MSPC_QIC_DBG_qic_dbg_en_s_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_spi0_spi3_sel : 1;
        unsigned int sts_spi03_spi2_sel : 1;
        unsigned int sts_i2c_sel : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ACTRL_IOMUX_SEL_STS1_UNION;
#endif
#define SOC_ACTRL_IOMUX_SEL_STS1_sts_spi0_spi3_sel_START (0)
#define SOC_ACTRL_IOMUX_SEL_STS1_sts_spi0_spi3_sel_END (0)
#define SOC_ACTRL_IOMUX_SEL_STS1_sts_spi03_spi2_sel_START (1)
#define SOC_ACTRL_IOMUX_SEL_STS1_sts_spi03_spi2_sel_END (1)
#define SOC_ACTRL_IOMUX_SEL_STS1_sts_i2c_sel_START (2)
#define SOC_ACTRL_IOMUX_SEL_STS1_sts_i2c_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_spi_cs2_n_in : 16;
        unsigned int bitmsk_sec_ctrl_sts_cs2 : 16;
    } reg;
} SOC_ACTRL_BITMSK_SEC_STS_CS_UNION;
#endif
#define SOC_ACTRL_BITMSK_SEC_STS_CS_sts_spi_cs2_n_in_START (0)
#define SOC_ACTRL_BITMSK_SEC_STS_CS_sts_spi_cs2_n_in_END (15)
#define SOC_ACTRL_BITMSK_SEC_STS_CS_bitmsk_sec_ctrl_sts_cs2_START (16)
#define SOC_ACTRL_BITMSK_SEC_STS_CS_bitmsk_sec_ctrl_sts_cs2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_sel_spi_cs01_n : 16;
        unsigned int bitmsk_sec_sel_sts_cs1 : 16;
    } reg;
} SOC_ACTRL_BITMSK_SEC_STS_SEL_UNION;
#endif
#define SOC_ACTRL_BITMSK_SEC_STS_SEL_sts_sel_spi_cs01_n_START (0)
#define SOC_ACTRL_BITMSK_SEC_STS_SEL_sts_sel_spi_cs01_n_END (15)
#define SOC_ACTRL_BITMSK_SEC_STS_SEL_bitmsk_sec_sel_sts_cs1_START (16)
#define SOC_ACTRL_BITMSK_SEC_STS_SEL_bitmsk_sec_sel_sts_cs1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xctrl_cs_sel : 16;
        unsigned int bitmsk_sec_cs_sel : 16;
    } reg;
} SOC_ACTRL_BITMSK_SEC_STS_XCTRL_SEL_UNION;
#endif
#define SOC_ACTRL_BITMSK_SEC_STS_XCTRL_SEL_xctrl_cs_sel_START (0)
#define SOC_ACTRL_BITMSK_SEC_STS_XCTRL_SEL_xctrl_cs_sel_END (15)
#define SOC_ACTRL_BITMSK_SEC_STS_XCTRL_SEL_bitmsk_sec_cs_sel_START (16)
#define SOC_ACTRL_BITMSK_SEC_STS_XCTRL_SEL_bitmsk_sec_cs_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_clk_sts_hiphyioulppll_aocrg : 1;
        unsigned int gt_clk_sts_inner : 1;
        unsigned int reserved : 14;
        unsigned int bitmsk_sec_sts_ctrl : 16;
    } reg;
} SOC_ACTRL_BITMSK_SEC_STS_CLK_CTRL_UNION;
#endif
#define SOC_ACTRL_BITMSK_SEC_STS_CLK_CTRL_sel_clk_sts_hiphyioulppll_aocrg_START (0)
#define SOC_ACTRL_BITMSK_SEC_STS_CLK_CTRL_sel_clk_sts_hiphyioulppll_aocrg_END (0)
#define SOC_ACTRL_BITMSK_SEC_STS_CLK_CTRL_gt_clk_sts_inner_START (1)
#define SOC_ACTRL_BITMSK_SEC_STS_CLK_CTRL_gt_clk_sts_inner_END (1)
#define SOC_ACTRL_BITMSK_SEC_STS_CLK_CTRL_bitmsk_sec_sts_ctrl_START (16)
#define SOC_ACTRL_BITMSK_SEC_STS_CLK_CTRL_bitmsk_sec_sts_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 2;
        unsigned int iomcu_arc_halt_req_a : 1;
        unsigned int iomcu_arc_run_req_a : 1;
        unsigned int reserved_3 : 10;
        unsigned int bitmsk_sec_ctrl0_msk : 16;
    } reg;
} SOC_ACTRL_BITMSK_SEC_CTRL0_UNION;
#endif
#define SOC_ACTRL_BITMSK_SEC_CTRL0_iomcu_arc_halt_req_a_START (4)
#define SOC_ACTRL_BITMSK_SEC_CTRL0_iomcu_arc_halt_req_a_END (4)
#define SOC_ACTRL_BITMSK_SEC_CTRL0_iomcu_arc_run_req_a_START (5)
#define SOC_ACTRL_BITMSK_SEC_CTRL0_iomcu_arc_run_req_a_END (5)
#define SOC_ACTRL_BITMSK_SEC_CTRL0_bitmsk_sec_ctrl0_msk_START (16)
#define SOC_ACTRL_BITMSK_SEC_CTRL0_bitmsk_sec_ctrl0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_dfa_cpu_init_por : 1;
        unsigned int ao_outer_base_addr : 24;
        unsigned int reserved : 7;
    } reg;
} SOC_ACTRL_HSDT_SEC_CTRL0_UNION;
#endif
#define SOC_ACTRL_HSDT_SEC_CTRL0_ao_dfa_cpu_init_por_START (0)
#define SOC_ACTRL_HSDT_SEC_CTRL0_ao_dfa_cpu_init_por_END (0)
#define SOC_ACTRL_HSDT_SEC_CTRL0_ao_outer_base_addr_START (1)
#define SOC_ACTRL_HSDT_SEC_CTRL0_ao_outer_base_addr_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu2tsp_swi_peri : 1;
        unsigned int lpmcu2tsp_swi_ddr : 1;
        unsigned int lpmcu2lpmcu_swi_peri : 1;
        unsigned int lpmcu2lpmcu_swi_ddr : 1;
        unsigned int reserved : 12;
        unsigned int modem_sec_ctrl0_msk : 16;
    } reg;
} SOC_ACTRL_MODEM_SEC_CTRL0_UNION;
#endif
#define SOC_ACTRL_MODEM_SEC_CTRL0_lpmcu2tsp_swi_peri_START (0)
#define SOC_ACTRL_MODEM_SEC_CTRL0_lpmcu2tsp_swi_peri_END (0)
#define SOC_ACTRL_MODEM_SEC_CTRL0_lpmcu2tsp_swi_ddr_START (1)
#define SOC_ACTRL_MODEM_SEC_CTRL0_lpmcu2tsp_swi_ddr_END (1)
#define SOC_ACTRL_MODEM_SEC_CTRL0_lpmcu2lpmcu_swi_peri_START (2)
#define SOC_ACTRL_MODEM_SEC_CTRL0_lpmcu2lpmcu_swi_peri_END (2)
#define SOC_ACTRL_MODEM_SEC_CTRL0_lpmcu2lpmcu_swi_ddr_START (3)
#define SOC_ACTRL_MODEM_SEC_CTRL0_lpmcu2lpmcu_swi_ddr_END (3)
#define SOC_ACTRL_MODEM_SEC_CTRL0_modem_sec_ctrl0_msk_START (16)
#define SOC_ACTRL_MODEM_SEC_CTRL0_modem_sec_ctrl0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdea_wakeup_irqs_ao_en_0 : 32;
    } reg;
} SOC_ACTRL_PDEA_BIT_MASK0_UNION;
#endif
#define SOC_ACTRL_PDEA_BIT_MASK0_pdea_wakeup_irqs_ao_en_0_START (0)
#define SOC_ACTRL_PDEA_BIT_MASK0_pdea_wakeup_irqs_ao_en_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdea_wakeup_irqs_ao_en_1 : 32;
    } reg;
} SOC_ACTRL_PDEA_BIT_MASK1_UNION;
#endif
#define SOC_ACTRL_PDEA_BIT_MASK1_pdea_wakeup_irqs_ao_en_1_START (0)
#define SOC_ACTRL_PDEA_BIT_MASK1_pdea_wakeup_irqs_ao_en_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tsp_wakeup_irqs_ao_en_0 : 32;
    } reg;
} SOC_ACTRL_TSP_BIT_MASK0_UNION;
#endif
#define SOC_ACTRL_TSP_BIT_MASK0_tsp_wakeup_irqs_ao_en_0_START (0)
#define SOC_ACTRL_TSP_BIT_MASK0_tsp_wakeup_irqs_ao_en_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tsp_wakeup_irqs_ao_en_1 : 32;
    } reg;
} SOC_ACTRL_TSP_BIT_MASK1_UNION;
#endif
#define SOC_ACTRL_TSP_BIT_MASK1_tsp_wakeup_irqs_ao_en_1_START (0)
#define SOC_ACTRL_TSP_BIT_MASK1_tsp_wakeup_irqs_ao_en_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_s_rsv_ctrl0 : 32;
    } reg;
} SOC_ACTRL_MDM_S_RSV_CTRL0_UNION;
#endif
#define SOC_ACTRL_MDM_S_RSV_CTRL0_mdm_s_rsv_ctrl0_START (0)
#define SOC_ACTRL_MDM_S_RSV_CTRL0_mdm_s_rsv_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_s_rsv_ctrl1 : 32;
    } reg;
} SOC_ACTRL_MDM_S_RSV_CTRL1_UNION;
#endif
#define SOC_ACTRL_MDM_S_RSV_CTRL1_mdm_s_rsv_ctrl1_START (0)
#define SOC_ACTRL_MDM_S_RSV_CTRL1_mdm_s_rsv_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ACTRL_MSPCQIC_TIMEOUT_ST_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_autofs_byp0 : 32;
    } reg;
} SOC_ACTRL_MSPC_AUTOFS_BYP0_UNION;
#endif
#define SOC_ACTRL_MSPC_AUTOFS_BYP0_mspc_autofs_byp0_START (0)
#define SOC_ACTRL_MSPC_AUTOFS_BYP0_mspc_autofs_byp0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_mspc_msk_low : 16;
        unsigned int qic_timeout_st_mspc_msk_low_msk : 16;
    } reg;
} SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_LOW_UNION;
#endif
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_LOW_qic_timeout_st_mspc_msk_low_START (0)
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_LOW_qic_timeout_st_mspc_msk_low_END (15)
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_LOW_qic_timeout_st_mspc_msk_low_msk_START (16)
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_LOW_qic_timeout_st_mspc_msk_low_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_mspc_msk_high : 16;
        unsigned int qic_timeout_st_mspc_msk_high_msk : 16;
    } reg;
} SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_HIGH_UNION;
#endif
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_HIGH_qic_timeout_st_mspc_msk_high_START (0)
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_HIGH_qic_timeout_st_mspc_msk_high_END (15)
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_HIGH_qic_timeout_st_mspc_msk_high_msk_START (16)
#define SOC_ACTRL_QIC_TIMEOUT_ST_MSPC_MSK_HIGH_qic_timeout_st_mspc_msk_high_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_iso_en_sec : 16;
        unsigned int iso_en_group_sec_msk : 16;
    } reg;
} SOC_ACTRL_ISO_EN_GROUP_SEC_UNION;
#endif
#define SOC_ACTRL_ISO_EN_GROUP_SEC_actrl_iso_en_sec_START (0)
#define SOC_ACTRL_ISO_EN_GROUP_SEC_actrl_iso_en_sec_END (15)
#define SOC_ACTRL_ISO_EN_GROUP_SEC_iso_en_group_sec_msk_START (16)
#define SOC_ACTRL_ISO_EN_GROUP_SEC_iso_en_group_sec_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mtcmos_en_group_sec : 16;
        unsigned int mtcmos_en_group_sec_msk : 16;
    } reg;
} SOC_ACTRL_MTCMOS_EN_GROUP_SEC_UNION;
#endif
#define SOC_ACTRL_MTCMOS_EN_GROUP_SEC_mtcmos_en_group_sec_START (0)
#define SOC_ACTRL_MTCMOS_EN_GROUP_SEC_mtcmos_en_group_sec_END (15)
#define SOC_ACTRL_MTCMOS_EN_GROUP_SEC_mtcmos_en_group_sec_msk_START (16)
#define SOC_ACTRL_MTCMOS_EN_GROUP_SEC_mtcmos_en_group_sec_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mtcmos_ack_group_sec : 32;
    } reg;
} SOC_ACTRL_MTCMOS_ACK_GROUP_SEC_UNION;
#endif
#define SOC_ACTRL_MTCMOS_ACK_GROUP_SEC_mtcmos_ack_group_sec_START (0)
#define SOC_ACTRL_MTCMOS_ACK_GROUP_SEC_mtcmos_ack_group_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_cer_en : 32;
    } reg;
} SOC_ACTRL_HIEPS_CER_EN_UNION;
#endif
#define SOC_ACTRL_HIEPS_CER_EN_hieps_cer_en_START (0)
#define SOC_ACTRL_HIEPS_CER_EN_hieps_cer_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_resume : 1;
        unsigned int reserved_0 : 3;
        unsigned int hieps_resume_session_key_eps : 1;
        unsigned int reserved_1 : 3;
        unsigned int hieps_resume_session_key_ufs : 1;
        unsigned int reserved_2 : 3;
        unsigned int hieps_resume_counter : 1;
        unsigned int reserved_3 : 3;
        unsigned int hieps_resume_session_key_eps_ree : 1;
        unsigned int reserved_4 : 3;
        unsigned int reserved_5 : 12;
    } reg;
} SOC_ACTRL_HIEPS_CTRL_SEC_UNION;
#endif
#define SOC_ACTRL_HIEPS_CTRL_SEC_hieps_resume_START (0)
#define SOC_ACTRL_HIEPS_CTRL_SEC_hieps_resume_END (0)
#define SOC_ACTRL_HIEPS_CTRL_SEC_hieps_resume_session_key_eps_START (4)
#define SOC_ACTRL_HIEPS_CTRL_SEC_hieps_resume_session_key_eps_END (4)
#define SOC_ACTRL_HIEPS_CTRL_SEC_hieps_resume_session_key_ufs_START (8)
#define SOC_ACTRL_HIEPS_CTRL_SEC_hieps_resume_session_key_ufs_END (8)
#define SOC_ACTRL_HIEPS_CTRL_SEC_hieps_resume_counter_START (12)
#define SOC_ACTRL_HIEPS_CTRL_SEC_hieps_resume_counter_END (12)
#define SOC_ACTRL_HIEPS_CTRL_SEC_hieps_resume_session_key_eps_ree_START (16)
#define SOC_ACTRL_HIEPS_CTRL_SEC_hieps_resume_session_key_eps_ree_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2mspc_ram_sd_vld : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ACTRL_MSPC_RAM_CTRL_UNION;
#endif
#define SOC_ACTRL_MSPC_RAM_CTRL_actrl2mspc_ram_sd_vld_START (0)
#define SOC_ACTRL_MSPC_RAM_CTRL_actrl2mspc_ram_sd_vld_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_state_counter : 32;
    } reg;
} SOC_ACTRL_HIEPS_STATE_COUNTER_UNION;
#endif
#define SOC_ACTRL_HIEPS_STATE_COUNTER_hieps_state_counter_START (0)
#define SOC_ACTRL_HIEPS_STATE_COUNTER_hieps_state_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2eps_reg0 : 32;
    } reg;
} SOC_ACTRL_ACTRL2EPS_REG0_UNION;
#endif
#define SOC_ACTRL_ACTRL2EPS_REG0_actrl2eps_reg0_START (0)
#define SOC_ACTRL_ACTRL2EPS_REG0_actrl2eps_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2eps_reg1 : 32;
    } reg;
} SOC_ACTRL_ACTRL2EPS_REG1_UNION;
#endif
#define SOC_ACTRL_ACTRL2EPS_REG1_actrl2eps_reg1_START (0)
#define SOC_ACTRL_ACTRL2EPS_REG1_actrl2eps_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2eps_reg2 : 32;
    } reg;
} SOC_ACTRL_ACTRL2EPS_REG2_UNION;
#endif
#define SOC_ACTRL_ACTRL2EPS_REG2_actrl2eps_reg2_START (0)
#define SOC_ACTRL_ACTRL2EPS_REG2_actrl2eps_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2eps_reg3 : 32;
    } reg;
} SOC_ACTRL_ACTRL2EPS_REG3_UNION;
#endif
#define SOC_ACTRL_ACTRL2EPS_REG3_actrl2eps_reg3_START (0)
#define SOC_ACTRL_ACTRL2EPS_REG3_actrl2eps_reg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl2eps_reg4 : 32;
    } reg;
} SOC_ACTRL_ACTRL2EPS_REG4_UNION;
#endif
#define SOC_ACTRL_ACTRL2EPS_REG4_actrl2eps_reg4_START (0)
#define SOC_ACTRL_ACTRL2EPS_REG4_actrl2eps_reg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps2actrl_reg0 : 32;
    } reg;
} SOC_ACTRL_EPS2ACTRL_REG0_UNION;
#endif
#define SOC_ACTRL_EPS2ACTRL_REG0_eps2actrl_reg0_START (0)
#define SOC_ACTRL_EPS2ACTRL_REG0_eps2actrl_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps2actrl_reg1 : 32;
    } reg;
} SOC_ACTRL_EPS2ACTRL_REG1_UNION;
#endif
#define SOC_ACTRL_EPS2ACTRL_REG1_eps2actrl_reg1_START (0)
#define SOC_ACTRL_EPS2ACTRL_REG1_eps2actrl_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps2actrl_reg2 : 32;
    } reg;
} SOC_ACTRL_EPS2ACTRL_REG2_UNION;
#endif
#define SOC_ACTRL_EPS2ACTRL_REG2_eps2actrl_reg2_START (0)
#define SOC_ACTRL_EPS2ACTRL_REG2_eps2actrl_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps2actrl_reg3 : 32;
    } reg;
} SOC_ACTRL_EPS2ACTRL_REG3_UNION;
#endif
#define SOC_ACTRL_EPS2ACTRL_REG3_eps2actrl_reg3_START (0)
#define SOC_ACTRL_EPS2ACTRL_REG3_eps2actrl_reg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps2actrl_reg4 : 32;
    } reg;
} SOC_ACTRL_EPS2ACTRL_REG4_UNION;
#endif
#define SOC_ACTRL_EPS2ACTRL_REG4_eps2actrl_reg4_START (0)
#define SOC_ACTRL_EPS2ACTRL_REG4_eps2actrl_reg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ACTRL_HIEPS_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lpmcu_por_rst_pc_lock : 1;
        unsigned int actrl_lpmcu_boot_rom_lock : 1;
        unsigned int actrl_acpu_boot_rom_lock : 1;
        unsigned int actrl_acpu_boot_cfg_lock : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ACTRL_ABSSEC_CTRL0_UNION;
#endif
#define SOC_ACTRL_ABSSEC_CTRL0_actrl_lpmcu_por_rst_pc_lock_START (0)
#define SOC_ACTRL_ABSSEC_CTRL0_actrl_lpmcu_por_rst_pc_lock_END (0)
#define SOC_ACTRL_ABSSEC_CTRL0_actrl_lpmcu_boot_rom_lock_START (1)
#define SOC_ACTRL_ABSSEC_CTRL0_actrl_lpmcu_boot_rom_lock_END (1)
#define SOC_ACTRL_ABSSEC_CTRL0_actrl_acpu_boot_rom_lock_START (2)
#define SOC_ACTRL_ABSSEC_CTRL0_actrl_acpu_boot_rom_lock_END (2)
#define SOC_ACTRL_ABSSEC_CTRL0_actrl_acpu_boot_cfg_lock_START (3)
#define SOC_ACTRL_ABSSEC_CTRL0_actrl_acpu_boot_cfg_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int actrl_lpmcu_por_rst_pc : 32;
    } reg;
} SOC_ACTRL_ABSSEC_CTRL1_UNION;
#endif
#define SOC_ACTRL_ABSSEC_CTRL1_actrl_lpmcu_por_rst_pc_START (0)
#define SOC_ACTRL_ABSSEC_CTRL1_actrl_lpmcu_por_rst_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_session_key_hsdt1_ufs_uncomp_lock_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int hieps_session_key_eps_ree_uncomp_lock_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int hieps_session_key_ufs_uncomp_lock_en : 1;
        unsigned int reserved_2 : 3;
        unsigned int hieps_session_key_eps_uncomp_lock_en : 1;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 16;
    } reg;
} SOC_ACTRL_HIEPS_CTRL_SEC1_UNION;
#endif
#define SOC_ACTRL_HIEPS_CTRL_SEC1_hieps_session_key_hsdt1_ufs_uncomp_lock_en_START (0)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_hieps_session_key_hsdt1_ufs_uncomp_lock_en_END (0)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_hieps_session_key_eps_ree_uncomp_lock_en_START (4)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_hieps_session_key_eps_ree_uncomp_lock_en_END (4)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_hieps_session_key_ufs_uncomp_lock_en_START (8)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_hieps_session_key_ufs_uncomp_lock_en_END (8)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_hieps_session_key_eps_uncomp_lock_en_START (12)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_hieps_session_key_eps_uncomp_lock_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_ufs_compress_mux : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ACTRL_HIEPS_CTRL_SEC1_MUX_UNION;
#endif
#define SOC_ACTRL_HIEPS_CTRL_SEC1_MUX_hieps_ufs_compress_mux_START (0)
#define SOC_ACTRL_HIEPS_CTRL_SEC1_MUX_hieps_ufs_compress_mux_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
