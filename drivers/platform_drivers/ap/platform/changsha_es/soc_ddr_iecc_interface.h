#ifndef __SOC_DDR_IECC_INTERFACE_H__
#define __SOC_DDR_IECC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_ADDR(base) (base)
#define SOC_DDR_IECC_IECC_CFG_MODE_ADDR(base) ((base) + 0x0004UL)
#define SOC_DDR_IECC_IECC_INTSTS_ADDR(base) ((base) + 0x0008UL)
#define SOC_DDR_IECC_IECC_INTMSK_ADDR(base) ((base) + 0x000cUL)
#define SOC_DDR_IECC_IECC_RINT_ADDR(base) ((base) + 0x0010UL)
#define SOC_DDR_IECC_IECC_CFG_SRAM_CE_ERR_THDES_ADDR(base) ((base) + 0x0014UL)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_ADDR(base) ((base) + 0x0018UL)
#define SOC_DDR_IECC_IECC_DFX_ST0_ADDR(base) ((base) + 0x001cUL)
#define SOC_DDR_IECC_IECC_DFX_ST1_ADDR(base) ((base) + 0x0020UL)
#define SOC_DDR_IECC_IECC_DFX_ST2_ADDR(base) ((base) + 0x0024UL)
#define SOC_DDR_IECC_IECC_DFX_ST3_ADDR(base) ((base) + 0x0028UL)
#define SOC_DDR_IECC_IECC_DFX_ST4_ADDR(base) ((base) + 0x002cUL)
#define SOC_DDR_IECC_IECC_DFX_ST5_ADDR(base) ((base) + 0x0030UL)
#define SOC_DDR_IECC_IECC_DFX_ST6_ADDR(base) ((base) + 0x0034UL)
#define SOC_DDR_IECC_IECC_DFX_ST7_ADDR(base) ((base) + 0x0038UL)
#define SOC_DDR_IECC_IECC_DFX_ST8_ADDR(base) ((base) + 0x003cUL)
#define SOC_DDR_IECC_IECC_DFX_ST9_ADDR(base) ((base) + 0x0040UL)
#define SOC_DDR_IECC_IECC_DFX_ST10_ADDR(base) ((base) + 0x0044UL)
#define SOC_DDR_IECC_IECC_DFX_ST11_ADDR(base) ((base) + 0x0048UL)
#define SOC_DDR_IECC_IECC_DFX_WC_ADDR(base) ((base) + 0x004cUL)
#define SOC_DDR_IECC_IECC_DFX_ST12_ADDR(base) ((base) + 0x0050UL)
#define SOC_DDR_IECC_IECC_DFX_ST13_ADDR(base) ((base) + 0x0054UL)
#define SOC_DDR_IECC_IECC_DFX_ST14_ADDR(base) ((base) + 0x0058UL)
#define SOC_DDR_IECC_IECC_DFX_ST15_ADDR(base) ((base) + 0x005cUL)
#define SOC_DDR_IECC_IECC_DFX_ST16_ADDR(base) ((base) + 0x0060UL)
#define SOC_DDR_IECC_IECC_DFX_ST17_ADDR(base) ((base) + 0x0064UL)
#define SOC_DDR_IECC_IECC_DFX_ST18_ADDR(base) ((base) + 0x0068UL)
#define SOC_DDR_IECC_IECC_DFX_ST19_ADDR(base) ((base) + 0x006cUL)
#define SOC_DDR_IECC_IECC_DFX_ST20_ADDR(base) ((base) + 0x0070UL)
#define SOC_DDR_IECC_IECC_DFX_ST21_ADDR(base) ((base) + 0x0074UL)
#define SOC_DDR_IECC_IECC_DFX_ST22_ADDR(base) ((base) + 0x0078UL)
#define SOC_DDR_IECC_IECC_DFX_ST23_ADDR(base) ((base) + 0x007cUL)
#define SOC_DDR_IECC_IECC_DFX_ST24_ADDR(base) ((base) + 0x0080UL)
#define SOC_DDR_IECC_IECC_DFX_ST25_ADDR(base) ((base) + 0x0084UL)
#define SOC_DDR_IECC_IECC_DFX_ST26_ADDR(base) ((base) + 0x0088UL)
#define SOC_DDR_IECC_IECC_DFX_ST27_ADDR(base) ((base) + 0x008cUL)
#define SOC_DDR_IECC_IECC_DFX_ST28_ADDR(base) ((base) + 0x0090UL)
#define SOC_DDR_IECC_IECC_DFX_ST29_ADDR(base) ((base) + 0x0094UL)
#define SOC_DDR_IECC_IECC_DFX_ST30_ADDR(base) ((base) + 0x0098UL)
#define SOC_DDR_IECC_IECC_DFX_ST31_ADDR(base) ((base) + 0x009cUL)
#define SOC_DDR_IECC_IECC_DFX_ST32_ADDR(base) ((base) + 0x00a0UL)
#define SOC_DDR_IECC_IECC_DFX_ST33_ADDR(base) ((base) + 0x00a4UL)
#define SOC_DDR_IECC_IECC_DFX_ST34_ADDR(base) ((base) + 0x00a8UL)
#define SOC_DDR_IECC_IECC_DFX_ST35_ADDR(base) ((base) + 0x00acUL)
#define SOC_DDR_IECC_IECC_DFX_ST36_ADDR(base) ((base) + 0x00b0UL)
#define SOC_DDR_IECC_IECC_DFX_ST37_ADDR(base) ((base) + 0x00b4UL)
#define SOC_DDR_IECC_IECC_DFX_ST38_ADDR(base) ((base) + 0x00b8UL)
#define SOC_DDR_IECC_IECC_DFX_ST39_ADDR(base) ((base) + 0x00bcUL)
#define SOC_DDR_IECC_IECC_DFX_ST40_ADDR(base) ((base) + 0x00c0UL)
#define SOC_DDR_IECC_IECC_DFX_ST41_ADDR(base) ((base) + 0x00c4UL)
#define SOC_DDR_IECC_IECC_DFX_ST42_ADDR(base) ((base) + 0x00c8UL)
#define SOC_DDR_IECC_IECC_DFX_ST43_ADDR(base) ((base) + 0x00ccUL)
#define SOC_DDR_IECC_IECC_DFX_ST44_ADDR(base) ((base) + 0x00d0UL)
#define SOC_DDR_IECC_IECC_DFX_ST45_ADDR(base) ((base) + 0x00d4UL)
#define SOC_DDR_IECC_IECC_DFX_ST46_ADDR(base) ((base) + 0x00d8UL)
#define SOC_DDR_IECC_IECC_DFX_ST47_ADDR(base) ((base) + 0x00dcUL)
#define SOC_DDR_IECC_IECC_DFX_ST57_ADDR(base) ((base) + 0x00e0UL)
#define SOC_DDR_IECC_IECC_DFX_ST58_ADDR(base) ((base) + 0x00e4UL)
#define SOC_DDR_IECC_IECC_DFX_ST59_ADDR(base) ((base) + 0x00e8UL)
#define SOC_DDR_IECC_IECC_DFX_ST60_ADDR(base) ((base) + 0x00ecUL)
#define SOC_DDR_IECC_IECC_DFX_ST61_ADDR(base) ((base) + 0x00f0UL)
#define SOC_DDR_IECC_IECC_DFX_ST62_ADDR(base) ((base) + 0x00f4UL)
#define SOC_DDR_IECC_IECC_DFX_ST63_ADDR(base) ((base) + 0x00f8UL)
#define SOC_DDR_IECC_IECC_DFX_ST64_ADDR(base) ((base) + 0x00fcUL)
#define SOC_DDR_IECC_IECC_DFX_ST65_ADDR(base) ((base) + 0x0100UL)
#define SOC_DDR_IECC_IECC_DFX_ST75_ADDR(base) ((base) + 0x0104UL)
#define SOC_DDR_IECC_IECC_DFX_ST76_ADDR(base) ((base) + 0x0108UL)
#define SOC_DDR_IECC_IECC_DFX_ST77_ADDR(base) ((base) + 0x010cUL)
#define SOC_DDR_IECC_IECC_DFX_ST78_ADDR(base) ((base) + 0x0110UL)
#define SOC_DDR_IECC_IECC_DFX_ST79_ADDR(base) ((base) + 0x0114UL)
#define SOC_DDR_IECC_IECC_DFX_ST80_ADDR(base) ((base) + 0x0118UL)
#define SOC_DDR_IECC_IECC_DFX_ST81_ADDR(base) ((base) + 0x011cUL)
#define SOC_DDR_IECC_IECC_DFX_ST82_ADDR(base) ((base) + 0x0120UL)
#define SOC_DDR_IECC_IECC_DFX_ST83_ADDR(base) ((base) + 0x0124UL)
#define SOC_DDR_IECC_IECC_INT_CLR_ADDR(base) ((base) + 0x0128UL)
#define SOC_DDR_IECC_IECC_OLM_RESERVED_LOW_ROW_ADDR(base) ((base) + 0x012CUL)
#define SOC_DDR_IECC_IECC_OLM_RESERVED_HIGH_ROW_ADDR(base) ((base) + 0x0130UL)
#define SOC_DDR_IECC_IECC_DFX_FIFO_CTRL_ADDR(base) ((base) + 0x0134UL)
#define SOC_DDR_IECC_IECC_DFX_FIFO_ST_ADDR(base) ((base) + 0x0138UL)
#define SOC_DDR_IECC_IECC_PDU_BUF_THRD_ADDR(base) ((base) + 0x0140UL)
#else
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_ADDR(base) (base)
#define SOC_DDR_IECC_IECC_CFG_MODE_ADDR(base) ((base) + 0x0004)
#define SOC_DDR_IECC_IECC_INTSTS_ADDR(base) ((base) + 0x0008)
#define SOC_DDR_IECC_IECC_INTMSK_ADDR(base) ((base) + 0x000c)
#define SOC_DDR_IECC_IECC_RINT_ADDR(base) ((base) + 0x0010)
#define SOC_DDR_IECC_IECC_CFG_SRAM_CE_ERR_THDES_ADDR(base) ((base) + 0x0014)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_ADDR(base) ((base) + 0x0018)
#define SOC_DDR_IECC_IECC_DFX_ST0_ADDR(base) ((base) + 0x001c)
#define SOC_DDR_IECC_IECC_DFX_ST1_ADDR(base) ((base) + 0x0020)
#define SOC_DDR_IECC_IECC_DFX_ST2_ADDR(base) ((base) + 0x0024)
#define SOC_DDR_IECC_IECC_DFX_ST3_ADDR(base) ((base) + 0x0028)
#define SOC_DDR_IECC_IECC_DFX_ST4_ADDR(base) ((base) + 0x002c)
#define SOC_DDR_IECC_IECC_DFX_ST5_ADDR(base) ((base) + 0x0030)
#define SOC_DDR_IECC_IECC_DFX_ST6_ADDR(base) ((base) + 0x0034)
#define SOC_DDR_IECC_IECC_DFX_ST7_ADDR(base) ((base) + 0x0038)
#define SOC_DDR_IECC_IECC_DFX_ST8_ADDR(base) ((base) + 0x003c)
#define SOC_DDR_IECC_IECC_DFX_ST9_ADDR(base) ((base) + 0x0040)
#define SOC_DDR_IECC_IECC_DFX_ST10_ADDR(base) ((base) + 0x0044)
#define SOC_DDR_IECC_IECC_DFX_ST11_ADDR(base) ((base) + 0x0048)
#define SOC_DDR_IECC_IECC_DFX_WC_ADDR(base) ((base) + 0x004c)
#define SOC_DDR_IECC_IECC_DFX_ST12_ADDR(base) ((base) + 0x0050)
#define SOC_DDR_IECC_IECC_DFX_ST13_ADDR(base) ((base) + 0x0054)
#define SOC_DDR_IECC_IECC_DFX_ST14_ADDR(base) ((base) + 0x0058)
#define SOC_DDR_IECC_IECC_DFX_ST15_ADDR(base) ((base) + 0x005c)
#define SOC_DDR_IECC_IECC_DFX_ST16_ADDR(base) ((base) + 0x0060)
#define SOC_DDR_IECC_IECC_DFX_ST17_ADDR(base) ((base) + 0x0064)
#define SOC_DDR_IECC_IECC_DFX_ST18_ADDR(base) ((base) + 0x0068)
#define SOC_DDR_IECC_IECC_DFX_ST19_ADDR(base) ((base) + 0x006c)
#define SOC_DDR_IECC_IECC_DFX_ST20_ADDR(base) ((base) + 0x0070)
#define SOC_DDR_IECC_IECC_DFX_ST21_ADDR(base) ((base) + 0x0074)
#define SOC_DDR_IECC_IECC_DFX_ST22_ADDR(base) ((base) + 0x0078)
#define SOC_DDR_IECC_IECC_DFX_ST23_ADDR(base) ((base) + 0x007c)
#define SOC_DDR_IECC_IECC_DFX_ST24_ADDR(base) ((base) + 0x0080)
#define SOC_DDR_IECC_IECC_DFX_ST25_ADDR(base) ((base) + 0x0084)
#define SOC_DDR_IECC_IECC_DFX_ST26_ADDR(base) ((base) + 0x0088)
#define SOC_DDR_IECC_IECC_DFX_ST27_ADDR(base) ((base) + 0x008c)
#define SOC_DDR_IECC_IECC_DFX_ST28_ADDR(base) ((base) + 0x0090)
#define SOC_DDR_IECC_IECC_DFX_ST29_ADDR(base) ((base) + 0x0094)
#define SOC_DDR_IECC_IECC_DFX_ST30_ADDR(base) ((base) + 0x0098)
#define SOC_DDR_IECC_IECC_DFX_ST31_ADDR(base) ((base) + 0x009c)
#define SOC_DDR_IECC_IECC_DFX_ST32_ADDR(base) ((base) + 0x00a0)
#define SOC_DDR_IECC_IECC_DFX_ST33_ADDR(base) ((base) + 0x00a4)
#define SOC_DDR_IECC_IECC_DFX_ST34_ADDR(base) ((base) + 0x00a8)
#define SOC_DDR_IECC_IECC_DFX_ST35_ADDR(base) ((base) + 0x00ac)
#define SOC_DDR_IECC_IECC_DFX_ST36_ADDR(base) ((base) + 0x00b0)
#define SOC_DDR_IECC_IECC_DFX_ST37_ADDR(base) ((base) + 0x00b4)
#define SOC_DDR_IECC_IECC_DFX_ST38_ADDR(base) ((base) + 0x00b8)
#define SOC_DDR_IECC_IECC_DFX_ST39_ADDR(base) ((base) + 0x00bc)
#define SOC_DDR_IECC_IECC_DFX_ST40_ADDR(base) ((base) + 0x00c0)
#define SOC_DDR_IECC_IECC_DFX_ST41_ADDR(base) ((base) + 0x00c4)
#define SOC_DDR_IECC_IECC_DFX_ST42_ADDR(base) ((base) + 0x00c8)
#define SOC_DDR_IECC_IECC_DFX_ST43_ADDR(base) ((base) + 0x00cc)
#define SOC_DDR_IECC_IECC_DFX_ST44_ADDR(base) ((base) + 0x00d0)
#define SOC_DDR_IECC_IECC_DFX_ST45_ADDR(base) ((base) + 0x00d4)
#define SOC_DDR_IECC_IECC_DFX_ST46_ADDR(base) ((base) + 0x00d8)
#define SOC_DDR_IECC_IECC_DFX_ST47_ADDR(base) ((base) + 0x00dc)
#define SOC_DDR_IECC_IECC_DFX_ST57_ADDR(base) ((base) + 0x00e0)
#define SOC_DDR_IECC_IECC_DFX_ST58_ADDR(base) ((base) + 0x00e4)
#define SOC_DDR_IECC_IECC_DFX_ST59_ADDR(base) ((base) + 0x00e8)
#define SOC_DDR_IECC_IECC_DFX_ST60_ADDR(base) ((base) + 0x00ec)
#define SOC_DDR_IECC_IECC_DFX_ST61_ADDR(base) ((base) + 0x00f0)
#define SOC_DDR_IECC_IECC_DFX_ST62_ADDR(base) ((base) + 0x00f4)
#define SOC_DDR_IECC_IECC_DFX_ST63_ADDR(base) ((base) + 0x00f8)
#define SOC_DDR_IECC_IECC_DFX_ST64_ADDR(base) ((base) + 0x00fc)
#define SOC_DDR_IECC_IECC_DFX_ST65_ADDR(base) ((base) + 0x0100)
#define SOC_DDR_IECC_IECC_DFX_ST75_ADDR(base) ((base) + 0x0104)
#define SOC_DDR_IECC_IECC_DFX_ST76_ADDR(base) ((base) + 0x0108)
#define SOC_DDR_IECC_IECC_DFX_ST77_ADDR(base) ((base) + 0x010c)
#define SOC_DDR_IECC_IECC_DFX_ST78_ADDR(base) ((base) + 0x0110)
#define SOC_DDR_IECC_IECC_DFX_ST79_ADDR(base) ((base) + 0x0114)
#define SOC_DDR_IECC_IECC_DFX_ST80_ADDR(base) ((base) + 0x0118)
#define SOC_DDR_IECC_IECC_DFX_ST81_ADDR(base) ((base) + 0x011c)
#define SOC_DDR_IECC_IECC_DFX_ST82_ADDR(base) ((base) + 0x0120)
#define SOC_DDR_IECC_IECC_DFX_ST83_ADDR(base) ((base) + 0x0124)
#define SOC_DDR_IECC_IECC_INT_CLR_ADDR(base) ((base) + 0x0128)
#define SOC_DDR_IECC_IECC_OLM_RESERVED_LOW_ROW_ADDR(base) ((base) + 0x012C)
#define SOC_DDR_IECC_IECC_OLM_RESERVED_HIGH_ROW_ADDR(base) ((base) + 0x0130)
#define SOC_DDR_IECC_IECC_DFX_FIFO_CTRL_ADDR(base) ((base) + 0x0134)
#define SOC_DDR_IECC_IECC_DFX_FIFO_ST_ADDR(base) ((base) + 0x0138)
#define SOC_DDR_IECC_IECC_PDU_BUF_THRD_ADDR(base) ((base) + 0x0140)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bpra_n : 3;
        unsigned int pdu_push_mod : 1;
        unsigned int iecc_row_bdry : 18;
        unsigned int mem_ba : 2;
        unsigned int mem_col : 3;
        unsigned int pdu_bl_map : 3;
        unsigned int dram_type : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_UNION;
#endif
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_bpra_n_START (0)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_bpra_n_END (2)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_pdu_push_mod_START (3)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_pdu_push_mod_END (3)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_iecc_row_bdry_START (4)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_iecc_row_bdry_END (21)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_mem_ba_START (22)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_mem_ba_END (23)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_mem_col_START (24)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_mem_col_END (26)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_pdu_bl_map_START (27)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_pdu_bl_map_END (29)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_dram_type_START (30)
#define SOC_DDR_IECC_IECC_CFG_ADDR_EXP0_dram_type_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int icfg_iecc_clkon : 1;
        unsigned int icfg_pclkon : 1;
        unsigned int ds_en : 1;
        unsigned int iecc_bypass_en : 1;
        unsigned int poison_en : 1;
        unsigned int iecc_buf_init : 1;
        unsigned int iecc_buf_init_done : 1;
        unsigned int icfg_clk_switch : 1;
        unsigned int icfg_flush_req : 1;
        unsigned int flush_done : 1;
        unsigned int iecc_pri : 3;
        unsigned int iecc_mid : 16;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_DDR_IECC_IECC_CFG_MODE_UNION;
#endif
#define SOC_DDR_IECC_IECC_CFG_MODE_icfg_iecc_clkon_START (2)
#define SOC_DDR_IECC_IECC_CFG_MODE_icfg_iecc_clkon_END (2)
#define SOC_DDR_IECC_IECC_CFG_MODE_icfg_pclkon_START (3)
#define SOC_DDR_IECC_IECC_CFG_MODE_icfg_pclkon_END (3)
#define SOC_DDR_IECC_IECC_CFG_MODE_ds_en_START (4)
#define SOC_DDR_IECC_IECC_CFG_MODE_ds_en_END (4)
#define SOC_DDR_IECC_IECC_CFG_MODE_iecc_bypass_en_START (5)
#define SOC_DDR_IECC_IECC_CFG_MODE_iecc_bypass_en_END (5)
#define SOC_DDR_IECC_IECC_CFG_MODE_poison_en_START (6)
#define SOC_DDR_IECC_IECC_CFG_MODE_poison_en_END (6)
#define SOC_DDR_IECC_IECC_CFG_MODE_iecc_buf_init_START (7)
#define SOC_DDR_IECC_IECC_CFG_MODE_iecc_buf_init_END (7)
#define SOC_DDR_IECC_IECC_CFG_MODE_iecc_buf_init_done_START (8)
#define SOC_DDR_IECC_IECC_CFG_MODE_iecc_buf_init_done_END (8)
#define SOC_DDR_IECC_IECC_CFG_MODE_icfg_clk_switch_START (9)
#define SOC_DDR_IECC_IECC_CFG_MODE_icfg_clk_switch_END (9)
#define SOC_DDR_IECC_IECC_CFG_MODE_icfg_flush_req_START (10)
#define SOC_DDR_IECC_IECC_CFG_MODE_icfg_flush_req_END (10)
#define SOC_DDR_IECC_IECC_CFG_MODE_flush_done_START (11)
#define SOC_DDR_IECC_IECC_CFG_MODE_flush_done_END (11)
#define SOC_DDR_IECC_IECC_CFG_MODE_iecc_pri_START (12)
#define SOC_DDR_IECC_IECC_CFG_MODE_iecc_pri_END (14)
#define SOC_DDR_IECC_IECC_CFG_MODE_iecc_mid_START (15)
#define SOC_DDR_IECC_IECC_CFG_MODE_iecc_mid_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int exp_ob_intsts : 1;
        unsigned int sbram_serr_intsts : 1;
        unsigned int sbram_derr_intsts : 1;
        unsigned int rbuf_serr_intsts : 1;
        unsigned int rbuf_derr_intsts : 1;
        unsigned int wbuf_serr_intsts : 1;
        unsigned int wbuf_derr_intsts : 1;
        unsigned int iecc_serr_intsts : 1;
        unsigned int iecc_derr_intsts : 1;
        unsigned int iecc_ptrserr_intsts : 1;
        unsigned int iecc_ptrderr_intsts : 1;
        unsigned int iecc_olmderr_intsts : 1;
        unsigned int iecc_rmwderr_intsts : 1;
        unsigned int iecc_dsderr_intsts : 1;
        unsigned int iecc_pois_derr_intsts : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_DDR_IECC_IECC_INTSTS_UNION;
#endif
#define SOC_DDR_IECC_IECC_INTSTS_exp_ob_intsts_START (0)
#define SOC_DDR_IECC_IECC_INTSTS_exp_ob_intsts_END (0)
#define SOC_DDR_IECC_IECC_INTSTS_sbram_serr_intsts_START (1)
#define SOC_DDR_IECC_IECC_INTSTS_sbram_serr_intsts_END (1)
#define SOC_DDR_IECC_IECC_INTSTS_sbram_derr_intsts_START (2)
#define SOC_DDR_IECC_IECC_INTSTS_sbram_derr_intsts_END (2)
#define SOC_DDR_IECC_IECC_INTSTS_rbuf_serr_intsts_START (3)
#define SOC_DDR_IECC_IECC_INTSTS_rbuf_serr_intsts_END (3)
#define SOC_DDR_IECC_IECC_INTSTS_rbuf_derr_intsts_START (4)
#define SOC_DDR_IECC_IECC_INTSTS_rbuf_derr_intsts_END (4)
#define SOC_DDR_IECC_IECC_INTSTS_wbuf_serr_intsts_START (5)
#define SOC_DDR_IECC_IECC_INTSTS_wbuf_serr_intsts_END (5)
#define SOC_DDR_IECC_IECC_INTSTS_wbuf_derr_intsts_START (6)
#define SOC_DDR_IECC_IECC_INTSTS_wbuf_derr_intsts_END (6)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_serr_intsts_START (7)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_serr_intsts_END (7)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_derr_intsts_START (8)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_derr_intsts_END (8)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_ptrserr_intsts_START (9)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_ptrserr_intsts_END (9)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_ptrderr_intsts_START (10)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_ptrderr_intsts_END (10)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_olmderr_intsts_START (11)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_olmderr_intsts_END (11)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_rmwderr_intsts_START (12)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_rmwderr_intsts_END (12)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_dsderr_intsts_START (13)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_dsderr_intsts_END (13)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_pois_derr_intsts_START (14)
#define SOC_DDR_IECC_IECC_INTSTS_iecc_pois_derr_intsts_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int exp_ob_intmsk : 1;
        unsigned int sbram_serr_intmsk : 1;
        unsigned int sbram_derr_intmsk : 1;
        unsigned int rbuf_serr_intmsk : 1;
        unsigned int rbuf_derr_intmsk : 1;
        unsigned int wbuf_serr_intmsk : 1;
        unsigned int wbuf_derr_intmsk : 1;
        unsigned int iecc_serr_intmsk : 1;
        unsigned int iecc_derr_intmsk : 1;
        unsigned int iecc_ptrserr_intmsk : 1;
        unsigned int iecc_ptrderr_intmsk : 1;
        unsigned int iecc_olmderr_intmsk : 1;
        unsigned int iecc_rmwderr_intmsk : 1;
        unsigned int iecc_dsderr_intmsk : 1;
        unsigned int iecc_pois_derr_intmsk : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_DDR_IECC_IECC_INTMSK_UNION;
#endif
#define SOC_DDR_IECC_IECC_INTMSK_exp_ob_intmsk_START (0)
#define SOC_DDR_IECC_IECC_INTMSK_exp_ob_intmsk_END (0)
#define SOC_DDR_IECC_IECC_INTMSK_sbram_serr_intmsk_START (1)
#define SOC_DDR_IECC_IECC_INTMSK_sbram_serr_intmsk_END (1)
#define SOC_DDR_IECC_IECC_INTMSK_sbram_derr_intmsk_START (2)
#define SOC_DDR_IECC_IECC_INTMSK_sbram_derr_intmsk_END (2)
#define SOC_DDR_IECC_IECC_INTMSK_rbuf_serr_intmsk_START (3)
#define SOC_DDR_IECC_IECC_INTMSK_rbuf_serr_intmsk_END (3)
#define SOC_DDR_IECC_IECC_INTMSK_rbuf_derr_intmsk_START (4)
#define SOC_DDR_IECC_IECC_INTMSK_rbuf_derr_intmsk_END (4)
#define SOC_DDR_IECC_IECC_INTMSK_wbuf_serr_intmsk_START (5)
#define SOC_DDR_IECC_IECC_INTMSK_wbuf_serr_intmsk_END (5)
#define SOC_DDR_IECC_IECC_INTMSK_wbuf_derr_intmsk_START (6)
#define SOC_DDR_IECC_IECC_INTMSK_wbuf_derr_intmsk_END (6)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_serr_intmsk_START (7)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_serr_intmsk_END (7)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_derr_intmsk_START (8)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_derr_intmsk_END (8)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_ptrserr_intmsk_START (9)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_ptrserr_intmsk_END (9)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_ptrderr_intmsk_START (10)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_ptrderr_intmsk_END (10)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_olmderr_intmsk_START (11)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_olmderr_intmsk_END (11)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_rmwderr_intmsk_START (12)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_rmwderr_intmsk_END (12)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_dsderr_intmsk_START (13)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_dsderr_intmsk_END (13)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_pois_derr_intmsk_START (14)
#define SOC_DDR_IECC_IECC_INTMSK_iecc_pois_derr_intmsk_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int exp_ob_rint : 1;
        unsigned int sbram_serr_rint : 1;
        unsigned int sbram_derr_rint : 1;
        unsigned int rbuf_serr_rint : 1;
        unsigned int rbuf_derr_rint : 1;
        unsigned int wbuf_serr_rint : 1;
        unsigned int wbuf_derr_rint : 1;
        unsigned int iecc_serr_rint : 1;
        unsigned int iecc_derr_rint : 1;
        unsigned int iecc_ptrserr_rint : 1;
        unsigned int iecc_ptrderr_rint : 1;
        unsigned int iecc_olmderr_rint : 1;
        unsigned int iecc_rmwderr_rint : 1;
        unsigned int iecc_dsderr_rint : 1;
        unsigned int iecc_pois_derr_rint : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_DDR_IECC_IECC_RINT_UNION;
#endif
#define SOC_DDR_IECC_IECC_RINT_exp_ob_rint_START (0)
#define SOC_DDR_IECC_IECC_RINT_exp_ob_rint_END (0)
#define SOC_DDR_IECC_IECC_RINT_sbram_serr_rint_START (1)
#define SOC_DDR_IECC_IECC_RINT_sbram_serr_rint_END (1)
#define SOC_DDR_IECC_IECC_RINT_sbram_derr_rint_START (2)
#define SOC_DDR_IECC_IECC_RINT_sbram_derr_rint_END (2)
#define SOC_DDR_IECC_IECC_RINT_rbuf_serr_rint_START (3)
#define SOC_DDR_IECC_IECC_RINT_rbuf_serr_rint_END (3)
#define SOC_DDR_IECC_IECC_RINT_rbuf_derr_rint_START (4)
#define SOC_DDR_IECC_IECC_RINT_rbuf_derr_rint_END (4)
#define SOC_DDR_IECC_IECC_RINT_wbuf_serr_rint_START (5)
#define SOC_DDR_IECC_IECC_RINT_wbuf_serr_rint_END (5)
#define SOC_DDR_IECC_IECC_RINT_wbuf_derr_rint_START (6)
#define SOC_DDR_IECC_IECC_RINT_wbuf_derr_rint_END (6)
#define SOC_DDR_IECC_IECC_RINT_iecc_serr_rint_START (7)
#define SOC_DDR_IECC_IECC_RINT_iecc_serr_rint_END (7)
#define SOC_DDR_IECC_IECC_RINT_iecc_derr_rint_START (8)
#define SOC_DDR_IECC_IECC_RINT_iecc_derr_rint_END (8)
#define SOC_DDR_IECC_IECC_RINT_iecc_ptrserr_rint_START (9)
#define SOC_DDR_IECC_IECC_RINT_iecc_ptrserr_rint_END (9)
#define SOC_DDR_IECC_IECC_RINT_iecc_ptrderr_rint_START (10)
#define SOC_DDR_IECC_IECC_RINT_iecc_ptrderr_rint_END (10)
#define SOC_DDR_IECC_IECC_RINT_iecc_olmderr_rint_START (11)
#define SOC_DDR_IECC_IECC_RINT_iecc_olmderr_rint_END (11)
#define SOC_DDR_IECC_IECC_RINT_iecc_rmwderr_rint_START (12)
#define SOC_DDR_IECC_IECC_RINT_iecc_rmwderr_rint_END (12)
#define SOC_DDR_IECC_IECC_RINT_iecc_dsderr_rint_START (13)
#define SOC_DDR_IECC_IECC_RINT_iecc_dsderr_rint_END (13)
#define SOC_DDR_IECC_IECC_RINT_iecc_pois_derr_rint_START (14)
#define SOC_DDR_IECC_IECC_RINT_iecc_pois_derr_rint_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ecc_serr_thd : 16;
        unsigned int necc_serr_thd : 16;
    } reg;
} SOC_DDR_IECC_IECC_CFG_SRAM_CE_ERR_THDES_UNION;
#endif
#define SOC_DDR_IECC_IECC_CFG_SRAM_CE_ERR_THDES_ecc_serr_thd_START (0)
#define SOC_DDR_IECC_IECC_CFG_SRAM_CE_ERR_THDES_ecc_serr_thd_END (15)
#define SOC_DDR_IECC_IECC_CFG_SRAM_CE_ERR_THDES_necc_serr_thd_START (16)
#define SOC_DDR_IECC_IECC_CFG_SRAM_CE_ERR_THDES_necc_serr_thd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sbram_serr_cnt_clr : 1;
        unsigned int rbuf_serr_cnt_clr : 1;
        unsigned int wbuf_serr_cnt_clr : 1;
        unsigned int iecc_serr_cnt_clr : 1;
        unsigned int ptr_serr_cnt_clr : 1;
        unsigned int serr_cnt : 16;
        unsigned int reserved : 11;
    } reg;
} SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_UNION;
#endif
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_sbram_serr_cnt_clr_START (0)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_sbram_serr_cnt_clr_END (0)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_rbuf_serr_cnt_clr_START (1)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_rbuf_serr_cnt_clr_END (1)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_wbuf_serr_cnt_clr_START (2)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_wbuf_serr_cnt_clr_END (2)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_iecc_serr_cnt_clr_START (3)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_iecc_serr_cnt_clr_END (3)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_ptr_serr_cnt_clr_START (4)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_ptr_serr_cnt_clr_END (4)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_serr_cnt_START (5)
#define SOC_DDR_IECC_IECC_SRAM_CE_CNT_CLR_serr_cnt_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cur_cmd_st : 4;
        unsigned int sbfifo_empty : 1;
        unsigned int sbfifo_full : 1;
        unsigned int ecc_buf_full : 1;
        unsigned int grtfifo_empty : 1;
        unsigned int grtfifo_full : 1;
        unsigned int expob_co_org : 11;
        unsigned int byp_psb : 6;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST0_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST0_cur_cmd_st_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST0_cur_cmd_st_END (3)
#define SOC_DDR_IECC_IECC_DFX_ST0_sbfifo_empty_START (4)
#define SOC_DDR_IECC_IECC_DFX_ST0_sbfifo_empty_END (4)
#define SOC_DDR_IECC_IECC_DFX_ST0_sbfifo_full_START (5)
#define SOC_DDR_IECC_IECC_DFX_ST0_sbfifo_full_END (5)
#define SOC_DDR_IECC_IECC_DFX_ST0_ecc_buf_full_START (6)
#define SOC_DDR_IECC_IECC_DFX_ST0_ecc_buf_full_END (6)
#define SOC_DDR_IECC_IECC_DFX_ST0_grtfifo_empty_START (7)
#define SOC_DDR_IECC_IECC_DFX_ST0_grtfifo_empty_END (7)
#define SOC_DDR_IECC_IECC_DFX_ST0_grtfifo_full_START (8)
#define SOC_DDR_IECC_IECC_DFX_ST0_grtfifo_full_END (8)
#define SOC_DDR_IECC_IECC_DFX_ST0_expob_co_org_START (9)
#define SOC_DDR_IECC_IECC_DFX_ST0_expob_co_org_END (19)
#define SOC_DDR_IECC_IECC_DFX_ST0_byp_psb_START (20)
#define SOC_DDR_IECC_IECC_DFX_ST0_byp_psb_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int expob_rbr_org : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST1_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST1_expob_rbr_org_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST1_expob_rbr_org_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int expob_co : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST2_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST2_expob_co_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST2_expob_co_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int expob_rbr : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST3_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST3_expob_rbr_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST3_expob_rbr_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_co_fst : 11;
        unsigned int sbfifo_serr_addr : 7;
        unsigned int rbuf_serr_addr : 6;
        unsigned int wbuf_serr_addr : 6;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST4_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST4_serr_co_fst_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST4_serr_co_fst_END (10)
#define SOC_DDR_IECC_IECC_DFX_ST4_sbfifo_serr_addr_START (11)
#define SOC_DDR_IECC_IECC_DFX_ST4_sbfifo_serr_addr_END (17)
#define SOC_DDR_IECC_IECC_DFX_ST4_rbuf_serr_addr_START (18)
#define SOC_DDR_IECC_IECC_DFX_ST4_rbuf_serr_addr_END (23)
#define SOC_DDR_IECC_IECC_DFX_ST4_wbuf_serr_addr_START (24)
#define SOC_DDR_IECC_IECC_DFX_ST4_wbuf_serr_addr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_rbr_fst : 27;
        unsigned int serr_type_fst : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST5_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST5_serr_rbr_fst_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST5_serr_rbr_fst_END (26)
#define SOC_DDR_IECC_IECC_DFX_ST5_serr_type_fst_START (27)
#define SOC_DDR_IECC_IECC_DFX_ST5_serr_type_fst_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_co_fst : 11;
        unsigned int sbfifo_derr_addr : 7;
        unsigned int rbuf_derr_addr : 6;
        unsigned int wbuf_derr_addr : 6;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST6_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST6_derr_co_fst_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST6_derr_co_fst_END (10)
#define SOC_DDR_IECC_IECC_DFX_ST6_sbfifo_derr_addr_START (11)
#define SOC_DDR_IECC_IECC_DFX_ST6_sbfifo_derr_addr_END (17)
#define SOC_DDR_IECC_IECC_DFX_ST6_rbuf_derr_addr_START (18)
#define SOC_DDR_IECC_IECC_DFX_ST6_rbuf_derr_addr_END (23)
#define SOC_DDR_IECC_IECC_DFX_ST6_wbuf_derr_addr_START (24)
#define SOC_DDR_IECC_IECC_DFX_ST6_wbuf_derr_addr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_rbr_fst : 27;
        unsigned int derr_type_fst : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST7_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST7_derr_rbr_fst_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST7_derr_rbr_fst_END (26)
#define SOC_DDR_IECC_IECC_DFX_ST7_derr_type_fst_START (27)
#define SOC_DDR_IECC_IECC_DFX_ST7_derr_type_fst_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_co_last : 11;
        unsigned int serr_type_last : 3;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST8_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST8_serr_co_last_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST8_serr_co_last_END (10)
#define SOC_DDR_IECC_IECC_DFX_ST8_serr_type_last_START (11)
#define SOC_DDR_IECC_IECC_DFX_ST8_serr_type_last_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_rbr_last : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST9_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST9_serr_rbr_last_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST9_serr_rbr_last_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_co_last : 11;
        unsigned int derr_type_last : 3;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST10_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST10_derr_co_last_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST10_derr_co_last_END (10)
#define SOC_DDR_IECC_IECC_DFX_ST10_derr_type_last_START (11)
#define SOC_DDR_IECC_IECC_DFX_ST10_derr_type_last_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_rbr_last : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST11_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST11_derr_rbr_last_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST11_derr_rbr_last_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int expob_clr : 1;
        unsigned int serr_clr : 1;
        unsigned int derr_clr : 1;
        unsigned int byp_psb_clr : 1;
        unsigned int rbuf_err_inj : 2;
        unsigned int wbuf_err_inj : 2;
        unsigned int sbram_err_inj : 2;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_IECC_IECC_DFX_WC_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_WC_expob_clr_START (0)
#define SOC_DDR_IECC_IECC_DFX_WC_expob_clr_END (0)
#define SOC_DDR_IECC_IECC_DFX_WC_serr_clr_START (1)
#define SOC_DDR_IECC_IECC_DFX_WC_serr_clr_END (1)
#define SOC_DDR_IECC_IECC_DFX_WC_derr_clr_START (2)
#define SOC_DDR_IECC_IECC_DFX_WC_derr_clr_END (2)
#define SOC_DDR_IECC_IECC_DFX_WC_byp_psb_clr_START (3)
#define SOC_DDR_IECC_IECC_DFX_WC_byp_psb_clr_END (3)
#define SOC_DDR_IECC_IECC_DFX_WC_rbuf_err_inj_START (4)
#define SOC_DDR_IECC_IECC_DFX_WC_rbuf_err_inj_END (5)
#define SOC_DDR_IECC_IECC_DFX_WC_wbuf_err_inj_START (6)
#define SOC_DDR_IECC_IECC_DFX_WC_wbuf_err_inj_END (7)
#define SOC_DDR_IECC_IECC_DFX_WC_sbram_err_inj_START (8)
#define SOC_DDR_IECC_IECC_DFX_WC_sbram_err_inj_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst_org0 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST12_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST12_serr_dat_fst_org0_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST12_serr_dat_fst_org0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst_org1 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST13_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST13_serr_dat_fst_org1_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST13_serr_dat_fst_org1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst_org2 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST14_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST14_serr_dat_fst_org2_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST14_serr_dat_fst_org2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst_org3 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST15_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST15_serr_dat_fst_org3_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST15_serr_dat_fst_org3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst_org4 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST16_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST16_serr_dat_fst_org4_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST16_serr_dat_fst_org4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst_org5 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST17_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST17_serr_dat_fst_org5_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST17_serr_dat_fst_org5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst_org6 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST18_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST18_serr_dat_fst_org6_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST18_serr_dat_fst_org6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst_org7 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST19_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST19_serr_dat_fst_org7_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST19_serr_dat_fst_org7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_psb_fst_org : 6;
        unsigned int serr_chkin_fst : 10;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST20_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST20_serr_psb_fst_org_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST20_serr_psb_fst_org_END (5)
#define SOC_DDR_IECC_IECC_DFX_ST20_serr_chkin_fst_START (6)
#define SOC_DDR_IECC_IECC_DFX_ST20_serr_chkin_fst_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst0 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST21_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST21_serr_dat_fst0_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST21_serr_dat_fst0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst1 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST22_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST22_serr_dat_fst1_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST22_serr_dat_fst1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst2 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST23_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST23_serr_dat_fst2_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST23_serr_dat_fst2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst3 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST24_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST24_serr_dat_fst3_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST24_serr_dat_fst3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst4 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST25_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST25_serr_dat_fst4_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST25_serr_dat_fst4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst5 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST26_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST26_serr_dat_fst5_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST26_serr_dat_fst5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst6 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST27_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST27_serr_dat_fst6_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST27_serr_dat_fst6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_fst7 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST28_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST28_serr_dat_fst7_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST28_serr_dat_fst7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_psb_fst : 6;
        unsigned int serr_id_fst : 13;
        unsigned int serr_chkout_fst : 10;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST29_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST29_serr_psb_fst_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST29_serr_psb_fst_END (5)
#define SOC_DDR_IECC_IECC_DFX_ST29_serr_id_fst_START (6)
#define SOC_DDR_IECC_IECC_DFX_ST29_serr_id_fst_END (18)
#define SOC_DDR_IECC_IECC_DFX_ST29_serr_chkout_fst_START (19)
#define SOC_DDR_IECC_IECC_DFX_ST29_serr_chkout_fst_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last_org0 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST30_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST30_serr_dat_last_org0_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST30_serr_dat_last_org0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last_org1 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST31_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST31_serr_dat_last_org1_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST31_serr_dat_last_org1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last_org2 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST32_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST32_serr_dat_last_org2_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST32_serr_dat_last_org2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last_org3 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST33_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST33_serr_dat_last_org3_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST33_serr_dat_last_org3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last_org4 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST34_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST34_serr_dat_last_org4_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST34_serr_dat_last_org4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last_org5 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST35_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST35_serr_dat_last_org5_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST35_serr_dat_last_org5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last_org6 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST36_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST36_serr_dat_last_org6_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST36_serr_dat_last_org6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last_org7 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST37_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST37_serr_dat_last_org7_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST37_serr_dat_last_org7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_psb_last_org : 6;
        unsigned int serr_chkin_last : 10;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST38_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST38_serr_psb_last_org_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST38_serr_psb_last_org_END (5)
#define SOC_DDR_IECC_IECC_DFX_ST38_serr_chkin_last_START (6)
#define SOC_DDR_IECC_IECC_DFX_ST38_serr_chkin_last_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last0 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST39_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST39_serr_dat_last0_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST39_serr_dat_last0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last1 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST40_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST40_serr_dat_last1_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST40_serr_dat_last1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last2 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST41_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST41_serr_dat_last2_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST41_serr_dat_last2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last3 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST42_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST42_serr_dat_last3_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST42_serr_dat_last3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last4 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST43_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST43_serr_dat_last4_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST43_serr_dat_last4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last5 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST44_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST44_serr_dat_last5_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST44_serr_dat_last5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last6 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST45_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST45_serr_dat_last6_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST45_serr_dat_last6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_dat_last7 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST46_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST46_serr_dat_last7_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST46_serr_dat_last7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serr_psb_last : 6;
        unsigned int serr_id_last : 13;
        unsigned int serr_chkout_last : 10;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST47_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST47_serr_psb_last_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST47_serr_psb_last_END (5)
#define SOC_DDR_IECC_IECC_DFX_ST47_serr_id_last_START (6)
#define SOC_DDR_IECC_IECC_DFX_ST47_serr_id_last_END (18)
#define SOC_DDR_IECC_IECC_DFX_ST47_serr_chkout_last_START (19)
#define SOC_DDR_IECC_IECC_DFX_ST47_serr_chkout_last_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_fst0 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST57_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST57_derr_dat_fst0_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST57_derr_dat_fst0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_fst1 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST58_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST58_derr_dat_fst1_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST58_derr_dat_fst1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_fst2 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST59_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST59_derr_dat_fst2_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST59_derr_dat_fst2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_fst3 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST60_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST60_derr_dat_fst3_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST60_derr_dat_fst3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_fst4 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST61_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST61_derr_dat_fst4_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST61_derr_dat_fst4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_fst5 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST62_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST62_derr_dat_fst5_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST62_derr_dat_fst5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_fst6 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST63_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST63_derr_dat_fst6_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST63_derr_dat_fst6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_fst7 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST64_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST64_derr_dat_fst7_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST64_derr_dat_fst7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_psb_fst : 6;
        unsigned int derr_id_fst : 13;
        unsigned int derr_chkout_fst : 10;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST65_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST65_derr_psb_fst_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST65_derr_psb_fst_END (5)
#define SOC_DDR_IECC_IECC_DFX_ST65_derr_id_fst_START (6)
#define SOC_DDR_IECC_IECC_DFX_ST65_derr_id_fst_END (18)
#define SOC_DDR_IECC_IECC_DFX_ST65_derr_chkout_fst_START (19)
#define SOC_DDR_IECC_IECC_DFX_ST65_derr_chkout_fst_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_last0 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST75_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST75_derr_dat_last0_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST75_derr_dat_last0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_last1 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST76_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST76_derr_dat_last1_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST76_derr_dat_last1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_last2 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST77_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST77_derr_dat_last2_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST77_derr_dat_last2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_last3 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST78_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST78_derr_dat_last3_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST78_derr_dat_last3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_last4 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST79_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST79_derr_dat_last4_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST79_derr_dat_last4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_last5 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST80_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST80_derr_dat_last5_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST80_derr_dat_last5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_last6 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST81_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST81_derr_dat_last6_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST81_derr_dat_last6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_dat_last7 : 32;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST82_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST82_derr_dat_last7_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST82_derr_dat_last7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derr_psb_last : 6;
        unsigned int derr_id_last : 13;
        unsigned int derr_chkout_last : 10;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_IECC_IECC_DFX_ST83_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_ST83_derr_psb_last_START (0)
#define SOC_DDR_IECC_IECC_DFX_ST83_derr_psb_last_END (5)
#define SOC_DDR_IECC_IECC_DFX_ST83_derr_id_last_START (6)
#define SOC_DDR_IECC_IECC_DFX_ST83_derr_id_last_END (18)
#define SOC_DDR_IECC_IECC_DFX_ST83_derr_chkout_last_START (19)
#define SOC_DDR_IECC_IECC_DFX_ST83_derr_chkout_last_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_clr_h10 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_IECC_IECC_INT_CLR_UNION;
#endif
#define SOC_DDR_IECC_IECC_INT_CLR_int_clr_h10_START (0)
#define SOC_DDR_IECC_IECC_INT_CLR_int_clr_h10_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int olm_low_row : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_IECC_IECC_OLM_RESERVED_LOW_ROW_UNION;
#endif
#define SOC_DDR_IECC_IECC_OLM_RESERVED_LOW_ROW_olm_low_row_START (0)
#define SOC_DDR_IECC_IECC_OLM_RESERVED_LOW_ROW_olm_low_row_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int olm_high_row : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_IECC_IECC_OLM_RESERVED_HIGH_ROW_UNION;
#endif
#define SOC_DDR_IECC_IECC_OLM_RESERVED_HIGH_ROW_olm_high_row_START (0)
#define SOC_DDR_IECC_IECC_OLM_RESERVED_HIGH_ROW_olm_high_row_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_fifo_rd_en : 1;
        unsigned int err_buf_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_IECC_IECC_DFX_FIFO_CTRL_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_FIFO_CTRL_dfx_fifo_rd_en_START (0)
#define SOC_DDR_IECC_IECC_DFX_FIFO_CTRL_dfx_fifo_rd_en_END (0)
#define SOC_DDR_IECC_IECC_DFX_FIFO_CTRL_err_buf_sel_START (1)
#define SOC_DDR_IECC_IECC_DFX_FIFO_CTRL_err_buf_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_fifo_overflow : 1;
        unsigned int dfx_fifo_empty : 1;
        unsigned int dfx_fifo_full : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_IECC_IECC_DFX_FIFO_ST_UNION;
#endif
#define SOC_DDR_IECC_IECC_DFX_FIFO_ST_dfx_fifo_overflow_START (0)
#define SOC_DDR_IECC_IECC_DFX_FIFO_ST_dfx_fifo_overflow_END (0)
#define SOC_DDR_IECC_IECC_DFX_FIFO_ST_dfx_fifo_empty_START (1)
#define SOC_DDR_IECC_IECC_DFX_FIFO_ST_dfx_fifo_empty_END (1)
#define SOC_DDR_IECC_IECC_DFX_FIFO_ST_dfx_fifo_full_START (2)
#define SOC_DDR_IECC_IECC_DFX_FIFO_ST_dfx_fifo_full_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdu_buf_thrd : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_IECC_IECC_PDU_BUF_THRD_UNION;
#endif
#define SOC_DDR_IECC_IECC_PDU_BUF_THRD_pdu_buf_thrd_START (0)
#define SOC_DDR_IECC_IECC_PDU_BUF_THRD_pdu_buf_thrd_END (4)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
