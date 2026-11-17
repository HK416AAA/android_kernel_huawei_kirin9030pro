#ifndef __SOC_HAPTIC_INTERFACE_H__
#define __SOC_HAPTIC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HAPTIC_LRA_BYPASS_CFG_ADDR(base) ((base) + (0x000UL))
#define SOC_HAPTIC_LRA_CLK_RST_CFG_ADDR(base) ((base) + (0x004UL))
#define SOC_HAPTIC_LRA_CLK_CG_EN_ADDR(base) ((base) + (0x008UL))
#define SOC_HAPTIC_LRA_INTR_STAT_REG_ADDR(base) ((base) + (0x00CUL))
#define SOC_HAPTIC_LRA_PRT_SWITCH_CFG_ADDR(base) ((base) + (0x010UL))
#define SOC_HAPTIC_LRA_LP_CFG0_ADDR(base) ((base) + (0x014UL))
#define SOC_HAPTIC_LRA_LP_CFG1_ADDR(base) ((base) + (0x018UL))
#define SOC_HAPTIC_LRA_LP_CFG2_ADDR(base) ((base) + (0x01CUL))
#define SOC_HAPTIC_LRA_LP_CFG3_ADDR(base) ((base) + (0x020UL))
#define SOC_HAPTIC_LRA_LP_CFG4_ADDR(base) ((base) + (0x024UL))
#define SOC_HAPTIC_LRA_LP_CFG5_ADDR(base) ((base) + (0x028UL))
#define SOC_HAPTIC_LRA_LP_CFG6_ADDR(base) ((base) + (0x02CUL))
#define SOC_HAPTIC_LRA_LP_CFG7_ADDR(base) ((base) + (0x030UL))
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_ADDR(base) ((base) + (0x034UL))
#define SOC_HAPTIC_LRA_RO_STATE0_ADDR(base) ((base) + (0x038UL))
#define SOC_HAPTIC_LRA_RO_STATE1_ADDR(base) ((base) + (0x03CUL))
#define SOC_HAPTIC_LRA_RO_STATE2_ADDR(base) ((base) + (0x040UL))
#define SOC_HAPTIC_LRA_RO_STATE3_ADDR(base) ((base) + (0x044UL))
#define SOC_HAPTIC_LRA_RO_STATE4_ADDR(base) ((base) + (0x048UL))
#define SOC_HAPTIC_LRA_RO_STATE5_ADDR(base) ((base) + (0x04CUL))
#define SOC_HAPTIC_LRA_RO_STATE6_ADDR(base) ((base) + (0x050UL))
#define SOC_HAPTIC_LRA_RO_STATE7_ADDR(base) ((base) + (0x054UL))
#define SOC_HAPTIC_LRA_RO_STATE8_ADDR(base) ((base) + (0x058UL))
#define SOC_HAPTIC_LRA_RO_STATE9_ADDR(base) ((base) + (0x05CUL))
#define SOC_HAPTIC_LRA_RO_STATE10_ADDR(base) ((base) + (0x060UL))
#define SOC_HAPTIC_LRA_RO_STATE11_ADDR(base) ((base) + (0x064UL))
#define SOC_HAPTIC_LRA_RO_STATE12_ADDR(base) ((base) + (0x068UL))
#define SOC_HAPTIC_LRA_RO_STATE13_ADDR(base) ((base) + (0x06CUL))
#define SOC_HAPTIC_LRA_RO_STATE14_ADDR(base) ((base) + (0x070UL))
#define SOC_HAPTIC_LRA_CFG0_ADDR(base) ((base) + (0x0A0UL))
#define SOC_HAPTIC_LRA_CFG1_ADDR(base) ((base) + (0x0A4UL))
#define SOC_HAPTIC_LRA_CFG2_ADDR(base) ((base) + (0x0A8UL))
#define SOC_HAPTIC_LRA_CFG3_ADDR(base) ((base) + (0x0ACUL))
#define SOC_HAPTIC_LRA_CFG4_ADDR(base) ((base) + (0x0B0UL))
#define SOC_HAPTIC_LRA_CFG5_ADDR(base) ((base) + (0x0B4UL))
#define SOC_HAPTIC_LRA_CFG6_ADDR(base) ((base) + (0x0B8UL))
#define SOC_HAPTIC_LRA_CFG7_ADDR(base) ((base) + (0x0BCUL))
#define SOC_HAPTIC_LRA_CFG8_ADDR(base) ((base) + (0x0C0UL))
#define SOC_HAPTIC_LRA_CFG9_ADDR(base) ((base) + (0x0C4UL))
#define SOC_HAPTIC_LRA_CFG10_ADDR(base) ((base) + (0x0C8UL))
#define SOC_HAPTIC_LRA_CFG11_ADDR(base) ((base) + (0x0CCUL))
#define SOC_HAPTIC_LRA_CFG12_ADDR(base) ((base) + (0x0D0UL))
#define SOC_HAPTIC_LRA_CFG13_ADDR(base) ((base) + (0x0D4UL))
#define SOC_HAPTIC_LRA_CFG14_ADDR(base) ((base) + (0x0D8UL))
#define SOC_HAPTIC_LRA_CFG15_ADDR(base) ((base) + (0x0DCUL))
#define SOC_HAPTIC_LRA_CFG16_ADDR(base) ((base) + (0x0E0UL))
#define SOC_HAPTIC_LRA_CFG17_ADDR(base) ((base) + (0x0E4UL))
#define SOC_HAPTIC_LRA_CFG18_ADDR(base) ((base) + (0x0E8UL))
#define SOC_HAPTIC_LRA_CFG19_ADDR(base) ((base) + (0x0ECUL))
#define SOC_HAPTIC_LRA_CFG20_ADDR(base) ((base) + (0x0F0UL))
#define SOC_HAPTIC_LRA_CFG21_ADDR(base) ((base) + (0x0F4UL))
#define SOC_HAPTIC_LRA_CFG22_ADDR(base) ((base) + (0x0F8UL))
#define SOC_HAPTIC_LRA_CFG23_ADDR(base) ((base) + (0x0FCUL))
#define SOC_HAPTIC_LRA_CFG24_ADDR(base) ((base) + (0x100UL))
#define SOC_HAPTIC_LRA_CFG25_ADDR(base) ((base) + (0x104UL))
#define SOC_HAPTIC_LRA_CFG26_ADDR(base) ((base) + (0x108UL))
#define SOC_HAPTIC_LRA_CFG27_ADDR(base) ((base) + (0x10CUL))
#define SOC_HAPTIC_LRA_CFG28_ADDR(base) ((base) + (0x110UL))
#define SOC_HAPTIC_LRA_CFG29_ADDR(base) ((base) + (0x114UL))
#define SOC_HAPTIC_LRA_CFG30_ADDR(base) ((base) + (0x118UL))
#define SOC_HAPTIC_LRA_CFG31_ADDR(base) ((base) + (0x11CUL))
#define SOC_HAPTIC_LRA_CFG32_ADDR(base) ((base) + (0x120UL))
#define SOC_HAPTIC_LRA_CFG33_ADDR(base) ((base) + (0x124UL))
#define SOC_HAPTIC_LRA_CFG34_ADDR(base) ((base) + (0x128UL))
#define SOC_HAPTIC_LRA_CFG35_ADDR(base) ((base) + (0x12CUL))
#define SOC_HAPTIC_LRA_CFG36_ADDR(base) ((base) + (0x130UL))
#define SOC_HAPTIC_LRA_CFG37_ADDR(base) ((base) + (0x134UL))
#define SOC_HAPTIC_LRA_CFG38_ADDR(base) ((base) + (0x138UL))
#define SOC_HAPTIC_LRA_CFG39_ADDR(base) ((base) + (0x13CUL))
#define SOC_HAPTIC_LRA_CFG40_ADDR(base) ((base) + (0x140UL))
#define SOC_HAPTIC_LRA_CFG41_ADDR(base) ((base) + (0x144UL))
#define SOC_HAPTIC_LRA_CFG42_ADDR(base) ((base) + (0x148UL))
#define SOC_HAPTIC_LRA_CFG43_ADDR(base) ((base) + (0x14CUL))
#define SOC_HAPTIC_LRA_CFG44_ADDR(base) ((base) + (0x150UL))
#define SOC_HAPTIC_LRA_CFG45_ADDR(base) ((base) + (0x154UL))
#define SOC_HAPTIC_LRA_CFG46_ADDR(base) ((base) + (0x158UL))
#define SOC_HAPTIC_LRA_CFG47_ADDR(base) ((base) + (0x15CUL))
#define SOC_HAPTIC_LRA_CFG48_ADDR(base) ((base) + (0x160UL))
#define SOC_HAPTIC_LRA_CFG49_ADDR(base) ((base) + (0x164UL))
#define SOC_HAPTIC_LRA_CFG50_ADDR(base) ((base) + (0x168UL))
#define SOC_HAPTIC_LRA_CFG51_ADDR(base) ((base) + (0x16CUL))
#define SOC_HAPTIC_LRA_CFG52_ADDR(base) ((base) + (0x170UL))
#define SOC_HAPTIC_LRA_CFG53_ADDR(base) ((base) + (0x174UL))
#define SOC_HAPTIC_LRA_CFG54_ADDR(base) ((base) + (0x178UL))
#define SOC_HAPTIC_LRA_CFG55_ADDR(base) ((base) + (0x17CUL))
#define SOC_HAPTIC_LRA_CFG56_ADDR(base) ((base) + (0x180UL))
#define SOC_HAPTIC_LRA_CFG57_ADDR(base) ((base) + (0x184UL))
#define SOC_HAPTIC_LRA_CFG58_ADDR(base) ((base) + (0x188UL))
#define SOC_HAPTIC_LRA_CFG59_ADDR(base) ((base) + (0x18CUL))
#define SOC_HAPTIC_LRA_CFG60_ADDR(base) ((base) + (0x190UL))
#define SOC_HAPTIC_LRA_CFG61_ADDR(base) ((base) + (0x194UL))
#define SOC_HAPTIC_LRA_CFG62_ADDR(base) ((base) + (0x198UL))
#define SOC_HAPTIC_LRA_CFG63_ADDR(base) ((base) + (0x19CUL))
#define SOC_HAPTIC_LRA_CFG64_ADDR(base) ((base) + (0x1A0UL))
#define SOC_HAPTIC_LRA_CFG65_ADDR(base) ((base) + (0x1A4UL))
#define SOC_HAPTIC_LRA_CFG66_ADDR(base) ((base) + (0x1A8UL))
#define SOC_HAPTIC_LRA_CFG67_ADDR(base) ((base) + (0x1ACUL))
#define SOC_HAPTIC_LRA_CFG68_ADDR(base) ((base) + (0x1B0UL))
#define SOC_HAPTIC_LRA_CFG69_ADDR(base) ((base) + (0x1B4UL))
#define SOC_HAPTIC_LRA_CFG70_ADDR(base) ((base) + (0x1B8UL))
#define SOC_HAPTIC_LRA_CFG71_ADDR(base) ((base) + (0x1BCUL))
#define SOC_HAPTIC_LRA_CFG72_ADDR(base) ((base) + (0x1C0UL))
#define SOC_HAPTIC_LRA_CFG73_ADDR(base) ((base) + (0x1C4UL))
#define SOC_HAPTIC_LRA_CFG74_ADDR(base) ((base) + (0x1C8UL))
#define SOC_HAPTIC_LRA_CFG75_ADDR(base) ((base) + (0x1CCUL))
#define SOC_HAPTIC_LRA_CFG76_ADDR(base) ((base) + (0x1D0UL))
#define SOC_HAPTIC_LRA_CFG77_ADDR(base) ((base) + (0x1D4UL))
#define SOC_HAPTIC_LRA_CFG78_ADDR(base) ((base) + (0x1D8UL))
#define SOC_HAPTIC_LRA_CFG79_ADDR(base) ((base) + (0x1DCUL))
#define SOC_HAPTIC_LRA_CFG80_ADDR(base) ((base) + (0x1E0UL))
#define SOC_HAPTIC_LRA_CFG81_ADDR(base) ((base) + (0x1E4UL))
#define SOC_HAPTIC_LRA_CFG82_ADDR(base) ((base) + (0x1E8UL))
#define SOC_HAPTIC_LRA_CFG83_ADDR(base) ((base) + (0x1ECUL))
#define SOC_HAPTIC_LRA_CFG84_ADDR(base) ((base) + (0x1F0UL))
#define SOC_HAPTIC_LRA_CFG85_ADDR(base) ((base) + (0x1F4UL))
#define SOC_HAPTIC_LRA_CFG86_ADDR(base) ((base) + (0x1F8UL))
#define SOC_HAPTIC_LRA_CFG87_ADDR(base) ((base) + (0x1FCUL))
#define SOC_HAPTIC_LRA_CFG88_ADDR(base) ((base) + (0x200UL))
#define SOC_HAPTIC_LRA_CFG89_ADDR(base) ((base) + (0x204UL))
#define SOC_HAPTIC_LRA_CFG90_ADDR(base) ((base) + (0x208UL))
#define SOC_HAPTIC_LRA_CFG91_ADDR(base) ((base) + (0x20CUL))
#define SOC_HAPTIC_LRA_CFG92_ADDR(base) ((base) + (0x210UL))
#define SOC_HAPTIC_LRA_CFG93_ADDR(base) ((base) + (0x214UL))
#define SOC_HAPTIC_LRA_CFG94_ADDR(base) ((base) + (0x218UL))
#define SOC_HAPTIC_LRA_CFG95_ADDR(base) ((base) + (0x21CUL))
#define SOC_HAPTIC_LRA_CFG96_ADDR(base) ((base) + (0x220UL))
#define SOC_HAPTIC_LRA_CFG97_ADDR(base) ((base) + (0x224UL))
#define SOC_HAPTIC_LRA_CFG98_ADDR(base) ((base) + (0x228UL))
#define SOC_HAPTIC_LRA_CFG99_ADDR(base) ((base) + (0x22CUL))
#define SOC_HAPTIC_LRA_CFG100_ADDR(base) ((base) + (0x230UL))
#define SOC_HAPTIC_LRA_CFG101_ADDR(base) ((base) + (0x234UL))
#define SOC_HAPTIC_LRA_CFG102_ADDR(base) ((base) + (0x238UL))
#define SOC_HAPTIC_LRA_CFG103_ADDR(base) ((base) + (0x23CUL))
#define SOC_HAPTIC_LRA_CFG104_ADDR(base) ((base) + (0x240UL))
#define SOC_HAPTIC_LRA_CFG105_ADDR(base) ((base) + (0x244UL))
#define SOC_HAPTIC_LRA_CFG106_ADDR(base) ((base) + (0x248UL))
#define SOC_HAPTIC_LRA_CFG107_ADDR(base) ((base) + (0x24CUL))
#define SOC_HAPTIC_LRA_CFG108_ADDR(base) ((base) + (0x250UL))
#define SOC_HAPTIC_LRA_CFG109_ADDR(base) ((base) + (0x254UL))
#define SOC_HAPTIC_LRA_CFG110_ADDR(base) ((base) + (0x258UL))
#define SOC_HAPTIC_LRA_CFG111_ADDR(base) ((base) + (0x25CUL))
#define SOC_HAPTIC_LRA_CFG112_ADDR(base) ((base) + (0x260UL))
#define SOC_HAPTIC_LRA_CFG113_ADDR(base) ((base) + (0x264UL))
#define SOC_HAPTIC_LRA_CFG114_ADDR(base) ((base) + (0x268UL))
#define SOC_HAPTIC_LRA_CFG115_ADDR(base) ((base) + (0x26CUL))
#define SOC_HAPTIC_LRA_CFG116_ADDR(base) ((base) + (0x270UL))
#define SOC_HAPTIC_LRA_CFG117_ADDR(base) ((base) + (0x274UL))
#define SOC_HAPTIC_LRA_CFG118_ADDR(base) ((base) + (0x278UL))
#define SOC_HAPTIC_LRA_CFG119_ADDR(base) ((base) + (0x27CUL))
#define SOC_HAPTIC_LRA_CFG120_ADDR(base) ((base) + (0x280UL))
#define SOC_HAPTIC_LRA_CFG121_ADDR(base) ((base) + (0x284UL))
#define SOC_HAPTIC_LRA_CFG122_ADDR(base) ((base) + (0x288UL))
#define SOC_HAPTIC_LRA_CFG123_ADDR(base) ((base) + (0x28CUL))
#define SOC_HAPTIC_LRA_CFG124_ADDR(base) ((base) + (0x290UL))
#define SOC_HAPTIC_LRA_CFG125_ADDR(base) ((base) + (0x294UL))
#define SOC_HAPTIC_LRA_CFG126_ADDR(base) ((base) + (0x298UL))
#define SOC_HAPTIC_LRA_CFG127_ADDR(base) ((base) + (0x29CUL))
#define SOC_HAPTIC_LRA_CFG128_ADDR(base) ((base) + (0x2A0UL))
#define SOC_HAPTIC_LRA_CFG129_ADDR(base) ((base) + (0x2A4UL))
#define SOC_HAPTIC_LRA_CFG130_ADDR(base) ((base) + (0x2A8UL))
#define SOC_HAPTIC_LRA_CFG131_ADDR(base) ((base) + (0x2ACUL))
#define SOC_HAPTIC_LRA_CFG132_ADDR(base) ((base) + (0x2B0UL))
#define SOC_HAPTIC_LRA_CFG133_ADDR(base) ((base) + (0x2B4UL))
#define SOC_HAPTIC_LRA_CFG134_ADDR(base) ((base) + (0x2B8UL))
#define SOC_HAPTIC_LRA_CFG135_ADDR(base) ((base) + (0x2BCUL))
#define SOC_HAPTIC_LRA_CFG136_ADDR(base) ((base) + (0x2C0UL))
#define SOC_HAPTIC_LRA_CFG137_ADDR(base) ((base) + (0x2C4UL))
#define SOC_HAPTIC_LRA_CFG138_ADDR(base) ((base) + (0x2C8UL))
#define SOC_HAPTIC_LRA_CFG139_ADDR(base) ((base) + (0x2CCUL))
#define SOC_HAPTIC_LRA_CFG140_ADDR(base) ((base) + (0x2D0UL))
#define SOC_HAPTIC_LRA_CFG141_ADDR(base) ((base) + (0x2D4UL))
#define SOC_HAPTIC_LRA_CFG142_ADDR(base) ((base) + (0x2D8UL))
#define SOC_HAPTIC_LRA_CFG143_ADDR(base) ((base) + (0x2DCUL))
#define SOC_HAPTIC_LRA_CFG144_ADDR(base) ((base) + (0x2E0UL))
#define SOC_HAPTIC_LRA_CFG145_ADDR(base) ((base) + (0x2E4UL))
#define SOC_HAPTIC_LRA_CFG146_ADDR(base) ((base) + (0x2F0UL))
#define SOC_HAPTIC_LRA_CFG147_ADDR(base) ((base) + (0x2F4UL))
#define SOC_HAPTIC_LRA_CFG148_ADDR(base) ((base) + (0x2F8UL))
#define SOC_HAPTIC_LRA_CFG149_ADDR(base) ((base) + (0x2FCUL))
#define SOC_HAPTIC_LRA_CFG150_ADDR(base) ((base) + (0x300UL))
#define SOC_HAPTIC_LRA_CFG151_ADDR(base) ((base) + (0x304UL))
#define SOC_HAPTIC_LRA_CFG152_ADDR(base) ((base) + (0x308UL))
#define SOC_HAPTIC_LRA_CFG153_ADDR(base) ((base) + (0x30CUL))
#define SOC_HAPTIC_LRA_CFG154_ADDR(base) ((base) + (0x310UL))
#define SOC_HAPTIC_LRA_CFG155_ADDR(base) ((base) + (0x314UL))
#define SOC_HAPTIC_LRA_CFG156_ADDR(base) ((base) + (0x318UL))
#define SOC_HAPTIC_LRA_CFG157_ADDR(base) ((base) + (0x31CUL))
#define SOC_HAPTIC_LRA_CFG158_ADDR(base) ((base) + (0x320UL))
#define SOC_HAPTIC_LRA_CFG159_ADDR(base) ((base) + (0x324UL))
#define SOC_HAPTIC_LRA_CFG160_ADDR(base) ((base) + (0x328UL))
#define SOC_HAPTIC_LRA_CFG161_ADDR(base) ((base) + (0x32CUL))
#define SOC_HAPTIC_LRA_CFG162_ADDR(base) ((base) + (0x330UL))
#define SOC_HAPTIC_LRA_CFG163_ADDR(base) ((base) + (0x334UL))
#define SOC_HAPTIC_LRA_CFG164_ADDR(base) ((base) + (0x338UL))
#define SOC_HAPTIC_LRA_CFG165_ADDR(base) ((base) + (0x33CUL))
#define SOC_HAPTIC_LRA_CFG166_ADDR(base) ((base) + (0x340UL))
#define SOC_HAPTIC_LRA_CFG167_ADDR(base) ((base) + (0x344UL))
#define SOC_HAPTIC_LRA_CFG168_ADDR(base) ((base) + (0x348UL))
#define SOC_HAPTIC_LRA_CFG169_ADDR(base) ((base) + (0x34CUL))
#define SOC_HAPTIC_LRA_CFG170_ADDR(base) ((base) + (0x350UL))
#define SOC_HAPTIC_LRA_CFG171_ADDR(base) ((base) + (0x354UL))
#define SOC_HAPTIC_LRA_CFG172_ADDR(base) ((base) + (0x358UL))
#define SOC_HAPTIC_LRA_CFG173_ADDR(base) ((base) + (0x35CUL))
#define SOC_HAPTIC_LRA_CFG174_ADDR(base) ((base) + (0x360UL))
#define SOC_HAPTIC_LRA_CFG175_ADDR(base) ((base) + (0x364UL))
#define SOC_HAPTIC_LRA_CFG176_ADDR(base) ((base) + (0x368UL))
#define SOC_HAPTIC_LRA_CFG177_ADDR(base) ((base) + (0x36CUL))
#define SOC_HAPTIC_LRA_CFG178_ADDR(base) ((base) + (0x370UL))
#define SOC_HAPTIC_LRA_CFG179_ADDR(base) ((base) + (0x374UL))
#define SOC_HAPTIC_LRA_CFG180_ADDR(base) ((base) + (0x378UL))
#define SOC_HAPTIC_LRA_CFG181_ADDR(base) ((base) + (0x37CUL))
#define SOC_HAPTIC_LRA_CFG182_ADDR(base) ((base) + (0x380UL))
#define SOC_HAPTIC_LRA_CFG183_ADDR(base) ((base) + (0x384UL))
#define SOC_HAPTIC_LRA_CFG184_ADDR(base) ((base) + (0x388UL))
#define SOC_HAPTIC_LRA_CFG185_ADDR(base) ((base) + (0x38CUL))
#define SOC_HAPTIC_LRA_CFG186_ADDR(base) ((base) + (0x390UL))
#define SOC_HAPTIC_LRA_CFG187_ADDR(base) ((base) + (0x394UL))
#define SOC_HAPTIC_LRA_CFG188_ADDR(base) ((base) + (0x398UL))
#define SOC_HAPTIC_LRA_CFG189_ADDR(base) ((base) + (0x39CUL))
#define SOC_HAPTIC_LRA_CFG190_ADDR(base) ((base) + (0x3A0UL))
#define SOC_HAPTIC_LRA_CFG191_ADDR(base) ((base) + (0x3A4UL))
#define SOC_HAPTIC_LRA_CFG192_ADDR(base) ((base) + (0x3A8UL))
#define SOC_HAPTIC_LRA_CFG193_ADDR(base) ((base) + (0x3ACUL))
#define SOC_HAPTIC_LRA_CFG194_ADDR(base) ((base) + (0x3B0UL))
#define SOC_HAPTIC_LRA_CFG195_ADDR(base) ((base) + (0x3B4UL))
#define SOC_HAPTIC_LRA_CFG196_ADDR(base) ((base) + (0x3B8UL))
#define SOC_HAPTIC_LRA_CFG197_ADDR(base) ((base) + (0x3BCUL))
#else
#define SOC_HAPTIC_LRA_BYPASS_CFG_ADDR(base) ((base) + (0x000))
#define SOC_HAPTIC_LRA_CLK_RST_CFG_ADDR(base) ((base) + (0x004))
#define SOC_HAPTIC_LRA_CLK_CG_EN_ADDR(base) ((base) + (0x008))
#define SOC_HAPTIC_LRA_INTR_STAT_REG_ADDR(base) ((base) + (0x00C))
#define SOC_HAPTIC_LRA_PRT_SWITCH_CFG_ADDR(base) ((base) + (0x010))
#define SOC_HAPTIC_LRA_LP_CFG0_ADDR(base) ((base) + (0x014))
#define SOC_HAPTIC_LRA_LP_CFG1_ADDR(base) ((base) + (0x018))
#define SOC_HAPTIC_LRA_LP_CFG2_ADDR(base) ((base) + (0x01C))
#define SOC_HAPTIC_LRA_LP_CFG3_ADDR(base) ((base) + (0x020))
#define SOC_HAPTIC_LRA_LP_CFG4_ADDR(base) ((base) + (0x024))
#define SOC_HAPTIC_LRA_LP_CFG5_ADDR(base) ((base) + (0x028))
#define SOC_HAPTIC_LRA_LP_CFG6_ADDR(base) ((base) + (0x02C))
#define SOC_HAPTIC_LRA_LP_CFG7_ADDR(base) ((base) + (0x030))
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_ADDR(base) ((base) + (0x034))
#define SOC_HAPTIC_LRA_RO_STATE0_ADDR(base) ((base) + (0x038))
#define SOC_HAPTIC_LRA_RO_STATE1_ADDR(base) ((base) + (0x03C))
#define SOC_HAPTIC_LRA_RO_STATE2_ADDR(base) ((base) + (0x040))
#define SOC_HAPTIC_LRA_RO_STATE3_ADDR(base) ((base) + (0x044))
#define SOC_HAPTIC_LRA_RO_STATE4_ADDR(base) ((base) + (0x048))
#define SOC_HAPTIC_LRA_RO_STATE5_ADDR(base) ((base) + (0x04C))
#define SOC_HAPTIC_LRA_RO_STATE6_ADDR(base) ((base) + (0x050))
#define SOC_HAPTIC_LRA_RO_STATE7_ADDR(base) ((base) + (0x054))
#define SOC_HAPTIC_LRA_RO_STATE8_ADDR(base) ((base) + (0x058))
#define SOC_HAPTIC_LRA_RO_STATE9_ADDR(base) ((base) + (0x05C))
#define SOC_HAPTIC_LRA_RO_STATE10_ADDR(base) ((base) + (0x060))
#define SOC_HAPTIC_LRA_RO_STATE11_ADDR(base) ((base) + (0x064))
#define SOC_HAPTIC_LRA_RO_STATE12_ADDR(base) ((base) + (0x068))
#define SOC_HAPTIC_LRA_RO_STATE13_ADDR(base) ((base) + (0x06C))
#define SOC_HAPTIC_LRA_RO_STATE14_ADDR(base) ((base) + (0x070))
#define SOC_HAPTIC_LRA_CFG0_ADDR(base) ((base) + (0x0A0))
#define SOC_HAPTIC_LRA_CFG1_ADDR(base) ((base) + (0x0A4))
#define SOC_HAPTIC_LRA_CFG2_ADDR(base) ((base) + (0x0A8))
#define SOC_HAPTIC_LRA_CFG3_ADDR(base) ((base) + (0x0AC))
#define SOC_HAPTIC_LRA_CFG4_ADDR(base) ((base) + (0x0B0))
#define SOC_HAPTIC_LRA_CFG5_ADDR(base) ((base) + (0x0B4))
#define SOC_HAPTIC_LRA_CFG6_ADDR(base) ((base) + (0x0B8))
#define SOC_HAPTIC_LRA_CFG7_ADDR(base) ((base) + (0x0BC))
#define SOC_HAPTIC_LRA_CFG8_ADDR(base) ((base) + (0x0C0))
#define SOC_HAPTIC_LRA_CFG9_ADDR(base) ((base) + (0x0C4))
#define SOC_HAPTIC_LRA_CFG10_ADDR(base) ((base) + (0x0C8))
#define SOC_HAPTIC_LRA_CFG11_ADDR(base) ((base) + (0x0CC))
#define SOC_HAPTIC_LRA_CFG12_ADDR(base) ((base) + (0x0D0))
#define SOC_HAPTIC_LRA_CFG13_ADDR(base) ((base) + (0x0D4))
#define SOC_HAPTIC_LRA_CFG14_ADDR(base) ((base) + (0x0D8))
#define SOC_HAPTIC_LRA_CFG15_ADDR(base) ((base) + (0x0DC))
#define SOC_HAPTIC_LRA_CFG16_ADDR(base) ((base) + (0x0E0))
#define SOC_HAPTIC_LRA_CFG17_ADDR(base) ((base) + (0x0E4))
#define SOC_HAPTIC_LRA_CFG18_ADDR(base) ((base) + (0x0E8))
#define SOC_HAPTIC_LRA_CFG19_ADDR(base) ((base) + (0x0EC))
#define SOC_HAPTIC_LRA_CFG20_ADDR(base) ((base) + (0x0F0))
#define SOC_HAPTIC_LRA_CFG21_ADDR(base) ((base) + (0x0F4))
#define SOC_HAPTIC_LRA_CFG22_ADDR(base) ((base) + (0x0F8))
#define SOC_HAPTIC_LRA_CFG23_ADDR(base) ((base) + (0x0FC))
#define SOC_HAPTIC_LRA_CFG24_ADDR(base) ((base) + (0x100))
#define SOC_HAPTIC_LRA_CFG25_ADDR(base) ((base) + (0x104))
#define SOC_HAPTIC_LRA_CFG26_ADDR(base) ((base) + (0x108))
#define SOC_HAPTIC_LRA_CFG27_ADDR(base) ((base) + (0x10C))
#define SOC_HAPTIC_LRA_CFG28_ADDR(base) ((base) + (0x110))
#define SOC_HAPTIC_LRA_CFG29_ADDR(base) ((base) + (0x114))
#define SOC_HAPTIC_LRA_CFG30_ADDR(base) ((base) + (0x118))
#define SOC_HAPTIC_LRA_CFG31_ADDR(base) ((base) + (0x11C))
#define SOC_HAPTIC_LRA_CFG32_ADDR(base) ((base) + (0x120))
#define SOC_HAPTIC_LRA_CFG33_ADDR(base) ((base) + (0x124))
#define SOC_HAPTIC_LRA_CFG34_ADDR(base) ((base) + (0x128))
#define SOC_HAPTIC_LRA_CFG35_ADDR(base) ((base) + (0x12C))
#define SOC_HAPTIC_LRA_CFG36_ADDR(base) ((base) + (0x130))
#define SOC_HAPTIC_LRA_CFG37_ADDR(base) ((base) + (0x134))
#define SOC_HAPTIC_LRA_CFG38_ADDR(base) ((base) + (0x138))
#define SOC_HAPTIC_LRA_CFG39_ADDR(base) ((base) + (0x13C))
#define SOC_HAPTIC_LRA_CFG40_ADDR(base) ((base) + (0x140))
#define SOC_HAPTIC_LRA_CFG41_ADDR(base) ((base) + (0x144))
#define SOC_HAPTIC_LRA_CFG42_ADDR(base) ((base) + (0x148))
#define SOC_HAPTIC_LRA_CFG43_ADDR(base) ((base) + (0x14C))
#define SOC_HAPTIC_LRA_CFG44_ADDR(base) ((base) + (0x150))
#define SOC_HAPTIC_LRA_CFG45_ADDR(base) ((base) + (0x154))
#define SOC_HAPTIC_LRA_CFG46_ADDR(base) ((base) + (0x158))
#define SOC_HAPTIC_LRA_CFG47_ADDR(base) ((base) + (0x15C))
#define SOC_HAPTIC_LRA_CFG48_ADDR(base) ((base) + (0x160))
#define SOC_HAPTIC_LRA_CFG49_ADDR(base) ((base) + (0x164))
#define SOC_HAPTIC_LRA_CFG50_ADDR(base) ((base) + (0x168))
#define SOC_HAPTIC_LRA_CFG51_ADDR(base) ((base) + (0x16C))
#define SOC_HAPTIC_LRA_CFG52_ADDR(base) ((base) + (0x170))
#define SOC_HAPTIC_LRA_CFG53_ADDR(base) ((base) + (0x174))
#define SOC_HAPTIC_LRA_CFG54_ADDR(base) ((base) + (0x178))
#define SOC_HAPTIC_LRA_CFG55_ADDR(base) ((base) + (0x17C))
#define SOC_HAPTIC_LRA_CFG56_ADDR(base) ((base) + (0x180))
#define SOC_HAPTIC_LRA_CFG57_ADDR(base) ((base) + (0x184))
#define SOC_HAPTIC_LRA_CFG58_ADDR(base) ((base) + (0x188))
#define SOC_HAPTIC_LRA_CFG59_ADDR(base) ((base) + (0x18C))
#define SOC_HAPTIC_LRA_CFG60_ADDR(base) ((base) + (0x190))
#define SOC_HAPTIC_LRA_CFG61_ADDR(base) ((base) + (0x194))
#define SOC_HAPTIC_LRA_CFG62_ADDR(base) ((base) + (0x198))
#define SOC_HAPTIC_LRA_CFG63_ADDR(base) ((base) + (0x19C))
#define SOC_HAPTIC_LRA_CFG64_ADDR(base) ((base) + (0x1A0))
#define SOC_HAPTIC_LRA_CFG65_ADDR(base) ((base) + (0x1A4))
#define SOC_HAPTIC_LRA_CFG66_ADDR(base) ((base) + (0x1A8))
#define SOC_HAPTIC_LRA_CFG67_ADDR(base) ((base) + (0x1AC))
#define SOC_HAPTIC_LRA_CFG68_ADDR(base) ((base) + (0x1B0))
#define SOC_HAPTIC_LRA_CFG69_ADDR(base) ((base) + (0x1B4))
#define SOC_HAPTIC_LRA_CFG70_ADDR(base) ((base) + (0x1B8))
#define SOC_HAPTIC_LRA_CFG71_ADDR(base) ((base) + (0x1BC))
#define SOC_HAPTIC_LRA_CFG72_ADDR(base) ((base) + (0x1C0))
#define SOC_HAPTIC_LRA_CFG73_ADDR(base) ((base) + (0x1C4))
#define SOC_HAPTIC_LRA_CFG74_ADDR(base) ((base) + (0x1C8))
#define SOC_HAPTIC_LRA_CFG75_ADDR(base) ((base) + (0x1CC))
#define SOC_HAPTIC_LRA_CFG76_ADDR(base) ((base) + (0x1D0))
#define SOC_HAPTIC_LRA_CFG77_ADDR(base) ((base) + (0x1D4))
#define SOC_HAPTIC_LRA_CFG78_ADDR(base) ((base) + (0x1D8))
#define SOC_HAPTIC_LRA_CFG79_ADDR(base) ((base) + (0x1DC))
#define SOC_HAPTIC_LRA_CFG80_ADDR(base) ((base) + (0x1E0))
#define SOC_HAPTIC_LRA_CFG81_ADDR(base) ((base) + (0x1E4))
#define SOC_HAPTIC_LRA_CFG82_ADDR(base) ((base) + (0x1E8))
#define SOC_HAPTIC_LRA_CFG83_ADDR(base) ((base) + (0x1EC))
#define SOC_HAPTIC_LRA_CFG84_ADDR(base) ((base) + (0x1F0))
#define SOC_HAPTIC_LRA_CFG85_ADDR(base) ((base) + (0x1F4))
#define SOC_HAPTIC_LRA_CFG86_ADDR(base) ((base) + (0x1F8))
#define SOC_HAPTIC_LRA_CFG87_ADDR(base) ((base) + (0x1FC))
#define SOC_HAPTIC_LRA_CFG88_ADDR(base) ((base) + (0x200))
#define SOC_HAPTIC_LRA_CFG89_ADDR(base) ((base) + (0x204))
#define SOC_HAPTIC_LRA_CFG90_ADDR(base) ((base) + (0x208))
#define SOC_HAPTIC_LRA_CFG91_ADDR(base) ((base) + (0x20C))
#define SOC_HAPTIC_LRA_CFG92_ADDR(base) ((base) + (0x210))
#define SOC_HAPTIC_LRA_CFG93_ADDR(base) ((base) + (0x214))
#define SOC_HAPTIC_LRA_CFG94_ADDR(base) ((base) + (0x218))
#define SOC_HAPTIC_LRA_CFG95_ADDR(base) ((base) + (0x21C))
#define SOC_HAPTIC_LRA_CFG96_ADDR(base) ((base) + (0x220))
#define SOC_HAPTIC_LRA_CFG97_ADDR(base) ((base) + (0x224))
#define SOC_HAPTIC_LRA_CFG98_ADDR(base) ((base) + (0x228))
#define SOC_HAPTIC_LRA_CFG99_ADDR(base) ((base) + (0x22C))
#define SOC_HAPTIC_LRA_CFG100_ADDR(base) ((base) + (0x230))
#define SOC_HAPTIC_LRA_CFG101_ADDR(base) ((base) + (0x234))
#define SOC_HAPTIC_LRA_CFG102_ADDR(base) ((base) + (0x238))
#define SOC_HAPTIC_LRA_CFG103_ADDR(base) ((base) + (0x23C))
#define SOC_HAPTIC_LRA_CFG104_ADDR(base) ((base) + (0x240))
#define SOC_HAPTIC_LRA_CFG105_ADDR(base) ((base) + (0x244))
#define SOC_HAPTIC_LRA_CFG106_ADDR(base) ((base) + (0x248))
#define SOC_HAPTIC_LRA_CFG107_ADDR(base) ((base) + (0x24C))
#define SOC_HAPTIC_LRA_CFG108_ADDR(base) ((base) + (0x250))
#define SOC_HAPTIC_LRA_CFG109_ADDR(base) ((base) + (0x254))
#define SOC_HAPTIC_LRA_CFG110_ADDR(base) ((base) + (0x258))
#define SOC_HAPTIC_LRA_CFG111_ADDR(base) ((base) + (0x25C))
#define SOC_HAPTIC_LRA_CFG112_ADDR(base) ((base) + (0x260))
#define SOC_HAPTIC_LRA_CFG113_ADDR(base) ((base) + (0x264))
#define SOC_HAPTIC_LRA_CFG114_ADDR(base) ((base) + (0x268))
#define SOC_HAPTIC_LRA_CFG115_ADDR(base) ((base) + (0x26C))
#define SOC_HAPTIC_LRA_CFG116_ADDR(base) ((base) + (0x270))
#define SOC_HAPTIC_LRA_CFG117_ADDR(base) ((base) + (0x274))
#define SOC_HAPTIC_LRA_CFG118_ADDR(base) ((base) + (0x278))
#define SOC_HAPTIC_LRA_CFG119_ADDR(base) ((base) + (0x27C))
#define SOC_HAPTIC_LRA_CFG120_ADDR(base) ((base) + (0x280))
#define SOC_HAPTIC_LRA_CFG121_ADDR(base) ((base) + (0x284))
#define SOC_HAPTIC_LRA_CFG122_ADDR(base) ((base) + (0x288))
#define SOC_HAPTIC_LRA_CFG123_ADDR(base) ((base) + (0x28C))
#define SOC_HAPTIC_LRA_CFG124_ADDR(base) ((base) + (0x290))
#define SOC_HAPTIC_LRA_CFG125_ADDR(base) ((base) + (0x294))
#define SOC_HAPTIC_LRA_CFG126_ADDR(base) ((base) + (0x298))
#define SOC_HAPTIC_LRA_CFG127_ADDR(base) ((base) + (0x29C))
#define SOC_HAPTIC_LRA_CFG128_ADDR(base) ((base) + (0x2A0))
#define SOC_HAPTIC_LRA_CFG129_ADDR(base) ((base) + (0x2A4))
#define SOC_HAPTIC_LRA_CFG130_ADDR(base) ((base) + (0x2A8))
#define SOC_HAPTIC_LRA_CFG131_ADDR(base) ((base) + (0x2AC))
#define SOC_HAPTIC_LRA_CFG132_ADDR(base) ((base) + (0x2B0))
#define SOC_HAPTIC_LRA_CFG133_ADDR(base) ((base) + (0x2B4))
#define SOC_HAPTIC_LRA_CFG134_ADDR(base) ((base) + (0x2B8))
#define SOC_HAPTIC_LRA_CFG135_ADDR(base) ((base) + (0x2BC))
#define SOC_HAPTIC_LRA_CFG136_ADDR(base) ((base) + (0x2C0))
#define SOC_HAPTIC_LRA_CFG137_ADDR(base) ((base) + (0x2C4))
#define SOC_HAPTIC_LRA_CFG138_ADDR(base) ((base) + (0x2C8))
#define SOC_HAPTIC_LRA_CFG139_ADDR(base) ((base) + (0x2CC))
#define SOC_HAPTIC_LRA_CFG140_ADDR(base) ((base) + (0x2D0))
#define SOC_HAPTIC_LRA_CFG141_ADDR(base) ((base) + (0x2D4))
#define SOC_HAPTIC_LRA_CFG142_ADDR(base) ((base) + (0x2D8))
#define SOC_HAPTIC_LRA_CFG143_ADDR(base) ((base) + (0x2DC))
#define SOC_HAPTIC_LRA_CFG144_ADDR(base) ((base) + (0x2E0))
#define SOC_HAPTIC_LRA_CFG145_ADDR(base) ((base) + (0x2E4))
#define SOC_HAPTIC_LRA_CFG146_ADDR(base) ((base) + (0x2F0))
#define SOC_HAPTIC_LRA_CFG147_ADDR(base) ((base) + (0x2F4))
#define SOC_HAPTIC_LRA_CFG148_ADDR(base) ((base) + (0x2F8))
#define SOC_HAPTIC_LRA_CFG149_ADDR(base) ((base) + (0x2FC))
#define SOC_HAPTIC_LRA_CFG150_ADDR(base) ((base) + (0x300))
#define SOC_HAPTIC_LRA_CFG151_ADDR(base) ((base) + (0x304))
#define SOC_HAPTIC_LRA_CFG152_ADDR(base) ((base) + (0x308))
#define SOC_HAPTIC_LRA_CFG153_ADDR(base) ((base) + (0x30C))
#define SOC_HAPTIC_LRA_CFG154_ADDR(base) ((base) + (0x310))
#define SOC_HAPTIC_LRA_CFG155_ADDR(base) ((base) + (0x314))
#define SOC_HAPTIC_LRA_CFG156_ADDR(base) ((base) + (0x318))
#define SOC_HAPTIC_LRA_CFG157_ADDR(base) ((base) + (0x31C))
#define SOC_HAPTIC_LRA_CFG158_ADDR(base) ((base) + (0x320))
#define SOC_HAPTIC_LRA_CFG159_ADDR(base) ((base) + (0x324))
#define SOC_HAPTIC_LRA_CFG160_ADDR(base) ((base) + (0x328))
#define SOC_HAPTIC_LRA_CFG161_ADDR(base) ((base) + (0x32C))
#define SOC_HAPTIC_LRA_CFG162_ADDR(base) ((base) + (0x330))
#define SOC_HAPTIC_LRA_CFG163_ADDR(base) ((base) + (0x334))
#define SOC_HAPTIC_LRA_CFG164_ADDR(base) ((base) + (0x338))
#define SOC_HAPTIC_LRA_CFG165_ADDR(base) ((base) + (0x33C))
#define SOC_HAPTIC_LRA_CFG166_ADDR(base) ((base) + (0x340))
#define SOC_HAPTIC_LRA_CFG167_ADDR(base) ((base) + (0x344))
#define SOC_HAPTIC_LRA_CFG168_ADDR(base) ((base) + (0x348))
#define SOC_HAPTIC_LRA_CFG169_ADDR(base) ((base) + (0x34C))
#define SOC_HAPTIC_LRA_CFG170_ADDR(base) ((base) + (0x350))
#define SOC_HAPTIC_LRA_CFG171_ADDR(base) ((base) + (0x354))
#define SOC_HAPTIC_LRA_CFG172_ADDR(base) ((base) + (0x358))
#define SOC_HAPTIC_LRA_CFG173_ADDR(base) ((base) + (0x35C))
#define SOC_HAPTIC_LRA_CFG174_ADDR(base) ((base) + (0x360))
#define SOC_HAPTIC_LRA_CFG175_ADDR(base) ((base) + (0x364))
#define SOC_HAPTIC_LRA_CFG176_ADDR(base) ((base) + (0x368))
#define SOC_HAPTIC_LRA_CFG177_ADDR(base) ((base) + (0x36C))
#define SOC_HAPTIC_LRA_CFG178_ADDR(base) ((base) + (0x370))
#define SOC_HAPTIC_LRA_CFG179_ADDR(base) ((base) + (0x374))
#define SOC_HAPTIC_LRA_CFG180_ADDR(base) ((base) + (0x378))
#define SOC_HAPTIC_LRA_CFG181_ADDR(base) ((base) + (0x37C))
#define SOC_HAPTIC_LRA_CFG182_ADDR(base) ((base) + (0x380))
#define SOC_HAPTIC_LRA_CFG183_ADDR(base) ((base) + (0x384))
#define SOC_HAPTIC_LRA_CFG184_ADDR(base) ((base) + (0x388))
#define SOC_HAPTIC_LRA_CFG185_ADDR(base) ((base) + (0x38C))
#define SOC_HAPTIC_LRA_CFG186_ADDR(base) ((base) + (0x390))
#define SOC_HAPTIC_LRA_CFG187_ADDR(base) ((base) + (0x394))
#define SOC_HAPTIC_LRA_CFG188_ADDR(base) ((base) + (0x398))
#define SOC_HAPTIC_LRA_CFG189_ADDR(base) ((base) + (0x39C))
#define SOC_HAPTIC_LRA_CFG190_ADDR(base) ((base) + (0x3A0))
#define SOC_HAPTIC_LRA_CFG191_ADDR(base) ((base) + (0x3A4))
#define SOC_HAPTIC_LRA_CFG192_ADDR(base) ((base) + (0x3A8))
#define SOC_HAPTIC_LRA_CFG193_ADDR(base) ((base) + (0x3AC))
#define SOC_HAPTIC_LRA_CFG194_ADDR(base) ((base) + (0x3B0))
#define SOC_HAPTIC_LRA_CFG195_ADDR(base) ((base) + (0x3B4))
#define SOC_HAPTIC_LRA_CFG196_ADDR(base) ((base) + (0x3B8))
#define SOC_HAPTIC_LRA_CFG197_ADDR(base) ((base) + (0x3BC))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_bypass : 1;
        unsigned int cfg_lra_calcf_bypass : 1;
        unsigned int cfg_lra_pre_plt_bypass : 1;
        unsigned int cfg_lra_pga_bypass : 1;
        unsigned int cfg_lra_plt_dly_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cfg_lra_geq6_bypass : 1;
        unsigned int cfg_lra_bgc_bypass : 1;
        unsigned int cfg_lra_bcn_bypass : 1;
        unsigned int cfg_lra_lmt_bypass : 1;
        unsigned int cfg_lra_plt_bypass : 1;
        unsigned int cfg_lra_srcup_bypass : 1;
        unsigned int cfg_lra_cicdn_bypass : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int cfg_lra_prt_bypass : 1;
        unsigned int reserved_4 : 13;
        unsigned int audio_haptic_plt_sin_fade_bypass : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_HAPTIC_LRA_BYPASS_CFG_UNION;
#endif
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_brake_bypass_START (0)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_brake_bypass_END (0)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_calcf_bypass_START (1)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_calcf_bypass_END (1)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_pre_plt_bypass_START (2)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_pre_plt_bypass_END (2)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_pga_bypass_START (3)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_pga_bypass_END (3)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_plt_dly_bypass_START (4)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_plt_dly_bypass_END (4)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_geq6_bypass_START (7)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_geq6_bypass_END (7)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_bgc_bypass_START (8)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_bgc_bypass_END (8)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_bcn_bypass_START (9)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_bcn_bypass_END (9)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_lmt_bypass_START (10)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_lmt_bypass_END (10)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_plt_bypass_START (11)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_plt_bypass_END (11)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_srcup_bypass_START (12)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_srcup_bypass_END (12)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_cicdn_bypass_START (13)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_cicdn_bypass_END (13)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_prt_bypass_START (16)
#define SOC_HAPTIC_LRA_BYPASS_CFG_cfg_lra_prt_bypass_END (16)
#define SOC_HAPTIC_LRA_BYPASS_CFG_audio_haptic_plt_sin_fade_bypass_START (30)
#define SOC_HAPTIC_LRA_BYPASS_CFG_audio_haptic_plt_sin_fade_bypass_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audio_haptic_brake_clk_rst_en : 1;
        unsigned int audio_haptic_calcf_clk_rst_en : 1;
        unsigned int audio_haptic_pre_plt_clk_rst_en : 1;
        unsigned int audio_haptic_pga_clk_rst_en : 1;
        unsigned int audio_haptic_plt_dly_clk_rst_en : 1;
        unsigned int audio_haptic_mixer_clk_rst_en : 1;
        unsigned int audio_haptic_lp_buffer_clk_rst_en : 1;
        unsigned int audio_haptic_geq6_clk_rst_en : 1;
        unsigned int audio_haptic_bgc_clk_rst_en : 1;
        unsigned int audio_haptic_bcn_clk_rst_en : 1;
        unsigned int audio_haptic_lmt_clk_rst_en : 1;
        unsigned int audio_haptic_plt_clk_rst_en : 1;
        unsigned int audio_haptic_srcup_clk_rst_en : 1;
        unsigned int audio_haptic_cicdn_clk_rst_en : 1;
        unsigned int audio_haptic_lp_ctrl_clk_rst_en : 1;
        unsigned int audio_haptic_prt_misc_clk_rst_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 13;
        unsigned int reserved_2 : 1;
        unsigned int audio_haptic_data_path_clk_rst_en : 1;
    } reg;
} SOC_HAPTIC_LRA_CLK_RST_CFG_UNION;
#endif
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_brake_clk_rst_en_START (0)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_brake_clk_rst_en_END (0)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_calcf_clk_rst_en_START (1)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_calcf_clk_rst_en_END (1)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_pre_plt_clk_rst_en_START (2)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_pre_plt_clk_rst_en_END (2)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_pga_clk_rst_en_START (3)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_pga_clk_rst_en_END (3)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_plt_dly_clk_rst_en_START (4)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_plt_dly_clk_rst_en_END (4)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_mixer_clk_rst_en_START (5)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_mixer_clk_rst_en_END (5)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_lp_buffer_clk_rst_en_START (6)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_lp_buffer_clk_rst_en_END (6)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_geq6_clk_rst_en_START (7)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_geq6_clk_rst_en_END (7)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_bgc_clk_rst_en_START (8)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_bgc_clk_rst_en_END (8)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_bcn_clk_rst_en_START (9)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_bcn_clk_rst_en_END (9)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_lmt_clk_rst_en_START (10)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_lmt_clk_rst_en_END (10)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_plt_clk_rst_en_START (11)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_plt_clk_rst_en_END (11)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_srcup_clk_rst_en_START (12)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_srcup_clk_rst_en_END (12)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_cicdn_clk_rst_en_START (13)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_cicdn_clk_rst_en_END (13)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_lp_ctrl_clk_rst_en_START (14)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_lp_ctrl_clk_rst_en_END (14)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_prt_misc_clk_rst_en_START (15)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_prt_misc_clk_rst_en_END (15)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_data_path_clk_rst_en_START (31)
#define SOC_HAPTIC_LRA_CLK_RST_CFG_audio_haptic_data_path_clk_rst_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audio_haptic_brake_cg_en : 1;
        unsigned int audio_haptic_calcf_cg_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int audio_haptic_plt_dly_cg_en : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int audio_haptic_geq6_cg_en : 1;
        unsigned int audio_haptic_bgc_cg_en : 1;
        unsigned int audio_haptic_bcn_cg_en : 1;
        unsigned int audio_haptic_lmt_cg_en : 1;
        unsigned int audio_haptic_plt_cg_en : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 13;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
    } reg;
} SOC_HAPTIC_LRA_CLK_CG_EN_UNION;
#endif
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_brake_cg_en_START (0)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_brake_cg_en_END (0)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_calcf_cg_en_START (1)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_calcf_cg_en_END (1)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_plt_dly_cg_en_START (4)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_plt_dly_cg_en_END (4)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_geq6_cg_en_START (7)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_geq6_cg_en_END (7)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_bgc_cg_en_START (8)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_bgc_cg_en_END (8)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_bcn_cg_en_START (9)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_bcn_cg_en_END (9)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_lmt_cg_en_START (10)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_lmt_cg_en_END (10)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_plt_cg_en_START (11)
#define SOC_HAPTIC_LRA_CLK_CG_EN_audio_haptic_plt_cg_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audio_haptic_brake_finish : 1;
        unsigned int cfg_audio_haptic_brake_auto_brake_debug : 1;
        unsigned int cfg_audio_haptic_brake_intr_brake_debug : 1;
        unsigned int reserved_0 : 1;
        unsigned int audio_haptic_calcf_finish : 1;
        unsigned int cfg_audio_haptic_f0_process_distubed_debug : 1;
        unsigned int cfg_audio_haptic_f0_disturb_brk_vib_debug : 1;
        unsigned int reserved_1 : 1;
        unsigned int audio_haptic_brake_finish_mask : 1;
        unsigned int cfg_audio_haptic_brake_auto_brake_debug_mask : 1;
        unsigned int cfg_audio_haptic_brake_intr_brake_debug_mask : 1;
        unsigned int reserved_2 : 1;
        unsigned int audio_haptic_calcf_finish_mask : 1;
        unsigned int cfg_audio_haptic_f0_process_distubed_debug_mask : 1;
        unsigned int cfg_audio_haptic_f0_disturb_brk_vib_debug_mask : 1;
        unsigned int reserved_3 : 1;
        unsigned int audio_haptic_brake_finish_mstat : 1;
        unsigned int cfg_audio_haptic_brake_auto_brake_debug_mstat : 1;
        unsigned int cfg_audio_haptic_brake_intr_brake_debug_mstat : 1;
        unsigned int reserved_4 : 1;
        unsigned int audio_haptic_calcf_finish_mstat : 1;
        unsigned int cfg_audio_haptic_f0_process_distubed_debug_mstat : 1;
        unsigned int cfg_audio_haptic_f0_disturb_brk_vib_debug_mstat : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 8;
    } reg;
} SOC_HAPTIC_LRA_INTR_STAT_REG_UNION;
#endif
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_brake_finish_START (0)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_brake_finish_END (0)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_auto_brake_debug_START (1)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_auto_brake_debug_END (1)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_intr_brake_debug_START (2)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_intr_brake_debug_END (2)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_calcf_finish_START (4)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_calcf_finish_END (4)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_process_distubed_debug_START (5)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_process_distubed_debug_END (5)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_disturb_brk_vib_debug_START (6)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_disturb_brk_vib_debug_END (6)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_brake_finish_mask_START (8)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_brake_finish_mask_END (8)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_auto_brake_debug_mask_START (9)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_auto_brake_debug_mask_END (9)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_intr_brake_debug_mask_START (10)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_intr_brake_debug_mask_END (10)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_calcf_finish_mask_START (12)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_calcf_finish_mask_END (12)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_process_distubed_debug_mask_START (13)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_process_distubed_debug_mask_END (13)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_disturb_brk_vib_debug_mask_START (14)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_disturb_brk_vib_debug_mask_END (14)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_brake_finish_mstat_START (16)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_brake_finish_mstat_END (16)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_auto_brake_debug_mstat_START (17)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_auto_brake_debug_mstat_END (17)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_intr_brake_debug_mstat_START (18)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_brake_intr_brake_debug_mstat_END (18)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_calcf_finish_mstat_START (20)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_audio_haptic_calcf_finish_mstat_END (20)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_process_distubed_debug_mstat_START (21)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_process_distubed_debug_mstat_END (21)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_disturb_brk_vib_debug_mstat_START (22)
#define SOC_HAPTIC_LRA_INTR_STAT_REG_cfg_audio_haptic_f0_disturb_brk_vib_debug_mstat_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_prt_para_passthrough_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HAPTIC_LRA_PRT_SWITCH_CFG_UNION;
#endif
#define SOC_HAPTIC_LRA_PRT_SWITCH_CFG_cfg_audio_haptic_prt_para_passthrough_en_START (0)
#define SOC_HAPTIC_LRA_PRT_SWITCH_CFG_cfg_audio_haptic_prt_para_passthrough_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_lp_i2s : 1;
        unsigned int cfg_audio_haptic_lp_pa : 1;
        unsigned int reserved : 29;
        unsigned int cfg_audio_haptic_delay_chain_clr : 1;
    } reg;
} SOC_HAPTIC_LRA_LP_CFG0_UNION;
#endif
#define SOC_HAPTIC_LRA_LP_CFG0_cfg_audio_haptic_lp_i2s_START (0)
#define SOC_HAPTIC_LRA_LP_CFG0_cfg_audio_haptic_lp_i2s_END (0)
#define SOC_HAPTIC_LRA_LP_CFG0_cfg_audio_haptic_lp_pa_START (1)
#define SOC_HAPTIC_LRA_LP_CFG0_cfg_audio_haptic_lp_pa_END (1)
#define SOC_HAPTIC_LRA_LP_CFG0_cfg_audio_haptic_delay_chain_clr_START (31)
#define SOC_HAPTIC_LRA_LP_CFG0_cfg_audio_haptic_delay_chain_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_stream_start_dly_cnt_i2s : 10;
        unsigned int reserved_0 : 6;
        unsigned int cfg_audio_haptic_stream_end_dly_cnt_i2s : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HAPTIC_LRA_LP_CFG1_UNION;
#endif
#define SOC_HAPTIC_LRA_LP_CFG1_cfg_audio_haptic_stream_start_dly_cnt_i2s_START (0)
#define SOC_HAPTIC_LRA_LP_CFG1_cfg_audio_haptic_stream_start_dly_cnt_i2s_END (9)
#define SOC_HAPTIC_LRA_LP_CFG1_cfg_audio_haptic_stream_end_dly_cnt_i2s_START (16)
#define SOC_HAPTIC_LRA_LP_CFG1_cfg_audio_haptic_stream_end_dly_cnt_i2s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_brake_start_dly_cnt_i2s : 10;
        unsigned int reserved_0 : 6;
        unsigned int cfg_audio_haptic_brake_end_dly_cnt_i2s : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HAPTIC_LRA_LP_CFG2_UNION;
#endif
#define SOC_HAPTIC_LRA_LP_CFG2_cfg_audio_haptic_brake_start_dly_cnt_i2s_START (0)
#define SOC_HAPTIC_LRA_LP_CFG2_cfg_audio_haptic_brake_start_dly_cnt_i2s_END (9)
#define SOC_HAPTIC_LRA_LP_CFG2_cfg_audio_haptic_brake_end_dly_cnt_i2s_START (16)
#define SOC_HAPTIC_LRA_LP_CFG2_cfg_audio_haptic_brake_end_dly_cnt_i2s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_stream_start_dly_cnt_pa : 10;
        unsigned int reserved_0 : 6;
        unsigned int cfg_audio_haptic_stream_end_dly_cnt_pa : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HAPTIC_LRA_LP_CFG3_UNION;
#endif
#define SOC_HAPTIC_LRA_LP_CFG3_cfg_audio_haptic_stream_start_dly_cnt_pa_START (0)
#define SOC_HAPTIC_LRA_LP_CFG3_cfg_audio_haptic_stream_start_dly_cnt_pa_END (9)
#define SOC_HAPTIC_LRA_LP_CFG3_cfg_audio_haptic_stream_end_dly_cnt_pa_START (16)
#define SOC_HAPTIC_LRA_LP_CFG3_cfg_audio_haptic_stream_end_dly_cnt_pa_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_brake_start_dly_cnt_pa : 10;
        unsigned int reserved_0 : 6;
        unsigned int cfg_audio_haptic_brake_end_dly_cnt_pa : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HAPTIC_LRA_LP_CFG4_UNION;
#endif
#define SOC_HAPTIC_LRA_LP_CFG4_cfg_audio_haptic_brake_start_dly_cnt_pa_START (0)
#define SOC_HAPTIC_LRA_LP_CFG4_cfg_audio_haptic_brake_start_dly_cnt_pa_END (9)
#define SOC_HAPTIC_LRA_LP_CFG4_cfg_audio_haptic_brake_end_dly_cnt_pa_START (16)
#define SOC_HAPTIC_LRA_LP_CFG4_cfg_audio_haptic_brake_end_dly_cnt_pa_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_lp_delay_buffer_depth : 9;
        unsigned int reserved_0 : 7;
        unsigned int cfg_audio_haptic_lp_delay_cnt : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HAPTIC_LRA_LP_CFG5_UNION;
#endif
#define SOC_HAPTIC_LRA_LP_CFG5_cfg_audio_haptic_lp_delay_buffer_depth_START (0)
#define SOC_HAPTIC_LRA_LP_CFG5_cfg_audio_haptic_lp_delay_buffer_depth_END (8)
#define SOC_HAPTIC_LRA_LP_CFG5_cfg_audio_haptic_lp_delay_cnt_START (16)
#define SOC_HAPTIC_LRA_LP_CFG5_cfg_audio_haptic_lp_delay_cnt_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_threshold_low : 32;
    } reg;
} SOC_HAPTIC_LRA_LP_CFG6_UNION;
#endif
#define SOC_HAPTIC_LRA_LP_CFG6_cfg_audio_haptic_threshold_low_START (0)
#define SOC_HAPTIC_LRA_LP_CFG6_cfg_audio_haptic_threshold_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_threshold_high : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HAPTIC_LRA_LP_CFG7_UNION;
#endif
#define SOC_HAPTIC_LRA_LP_CFG7_cfg_audio_haptic_threshold_high_START (0)
#define SOC_HAPTIC_LRA_LP_CFG7_cfg_audio_haptic_threshold_high_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audio_haptic_debug_sel : 2;
        unsigned int reserved_0 : 1;
        unsigned int cfg_lra_empty_debug : 1;
        unsigned int prt_debug_sel : 4;
        unsigned int f0_debug_sel : 3;
        unsigned int brk_debug_sel : 3;
        unsigned int reserved_1 : 2;
        unsigned int cfg_lra_srcup_group_dly : 1;
        unsigned int cfg_lra_geq_mask_en : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_HAPTIC_LRA_DBG_DATA_SEL_UNION;
#endif
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_audio_haptic_debug_sel_START (0)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_audio_haptic_debug_sel_END (1)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_cfg_lra_empty_debug_START (3)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_cfg_lra_empty_debug_END (3)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_prt_debug_sel_START (4)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_prt_debug_sel_END (7)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_f0_debug_sel_START (8)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_f0_debug_sel_END (10)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_brk_debug_sel_START (11)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_brk_debug_sel_END (13)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_cfg_lra_srcup_group_dly_START (16)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_cfg_lra_srcup_group_dly_END (16)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_cfg_lra_geq_mask_en_START (17)
#define SOC_HAPTIC_LRA_DBG_DATA_SEL_cfg_lra_geq_mask_en_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_brake_emfavg_debug : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE0_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE0_cfg_audio_haptic_brake_emfavg_debug_START (0)
#define SOC_HAPTIC_LRA_RO_STATE0_cfg_audio_haptic_brake_emfavg_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_brake_emfdavg_debug : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE1_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE1_cfg_audio_haptic_brake_emfdavg_debug_START (0)
#define SOC_HAPTIC_LRA_RO_STATE1_cfg_audio_haptic_brake_emfdavg_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_brake_framegain_debug : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE2_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE2_cfg_audio_haptic_brake_framegain_debug_START (0)
#define SOC_HAPTIC_LRA_RO_STATE2_cfg_audio_haptic_brake_framegain_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_brake_brakecnt1_debug : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE3_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE3_cfg_audio_haptic_brake_brakecnt1_debug_START (0)
#define SOC_HAPTIC_LRA_RO_STATE3_cfg_audio_haptic_brake_brakecnt1_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_brake_brakecnt2_debug : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE4_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE4_cfg_audio_haptic_brake_brakecnt2_debug_START (0)
#define SOC_HAPTIC_LRA_RO_STATE4_cfg_audio_haptic_brake_brakecnt2_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_bcn_currentgain : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE5_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE5_cfg_audio_haptic_bcn_currentgain_START (0)
#define SOC_HAPTIC_LRA_RO_STATE5_cfg_audio_haptic_bcn_currentgain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_bgc_gain : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE6_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE6_cfg_audio_haptic_bgc_gain_START (0)
#define SOC_HAPTIC_LRA_RO_STATE6_cfg_audio_haptic_bgc_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_bgc_vbat_min : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE7_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE7_cfg_audio_haptic_bgc_vbat_min_START (0)
#define SOC_HAPTIC_LRA_RO_STATE7_cfg_audio_haptic_bgc_vbat_min_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_prt_debug_status : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE8_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE8_cfg_audio_haptic_prt_debug_status_START (0)
#define SOC_HAPTIC_LRA_RO_STATE8_cfg_audio_haptic_prt_debug_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_f0_peak_value_sum_debug : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE9_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE9_cfg_audio_haptic_f0_peak_value_sum_debug_START (0)
#define SOC_HAPTIC_LRA_RO_STATE9_cfg_audio_haptic_f0_peak_value_sum_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_f0_tdp_sum_debug : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE10_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE10_cfg_audio_haptic_f0_tdp_sum_debug_START (0)
#define SOC_HAPTIC_LRA_RO_STATE10_cfg_audio_haptic_f0_tdp_sum_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_f0_tdz_sum_debug : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE11_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE11_cfg_audio_haptic_f0_tdz_sum_debug_START (0)
#define SOC_HAPTIC_LRA_RO_STATE11_cfg_audio_haptic_f0_tdz_sum_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_f0_dw0_debug : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE12_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE12_cfg_audio_haptic_f0_dw0_debug_START (0)
#define SOC_HAPTIC_LRA_RO_STATE12_cfg_audio_haptic_f0_dw0_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_f0_wd_debug : 32;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE13_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE13_cfg_audio_haptic_f0_wd_debug_START (0)
#define SOC_HAPTIC_LRA_RO_STATE13_cfg_audio_haptic_f0_wd_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_audio_haptic_f0_delta_peak_num_debug : 2;
        unsigned int reserved_0 : 2;
        unsigned int cfg_audio_haptic_f0_delta_zero_num_debug : 2;
        unsigned int reserved_1 : 2;
        unsigned int cfg_audio_haptic_brake_auto_brake_state : 1;
        unsigned int cfg_audio_haptic_brake_intr_brake_state : 1;
        unsigned int reserved_2 : 22;
    } reg;
} SOC_HAPTIC_LRA_RO_STATE14_UNION;
#endif
#define SOC_HAPTIC_LRA_RO_STATE14_cfg_audio_haptic_f0_delta_peak_num_debug_START (0)
#define SOC_HAPTIC_LRA_RO_STATE14_cfg_audio_haptic_f0_delta_peak_num_debug_END (1)
#define SOC_HAPTIC_LRA_RO_STATE14_cfg_audio_haptic_f0_delta_zero_num_debug_START (4)
#define SOC_HAPTIC_LRA_RO_STATE14_cfg_audio_haptic_f0_delta_zero_num_debug_END (5)
#define SOC_HAPTIC_LRA_RO_STATE14_cfg_audio_haptic_brake_auto_brake_state_START (8)
#define SOC_HAPTIC_LRA_RO_STATE14_cfg_audio_haptic_brake_auto_brake_state_END (8)
#define SOC_HAPTIC_LRA_RO_STATE14_cfg_audio_haptic_brake_intr_brake_state_START (9)
#define SOC_HAPTIC_LRA_RO_STATE14_cfg_audio_haptic_brake_intr_brake_state_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 5;
        unsigned int cfg_lra_mixer_zero_num : 5;
        unsigned int cfg_lra_mixer_fade_out : 5;
        unsigned int cfg_lra_mixer_fade_in : 5;
        unsigned int cfg_lra_mixer_fade_en1 : 1;
        unsigned int cfg_lra_mixer_fade_en2 : 1;
        unsigned int cfg_lra_mixer_gain1 : 2;
        unsigned int cfg_lra_mixer_gain2 : 2;
        unsigned int cfg_lra_mixer_f0_drv_0 : 1;
        unsigned int cfg_lra_mixer_f0_drv_1 : 1;
        unsigned int cfg_lra_mixer_in1_id : 2;
        unsigned int cfg_lra_mixer_in2_id : 2;
    } reg;
} SOC_HAPTIC_LRA_CFG0_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_zero_num_START (5)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_zero_num_END (9)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_fade_out_START (10)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_fade_out_END (14)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_fade_in_START (15)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_fade_in_END (19)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_fade_en1_START (20)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_fade_en1_END (20)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_fade_en2_START (21)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_fade_en2_END (21)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_gain1_START (22)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_gain1_END (23)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_gain2_START (24)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_gain2_END (25)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_f0_drv_0_START (26)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_f0_drv_0_END (26)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_f0_drv_1_START (27)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_f0_drv_1_END (27)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_in1_id_START (28)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_in1_id_END (29)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_in2_id_START (30)
#define SOC_HAPTIC_LRA_CFG0_cfg_lra_mixer_in2_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_mixer_in1_thre_0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG1_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG1_cfg_lra_mixer_in1_thre_0_START (0)
#define SOC_HAPTIC_LRA_CFG1_cfg_lra_mixer_in1_thre_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_mixer_in1_thre_1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG2_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG2_cfg_lra_mixer_in1_thre_1_START (0)
#define SOC_HAPTIC_LRA_CFG2_cfg_lra_mixer_in1_thre_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_mixer_in1_thre_2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG3_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG3_cfg_lra_mixer_in1_thre_2_START (0)
#define SOC_HAPTIC_LRA_CFG3_cfg_lra_mixer_in1_thre_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_mixer_in2_thre_0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG4_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG4_cfg_lra_mixer_in2_thre_0_START (0)
#define SOC_HAPTIC_LRA_CFG4_cfg_lra_mixer_in2_thre_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_mixer_in2_thre_1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG5_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG5_cfg_lra_mixer_in2_thre_1_START (0)
#define SOC_HAPTIC_LRA_CFG5_cfg_lra_mixer_in2_thre_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_mixer_in2_thre_2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG6_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG6_cfg_lra_mixer_in2_thre_2_START (0)
#define SOC_HAPTIC_LRA_CFG6_cfg_lra_mixer_in2_thre_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_samplerate : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HAPTIC_LRA_CFG7_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG7_cfg_lra_brake_samplerate_START (0)
#define SOC_HAPTIC_LRA_CFG7_cfg_lra_brake_samplerate_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_re_q15 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG8_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG8_cfg_lra_re_q15_START (0)
#define SOC_HAPTIC_LRA_CFG8_cfg_lra_re_q15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_rewire_q15 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG9_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG9_cfg_lra_rewire_q15_START (0)
#define SOC_HAPTIC_LRA_CFG9_cfg_lra_rewire_q15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_dcr_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HAPTIC_LRA_CFG10_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG10_cfg_lra_brk_dcr_enable_START (0)
#define SOC_HAPTIC_LRA_CFG10_cfg_lra_brk_dcr_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_dcr_calc_starttime : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG11_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG11_cfg_lra_brk_dcr_calc_starttime_START (0)
#define SOC_HAPTIC_LRA_CFG11_cfg_lra_brk_dcr_calc_starttime_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_dcr_calc_buf : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG12_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG12_cfg_lra_brk_dcr_calc_buf_START (0)
#define SOC_HAPTIC_LRA_CFG12_cfg_lra_brk_dcr_calc_buf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_dcr_calc_pt_recip : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG13_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG13_cfg_lra_brk_dcr_calc_pt_recip_START (0)
#define SOC_HAPTIC_LRA_CFG13_cfg_lra_brk_dcr_calc_pt_recip_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_num : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HAPTIC_LRA_CFG14_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG14_cfg_lra_brk_geq_num_START (0)
#define SOC_HAPTIC_LRA_CFG14_cfg_lra_brk_geq_num_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_0_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG15_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG15_cfg_lra_brk_geq_iv_0_b0_START (0)
#define SOC_HAPTIC_LRA_CFG15_cfg_lra_brk_geq_iv_0_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_0_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG16_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG16_cfg_lra_brk_geq_iv_0_b1_START (0)
#define SOC_HAPTIC_LRA_CFG16_cfg_lra_brk_geq_iv_0_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_0_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG17_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG17_cfg_lra_brk_geq_iv_0_b2_START (0)
#define SOC_HAPTIC_LRA_CFG17_cfg_lra_brk_geq_iv_0_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_0_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG18_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG18_cfg_lra_brk_geq_iv_0_a1_START (0)
#define SOC_HAPTIC_LRA_CFG18_cfg_lra_brk_geq_iv_0_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_0_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG19_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG19_cfg_lra_brk_geq_iv_0_a2_START (0)
#define SOC_HAPTIC_LRA_CFG19_cfg_lra_brk_geq_iv_0_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_1_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG20_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG20_cfg_lra_brk_geq_iv_1_b0_START (0)
#define SOC_HAPTIC_LRA_CFG20_cfg_lra_brk_geq_iv_1_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_1_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG21_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG21_cfg_lra_brk_geq_iv_1_b1_START (0)
#define SOC_HAPTIC_LRA_CFG21_cfg_lra_brk_geq_iv_1_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_1_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG22_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG22_cfg_lra_brk_geq_iv_1_b2_START (0)
#define SOC_HAPTIC_LRA_CFG22_cfg_lra_brk_geq_iv_1_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_1_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG23_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG23_cfg_lra_brk_geq_iv_1_a1_START (0)
#define SOC_HAPTIC_LRA_CFG23_cfg_lra_brk_geq_iv_1_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_1_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG24_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG24_cfg_lra_brk_geq_iv_1_a2_START (0)
#define SOC_HAPTIC_LRA_CFG24_cfg_lra_brk_geq_iv_1_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_2_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG25_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG25_cfg_lra_brk_geq_iv_2_b0_START (0)
#define SOC_HAPTIC_LRA_CFG25_cfg_lra_brk_geq_iv_2_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_2_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG26_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG26_cfg_lra_brk_geq_iv_2_b1_START (0)
#define SOC_HAPTIC_LRA_CFG26_cfg_lra_brk_geq_iv_2_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_2_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG27_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG27_cfg_lra_brk_geq_iv_2_b2_START (0)
#define SOC_HAPTIC_LRA_CFG27_cfg_lra_brk_geq_iv_2_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_2_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG28_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG28_cfg_lra_brk_geq_iv_2_a1_START (0)
#define SOC_HAPTIC_LRA_CFG28_cfg_lra_brk_geq_iv_2_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_2_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG29_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG29_cfg_lra_brk_geq_iv_2_a2_START (0)
#define SOC_HAPTIC_LRA_CFG29_cfg_lra_brk_geq_iv_2_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_3_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG30_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG30_cfg_lra_brk_geq_iv_3_b0_START (0)
#define SOC_HAPTIC_LRA_CFG30_cfg_lra_brk_geq_iv_3_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_3_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG31_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG31_cfg_lra_brk_geq_iv_3_b1_START (0)
#define SOC_HAPTIC_LRA_CFG31_cfg_lra_brk_geq_iv_3_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_3_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG32_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG32_cfg_lra_brk_geq_iv_3_b2_START (0)
#define SOC_HAPTIC_LRA_CFG32_cfg_lra_brk_geq_iv_3_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_3_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG33_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG33_cfg_lra_brk_geq_iv_3_a1_START (0)
#define SOC_HAPTIC_LRA_CFG33_cfg_lra_brk_geq_iv_3_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_geq_iv_3_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG34_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG34_cfg_lra_brk_geq_iv_3_a2_START (0)
#define SOC_HAPTIC_LRA_CFG34_cfg_lra_brk_geq_iv_3_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_inter_brake : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HAPTIC_LRA_CFG35_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG35_cfg_lra_inter_brake_START (0)
#define SOC_HAPTIC_LRA_CFG35_cfg_lra_inter_brake_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_p_ratio : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG36_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG36_cfg_lra_brk_p_ratio_START (0)
#define SOC_HAPTIC_LRA_CFG36_cfg_lra_brk_p_ratio_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brk_d_ratio : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG37_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG37_cfg_lra_brk_d_ratio_START (0)
#define SOC_HAPTIC_LRA_CFG37_cfg_lra_brk_d_ratio_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_gain_frm_alpha0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG38_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG38_cfg_lra_gain_frm_alpha0_START (0)
#define SOC_HAPTIC_LRA_CFG38_cfg_lra_gain_frm_alpha0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_gain_sample_alpha0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG39_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG39_cfg_lra_gain_sample_alpha0_START (0)
#define SOC_HAPTIC_LRA_CFG39_cfg_lra_gain_sample_alpha0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_gain_frm_alpha1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG40_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG40_cfg_lra_gain_frm_alpha1_START (0)
#define SOC_HAPTIC_LRA_CFG40_cfg_lra_gain_frm_alpha1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_gain_sample_alpha1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG41_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG41_cfg_lra_gain_sample_alpha1_START (0)
#define SOC_HAPTIC_LRA_CFG41_cfg_lra_gain_sample_alpha1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_f0_q15 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG42_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG42_cfg_lra_f0_q15_START (0)
#define SOC_HAPTIC_LRA_CFG42_cfg_lra_f0_q15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_angle : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG43_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG43_cfg_lra_brake_angle_START (0)
#define SOC_HAPTIC_LRA_CFG43_cfg_lra_brake_angle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_sqr_boost : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG44_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG44_cfg_lra_brake_sqr_boost_START (0)
#define SOC_HAPTIC_LRA_CFG44_cfg_lra_brake_sqr_boost_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_frm_len : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_HAPTIC_LRA_CFG45_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG45_cfg_lra_brake_frm_len_START (0)
#define SOC_HAPTIC_LRA_CFG45_cfg_lra_brake_frm_len_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_frm_sft : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_HAPTIC_LRA_CFG46_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG46_cfg_lra_brake_frm_sft_START (0)
#define SOC_HAPTIC_LRA_CFG46_cfg_lra_brake_frm_sft_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_gain_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HAPTIC_LRA_CFG47_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG47_cfg_lra_brake_gain_mode_START (0)
#define SOC_HAPTIC_LRA_CFG47_cfg_lra_brake_gain_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_delay_loc : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG48_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG48_cfg_lra_brake_delay_loc_START (0)
#define SOC_HAPTIC_LRA_CFG48_cfg_lra_brake_delay_loc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_inv_frmlen : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG49_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG49_cfg_lra_brake_inv_frmlen_START (0)
#define SOC_HAPTIC_LRA_CFG49_cfg_lra_brake_inv_frmlen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_sat_q24 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG50_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG50_cfg_lra_brake_sat_q24_START (0)
#define SOC_HAPTIC_LRA_CFG50_cfg_lra_brake_sat_q24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_value_thr : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG51_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG51_cfg_lra_brake_value_thr_START (0)
#define SOC_HAPTIC_LRA_CFG51_cfg_lra_brake_value_thr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_cnt1_thr : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG52_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG52_cfg_lra_brake_cnt1_thr_START (0)
#define SOC_HAPTIC_LRA_CFG52_cfg_lra_brake_cnt1_thr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_brake_cnt2_thr : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG53_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG53_cfg_lra_brake_cnt2_thr_START (0)
#define SOC_HAPTIC_LRA_CFG53_cfg_lra_brake_cnt2_thr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_delta_time_thr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HAPTIC_LRA_CFG54_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG54_cfg_lra_delta_time_thr_START (0)
#define SOC_HAPTIC_LRA_CFG54_cfg_lra_delta_time_thr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_dcr_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HAPTIC_LRA_CFG55_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG55_cfg_lra_calcf_dcr_enable_START (0)
#define SOC_HAPTIC_LRA_CFG55_cfg_lra_calcf_dcr_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_dcr_calc_starttime : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG56_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG56_cfg_lra_calcf_dcr_calc_starttime_START (0)
#define SOC_HAPTIC_LRA_CFG56_cfg_lra_calcf_dcr_calc_starttime_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_dcr_calc_buf : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG57_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG57_cfg_lra_calcf_dcr_calc_buf_START (0)
#define SOC_HAPTIC_LRA_CFG57_cfg_lra_calcf_dcr_calc_buf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_dcr_calc_pt_recip : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG58_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG58_cfg_lra_calcf_dcr_calc_pt_recip_START (0)
#define SOC_HAPTIC_LRA_CFG58_cfg_lra_calcf_dcr_calc_pt_recip_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_num : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HAPTIC_LRA_CFG59_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG59_cfg_lra_calcf_geq_num_START (0)
#define SOC_HAPTIC_LRA_CFG59_cfg_lra_calcf_geq_num_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_0_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG60_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG60_cfg_lra_calcf_geq_iv_0_b0_START (0)
#define SOC_HAPTIC_LRA_CFG60_cfg_lra_calcf_geq_iv_0_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_0_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG61_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG61_cfg_lra_calcf_geq_iv_0_b1_START (0)
#define SOC_HAPTIC_LRA_CFG61_cfg_lra_calcf_geq_iv_0_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_0_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG62_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG62_cfg_lra_calcf_geq_iv_0_b2_START (0)
#define SOC_HAPTIC_LRA_CFG62_cfg_lra_calcf_geq_iv_0_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_0_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG63_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG63_cfg_lra_calcf_geq_iv_0_a1_START (0)
#define SOC_HAPTIC_LRA_CFG63_cfg_lra_calcf_geq_iv_0_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_0_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG64_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG64_cfg_lra_calcf_geq_iv_0_a2_START (0)
#define SOC_HAPTIC_LRA_CFG64_cfg_lra_calcf_geq_iv_0_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_1_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG65_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG65_cfg_lra_calcf_geq_iv_1_b0_START (0)
#define SOC_HAPTIC_LRA_CFG65_cfg_lra_calcf_geq_iv_1_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_1_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG66_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG66_cfg_lra_calcf_geq_iv_1_b1_START (0)
#define SOC_HAPTIC_LRA_CFG66_cfg_lra_calcf_geq_iv_1_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_1_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG67_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG67_cfg_lra_calcf_geq_iv_1_b2_START (0)
#define SOC_HAPTIC_LRA_CFG67_cfg_lra_calcf_geq_iv_1_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_1_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG68_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG68_cfg_lra_calcf_geq_iv_1_a1_START (0)
#define SOC_HAPTIC_LRA_CFG68_cfg_lra_calcf_geq_iv_1_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_1_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG69_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG69_cfg_lra_calcf_geq_iv_1_a2_START (0)
#define SOC_HAPTIC_LRA_CFG69_cfg_lra_calcf_geq_iv_1_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_2_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG70_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG70_cfg_lra_calcf_geq_iv_2_b0_START (0)
#define SOC_HAPTIC_LRA_CFG70_cfg_lra_calcf_geq_iv_2_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_2_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG71_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG71_cfg_lra_calcf_geq_iv_2_b1_START (0)
#define SOC_HAPTIC_LRA_CFG71_cfg_lra_calcf_geq_iv_2_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_2_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG72_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG72_cfg_lra_calcf_geq_iv_2_b2_START (0)
#define SOC_HAPTIC_LRA_CFG72_cfg_lra_calcf_geq_iv_2_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_2_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG73_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG73_cfg_lra_calcf_geq_iv_2_a1_START (0)
#define SOC_HAPTIC_LRA_CFG73_cfg_lra_calcf_geq_iv_2_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_2_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG74_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG74_cfg_lra_calcf_geq_iv_2_a2_START (0)
#define SOC_HAPTIC_LRA_CFG74_cfg_lra_calcf_geq_iv_2_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_3_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG75_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG75_cfg_lra_calcf_geq_iv_3_b0_START (0)
#define SOC_HAPTIC_LRA_CFG75_cfg_lra_calcf_geq_iv_3_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_3_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG76_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG76_cfg_lra_calcf_geq_iv_3_b1_START (0)
#define SOC_HAPTIC_LRA_CFG76_cfg_lra_calcf_geq_iv_3_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_3_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG77_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG77_cfg_lra_calcf_geq_iv_3_b2_START (0)
#define SOC_HAPTIC_LRA_CFG77_cfg_lra_calcf_geq_iv_3_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_3_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG78_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG78_cfg_lra_calcf_geq_iv_3_a1_START (0)
#define SOC_HAPTIC_LRA_CFG78_cfg_lra_calcf_geq_iv_3_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_geq_iv_3_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG79_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG79_cfg_lra_calcf_geq_iv_3_a2_START (0)
#define SOC_HAPTIC_LRA_CFG79_cfg_lra_calcf_geq_iv_3_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_calcf_is_usedds : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HAPTIC_LRA_CFG80_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG80_cfg_lra_calcf_is_usedds_START (0)
#define SOC_HAPTIC_LRA_CFG80_cfg_lra_calcf_is_usedds_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_dds_start : 1;
        unsigned int cfg_lra_software_dds : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HAPTIC_LRA_CFG81_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG81_cfg_lra_dds_start_START (0)
#define SOC_HAPTIC_LRA_CFG81_cfg_lra_dds_start_END (0)
#define SOC_HAPTIC_LRA_CFG81_cfg_lra_software_dds_START (1)
#define SOC_HAPTIC_LRA_CFG81_cfg_lra_software_dds_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_dds_length : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG82_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG82_cfg_lra_dds_length_START (0)
#define SOC_HAPTIC_LRA_CFG82_cfg_lra_dds_length_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_f0_calc_start : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG83_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG83_cfg_lra_f0_calc_start_START (0)
#define SOC_HAPTIC_LRA_CFG83_cfg_lra_f0_calc_start_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_f0_calc_length : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG84_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG84_cfg_lra_f0_calc_length_START (0)
#define SOC_HAPTIC_LRA_CFG84_cfg_lra_f0_calc_length_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_gain_ini_q23 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG85_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG85_cfg_lra_gain_ini_q23_START (0)
#define SOC_HAPTIC_LRA_CFG85_cfg_lra_gain_ini_q23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_gain_ini_length : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG86_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG86_cfg_lra_gain_ini_length_START (0)
#define SOC_HAPTIC_LRA_CFG86_cfg_lra_gain_ini_length_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_gain_alpha_q23 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG87_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG87_cfg_lra_gain_alpha_q23_START (0)
#define SOC_HAPTIC_LRA_CFG87_cfg_lra_gain_alpha_q23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_gain_target_q23 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG88_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG88_cfg_lra_gain_target_q23_START (0)
#define SOC_HAPTIC_LRA_CFG88_cfg_lra_gain_target_q23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_f0_max_q4 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HAPTIC_LRA_CFG89_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG89_cfg_lra_f0_max_q4_START (0)
#define SOC_HAPTIC_LRA_CFG89_cfg_lra_f0_max_q4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_f0_min_q4 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HAPTIC_LRA_CFG90_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG90_cfg_lra_f0_min_q4_START (0)
#define SOC_HAPTIC_LRA_CFG90_cfg_lra_f0_min_q4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_tattsamples : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG91_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG91_cfg_lra_bgc_tattsamples_START (0)
#define SOC_HAPTIC_LRA_CFG91_cfg_lra_bgc_tattsamples_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_trelframes : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG92_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG92_cfg_lra_bgc_trelframes_START (0)
#define SOC_HAPTIC_LRA_CFG92_cfg_lra_bgc_trelframes_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_vbat_limit1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG93_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG93_cfg_lra_bgc_vbat_limit1_START (0)
#define SOC_HAPTIC_LRA_CFG93_cfg_lra_bgc_vbat_limit1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_vbat_limit2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG94_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG94_cfg_lra_bgc_vbat_limit2_START (0)
#define SOC_HAPTIC_LRA_CFG94_cfg_lra_bgc_vbat_limit2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_vbat_limit3 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG95_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG95_cfg_lra_bgc_vbat_limit3_START (0)
#define SOC_HAPTIC_LRA_CFG95_cfg_lra_bgc_vbat_limit3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_mingain1_0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG96_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG96_cfg_lra_bgc_mingain1_0_START (0)
#define SOC_HAPTIC_LRA_CFG96_cfg_lra_bgc_mingain1_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_mingain1_1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG97_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG97_cfg_lra_bgc_mingain1_1_START (0)
#define SOC_HAPTIC_LRA_CFG97_cfg_lra_bgc_mingain1_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_mingain1_2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG98_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG98_cfg_lra_bgc_mingain1_2_START (0)
#define SOC_HAPTIC_LRA_CFG98_cfg_lra_bgc_mingain1_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_mingain2_0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG99_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG99_cfg_lra_bgc_mingain2_0_START (0)
#define SOC_HAPTIC_LRA_CFG99_cfg_lra_bgc_mingain2_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_mingain2_1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG100_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG100_cfg_lra_bgc_mingain2_1_START (0)
#define SOC_HAPTIC_LRA_CFG100_cfg_lra_bgc_mingain2_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_mingain2_2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG101_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG101_cfg_lra_bgc_mingain2_2_START (0)
#define SOC_HAPTIC_LRA_CFG101_cfg_lra_bgc_mingain2_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_mingain3_0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG102_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG102_cfg_lra_bgc_mingain3_0_START (0)
#define SOC_HAPTIC_LRA_CFG102_cfg_lra_bgc_mingain3_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_mingain3_1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG103_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG103_cfg_lra_bgc_mingain3_1_START (0)
#define SOC_HAPTIC_LRA_CFG103_cfg_lra_bgc_mingain3_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_mingain3_2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG104_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG104_cfg_lra_bgc_mingain3_2_START (0)
#define SOC_HAPTIC_LRA_CFG104_cfg_lra_bgc_mingain3_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_gain_step : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG105_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG105_cfg_lra_bgc_gain_step_START (0)
#define SOC_HAPTIC_LRA_CFG105_cfg_lra_bgc_gain_step_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_rbat : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG106_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG106_cfg_lra_bgc_rbat_START (0)
#define SOC_HAPTIC_LRA_CFG106_cfg_lra_bgc_rbat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_rloaddiv : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG107_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG107_cfg_lra_bgc_rloaddiv_START (0)
#define SOC_HAPTIC_LRA_CFG107_cfg_lra_bgc_rloaddiv_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_gamp : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG108_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG108_cfg_lra_bgc_gamp_START (0)
#define SOC_HAPTIC_LRA_CFG108_cfg_lra_bgc_gamp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_ampeff : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG109_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG109_cfg_lra_bgc_ampeff_START (0)
#define SOC_HAPTIC_LRA_CFG109_cfg_lra_bgc_ampeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_vrmscoeff : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG110_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG110_cfg_lra_bgc_vrmscoeff_START (0)
#define SOC_HAPTIC_LRA_CFG110_cfg_lra_bgc_vrmscoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_vrmscoeffdiv : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG111_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG111_cfg_lra_bgc_vrmscoeffdiv_START (0)
#define SOC_HAPTIC_LRA_CFG111_cfg_lra_bgc_vrmscoeffdiv_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_irmscoeff : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG112_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG112_cfg_lra_bgc_irmscoeff_START (0)
#define SOC_HAPTIC_LRA_CFG112_cfg_lra_bgc_irmscoeff_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_irmscoeffdiv : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG113_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG113_cfg_lra_bgc_irmscoeffdiv_START (0)
#define SOC_HAPTIC_LRA_CFG113_cfg_lra_bgc_irmscoeffdiv_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_vbat : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG114_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG114_cfg_lra_bgc_vbat_START (0)
#define SOC_HAPTIC_LRA_CFG114_cfg_lra_bgc_vbat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_ibat : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG115_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG115_cfg_lra_bgc_ibat_START (0)
#define SOC_HAPTIC_LRA_CFG115_cfg_lra_bgc_ibat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_cbat : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG116_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG116_cfg_lra_bgc_cbat_START (0)
#define SOC_HAPTIC_LRA_CFG116_cfg_lra_bgc_cbat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_cbat_limit : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG117_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG117_cfg_lra_bgc_cbat_limit_START (0)
#define SOC_HAPTIC_LRA_CFG117_cfg_lra_bgc_cbat_limit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_tbat : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG118_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG118_cfg_lra_bgc_tbat_START (0)
#define SOC_HAPTIC_LRA_CFG118_cfg_lra_bgc_tbat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bgc_tbat_limit : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG119_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG119_cfg_lra_bgc_tbat_limit_START (0)
#define SOC_HAPTIC_LRA_CFG119_cfg_lra_bgc_tbat_limit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_vol_therd : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG120_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG120_cfg_lra_bcn_vol_therd_START (0)
#define SOC_HAPTIC_LRA_CFG120_cfg_lra_bcn_vol_therd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_with_ac0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG121_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG121_cfg_lra_bcn_gain_with_ac0_START (0)
#define SOC_HAPTIC_LRA_CFG121_cfg_lra_bcn_gain_with_ac0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_with_ac1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG122_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG122_cfg_lra_bcn_gain_with_ac1_START (0)
#define SOC_HAPTIC_LRA_CFG122_cfg_lra_bcn_gain_with_ac1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_with_ac2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG123_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG123_cfg_lra_bcn_gain_with_ac2_START (0)
#define SOC_HAPTIC_LRA_CFG123_cfg_lra_bcn_gain_with_ac2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_with_ac3 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG124_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG124_cfg_lra_bcn_gain_with_ac3_START (0)
#define SOC_HAPTIC_LRA_CFG124_cfg_lra_bcn_gain_with_ac3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_with_ac4 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG125_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG125_cfg_lra_bcn_gain_with_ac4_START (0)
#define SOC_HAPTIC_LRA_CFG125_cfg_lra_bcn_gain_with_ac4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_with_ac5 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG126_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG126_cfg_lra_bcn_gain_with_ac5_START (0)
#define SOC_HAPTIC_LRA_CFG126_cfg_lra_bcn_gain_with_ac5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_with_ac6 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG127_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG127_cfg_lra_bcn_gain_with_ac6_START (0)
#define SOC_HAPTIC_LRA_CFG127_cfg_lra_bcn_gain_with_ac6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_with_ac7 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG128_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG128_cfg_lra_bcn_gain_with_ac7_START (0)
#define SOC_HAPTIC_LRA_CFG128_cfg_lra_bcn_gain_with_ac7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_with_ac8 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG129_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG129_cfg_lra_bcn_gain_with_ac8_START (0)
#define SOC_HAPTIC_LRA_CFG129_cfg_lra_bcn_gain_with_ac8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_with_ac9 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG130_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG130_cfg_lra_bcn_gain_with_ac9_START (0)
#define SOC_HAPTIC_LRA_CFG130_cfg_lra_bcn_gain_with_ac9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_with_ac10 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG131_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG131_cfg_lra_bcn_gain_with_ac10_START (0)
#define SOC_HAPTIC_LRA_CFG131_cfg_lra_bcn_gain_with_ac10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_withno_ac0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG132_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG132_cfg_lra_bcn_gain_withno_ac0_START (0)
#define SOC_HAPTIC_LRA_CFG132_cfg_lra_bcn_gain_withno_ac0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_withno_ac1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG133_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG133_cfg_lra_bcn_gain_withno_ac1_START (0)
#define SOC_HAPTIC_LRA_CFG133_cfg_lra_bcn_gain_withno_ac1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_withno_ac2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG134_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG134_cfg_lra_bcn_gain_withno_ac2_START (0)
#define SOC_HAPTIC_LRA_CFG134_cfg_lra_bcn_gain_withno_ac2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_withno_ac3 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG135_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG135_cfg_lra_bcn_gain_withno_ac3_START (0)
#define SOC_HAPTIC_LRA_CFG135_cfg_lra_bcn_gain_withno_ac3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_withno_ac4 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG136_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG136_cfg_lra_bcn_gain_withno_ac4_START (0)
#define SOC_HAPTIC_LRA_CFG136_cfg_lra_bcn_gain_withno_ac4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_withno_ac5 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG137_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG137_cfg_lra_bcn_gain_withno_ac5_START (0)
#define SOC_HAPTIC_LRA_CFG137_cfg_lra_bcn_gain_withno_ac5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_withno_ac6 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG138_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG138_cfg_lra_bcn_gain_withno_ac6_START (0)
#define SOC_HAPTIC_LRA_CFG138_cfg_lra_bcn_gain_withno_ac6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_withno_ac7 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG139_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG139_cfg_lra_bcn_gain_withno_ac7_START (0)
#define SOC_HAPTIC_LRA_CFG139_cfg_lra_bcn_gain_withno_ac7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_withno_ac8 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG140_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG140_cfg_lra_bcn_gain_withno_ac8_START (0)
#define SOC_HAPTIC_LRA_CFG140_cfg_lra_bcn_gain_withno_ac8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_withno_ac9 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG141_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG141_cfg_lra_bcn_gain_withno_ac9_START (0)
#define SOC_HAPTIC_LRA_CFG141_cfg_lra_bcn_gain_withno_ac9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_gain_withno_ac10 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG142_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG142_cfg_lra_bcn_gain_withno_ac10_START (0)
#define SOC_HAPTIC_LRA_CFG142_cfg_lra_bcn_gain_withno_ac10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_att_coef : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG143_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG143_cfg_lra_bcn_att_coef_START (0)
#define SOC_HAPTIC_LRA_CFG143_cfg_lra_bcn_att_coef_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_rel_coef : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG144_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG144_cfg_lra_bcn_rel_coef_START (0)
#define SOC_HAPTIC_LRA_CFG144_cfg_lra_bcn_rel_coef_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_bcn_pow : 1;
        unsigned int reserved_0 : 3;
        unsigned int cfg_lra_bcn_volper : 10;
        unsigned int reserved_1 : 2;
        unsigned int cfg_lra_bcn_cap : 10;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_HAPTIC_LRA_CFG145_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG145_cfg_lra_bcn_pow_START (0)
#define SOC_HAPTIC_LRA_CFG145_cfg_lra_bcn_pow_END (0)
#define SOC_HAPTIC_LRA_CFG145_cfg_lra_bcn_volper_START (4)
#define SOC_HAPTIC_LRA_CFG145_cfg_lra_bcn_volper_END (13)
#define SOC_HAPTIC_LRA_CFG145_cfg_lra_bcn_cap_START (16)
#define SOC_HAPTIC_LRA_CFG145_cfg_lra_bcn_cap_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_lmt_thred : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG146_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG146_cfg_lra_lmt_thred_START (0)
#define SOC_HAPTIC_LRA_CFG146_cfg_lra_lmt_thred_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_lmt_noisegate : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG147_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG147_cfg_lra_lmt_noisegate_START (0)
#define SOC_HAPTIC_LRA_CFG147_cfg_lra_lmt_noisegate_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_lmt_softknee : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG148_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG148_cfg_lra_lmt_softknee_START (0)
#define SOC_HAPTIC_LRA_CFG148_cfg_lra_lmt_softknee_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_lmt_invsoftknee : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG149_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG149_cfg_lra_lmt_invsoftknee_START (0)
#define SOC_HAPTIC_LRA_CFG149_cfg_lra_lmt_invsoftknee_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_lmt_makeup : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG150_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG150_cfg_lra_lmt_makeup_START (0)
#define SOC_HAPTIC_LRA_CFG150_cfg_lra_lmt_makeup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_lmt_ratio : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG151_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG151_cfg_lra_lmt_ratio_START (0)
#define SOC_HAPTIC_LRA_CFG151_cfg_lra_lmt_ratio_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_lmt_attack : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG152_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG152_cfg_lra_lmt_attack_START (0)
#define SOC_HAPTIC_LRA_CFG152_cfg_lra_lmt_attack_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_lmt_release : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG153_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG153_cfg_lra_lmt_release_START (0)
#define SOC_HAPTIC_LRA_CFG153_cfg_lra_lmt_release_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_plt_sin : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG154_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG154_cfg_lra_plt_sin_START (0)
#define SOC_HAPTIC_LRA_CFG154_cfg_lra_plt_sin_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_plt_media : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG155_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG155_cfg_lra_plt_media_START (0)
#define SOC_HAPTIC_LRA_CFG155_cfg_lra_plt_media_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_plt_att_coef : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG156_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG156_cfg_lra_plt_att_coef_START (0)
#define SOC_HAPTIC_LRA_CFG156_cfg_lra_plt_att_coef_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_plt_rel_coef : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG157_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG157_cfg_lra_plt_rel_coef_START (0)
#define SOC_HAPTIC_LRA_CFG157_cfg_lra_plt_rel_coef_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_plt_cross_step : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG158_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG158_cfg_lra_plt_cross_step_START (0)
#define SOC_HAPTIC_LRA_CFG158_cfg_lra_plt_cross_step_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_pre_pilotone_ength : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG159_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG159_cfg_lra_pre_pilotone_ength_START (0)
#define SOC_HAPTIC_LRA_CFG159_cfg_lra_pre_pilotone_ength_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_plt_cross_fade_len : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG160_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG160_cfg_lra_plt_cross_fade_len_START (0)
#define SOC_HAPTIC_LRA_CFG160_cfg_lra_plt_cross_fade_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_plt_frq_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HAPTIC_LRA_CFG161_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG161_cfg_lra_plt_frq_sel_START (0)
#define SOC_HAPTIC_LRA_CFG161_cfg_lra_plt_frq_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geqnum : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HAPTIC_LRA_CFG162_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG162_cfg_lra_drv_geqnum_START (0)
#define SOC_HAPTIC_LRA_CFG162_cfg_lra_drv_geqnum_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_0_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG163_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG163_cfg_lra_drv_geq_0_b0_START (0)
#define SOC_HAPTIC_LRA_CFG163_cfg_lra_drv_geq_0_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_0_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG164_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG164_cfg_lra_drv_geq_0_b1_START (0)
#define SOC_HAPTIC_LRA_CFG164_cfg_lra_drv_geq_0_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_0_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG165_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG165_cfg_lra_drv_geq_0_b2_START (0)
#define SOC_HAPTIC_LRA_CFG165_cfg_lra_drv_geq_0_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_0_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG166_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG166_cfg_lra_drv_geq_0_a1_START (0)
#define SOC_HAPTIC_LRA_CFG166_cfg_lra_drv_geq_0_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_0_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG167_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG167_cfg_lra_drv_geq_0_a2_START (0)
#define SOC_HAPTIC_LRA_CFG167_cfg_lra_drv_geq_0_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_1_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG168_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG168_cfg_lra_drv_geq_1_b0_START (0)
#define SOC_HAPTIC_LRA_CFG168_cfg_lra_drv_geq_1_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_1_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG169_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG169_cfg_lra_drv_geq_1_b1_START (0)
#define SOC_HAPTIC_LRA_CFG169_cfg_lra_drv_geq_1_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_1_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG170_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG170_cfg_lra_drv_geq_1_b2_START (0)
#define SOC_HAPTIC_LRA_CFG170_cfg_lra_drv_geq_1_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_1_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG171_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG171_cfg_lra_drv_geq_1_a1_START (0)
#define SOC_HAPTIC_LRA_CFG171_cfg_lra_drv_geq_1_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_1_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG172_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG172_cfg_lra_drv_geq_1_a2_START (0)
#define SOC_HAPTIC_LRA_CFG172_cfg_lra_drv_geq_1_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_2_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG173_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG173_cfg_lra_drv_geq_2_b0_START (0)
#define SOC_HAPTIC_LRA_CFG173_cfg_lra_drv_geq_2_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_2_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG174_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG174_cfg_lra_drv_geq_2_b1_START (0)
#define SOC_HAPTIC_LRA_CFG174_cfg_lra_drv_geq_2_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_2_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG175_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG175_cfg_lra_drv_geq_2_b2_START (0)
#define SOC_HAPTIC_LRA_CFG175_cfg_lra_drv_geq_2_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_2_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG176_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG176_cfg_lra_drv_geq_2_a1_START (0)
#define SOC_HAPTIC_LRA_CFG176_cfg_lra_drv_geq_2_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_2_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG177_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG177_cfg_lra_drv_geq_2_a2_START (0)
#define SOC_HAPTIC_LRA_CFG177_cfg_lra_drv_geq_2_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_3_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG178_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG178_cfg_lra_drv_geq_3_b0_START (0)
#define SOC_HAPTIC_LRA_CFG178_cfg_lra_drv_geq_3_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_3_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG179_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG179_cfg_lra_drv_geq_3_b1_START (0)
#define SOC_HAPTIC_LRA_CFG179_cfg_lra_drv_geq_3_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_3_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG180_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG180_cfg_lra_drv_geq_3_b2_START (0)
#define SOC_HAPTIC_LRA_CFG180_cfg_lra_drv_geq_3_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_3_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG181_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG181_cfg_lra_drv_geq_3_a1_START (0)
#define SOC_HAPTIC_LRA_CFG181_cfg_lra_drv_geq_3_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_3_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG182_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG182_cfg_lra_drv_geq_3_a2_START (0)
#define SOC_HAPTIC_LRA_CFG182_cfg_lra_drv_geq_3_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_4_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG183_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG183_cfg_lra_drv_geq_4_b0_START (0)
#define SOC_HAPTIC_LRA_CFG183_cfg_lra_drv_geq_4_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_4_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG184_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG184_cfg_lra_drv_geq_4_b1_START (0)
#define SOC_HAPTIC_LRA_CFG184_cfg_lra_drv_geq_4_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_4_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG185_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG185_cfg_lra_drv_geq_4_b2_START (0)
#define SOC_HAPTIC_LRA_CFG185_cfg_lra_drv_geq_4_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_4_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG186_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG186_cfg_lra_drv_geq_4_a1_START (0)
#define SOC_HAPTIC_LRA_CFG186_cfg_lra_drv_geq_4_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_4_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG187_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG187_cfg_lra_drv_geq_4_a2_START (0)
#define SOC_HAPTIC_LRA_CFG187_cfg_lra_drv_geq_4_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_5_b0 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG188_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG188_cfg_lra_drv_geq_5_b0_START (0)
#define SOC_HAPTIC_LRA_CFG188_cfg_lra_drv_geq_5_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_5_b1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG189_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG189_cfg_lra_drv_geq_5_b1_START (0)
#define SOC_HAPTIC_LRA_CFG189_cfg_lra_drv_geq_5_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_5_b2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG190_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG190_cfg_lra_drv_geq_5_b2_START (0)
#define SOC_HAPTIC_LRA_CFG190_cfg_lra_drv_geq_5_b2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_5_a1 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG191_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG191_cfg_lra_drv_geq_5_a1_START (0)
#define SOC_HAPTIC_LRA_CFG191_cfg_lra_drv_geq_5_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_drv_geq_5_a2 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG192_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG192_cfg_lra_drv_geq_5_a2_START (0)
#define SOC_HAPTIC_LRA_CFG192_cfg_lra_drv_geq_5_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_pgagain_q15 : 32;
    } reg;
} SOC_HAPTIC_LRA_CFG193_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG193_cfg_lra_pgagain_q15_START (0)
#define SOC_HAPTIC_LRA_CFG193_cfg_lra_pgagain_q15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_srcup_type : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HAPTIC_LRA_CFG194_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG194_cfg_lra_srcup_type_START (0)
#define SOC_HAPTIC_LRA_CFG194_cfg_lra_srcup_type_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_cicdn_type : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HAPTIC_LRA_CFG195_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG195_cfg_lra_cicdn_type_START (0)
#define SOC_HAPTIC_LRA_CFG195_cfg_lra_cicdn_type_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_cicdn_lowlatency : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HAPTIC_LRA_CFG196_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG196_cfg_lra_cicdn_lowlatency_START (0)
#define SOC_HAPTIC_LRA_CFG196_cfg_lra_cicdn_lowlatency_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_lra_cicdn_gain : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HAPTIC_LRA_CFG197_UNION;
#endif
#define SOC_HAPTIC_LRA_CFG197_cfg_lra_cicdn_gain_START (0)
#define SOC_HAPTIC_LRA_CFG197_cfg_lra_cicdn_gain_END (15)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
