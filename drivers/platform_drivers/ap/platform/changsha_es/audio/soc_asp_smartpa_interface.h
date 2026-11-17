#ifndef __SOC_ASP_SMARTPA_INTERFACE_H__
#define __SOC_ASP_SMARTPA_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ASP_SMARTPA_BYPASS_CFG_ADDR(base) (base)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_ADDR(base) ((base) + 0x004UL)
#define SOC_ASP_SMARTPA_PRE_CFG0_ADDR(base) ((base) + 0x008UL)
#define SOC_ASP_SMARTPA_PRE_CFG1_ADDR(base) ((base) + 0x00CUL)
#define SOC_ASP_SMARTPA_PRE_CFG2_ADDR(base) ((base) + 0x010UL)
#define SOC_ASP_SMARTPA_PRE_CFG3_ADDR(base) ((base) + 0x014UL)
#define SOC_ASP_SMARTPA_PRE_CFG4_ADDR(base) ((base) + 0x018UL)
#define SOC_ASP_SMARTPA_PRE_CFG5_ADDR(base) ((base) + 0x01CUL)
#define SOC_ASP_SMARTPA_PRE_CFG6_ADDR(base) ((base) + 0x020UL)
#define SOC_ASP_SMARTPA_PRE_CFG7_ADDR(base) ((base) + 0x024UL)
#define SOC_ASP_SMARTPA_PRE_CFG8_ADDR(base) ((base) + 0x028UL)
#define SOC_ASP_SMARTPA_PRE_CFG9_ADDR(base) ((base) + 0x02CUL)
#define SOC_ASP_SMARTPA_PRE_CFG10_ADDR(base) ((base) + 0x030UL)
#define SOC_ASP_SMARTPA_PRE_CFG11_ADDR(base) ((base) + 0x034UL)
#define SOC_ASP_SMARTPA_PRE_CFG12_ADDR(base) ((base) + 0x038UL)
#define SOC_ASP_SMARTPA_PRE_CFG13_ADDR(base) ((base) + 0x03CUL)
#define SOC_ASP_SMARTPA_GEQ_CFG0_ADDR(base) ((base) + 0x068UL)
#define SOC_ASP_SMARTPA_GEQ_CFG1_ADDR(base) ((base) + 0x06CUL)
#define SOC_ASP_SMARTPA_GEQ_CFG2_ADDR(base) ((base) + 0x070UL)
#define SOC_ASP_SMARTPA_GEQ_CFG3_ADDR(base) ((base) + 0x074UL)
#define SOC_ASP_SMARTPA_GEQ_CFG4_ADDR(base) ((base) + 0x078UL)
#define SOC_ASP_SMARTPA_GEQ_CFG5_ADDR(base) ((base) + 0x07CUL)
#define SOC_ASP_SMARTPA_GEQ_CFG6_ADDR(base) ((base) + 0x080UL)
#define SOC_ASP_SMARTPA_GEQ_CFG7_ADDR(base) ((base) + 0x084UL)
#define SOC_ASP_SMARTPA_GEQ_CFG8_ADDR(base) ((base) + 0x088UL)
#define SOC_ASP_SMARTPA_GEQ_CFG9_ADDR(base) ((base) + 0x08CUL)
#define SOC_ASP_SMARTPA_GEQ_CFG10_ADDR(base) ((base) + 0x090UL)
#define SOC_ASP_SMARTPA_GEQ_CFG11_ADDR(base) ((base) + 0x094UL)
#define SOC_ASP_SMARTPA_GEQ_CFG12_ADDR(base) ((base) + 0x098UL)
#define SOC_ASP_SMARTPA_GEQ_CFG13_ADDR(base) ((base) + 0x09CUL)
#define SOC_ASP_SMARTPA_GEQ_CFG14_ADDR(base) ((base) + 0x0A0UL)
#define SOC_ASP_SMARTPA_GEQ_CFG15_ADDR(base) ((base) + 0x0A4UL)
#define SOC_ASP_SMARTPA_GEQ_CFG16_ADDR(base) ((base) + 0x0A8UL)
#define SOC_ASP_SMARTPA_GEQ_CFG17_ADDR(base) ((base) + 0x0ACUL)
#define SOC_ASP_SMARTPA_GEQ_CFG18_ADDR(base) ((base) + 0x0B0UL)
#define SOC_ASP_SMARTPA_GEQ_CFG19_ADDR(base) ((base) + 0x0B4UL)
#define SOC_ASP_SMARTPA_GEQ_CFG20_ADDR(base) ((base) + 0x0B8UL)
#define SOC_ASP_SMARTPA_GEQ_CFG21_ADDR(base) ((base) + 0x0BCUL)
#define SOC_ASP_SMARTPA_GEQ_CFG22_ADDR(base) ((base) + 0x0C0UL)
#define SOC_ASP_SMARTPA_GEQ_CFG23_ADDR(base) ((base) + 0x0C4UL)
#define SOC_ASP_SMARTPA_GEQ_CFG24_ADDR(base) ((base) + 0x0C8UL)
#define SOC_ASP_SMARTPA_GEQ_CFG25_ADDR(base) ((base) + 0x0CCUL)
#define SOC_ASP_SMARTPA_GEQ_CFG26_ADDR(base) ((base) + 0x0D0UL)
#define SOC_ASP_SMARTPA_GEQ_CFG27_ADDR(base) ((base) + 0x0D4UL)
#define SOC_ASP_SMARTPA_GEQ_CFG28_ADDR(base) ((base) + 0x0D8UL)
#define SOC_ASP_SMARTPA_GEQ_CFG29_ADDR(base) ((base) + 0x0DCUL)
#define SOC_ASP_SMARTPA_GEQ_CFG30_ADDR(base) ((base) + 0x0E0UL)
#define SOC_ASP_SMARTPA_GEQ_CFG31_ADDR(base) ((base) + 0x0E4UL)
#define SOC_ASP_SMARTPA_GEQ_CFG32_ADDR(base) ((base) + 0x0E8UL)
#define SOC_ASP_SMARTPA_GEQ_CFG33_ADDR(base) ((base) + 0x0ECUL)
#define SOC_ASP_SMARTPA_GEQ_CFG34_ADDR(base) ((base) + 0x0F0UL)
#define SOC_ASP_SMARTPA_GEQ_CFG35_ADDR(base) ((base) + 0x0F4UL)
#define SOC_ASP_SMARTPA_GEQ_CFG36_ADDR(base) ((base) + 0x0F8UL)
#define SOC_ASP_SMARTPA_GEQ_CFG37_ADDR(base) ((base) + 0x0FCUL)
#define SOC_ASP_SMARTPA_GEQ_CFG38_ADDR(base) ((base) + 0x100UL)
#define SOC_ASP_SMARTPA_GEQ_CFG39_ADDR(base) ((base) + 0x104UL)
#define SOC_ASP_SMARTPA_GEQ_CFG40_ADDR(base) ((base) + 0x108UL)
#define SOC_ASP_SMARTPA_GEQ_CFG41_ADDR(base) ((base) + 0x10CUL)
#define SOC_ASP_SMARTPA_GEQ_CFG42_ADDR(base) ((base) + 0x110UL)
#define SOC_ASP_SMARTPA_GEQ_CFG43_ADDR(base) ((base) + 0x114UL)
#define SOC_ASP_SMARTPA_GEQ_CFG44_ADDR(base) ((base) + 0x118UL)
#define SOC_ASP_SMARTPA_GEQ_CFG45_ADDR(base) ((base) + 0x11CUL)
#define SOC_ASP_SMARTPA_GEQ_CFG46_ADDR(base) ((base) + 0x120UL)
#define SOC_ASP_SMARTPA_GEQ_CFG47_ADDR(base) ((base) + 0x124UL)
#define SOC_ASP_SMARTPA_GEQ_CFG48_ADDR(base) ((base) + 0x128UL)
#define SOC_ASP_SMARTPA_GEQ_CFG49_ADDR(base) ((base) + 0x12CUL)
#define SOC_ASP_SMARTPA_GEQ_CFG50_ADDR(base) ((base) + 0x130UL)
#define SOC_ASP_SMARTPA_GEQ_CFG51_ADDR(base) ((base) + 0x134UL)
#define SOC_ASP_SMARTPA_GEQ_CFG52_ADDR(base) ((base) + 0x138UL)
#define SOC_ASP_SMARTPA_GEQ_CFG53_ADDR(base) ((base) + 0x13CUL)
#define SOC_ASP_SMARTPA_GEQ_CFG54_ADDR(base) ((base) + 0x140UL)
#define SOC_ASP_SMARTPA_GEQ_CFG55_ADDR(base) ((base) + 0x144UL)
#define SOC_ASP_SMARTPA_GEQ_CFG56_ADDR(base) ((base) + 0x148UL)
#define SOC_ASP_SMARTPA_GEQ_CFG57_ADDR(base) ((base) + 0x14CUL)
#define SOC_ASP_SMARTPA_GEQ_CFG58_ADDR(base) ((base) + 0x150UL)
#define SOC_ASP_SMARTPA_GEQ_CFG59_ADDR(base) ((base) + 0x154UL)
#define SOC_ASP_SMARTPA_DRC_CFG0_ADDR(base) ((base) + 0x158UL)
#define SOC_ASP_SMARTPA_DRC_CFG1_ADDR(base) ((base) + 0x15CUL)
#define SOC_ASP_SMARTPA_DRC_CFG2_ADDR(base) ((base) + 0x160UL)
#define SOC_ASP_SMARTPA_DRC_CFG3_ADDR(base) ((base) + 0x164UL)
#define SOC_ASP_SMARTPA_DRC_CFG4_ADDR(base) ((base) + 0x168UL)
#define SOC_ASP_SMARTPA_DRC_CFG5_ADDR(base) ((base) + 0x16CUL)
#define SOC_ASP_SMARTPA_DRC_CFG6_ADDR(base) ((base) + 0x170UL)
#define SOC_ASP_SMARTPA_DRC_CFG7_ADDR(base) ((base) + 0x174UL)
#define SOC_ASP_SMARTPA_DRC_CFG8_ADDR(base) ((base) + 0x178UL)
#define SOC_ASP_SMARTPA_DRC_CFG9_ADDR(base) ((base) + 0x17CUL)
#define SOC_ASP_SMARTPA_DRC_CFG10_ADDR(base) ((base) + 0x180UL)
#define SOC_ASP_SMARTPA_DRC_CFG11_ADDR(base) ((base) + 0x184UL)
#define SOC_ASP_SMARTPA_DRC_CFG12_ADDR(base) ((base) + 0x188UL)
#define SOC_ASP_SMARTPA_DRC_CFG13_ADDR(base) ((base) + 0x18CUL)
#define SOC_ASP_SMARTPA_DRC_CFG14_ADDR(base) ((base) + 0x190UL)
#define SOC_ASP_SMARTPA_DRC_CFG15_ADDR(base) ((base) + 0x194UL)
#define SOC_ASP_SMARTPA_DRC_CFG16_ADDR(base) ((base) + 0x198UL)
#define SOC_ASP_SMARTPA_DRC_CFG17_ADDR(base) ((base) + 0x19CUL)
#define SOC_ASP_SMARTPA_DRC_CFG18_ADDR(base) ((base) + 0x1A0UL)
#define SOC_ASP_SMARTPA_DRC_CFG19_ADDR(base) ((base) + 0x1A4UL)
#define SOC_ASP_SMARTPA_DRC_CFG20_ADDR(base) ((base) + 0x1A8UL)
#define SOC_ASP_SMARTPA_DRC_CFG21_ADDR(base) ((base) + 0x1ACUL)
#define SOC_ASP_SMARTPA_DRC_CFG22_ADDR(base) ((base) + 0x1B0UL)
#define SOC_ASP_SMARTPA_DRC_CFG23_ADDR(base) ((base) + 0x1B4UL)
#define SOC_ASP_SMARTPA_DRC_CFG24_ADDR(base) ((base) + 0x1B8UL)
#define SOC_ASP_SMARTPA_DRC_CFG25_ADDR(base) ((base) + 0x1BCUL)
#define SOC_ASP_SMARTPA_DRC_CFG26_ADDR(base) ((base) + 0x1C0UL)
#define SOC_ASP_SMARTPA_DRC_CFG27_ADDR(base) ((base) + 0x1C4UL)
#define SOC_ASP_SMARTPA_DRC_CFG28_ADDR(base) ((base) + 0x1C8UL)
#define SOC_ASP_SMARTPA_DRC_CFG29_ADDR(base) ((base) + 0x1CCUL)
#define SOC_ASP_SMARTPA_DRC_CFG30_ADDR(base) ((base) + 0x1D0UL)
#define SOC_ASP_SMARTPA_DRC_CFG31_ADDR(base) ((base) + 0x1D4UL)
#define SOC_ASP_SMARTPA_DRC_CFG32_ADDR(base) ((base) + 0x1D8UL)
#define SOC_ASP_SMARTPA_DRC_CFG33_ADDR(base) ((base) + 0x1DCUL)
#define SOC_ASP_SMARTPA_DRC_CFG34_ADDR(base) ((base) + 0x1E0UL)
#define SOC_ASP_SMARTPA_DRC_CFG35_ADDR(base) ((base) + 0x1E4UL)
#define SOC_ASP_SMARTPA_DRC_CFG36_ADDR(base) ((base) + 0x1E8UL)
#define SOC_ASP_SMARTPA_DRC_CFG37_ADDR(base) ((base) + 0x1ECUL)
#define SOC_ASP_SMARTPA_DRC_CFG38_ADDR(base) ((base) + 0x1F0UL)
#define SOC_ASP_SMARTPA_DRC_CFG39_ADDR(base) ((base) + 0x1F4UL)
#define SOC_ASP_SMARTPA_DRC_CFG40_ADDR(base) ((base) + 0x1F8UL)
#define SOC_ASP_SMARTPA_DRC_CFG41_ADDR(base) ((base) + 0x1FCUL)
#define SOC_ASP_SMARTPA_DRC_CFG42_ADDR(base) ((base) + 0x200UL)
#define SOC_ASP_SMARTPA_DRC_CFG43_ADDR(base) ((base) + 0x204UL)
#define SOC_ASP_SMARTPA_DRC_CFG44_ADDR(base) ((base) + 0x208UL)
#define SOC_ASP_SMARTPA_DRC_CFG45_ADDR(base) ((base) + 0x20CUL)
#define SOC_ASP_SMARTPA_DRC_CFG46_ADDR(base) ((base) + 0x210UL)
#define SOC_ASP_SMARTPA_DRC_CFG47_ADDR(base) ((base) + 0x214UL)
#define SOC_ASP_SMARTPA_DRC_CFG48_ADDR(base) ((base) + 0x218UL)
#define SOC_ASP_SMARTPA_DRC_CFG49_ADDR(base) ((base) + 0x21CUL)
#define SOC_ASP_SMARTPA_DRC_CFG50_ADDR(base) ((base) + 0x220UL)
#define SOC_ASP_SMARTPA_DRC_CFG51_ADDR(base) ((base) + 0x224UL)
#define SOC_ASP_SMARTPA_DRC_CFG52_ADDR(base) ((base) + 0x228UL)
#define SOC_ASP_SMARTPA_DRC_CFG53_ADDR(base) ((base) + 0x22CUL)
#define SOC_ASP_SMARTPA_DRC_CFG54_ADDR(base) ((base) + 0x230UL)
#define SOC_ASP_SMARTPA_DRC_CFG55_ADDR(base) ((base) + 0x234UL)
#define SOC_ASP_SMARTPA_DRC_CFG56_ADDR(base) ((base) + 0x238UL)
#define SOC_ASP_SMARTPA_DRC_CFG57_ADDR(base) ((base) + 0x23CUL)
#define SOC_ASP_SMARTPA_DRC_CFG58_ADDR(base) ((base) + 0x240UL)
#define SOC_ASP_SMARTPA_DRC_CFG59_ADDR(base) ((base) + 0x244UL)
#define SOC_ASP_SMARTPA_DRC_CFG60_ADDR(base) ((base) + 0x248UL)
#define SOC_ASP_SMARTPA_DRC_CFG61_ADDR(base) ((base) + 0x24CUL)
#define SOC_ASP_SMARTPA_DRC_CFG62_ADDR(base) ((base) + 0x250UL)
#define SOC_ASP_SMARTPA_DRC_CFG63_ADDR(base) ((base) + 0x254UL)
#define SOC_ASP_SMARTPA_SSD_CFG0_ADDR(base) ((base) + 0x258UL)
#define SOC_ASP_SMARTPA_IDF_CFG0_ADDR(base) ((base) + 0x25CUL)
#define SOC_ASP_SMARTPA_IDF_CFG1_ADDR(base) ((base) + 0x260UL)
#define SOC_ASP_SMARTPA_IDF_CFG2_ADDR(base) ((base) + 0x264UL)
#define SOC_ASP_SMARTPA_IDF_CFG3_ADDR(base) ((base) + 0x268UL)
#define SOC_ASP_SMARTPA_IDF_CFG4_ADDR(base) ((base) + 0x26CUL)
#define SOC_ASP_SMARTPA_POW_CFG0_ADDR(base) ((base) + 0x270UL)
#define SOC_ASP_SMARTPA_POW_CFG2_ADDR(base) ((base) + 0x278UL)
#define SOC_ASP_SMARTPA_POW_CFG3_ADDR(base) ((base) + 0x27CUL)
#define SOC_ASP_SMARTPA_POW_CFG4_ADDR(base) ((base) + 0x280UL)
#define SOC_ASP_SMARTPA_POW_CFG5_ADDR(base) ((base) + 0x284UL)
#define SOC_ASP_SMARTPA_POW_CFG6_ADDR(base) ((base) + 0x288UL)
#define SOC_ASP_SMARTPA_POW_CFG7_ADDR(base) ((base) + 0x28CUL)
#define SOC_ASP_SMARTPA_POW_CFG8_ADDR(base) ((base) + 0x290UL)
#define SOC_ASP_SMARTPA_POW_CFG9_ADDR(base) ((base) + 0x294UL)
#define SOC_ASP_SMARTPA_POW_CFG10_ADDR(base) ((base) + 0x298UL)
#define SOC_ASP_SMARTPA_POW_CFG11_ADDR(base) ((base) + 0x29CUL)
#define SOC_ASP_SMARTPA_POW_CFG12_ADDR(base) ((base) + 0x2A0UL)
#define SOC_ASP_SMARTPA_TEP_CFG0_ADDR(base) ((base) + 0x2A4UL)
#define SOC_ASP_SMARTPA_TEP_CFG1_ADDR(base) ((base) + 0x2A8UL)
#define SOC_ASP_SMARTPA_TEP_CFG2_ADDR(base) ((base) + 0x2ACUL)
#define SOC_ASP_SMARTPA_TEP_CFG3_ADDR(base) ((base) + 0x2B0UL)
#define SOC_ASP_SMARTPA_TEP_CFG4_ADDR(base) ((base) + 0x2B4UL)
#define SOC_ASP_SMARTPA_TEP_CFG5_ADDR(base) ((base) + 0x2B8UL)
#define SOC_ASP_SMARTPA_TEP_CFG6_ADDR(base) ((base) + 0x2BCUL)
#define SOC_ASP_SMARTPA_TEP_CFG7_ADDR(base) ((base) + 0x2C0UL)
#define SOC_ASP_SMARTPA_TEP_CFG8_ADDR(base) ((base) + 0x2C4UL)
#define SOC_ASP_SMARTPA_TEP_CFG9_ADDR(base) ((base) + 0x2C8UL)
#define SOC_ASP_SMARTPA_TEP_CFG10_ADDR(base) ((base) + 0x2CCUL)
#define SOC_ASP_SMARTPA_TEP_CFG11_ADDR(base) ((base) + 0x2D0UL)
#define SOC_ASP_SMARTPA_TEP_CFG12_ADDR(base) ((base) + 0x2D4UL)
#define SOC_ASP_SMARTPA_TEP_CFG13_ADDR(base) ((base) + 0x2D8UL)
#define SOC_ASP_SMARTPA_TEP_CFG14_ADDR(base) ((base) + 0x2DCUL)
#define SOC_ASP_SMARTPA_AND_CFG0_ADDR(base) ((base) + 0x2E0UL)
#define SOC_ASP_SMARTPA_AND_CFG1_ADDR(base) ((base) + 0x2E4UL)
#define SOC_ASP_SMARTPA_AND_CFG2_ADDR(base) ((base) + 0x2E8UL)
#define SOC_ASP_SMARTPA_AND_CFG3_ADDR(base) ((base) + 0x2ECUL)
#define SOC_ASP_SMARTPA_AND_CFG4_ADDR(base) ((base) + 0x2F0UL)
#define SOC_ASP_SMARTPA_AND_CFG5_ADDR(base) ((base) + 0x2F4UL)
#define SOC_ASP_SMARTPA_AND_CFG6_ADDR(base) ((base) + 0x2F8UL)
#define SOC_ASP_SMARTPA_RGC_CFG0_ADDR(base) ((base) + 0x2FCUL)
#define SOC_ASP_SMARTPA_RGC_CFG1_ADDR(base) ((base) + 0x300UL)
#define SOC_ASP_SMARTPA_RGC_CFG2_ADDR(base) ((base) + 0x304UL)
#define SOC_ASP_SMARTPA_RGC_CFG3_ADDR(base) ((base) + 0x308UL)
#define SOC_ASP_SMARTPA_RGC_CFG4_ADDR(base) ((base) + 0x30CUL)
#define SOC_ASP_SMARTPA_RGC_CFG5_ADDR(base) ((base) + 0x310UL)
#define SOC_ASP_SMARTPA_RGC_CFG6_ADDR(base) ((base) + 0x314UL)
#define SOC_ASP_SMARTPA_RGC_CFG7_ADDR(base) ((base) + 0x318UL)
#define SOC_ASP_SMARTPA_RGC_CFG9_ADDR(base) ((base) + 0x320UL)
#define SOC_ASP_SMARTPA_RGC_CFG10_ADDR(base) ((base) + 0x324UL)
#define SOC_ASP_SMARTPA_RGC_CFG13_ADDR(base) ((base) + 0x330UL)
#define SOC_ASP_SMARTPA_RGC_CFG14_ADDR(base) ((base) + 0x334UL)
#define SOC_ASP_SMARTPA_RGC_CFG15_ADDR(base) ((base) + 0x338UL)
#define SOC_ASP_SMARTPA_RGC_CFG17_ADDR(base) ((base) + 0x340UL)
#define SOC_ASP_SMARTPA_RGC_CFG18_ADDR(base) ((base) + 0x344UL)
#define SOC_ASP_SMARTPA_RGC_CFG19_ADDR(base) ((base) + 0x348UL)
#define SOC_ASP_SMARTPA_RGC_CFG20_ADDR(base) ((base) + 0x34CUL)
#define SOC_ASP_SMARTPA_RGC_CFG21_ADDR(base) ((base) + 0x350UL)
#define SOC_ASP_SMARTPA_RGC_CFG22_ADDR(base) ((base) + 0x354UL)
#define SOC_ASP_SMARTPA_BGC_CFG0_ADDR(base) ((base) + 0x358UL)
#define SOC_ASP_SMARTPA_BGC_CFG1_ADDR(base) ((base) + 0x35CUL)
#define SOC_ASP_SMARTPA_BGC_CFG2_ADDR(base) ((base) + 0x360UL)
#define SOC_ASP_SMARTPA_BGC_CFG3_ADDR(base) ((base) + 0x364UL)
#define SOC_ASP_SMARTPA_BGC_CFG4_ADDR(base) ((base) + 0x368UL)
#define SOC_ASP_SMARTPA_BGC_CFG5_ADDR(base) ((base) + 0x36CUL)
#define SOC_ASP_SMARTPA_BGC_CFG6_ADDR(base) ((base) + 0x370UL)
#define SOC_ASP_SMARTPA_BGC_CFG7_ADDR(base) ((base) + 0x374UL)
#define SOC_ASP_SMARTPA_BGC_CFG8_ADDR(base) ((base) + 0x378UL)
#define SOC_ASP_SMARTPA_BGC_CFG9_ADDR(base) ((base) + 0x37CUL)
#define SOC_ASP_SMARTPA_BGC_CFG10_ADDR(base) ((base) + 0x380UL)
#define SOC_ASP_SMARTPA_BGC_CFG11_ADDR(base) ((base) + 0x384UL)
#define SOC_ASP_SMARTPA_BGC_CFG12_ADDR(base) ((base) + 0x388UL)
#define SOC_ASP_SMARTPA_BGC_CFG13_ADDR(base) ((base) + 0x38CUL)
#define SOC_ASP_SMARTPA_BGC_CFG14_ADDR(base) ((base) + 0x390UL)
#define SOC_ASP_SMARTPA_BGC_CFG15_ADDR(base) ((base) + 0x394UL)
#define SOC_ASP_SMARTPA_BGC_CFG16_ADDR(base) ((base) + 0x398UL)
#define SOC_ASP_SMARTPA_BGC_CFG17_ADDR(base) ((base) + 0x39CUL)
#define SOC_ASP_SMARTPA_BGC_CFG18_ADDR(base) ((base) + 0x3A0UL)
#define SOC_ASP_SMARTPA_BGC_CFG19_ADDR(base) ((base) + 0x3A4UL)
#define SOC_ASP_SMARTPA_BGC_CFG20_ADDR(base) ((base) + 0x3A8UL)
#define SOC_ASP_SMARTPA_BGC_CFG21_ADDR(base) ((base) + 0x3ACUL)
#define SOC_ASP_SMARTPA_BGC_CFG22_ADDR(base) ((base) + 0x3B0UL)
#define SOC_ASP_SMARTPA_BGC_CFG23_ADDR(base) ((base) + 0x3B4UL)
#define SOC_ASP_SMARTPA_BGC_CFG24_ADDR(base) ((base) + 0x3B8UL)
#define SOC_ASP_SMARTPA_BGC_CFG25_ADDR(base) ((base) + 0x3BCUL)
#define SOC_ASP_SMARTPA_BGC_CFG26_ADDR(base) ((base) + 0x3C0UL)
#define SOC_ASP_SMARTPA_BGC_CFG27_ADDR(base) ((base) + 0x3C4UL)
#define SOC_ASP_SMARTPA_SDC_CFG0_ADDR(base) ((base) + 0x3C8UL)
#define SOC_ASP_SMARTPA_SDC_CFG1_ADDR(base) ((base) + 0x3CCUL)
#define SOC_ASP_SMARTPA_SDC_CFG2_ADDR(base) ((base) + 0x3D0UL)
#define SOC_ASP_SMARTPA_SDC_CFG3_ADDR(base) ((base) + 0x3D4UL)
#define SOC_ASP_SMARTPA_SDC_CFG4_ADDR(base) ((base) + 0x3D8UL)
#define SOC_ASP_SMARTPA_SDC_CFG5_ADDR(base) ((base) + 0x3DCUL)
#define SOC_ASP_SMARTPA_SDC_CFG6_ADDR(base) ((base) + 0x3E0UL)
#define SOC_ASP_SMARTPA_SDC_CFG7_ADDR(base) ((base) + 0x3E4UL)
#define SOC_ASP_SMARTPA_SDC_CFG8_ADDR(base) ((base) + 0x3E8UL)
#define SOC_ASP_SMARTPA_SDC_CFG9_ADDR(base) ((base) + 0x3ECUL)
#define SOC_ASP_SMARTPA_SDC_CFG10_ADDR(base) ((base) + 0x3F0UL)
#define SOC_ASP_SMARTPA_SDC_CFG11_ADDR(base) ((base) + 0x3F4UL)
#define SOC_ASP_SMARTPA_SDC_CFG12_ADDR(base) ((base) + 0x3F8UL)
#define SOC_ASP_SMARTPA_SDC_CFG13_ADDR(base) ((base) + 0x3FCUL)
#define SOC_ASP_SMARTPA_SDC_CFG14_ADDR(base) ((base) + 0x400UL)
#define SOC_ASP_SMARTPA_SDC_CFG15_ADDR(base) ((base) + 0x404UL)
#define SOC_ASP_SMARTPA_SDC_CFG16_ADDR(base) ((base) + 0x408UL)
#define SOC_ASP_SMARTPA_SDC_CFG17_ADDR(base) ((base) + 0x40CUL)
#define SOC_ASP_SMARTPA_SDC_CFG18_ADDR(base) ((base) + 0x410UL)
#define SOC_ASP_SMARTPA_SDC_CFG19_ADDR(base) ((base) + 0x414UL)
#define SOC_ASP_SMARTPA_SDC_CFG20_ADDR(base) ((base) + 0x418UL)
#define SOC_ASP_SMARTPA_SDC_CFG21_ADDR(base) ((base) + 0x41CUL)
#define SOC_ASP_SMARTPA_SDC_CFG22_ADDR(base) ((base) + 0x420UL)
#define SOC_ASP_SMARTPA_SDC_CFG23_ADDR(base) ((base) + 0x424UL)
#define SOC_ASP_SMARTPA_SDC_CFG24_ADDR(base) ((base) + 0x428UL)
#define SOC_ASP_SMARTPA_SDC_CFG25_ADDR(base) ((base) + 0x42CUL)
#define SOC_ASP_SMARTPA_SDC_CFG26_ADDR(base) ((base) + 0x430UL)
#define SOC_ASP_SMARTPA_SDC_CFG27_ADDR(base) ((base) + 0x434UL)
#define SOC_ASP_SMARTPA_SDC_CFG28_ADDR(base) ((base) + 0x438UL)
#define SOC_ASP_SMARTPA_SDC_CFG29_ADDR(base) ((base) + 0x43CUL)
#define SOC_ASP_SMARTPA_NDC_CFG0_ADDR(base) ((base) + 0x440UL)
#define SOC_ASP_SMARTPA_NDC_CFG1_ADDR(base) ((base) + 0x444UL)
#define SOC_ASP_SMARTPA_NDC_CFG2_ADDR(base) ((base) + 0x448UL)
#define SOC_ASP_SMARTPA_NDC_CFG3_ADDR(base) ((base) + 0x44CUL)
#define SOC_ASP_SMARTPA_NDC_CFG4_ADDR(base) ((base) + 0x450UL)
#define SOC_ASP_SMARTPA_NDC_CFG5_ADDR(base) ((base) + 0x454UL)
#define SOC_ASP_SMARTPA_NDC_CFG6_ADDR(base) ((base) + 0x458UL)
#define SOC_ASP_SMARTPA_NDC_CFG7_ADDR(base) ((base) + 0x45CUL)
#define SOC_ASP_SMARTPA_NDC_CFG8_ADDR(base) ((base) + 0x460UL)
#define SOC_ASP_SMARTPA_NDC_CFG9_ADDR(base) ((base) + 0x464UL)
#define SOC_ASP_SMARTPA_NDC_CFG10_ADDR(base) ((base) + 0x468UL)
#define SOC_ASP_SMARTPA_NDC_CFG11_ADDR(base) ((base) + 0x46CUL)
#define SOC_ASP_SMARTPA_NDC_CFG12_ADDR(base) ((base) + 0x470UL)
#define SOC_ASP_SMARTPA_NDC_CFG13_ADDR(base) ((base) + 0x474UL)
#define SOC_ASP_SMARTPA_NDC_CFG14_ADDR(base) ((base) + 0x478UL)
#define SOC_ASP_SMARTPA_NDC_CFG15_ADDR(base) ((base) + 0x47CUL)
#define SOC_ASP_SMARTPA_NDC_CFG16_ADDR(base) ((base) + 0x480UL)
#define SOC_ASP_SMARTPA_NDC_CFG17_ADDR(base) ((base) + 0x484UL)
#define SOC_ASP_SMARTPA_NDC_CFG18_ADDR(base) ((base) + 0x488UL)
#define SOC_ASP_SMARTPA_NDC_CFG19_ADDR(base) ((base) + 0x48CUL)
#define SOC_ASP_SMARTPA_NDC_CFG20_ADDR(base) ((base) + 0x490UL)
#define SOC_ASP_SMARTPA_NDC_CFG21_ADDR(base) ((base) + 0x494UL)
#define SOC_ASP_SMARTPA_NDC_CFG22_ADDR(base) ((base) + 0x498UL)
#define SOC_ASP_SMARTPA_NDC_CFG23_ADDR(base) ((base) + 0x49CUL)
#define SOC_ASP_SMARTPA_NDC_CFG24_ADDR(base) ((base) + 0x4A0UL)
#define SOC_ASP_SMARTPA_NDC_CFG25_ADDR(base) ((base) + 0x4A4UL)
#define SOC_ASP_SMARTPA_NDC_CFG26_ADDR(base) ((base) + 0x4A8UL)
#define SOC_ASP_SMARTPA_NDC_CFG27_ADDR(base) ((base) + 0x4ACUL)
#define SOC_ASP_SMARTPA_NDC_CFG28_ADDR(base) ((base) + 0x4B0UL)
#define SOC_ASP_SMARTPA_NDC_CFG29_ADDR(base) ((base) + 0x4B4UL)
#define SOC_ASP_SMARTPA_NDC_CFG30_ADDR(base) ((base) + 0x4B8UL)
#define SOC_ASP_SMARTPA_NDC_CFG31_ADDR(base) ((base) + 0x4BCUL)
#define SOC_ASP_SMARTPA_NDC_CFG32_ADDR(base) ((base) + 0x4C0UL)
#define SOC_ASP_SMARTPA_NDC_CFG33_ADDR(base) ((base) + 0x4C4UL)
#define SOC_ASP_SMARTPA_NDC_CFG34_ADDR(base) ((base) + 0x4C8UL)
#define SOC_ASP_SMARTPA_LMT_CFG0_ADDR(base) ((base) + 0x4CCUL)
#define SOC_ASP_SMARTPA_PLT_CFG0_ADDR(base) ((base) + 0x4D0UL)
#define SOC_ASP_SMARTPA_PLT_CFG1_ADDR(base) ((base) + 0x4D4UL)
#define SOC_ASP_SMARTPA_PLT_CFG2_ADDR(base) ((base) + 0x4D8UL)
#define SOC_ASP_SMARTPA_IDF_CFG5_ADDR(base) ((base) + 0x4DCUL)
#define SOC_ASP_SMARTPA_IDF_CFG6_ADDR(base) ((base) + 0x4E0UL)
#define SOC_ASP_SMARTPA_IDF_CFG7_ADDR(base) ((base) + 0x4E4UL)
#define SOC_ASP_SMARTPA_IDF_CFG8_ADDR(base) ((base) + 0x4E8UL)
#define SOC_ASP_SMARTPA_IDF_CFG10_ADDR(base) ((base) + 0x4F0UL)
#define SOC_ASP_SMARTPA_IDF_CFG11_ADDR(base) ((base) + 0x4F4UL)
#define SOC_ASP_SMARTPA_IDF_CFG12_ADDR(base) ((base) + 0x4F8UL)
#define SOC_ASP_SMARTPA_IDF_CFG13_ADDR(base) ((base) + 0x4FCUL)
#define SOC_ASP_SMARTPA_LSM_CFG0_ADDR(base) ((base) + 0x504UL)
#define SOC_ASP_SMARTPA_LSM_CFG1_ADDR(base) ((base) + 0x508UL)
#define SOC_ASP_SMARTPA_LSM_CFG2_ADDR(base) ((base) + 0x50CUL)
#define SOC_ASP_SMARTPA_LSM_CFG3_ADDR(base) ((base) + 0x510UL)
#define SOC_ASP_SMARTPA_LSM_CFG4_ADDR(base) ((base) + 0x514UL)
#define SOC_ASP_SMARTPA_LSM_CFG6_ADDR(base) ((base) + 0x51CUL)
#define SOC_ASP_SMARTPA_LSM_CFG7_ADDR(base) ((base) + 0x520UL)
#define SOC_ASP_SMARTPA_LSM_CFG8_ADDR(base) ((base) + 0x524UL)
#define SOC_ASP_SMARTPA_LSM_CFG9_ADDR(base) ((base) + 0x528UL)
#define SOC_ASP_SMARTPA_LSM_CFG10_ADDR(base) ((base) + 0x52CUL)
#define SOC_ASP_SMARTPA_LSM_CFG12_ADDR(base) ((base) + 0x534UL)
#define SOC_ASP_SMARTPA_LSM_CFG13_ADDR(base) ((base) + 0x538UL)
#define SOC_ASP_SMARTPA_LSM_CFG14_ADDR(base) ((base) + 0x53CUL)
#define SOC_ASP_SMARTPA_LSM_CFG15_ADDR(base) ((base) + 0x540UL)
#define SOC_ASP_SMARTPA_LSM_CFG16_ADDR(base) ((base) + 0x544UL)
#define SOC_ASP_SMARTPA_LSM_CFG17_ADDR(base) ((base) + 0x548UL)
#define SOC_ASP_SMARTPA_LSM_CFG18_ADDR(base) ((base) + 0x54CUL)
#define SOC_ASP_SMARTPA_LSM_CFG19_ADDR(base) ((base) + 0x550UL)
#define SOC_ASP_SMARTPA_LSM_CFG20_ADDR(base) ((base) + 0x554UL)
#define SOC_ASP_SMARTPA_LSM_CFG21_ADDR(base) ((base) + 0x558UL)
#define SOC_ASP_SMARTPA_LSM_CFG22_ADDR(base) ((base) + 0x55CUL)
#define SOC_ASP_SMARTPA_LSM_CFG24_ADDR(base) ((base) + 0x564UL)
#define SOC_ASP_SMARTPA_LSM_CFG25_ADDR(base) ((base) + 0x568UL)
#define SOC_ASP_SMARTPA_LSM_CFG26_ADDR(base) ((base) + 0x56CUL)
#define SOC_ASP_SMARTPA_LSM_CFG28_ADDR(base) ((base) + 0x57CUL)
#define SOC_ASP_SMARTPA_ECP_CFG0_ADDR(base) ((base) + 0x590UL)
#define SOC_ASP_SMARTPA_ECP_CFG1_ADDR(base) ((base) + 0x594UL)
#define SOC_ASP_SMARTPA_ECP_CFG2_ADDR(base) ((base) + 0x598UL)
#define SOC_ASP_SMARTPA_ECP_CFG3_ADDR(base) ((base) + 0x59CUL)
#define SOC_ASP_SMARTPA_ECP_CFG4_ADDR(base) ((base) + 0x5A0UL)
#define SOC_ASP_SMARTPA_ECP_CFG5_ADDR(base) ((base) + 0x5A4UL)
#define SOC_ASP_SMARTPA_ECP_CFG6_ADDR(base) ((base) + 0x5A8UL)
#define SOC_ASP_SMARTPA_ECP_CFG7_ADDR(base) ((base) + 0x5ACUL)
#define SOC_ASP_SMARTPA_ECP_CFG8_ADDR(base) ((base) + 0x5B0UL)
#define SOC_ASP_SMARTPA_ECP_CFG9_ADDR(base) ((base) + 0x5B4UL)
#define SOC_ASP_SMARTPA_ECP_CFG10_ADDR(base) ((base) + 0x5B8UL)
#define SOC_ASP_SMARTPA_ECP_CFG11_ADDR(base) ((base) + 0x5BCUL)
#define SOC_ASP_SMARTPA_ECP_CFG12_ADDR(base) ((base) + 0x5C0UL)
#define SOC_ASP_SMARTPA_ECP_CFG13_ADDR(base) ((base) + 0x5C4UL)
#define SOC_ASP_SMARTPA_ECP_CFG14_ADDR(base) ((base) + 0x5C8UL)
#define SOC_ASP_SMARTPA_ECP_CFG15_ADDR(base) ((base) + 0x5CCUL)
#define SOC_ASP_SMARTPA_ECP_CFG16_ADDR(base) ((base) + 0x5D0UL)
#define SOC_ASP_SMARTPA_ECP_CFG17_ADDR(base) ((base) + 0x5D4UL)
#define SOC_ASP_SMARTPA_ECP_CFG18_ADDR(base) ((base) + 0x5D8UL)
#define SOC_ASP_SMARTPA_ECP_CFG19_ADDR(base) ((base) + 0x5DCUL)
#define SOC_ASP_SMARTPA_ECP_CFG20_ADDR(base) ((base) + 0x5E0UL)
#define SOC_ASP_SMARTPA_ECP_CFG21_ADDR(base) ((base) + 0x5E4UL)
#define SOC_ASP_SMARTPA_ECP_CFG22_ADDR(base) ((base) + 0x5E8UL)
#define SOC_ASP_SMARTPA_ECP_CFG23_ADDR(base) ((base) + 0x5ECUL)
#define SOC_ASP_SMARTPA_ECP_CFG24_ADDR(base) ((base) + 0x5F0UL)
#define SOC_ASP_SMARTPA_ECP_CFG25_ADDR(base) ((base) + 0x5F4UL)
#define SOC_ASP_SMARTPA_ECP_CFG26_ADDR(base) ((base) + 0x5F8UL)
#define SOC_ASP_SMARTPA_ECP_CFG27_ADDR(base) ((base) + 0x5FCUL)
#define SOC_ASP_SMARTPA_ECP_CFG28_ADDR(base) ((base) + 0x600UL)
#define SOC_ASP_SMARTPA_ECP_CFG29_ADDR(base) ((base) + 0x604UL)
#define SOC_ASP_SMARTPA_ECP_CFG30_ADDR(base) ((base) + 0x608UL)
#define SOC_ASP_SMARTPA_ECP_CFG31_ADDR(base) ((base) + 0x60CUL)
#define SOC_ASP_SMARTPA_ECP_CFG32_ADDR(base) ((base) + 0x610UL)
#define SOC_ASP_SMARTPA_ECP_CFG33_ADDR(base) ((base) + 0x614UL)
#define SOC_ASP_SMARTPA_ECP_CFG34_ADDR(base) ((base) + 0x618UL)
#define SOC_ASP_SMARTPA_ECP_CFG35_ADDR(base) ((base) + 0x61CUL)
#define SOC_ASP_SMARTPA_ECP_CFG36_ADDR(base) ((base) + 0x620UL)
#define SOC_ASP_SMARTPA_ECP_CFG37_ADDR(base) ((base) + 0x624UL)
#define SOC_ASP_SMARTPA_ECP_CFG38_ADDR(base) ((base) + 0x628UL)
#define SOC_ASP_SMARTPA_ECP_CFG39_ADDR(base) ((base) + 0x62CUL)
#define SOC_ASP_SMARTPA_ECP_CFG40_ADDR(base) ((base) + 0x630UL)
#define SOC_ASP_SMARTPA_ECP_CFG41_ADDR(base) ((base) + 0x634UL)
#define SOC_ASP_SMARTPA_ECP_CFG42_ADDR(base) ((base) + 0x638UL)
#define SOC_ASP_SMARTPA_ECP_CFG43_ADDR(base) ((base) + 0x63CUL)
#define SOC_ASP_SMARTPA_ECP_CFG44_ADDR(base) ((base) + 0x640UL)
#define SOC_ASP_SMARTPA_ECP_CFG45_ADDR(base) ((base) + 0x644UL)
#define SOC_ASP_SMARTPA_ECP_CFG46_ADDR(base) ((base) + 0x648UL)
#define SOC_ASP_SMARTPA_ECP_CFG47_ADDR(base) ((base) + 0x64CUL)
#define SOC_ASP_SMARTPA_ECP_CFG48_ADDR(base) ((base) + 0x650UL)
#define SOC_ASP_SMARTPA_ECP_CFG49_ADDR(base) ((base) + 0x654UL)
#define SOC_ASP_SMARTPA_ECP_CFG50_ADDR(base) ((base) + 0x658UL)
#define SOC_ASP_SMARTPA_ECP_CFG51_ADDR(base) ((base) + 0x65CUL)
#define SOC_ASP_SMARTPA_ECP_CFG52_ADDR(base) ((base) + 0x660UL)
#define SOC_ASP_SMARTPA_ECP_CFG53_ADDR(base) ((base) + 0x664UL)
#define SOC_ASP_SMARTPA_ECP_CFG54_ADDR(base) ((base) + 0x668UL)
#define SOC_ASP_SMARTPA_ECP_CFG55_ADDR(base) ((base) + 0x66CUL)
#define SOC_ASP_SMARTPA_ECP_CFG56_ADDR(base) ((base) + 0x670UL)
#define SOC_ASP_SMARTPA_ECP_CFG57_ADDR(base) ((base) + 0x674UL)
#define SOC_ASP_SMARTPA_ECP_CFG58_ADDR(base) ((base) + 0x678UL)
#define SOC_ASP_SMARTPA_ECP_CFG59_ADDR(base) ((base) + 0x67CUL)
#define SOC_ASP_SMARTPA_ECP_CFG60_ADDR(base) ((base) + 0x680UL)
#define SOC_ASP_SMARTPA_ECP_CFG61_ADDR(base) ((base) + 0x684UL)
#define SOC_ASP_SMARTPA_ECP_CFG62_ADDR(base) ((base) + 0x688UL)
#define SOC_ASP_SMARTPA_ECP_CFG63_ADDR(base) ((base) + 0x68CUL)
#define SOC_ASP_SMARTPA_ECP_CFG64_ADDR(base) ((base) + 0x690UL)
#define SOC_ASP_SMARTPA_ECP_CFG65_ADDR(base) ((base) + 0x694UL)
#define SOC_ASP_SMARTPA_ECP_CFG66_ADDR(base) ((base) + 0x698UL)
#define SOC_ASP_SMARTPA_ECP_CFG67_ADDR(base) ((base) + 0x69CUL)
#define SOC_ASP_SMARTPA_ECP_CFG68_ADDR(base) ((base) + 0x6A0UL)
#define SOC_ASP_SMARTPA_ECP_CFG69_ADDR(base) ((base) + 0x6A4UL)
#define SOC_ASP_SMARTPA_ECP_CFG70_ADDR(base) ((base) + 0x6A8UL)
#define SOC_ASP_SMARTPA_ECP_CFG71_ADDR(base) ((base) + 0x6ACUL)
#define SOC_ASP_SMARTPA_ECP_CFG72_ADDR(base) ((base) + 0x6B0UL)
#define SOC_ASP_SMARTPA_ECP_CFG73_ADDR(base) ((base) + 0x6B4UL)
#define SOC_ASP_SMARTPA_ECP_CFG74_ADDR(base) ((base) + 0x6B8UL)
#define SOC_ASP_SMARTPA_ECP_CFG75_ADDR(base) ((base) + 0x6BCUL)
#define SOC_ASP_SMARTPA_ECP_CFG76_ADDR(base) ((base) + 0x6C0UL)
#define SOC_ASP_SMARTPA_ECP_CFG77_ADDR(base) ((base) + 0x6C4UL)
#define SOC_ASP_SMARTPA_ECP_CFG78_ADDR(base) ((base) + 0x6C8UL)
#define SOC_ASP_SMARTPA_ECP_CFG79_ADDR(base) ((base) + 0x6CCUL)
#define SOC_ASP_SMARTPA_ECP_CFG80_ADDR(base) ((base) + 0x6D0UL)
#define SOC_ASP_SMARTPA_ECP_CFG81_ADDR(base) ((base) + 0x6D4UL)
#define SOC_ASP_SMARTPA_ECP_CFG82_ADDR(base) ((base) + 0x6D8UL)
#define SOC_ASP_SMARTPA_ECP_CFG83_ADDR(base) ((base) + 0x6DCUL)
#define SOC_ASP_SMARTPA_ECP_CFG84_ADDR(base) ((base) + 0x6E0UL)
#define SOC_ASP_SMARTPA_ECP_CFG85_ADDR(base) ((base) + 0x6E4UL)
#define SOC_ASP_SMARTPA_ECP_CFG86_ADDR(base) ((base) + 0x6E8UL)
#define SOC_ASP_SMARTPA_IDF_CFG14_ADDR(base) ((base) + 0x6ECUL)
#define SOC_ASP_SMARTPA_IDF_CFG16_ADDR(base) ((base) + 0x6F4UL)
#define SOC_ASP_SMARTPA_IDF_CFG17_ADDR(base) ((base) + 0x6F8UL)
#define SOC_ASP_SMARTPA_IDF_CFG18_ADDR(base) ((base) + 0x6FCUL)
#define SOC_ASP_SMARTPA_BGC_CFG28_ADDR(base) ((base) + 0x700UL)
#define SOC_ASP_SMARTPA_PLT_CFG3_ADDR(base) ((base) + 0x704UL)
#define SOC_ASP_SMARTPA_PLT_CFG4_ADDR(base) ((base) + 0x708UL)
#define SOC_ASP_SMARTPA_PLT_CFG5_ADDR(base) ((base) + 0x710UL)
#define SOC_ASP_SMARTPA_PLT_CFG6_ADDR(base) ((base) + 0x714UL)
#define SOC_ASP_SMARTPA_IDF_CFG19_ADDR(base) ((base) + 0x70CUL)
#define SOC_ASP_SMARTPA_CROSSFADE_STEP_CFG_ADDR(base) ((base) + 0x780UL)
#define SOC_ASP_SMARTPA_LSM_RO_STATE0_ADDR(base) ((base) + 0x7A4UL)
#define SOC_ASP_SMARTPA_IDF_RO_STATE0_ADDR(base) ((base) + 0x7A8UL)
#define SOC_ASP_SMARTPA_IDF_RO_STATE1_ADDR(base) ((base) + 0x7ACUL)
#define SOC_ASP_SMARTPA_IDF_RO_STATE2_ADDR(base) ((base) + 0x7B0UL)
#define SOC_ASP_SMARTPA_POW_RO_STATE0_ADDR(base) ((base) + 0x7B4UL)
#define SOC_ASP_SMARTPA_POW_RO_STATE1_ADDR(base) ((base) + 0x7B8UL)
#define SOC_ASP_SMARTPA_POW_RO_STATE2_ADDR(base) ((base) + 0x7BCUL)
#define SOC_ASP_SMARTPA_AND_RO_STATE0_ADDR(base) ((base) + 0x7C0UL)
#define SOC_ASP_SMARTPA_RGC_RO_STATE0_ADDR(base) ((base) + 0x7C4UL)
#define SOC_ASP_SMARTPA_RGC_RO_STATE1_ADDR(base) ((base) + 0x7C8UL)
#define SOC_ASP_SMARTPA_RGC_RO_STATE2_ADDR(base) ((base) + 0x7CCUL)
#define SOC_ASP_SMARTPA_IDF_RO_STATE4_ADDR(base) ((base) + 0x7D0UL)
#define SOC_ASP_SMARTPA_POW_RO_STATE3_ADDR(base) ((base) + 0x7D4UL)
#define SOC_ASP_SMARTPA_TEP_RO_STATE0_ADDR(base) ((base) + 0x7D8UL)
#define SOC_ASP_SMARTPA_AND_RO_STATE1_ADDR(base) ((base) + 0x7DCUL)
#define SOC_ASP_SMARTPA_RGC_RO_STATE3_ADDR(base) ((base) + 0x7E0UL)
#define SOC_ASP_SMARTPA_BGC_RO_STATE0_ADDR(base) ((base) + 0x7E4UL)
#define SOC_ASP_SMARTPA_BGC_RO_STATE1_ADDR(base) ((base) + 0x7E8UL)
#define SOC_ASP_SMARTPA_LSM_RO_STATE1_ADDR(base) ((base) + 0x7ECUL)
#define SOC_ASP_SMARTPA_LSM_RO_STATE2_ADDR(base) ((base) + 0x7F0UL)
#define SOC_ASP_SMARTPA_LSM_RO_STATE3_ADDR(base) ((base) + 0x7F4UL)
#define SOC_ASP_SMARTPA_LSM_RO_STATE4_ADDR(base) ((base) + 0x7F8UL)
#define SOC_ASP_SMARTPA_NDC_RO_STATE0_ADDR(base) ((base) + 0x7FCUL)
#define SOC_ASP_SMARTPA_SSD_CFG2_ADDR(base) ((base) + 0x800UL)
#define SOC_ASP_SMARTPA_LMT_CFG1_ADDR(base) ((base) + 0x804UL)
#define SOC_ASP_SMARTPA_LMT_CFG2_ADDR(base) ((base) + 0x808UL)
#define SOC_ASP_SMARTPA_LMT_CFG3_ADDR(base) ((base) + 0x80CUL)
#define SOC_ASP_SMARTPA_LMT_CFG4_ADDR(base) ((base) + 0x810UL)
#define SOC_ASP_SMARTPA_LTM_CFG0_ADDR(base) ((base) + 0x814UL)
#define SOC_ASP_SMARTPA_LTM_CFG1_ADDR(base) ((base) + 0x818UL)
#define SOC_ASP_SMARTPA_LTM_CFG2_ADDR(base) ((base) + 0x81CUL)
#define SOC_ASP_SMARTPA_LTM_CFG3_ADDR(base) ((base) + 0x820UL)
#define SOC_ASP_SMARTPA_LTM_CFG4_ADDR(base) ((base) + 0x824UL)
#define SOC_ASP_SMARTPA_LTM_CFG5_ADDR(base) ((base) + 0x828UL)
#define SOC_ASP_SMARTPA_LTM_CFG6_ADDR(base) ((base) + 0x82CUL)
#define SOC_ASP_SMARTPA_LTM_CFG7_ADDR(base) ((base) + 0x830UL)
#define SOC_ASP_SMARTPA_LTM_CFG8_ADDR(base) ((base) + 0x834UL)
#define SOC_ASP_SMARTPA_LTM_CFG9_ADDR(base) ((base) + 0x838UL)
#define SOC_ASP_SMARTPA_LTM_CFG10_ADDR(base) ((base) + 0x83CUL)
#define SOC_ASP_SMARTPA_LTM_CFG11_ADDR(base) ((base) + 0x840UL)
#define SOC_ASP_SMARTPA_LTM_CFG12_ADDR(base) ((base) + 0x844UL)
#define SOC_ASP_SMARTPA_LTM_CFG13_ADDR(base) ((base) + 0x848UL)
#define SOC_ASP_SMARTPA_LTM_CFG14_ADDR(base) ((base) + 0x84CUL)
#define SOC_ASP_SMARTPA_LTM_CFG15_ADDR(base) ((base) + 0x850UL)
#define SOC_ASP_SMARTPA_LTM_CFG16_ADDR(base) ((base) + 0x854UL)
#define SOC_ASP_SMARTPA_LTM_CFG17_ADDR(base) ((base) + 0x858UL)
#define SOC_ASP_SMARTPA_LTM_CFG18_ADDR(base) ((base) + 0x85CUL)
#define SOC_ASP_SMARTPA_LTM_CFG19_ADDR(base) ((base) + 0x860UL)
#define SOC_ASP_SMARTPA_LTM_CFG20_ADDR(base) ((base) + 0x864UL)
#define SOC_ASP_SMARTPA_LTM_CFG21_ADDR(base) ((base) + 0x868UL)
#define SOC_ASP_SMARTPA_LTM_CFG22_ADDR(base) ((base) + 0x86CUL)
#define SOC_ASP_SMARTPA_LTM_CFG23_ADDR(base) ((base) + 0x870UL)
#define SOC_ASP_SMARTPA_LTM_CFG24_ADDR(base) ((base) + 0x874UL)
#define SOC_ASP_SMARTPA_LTM_CFG25_ADDR(base) ((base) + 0x878UL)
#define SOC_ASP_SMARTPA_LTM_CFG26_ADDR(base) ((base) + 0x87CUL)
#define SOC_ASP_SMARTPA_LTM_CFG27_ADDR(base) ((base) + 0x880UL)
#define SOC_ASP_SMARTPA_LTM_CFG28_ADDR(base) ((base) + 0x884UL)
#define SOC_ASP_SMARTPA_LTM_CFG29_ADDR(base) ((base) + 0x888UL)
#define SOC_ASP_SMARTPA_LTM_CFG30_ADDR(base) ((base) + 0x88CUL)
#define SOC_ASP_SMARTPA_LTM_CFG31_ADDR(base) ((base) + 0x890UL)
#define SOC_ASP_SMARTPA_LTM_CFG32_ADDR(base) ((base) + 0x894UL)
#define SOC_ASP_SMARTPA_LTM_CFG33_ADDR(base) ((base) + 0x898UL)
#define SOC_ASP_SMARTPA_LTM_CFG34_ADDR(base) ((base) + 0x89CUL)
#define SOC_ASP_SMARTPA_LTM_CFG35_ADDR(base) ((base) + 0x8A0UL)
#define SOC_ASP_SMARTPA_LTM_CFG36_ADDR(base) ((base) + 0x8A4UL)
#define SOC_ASP_SMARTPA_LTM_CFG37_ADDR(base) ((base) + 0x8A8UL)
#define SOC_ASP_SMARTPA_LTM_CFG38_ADDR(base) ((base) + 0x8ACUL)
#define SOC_ASP_SMARTPA_LTM_CFG39_ADDR(base) ((base) + 0x8B0UL)
#define SOC_ASP_SMARTPA_LTM_CFG40_ADDR(base) ((base) + 0x8B4UL)
#define SOC_ASP_SMARTPA_LTM_CFG41_ADDR(base) ((base) + 0x8B8UL)
#define SOC_ASP_SMARTPA_LTM_CFG42_ADDR(base) ((base) + 0x8BCUL)
#define SOC_ASP_SMARTPA_LTM_CFG43_ADDR(base) ((base) + 0x8C0UL)
#define SOC_ASP_SMARTPA_LTM_CFG44_ADDR(base) ((base) + 0x8C4UL)
#define SOC_ASP_SMARTPA_LTM_CFG45_ADDR(base) ((base) + 0x8C8UL)
#define SOC_ASP_SMARTPA_LTM_CFG46_ADDR(base) ((base) + 0x8CCUL)
#define SOC_ASP_SMARTPA_LTM_CFG47_ADDR(base) ((base) + 0x8D0UL)
#define SOC_ASP_SMARTPA_LTM_CFG48_ADDR(base) ((base) + 0x8D4UL)
#define SOC_ASP_SMARTPA_LTM_CFG49_ADDR(base) ((base) + 0x8D8UL)
#define SOC_ASP_SMARTPA_LTM_CFG50_ADDR(base) ((base) + 0x8DCUL)
#define SOC_ASP_SMARTPA_LTM_CFG51_ADDR(base) ((base) + 0x8E0UL)
#define SOC_ASP_SMARTPA_LTM_CFG52_ADDR(base) ((base) + 0x8E4UL)
#define SOC_ASP_SMARTPA_LTM_CFG53_ADDR(base) ((base) + 0x8E8UL)
#define SOC_ASP_SMARTPA_LTM_CFG54_ADDR(base) ((base) + 0x8ECUL)
#define SOC_ASP_SMARTPA_LTM_CFG55_ADDR(base) ((base) + 0x8F0UL)
#define SOC_ASP_SMARTPA_LTM_CFG56_ADDR(base) ((base) + 0x8F4UL)
#define SOC_ASP_SMARTPA_LTM_CFG57_ADDR(base) ((base) + 0x8F8UL)
#define SOC_ASP_SMARTPA_LTM_CFG58_ADDR(base) ((base) + 0x8FCUL)
#define SOC_ASP_SMARTPA_LTM_CFG59_ADDR(base) ((base) + 0x900UL)
#define SOC_ASP_SMARTPA_LTM_CFG60_ADDR(base) ((base) + 0x904UL)
#define SOC_ASP_SMARTPA_LTM_CFG61_ADDR(base) ((base) + 0x908UL)
#define SOC_ASP_SMARTPA_LTM_CFG62_ADDR(base) ((base) + 0x90CUL)
#define SOC_ASP_SMARTPA_LTM_CFG63_ADDR(base) ((base) + 0x910UL)
#define SOC_ASP_SMARTPA_LTM_CFG64_ADDR(base) ((base) + 0x914UL)
#define SOC_ASP_SMARTPA_LTM_CFG65_ADDR(base) ((base) + 0x918UL)
#define SOC_ASP_SMARTPA_LTM_CFG66_ADDR(base) ((base) + 0x91CUL)
#define SOC_ASP_SMARTPA_LTM_CFG67_ADDR(base) ((base) + 0x920UL)
#define SOC_ASP_SMARTPA_LTM_CFG68_ADDR(base) ((base) + 0x924UL)
#define SOC_ASP_SMARTPA_LTM_CFG69_ADDR(base) ((base) + 0x928UL)
#define SOC_ASP_SMARTPA_LTM_CFG70_ADDR(base) ((base) + 0x92CUL)
#define SOC_ASP_SMARTPA_LTM_CFG71_ADDR(base) ((base) + 0x930UL)
#define SOC_ASP_SMARTPA_LTM_CFG72_ADDR(base) ((base) + 0x934UL)
#define SOC_ASP_SMARTPA_LTM_CFG73_ADDR(base) ((base) + 0x938UL)
#define SOC_ASP_SMARTPA_LTM_CFG74_ADDR(base) ((base) + 0x93CUL)
#define SOC_ASP_SMARTPA_LTM_CFG75_ADDR(base) ((base) + 0x940UL)
#define SOC_ASP_SMARTPA_LTM_CFG76_ADDR(base) ((base) + 0x944UL)
#define SOC_ASP_SMARTPA_LTM_CFG77_ADDR(base) ((base) + 0x948UL)
#define SOC_ASP_SMARTPA_LTM_CFG78_ADDR(base) ((base) + 0x94CUL)
#define SOC_ASP_SMARTPA_LTM_CFG79_ADDR(base) ((base) + 0x950UL)
#define SOC_ASP_SMARTPA_LTM_CFG80_ADDR(base) ((base) + 0x954UL)
#define SOC_ASP_SMARTPA_LTM_CFG81_ADDR(base) ((base) + 0x958UL)
#define SOC_ASP_SMARTPA_LTM_CFG82_ADDR(base) ((base) + 0x95CUL)
#define SOC_ASP_SMARTPA_LTM_CFG83_ADDR(base) ((base) + 0x960UL)
#define SOC_ASP_SMARTPA_LTM_CFG84_ADDR(base) ((base) + 0x964UL)
#define SOC_ASP_SMARTPA_LTM_CFG85_ADDR(base) ((base) + 0x968UL)
#define SOC_ASP_SMARTPA_LTM_CFG86_ADDR(base) ((base) + 0x96CUL)
#define SOC_ASP_SMARTPA_LTM_CFG87_ADDR(base) ((base) + 0x970UL)
#define SOC_ASP_SMARTPA_LTM_CFG88_ADDR(base) ((base) + 0x974UL)
#define SOC_ASP_SMARTPA_LTM_CFG89_ADDR(base) ((base) + 0x978UL)
#define SOC_ASP_SMARTPA_LTM_CFG90_ADDR(base) ((base) + 0x97CUL)
#define SOC_ASP_SMARTPA_LTM_CFG91_ADDR(base) ((base) + 0x980UL)
#define SOC_ASP_SMARTPA_LTM_CFG92_ADDR(base) ((base) + 0x984UL)
#define SOC_ASP_SMARTPA_LTM_CFG93_ADDR(base) ((base) + 0x988UL)
#define SOC_ASP_SMARTPA_LTM_CFG94_ADDR(base) ((base) + 0x98CUL)
#define SOC_ASP_SMARTPA_LTM_CFG95_ADDR(base) ((base) + 0x990UL)
#define SOC_ASP_SMARTPA_LTM_CFG96_ADDR(base) ((base) + 0x994UL)
#define SOC_ASP_SMARTPA_LTM_CFG97_ADDR(base) ((base) + 0x998UL)
#define SOC_ASP_SMARTPA_LTM_CFG98_ADDR(base) ((base) + 0x99CUL)
#define SOC_ASP_SMARTPA_LTM_CFG99_ADDR(base) ((base) + 0x9A0UL)
#define SOC_ASP_SMARTPA_LTM_CFG100_ADDR(base) ((base) + 0x9A4UL)
#define SOC_ASP_SMARTPA_LTM_CFG101_ADDR(base) ((base) + 0x9A8UL)
#define SOC_ASP_SMARTPA_LTM_CFG102_ADDR(base) ((base) + 0x9ACUL)
#define SOC_ASP_SMARTPA_LTM_CFG103_ADDR(base) ((base) + 0x9B0UL)
#define SOC_ASP_SMARTPA_LTM_CFG104_ADDR(base) ((base) + 0x9B4UL)
#define SOC_ASP_SMARTPA_LTM_CFG105_ADDR(base) ((base) + 0x9B8UL)
#define SOC_ASP_SMARTPA_LTM_CFG106_ADDR(base) ((base) + 0x9BCUL)
#define SOC_ASP_SMARTPA_LTM_CFG107_ADDR(base) ((base) + 0x9C0UL)
#define SOC_ASP_SMARTPA_LTM_CFG108_ADDR(base) ((base) + 0x9C4UL)
#define SOC_ASP_SMARTPA_LTM_CFG109_ADDR(base) ((base) + 0x9C8UL)
#define SOC_ASP_SMARTPA_LTM_CFG110_ADDR(base) ((base) + 0x9CCUL)
#define SOC_ASP_SMARTPA_LTM_CFG111_ADDR(base) ((base) + 0x9D0UL)
#define SOC_ASP_SMARTPA_LTM_CFG112_ADDR(base) ((base) + 0x9D4UL)
#define SOC_ASP_SMARTPA_LTM_CFG113_ADDR(base) ((base) + 0x9D8UL)
#define SOC_ASP_SMARTPA_LTM_CFG114_ADDR(base) ((base) + 0x9DCUL)
#define SOC_ASP_SMARTPA_LTM_CFG115_ADDR(base) ((base) + 0x9E0UL)
#define SOC_ASP_SMARTPA_LTM_CFG116_ADDR(base) ((base) + 0x9E4UL)
#define SOC_ASP_SMARTPA_LTM_CFG117_ADDR(base) ((base) + 0x9E8UL)
#define SOC_ASP_SMARTPA_LTM_CFG118_ADDR(base) ((base) + 0x9ECUL)
#define SOC_ASP_SMARTPA_LTM_CFG119_ADDR(base) ((base) + 0x9F0UL)
#define SOC_ASP_SMARTPA_LTM_CFG120_ADDR(base) ((base) + 0x9F4UL)
#define SOC_ASP_SMARTPA_LTM_CFG121_ADDR(base) ((base) + 0x9F8UL)
#define SOC_ASP_SMARTPA_LTM_CFG122_ADDR(base) ((base) + 0x9FCUL)
#define SOC_ASP_SMARTPA_BCN_CFG0_ADDR(base) ((base) + 0xA00UL)
#define SOC_ASP_SMARTPA_BCN_CFG1_ADDR(base) ((base) + 0xA04UL)
#define SOC_ASP_SMARTPA_BCN_CFG2_ADDR(base) ((base) + 0xA08UL)
#define SOC_ASP_SMARTPA_BCN_CFG3_ADDR(base) ((base) + 0xA0CUL)
#define SOC_ASP_SMARTPA_BCN_CFG4_ADDR(base) ((base) + 0xA10UL)
#define SOC_ASP_SMARTPA_BCN_CFG5_ADDR(base) ((base) + 0xA14UL)
#define SOC_ASP_SMARTPA_BCN_CFG6_ADDR(base) ((base) + 0xA18UL)
#define SOC_ASP_SMARTPA_BCN_CFG7_ADDR(base) ((base) + 0xA1CUL)
#define SOC_ASP_SMARTPA_BCN_CFG8_ADDR(base) ((base) + 0xA20UL)
#define SOC_ASP_SMARTPA_BCN_CFG9_ADDR(base) ((base) + 0xA24UL)
#define SOC_ASP_SMARTPA_BCN_CFG10_ADDR(base) ((base) + 0xA28UL)
#define SOC_ASP_SMARTPA_BCN_CFG11_ADDR(base) ((base) + 0xA2CUL)
#define SOC_ASP_SMARTPA_BCN_CFG12_ADDR(base) ((base) + 0xA30UL)
#define SOC_ASP_SMARTPA_BCN_CFG13_ADDR(base) ((base) + 0xA34UL)
#define SOC_ASP_SMARTPA_BCN_CFG14_ADDR(base) ((base) + 0xA38UL)
#define SOC_ASP_SMARTPA_BCN_CFG15_ADDR(base) ((base) + 0xA3CUL)
#define SOC_ASP_SMARTPA_BCN_CFG16_ADDR(base) ((base) + 0xA40UL)
#define SOC_ASP_SMARTPA_BCN_CFG17_ADDR(base) ((base) + 0xA44UL)
#define SOC_ASP_SMARTPA_BCN_CFG18_ADDR(base) ((base) + 0xA48UL)
#define SOC_ASP_SMARTPA_BCN_CFG19_ADDR(base) ((base) + 0xA4CUL)
#define SOC_ASP_SMARTPA_BCN_CFG20_ADDR(base) ((base) + 0xA50UL)
#define SOC_ASP_SMARTPA_BCN_CFG21_ADDR(base) ((base) + 0xA54UL)
#define SOC_ASP_SMARTPA_BCN_CFG22_ADDR(base) ((base) + 0xA58UL)
#define SOC_ASP_SMARTPA_BCN_CFG23_ADDR(base) ((base) + 0xA5CUL)
#define SOC_ASP_SMARTPA_BCN_CFG24_ADDR(base) ((base) + 0xA60UL)
#define SOC_ASP_SMARTPA_BCN_CFG25_ADDR(base) ((base) + 0xA64UL)
#define SOC_ASP_SMARTPA_BCN_CFG26_ADDR(base) ((base) + 0xA68UL)
#define SOC_ASP_SMARTPA_BCN_CFG27_ADDR(base) ((base) + 0xA6CUL)
#define SOC_ASP_SMARTPA_BCN_CFG28_ADDR(base) ((base) + 0xA70UL)
#define SOC_ASP_SMARTPA_BCN_CFG29_ADDR(base) ((base) + 0xA74UL)
#define SOC_ASP_SMARTPA_BCN_CFG30_ADDR(base) ((base) + 0xA78UL)
#define SOC_ASP_SMARTPA_BCN_CFG31_ADDR(base) ((base) + 0xA7CUL)
#define SOC_ASP_SMARTPA_BCN_CFG32_ADDR(base) ((base) + 0xA80UL)
#define SOC_ASP_SMARTPA_BCN_CFG33_ADDR(base) ((base) + 0xA84UL)
#define SOC_ASP_SMARTPA_BCN_CFG34_ADDR(base) ((base) + 0xA88UL)
#define SOC_ASP_SMARTPA_BCN_CFG35_ADDR(base) ((base) + 0xA8CUL)
#define SOC_ASP_SMARTPA_BCN_CFG36_ADDR(base) ((base) + 0xA90UL)
#define SOC_ASP_SMARTPA_BCN_CFG37_ADDR(base) ((base) + 0xA94UL)
#define SOC_ASP_SMARTPA_BCN_CFG38_ADDR(base) ((base) + 0xA98UL)
#define SOC_ASP_SMARTPA_BCN_CFG39_ADDR(base) ((base) + 0xA9CUL)
#define SOC_ASP_SMARTPA_BCN_CFG40_ADDR(base) ((base) + 0xAA0UL)
#define SOC_ASP_SMARTPA_BCN_CFG41_ADDR(base) ((base) + 0xAA4UL)
#define SOC_ASP_SMARTPA_BCN_CFG42_ADDR(base) ((base) + 0xAA8UL)
#define SOC_ASP_SMARTPA_BCN_CFG43_ADDR(base) ((base) + 0xAACUL)
#define SOC_ASP_SMARTPA_BCN_CFG44_ADDR(base) ((base) + 0xAB0UL)
#define SOC_ASP_SMARTPA_BCN_CFG45_ADDR(base) ((base) + 0xAB4UL)
#define SOC_ASP_SMARTPA_BCN_CFG46_ADDR(base) ((base) + 0xAB8UL)
#define SOC_ASP_SMARTPA_BCN_CFG47_ADDR(base) ((base) + 0xABCUL)
#define SOC_ASP_SMARTPA_BCN_CFG48_ADDR(base) ((base) + 0xAC0UL)
#define SOC_ASP_SMARTPA_BCN_CFG49_ADDR(base) ((base) + 0xAC4UL)
#define SOC_ASP_SMARTPA_BCN_CFG50_ADDR(base) ((base) + 0xAC8UL)
#define SOC_ASP_SMARTPA_BCN_CFG51_ADDR(base) ((base) + 0xACCUL)
#define SOC_ASP_SMARTPA_BCN_CFG52_ADDR(base) ((base) + 0xAD0UL)
#define SOC_ASP_SMARTPA_BCN_CFG53_ADDR(base) ((base) + 0xAD4UL)
#define SOC_ASP_SMARTPA_BCN_CFG54_ADDR(base) ((base) + 0xAD8UL)
#define SOC_ASP_SMARTPA_BCN_CFG55_ADDR(base) ((base) + 0xADCUL)
#define SOC_ASP_SMARTPA_BCN_CFG56_ADDR(base) ((base) + 0xAE0UL)
#define SOC_ASP_SMARTPA_BCN_CFG57_ADDR(base) ((base) + 0xAE4UL)
#define SOC_ASP_SMARTPA_BCN_CFG58_ADDR(base) ((base) + 0xAE8UL)
#define SOC_ASP_SMARTPA_BCN_CFG59_ADDR(base) ((base) + 0xAECUL)
#define SOC_ASP_SMARTPA_BCN_CFG60_ADDR(base) ((base) + 0xAF0UL)
#define SOC_ASP_SMARTPA_BCN_CFG61_ADDR(base) ((base) + 0xAF4UL)
#define SOC_ASP_SMARTPA_BCN_CFG62_ADDR(base) ((base) + 0xAF8UL)
#define SOC_ASP_SMARTPA_BCN_CFG63_ADDR(base) ((base) + 0xAFCUL)
#define SOC_ASP_SMARTPA_BCN_CFG64_ADDR(base) ((base) + 0xB00UL)
#define SOC_ASP_SMARTPA_BCN_CFG65_ADDR(base) ((base) + 0xB04UL)
#define SOC_ASP_SMARTPA_BCN_CFG66_ADDR(base) ((base) + 0xB08UL)
#define SOC_ASP_SMARTPA_BCN_CFG67_ADDR(base) ((base) + 0xB0CUL)
#define SOC_ASP_SMARTPA_BCN_CFG68_ADDR(base) ((base) + 0xB10UL)
#define SOC_ASP_SMARTPA_BCN_CFG69_ADDR(base) ((base) + 0xB14UL)
#define SOC_ASP_SMARTPA_BCN_CFG70_ADDR(base) ((base) + 0xB18UL)
#define SOC_ASP_SMARTPA_BCN_CFG71_ADDR(base) ((base) + 0xB1CUL)
#define SOC_ASP_SMARTPA_BCN_CFG72_ADDR(base) ((base) + 0xB20UL)
#define SOC_ASP_SMARTPA_BCN_CFG73_ADDR(base) ((base) + 0xB24UL)
#define SOC_ASP_SMARTPA_BCN_CFG74_ADDR(base) ((base) + 0xB28UL)
#define SOC_ASP_SMARTPA_BCN_CFG75_ADDR(base) ((base) + 0xB2CUL)
#define SOC_ASP_SMARTPA_BCN_CFG76_ADDR(base) ((base) + 0xB30UL)
#define SOC_ASP_SMARTPA_BCN_CFG77_ADDR(base) ((base) + 0xB34UL)
#define SOC_ASP_SMARTPA_BCN_CFG78_ADDR(base) ((base) + 0xB38UL)
#define SOC_ASP_SMARTPA_BCN_CFG79_ADDR(base) ((base) + 0xB3CUL)
#define SOC_ASP_SMARTPA_BCN_CFG80_ADDR(base) ((base) + 0xB40UL)
#define SOC_ASP_SMARTPA_BCN_CFG81_ADDR(base) ((base) + 0xB44UL)
#define SOC_ASP_SMARTPA_BCN_CFG82_ADDR(base) ((base) + 0xB48UL)
#define SOC_ASP_SMARTPA_BCN_CFG83_ADDR(base) ((base) + 0xB4CUL)
#define SOC_ASP_SMARTPA_BCN_CFG84_ADDR(base) ((base) + 0xB50UL)
#define SOC_ASP_SMARTPA_BCN_CFG85_ADDR(base) ((base) + 0xB54UL)
#define SOC_ASP_SMARTPA_BCN_CFG86_ADDR(base) ((base) + 0xB58UL)
#define SOC_ASP_SMARTPA_BCN_CFG87_ADDR(base) ((base) + 0xB5CUL)
#define SOC_ASP_SMARTPA_BCN_CFG88_ADDR(base) ((base) + 0xB60UL)
#define SOC_ASP_SMARTPA_BCN_CFG89_ADDR(base) ((base) + 0xB64UL)
#define SOC_ASP_SMARTPA_BCN_CFG90_ADDR(base) ((base) + 0xB68UL)
#define SOC_ASP_SMARTPA_BCN_CFG91_ADDR(base) ((base) + 0xB6CUL)
#define SOC_ASP_SMARTPA_BCN_CFG92_ADDR(base) ((base) + 0xB70UL)
#define SOC_ASP_SMARTPA_BCN_CFG93_ADDR(base) ((base) + 0xB74UL)
#define SOC_ASP_SMARTPA_BCN_CFG94_ADDR(base) ((base) + 0xB78UL)
#define SOC_ASP_SMARTPA_BCN_CFG95_ADDR(base) ((base) + 0xB7CUL)
#define SOC_ASP_SMARTPA_BCN_CFG96_ADDR(base) ((base) + 0xB80UL)
#define SOC_ASP_SMARTPA_BCN_CFG97_ADDR(base) ((base) + 0xB84UL)
#define SOC_ASP_SMARTPA_BCN_CFG98_ADDR(base) ((base) + 0xB88UL)
#define SOC_ASP_SMARTPA_BCN_CFG99_ADDR(base) ((base) + 0xB8CUL)
#define SOC_ASP_SMARTPA_BCN_CFG100_ADDR(base) ((base) + 0xB90UL)
#define SOC_ASP_SMARTPA_BCN_CFG101_ADDR(base) ((base) + 0xB94UL)
#define SOC_ASP_SMARTPA_BCN_CFG102_ADDR(base) ((base) + 0xB98UL)
#define SOC_ASP_SMARTPA_BCN_CFG103_ADDR(base) ((base) + 0xB9CUL)
#define SOC_ASP_SMARTPA_BCN_CFG104_ADDR(base) ((base) + 0xBA0UL)
#define SOC_ASP_SMARTPA_BCN_CFG105_ADDR(base) ((base) + 0xBA4UL)
#define SOC_ASP_SMARTPA_BCN_CFG106_ADDR(base) ((base) + 0xBA8UL)
#define SOC_ASP_SMARTPA_BCN_CFG107_ADDR(base) ((base) + 0xBACUL)
#define SOC_ASP_SMARTPA_BCN_CFG108_ADDR(base) ((base) + 0xBB0UL)
#define SOC_ASP_SMARTPA_BCN_CFG109_ADDR(base) ((base) + 0xBB4UL)
#define SOC_ASP_SMARTPA_BCN_CFG110_ADDR(base) ((base) + 0xBB8UL)
#define SOC_ASP_SMARTPA_BCN_CFG111_ADDR(base) ((base) + 0xBBCUL)
#define SOC_ASP_SMARTPA_BCN_CFG112_ADDR(base) ((base) + 0xBC0UL)
#define SOC_ASP_SMARTPA_BCN_CFG113_ADDR(base) ((base) + 0xBC4UL)
#define SOC_ASP_SMARTPA_BCN_CFG114_ADDR(base) ((base) + 0xBC8UL)
#define SOC_ASP_SMARTPA_BCN_CFG115_ADDR(base) ((base) + 0xBCCUL)
#define SOC_ASP_SMARTPA_BCN_CFG116_ADDR(base) ((base) + 0xBD0UL)
#define SOC_ASP_SMARTPA_BCN_CFG117_ADDR(base) ((base) + 0xBD4UL)
#define SOC_ASP_SMARTPA_BCN_CFG118_ADDR(base) ((base) + 0xBD8UL)
#define SOC_ASP_SMARTPA_BCN_CFG119_ADDR(base) ((base) + 0xBDCUL)
#define SOC_ASP_SMARTPA_BCN_CFG120_ADDR(base) ((base) + 0xBE0UL)
#define SOC_ASP_SMARTPA_BCN_CFG121_ADDR(base) ((base) + 0xBE4UL)
#define SOC_ASP_SMARTPA_BCN_CFG122_ADDR(base) ((base) + 0xBE8UL)
#define SOC_ASP_SMARTPA_BCN_CFG123_ADDR(base) ((base) + 0xBECUL)
#define SOC_ASP_SMARTPA_BCN_CFG124_ADDR(base) ((base) + 0xBF0UL)
#define SOC_ASP_SMARTPA_BCN_CFG125_ADDR(base) ((base) + 0xBF4UL)
#define SOC_ASP_SMARTPA_BCN_CFG126_ADDR(base) ((base) + 0xBF8UL)
#define SOC_ASP_SMARTPA_ECP_CFG87_ADDR(base) ((base) + 0xBFCUL)
#define SOC_ASP_SMARTPA_ECP_CFG88_ADDR(base) ((base) + 0xC00UL)
#define SOC_ASP_SMARTPA_ECP_CFG89_ADDR(base) ((base) + 0xC04UL)
#define SOC_ASP_SMARTPA_FIR_CFG0_ADDR(base) ((base) + 0xC08UL)
#else
#define SOC_ASP_SMARTPA_BYPASS_CFG_ADDR(base) (base)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_ADDR(base) ((base) + 0x004)
#define SOC_ASP_SMARTPA_PRE_CFG0_ADDR(base) ((base) + 0x008)
#define SOC_ASP_SMARTPA_PRE_CFG1_ADDR(base) ((base) + 0x00C)
#define SOC_ASP_SMARTPA_PRE_CFG2_ADDR(base) ((base) + 0x010)
#define SOC_ASP_SMARTPA_PRE_CFG3_ADDR(base) ((base) + 0x014)
#define SOC_ASP_SMARTPA_PRE_CFG4_ADDR(base) ((base) + 0x018)
#define SOC_ASP_SMARTPA_PRE_CFG5_ADDR(base) ((base) + 0x01C)
#define SOC_ASP_SMARTPA_PRE_CFG6_ADDR(base) ((base) + 0x020)
#define SOC_ASP_SMARTPA_PRE_CFG7_ADDR(base) ((base) + 0x024)
#define SOC_ASP_SMARTPA_PRE_CFG8_ADDR(base) ((base) + 0x028)
#define SOC_ASP_SMARTPA_PRE_CFG9_ADDR(base) ((base) + 0x02C)
#define SOC_ASP_SMARTPA_PRE_CFG10_ADDR(base) ((base) + 0x030)
#define SOC_ASP_SMARTPA_PRE_CFG11_ADDR(base) ((base) + 0x034)
#define SOC_ASP_SMARTPA_PRE_CFG12_ADDR(base) ((base) + 0x038)
#define SOC_ASP_SMARTPA_PRE_CFG13_ADDR(base) ((base) + 0x03C)
#define SOC_ASP_SMARTPA_GEQ_CFG0_ADDR(base) ((base) + 0x068)
#define SOC_ASP_SMARTPA_GEQ_CFG1_ADDR(base) ((base) + 0x06C)
#define SOC_ASP_SMARTPA_GEQ_CFG2_ADDR(base) ((base) + 0x070)
#define SOC_ASP_SMARTPA_GEQ_CFG3_ADDR(base) ((base) + 0x074)
#define SOC_ASP_SMARTPA_GEQ_CFG4_ADDR(base) ((base) + 0x078)
#define SOC_ASP_SMARTPA_GEQ_CFG5_ADDR(base) ((base) + 0x07C)
#define SOC_ASP_SMARTPA_GEQ_CFG6_ADDR(base) ((base) + 0x080)
#define SOC_ASP_SMARTPA_GEQ_CFG7_ADDR(base) ((base) + 0x084)
#define SOC_ASP_SMARTPA_GEQ_CFG8_ADDR(base) ((base) + 0x088)
#define SOC_ASP_SMARTPA_GEQ_CFG9_ADDR(base) ((base) + 0x08C)
#define SOC_ASP_SMARTPA_GEQ_CFG10_ADDR(base) ((base) + 0x090)
#define SOC_ASP_SMARTPA_GEQ_CFG11_ADDR(base) ((base) + 0x094)
#define SOC_ASP_SMARTPA_GEQ_CFG12_ADDR(base) ((base) + 0x098)
#define SOC_ASP_SMARTPA_GEQ_CFG13_ADDR(base) ((base) + 0x09C)
#define SOC_ASP_SMARTPA_GEQ_CFG14_ADDR(base) ((base) + 0x0A0)
#define SOC_ASP_SMARTPA_GEQ_CFG15_ADDR(base) ((base) + 0x0A4)
#define SOC_ASP_SMARTPA_GEQ_CFG16_ADDR(base) ((base) + 0x0A8)
#define SOC_ASP_SMARTPA_GEQ_CFG17_ADDR(base) ((base) + 0x0AC)
#define SOC_ASP_SMARTPA_GEQ_CFG18_ADDR(base) ((base) + 0x0B0)
#define SOC_ASP_SMARTPA_GEQ_CFG19_ADDR(base) ((base) + 0x0B4)
#define SOC_ASP_SMARTPA_GEQ_CFG20_ADDR(base) ((base) + 0x0B8)
#define SOC_ASP_SMARTPA_GEQ_CFG21_ADDR(base) ((base) + 0x0BC)
#define SOC_ASP_SMARTPA_GEQ_CFG22_ADDR(base) ((base) + 0x0C0)
#define SOC_ASP_SMARTPA_GEQ_CFG23_ADDR(base) ((base) + 0x0C4)
#define SOC_ASP_SMARTPA_GEQ_CFG24_ADDR(base) ((base) + 0x0C8)
#define SOC_ASP_SMARTPA_GEQ_CFG25_ADDR(base) ((base) + 0x0CC)
#define SOC_ASP_SMARTPA_GEQ_CFG26_ADDR(base) ((base) + 0x0D0)
#define SOC_ASP_SMARTPA_GEQ_CFG27_ADDR(base) ((base) + 0x0D4)
#define SOC_ASP_SMARTPA_GEQ_CFG28_ADDR(base) ((base) + 0x0D8)
#define SOC_ASP_SMARTPA_GEQ_CFG29_ADDR(base) ((base) + 0x0DC)
#define SOC_ASP_SMARTPA_GEQ_CFG30_ADDR(base) ((base) + 0x0E0)
#define SOC_ASP_SMARTPA_GEQ_CFG31_ADDR(base) ((base) + 0x0E4)
#define SOC_ASP_SMARTPA_GEQ_CFG32_ADDR(base) ((base) + 0x0E8)
#define SOC_ASP_SMARTPA_GEQ_CFG33_ADDR(base) ((base) + 0x0EC)
#define SOC_ASP_SMARTPA_GEQ_CFG34_ADDR(base) ((base) + 0x0F0)
#define SOC_ASP_SMARTPA_GEQ_CFG35_ADDR(base) ((base) + 0x0F4)
#define SOC_ASP_SMARTPA_GEQ_CFG36_ADDR(base) ((base) + 0x0F8)
#define SOC_ASP_SMARTPA_GEQ_CFG37_ADDR(base) ((base) + 0x0FC)
#define SOC_ASP_SMARTPA_GEQ_CFG38_ADDR(base) ((base) + 0x100)
#define SOC_ASP_SMARTPA_GEQ_CFG39_ADDR(base) ((base) + 0x104)
#define SOC_ASP_SMARTPA_GEQ_CFG40_ADDR(base) ((base) + 0x108)
#define SOC_ASP_SMARTPA_GEQ_CFG41_ADDR(base) ((base) + 0x10C)
#define SOC_ASP_SMARTPA_GEQ_CFG42_ADDR(base) ((base) + 0x110)
#define SOC_ASP_SMARTPA_GEQ_CFG43_ADDR(base) ((base) + 0x114)
#define SOC_ASP_SMARTPA_GEQ_CFG44_ADDR(base) ((base) + 0x118)
#define SOC_ASP_SMARTPA_GEQ_CFG45_ADDR(base) ((base) + 0x11C)
#define SOC_ASP_SMARTPA_GEQ_CFG46_ADDR(base) ((base) + 0x120)
#define SOC_ASP_SMARTPA_GEQ_CFG47_ADDR(base) ((base) + 0x124)
#define SOC_ASP_SMARTPA_GEQ_CFG48_ADDR(base) ((base) + 0x128)
#define SOC_ASP_SMARTPA_GEQ_CFG49_ADDR(base) ((base) + 0x12C)
#define SOC_ASP_SMARTPA_GEQ_CFG50_ADDR(base) ((base) + 0x130)
#define SOC_ASP_SMARTPA_GEQ_CFG51_ADDR(base) ((base) + 0x134)
#define SOC_ASP_SMARTPA_GEQ_CFG52_ADDR(base) ((base) + 0x138)
#define SOC_ASP_SMARTPA_GEQ_CFG53_ADDR(base) ((base) + 0x13C)
#define SOC_ASP_SMARTPA_GEQ_CFG54_ADDR(base) ((base) + 0x140)
#define SOC_ASP_SMARTPA_GEQ_CFG55_ADDR(base) ((base) + 0x144)
#define SOC_ASP_SMARTPA_GEQ_CFG56_ADDR(base) ((base) + 0x148)
#define SOC_ASP_SMARTPA_GEQ_CFG57_ADDR(base) ((base) + 0x14C)
#define SOC_ASP_SMARTPA_GEQ_CFG58_ADDR(base) ((base) + 0x150)
#define SOC_ASP_SMARTPA_GEQ_CFG59_ADDR(base) ((base) + 0x154)
#define SOC_ASP_SMARTPA_DRC_CFG0_ADDR(base) ((base) + 0x158)
#define SOC_ASP_SMARTPA_DRC_CFG1_ADDR(base) ((base) + 0x15C)
#define SOC_ASP_SMARTPA_DRC_CFG2_ADDR(base) ((base) + 0x160)
#define SOC_ASP_SMARTPA_DRC_CFG3_ADDR(base) ((base) + 0x164)
#define SOC_ASP_SMARTPA_DRC_CFG4_ADDR(base) ((base) + 0x168)
#define SOC_ASP_SMARTPA_DRC_CFG5_ADDR(base) ((base) + 0x16C)
#define SOC_ASP_SMARTPA_DRC_CFG6_ADDR(base) ((base) + 0x170)
#define SOC_ASP_SMARTPA_DRC_CFG7_ADDR(base) ((base) + 0x174)
#define SOC_ASP_SMARTPA_DRC_CFG8_ADDR(base) ((base) + 0x178)
#define SOC_ASP_SMARTPA_DRC_CFG9_ADDR(base) ((base) + 0x17C)
#define SOC_ASP_SMARTPA_DRC_CFG10_ADDR(base) ((base) + 0x180)
#define SOC_ASP_SMARTPA_DRC_CFG11_ADDR(base) ((base) + 0x184)
#define SOC_ASP_SMARTPA_DRC_CFG12_ADDR(base) ((base) + 0x188)
#define SOC_ASP_SMARTPA_DRC_CFG13_ADDR(base) ((base) + 0x18C)
#define SOC_ASP_SMARTPA_DRC_CFG14_ADDR(base) ((base) + 0x190)
#define SOC_ASP_SMARTPA_DRC_CFG15_ADDR(base) ((base) + 0x194)
#define SOC_ASP_SMARTPA_DRC_CFG16_ADDR(base) ((base) + 0x198)
#define SOC_ASP_SMARTPA_DRC_CFG17_ADDR(base) ((base) + 0x19C)
#define SOC_ASP_SMARTPA_DRC_CFG18_ADDR(base) ((base) + 0x1A0)
#define SOC_ASP_SMARTPA_DRC_CFG19_ADDR(base) ((base) + 0x1A4)
#define SOC_ASP_SMARTPA_DRC_CFG20_ADDR(base) ((base) + 0x1A8)
#define SOC_ASP_SMARTPA_DRC_CFG21_ADDR(base) ((base) + 0x1AC)
#define SOC_ASP_SMARTPA_DRC_CFG22_ADDR(base) ((base) + 0x1B0)
#define SOC_ASP_SMARTPA_DRC_CFG23_ADDR(base) ((base) + 0x1B4)
#define SOC_ASP_SMARTPA_DRC_CFG24_ADDR(base) ((base) + 0x1B8)
#define SOC_ASP_SMARTPA_DRC_CFG25_ADDR(base) ((base) + 0x1BC)
#define SOC_ASP_SMARTPA_DRC_CFG26_ADDR(base) ((base) + 0x1C0)
#define SOC_ASP_SMARTPA_DRC_CFG27_ADDR(base) ((base) + 0x1C4)
#define SOC_ASP_SMARTPA_DRC_CFG28_ADDR(base) ((base) + 0x1C8)
#define SOC_ASP_SMARTPA_DRC_CFG29_ADDR(base) ((base) + 0x1CC)
#define SOC_ASP_SMARTPA_DRC_CFG30_ADDR(base) ((base) + 0x1D0)
#define SOC_ASP_SMARTPA_DRC_CFG31_ADDR(base) ((base) + 0x1D4)
#define SOC_ASP_SMARTPA_DRC_CFG32_ADDR(base) ((base) + 0x1D8)
#define SOC_ASP_SMARTPA_DRC_CFG33_ADDR(base) ((base) + 0x1DC)
#define SOC_ASP_SMARTPA_DRC_CFG34_ADDR(base) ((base) + 0x1E0)
#define SOC_ASP_SMARTPA_DRC_CFG35_ADDR(base) ((base) + 0x1E4)
#define SOC_ASP_SMARTPA_DRC_CFG36_ADDR(base) ((base) + 0x1E8)
#define SOC_ASP_SMARTPA_DRC_CFG37_ADDR(base) ((base) + 0x1EC)
#define SOC_ASP_SMARTPA_DRC_CFG38_ADDR(base) ((base) + 0x1F0)
#define SOC_ASP_SMARTPA_DRC_CFG39_ADDR(base) ((base) + 0x1F4)
#define SOC_ASP_SMARTPA_DRC_CFG40_ADDR(base) ((base) + 0x1F8)
#define SOC_ASP_SMARTPA_DRC_CFG41_ADDR(base) ((base) + 0x1FC)
#define SOC_ASP_SMARTPA_DRC_CFG42_ADDR(base) ((base) + 0x200)
#define SOC_ASP_SMARTPA_DRC_CFG43_ADDR(base) ((base) + 0x204)
#define SOC_ASP_SMARTPA_DRC_CFG44_ADDR(base) ((base) + 0x208)
#define SOC_ASP_SMARTPA_DRC_CFG45_ADDR(base) ((base) + 0x20C)
#define SOC_ASP_SMARTPA_DRC_CFG46_ADDR(base) ((base) + 0x210)
#define SOC_ASP_SMARTPA_DRC_CFG47_ADDR(base) ((base) + 0x214)
#define SOC_ASP_SMARTPA_DRC_CFG48_ADDR(base) ((base) + 0x218)
#define SOC_ASP_SMARTPA_DRC_CFG49_ADDR(base) ((base) + 0x21C)
#define SOC_ASP_SMARTPA_DRC_CFG50_ADDR(base) ((base) + 0x220)
#define SOC_ASP_SMARTPA_DRC_CFG51_ADDR(base) ((base) + 0x224)
#define SOC_ASP_SMARTPA_DRC_CFG52_ADDR(base) ((base) + 0x228)
#define SOC_ASP_SMARTPA_DRC_CFG53_ADDR(base) ((base) + 0x22C)
#define SOC_ASP_SMARTPA_DRC_CFG54_ADDR(base) ((base) + 0x230)
#define SOC_ASP_SMARTPA_DRC_CFG55_ADDR(base) ((base) + 0x234)
#define SOC_ASP_SMARTPA_DRC_CFG56_ADDR(base) ((base) + 0x238)
#define SOC_ASP_SMARTPA_DRC_CFG57_ADDR(base) ((base) + 0x23C)
#define SOC_ASP_SMARTPA_DRC_CFG58_ADDR(base) ((base) + 0x240)
#define SOC_ASP_SMARTPA_DRC_CFG59_ADDR(base) ((base) + 0x244)
#define SOC_ASP_SMARTPA_DRC_CFG60_ADDR(base) ((base) + 0x248)
#define SOC_ASP_SMARTPA_DRC_CFG61_ADDR(base) ((base) + 0x24C)
#define SOC_ASP_SMARTPA_DRC_CFG62_ADDR(base) ((base) + 0x250)
#define SOC_ASP_SMARTPA_DRC_CFG63_ADDR(base) ((base) + 0x254)
#define SOC_ASP_SMARTPA_SSD_CFG0_ADDR(base) ((base) + 0x258)
#define SOC_ASP_SMARTPA_IDF_CFG0_ADDR(base) ((base) + 0x25C)
#define SOC_ASP_SMARTPA_IDF_CFG1_ADDR(base) ((base) + 0x260)
#define SOC_ASP_SMARTPA_IDF_CFG2_ADDR(base) ((base) + 0x264)
#define SOC_ASP_SMARTPA_IDF_CFG3_ADDR(base) ((base) + 0x268)
#define SOC_ASP_SMARTPA_IDF_CFG4_ADDR(base) ((base) + 0x26C)
#define SOC_ASP_SMARTPA_POW_CFG0_ADDR(base) ((base) + 0x270)
#define SOC_ASP_SMARTPA_POW_CFG2_ADDR(base) ((base) + 0x278)
#define SOC_ASP_SMARTPA_POW_CFG3_ADDR(base) ((base) + 0x27C)
#define SOC_ASP_SMARTPA_POW_CFG4_ADDR(base) ((base) + 0x280)
#define SOC_ASP_SMARTPA_POW_CFG5_ADDR(base) ((base) + 0x284)
#define SOC_ASP_SMARTPA_POW_CFG6_ADDR(base) ((base) + 0x288)
#define SOC_ASP_SMARTPA_POW_CFG7_ADDR(base) ((base) + 0x28C)
#define SOC_ASP_SMARTPA_POW_CFG8_ADDR(base) ((base) + 0x290)
#define SOC_ASP_SMARTPA_POW_CFG9_ADDR(base) ((base) + 0x294)
#define SOC_ASP_SMARTPA_POW_CFG10_ADDR(base) ((base) + 0x298)
#define SOC_ASP_SMARTPA_POW_CFG11_ADDR(base) ((base) + 0x29C)
#define SOC_ASP_SMARTPA_POW_CFG12_ADDR(base) ((base) + 0x2A0)
#define SOC_ASP_SMARTPA_TEP_CFG0_ADDR(base) ((base) + 0x2A4)
#define SOC_ASP_SMARTPA_TEP_CFG1_ADDR(base) ((base) + 0x2A8)
#define SOC_ASP_SMARTPA_TEP_CFG2_ADDR(base) ((base) + 0x2AC)
#define SOC_ASP_SMARTPA_TEP_CFG3_ADDR(base) ((base) + 0x2B0)
#define SOC_ASP_SMARTPA_TEP_CFG4_ADDR(base) ((base) + 0x2B4)
#define SOC_ASP_SMARTPA_TEP_CFG5_ADDR(base) ((base) + 0x2B8)
#define SOC_ASP_SMARTPA_TEP_CFG6_ADDR(base) ((base) + 0x2BC)
#define SOC_ASP_SMARTPA_TEP_CFG7_ADDR(base) ((base) + 0x2C0)
#define SOC_ASP_SMARTPA_TEP_CFG8_ADDR(base) ((base) + 0x2C4)
#define SOC_ASP_SMARTPA_TEP_CFG9_ADDR(base) ((base) + 0x2C8)
#define SOC_ASP_SMARTPA_TEP_CFG10_ADDR(base) ((base) + 0x2CC)
#define SOC_ASP_SMARTPA_TEP_CFG11_ADDR(base) ((base) + 0x2D0)
#define SOC_ASP_SMARTPA_TEP_CFG12_ADDR(base) ((base) + 0x2D4)
#define SOC_ASP_SMARTPA_TEP_CFG13_ADDR(base) ((base) + 0x2D8)
#define SOC_ASP_SMARTPA_TEP_CFG14_ADDR(base) ((base) + 0x2DC)
#define SOC_ASP_SMARTPA_AND_CFG0_ADDR(base) ((base) + 0x2E0)
#define SOC_ASP_SMARTPA_AND_CFG1_ADDR(base) ((base) + 0x2E4)
#define SOC_ASP_SMARTPA_AND_CFG2_ADDR(base) ((base) + 0x2E8)
#define SOC_ASP_SMARTPA_AND_CFG3_ADDR(base) ((base) + 0x2EC)
#define SOC_ASP_SMARTPA_AND_CFG4_ADDR(base) ((base) + 0x2F0)
#define SOC_ASP_SMARTPA_AND_CFG5_ADDR(base) ((base) + 0x2F4)
#define SOC_ASP_SMARTPA_AND_CFG6_ADDR(base) ((base) + 0x2F8)
#define SOC_ASP_SMARTPA_RGC_CFG0_ADDR(base) ((base) + 0x2FC)
#define SOC_ASP_SMARTPA_RGC_CFG1_ADDR(base) ((base) + 0x300)
#define SOC_ASP_SMARTPA_RGC_CFG2_ADDR(base) ((base) + 0x304)
#define SOC_ASP_SMARTPA_RGC_CFG3_ADDR(base) ((base) + 0x308)
#define SOC_ASP_SMARTPA_RGC_CFG4_ADDR(base) ((base) + 0x30C)
#define SOC_ASP_SMARTPA_RGC_CFG5_ADDR(base) ((base) + 0x310)
#define SOC_ASP_SMARTPA_RGC_CFG6_ADDR(base) ((base) + 0x314)
#define SOC_ASP_SMARTPA_RGC_CFG7_ADDR(base) ((base) + 0x318)
#define SOC_ASP_SMARTPA_RGC_CFG9_ADDR(base) ((base) + 0x320)
#define SOC_ASP_SMARTPA_RGC_CFG10_ADDR(base) ((base) + 0x324)
#define SOC_ASP_SMARTPA_RGC_CFG13_ADDR(base) ((base) + 0x330)
#define SOC_ASP_SMARTPA_RGC_CFG14_ADDR(base) ((base) + 0x334)
#define SOC_ASP_SMARTPA_RGC_CFG15_ADDR(base) ((base) + 0x338)
#define SOC_ASP_SMARTPA_RGC_CFG17_ADDR(base) ((base) + 0x340)
#define SOC_ASP_SMARTPA_RGC_CFG18_ADDR(base) ((base) + 0x344)
#define SOC_ASP_SMARTPA_RGC_CFG19_ADDR(base) ((base) + 0x348)
#define SOC_ASP_SMARTPA_RGC_CFG20_ADDR(base) ((base) + 0x34C)
#define SOC_ASP_SMARTPA_RGC_CFG21_ADDR(base) ((base) + 0x350)
#define SOC_ASP_SMARTPA_RGC_CFG22_ADDR(base) ((base) + 0x354)
#define SOC_ASP_SMARTPA_BGC_CFG0_ADDR(base) ((base) + 0x358)
#define SOC_ASP_SMARTPA_BGC_CFG1_ADDR(base) ((base) + 0x35C)
#define SOC_ASP_SMARTPA_BGC_CFG2_ADDR(base) ((base) + 0x360)
#define SOC_ASP_SMARTPA_BGC_CFG3_ADDR(base) ((base) + 0x364)
#define SOC_ASP_SMARTPA_BGC_CFG4_ADDR(base) ((base) + 0x368)
#define SOC_ASP_SMARTPA_BGC_CFG5_ADDR(base) ((base) + 0x36C)
#define SOC_ASP_SMARTPA_BGC_CFG6_ADDR(base) ((base) + 0x370)
#define SOC_ASP_SMARTPA_BGC_CFG7_ADDR(base) ((base) + 0x374)
#define SOC_ASP_SMARTPA_BGC_CFG8_ADDR(base) ((base) + 0x378)
#define SOC_ASP_SMARTPA_BGC_CFG9_ADDR(base) ((base) + 0x37C)
#define SOC_ASP_SMARTPA_BGC_CFG10_ADDR(base) ((base) + 0x380)
#define SOC_ASP_SMARTPA_BGC_CFG11_ADDR(base) ((base) + 0x384)
#define SOC_ASP_SMARTPA_BGC_CFG12_ADDR(base) ((base) + 0x388)
#define SOC_ASP_SMARTPA_BGC_CFG13_ADDR(base) ((base) + 0x38C)
#define SOC_ASP_SMARTPA_BGC_CFG14_ADDR(base) ((base) + 0x390)
#define SOC_ASP_SMARTPA_BGC_CFG15_ADDR(base) ((base) + 0x394)
#define SOC_ASP_SMARTPA_BGC_CFG16_ADDR(base) ((base) + 0x398)
#define SOC_ASP_SMARTPA_BGC_CFG17_ADDR(base) ((base) + 0x39C)
#define SOC_ASP_SMARTPA_BGC_CFG18_ADDR(base) ((base) + 0x3A0)
#define SOC_ASP_SMARTPA_BGC_CFG19_ADDR(base) ((base) + 0x3A4)
#define SOC_ASP_SMARTPA_BGC_CFG20_ADDR(base) ((base) + 0x3A8)
#define SOC_ASP_SMARTPA_BGC_CFG21_ADDR(base) ((base) + 0x3AC)
#define SOC_ASP_SMARTPA_BGC_CFG22_ADDR(base) ((base) + 0x3B0)
#define SOC_ASP_SMARTPA_BGC_CFG23_ADDR(base) ((base) + 0x3B4)
#define SOC_ASP_SMARTPA_BGC_CFG24_ADDR(base) ((base) + 0x3B8)
#define SOC_ASP_SMARTPA_BGC_CFG25_ADDR(base) ((base) + 0x3BC)
#define SOC_ASP_SMARTPA_BGC_CFG26_ADDR(base) ((base) + 0x3C0)
#define SOC_ASP_SMARTPA_BGC_CFG27_ADDR(base) ((base) + 0x3C4)
#define SOC_ASP_SMARTPA_SDC_CFG0_ADDR(base) ((base) + 0x3C8)
#define SOC_ASP_SMARTPA_SDC_CFG1_ADDR(base) ((base) + 0x3CC)
#define SOC_ASP_SMARTPA_SDC_CFG2_ADDR(base) ((base) + 0x3D0)
#define SOC_ASP_SMARTPA_SDC_CFG3_ADDR(base) ((base) + 0x3D4)
#define SOC_ASP_SMARTPA_SDC_CFG4_ADDR(base) ((base) + 0x3D8)
#define SOC_ASP_SMARTPA_SDC_CFG5_ADDR(base) ((base) + 0x3DC)
#define SOC_ASP_SMARTPA_SDC_CFG6_ADDR(base) ((base) + 0x3E0)
#define SOC_ASP_SMARTPA_SDC_CFG7_ADDR(base) ((base) + 0x3E4)
#define SOC_ASP_SMARTPA_SDC_CFG8_ADDR(base) ((base) + 0x3E8)
#define SOC_ASP_SMARTPA_SDC_CFG9_ADDR(base) ((base) + 0x3EC)
#define SOC_ASP_SMARTPA_SDC_CFG10_ADDR(base) ((base) + 0x3F0)
#define SOC_ASP_SMARTPA_SDC_CFG11_ADDR(base) ((base) + 0x3F4)
#define SOC_ASP_SMARTPA_SDC_CFG12_ADDR(base) ((base) + 0x3F8)
#define SOC_ASP_SMARTPA_SDC_CFG13_ADDR(base) ((base) + 0x3FC)
#define SOC_ASP_SMARTPA_SDC_CFG14_ADDR(base) ((base) + 0x400)
#define SOC_ASP_SMARTPA_SDC_CFG15_ADDR(base) ((base) + 0x404)
#define SOC_ASP_SMARTPA_SDC_CFG16_ADDR(base) ((base) + 0x408)
#define SOC_ASP_SMARTPA_SDC_CFG17_ADDR(base) ((base) + 0x40C)
#define SOC_ASP_SMARTPA_SDC_CFG18_ADDR(base) ((base) + 0x410)
#define SOC_ASP_SMARTPA_SDC_CFG19_ADDR(base) ((base) + 0x414)
#define SOC_ASP_SMARTPA_SDC_CFG20_ADDR(base) ((base) + 0x418)
#define SOC_ASP_SMARTPA_SDC_CFG21_ADDR(base) ((base) + 0x41C)
#define SOC_ASP_SMARTPA_SDC_CFG22_ADDR(base) ((base) + 0x420)
#define SOC_ASP_SMARTPA_SDC_CFG23_ADDR(base) ((base) + 0x424)
#define SOC_ASP_SMARTPA_SDC_CFG24_ADDR(base) ((base) + 0x428)
#define SOC_ASP_SMARTPA_SDC_CFG25_ADDR(base) ((base) + 0x42C)
#define SOC_ASP_SMARTPA_SDC_CFG26_ADDR(base) ((base) + 0x430)
#define SOC_ASP_SMARTPA_SDC_CFG27_ADDR(base) ((base) + 0x434)
#define SOC_ASP_SMARTPA_SDC_CFG28_ADDR(base) ((base) + 0x438)
#define SOC_ASP_SMARTPA_SDC_CFG29_ADDR(base) ((base) + 0x43C)
#define SOC_ASP_SMARTPA_NDC_CFG0_ADDR(base) ((base) + 0x440)
#define SOC_ASP_SMARTPA_NDC_CFG1_ADDR(base) ((base) + 0x444)
#define SOC_ASP_SMARTPA_NDC_CFG2_ADDR(base) ((base) + 0x448)
#define SOC_ASP_SMARTPA_NDC_CFG3_ADDR(base) ((base) + 0x44C)
#define SOC_ASP_SMARTPA_NDC_CFG4_ADDR(base) ((base) + 0x450)
#define SOC_ASP_SMARTPA_NDC_CFG5_ADDR(base) ((base) + 0x454)
#define SOC_ASP_SMARTPA_NDC_CFG6_ADDR(base) ((base) + 0x458)
#define SOC_ASP_SMARTPA_NDC_CFG7_ADDR(base) ((base) + 0x45C)
#define SOC_ASP_SMARTPA_NDC_CFG8_ADDR(base) ((base) + 0x460)
#define SOC_ASP_SMARTPA_NDC_CFG9_ADDR(base) ((base) + 0x464)
#define SOC_ASP_SMARTPA_NDC_CFG10_ADDR(base) ((base) + 0x468)
#define SOC_ASP_SMARTPA_NDC_CFG11_ADDR(base) ((base) + 0x46C)
#define SOC_ASP_SMARTPA_NDC_CFG12_ADDR(base) ((base) + 0x470)
#define SOC_ASP_SMARTPA_NDC_CFG13_ADDR(base) ((base) + 0x474)
#define SOC_ASP_SMARTPA_NDC_CFG14_ADDR(base) ((base) + 0x478)
#define SOC_ASP_SMARTPA_NDC_CFG15_ADDR(base) ((base) + 0x47C)
#define SOC_ASP_SMARTPA_NDC_CFG16_ADDR(base) ((base) + 0x480)
#define SOC_ASP_SMARTPA_NDC_CFG17_ADDR(base) ((base) + 0x484)
#define SOC_ASP_SMARTPA_NDC_CFG18_ADDR(base) ((base) + 0x488)
#define SOC_ASP_SMARTPA_NDC_CFG19_ADDR(base) ((base) + 0x48C)
#define SOC_ASP_SMARTPA_NDC_CFG20_ADDR(base) ((base) + 0x490)
#define SOC_ASP_SMARTPA_NDC_CFG21_ADDR(base) ((base) + 0x494)
#define SOC_ASP_SMARTPA_NDC_CFG22_ADDR(base) ((base) + 0x498)
#define SOC_ASP_SMARTPA_NDC_CFG23_ADDR(base) ((base) + 0x49C)
#define SOC_ASP_SMARTPA_NDC_CFG24_ADDR(base) ((base) + 0x4A0)
#define SOC_ASP_SMARTPA_NDC_CFG25_ADDR(base) ((base) + 0x4A4)
#define SOC_ASP_SMARTPA_NDC_CFG26_ADDR(base) ((base) + 0x4A8)
#define SOC_ASP_SMARTPA_NDC_CFG27_ADDR(base) ((base) + 0x4AC)
#define SOC_ASP_SMARTPA_NDC_CFG28_ADDR(base) ((base) + 0x4B0)
#define SOC_ASP_SMARTPA_NDC_CFG29_ADDR(base) ((base) + 0x4B4)
#define SOC_ASP_SMARTPA_NDC_CFG30_ADDR(base) ((base) + 0x4B8)
#define SOC_ASP_SMARTPA_NDC_CFG31_ADDR(base) ((base) + 0x4BC)
#define SOC_ASP_SMARTPA_NDC_CFG32_ADDR(base) ((base) + 0x4C0)
#define SOC_ASP_SMARTPA_NDC_CFG33_ADDR(base) ((base) + 0x4C4)
#define SOC_ASP_SMARTPA_NDC_CFG34_ADDR(base) ((base) + 0x4C8)
#define SOC_ASP_SMARTPA_LMT_CFG0_ADDR(base) ((base) + 0x4CC)
#define SOC_ASP_SMARTPA_PLT_CFG0_ADDR(base) ((base) + 0x4D0)
#define SOC_ASP_SMARTPA_PLT_CFG1_ADDR(base) ((base) + 0x4D4)
#define SOC_ASP_SMARTPA_PLT_CFG2_ADDR(base) ((base) + 0x4D8)
#define SOC_ASP_SMARTPA_IDF_CFG5_ADDR(base) ((base) + 0x4DC)
#define SOC_ASP_SMARTPA_IDF_CFG6_ADDR(base) ((base) + 0x4E0)
#define SOC_ASP_SMARTPA_IDF_CFG7_ADDR(base) ((base) + 0x4E4)
#define SOC_ASP_SMARTPA_IDF_CFG8_ADDR(base) ((base) + 0x4E8)
#define SOC_ASP_SMARTPA_IDF_CFG10_ADDR(base) ((base) + 0x4F0)
#define SOC_ASP_SMARTPA_IDF_CFG11_ADDR(base) ((base) + 0x4F4)
#define SOC_ASP_SMARTPA_IDF_CFG12_ADDR(base) ((base) + 0x4F8)
#define SOC_ASP_SMARTPA_IDF_CFG13_ADDR(base) ((base) + 0x4FC)
#define SOC_ASP_SMARTPA_LSM_CFG0_ADDR(base) ((base) + 0x504)
#define SOC_ASP_SMARTPA_LSM_CFG1_ADDR(base) ((base) + 0x508)
#define SOC_ASP_SMARTPA_LSM_CFG2_ADDR(base) ((base) + 0x50C)
#define SOC_ASP_SMARTPA_LSM_CFG3_ADDR(base) ((base) + 0x510)
#define SOC_ASP_SMARTPA_LSM_CFG4_ADDR(base) ((base) + 0x514)
#define SOC_ASP_SMARTPA_LSM_CFG6_ADDR(base) ((base) + 0x51C)
#define SOC_ASP_SMARTPA_LSM_CFG7_ADDR(base) ((base) + 0x520)
#define SOC_ASP_SMARTPA_LSM_CFG8_ADDR(base) ((base) + 0x524)
#define SOC_ASP_SMARTPA_LSM_CFG9_ADDR(base) ((base) + 0x528)
#define SOC_ASP_SMARTPA_LSM_CFG10_ADDR(base) ((base) + 0x52C)
#define SOC_ASP_SMARTPA_LSM_CFG12_ADDR(base) ((base) + 0x534)
#define SOC_ASP_SMARTPA_LSM_CFG13_ADDR(base) ((base) + 0x538)
#define SOC_ASP_SMARTPA_LSM_CFG14_ADDR(base) ((base) + 0x53C)
#define SOC_ASP_SMARTPA_LSM_CFG15_ADDR(base) ((base) + 0x540)
#define SOC_ASP_SMARTPA_LSM_CFG16_ADDR(base) ((base) + 0x544)
#define SOC_ASP_SMARTPA_LSM_CFG17_ADDR(base) ((base) + 0x548)
#define SOC_ASP_SMARTPA_LSM_CFG18_ADDR(base) ((base) + 0x54C)
#define SOC_ASP_SMARTPA_LSM_CFG19_ADDR(base) ((base) + 0x550)
#define SOC_ASP_SMARTPA_LSM_CFG20_ADDR(base) ((base) + 0x554)
#define SOC_ASP_SMARTPA_LSM_CFG21_ADDR(base) ((base) + 0x558)
#define SOC_ASP_SMARTPA_LSM_CFG22_ADDR(base) ((base) + 0x55C)
#define SOC_ASP_SMARTPA_LSM_CFG24_ADDR(base) ((base) + 0x564)
#define SOC_ASP_SMARTPA_LSM_CFG25_ADDR(base) ((base) + 0x568)
#define SOC_ASP_SMARTPA_LSM_CFG26_ADDR(base) ((base) + 0x56C)
#define SOC_ASP_SMARTPA_LSM_CFG28_ADDR(base) ((base) + 0x57C)
#define SOC_ASP_SMARTPA_ECP_CFG0_ADDR(base) ((base) + 0x590)
#define SOC_ASP_SMARTPA_ECP_CFG1_ADDR(base) ((base) + 0x594)
#define SOC_ASP_SMARTPA_ECP_CFG2_ADDR(base) ((base) + 0x598)
#define SOC_ASP_SMARTPA_ECP_CFG3_ADDR(base) ((base) + 0x59C)
#define SOC_ASP_SMARTPA_ECP_CFG4_ADDR(base) ((base) + 0x5A0)
#define SOC_ASP_SMARTPA_ECP_CFG5_ADDR(base) ((base) + 0x5A4)
#define SOC_ASP_SMARTPA_ECP_CFG6_ADDR(base) ((base) + 0x5A8)
#define SOC_ASP_SMARTPA_ECP_CFG7_ADDR(base) ((base) + 0x5AC)
#define SOC_ASP_SMARTPA_ECP_CFG8_ADDR(base) ((base) + 0x5B0)
#define SOC_ASP_SMARTPA_ECP_CFG9_ADDR(base) ((base) + 0x5B4)
#define SOC_ASP_SMARTPA_ECP_CFG10_ADDR(base) ((base) + 0x5B8)
#define SOC_ASP_SMARTPA_ECP_CFG11_ADDR(base) ((base) + 0x5BC)
#define SOC_ASP_SMARTPA_ECP_CFG12_ADDR(base) ((base) + 0x5C0)
#define SOC_ASP_SMARTPA_ECP_CFG13_ADDR(base) ((base) + 0x5C4)
#define SOC_ASP_SMARTPA_ECP_CFG14_ADDR(base) ((base) + 0x5C8)
#define SOC_ASP_SMARTPA_ECP_CFG15_ADDR(base) ((base) + 0x5CC)
#define SOC_ASP_SMARTPA_ECP_CFG16_ADDR(base) ((base) + 0x5D0)
#define SOC_ASP_SMARTPA_ECP_CFG17_ADDR(base) ((base) + 0x5D4)
#define SOC_ASP_SMARTPA_ECP_CFG18_ADDR(base) ((base) + 0x5D8)
#define SOC_ASP_SMARTPA_ECP_CFG19_ADDR(base) ((base) + 0x5DC)
#define SOC_ASP_SMARTPA_ECP_CFG20_ADDR(base) ((base) + 0x5E0)
#define SOC_ASP_SMARTPA_ECP_CFG21_ADDR(base) ((base) + 0x5E4)
#define SOC_ASP_SMARTPA_ECP_CFG22_ADDR(base) ((base) + 0x5E8)
#define SOC_ASP_SMARTPA_ECP_CFG23_ADDR(base) ((base) + 0x5EC)
#define SOC_ASP_SMARTPA_ECP_CFG24_ADDR(base) ((base) + 0x5F0)
#define SOC_ASP_SMARTPA_ECP_CFG25_ADDR(base) ((base) + 0x5F4)
#define SOC_ASP_SMARTPA_ECP_CFG26_ADDR(base) ((base) + 0x5F8)
#define SOC_ASP_SMARTPA_ECP_CFG27_ADDR(base) ((base) + 0x5FC)
#define SOC_ASP_SMARTPA_ECP_CFG28_ADDR(base) ((base) + 0x600)
#define SOC_ASP_SMARTPA_ECP_CFG29_ADDR(base) ((base) + 0x604)
#define SOC_ASP_SMARTPA_ECP_CFG30_ADDR(base) ((base) + 0x608)
#define SOC_ASP_SMARTPA_ECP_CFG31_ADDR(base) ((base) + 0x60C)
#define SOC_ASP_SMARTPA_ECP_CFG32_ADDR(base) ((base) + 0x610)
#define SOC_ASP_SMARTPA_ECP_CFG33_ADDR(base) ((base) + 0x614)
#define SOC_ASP_SMARTPA_ECP_CFG34_ADDR(base) ((base) + 0x618)
#define SOC_ASP_SMARTPA_ECP_CFG35_ADDR(base) ((base) + 0x61C)
#define SOC_ASP_SMARTPA_ECP_CFG36_ADDR(base) ((base) + 0x620)
#define SOC_ASP_SMARTPA_ECP_CFG37_ADDR(base) ((base) + 0x624)
#define SOC_ASP_SMARTPA_ECP_CFG38_ADDR(base) ((base) + 0x628)
#define SOC_ASP_SMARTPA_ECP_CFG39_ADDR(base) ((base) + 0x62C)
#define SOC_ASP_SMARTPA_ECP_CFG40_ADDR(base) ((base) + 0x630)
#define SOC_ASP_SMARTPA_ECP_CFG41_ADDR(base) ((base) + 0x634)
#define SOC_ASP_SMARTPA_ECP_CFG42_ADDR(base) ((base) + 0x638)
#define SOC_ASP_SMARTPA_ECP_CFG43_ADDR(base) ((base) + 0x63C)
#define SOC_ASP_SMARTPA_ECP_CFG44_ADDR(base) ((base) + 0x640)
#define SOC_ASP_SMARTPA_ECP_CFG45_ADDR(base) ((base) + 0x644)
#define SOC_ASP_SMARTPA_ECP_CFG46_ADDR(base) ((base) + 0x648)
#define SOC_ASP_SMARTPA_ECP_CFG47_ADDR(base) ((base) + 0x64C)
#define SOC_ASP_SMARTPA_ECP_CFG48_ADDR(base) ((base) + 0x650)
#define SOC_ASP_SMARTPA_ECP_CFG49_ADDR(base) ((base) + 0x654)
#define SOC_ASP_SMARTPA_ECP_CFG50_ADDR(base) ((base) + 0x658)
#define SOC_ASP_SMARTPA_ECP_CFG51_ADDR(base) ((base) + 0x65C)
#define SOC_ASP_SMARTPA_ECP_CFG52_ADDR(base) ((base) + 0x660)
#define SOC_ASP_SMARTPA_ECP_CFG53_ADDR(base) ((base) + 0x664)
#define SOC_ASP_SMARTPA_ECP_CFG54_ADDR(base) ((base) + 0x668)
#define SOC_ASP_SMARTPA_ECP_CFG55_ADDR(base) ((base) + 0x66C)
#define SOC_ASP_SMARTPA_ECP_CFG56_ADDR(base) ((base) + 0x670)
#define SOC_ASP_SMARTPA_ECP_CFG57_ADDR(base) ((base) + 0x674)
#define SOC_ASP_SMARTPA_ECP_CFG58_ADDR(base) ((base) + 0x678)
#define SOC_ASP_SMARTPA_ECP_CFG59_ADDR(base) ((base) + 0x67C)
#define SOC_ASP_SMARTPA_ECP_CFG60_ADDR(base) ((base) + 0x680)
#define SOC_ASP_SMARTPA_ECP_CFG61_ADDR(base) ((base) + 0x684)
#define SOC_ASP_SMARTPA_ECP_CFG62_ADDR(base) ((base) + 0x688)
#define SOC_ASP_SMARTPA_ECP_CFG63_ADDR(base) ((base) + 0x68C)
#define SOC_ASP_SMARTPA_ECP_CFG64_ADDR(base) ((base) + 0x690)
#define SOC_ASP_SMARTPA_ECP_CFG65_ADDR(base) ((base) + 0x694)
#define SOC_ASP_SMARTPA_ECP_CFG66_ADDR(base) ((base) + 0x698)
#define SOC_ASP_SMARTPA_ECP_CFG67_ADDR(base) ((base) + 0x69C)
#define SOC_ASP_SMARTPA_ECP_CFG68_ADDR(base) ((base) + 0x6A0)
#define SOC_ASP_SMARTPA_ECP_CFG69_ADDR(base) ((base) + 0x6A4)
#define SOC_ASP_SMARTPA_ECP_CFG70_ADDR(base) ((base) + 0x6A8)
#define SOC_ASP_SMARTPA_ECP_CFG71_ADDR(base) ((base) + 0x6AC)
#define SOC_ASP_SMARTPA_ECP_CFG72_ADDR(base) ((base) + 0x6B0)
#define SOC_ASP_SMARTPA_ECP_CFG73_ADDR(base) ((base) + 0x6B4)
#define SOC_ASP_SMARTPA_ECP_CFG74_ADDR(base) ((base) + 0x6B8)
#define SOC_ASP_SMARTPA_ECP_CFG75_ADDR(base) ((base) + 0x6BC)
#define SOC_ASP_SMARTPA_ECP_CFG76_ADDR(base) ((base) + 0x6C0)
#define SOC_ASP_SMARTPA_ECP_CFG77_ADDR(base) ((base) + 0x6C4)
#define SOC_ASP_SMARTPA_ECP_CFG78_ADDR(base) ((base) + 0x6C8)
#define SOC_ASP_SMARTPA_ECP_CFG79_ADDR(base) ((base) + 0x6CC)
#define SOC_ASP_SMARTPA_ECP_CFG80_ADDR(base) ((base) + 0x6D0)
#define SOC_ASP_SMARTPA_ECP_CFG81_ADDR(base) ((base) + 0x6D4)
#define SOC_ASP_SMARTPA_ECP_CFG82_ADDR(base) ((base) + 0x6D8)
#define SOC_ASP_SMARTPA_ECP_CFG83_ADDR(base) ((base) + 0x6DC)
#define SOC_ASP_SMARTPA_ECP_CFG84_ADDR(base) ((base) + 0x6E0)
#define SOC_ASP_SMARTPA_ECP_CFG85_ADDR(base) ((base) + 0x6E4)
#define SOC_ASP_SMARTPA_ECP_CFG86_ADDR(base) ((base) + 0x6E8)
#define SOC_ASP_SMARTPA_IDF_CFG14_ADDR(base) ((base) + 0x6EC)
#define SOC_ASP_SMARTPA_IDF_CFG16_ADDR(base) ((base) + 0x6F4)
#define SOC_ASP_SMARTPA_IDF_CFG17_ADDR(base) ((base) + 0x6F8)
#define SOC_ASP_SMARTPA_IDF_CFG18_ADDR(base) ((base) + 0x6FC)
#define SOC_ASP_SMARTPA_BGC_CFG28_ADDR(base) ((base) + 0x700)
#define SOC_ASP_SMARTPA_PLT_CFG3_ADDR(base) ((base) + 0x704)
#define SOC_ASP_SMARTPA_PLT_CFG4_ADDR(base) ((base) + 0x708)
#define SOC_ASP_SMARTPA_PLT_CFG5_ADDR(base) ((base) + 0x710)
#define SOC_ASP_SMARTPA_PLT_CFG6_ADDR(base) ((base) + 0x714)
#define SOC_ASP_SMARTPA_IDF_CFG19_ADDR(base) ((base) + 0x70C)
#define SOC_ASP_SMARTPA_CROSSFADE_STEP_CFG_ADDR(base) ((base) + 0x780)
#define SOC_ASP_SMARTPA_LSM_RO_STATE0_ADDR(base) ((base) + 0x7A4)
#define SOC_ASP_SMARTPA_IDF_RO_STATE0_ADDR(base) ((base) + 0x7A8)
#define SOC_ASP_SMARTPA_IDF_RO_STATE1_ADDR(base) ((base) + 0x7AC)
#define SOC_ASP_SMARTPA_IDF_RO_STATE2_ADDR(base) ((base) + 0x7B0)
#define SOC_ASP_SMARTPA_POW_RO_STATE0_ADDR(base) ((base) + 0x7B4)
#define SOC_ASP_SMARTPA_POW_RO_STATE1_ADDR(base) ((base) + 0x7B8)
#define SOC_ASP_SMARTPA_POW_RO_STATE2_ADDR(base) ((base) + 0x7BC)
#define SOC_ASP_SMARTPA_AND_RO_STATE0_ADDR(base) ((base) + 0x7C0)
#define SOC_ASP_SMARTPA_RGC_RO_STATE0_ADDR(base) ((base) + 0x7C4)
#define SOC_ASP_SMARTPA_RGC_RO_STATE1_ADDR(base) ((base) + 0x7C8)
#define SOC_ASP_SMARTPA_RGC_RO_STATE2_ADDR(base) ((base) + 0x7CC)
#define SOC_ASP_SMARTPA_IDF_RO_STATE4_ADDR(base) ((base) + 0x7D0)
#define SOC_ASP_SMARTPA_POW_RO_STATE3_ADDR(base) ((base) + 0x7D4)
#define SOC_ASP_SMARTPA_TEP_RO_STATE0_ADDR(base) ((base) + 0x7D8)
#define SOC_ASP_SMARTPA_AND_RO_STATE1_ADDR(base) ((base) + 0x7DC)
#define SOC_ASP_SMARTPA_RGC_RO_STATE3_ADDR(base) ((base) + 0x7E0)
#define SOC_ASP_SMARTPA_BGC_RO_STATE0_ADDR(base) ((base) + 0x7E4)
#define SOC_ASP_SMARTPA_BGC_RO_STATE1_ADDR(base) ((base) + 0x7E8)
#define SOC_ASP_SMARTPA_LSM_RO_STATE1_ADDR(base) ((base) + 0x7EC)
#define SOC_ASP_SMARTPA_LSM_RO_STATE2_ADDR(base) ((base) + 0x7F0)
#define SOC_ASP_SMARTPA_LSM_RO_STATE3_ADDR(base) ((base) + 0x7F4)
#define SOC_ASP_SMARTPA_LSM_RO_STATE4_ADDR(base) ((base) + 0x7F8)
#define SOC_ASP_SMARTPA_NDC_RO_STATE0_ADDR(base) ((base) + 0x7FC)
#define SOC_ASP_SMARTPA_SSD_CFG2_ADDR(base) ((base) + 0x800)
#define SOC_ASP_SMARTPA_LMT_CFG1_ADDR(base) ((base) + 0x804)
#define SOC_ASP_SMARTPA_LMT_CFG2_ADDR(base) ((base) + 0x808)
#define SOC_ASP_SMARTPA_LMT_CFG3_ADDR(base) ((base) + 0x80C)
#define SOC_ASP_SMARTPA_LMT_CFG4_ADDR(base) ((base) + 0x810)
#define SOC_ASP_SMARTPA_LTM_CFG0_ADDR(base) ((base) + 0x814)
#define SOC_ASP_SMARTPA_LTM_CFG1_ADDR(base) ((base) + 0x818)
#define SOC_ASP_SMARTPA_LTM_CFG2_ADDR(base) ((base) + 0x81C)
#define SOC_ASP_SMARTPA_LTM_CFG3_ADDR(base) ((base) + 0x820)
#define SOC_ASP_SMARTPA_LTM_CFG4_ADDR(base) ((base) + 0x824)
#define SOC_ASP_SMARTPA_LTM_CFG5_ADDR(base) ((base) + 0x828)
#define SOC_ASP_SMARTPA_LTM_CFG6_ADDR(base) ((base) + 0x82C)
#define SOC_ASP_SMARTPA_LTM_CFG7_ADDR(base) ((base) + 0x830)
#define SOC_ASP_SMARTPA_LTM_CFG8_ADDR(base) ((base) + 0x834)
#define SOC_ASP_SMARTPA_LTM_CFG9_ADDR(base) ((base) + 0x838)
#define SOC_ASP_SMARTPA_LTM_CFG10_ADDR(base) ((base) + 0x83C)
#define SOC_ASP_SMARTPA_LTM_CFG11_ADDR(base) ((base) + 0x840)
#define SOC_ASP_SMARTPA_LTM_CFG12_ADDR(base) ((base) + 0x844)
#define SOC_ASP_SMARTPA_LTM_CFG13_ADDR(base) ((base) + 0x848)
#define SOC_ASP_SMARTPA_LTM_CFG14_ADDR(base) ((base) + 0x84C)
#define SOC_ASP_SMARTPA_LTM_CFG15_ADDR(base) ((base) + 0x850)
#define SOC_ASP_SMARTPA_LTM_CFG16_ADDR(base) ((base) + 0x854)
#define SOC_ASP_SMARTPA_LTM_CFG17_ADDR(base) ((base) + 0x858)
#define SOC_ASP_SMARTPA_LTM_CFG18_ADDR(base) ((base) + 0x85C)
#define SOC_ASP_SMARTPA_LTM_CFG19_ADDR(base) ((base) + 0x860)
#define SOC_ASP_SMARTPA_LTM_CFG20_ADDR(base) ((base) + 0x864)
#define SOC_ASP_SMARTPA_LTM_CFG21_ADDR(base) ((base) + 0x868)
#define SOC_ASP_SMARTPA_LTM_CFG22_ADDR(base) ((base) + 0x86C)
#define SOC_ASP_SMARTPA_LTM_CFG23_ADDR(base) ((base) + 0x870)
#define SOC_ASP_SMARTPA_LTM_CFG24_ADDR(base) ((base) + 0x874)
#define SOC_ASP_SMARTPA_LTM_CFG25_ADDR(base) ((base) + 0x878)
#define SOC_ASP_SMARTPA_LTM_CFG26_ADDR(base) ((base) + 0x87C)
#define SOC_ASP_SMARTPA_LTM_CFG27_ADDR(base) ((base) + 0x880)
#define SOC_ASP_SMARTPA_LTM_CFG28_ADDR(base) ((base) + 0x884)
#define SOC_ASP_SMARTPA_LTM_CFG29_ADDR(base) ((base) + 0x888)
#define SOC_ASP_SMARTPA_LTM_CFG30_ADDR(base) ((base) + 0x88C)
#define SOC_ASP_SMARTPA_LTM_CFG31_ADDR(base) ((base) + 0x890)
#define SOC_ASP_SMARTPA_LTM_CFG32_ADDR(base) ((base) + 0x894)
#define SOC_ASP_SMARTPA_LTM_CFG33_ADDR(base) ((base) + 0x898)
#define SOC_ASP_SMARTPA_LTM_CFG34_ADDR(base) ((base) + 0x89C)
#define SOC_ASP_SMARTPA_LTM_CFG35_ADDR(base) ((base) + 0x8A0)
#define SOC_ASP_SMARTPA_LTM_CFG36_ADDR(base) ((base) + 0x8A4)
#define SOC_ASP_SMARTPA_LTM_CFG37_ADDR(base) ((base) + 0x8A8)
#define SOC_ASP_SMARTPA_LTM_CFG38_ADDR(base) ((base) + 0x8AC)
#define SOC_ASP_SMARTPA_LTM_CFG39_ADDR(base) ((base) + 0x8B0)
#define SOC_ASP_SMARTPA_LTM_CFG40_ADDR(base) ((base) + 0x8B4)
#define SOC_ASP_SMARTPA_LTM_CFG41_ADDR(base) ((base) + 0x8B8)
#define SOC_ASP_SMARTPA_LTM_CFG42_ADDR(base) ((base) + 0x8BC)
#define SOC_ASP_SMARTPA_LTM_CFG43_ADDR(base) ((base) + 0x8C0)
#define SOC_ASP_SMARTPA_LTM_CFG44_ADDR(base) ((base) + 0x8C4)
#define SOC_ASP_SMARTPA_LTM_CFG45_ADDR(base) ((base) + 0x8C8)
#define SOC_ASP_SMARTPA_LTM_CFG46_ADDR(base) ((base) + 0x8CC)
#define SOC_ASP_SMARTPA_LTM_CFG47_ADDR(base) ((base) + 0x8D0)
#define SOC_ASP_SMARTPA_LTM_CFG48_ADDR(base) ((base) + 0x8D4)
#define SOC_ASP_SMARTPA_LTM_CFG49_ADDR(base) ((base) + 0x8D8)
#define SOC_ASP_SMARTPA_LTM_CFG50_ADDR(base) ((base) + 0x8DC)
#define SOC_ASP_SMARTPA_LTM_CFG51_ADDR(base) ((base) + 0x8E0)
#define SOC_ASP_SMARTPA_LTM_CFG52_ADDR(base) ((base) + 0x8E4)
#define SOC_ASP_SMARTPA_LTM_CFG53_ADDR(base) ((base) + 0x8E8)
#define SOC_ASP_SMARTPA_LTM_CFG54_ADDR(base) ((base) + 0x8EC)
#define SOC_ASP_SMARTPA_LTM_CFG55_ADDR(base) ((base) + 0x8F0)
#define SOC_ASP_SMARTPA_LTM_CFG56_ADDR(base) ((base) + 0x8F4)
#define SOC_ASP_SMARTPA_LTM_CFG57_ADDR(base) ((base) + 0x8F8)
#define SOC_ASP_SMARTPA_LTM_CFG58_ADDR(base) ((base) + 0x8FC)
#define SOC_ASP_SMARTPA_LTM_CFG59_ADDR(base) ((base) + 0x900)
#define SOC_ASP_SMARTPA_LTM_CFG60_ADDR(base) ((base) + 0x904)
#define SOC_ASP_SMARTPA_LTM_CFG61_ADDR(base) ((base) + 0x908)
#define SOC_ASP_SMARTPA_LTM_CFG62_ADDR(base) ((base) + 0x90C)
#define SOC_ASP_SMARTPA_LTM_CFG63_ADDR(base) ((base) + 0x910)
#define SOC_ASP_SMARTPA_LTM_CFG64_ADDR(base) ((base) + 0x914)
#define SOC_ASP_SMARTPA_LTM_CFG65_ADDR(base) ((base) + 0x918)
#define SOC_ASP_SMARTPA_LTM_CFG66_ADDR(base) ((base) + 0x91C)
#define SOC_ASP_SMARTPA_LTM_CFG67_ADDR(base) ((base) + 0x920)
#define SOC_ASP_SMARTPA_LTM_CFG68_ADDR(base) ((base) + 0x924)
#define SOC_ASP_SMARTPA_LTM_CFG69_ADDR(base) ((base) + 0x928)
#define SOC_ASP_SMARTPA_LTM_CFG70_ADDR(base) ((base) + 0x92C)
#define SOC_ASP_SMARTPA_LTM_CFG71_ADDR(base) ((base) + 0x930)
#define SOC_ASP_SMARTPA_LTM_CFG72_ADDR(base) ((base) + 0x934)
#define SOC_ASP_SMARTPA_LTM_CFG73_ADDR(base) ((base) + 0x938)
#define SOC_ASP_SMARTPA_LTM_CFG74_ADDR(base) ((base) + 0x93C)
#define SOC_ASP_SMARTPA_LTM_CFG75_ADDR(base) ((base) + 0x940)
#define SOC_ASP_SMARTPA_LTM_CFG76_ADDR(base) ((base) + 0x944)
#define SOC_ASP_SMARTPA_LTM_CFG77_ADDR(base) ((base) + 0x948)
#define SOC_ASP_SMARTPA_LTM_CFG78_ADDR(base) ((base) + 0x94C)
#define SOC_ASP_SMARTPA_LTM_CFG79_ADDR(base) ((base) + 0x950)
#define SOC_ASP_SMARTPA_LTM_CFG80_ADDR(base) ((base) + 0x954)
#define SOC_ASP_SMARTPA_LTM_CFG81_ADDR(base) ((base) + 0x958)
#define SOC_ASP_SMARTPA_LTM_CFG82_ADDR(base) ((base) + 0x95C)
#define SOC_ASP_SMARTPA_LTM_CFG83_ADDR(base) ((base) + 0x960)
#define SOC_ASP_SMARTPA_LTM_CFG84_ADDR(base) ((base) + 0x964)
#define SOC_ASP_SMARTPA_LTM_CFG85_ADDR(base) ((base) + 0x968)
#define SOC_ASP_SMARTPA_LTM_CFG86_ADDR(base) ((base) + 0x96C)
#define SOC_ASP_SMARTPA_LTM_CFG87_ADDR(base) ((base) + 0x970)
#define SOC_ASP_SMARTPA_LTM_CFG88_ADDR(base) ((base) + 0x974)
#define SOC_ASP_SMARTPA_LTM_CFG89_ADDR(base) ((base) + 0x978)
#define SOC_ASP_SMARTPA_LTM_CFG90_ADDR(base) ((base) + 0x97C)
#define SOC_ASP_SMARTPA_LTM_CFG91_ADDR(base) ((base) + 0x980)
#define SOC_ASP_SMARTPA_LTM_CFG92_ADDR(base) ((base) + 0x984)
#define SOC_ASP_SMARTPA_LTM_CFG93_ADDR(base) ((base) + 0x988)
#define SOC_ASP_SMARTPA_LTM_CFG94_ADDR(base) ((base) + 0x98C)
#define SOC_ASP_SMARTPA_LTM_CFG95_ADDR(base) ((base) + 0x990)
#define SOC_ASP_SMARTPA_LTM_CFG96_ADDR(base) ((base) + 0x994)
#define SOC_ASP_SMARTPA_LTM_CFG97_ADDR(base) ((base) + 0x998)
#define SOC_ASP_SMARTPA_LTM_CFG98_ADDR(base) ((base) + 0x99C)
#define SOC_ASP_SMARTPA_LTM_CFG99_ADDR(base) ((base) + 0x9A0)
#define SOC_ASP_SMARTPA_LTM_CFG100_ADDR(base) ((base) + 0x9A4)
#define SOC_ASP_SMARTPA_LTM_CFG101_ADDR(base) ((base) + 0x9A8)
#define SOC_ASP_SMARTPA_LTM_CFG102_ADDR(base) ((base) + 0x9AC)
#define SOC_ASP_SMARTPA_LTM_CFG103_ADDR(base) ((base) + 0x9B0)
#define SOC_ASP_SMARTPA_LTM_CFG104_ADDR(base) ((base) + 0x9B4)
#define SOC_ASP_SMARTPA_LTM_CFG105_ADDR(base) ((base) + 0x9B8)
#define SOC_ASP_SMARTPA_LTM_CFG106_ADDR(base) ((base) + 0x9BC)
#define SOC_ASP_SMARTPA_LTM_CFG107_ADDR(base) ((base) + 0x9C0)
#define SOC_ASP_SMARTPA_LTM_CFG108_ADDR(base) ((base) + 0x9C4)
#define SOC_ASP_SMARTPA_LTM_CFG109_ADDR(base) ((base) + 0x9C8)
#define SOC_ASP_SMARTPA_LTM_CFG110_ADDR(base) ((base) + 0x9CC)
#define SOC_ASP_SMARTPA_LTM_CFG111_ADDR(base) ((base) + 0x9D0)
#define SOC_ASP_SMARTPA_LTM_CFG112_ADDR(base) ((base) + 0x9D4)
#define SOC_ASP_SMARTPA_LTM_CFG113_ADDR(base) ((base) + 0x9D8)
#define SOC_ASP_SMARTPA_LTM_CFG114_ADDR(base) ((base) + 0x9DC)
#define SOC_ASP_SMARTPA_LTM_CFG115_ADDR(base) ((base) + 0x9E0)
#define SOC_ASP_SMARTPA_LTM_CFG116_ADDR(base) ((base) + 0x9E4)
#define SOC_ASP_SMARTPA_LTM_CFG117_ADDR(base) ((base) + 0x9E8)
#define SOC_ASP_SMARTPA_LTM_CFG118_ADDR(base) ((base) + 0x9EC)
#define SOC_ASP_SMARTPA_LTM_CFG119_ADDR(base) ((base) + 0x9F0)
#define SOC_ASP_SMARTPA_LTM_CFG120_ADDR(base) ((base) + 0x9F4)
#define SOC_ASP_SMARTPA_LTM_CFG121_ADDR(base) ((base) + 0x9F8)
#define SOC_ASP_SMARTPA_LTM_CFG122_ADDR(base) ((base) + 0x9FC)
#define SOC_ASP_SMARTPA_BCN_CFG0_ADDR(base) ((base) + 0xA00)
#define SOC_ASP_SMARTPA_BCN_CFG1_ADDR(base) ((base) + 0xA04)
#define SOC_ASP_SMARTPA_BCN_CFG2_ADDR(base) ((base) + 0xA08)
#define SOC_ASP_SMARTPA_BCN_CFG3_ADDR(base) ((base) + 0xA0C)
#define SOC_ASP_SMARTPA_BCN_CFG4_ADDR(base) ((base) + 0xA10)
#define SOC_ASP_SMARTPA_BCN_CFG5_ADDR(base) ((base) + 0xA14)
#define SOC_ASP_SMARTPA_BCN_CFG6_ADDR(base) ((base) + 0xA18)
#define SOC_ASP_SMARTPA_BCN_CFG7_ADDR(base) ((base) + 0xA1C)
#define SOC_ASP_SMARTPA_BCN_CFG8_ADDR(base) ((base) + 0xA20)
#define SOC_ASP_SMARTPA_BCN_CFG9_ADDR(base) ((base) + 0xA24)
#define SOC_ASP_SMARTPA_BCN_CFG10_ADDR(base) ((base) + 0xA28)
#define SOC_ASP_SMARTPA_BCN_CFG11_ADDR(base) ((base) + 0xA2C)
#define SOC_ASP_SMARTPA_BCN_CFG12_ADDR(base) ((base) + 0xA30)
#define SOC_ASP_SMARTPA_BCN_CFG13_ADDR(base) ((base) + 0xA34)
#define SOC_ASP_SMARTPA_BCN_CFG14_ADDR(base) ((base) + 0xA38)
#define SOC_ASP_SMARTPA_BCN_CFG15_ADDR(base) ((base) + 0xA3C)
#define SOC_ASP_SMARTPA_BCN_CFG16_ADDR(base) ((base) + 0xA40)
#define SOC_ASP_SMARTPA_BCN_CFG17_ADDR(base) ((base) + 0xA44)
#define SOC_ASP_SMARTPA_BCN_CFG18_ADDR(base) ((base) + 0xA48)
#define SOC_ASP_SMARTPA_BCN_CFG19_ADDR(base) ((base) + 0xA4C)
#define SOC_ASP_SMARTPA_BCN_CFG20_ADDR(base) ((base) + 0xA50)
#define SOC_ASP_SMARTPA_BCN_CFG21_ADDR(base) ((base) + 0xA54)
#define SOC_ASP_SMARTPA_BCN_CFG22_ADDR(base) ((base) + 0xA58)
#define SOC_ASP_SMARTPA_BCN_CFG23_ADDR(base) ((base) + 0xA5C)
#define SOC_ASP_SMARTPA_BCN_CFG24_ADDR(base) ((base) + 0xA60)
#define SOC_ASP_SMARTPA_BCN_CFG25_ADDR(base) ((base) + 0xA64)
#define SOC_ASP_SMARTPA_BCN_CFG26_ADDR(base) ((base) + 0xA68)
#define SOC_ASP_SMARTPA_BCN_CFG27_ADDR(base) ((base) + 0xA6C)
#define SOC_ASP_SMARTPA_BCN_CFG28_ADDR(base) ((base) + 0xA70)
#define SOC_ASP_SMARTPA_BCN_CFG29_ADDR(base) ((base) + 0xA74)
#define SOC_ASP_SMARTPA_BCN_CFG30_ADDR(base) ((base) + 0xA78)
#define SOC_ASP_SMARTPA_BCN_CFG31_ADDR(base) ((base) + 0xA7C)
#define SOC_ASP_SMARTPA_BCN_CFG32_ADDR(base) ((base) + 0xA80)
#define SOC_ASP_SMARTPA_BCN_CFG33_ADDR(base) ((base) + 0xA84)
#define SOC_ASP_SMARTPA_BCN_CFG34_ADDR(base) ((base) + 0xA88)
#define SOC_ASP_SMARTPA_BCN_CFG35_ADDR(base) ((base) + 0xA8C)
#define SOC_ASP_SMARTPA_BCN_CFG36_ADDR(base) ((base) + 0xA90)
#define SOC_ASP_SMARTPA_BCN_CFG37_ADDR(base) ((base) + 0xA94)
#define SOC_ASP_SMARTPA_BCN_CFG38_ADDR(base) ((base) + 0xA98)
#define SOC_ASP_SMARTPA_BCN_CFG39_ADDR(base) ((base) + 0xA9C)
#define SOC_ASP_SMARTPA_BCN_CFG40_ADDR(base) ((base) + 0xAA0)
#define SOC_ASP_SMARTPA_BCN_CFG41_ADDR(base) ((base) + 0xAA4)
#define SOC_ASP_SMARTPA_BCN_CFG42_ADDR(base) ((base) + 0xAA8)
#define SOC_ASP_SMARTPA_BCN_CFG43_ADDR(base) ((base) + 0xAAC)
#define SOC_ASP_SMARTPA_BCN_CFG44_ADDR(base) ((base) + 0xAB0)
#define SOC_ASP_SMARTPA_BCN_CFG45_ADDR(base) ((base) + 0xAB4)
#define SOC_ASP_SMARTPA_BCN_CFG46_ADDR(base) ((base) + 0xAB8)
#define SOC_ASP_SMARTPA_BCN_CFG47_ADDR(base) ((base) + 0xABC)
#define SOC_ASP_SMARTPA_BCN_CFG48_ADDR(base) ((base) + 0xAC0)
#define SOC_ASP_SMARTPA_BCN_CFG49_ADDR(base) ((base) + 0xAC4)
#define SOC_ASP_SMARTPA_BCN_CFG50_ADDR(base) ((base) + 0xAC8)
#define SOC_ASP_SMARTPA_BCN_CFG51_ADDR(base) ((base) + 0xACC)
#define SOC_ASP_SMARTPA_BCN_CFG52_ADDR(base) ((base) + 0xAD0)
#define SOC_ASP_SMARTPA_BCN_CFG53_ADDR(base) ((base) + 0xAD4)
#define SOC_ASP_SMARTPA_BCN_CFG54_ADDR(base) ((base) + 0xAD8)
#define SOC_ASP_SMARTPA_BCN_CFG55_ADDR(base) ((base) + 0xADC)
#define SOC_ASP_SMARTPA_BCN_CFG56_ADDR(base) ((base) + 0xAE0)
#define SOC_ASP_SMARTPA_BCN_CFG57_ADDR(base) ((base) + 0xAE4)
#define SOC_ASP_SMARTPA_BCN_CFG58_ADDR(base) ((base) + 0xAE8)
#define SOC_ASP_SMARTPA_BCN_CFG59_ADDR(base) ((base) + 0xAEC)
#define SOC_ASP_SMARTPA_BCN_CFG60_ADDR(base) ((base) + 0xAF0)
#define SOC_ASP_SMARTPA_BCN_CFG61_ADDR(base) ((base) + 0xAF4)
#define SOC_ASP_SMARTPA_BCN_CFG62_ADDR(base) ((base) + 0xAF8)
#define SOC_ASP_SMARTPA_BCN_CFG63_ADDR(base) ((base) + 0xAFC)
#define SOC_ASP_SMARTPA_BCN_CFG64_ADDR(base) ((base) + 0xB00)
#define SOC_ASP_SMARTPA_BCN_CFG65_ADDR(base) ((base) + 0xB04)
#define SOC_ASP_SMARTPA_BCN_CFG66_ADDR(base) ((base) + 0xB08)
#define SOC_ASP_SMARTPA_BCN_CFG67_ADDR(base) ((base) + 0xB0C)
#define SOC_ASP_SMARTPA_BCN_CFG68_ADDR(base) ((base) + 0xB10)
#define SOC_ASP_SMARTPA_BCN_CFG69_ADDR(base) ((base) + 0xB14)
#define SOC_ASP_SMARTPA_BCN_CFG70_ADDR(base) ((base) + 0xB18)
#define SOC_ASP_SMARTPA_BCN_CFG71_ADDR(base) ((base) + 0xB1C)
#define SOC_ASP_SMARTPA_BCN_CFG72_ADDR(base) ((base) + 0xB20)
#define SOC_ASP_SMARTPA_BCN_CFG73_ADDR(base) ((base) + 0xB24)
#define SOC_ASP_SMARTPA_BCN_CFG74_ADDR(base) ((base) + 0xB28)
#define SOC_ASP_SMARTPA_BCN_CFG75_ADDR(base) ((base) + 0xB2C)
#define SOC_ASP_SMARTPA_BCN_CFG76_ADDR(base) ((base) + 0xB30)
#define SOC_ASP_SMARTPA_BCN_CFG77_ADDR(base) ((base) + 0xB34)
#define SOC_ASP_SMARTPA_BCN_CFG78_ADDR(base) ((base) + 0xB38)
#define SOC_ASP_SMARTPA_BCN_CFG79_ADDR(base) ((base) + 0xB3C)
#define SOC_ASP_SMARTPA_BCN_CFG80_ADDR(base) ((base) + 0xB40)
#define SOC_ASP_SMARTPA_BCN_CFG81_ADDR(base) ((base) + 0xB44)
#define SOC_ASP_SMARTPA_BCN_CFG82_ADDR(base) ((base) + 0xB48)
#define SOC_ASP_SMARTPA_BCN_CFG83_ADDR(base) ((base) + 0xB4C)
#define SOC_ASP_SMARTPA_BCN_CFG84_ADDR(base) ((base) + 0xB50)
#define SOC_ASP_SMARTPA_BCN_CFG85_ADDR(base) ((base) + 0xB54)
#define SOC_ASP_SMARTPA_BCN_CFG86_ADDR(base) ((base) + 0xB58)
#define SOC_ASP_SMARTPA_BCN_CFG87_ADDR(base) ((base) + 0xB5C)
#define SOC_ASP_SMARTPA_BCN_CFG88_ADDR(base) ((base) + 0xB60)
#define SOC_ASP_SMARTPA_BCN_CFG89_ADDR(base) ((base) + 0xB64)
#define SOC_ASP_SMARTPA_BCN_CFG90_ADDR(base) ((base) + 0xB68)
#define SOC_ASP_SMARTPA_BCN_CFG91_ADDR(base) ((base) + 0xB6C)
#define SOC_ASP_SMARTPA_BCN_CFG92_ADDR(base) ((base) + 0xB70)
#define SOC_ASP_SMARTPA_BCN_CFG93_ADDR(base) ((base) + 0xB74)
#define SOC_ASP_SMARTPA_BCN_CFG94_ADDR(base) ((base) + 0xB78)
#define SOC_ASP_SMARTPA_BCN_CFG95_ADDR(base) ((base) + 0xB7C)
#define SOC_ASP_SMARTPA_BCN_CFG96_ADDR(base) ((base) + 0xB80)
#define SOC_ASP_SMARTPA_BCN_CFG97_ADDR(base) ((base) + 0xB84)
#define SOC_ASP_SMARTPA_BCN_CFG98_ADDR(base) ((base) + 0xB88)
#define SOC_ASP_SMARTPA_BCN_CFG99_ADDR(base) ((base) + 0xB8C)
#define SOC_ASP_SMARTPA_BCN_CFG100_ADDR(base) ((base) + 0xB90)
#define SOC_ASP_SMARTPA_BCN_CFG101_ADDR(base) ((base) + 0xB94)
#define SOC_ASP_SMARTPA_BCN_CFG102_ADDR(base) ((base) + 0xB98)
#define SOC_ASP_SMARTPA_BCN_CFG103_ADDR(base) ((base) + 0xB9C)
#define SOC_ASP_SMARTPA_BCN_CFG104_ADDR(base) ((base) + 0xBA0)
#define SOC_ASP_SMARTPA_BCN_CFG105_ADDR(base) ((base) + 0xBA4)
#define SOC_ASP_SMARTPA_BCN_CFG106_ADDR(base) ((base) + 0xBA8)
#define SOC_ASP_SMARTPA_BCN_CFG107_ADDR(base) ((base) + 0xBAC)
#define SOC_ASP_SMARTPA_BCN_CFG108_ADDR(base) ((base) + 0xBB0)
#define SOC_ASP_SMARTPA_BCN_CFG109_ADDR(base) ((base) + 0xBB4)
#define SOC_ASP_SMARTPA_BCN_CFG110_ADDR(base) ((base) + 0xBB8)
#define SOC_ASP_SMARTPA_BCN_CFG111_ADDR(base) ((base) + 0xBBC)
#define SOC_ASP_SMARTPA_BCN_CFG112_ADDR(base) ((base) + 0xBC0)
#define SOC_ASP_SMARTPA_BCN_CFG113_ADDR(base) ((base) + 0xBC4)
#define SOC_ASP_SMARTPA_BCN_CFG114_ADDR(base) ((base) + 0xBC8)
#define SOC_ASP_SMARTPA_BCN_CFG115_ADDR(base) ((base) + 0xBCC)
#define SOC_ASP_SMARTPA_BCN_CFG116_ADDR(base) ((base) + 0xBD0)
#define SOC_ASP_SMARTPA_BCN_CFG117_ADDR(base) ((base) + 0xBD4)
#define SOC_ASP_SMARTPA_BCN_CFG118_ADDR(base) ((base) + 0xBD8)
#define SOC_ASP_SMARTPA_BCN_CFG119_ADDR(base) ((base) + 0xBDC)
#define SOC_ASP_SMARTPA_BCN_CFG120_ADDR(base) ((base) + 0xBE0)
#define SOC_ASP_SMARTPA_BCN_CFG121_ADDR(base) ((base) + 0xBE4)
#define SOC_ASP_SMARTPA_BCN_CFG122_ADDR(base) ((base) + 0xBE8)
#define SOC_ASP_SMARTPA_BCN_CFG123_ADDR(base) ((base) + 0xBEC)
#define SOC_ASP_SMARTPA_BCN_CFG124_ADDR(base) ((base) + 0xBF0)
#define SOC_ASP_SMARTPA_BCN_CFG125_ADDR(base) ((base) + 0xBF4)
#define SOC_ASP_SMARTPA_BCN_CFG126_ADDR(base) ((base) + 0xBF8)
#define SOC_ASP_SMARTPA_ECP_CFG87_ADDR(base) ((base) + 0xBFC)
#define SOC_ASP_SMARTPA_ECP_CFG88_ADDR(base) ((base) + 0xC00)
#define SOC_ASP_SMARTPA_ECP_CFG89_ADDR(base) ((base) + 0xC04)
#define SOC_ASP_SMARTPA_FIR_CFG0_ADDR(base) ((base) + 0xC08)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pre_process_bypass : 1;
        unsigned int geq_bypass : 1;
        unsigned int drc_bypass : 1;
        unsigned int ecp_bypass : 1;
        unsigned int pow_bypass : 1;
        unsigned int tep_bypass : 1;
        unsigned int and_bypass : 1;
        unsigned int rgc_bypass : 1;
        unsigned int bgc_bypass : 1;
        unsigned int sdc_bypass : 1;
        unsigned int ndc_bypass : 1;
        unsigned int lmt_bypass : 1;
        unsigned int plt_bypass : 1;
        unsigned int ssd_bypass : 1;
        unsigned int idf_bypass : 1;
        unsigned int lsm_bypass : 1;
        unsigned int pre_process_cg_en : 1;
        unsigned int geq_cg_en : 1;
        unsigned int drc_cg_en : 1;
        unsigned int ecp_cg_en : 1;
        unsigned int pow_cg_en : 1;
        unsigned int tep_cg_en : 1;
        unsigned int and_cg_en : 1;
        unsigned int rgc_cg_en : 1;
        unsigned int bgc_cg_en : 1;
        unsigned int sdc_cg_en : 1;
        unsigned int ndc_cg_en : 1;
        unsigned int lmt_cg_en : 1;
        unsigned int plt_cg_en : 1;
        unsigned int ssd_cg_en : 1;
        unsigned int idf_cg_en : 1;
        unsigned int lsm_cg_en : 1;
    } reg;
} SOC_ASP_SMARTPA_BYPASS_CFG_UNION;
#endif
#define SOC_ASP_SMARTPA_BYPASS_CFG_pre_process_bypass_START (0)
#define SOC_ASP_SMARTPA_BYPASS_CFG_pre_process_bypass_END (0)
#define SOC_ASP_SMARTPA_BYPASS_CFG_geq_bypass_START (1)
#define SOC_ASP_SMARTPA_BYPASS_CFG_geq_bypass_END (1)
#define SOC_ASP_SMARTPA_BYPASS_CFG_drc_bypass_START (2)
#define SOC_ASP_SMARTPA_BYPASS_CFG_drc_bypass_END (2)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ecp_bypass_START (3)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ecp_bypass_END (3)
#define SOC_ASP_SMARTPA_BYPASS_CFG_pow_bypass_START (4)
#define SOC_ASP_SMARTPA_BYPASS_CFG_pow_bypass_END (4)
#define SOC_ASP_SMARTPA_BYPASS_CFG_tep_bypass_START (5)
#define SOC_ASP_SMARTPA_BYPASS_CFG_tep_bypass_END (5)
#define SOC_ASP_SMARTPA_BYPASS_CFG_and_bypass_START (6)
#define SOC_ASP_SMARTPA_BYPASS_CFG_and_bypass_END (6)
#define SOC_ASP_SMARTPA_BYPASS_CFG_rgc_bypass_START (7)
#define SOC_ASP_SMARTPA_BYPASS_CFG_rgc_bypass_END (7)
#define SOC_ASP_SMARTPA_BYPASS_CFG_bgc_bypass_START (8)
#define SOC_ASP_SMARTPA_BYPASS_CFG_bgc_bypass_END (8)
#define SOC_ASP_SMARTPA_BYPASS_CFG_sdc_bypass_START (9)
#define SOC_ASP_SMARTPA_BYPASS_CFG_sdc_bypass_END (9)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ndc_bypass_START (10)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ndc_bypass_END (10)
#define SOC_ASP_SMARTPA_BYPASS_CFG_lmt_bypass_START (11)
#define SOC_ASP_SMARTPA_BYPASS_CFG_lmt_bypass_END (11)
#define SOC_ASP_SMARTPA_BYPASS_CFG_plt_bypass_START (12)
#define SOC_ASP_SMARTPA_BYPASS_CFG_plt_bypass_END (12)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ssd_bypass_START (13)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ssd_bypass_END (13)
#define SOC_ASP_SMARTPA_BYPASS_CFG_idf_bypass_START (14)
#define SOC_ASP_SMARTPA_BYPASS_CFG_idf_bypass_END (14)
#define SOC_ASP_SMARTPA_BYPASS_CFG_lsm_bypass_START (15)
#define SOC_ASP_SMARTPA_BYPASS_CFG_lsm_bypass_END (15)
#define SOC_ASP_SMARTPA_BYPASS_CFG_pre_process_cg_en_START (16)
#define SOC_ASP_SMARTPA_BYPASS_CFG_pre_process_cg_en_END (16)
#define SOC_ASP_SMARTPA_BYPASS_CFG_geq_cg_en_START (17)
#define SOC_ASP_SMARTPA_BYPASS_CFG_geq_cg_en_END (17)
#define SOC_ASP_SMARTPA_BYPASS_CFG_drc_cg_en_START (18)
#define SOC_ASP_SMARTPA_BYPASS_CFG_drc_cg_en_END (18)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ecp_cg_en_START (19)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ecp_cg_en_END (19)
#define SOC_ASP_SMARTPA_BYPASS_CFG_pow_cg_en_START (20)
#define SOC_ASP_SMARTPA_BYPASS_CFG_pow_cg_en_END (20)
#define SOC_ASP_SMARTPA_BYPASS_CFG_tep_cg_en_START (21)
#define SOC_ASP_SMARTPA_BYPASS_CFG_tep_cg_en_END (21)
#define SOC_ASP_SMARTPA_BYPASS_CFG_and_cg_en_START (22)
#define SOC_ASP_SMARTPA_BYPASS_CFG_and_cg_en_END (22)
#define SOC_ASP_SMARTPA_BYPASS_CFG_rgc_cg_en_START (23)
#define SOC_ASP_SMARTPA_BYPASS_CFG_rgc_cg_en_END (23)
#define SOC_ASP_SMARTPA_BYPASS_CFG_bgc_cg_en_START (24)
#define SOC_ASP_SMARTPA_BYPASS_CFG_bgc_cg_en_END (24)
#define SOC_ASP_SMARTPA_BYPASS_CFG_sdc_cg_en_START (25)
#define SOC_ASP_SMARTPA_BYPASS_CFG_sdc_cg_en_END (25)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ndc_cg_en_START (26)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ndc_cg_en_END (26)
#define SOC_ASP_SMARTPA_BYPASS_CFG_lmt_cg_en_START (27)
#define SOC_ASP_SMARTPA_BYPASS_CFG_lmt_cg_en_END (27)
#define SOC_ASP_SMARTPA_BYPASS_CFG_plt_cg_en_START (28)
#define SOC_ASP_SMARTPA_BYPASS_CFG_plt_cg_en_END (28)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ssd_cg_en_START (29)
#define SOC_ASP_SMARTPA_BYPASS_CFG_ssd_cg_en_END (29)
#define SOC_ASP_SMARTPA_BYPASS_CFG_idf_cg_en_START (30)
#define SOC_ASP_SMARTPA_BYPASS_CFG_idf_cg_en_END (30)
#define SOC_ASP_SMARTPA_BYPASS_CFG_lsm_cg_en_START (31)
#define SOC_ASP_SMARTPA_BYPASS_CFG_lsm_cg_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spa_v_data_sel : 4;
        unsigned int spa_i_data_sel : 4;
        unsigned int spa_vbat_data_sel : 4;
        unsigned int params_passthrough_en : 1;
        unsigned int cross_fade_start : 1;
        unsigned int cross_fade_end : 1;
        unsigned int smartpa_protect_clk_rst_en : 1;
        unsigned int pre_process_clk_rst_en : 1;
        unsigned int geq_clk_rst_en : 1;
        unsigned int drc_clk_rst_en : 1;
        unsigned int ecp_clk_rst_en : 1;
        unsigned int pow_clk_rst_en : 1;
        unsigned int tep_clk_rst_en : 1;
        unsigned int and_clk_rst_en : 1;
        unsigned int rgc_clk_rst_en : 1;
        unsigned int bgc_clk_rst_en : 1;
        unsigned int sdc_clk_rst_en : 1;
        unsigned int ndc_clk_rst_en : 1;
        unsigned int lmt_clk_rst_en : 1;
        unsigned int plt_clk_rst_en : 1;
        unsigned int ssd_clk_rst_en : 1;
        unsigned int idf_clk_rst_en : 1;
        unsigned int lsm_clk_rst_en : 1;
    } reg;
} SOC_ASP_SMARTPA_IV_DATA_SEL_UNION;
#endif
#define SOC_ASP_SMARTPA_IV_DATA_SEL_spa_v_data_sel_START (0)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_spa_v_data_sel_END (3)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_spa_i_data_sel_START (4)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_spa_i_data_sel_END (7)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_spa_vbat_data_sel_START (8)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_spa_vbat_data_sel_END (11)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_params_passthrough_en_START (12)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_params_passthrough_en_END (12)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_cross_fade_start_START (13)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_cross_fade_start_END (13)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_cross_fade_end_START (14)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_cross_fade_end_END (14)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_smartpa_protect_clk_rst_en_START (15)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_smartpa_protect_clk_rst_en_END (15)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_pre_process_clk_rst_en_START (16)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_pre_process_clk_rst_en_END (16)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_geq_clk_rst_en_START (17)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_geq_clk_rst_en_END (17)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_drc_clk_rst_en_START (18)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_drc_clk_rst_en_END (18)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_ecp_clk_rst_en_START (19)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_ecp_clk_rst_en_END (19)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_pow_clk_rst_en_START (20)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_pow_clk_rst_en_END (20)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_tep_clk_rst_en_START (21)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_tep_clk_rst_en_END (21)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_and_clk_rst_en_START (22)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_and_clk_rst_en_END (22)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_rgc_clk_rst_en_START (23)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_rgc_clk_rst_en_END (23)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_bgc_clk_rst_en_START (24)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_bgc_clk_rst_en_END (24)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_sdc_clk_rst_en_START (25)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_sdc_clk_rst_en_END (25)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_ndc_clk_rst_en_START (26)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_ndc_clk_rst_en_END (26)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_lmt_clk_rst_en_START (27)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_lmt_clk_rst_en_END (27)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_plt_clk_rst_en_START (28)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_plt_clk_rst_en_END (28)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_ssd_clk_rst_en_START (29)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_ssd_clk_rst_en_END (29)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_idf_clk_rst_en_START (30)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_idf_clk_rst_en_END (30)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_lsm_clk_rst_en_START (31)
#define SOC_ASP_SMARTPA_IV_DATA_SEL_lsm_clk_rst_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_pilottone_clken : 1;
        unsigned int reserved_0 : 1;
        unsigned int cfg_pre_lps_bypass : 1;
        unsigned int cfg_pre_hps_bypass : 1;
        unsigned int cfg_pre_pga_bypass : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG0_cfg_pre_pilottone_clken_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG0_cfg_pre_pilottone_clken_END (0)
#define SOC_ASP_SMARTPA_PRE_CFG0_cfg_pre_lps_bypass_START (2)
#define SOC_ASP_SMARTPA_PRE_CFG0_cfg_pre_lps_bypass_END (2)
#define SOC_ASP_SMARTPA_PRE_CFG0_cfg_pre_hps_bypass_START (3)
#define SOC_ASP_SMARTPA_PRE_CFG0_cfg_pre_hps_bypass_END (3)
#define SOC_ASP_SMARTPA_PRE_CFG0_cfg_pre_pga_bypass_START (4)
#define SOC_ASP_SMARTPA_PRE_CFG0_cfg_pre_pga_bypass_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_pga_gain : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG1_cfg_pre_pga_gain_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG1_cfg_pre_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_process_lps_order : 2;
        unsigned int cfg_pre_process_hps_order : 2;
        unsigned int cfg_pre_hps_iir_6th_sel : 3;
        unsigned int reserved : 25;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG2_cfg_pre_process_lps_order_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG2_cfg_pre_process_lps_order_END (1)
#define SOC_ASP_SMARTPA_PRE_CFG2_cfg_pre_process_hps_order_START (2)
#define SOC_ASP_SMARTPA_PRE_CFG2_cfg_pre_process_hps_order_END (3)
#define SOC_ASP_SMARTPA_PRE_CFG2_cfg_pre_hps_iir_6th_sel_START (4)
#define SOC_ASP_SMARTPA_PRE_CFG2_cfg_pre_hps_iir_6th_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_lps_bq_b0 : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG3_cfg_pre_lps_bq_b0_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG3_cfg_pre_lps_bq_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_lps_bq_b1 : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG4_cfg_pre_lps_bq_b1_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG4_cfg_pre_lps_bq_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_lps_bq_b2 : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG5_cfg_pre_lps_bq_b2_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG5_cfg_pre_lps_bq_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_lps_bq_a1 : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG6_cfg_pre_lps_bq_a1_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG6_cfg_pre_lps_bq_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_lps_bq_a2 : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG7_cfg_pre_lps_bq_a2_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG7_cfg_pre_lps_bq_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_hps_bq_b0 : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG8_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG8_cfg_pre_hps_bq_b0_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG8_cfg_pre_hps_bq_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_hps_bq_b1 : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG9_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG9_cfg_pre_hps_bq_b1_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG9_cfg_pre_hps_bq_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_hps_bq_b2 : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG10_cfg_pre_hps_bq_b2_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG10_cfg_pre_hps_bq_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_hps_bq_a1 : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG11_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG11_cfg_pre_hps_bq_a1_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG11_cfg_pre_hps_bq_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_hps_bq_a2 : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG12_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG12_cfg_pre_hps_bq_a2_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG12_cfg_pre_hps_bq_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pre_pilotone_ength : 32;
    } reg;
} SOC_ASP_SMARTPA_PRE_CFG13_UNION;
#endif
#define SOC_ASP_SMARTPA_PRE_CFG13_cfg_pre_pilotone_ength_START (0)
#define SOC_ASP_SMARTPA_PRE_CFG13_cfg_pre_pilotone_ength_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad0_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG0_cfg_geq_biquad0_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG0_cfg_geq_biquad0_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad0_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG1_cfg_geq_biquad0_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG1_cfg_geq_biquad0_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad0_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG2_cfg_geq_biquad0_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG2_cfg_geq_biquad0_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad0_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG3_cfg_geq_biquad0_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG3_cfg_geq_biquad0_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad0_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG4_cfg_geq_biquad0_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG4_cfg_geq_biquad0_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad1_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG5_cfg_geq_biquad1_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG5_cfg_geq_biquad1_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad1_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG6_cfg_geq_biquad1_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG6_cfg_geq_biquad1_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad1_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG7_cfg_geq_biquad1_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG7_cfg_geq_biquad1_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad1_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG8_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG8_cfg_geq_biquad1_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG8_cfg_geq_biquad1_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad1_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG9_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG9_cfg_geq_biquad1_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG9_cfg_geq_biquad1_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad2_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG10_cfg_geq_biquad2_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG10_cfg_geq_biquad2_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad2_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG11_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG11_cfg_geq_biquad2_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG11_cfg_geq_biquad2_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad2_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG12_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG12_cfg_geq_biquad2_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG12_cfg_geq_biquad2_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad2_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG13_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG13_cfg_geq_biquad2_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG13_cfg_geq_biquad2_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad2_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG14_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG14_cfg_geq_biquad2_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG14_cfg_geq_biquad2_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad3_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG15_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG15_cfg_geq_biquad3_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG15_cfg_geq_biquad3_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad3_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG16_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG16_cfg_geq_biquad3_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG16_cfg_geq_biquad3_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad3_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG17_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG17_cfg_geq_biquad3_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG17_cfg_geq_biquad3_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad3_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG18_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG18_cfg_geq_biquad3_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG18_cfg_geq_biquad3_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad3_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG19_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG19_cfg_geq_biquad3_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG19_cfg_geq_biquad3_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad4_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG20_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG20_cfg_geq_biquad4_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG20_cfg_geq_biquad4_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad4_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG21_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG21_cfg_geq_biquad4_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG21_cfg_geq_biquad4_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad4_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG22_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG22_cfg_geq_biquad4_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG22_cfg_geq_biquad4_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad4_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG23_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG23_cfg_geq_biquad4_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG23_cfg_geq_biquad4_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad4_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG24_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG24_cfg_geq_biquad4_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG24_cfg_geq_biquad4_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad5_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG25_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG25_cfg_geq_biquad5_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG25_cfg_geq_biquad5_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad5_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG26_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG26_cfg_geq_biquad5_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG26_cfg_geq_biquad5_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad5_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG27_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG27_cfg_geq_biquad5_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG27_cfg_geq_biquad5_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad5_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG28_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG28_cfg_geq_biquad5_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG28_cfg_geq_biquad5_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad5_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG29_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG29_cfg_geq_biquad5_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG29_cfg_geq_biquad5_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad6_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG30_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG30_cfg_geq_biquad6_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG30_cfg_geq_biquad6_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad6_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG31_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG31_cfg_geq_biquad6_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG31_cfg_geq_biquad6_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad6_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG32_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG32_cfg_geq_biquad6_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG32_cfg_geq_biquad6_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad6_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG33_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG33_cfg_geq_biquad6_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG33_cfg_geq_biquad6_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad6_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG34_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG34_cfg_geq_biquad6_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG34_cfg_geq_biquad6_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad7_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG35_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG35_cfg_geq_biquad7_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG35_cfg_geq_biquad7_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad7_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG36_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG36_cfg_geq_biquad7_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG36_cfg_geq_biquad7_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad7_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG37_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG37_cfg_geq_biquad7_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG37_cfg_geq_biquad7_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad7_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG38_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG38_cfg_geq_biquad7_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG38_cfg_geq_biquad7_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad7_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG39_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG39_cfg_geq_biquad7_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG39_cfg_geq_biquad7_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad8_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG40_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG40_cfg_geq_biquad8_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG40_cfg_geq_biquad8_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad8_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG41_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG41_cfg_geq_biquad8_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG41_cfg_geq_biquad8_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad8_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG42_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG42_cfg_geq_biquad8_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG42_cfg_geq_biquad8_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad8_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG43_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG43_cfg_geq_biquad8_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG43_cfg_geq_biquad8_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad8_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG44_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG44_cfg_geq_biquad8_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG44_cfg_geq_biquad8_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad9_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG45_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG45_cfg_geq_biquad9_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG45_cfg_geq_biquad9_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad9_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG46_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG46_cfg_geq_biquad9_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG46_cfg_geq_biquad9_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad9_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG47_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG47_cfg_geq_biquad9_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG47_cfg_geq_biquad9_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad9_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG48_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG48_cfg_geq_biquad9_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG48_cfg_geq_biquad9_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad9_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG49_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG49_cfg_geq_biquad9_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG49_cfg_geq_biquad9_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad10_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG50_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG50_cfg_geq_biquad10_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG50_cfg_geq_biquad10_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad10_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG51_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG51_cfg_geq_biquad10_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG51_cfg_geq_biquad10_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad10_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG52_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG52_cfg_geq_biquad10_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG52_cfg_geq_biquad10_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad10_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG53_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG53_cfg_geq_biquad10_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG53_cfg_geq_biquad10_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad10_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG54_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG54_cfg_geq_biquad10_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG54_cfg_geq_biquad10_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad11_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG55_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG55_cfg_geq_biquad11_coefa1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG55_cfg_geq_biquad11_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad11_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG56_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG56_cfg_geq_biquad11_coefa2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG56_cfg_geq_biquad11_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad11_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG57_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG57_cfg_geq_biquad11_coefb0_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG57_cfg_geq_biquad11_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad11_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG58_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG58_cfg_geq_biquad11_coefb1_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG58_cfg_geq_biquad11_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_geq_biquad11_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_GEQ_CFG59_UNION;
#endif
#define SOC_ASP_SMARTPA_GEQ_CFG59_cfg_geq_biquad11_coefb2_START (0)
#define SOC_ASP_SMARTPA_GEQ_CFG59_cfg_geq_biquad11_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b0_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG0_cfg_drc_b0_coefa1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG0_cfg_drc_b0_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b0_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG1_cfg_drc_b0_coefa2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG1_cfg_drc_b0_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b0_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG2_cfg_drc_b0_coefb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG2_cfg_drc_b0_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b0_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG3_cfg_drc_b0_coefb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG3_cfg_drc_b0_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b0_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG4_cfg_drc_b0_coefb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG4_cfg_drc_b0_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b1_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG5_cfg_drc_b1_coefa1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG5_cfg_drc_b1_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b1_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG6_cfg_drc_b1_coefa2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG6_cfg_drc_b1_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b1_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG7_cfg_drc_b1_coefb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG7_cfg_drc_b1_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b1_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG8_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG8_cfg_drc_b1_coefb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG8_cfg_drc_b1_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b1_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG9_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG9_cfg_drc_b1_coefb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG9_cfg_drc_b1_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b2_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG10_cfg_drc_b2_coefa1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG10_cfg_drc_b2_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b2_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG11_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG11_cfg_drc_b2_coefa2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG11_cfg_drc_b2_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b2_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG12_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG12_cfg_drc_b2_coefb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG12_cfg_drc_b2_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b2_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG13_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG13_cfg_drc_b2_coefb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG13_cfg_drc_b2_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b2_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG14_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG14_cfg_drc_b2_coefb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG14_cfg_drc_b2_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b3_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG15_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG15_cfg_drc_b3_coefa1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG15_cfg_drc_b3_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b3_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG16_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG16_cfg_drc_b3_coefa2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG16_cfg_drc_b3_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b3_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG17_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG17_cfg_drc_b3_coefb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG17_cfg_drc_b3_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b3_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG18_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG18_cfg_drc_b3_coefb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG18_cfg_drc_b3_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b3_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG19_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG19_cfg_drc_b3_coefb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG19_cfg_drc_b3_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b4_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG20_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG20_cfg_drc_b4_coefa1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG20_cfg_drc_b4_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b4_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG21_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG21_cfg_drc_b4_coefa2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG21_cfg_drc_b4_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b4_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG22_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG22_cfg_drc_b4_coefb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG22_cfg_drc_b4_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b4_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG23_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG23_cfg_drc_b4_coefb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG23_cfg_drc_b4_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b4_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG24_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG24_cfg_drc_b4_coefb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG24_cfg_drc_b4_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b5_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG25_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG25_cfg_drc_b5_coefa1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG25_cfg_drc_b5_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b5_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG26_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG26_cfg_drc_b5_coefa2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG26_cfg_drc_b5_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b5_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG27_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG27_cfg_drc_b5_coefb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG27_cfg_drc_b5_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b5_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG28_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG28_cfg_drc_b5_coefb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG28_cfg_drc_b5_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b5_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG29_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG29_cfg_drc_b5_coefb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG29_cfg_drc_b5_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b6_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG30_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG30_cfg_drc_b6_coefa1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG30_cfg_drc_b6_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b6_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG31_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG31_cfg_drc_b6_coefa2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG31_cfg_drc_b6_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b6_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG32_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG32_cfg_drc_b6_coefb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG32_cfg_drc_b6_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b6_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG33_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG33_cfg_drc_b6_coefb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG33_cfg_drc_b6_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b6_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG34_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG34_cfg_drc_b6_coefb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG34_cfg_drc_b6_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b7_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG35_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG35_cfg_drc_b7_coefa1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG35_cfg_drc_b7_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b7_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG36_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG36_cfg_drc_b7_coefa2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG36_cfg_drc_b7_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b7_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG37_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG37_cfg_drc_b7_coefb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG37_cfg_drc_b7_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b7_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG38_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG38_cfg_drc_b7_coefb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG38_cfg_drc_b7_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_b7_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG39_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG39_cfg_drc_b7_coefb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG39_cfg_drc_b7_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_thredb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG40_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG40_cfg_drc_thredb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG40_cfg_drc_thredb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_thredb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG41_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG41_cfg_drc_thredb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG41_cfg_drc_thredb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_thredb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG42_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG42_cfg_drc_thredb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG42_cfg_drc_thredb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_noisegateb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG43_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG43_cfg_drc_noisegateb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG43_cfg_drc_noisegateb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_noisegateb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG44_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG44_cfg_drc_noisegateb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG44_cfg_drc_noisegateb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_noisegateb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG45_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG45_cfg_drc_noisegateb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG45_cfg_drc_noisegateb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_softkneeb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG46_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG46_cfg_drc_softkneeb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG46_cfg_drc_softkneeb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_softkneeb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG47_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG47_cfg_drc_softkneeb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG47_cfg_drc_softkneeb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_softkneeb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG48_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG48_cfg_drc_softkneeb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG48_cfg_drc_softkneeb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_invsoftkneeb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG49_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG49_cfg_drc_invsoftkneeb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG49_cfg_drc_invsoftkneeb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_invsoftkneeb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG50_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG50_cfg_drc_invsoftkneeb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG50_cfg_drc_invsoftkneeb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_invsoftkneeb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG51_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG51_cfg_drc_invsoftkneeb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG51_cfg_drc_invsoftkneeb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_makeupb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG52_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG52_cfg_drc_makeupb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG52_cfg_drc_makeupb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_makeupb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG53_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG53_cfg_drc_makeupb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG53_cfg_drc_makeupb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_makeupb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG54_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG54_cfg_drc_makeupb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG54_cfg_drc_makeupb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_ratiob0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG55_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG55_cfg_drc_ratiob0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG55_cfg_drc_ratiob0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_ratiob1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG56_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG56_cfg_drc_ratiob1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG56_cfg_drc_ratiob1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_ratiob2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG57_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG57_cfg_drc_ratiob2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG57_cfg_drc_ratiob2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_attackb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG58_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG58_cfg_drc_attackb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG58_cfg_drc_attackb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_attackb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG59_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG59_cfg_drc_attackb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG59_cfg_drc_attackb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_attackb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG60_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG60_cfg_drc_attackb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG60_cfg_drc_attackb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_releaseb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG61_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG61_cfg_drc_releaseb0_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG61_cfg_drc_releaseb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_releaseb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG62_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG62_cfg_drc_releaseb1_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG62_cfg_drc_releaseb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_drc_releaseb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_DRC_CFG63_UNION;
#endif
#define SOC_ASP_SMARTPA_DRC_CFG63_cfg_drc_releaseb2_START (0)
#define SOC_ASP_SMARTPA_DRC_CFG63_cfg_drc_releaseb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ssd_tonethr : 32;
    } reg;
} SOC_ASP_SMARTPA_SSD_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_SSD_CFG0_cfg_ssd_tonethr_START (0)
#define SOC_ASP_SMARTPA_SSD_CFG0_cfg_ssd_tonethr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_bq_coef0 : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG0_cfg_idf_bq_coef0_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG0_cfg_idf_bq_coef0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_bq_coef1 : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG1_cfg_idf_bq_coef1_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG1_cfg_idf_bq_coef1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_bq_coef2 : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG2_cfg_idf_bq_coef2_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG2_cfg_idf_bq_coef2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_bq_coef3 : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG3_cfg_idf_bq_coef3_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG3_cfg_idf_bq_coef3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_bq_coef4 : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG4_cfg_idf_bq_coef4_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG4_cfg_idf_bq_coef4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_w1 : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG0_cfg_pow_w1_START (0)
#define SOC_ASP_SMARTPA_POW_CFG0_cfg_pow_w1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_tlim_low : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG2_cfg_pow_tlim_low_START (0)
#define SOC_ASP_SMARTPA_POW_CFG2_cfg_pow_tlim_low_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_tlim_mid : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG3_cfg_pow_tlim_mid_START (0)
#define SOC_ASP_SMARTPA_POW_CFG3_cfg_pow_tlim_mid_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_tlim_high : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG4_cfg_pow_tlim_high_START (0)
#define SOC_ASP_SMARTPA_POW_CFG4_cfg_pow_tlim_high_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_plim_low : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG5_cfg_pow_plim_low_START (0)
#define SOC_ASP_SMARTPA_POW_CFG5_cfg_pow_plim_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_plim_mid : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG6_cfg_pow_plim_mid_START (0)
#define SOC_ASP_SMARTPA_POW_CFG6_cfg_pow_plim_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_plim_high : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG7_cfg_pow_plim_high_START (0)
#define SOC_ASP_SMARTPA_POW_CFG7_cfg_pow_plim_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_plim_rate1 : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG8_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG8_cfg_pow_plim_rate1_START (0)
#define SOC_ASP_SMARTPA_POW_CFG8_cfg_pow_plim_rate1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_plim_rate2 : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG9_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG9_cfg_pow_plim_rate2_START (0)
#define SOC_ASP_SMARTPA_POW_CFG9_cfg_pow_plim_rate2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_plim_gain1 : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG10_cfg_pow_plim_gain1_START (0)
#define SOC_ASP_SMARTPA_POW_CFG10_cfg_pow_plim_gain1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_plim_gain2 : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG11_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG11_cfg_pow_plim_gain2_START (0)
#define SOC_ASP_SMARTPA_POW_CFG11_cfg_pow_plim_gain2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pow_att0 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_SMARTPA_POW_CFG12_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_CFG12_cfg_pow_att0_START (0)
#define SOC_ASP_SMARTPA_POW_CFG12_cfg_pow_att0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_damagetime : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG0_cfg_tep_damagetime_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG0_cfg_tep_damagetime_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_re_settime : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG1_cfg_tep_re_settime_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG1_cfg_tep_re_settime_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_thigh : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG2_cfg_tep_thigh_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG2_cfg_tep_thigh_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_tmid : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG3_cfg_tep_tmid_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG3_cfg_tep_tmid_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_tlow : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG4_cfg_tep_tlow_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG4_cfg_tep_tlow_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_t_protectgain0 : 32;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG5_cfg_tep_t_protectgain0_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG5_cfg_tep_t_protectgain0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_t_protectgain1 : 32;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG6_cfg_tep_t_protectgain1_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG6_cfg_tep_t_protectgain1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_t_protectgain2 : 32;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG7_cfg_tep_t_protectgain2_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG7_cfg_tep_t_protectgain2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_t_att_seg0 : 32;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG8_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG8_cfg_tep_t_att_seg0_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG8_cfg_tep_t_att_seg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_t_att_seg1 : 32;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG9_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG9_cfg_tep_t_att_seg1_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG9_cfg_tep_t_att_seg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_t_att_seg2 : 32;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG10_cfg_tep_t_att_seg2_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG10_cfg_tep_t_att_seg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_tre_high : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG11_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG11_cfg_tep_tre_high_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG11_cfg_tep_tre_high_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_tre_mid : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG12_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG12_cfg_tep_tre_mid_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG12_cfg_tep_tre_mid_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_tre_low : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG13_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG13_cfg_tep_tre_low_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG13_cfg_tep_tre_low_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tep_t_rel : 32;
    } reg;
} SOC_ASP_SMARTPA_TEP_CFG14_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_CFG14_cfg_tep_t_rel_START (0)
#define SOC_ASP_SMARTPA_TEP_CFG14_cfg_tep_t_rel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_and_detect_time : 32;
    } reg;
} SOC_ASP_SMARTPA_AND_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_AND_CFG0_cfg_and_detect_time_START (0)
#define SOC_ASP_SMARTPA_AND_CFG0_cfg_and_detect_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_and_f0_anm_gain : 32;
    } reg;
} SOC_ASP_SMARTPA_AND_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_AND_CFG1_cfg_and_f0_anm_gain_START (0)
#define SOC_ASP_SMARTPA_AND_CFG1_cfg_and_f0_anm_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_and_leak_anm_gain : 32;
    } reg;
} SOC_ASP_SMARTPA_AND_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_AND_CFG2_cfg_and_leak_anm_gain_START (0)
#define SOC_ASP_SMARTPA_AND_CFG2_cfg_and_leak_anm_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_and_sc_anm_gain : 32;
    } reg;
} SOC_ASP_SMARTPA_AND_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_AND_CFG3_cfg_and_sc_anm_gain_START (0)
#define SOC_ASP_SMARTPA_AND_CFG3_cfg_and_sc_anm_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_and_temp_anm_gain : 32;
    } reg;
} SOC_ASP_SMARTPA_AND_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_AND_CFG4_cfg_and_temp_anm_gain_START (0)
#define SOC_ASP_SMARTPA_AND_CFG4_cfg_and_temp_anm_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_and_att_time : 32;
    } reg;
} SOC_ASP_SMARTPA_AND_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_AND_CFG5_cfg_and_att_time_START (0)
#define SOC_ASP_SMARTPA_AND_CFG5_cfg_and_att_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_and_rel_time : 32;
    } reg;
} SOC_ASP_SMARTPA_AND_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_AND_CFG6_cfg_and_rel_time_START (0)
#define SOC_ASP_SMARTPA_AND_CFG6_cfg_and_rel_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_efficxup : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG0_cfg_rgc_efficxup_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG0_cfg_rgc_efficxup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_efficxlow : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG1_cfg_rgc_efficxlow_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG1_cfg_rgc_efficxlow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_efficyup : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG2_cfg_rgc_efficyup_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG2_cfg_rgc_efficyup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_efficylow : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG3_cfg_rgc_efficylow_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG3_cfg_rgc_efficylow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_uscale : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG4_cfg_rgc_uscale_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG4_cfg_rgc_uscale_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_iscale : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG5_cfg_rgc_iscale_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG5_cfg_rgc_iscale_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_ubatscale : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG6_cfg_rgc_ubatscale_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG6_cfg_rgc_ubatscale_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_ibatrmslim : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG7_cfg_rgc_ibatrmslim_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG7_cfg_rgc_ibatrmslim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_rctcoeff : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG9_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG9_cfg_rgc_rctcoeff_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG9_cfg_rgc_rctcoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_temppbattopal : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG10_cfg_rgc_temppbattopal_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG10_cfg_rgc_temppbattopal_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_ubatlimit1 : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG13_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG13_cfg_rgc_ubatlimit1_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG13_cfg_rgc_ubatlimit1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_ubatlimit2 : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG14_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG14_cfg_rgc_ubatlimit2_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG14_cfg_rgc_ubatlimit2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_ubatlimit3 : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG15_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG15_cfg_rgc_ubatlimit3_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG15_cfg_rgc_ubatlimit3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_gainlowlimit1 : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG17_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG17_cfg_rgc_gainlowlimit1_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG17_cfg_rgc_gainlowlimit1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_gainlowlimit2 : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG18_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG18_cfg_rgc_gainlowlimit2_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG18_cfg_rgc_gainlowlimit2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_gainlowlimit3 : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG19_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG19_cfg_rgc_gainlowlimit3_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG19_cfg_rgc_gainlowlimit3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_gainlowcoef1 : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG20_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG20_cfg_rgc_gainlowcoef1_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG20_cfg_rgc_gainlowcoef1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_gainlowcoef2 : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG21_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG21_cfg_rgc_gainlowcoef2_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG21_cfg_rgc_gainlowcoef2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rgc_gainlowcoef3 : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_CFG22_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_CFG22_cfg_rgc_gainlowcoef3_START (0)
#define SOC_ASP_SMARTPA_RGC_CFG22_cfg_rgc_gainlowcoef3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_gamp : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG0_cfg_bgc_gamp_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG0_cfg_bgc_gamp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_rloaddiv : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG1_cfg_bgc_rloaddiv_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG1_cfg_bgc_rloaddiv_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_ampeff : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG2_cfg_bgc_ampeff_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG2_cfg_bgc_ampeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_vbat_limit1 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG3_cfg_bgc_vbat_limit1_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG3_cfg_bgc_vbat_limit1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_vbat_limit2 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG4_cfg_bgc_vbat_limit2_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG4_cfg_bgc_vbat_limit2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_vbat_limit3 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG5_cfg_bgc_vbat_limit3_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG5_cfg_bgc_vbat_limit3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_tattsamples : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG6_cfg_bgc_tattsamples_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG6_cfg_bgc_tattsamples_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_trelframes : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG7_cfg_bgc_trelframes_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG7_cfg_bgc_trelframes_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_gain_step : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG8_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG8_cfg_bgc_gain_step_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG8_cfg_bgc_gain_step_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_mingain1_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG9_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG9_cfg_bgc_mingain1_0_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG9_cfg_bgc_mingain1_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_mingain1_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG10_cfg_bgc_mingain1_1_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG10_cfg_bgc_mingain1_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_mingain1_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG11_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG11_cfg_bgc_mingain1_2_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG11_cfg_bgc_mingain1_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_mingain2_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG12_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG12_cfg_bgc_mingain2_0_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG12_cfg_bgc_mingain2_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_mingain2_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG13_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG13_cfg_bgc_mingain2_1_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG13_cfg_bgc_mingain2_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_mingain2_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG14_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG14_cfg_bgc_mingain2_2_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG14_cfg_bgc_mingain2_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_mingain3_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG15_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG15_cfg_bgc_mingain3_0_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG15_cfg_bgc_mingain3_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_mingain3_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG16_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG16_cfg_bgc_mingain3_1_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG16_cfg_bgc_mingain3_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_mingain3_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG17_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG17_cfg_bgc_mingain3_2_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG17_cfg_bgc_mingain3_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_tbat : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG18_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG18_cfg_bgc_tbat_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG18_cfg_bgc_tbat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_cbat : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG19_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG19_cfg_bgc_cbat_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG19_cfg_bgc_cbat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_rbat : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG20_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG20_cfg_bgc_rbat_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG20_cfg_bgc_rbat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_vbat : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG21_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG21_cfg_bgc_vbat_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG21_cfg_bgc_vbat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_tbat_limit : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG22_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG22_cfg_bgc_tbat_limit_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG22_cfg_bgc_tbat_limit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_cbat_limit : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG23_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG23_cfg_bgc_cbat_limit_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG23_cfg_bgc_cbat_limit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_vrmscoeff : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG24_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG24_cfg_bgc_vrmscoeff_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG24_cfg_bgc_vrmscoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_vrmscoeffdiv : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG25_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG25_cfg_bgc_vrmscoeffdiv_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG25_cfg_bgc_vrmscoeffdiv_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_irmscoeff : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG26_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG26_cfg_bgc_irmscoeff_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG26_cfg_bgc_irmscoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_imscoeffdiv : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG27_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG27_cfg_bgc_imscoeffdiv_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG27_cfg_bgc_imscoeffdiv_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad0_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG0_cfg_sdc_biquad0_coefa1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG0_cfg_sdc_biquad0_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad0_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG1_cfg_sdc_biquad0_coefa2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG1_cfg_sdc_biquad0_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad0_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG2_cfg_sdc_biquad0_coefb0_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG2_cfg_sdc_biquad0_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad0_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG3_cfg_sdc_biquad0_coefb1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG3_cfg_sdc_biquad0_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad0_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG4_cfg_sdc_biquad0_coefb2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG4_cfg_sdc_biquad0_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad1_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG5_cfg_sdc_biquad1_coefa1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG5_cfg_sdc_biquad1_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad1_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG6_cfg_sdc_biquad1_coefa2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG6_cfg_sdc_biquad1_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad1_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG7_cfg_sdc_biquad1_coefb0_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG7_cfg_sdc_biquad1_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad1_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG8_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG8_cfg_sdc_biquad1_coefb1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG8_cfg_sdc_biquad1_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad1_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG9_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG9_cfg_sdc_biquad1_coefb2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG9_cfg_sdc_biquad1_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad2_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG10_cfg_sdc_biquad2_coefa1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG10_cfg_sdc_biquad2_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad2_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG11_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG11_cfg_sdc_biquad2_coefa2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG11_cfg_sdc_biquad2_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad2_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG12_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG12_cfg_sdc_biquad2_coefb0_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG12_cfg_sdc_biquad2_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad2_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG13_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG13_cfg_sdc_biquad2_coefb1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG13_cfg_sdc_biquad2_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad2_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG14_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG14_cfg_sdc_biquad2_coefb2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG14_cfg_sdc_biquad2_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad3_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG15_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG15_cfg_sdc_biquad3_coefa1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG15_cfg_sdc_biquad3_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad3_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG16_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG16_cfg_sdc_biquad3_coefa2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG16_cfg_sdc_biquad3_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad3_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG17_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG17_cfg_sdc_biquad3_coefb0_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG17_cfg_sdc_biquad3_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad3_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG18_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG18_cfg_sdc_biquad3_coefb1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG18_cfg_sdc_biquad3_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad3_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG19_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG19_cfg_sdc_biquad3_coefb2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG19_cfg_sdc_biquad3_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad4_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG20_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG20_cfg_sdc_biquad4_coefa1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG20_cfg_sdc_biquad4_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad4_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG21_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG21_cfg_sdc_biquad4_coefa2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG21_cfg_sdc_biquad4_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad4_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG22_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG22_cfg_sdc_biquad4_coefb0_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG22_cfg_sdc_biquad4_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad4_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG23_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG23_cfg_sdc_biquad4_coefb1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG23_cfg_sdc_biquad4_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad4_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG24_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG24_cfg_sdc_biquad4_coefb2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG24_cfg_sdc_biquad4_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad5_coefa1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG25_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG25_cfg_sdc_biquad5_coefa1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG25_cfg_sdc_biquad5_coefa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad5_coefa2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG26_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG26_cfg_sdc_biquad5_coefa2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG26_cfg_sdc_biquad5_coefa2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad5_coefb0 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG27_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG27_cfg_sdc_biquad5_coefb0_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG27_cfg_sdc_biquad5_coefb0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad5_coefb1 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG28_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG28_cfg_sdc_biquad5_coefb1_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG28_cfg_sdc_biquad5_coefb1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sdc_biquad5_coefb2 : 32;
    } reg;
} SOC_ASP_SMARTPA_SDC_CFG29_UNION;
#endif
#define SOC_ASP_SMARTPA_SDC_CFG29_cfg_sdc_biquad5_coefb2_START (0)
#define SOC_ASP_SMARTPA_SDC_CFG29_cfg_sdc_biquad5_coefb2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fre : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG0_cfg_ndc_fre_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG0_cfg_ndc_fre_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fle : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG1_cfg_ndc_fle_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG1_cfg_ndc_fle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fbl_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG2_cfg_ndc_fbl_0_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG2_cfg_ndc_fbl_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fbl_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG3_cfg_ndc_fbl_1_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG3_cfg_ndc_fbl_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fbl_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG4_cfg_ndc_fbl_2_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG4_cfg_ndc_fbl_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fbl_3 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG5_cfg_ndc_fbl_3_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG5_cfg_ndc_fbl_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fbl_4 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG6_cfg_ndc_fbl_4_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG6_cfg_ndc_fbl_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fkms_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG7_cfg_ndc_fkms_0_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG7_cfg_ndc_fkms_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fkms_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG8_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG8_cfg_ndc_fkms_1_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG8_cfg_ndc_fkms_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fkms_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG9_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG9_cfg_ndc_fkms_2_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG9_cfg_ndc_fkms_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fkms_3 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG10_cfg_ndc_fkms_3_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG10_cfg_ndc_fkms_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_fkms_4 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG11_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG11_cfg_ndc_fkms_4_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG11_cfg_ndc_fkms_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_frms_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG12_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG12_cfg_ndc_frms_0_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG12_cfg_ndc_frms_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_frms_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG13_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG13_cfg_ndc_frms_1_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG13_cfg_ndc_frms_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_frms_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG14_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG14_cfg_ndc_frms_2_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG14_cfg_ndc_frms_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_pagain : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG15_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG15_cfg_ndc_pagain_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG15_cfg_ndc_pagain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_alpha_min : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG16_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG16_cfg_ndc_alpha_min_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG16_cfg_ndc_alpha_min_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_alpha_max : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG17_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG17_cfg_ndc_alpha_max_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG17_cfg_ndc_alpha_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_umin : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG18_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG18_cfg_ndc_umin_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG18_cfg_ndc_umin_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_umax : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG19_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG19_cfg_ndc_umax_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG19_cfg_ndc_umax_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_alpha_buf_init : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG20_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG20_cfg_ndc_alpha_buf_init_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG20_cfg_ndc_alpha_buf_init_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_bx_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG21_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG21_cfg_ndc_bx_0_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG21_cfg_ndc_bx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_bx_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG22_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG22_cfg_ndc_bx_1_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG22_cfg_ndc_bx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_bx_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG23_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG23_cfg_ndc_bx_2_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG23_cfg_ndc_bx_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_ax_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG24_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG24_cfg_ndc_ax_1_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG24_cfg_ndc_ax_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_ax_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG25_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG25_cfg_ndc_ax_2_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG25_cfg_ndc_ax_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_bv_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG26_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG26_cfg_ndc_bv_0_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG26_cfg_ndc_bv_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_bv_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG27_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG27_cfg_ndc_bv_1_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG27_cfg_ndc_bv_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_bv_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG28_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG28_cfg_ndc_bv_2_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG28_cfg_ndc_bv_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_av_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG29_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG29_cfg_ndc_av_1_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG29_cfg_ndc_av_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_av_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG30_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG30_cfg_ndc_av_2_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG30_cfg_ndc_av_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_tmplm : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG31_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG31_cfg_ndc_tmplm_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG31_cfg_ndc_tmplm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_tmpdpa : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG32_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG32_cfg_ndc_tmpdpa_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG32_cfg_ndc_tmpdpa_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_tmpdrbi : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG33_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG33_cfg_ndc_tmpdrbi_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG33_cfg_ndc_tmpdrbi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ndc_tmpu5 : 32;
    } reg;
} SOC_ASP_SMARTPA_NDC_CFG34_UNION;
#endif
#define SOC_ASP_SMARTPA_NDC_CFG34_cfg_ndc_tmpu5_START (0)
#define SOC_ASP_SMARTPA_NDC_CFG34_cfg_ndc_tmpu5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lmt_threshold : 32;
    } reg;
} SOC_ASP_SMARTPA_LMT_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_LMT_CFG0_cfg_lmt_threshold_START (0)
#define SOC_ASP_SMARTPA_LMT_CFG0_cfg_lmt_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_plt_clken : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_SMARTPA_PLT_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_PLT_CFG0_cfg_plt_clken_START (0)
#define SOC_ASP_SMARTPA_PLT_CFG0_cfg_plt_clken_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_plt_cross_step : 32;
    } reg;
} SOC_ASP_SMARTPA_PLT_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_PLT_CFG1_cfg_plt_cross_step_START (0)
#define SOC_ASP_SMARTPA_PLT_CFG1_cfg_plt_cross_step_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_plt_cross_fade_len : 32;
    } reg;
} SOC_ASP_SMARTPA_PLT_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_PLT_CFG2_cfg_plt_cross_fade_len_START (0)
#define SOC_ASP_SMARTPA_PLT_CFG2_cfg_plt_cross_fade_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_vol_th : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG5_cfg_idf_vol_th_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG5_cfg_idf_vol_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_cur_th : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG6_cfg_idf_cur_th_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG6_cfg_idf_cur_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_re_tone : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG7_cfg_idf_re_tone_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG7_cfg_idf_re_tone_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_pilot_cross_fade_len : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG8_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG8_cfg_idf_pilot_cross_fade_len_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG8_cfg_idf_pilot_cross_fade_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_err_th : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG10_cfg_idf_err_th_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG10_cfg_idf_err_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_invneng_th : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG11_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG11_cfg_idf_invneng_th_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG11_cfg_idf_invneng_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_neng_th : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG12_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG12_cfg_idf_neng_th_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG12_cfg_idf_neng_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_stepsize : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG13_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG13_cfg_idf_stepsize_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG13_cfg_idf_stepsize_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_re_wire : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG0_cfg_lsm_re_wire_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG0_cfg_lsm_re_wire_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_re_old : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG1_cfg_lsm_re_old_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG1_cfg_lsm_re_old_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_abnormal_sc_th : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG2_cfg_lsm_abnormal_sc_th_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG2_cfg_lsm_abnormal_sc_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_abnormal_oc_th : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG3_cfg_lsm_abnormal_oc_th_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG3_cfg_lsm_abnormal_oc_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_re_w1 : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG4_cfg_lsm_re_w1_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG4_cfg_lsm_re_w1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_tempcoeff_32fix : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG6_cfg_lsm_tempcoeff_32fix_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG6_cfg_lsm_tempcoeff_32fix_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_coiltemp_32fix : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG7_cfg_lsm_coiltemp_32fix_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG7_cfg_lsm_coiltemp_32fix_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_abnormal_temp_th2 : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG8_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG8_cfg_lsm_abnormal_temp_th2_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG8_cfg_lsm_abnormal_temp_th2_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_abnormal_temp_th1 : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG9_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG9_cfg_lsm_abnormal_temp_th1_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG9_cfg_lsm_abnormal_temp_th1_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_temp_w1 : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG10_cfg_lsm_temp_w1_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG10_cfg_lsm_temp_w1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_f1f2_err_th : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG12_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG12_cfg_lsm_f1f2_err_th_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG12_cfg_lsm_f1f2_err_th_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_maxf1f2_th : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG13_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG13_cfg_lsm_maxf1f2_th_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG13_cfg_lsm_maxf1f2_th_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_q_thr : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG14_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG14_cfg_lsm_q_thr_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG14_cfg_lsm_q_thr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_detour_percent_th : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG15_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG15_cfg_lsm_detour_percent_th_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG15_cfg_lsm_detour_percent_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_abnormal_f0_th2 : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG16_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG16_cfg_lsm_abnormal_f0_th2_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG16_cfg_lsm_abnormal_f0_th2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_abnormal_f0_th1 : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG17_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG17_cfg_lsm_abnormal_f0_th1_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG17_cfg_lsm_abnormal_f0_th1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_abnormal_blocked_th2 : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG18_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG18_cfg_lsm_abnormal_blocked_th2_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG18_cfg_lsm_abnormal_blocked_th2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_abnormal_blocked_th1 : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG19_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG19_cfg_lsm_abnormal_blocked_th1_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG19_cfg_lsm_abnormal_blocked_th1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_abnormal_leakage_th2 : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG20_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG20_cfg_lsm_abnormal_leakage_th2_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG20_cfg_lsm_abnormal_leakage_th2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_abnormal_leakage_th1 : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG21_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG21_cfg_lsm_abnormal_leakage_th1_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG21_cfg_lsm_abnormal_leakage_th1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_f0_w1 : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG22_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG22_cfg_lsm_f0_w1_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG22_cfg_lsm_f0_w1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_start_time : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG24_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG24_cfg_lsm_start_time_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG24_cfg_lsm_start_time_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_f0 : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG25_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG25_cfg_lsm_f0_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG25_cfg_lsm_f0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_re_ref : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG26_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG26_cfg_lsm_re_ref_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG26_cfg_lsm_re_ref_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lsm_coiel_tem_ref : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_SMARTPA_LSM_CFG28_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_CFG28_cfg_lsm_coiel_tem_ref_START (0)
#define SOC_ASP_SMARTPA_LSM_CFG28_cfg_lsm_coiel_tem_ref_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_lon : 1;
        unsigned int cfg_ecp_pxkg : 1;
        unsigned int cfg_ecp_hpkg : 1;
        unsigned int cfg_ecp_wpkg : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG0_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG0_cfg_ecp_lon_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG0_cfg_ecp_lon_END (0)
#define SOC_ASP_SMARTPA_ECP_CFG0_cfg_ecp_pxkg_START (1)
#define SOC_ASP_SMARTPA_ECP_CFG0_cfg_ecp_pxkg_END (1)
#define SOC_ASP_SMARTPA_ECP_CFG0_cfg_ecp_hpkg_START (2)
#define SOC_ASP_SMARTPA_ECP_CFG0_cfg_ecp_hpkg_END (2)
#define SOC_ASP_SMARTPA_ECP_CFG0_cfg_ecp_wpkg_START (3)
#define SOC_ASP_SMARTPA_ECP_CFG0_cfg_ecp_wpkg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_re : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG1_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG1_cfg_ecp_re_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG1_cfg_ecp_re_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_mms : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG2_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG2_cfg_ecp_mms_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG2_cfg_ecp_mms_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_bl : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG3_cfg_ecp_bl_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG3_cfg_ecp_bl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_kms : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG4_cfg_ecp_kms_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG4_cfg_ecp_kms_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_rms : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG5_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG5_cfg_ecp_rms_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG5_cfg_ecp_rms_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_lfcoeff : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG6_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG6_cfg_ecp_lfcoeff_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG6_cfg_ecp_lfcoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_mfcoeff : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG7_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG7_cfg_ecp_mfcoeff_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG7_cfg_ecp_mfcoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hfcoeff : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG8_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG8_cfg_ecp_hfcoeff_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG8_cfg_ecp_hfcoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_bflen : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG9_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG9_cfg_ecp_bflen_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG9_cfg_ecp_bflen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_gamp : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG10_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG10_cfg_ecp_gamp_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG10_cfg_ecp_gamp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_xth : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG11_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG11_cfg_ecp_xth_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG11_cfg_ecp_xth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_relimit_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG12_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG12_cfg_ecp_relimit_0_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG12_cfg_ecp_relimit_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_relimit_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG13_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG13_cfg_ecp_relimit_1_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG13_cfg_ecp_relimit_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_xlimit_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG14_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG14_cfg_ecp_xlimit_0_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG14_cfg_ecp_xlimit_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_xlimit_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG15_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG15_cfg_ecp_xlimit_1_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG15_cfg_ecp_xlimit_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_xjzcoeff : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG16_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG16_cfg_ecp_xjzcoeff_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG16_cfg_ecp_xjzcoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_xdc : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG17_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG17_cfg_ecp_xdc_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG17_cfg_ecp_xdc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_nhpd : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG18_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG18_cfg_ecp_nhpd_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG18_cfg_ecp_nhpd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_coeff : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG19_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG19_cfg_ecp_coeff_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG19_cfg_ecp_coeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_xzcoeff : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG20_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG20_cfg_ecp_xzcoeff_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG20_cfg_ecp_xzcoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_dtcoeff : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG21_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG21_cfg_ecp_dtcoeff_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG21_cfg_ecp_dtcoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_bseh : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG22_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG22_cfg_ecp_bseh_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG22_cfg_ecp_bseh_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_wpf0htmp : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG23_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG23_cfg_ecp_wpf0htmp_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG23_cfg_ecp_wpf0htmp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_wpf0ltmp : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG24_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG24_cfg_ecp_wpf0ltmp_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG24_cfg_ecp_wpf0ltmp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_wpcoeff : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG25_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG25_cfg_ecp_wpcoeff_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG25_cfg_ecp_wpcoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_pxb_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG26_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG26_cfg_ecp_pxb_0_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG26_cfg_ecp_pxb_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_pxb_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG27_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG27_cfg_ecp_pxb_1_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG27_cfg_ecp_pxb_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_pxb_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG28_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG28_cfg_ecp_pxb_2_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG28_cfg_ecp_pxb_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_pxa_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG29_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG29_cfg_ecp_pxa_0_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG29_cfg_ecp_pxa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_pxa_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG30_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG30_cfg_ecp_pxa_1_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG30_cfg_ecp_pxa_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_pxa_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG31_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG31_cfg_ecp_pxa_2_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG31_cfg_ecp_pxa_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_linxb_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG32_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG32_cfg_ecp_linxb_0_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG32_cfg_ecp_linxb_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_linxb_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG33_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG33_cfg_ecp_linxb_1_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG33_cfg_ecp_linxb_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_linxb_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG34_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG34_cfg_ecp_linxb_2_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG34_cfg_ecp_linxb_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_linxb_3 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG35_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG35_cfg_ecp_linxb_3_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG35_cfg_ecp_linxb_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_linxa_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG36_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG36_cfg_ecp_linxa_0_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG36_cfg_ecp_linxa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_linxa_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG37_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG37_cfg_ecp_linxa_1_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG37_cfg_ecp_linxa_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_linxa_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG38_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG38_cfg_ecp_linxa_2_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG38_cfg_ecp_linxa_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_linxa_3 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG39_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG39_cfg_ecp_linxa_3_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG39_cfg_ecp_linxa_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpc_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG40_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG40_cfg_ecp_hpc_0_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG40_cfg_ecp_hpc_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpc_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG41_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG41_cfg_ecp_hpc_1_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG41_cfg_ecp_hpc_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpc_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG42_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG42_cfg_ecp_hpc_2_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG42_cfg_ecp_hpc_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpc_3 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG43_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG43_cfg_ecp_hpc_3_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG43_cfg_ecp_hpc_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG44_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG44_cfg_ecp_hpwh_0_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG44_cfg_ecp_hpwh_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG45_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG45_cfg_ecp_hpwh_1_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG45_cfg_ecp_hpwh_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG46_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG46_cfg_ecp_hpwh_2_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG46_cfg_ecp_hpwh_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_3 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG47_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG47_cfg_ecp_hpwh_3_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG47_cfg_ecp_hpwh_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_4 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG48_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG48_cfg_ecp_hpwh_4_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG48_cfg_ecp_hpwh_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_5 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG49_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG49_cfg_ecp_hpwh_5_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG49_cfg_ecp_hpwh_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_6 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG50_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG50_cfg_ecp_hpwh_6_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG50_cfg_ecp_hpwh_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_7 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG51_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG51_cfg_ecp_hpwh_7_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG51_cfg_ecp_hpwh_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_8 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG52_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG52_cfg_ecp_hpwh_8_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG52_cfg_ecp_hpwh_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_9 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG53_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG53_cfg_ecp_hpwh_9_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG53_cfg_ecp_hpwh_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_10 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG54_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG54_cfg_ecp_hpwh_10_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG54_cfg_ecp_hpwh_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_11 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG55_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG55_cfg_ecp_hpwh_11_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG55_cfg_ecp_hpwh_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_12 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG56_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG56_cfg_ecp_hpwh_12_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG56_cfg_ecp_hpwh_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_13 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG57_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG57_cfg_ecp_hpwh_13_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG57_cfg_ecp_hpwh_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_14 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG58_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG58_cfg_ecp_hpwh_14_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG58_cfg_ecp_hpwh_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_15 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG59_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG59_cfg_ecp_hpwh_15_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG59_cfg_ecp_hpwh_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_16 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG60_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG60_cfg_ecp_hpwh_16_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG60_cfg_ecp_hpwh_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_17 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG61_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG61_cfg_ecp_hpwh_17_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG61_cfg_ecp_hpwh_17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_18 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG62_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG62_cfg_ecp_hpwh_18_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG62_cfg_ecp_hpwh_18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwh_19 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG63_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG63_cfg_ecp_hpwh_19_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG63_cfg_ecp_hpwh_19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_0 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG64_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG64_cfg_ecp_hpwr_0_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG64_cfg_ecp_hpwr_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_1 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG65_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG65_cfg_ecp_hpwr_1_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG65_cfg_ecp_hpwr_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_2 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG66_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG66_cfg_ecp_hpwr_2_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG66_cfg_ecp_hpwr_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_3 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG67_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG67_cfg_ecp_hpwr_3_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG67_cfg_ecp_hpwr_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_4 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG68_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG68_cfg_ecp_hpwr_4_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG68_cfg_ecp_hpwr_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_5 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG69_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG69_cfg_ecp_hpwr_5_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG69_cfg_ecp_hpwr_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_6 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG70_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG70_cfg_ecp_hpwr_6_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG70_cfg_ecp_hpwr_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_7 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG71_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG71_cfg_ecp_hpwr_7_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG71_cfg_ecp_hpwr_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_8 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG72_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG72_cfg_ecp_hpwr_8_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG72_cfg_ecp_hpwr_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_9 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG73_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG73_cfg_ecp_hpwr_9_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG73_cfg_ecp_hpwr_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_10 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG74_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG74_cfg_ecp_hpwr_10_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG74_cfg_ecp_hpwr_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_11 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG75_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG75_cfg_ecp_hpwr_11_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG75_cfg_ecp_hpwr_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_12 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG76_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG76_cfg_ecp_hpwr_12_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG76_cfg_ecp_hpwr_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_13 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG77_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG77_cfg_ecp_hpwr_13_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG77_cfg_ecp_hpwr_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_14 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG78_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG78_cfg_ecp_hpwr_14_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG78_cfg_ecp_hpwr_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_15 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG79_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG79_cfg_ecp_hpwr_15_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG79_cfg_ecp_hpwr_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_16 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG80_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG80_cfg_ecp_hpwr_16_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG80_cfg_ecp_hpwr_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_17 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG81_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG81_cfg_ecp_hpwr_17_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG81_cfg_ecp_hpwr_17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_18 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG82_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG82_cfg_ecp_hpwr_18_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG82_cfg_ecp_hpwr_18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpwr_19 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG83_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG83_cfg_ecp_hpwr_19_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG83_cfg_ecp_hpwr_19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpw : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG84_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG84_cfg_ecp_hpw_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG84_cfg_ecp_hpw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_bufw1 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG85_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG85_cfg_ecp_bufw1_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG85_cfg_ecp_bufw1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ecp_hpw1 : 32;
    } reg;
} SOC_ASP_SMARTPA_ECP_CFG86_UNION;
#endif
#define SOC_ASP_SMARTPA_ECP_CFG86_cfg_ecp_hpw1_START (0)
#define SOC_ASP_SMARTPA_ECP_CFG86_cfg_ecp_hpw1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_yk_w1 : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG14_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG14_cfg_idf_yk_w1_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG14_cfg_idf_yk_w1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_eng_th : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG16_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG16_cfg_idf_eng_th_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG16_cfg_idf_eng_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_delay : 9;
        unsigned int cfg_idf_debug_select : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG17_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG17_cfg_idf_delay_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG17_cfg_idf_delay_END (8)
#define SOC_ASP_SMARTPA_IDF_CFG17_cfg_idf_debug_select_START (9)
#define SOC_ASP_SMARTPA_IDF_CFG17_cfg_idf_debug_select_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_yk_init : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG18_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG18_cfg_idf_yk_init_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG18_cfg_idf_yk_init_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_bgc_ibat : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_CFG28_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_CFG28_cfg_bgc_ibat_START (0)
#define SOC_ASP_SMARTPA_BGC_CFG28_cfg_bgc_ibat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_plt_media : 32;
    } reg;
} SOC_ASP_SMARTPA_PLT_CFG3_UNION;
#endif
#define SOC_ASP_SMARTPA_PLT_CFG3_cfg_plt_media_START (0)
#define SOC_ASP_SMARTPA_PLT_CFG3_cfg_plt_media_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_plt_sin : 32;
    } reg;
} SOC_ASP_SMARTPA_PLT_CFG4_UNION;
#endif
#define SOC_ASP_SMARTPA_PLT_CFG4_cfg_plt_sin_START (0)
#define SOC_ASP_SMARTPA_PLT_CFG4_cfg_plt_sin_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_idf_retone_phase_tune : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_SMARTPA_IDF_CFG19_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_CFG19_cfg_idf_retone_phase_tune_START (0)
#define SOC_ASP_SMARTPA_IDF_CFG19_cfg_idf_retone_phase_tune_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cross_fade_gain_step : 32;
    } reg;
} SOC_ASP_SMARTPA_CROSSFADE_STEP_CFG_UNION;
#endif
#define SOC_ASP_SMARTPA_CROSSFADE_STEP_CFG_cross_fade_gain_step_START (0)
#define SOC_ASP_SMARTPA_CROSSFADE_STEP_CFG_cross_fade_gain_step_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lsm_f0_locate : 8;
        unsigned int lsm_f1_locate : 8;
        unsigned int lsm_f2_locate : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_SMARTPA_LSM_RO_STATE0_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_RO_STATE0_lsm_f0_locate_START (0)
#define SOC_ASP_SMARTPA_LSM_RO_STATE0_lsm_f0_locate_END (7)
#define SOC_ASP_SMARTPA_LSM_RO_STATE0_lsm_f1_locate_START (8)
#define SOC_ASP_SMARTPA_LSM_RO_STATE0_lsm_f1_locate_END (15)
#define SOC_ASP_SMARTPA_LSM_RO_STATE0_lsm_f2_locate_START (16)
#define SOC_ASP_SMARTPA_LSM_RO_STATE0_lsm_f2_locate_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idf_debug_ctrl_bit0 : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_RO_STATE0_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_RO_STATE0_idf_debug_ctrl_bit0_START (0)
#define SOC_ASP_SMARTPA_IDF_RO_STATE0_idf_debug_ctrl_bit0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idf_debug_data_in : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_RO_STATE1_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_RO_STATE1_idf_debug_data_in_START (0)
#define SOC_ASP_SMARTPA_IDF_RO_STATE1_idf_debug_data_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idf_debug_data_out : 32;
    } reg;
} SOC_ASP_SMARTPA_IDF_RO_STATE2_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_RO_STATE2_idf_debug_data_out_START (0)
#define SOC_ASP_SMARTPA_IDF_RO_STATE2_idf_debug_data_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pow_plim_crt : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_RO_STATE0_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_RO_STATE0_pow_plim_crt_START (0)
#define SOC_ASP_SMARTPA_POW_RO_STATE0_pow_plim_crt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pow_delta_t : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_RO_STATE1_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_RO_STATE1_pow_delta_t_START (0)
#define SOC_ASP_SMARTPA_POW_RO_STATE1_pow_delta_t_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pow_predict_t : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_RO_STATE2_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_RO_STATE2_pow_predict_t_START (0)
#define SOC_ASP_SMARTPA_POW_RO_STATE2_pow_predict_t_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int and_ret_state : 3;
        unsigned int pow_count : 16;
        unsigned int reserved : 12;
        unsigned int spa_abnormal_int : 1;
    } reg;
} SOC_ASP_SMARTPA_AND_RO_STATE0_UNION;
#endif
#define SOC_ASP_SMARTPA_AND_RO_STATE0_and_ret_state_START (0)
#define SOC_ASP_SMARTPA_AND_RO_STATE0_and_ret_state_END (2)
#define SOC_ASP_SMARTPA_AND_RO_STATE0_pow_count_START (3)
#define SOC_ASP_SMARTPA_AND_RO_STATE0_pow_count_END (18)
#define SOC_ASP_SMARTPA_AND_RO_STATE0_spa_abnormal_int_START (31)
#define SOC_ASP_SMARTPA_AND_RO_STATE0_spa_abnormal_int_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rgc_temp_ibat : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_RO_STATE0_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_RO_STATE0_rgc_temp_ibat_START (0)
#define SOC_ASP_SMARTPA_RGC_RO_STATE0_rgc_temp_ibat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rgc_temp_rbat : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_RO_STATE1_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_RO_STATE1_rgc_temp_rbat_START (0)
#define SOC_ASP_SMARTPA_RGC_RO_STATE1_rgc_temp_rbat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rgc_temp_vbat : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_RO_STATE2_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_RO_STATE2_rgc_temp_vbat_START (0)
#define SOC_ASP_SMARTPA_RGC_RO_STATE2_rgc_temp_vbat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idf_yk_init_finish : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_SMARTPA_IDF_RO_STATE4_UNION;
#endif
#define SOC_ASP_SMARTPA_IDF_RO_STATE4_idf_yk_init_finish_START (0)
#define SOC_ASP_SMARTPA_IDF_RO_STATE4_idf_yk_init_finish_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pow_prms_in : 32;
    } reg;
} SOC_ASP_SMARTPA_POW_RO_STATE3_UNION;
#endif
#define SOC_ASP_SMARTPA_POW_RO_STATE3_pow_prms_in_START (0)
#define SOC_ASP_SMARTPA_POW_RO_STATE3_pow_prms_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tep_t_currentgain : 32;
    } reg;
} SOC_ASP_SMARTPA_TEP_RO_STATE0_UNION;
#endif
#define SOC_ASP_SMARTPA_TEP_RO_STATE0_tep_t_currentgain_START (0)
#define SOC_ASP_SMARTPA_TEP_RO_STATE0_tep_t_currentgain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int and_current_gain : 32;
    } reg;
} SOC_ASP_SMARTPA_AND_RO_STATE1_UNION;
#endif
#define SOC_ASP_SMARTPA_AND_RO_STATE1_and_current_gain_START (0)
#define SOC_ASP_SMARTPA_AND_RO_STATE1_and_current_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rgc_gainbuffer : 32;
    } reg;
} SOC_ASP_SMARTPA_RGC_RO_STATE3_UNION;
#endif
#define SOC_ASP_SMARTPA_RGC_RO_STATE3_rgc_gainbuffer_START (0)
#define SOC_ASP_SMARTPA_RGC_RO_STATE3_rgc_gainbuffer_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bgc_current_gain : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_RO_STATE0_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_RO_STATE0_bgc_current_gain_START (0)
#define SOC_ASP_SMARTPA_BGC_RO_STATE0_bgc_current_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bgc_vbat_min : 32;
    } reg;
} SOC_ASP_SMARTPA_BGC_RO_STATE1_UNION;
#endif
#define SOC_ASP_SMARTPA_BGC_RO_STATE1_bgc_vbat_min_START (0)
#define SOC_ASP_SMARTPA_BGC_RO_STATE1_bgc_vbat_min_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lsm_f0 : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_RO_STATE1_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_RO_STATE1_lsm_f0_START (0)
#define SOC_ASP_SMARTPA_LSM_RO_STATE1_lsm_f0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lsm_re : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_RO_STATE2_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_RO_STATE2_lsm_re_START (0)
#define SOC_ASP_SMARTPA_LSM_RO_STATE2_lsm_re_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lsm_reref : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_RO_STATE3_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_RO_STATE3_lsm_reref_START (0)
#define SOC_ASP_SMARTPA_LSM_RO_STATE3_lsm_reref_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lsm_coiltemp : 32;
    } reg;
} SOC_ASP_SMARTPA_LSM_RO_STATE4_UNION;
#endif
#define SOC_ASP_SMARTPA_LSM_RO_STATE4_lsm_coiltemp_START (0)
#define SOC_ASP_SMARTPA_LSM_RO_STATE4_lsm_coiltemp_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
