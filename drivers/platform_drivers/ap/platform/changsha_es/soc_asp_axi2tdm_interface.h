#ifndef __SOC_ASP_AXI2TDM_INTERFACE_H__
#define __SOC_ASP_AXI2TDM_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_ADDR(base) ((base) + (0x0000UL))
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_ADDR(base) ((base) + (0x0004UL))
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_ADDR(base) ((base) + (0x0008UL))
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_ADDR(base) ((base) + (0x000CUL))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL0_ADDR(base) ((base) + (0x0010UL))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_ADDR(base) ((base) + (0x0014UL))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_ADDR(base) ((base) + (0x0018UL))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_ADDR(base) ((base) + (0x001CUL))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_ADDR(base) ((base) + (0x0020UL))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_ADDR(base) ((base) + (0x0024UL))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_ADDR(base) ((base) + (0x0028UL))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_ADDR(base) ((base) + (0x002CUL))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_ADDR(base) ((base) + (0x0030UL))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_ADDR(base) ((base) + (0x0034UL))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_ADDR(base) ((base) + (0x0038UL))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_ADDR(base) ((base) + (0x003CUL))
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_ADDR(base) ((base) + (0x0040UL))
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_ADDR(base) ((base) + (0x0044UL))
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_ADDR(base) ((base) + (0x0048UL))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL0_ADDR(base) ((base) + (0x004CUL))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_ADDR(base) ((base) + (0x0050UL))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_ADDR(base) ((base) + (0x0054UL))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_ADDR(base) ((base) + (0x0058UL))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_ADDR(base) ((base) + (0x005CUL))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_ADDR(base) ((base) + (0x0060UL))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_ADDR(base) ((base) + (0x0064UL))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_ADDR(base) ((base) + (0x0068UL))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_ADDR(base) ((base) + (0x006CUL))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_ADDR(base) ((base) + (0x0070UL))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_ADDR(base) ((base) + (0x0074UL))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_ADDR(base) ((base) + (0x0078UL))
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_ADDR(base) ((base) + (0x007CUL))
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_ADDR(base) ((base) + (0x0080UL))
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_ADDR(base) ((base) + (0x0084UL))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL0_ADDR(base) ((base) + (0x0088UL))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_ADDR(base) ((base) + (0x008CUL))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_ADDR(base) ((base) + (0x0090UL))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_ADDR(base) ((base) + (0x0094UL))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_ADDR(base) ((base) + (0x0098UL))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_ADDR(base) ((base) + (0x009CUL))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_ADDR(base) ((base) + (0x00A0UL))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_ADDR(base) ((base) + (0x00A4UL))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_ADDR(base) ((base) + (0x00A8UL))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_ADDR(base) ((base) + (0x00ACUL))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_ADDR(base) ((base) + (0x00B0UL))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_ADDR(base) ((base) + (0x00B4UL))
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_0_ADDR(base) ((base) + (0x00B8UL))
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_1_ADDR(base) ((base) + (0x00BCUL))
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_2_ADDR(base) ((base) + (0x00C0UL))
#define SOC_ASP_AXI2TDM_MEM_CTRL_ADDR(base) ((base) + (0x00C4UL))
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG1_ADDR(base) ((base) + (0x00C8UL))
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG2_ADDR(base) ((base) + (0x00CCUL))
#else
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_ADDR(base) ((base) + (0x0000))
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_ADDR(base) ((base) + (0x0004))
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_ADDR(base) ((base) + (0x0008))
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_ADDR(base) ((base) + (0x000C))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL0_ADDR(base) ((base) + (0x0010))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_ADDR(base) ((base) + (0x0014))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_ADDR(base) ((base) + (0x0018))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_ADDR(base) ((base) + (0x001C))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_ADDR(base) ((base) + (0x0020))
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_ADDR(base) ((base) + (0x0024))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_ADDR(base) ((base) + (0x0028))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_ADDR(base) ((base) + (0x002C))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_ADDR(base) ((base) + (0x0030))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_ADDR(base) ((base) + (0x0034))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_ADDR(base) ((base) + (0x0038))
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_ADDR(base) ((base) + (0x003C))
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_ADDR(base) ((base) + (0x0040))
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_ADDR(base) ((base) + (0x0044))
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_ADDR(base) ((base) + (0x0048))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL0_ADDR(base) ((base) + (0x004C))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_ADDR(base) ((base) + (0x0050))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_ADDR(base) ((base) + (0x0054))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_ADDR(base) ((base) + (0x0058))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_ADDR(base) ((base) + (0x005C))
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_ADDR(base) ((base) + (0x0060))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_ADDR(base) ((base) + (0x0064))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_ADDR(base) ((base) + (0x0068))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_ADDR(base) ((base) + (0x006C))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_ADDR(base) ((base) + (0x0070))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_ADDR(base) ((base) + (0x0074))
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_ADDR(base) ((base) + (0x0078))
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_ADDR(base) ((base) + (0x007C))
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_ADDR(base) ((base) + (0x0080))
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_ADDR(base) ((base) + (0x0084))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL0_ADDR(base) ((base) + (0x0088))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_ADDR(base) ((base) + (0x008C))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_ADDR(base) ((base) + (0x0090))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_ADDR(base) ((base) + (0x0094))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_ADDR(base) ((base) + (0x0098))
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_ADDR(base) ((base) + (0x009C))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_ADDR(base) ((base) + (0x00A0))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_ADDR(base) ((base) + (0x00A4))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_ADDR(base) ((base) + (0x00A8))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_ADDR(base) ((base) + (0x00AC))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_ADDR(base) ((base) + (0x00B0))
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_ADDR(base) ((base) + (0x00B4))
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_0_ADDR(base) ((base) + (0x00B8))
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_1_ADDR(base) ((base) + (0x00BC))
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_2_ADDR(base) ((base) + (0x00C0))
#define SOC_ASP_AXI2TDM_MEM_CTRL_ADDR(base) ((base) + (0x00C4))
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG1_ADDR(base) ((base) + (0x00C8))
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG2_ADDR(base) ((base) + (0x00CC))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int codec_dp_en : 1;
        unsigned int codec_dp1_dn_clk_en : 1;
        unsigned int codec_dp1_up_clk_en : 1;
        unsigned int codec_dp2_dn_clk_en : 1;
        unsigned int codec_dp2_up_clk_en : 1;
        unsigned int codec_dp3_dn_clk_en : 1;
        unsigned int codec_dp3_up_clk_en : 1;
        unsigned int reserved : 24;
        unsigned int x2ram_cg_en : 1;
    } reg;
} SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_UNION;
#endif
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp_en_START (0)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp_en_END (0)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp1_dn_clk_en_START (1)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp1_dn_clk_en_END (1)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp1_up_clk_en_START (2)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp1_up_clk_en_END (2)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp2_dn_clk_en_START (3)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp2_dn_clk_en_END (3)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp2_up_clk_en_START (4)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp2_up_clk_en_END (4)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp3_dn_clk_en_START (5)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp3_dn_clk_en_END (5)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp3_up_clk_en_START (6)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_codec_dp3_up_clk_en_END (6)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_x2ram_cg_en_START (31)
#define SOC_ASP_AXI2TDM_AXI2TDM_CLK_CTRL_x2ram_cg_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_i2s_if_tx_ena : 1;
        unsigned int intf1_i2s_if_rx_ena : 1;
        unsigned int intf1_tdm128_if_en : 1;
        unsigned int intf1_tdm256_if_en : 1;
        unsigned int intf1_clk_en : 1;
        unsigned int intf1_i2s_tx_clk_sel : 1;
        unsigned int intf1_i2s_rx_clk_sel : 1;
        unsigned int intf1_tdm_tx_clk_sel : 1;
        unsigned int intf1_tdm_rx_clk_sel : 1;
        unsigned int intf1_i2s_fs : 3;
        unsigned int intf1_tdm_fs : 2;
        unsigned int intf1_mst_slv : 1;
        unsigned int intf1_i2s_tdm_mode : 2;
        unsigned int intf1_core_clk_en : 1;
        unsigned int intf2_core_clk_en : 1;
        unsigned int intf3_core_clk_en : 1;
        unsigned int intf1_clk_boost_en : 1;
        unsigned int intf2_clk_boost_en : 1;
        unsigned int intf3_clk_boost_en : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_if_tx_ena_START (0)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_if_tx_ena_END (0)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_if_rx_ena_START (1)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_if_rx_ena_END (1)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_tdm128_if_en_START (2)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_tdm128_if_en_END (2)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_tdm256_if_en_START (3)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_tdm256_if_en_END (3)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_clk_en_START (4)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_clk_en_END (4)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_tx_clk_sel_START (5)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_tx_clk_sel_END (5)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_rx_clk_sel_START (6)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_rx_clk_sel_END (6)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_tdm_tx_clk_sel_START (7)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_tdm_tx_clk_sel_END (7)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_tdm_rx_clk_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_tdm_rx_clk_sel_END (8)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_fs_START (9)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_fs_END (11)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_tdm_fs_START (12)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_tdm_fs_END (13)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_mst_slv_START (14)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_mst_slv_END (14)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_tdm_mode_START (15)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_i2s_tdm_mode_END (16)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_core_clk_en_START (17)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_core_clk_en_END (17)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf2_core_clk_en_START (18)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf2_core_clk_en_END (18)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf3_core_clk_en_START (19)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf3_core_clk_en_END (19)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_clk_boost_en_START (20)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf1_clk_boost_en_END (20)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf2_clk_boost_en_START (21)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf2_clk_boost_en_END (21)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf3_clk_boost_en_START (22)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL0_intf3_clk_boost_en_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm128_clk_in_sel : 2;
        unsigned int intf1_i2s64_clk_in_sel : 3;
        unsigned int intf1_i2s32_clk_in_sel : 3;
        unsigned int intf1_pcm32_clk_in_sel : 3;
        unsigned int intf1_pcm16_clk_in_sel : 3;
        unsigned int reserved : 18;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_intf1_tdm128_clk_in_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_intf1_tdm128_clk_in_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_intf1_i2s64_clk_in_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_intf1_i2s64_clk_in_sel_END (4)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_intf1_i2s32_clk_in_sel_START (5)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_intf1_i2s32_clk_in_sel_END (7)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_intf1_pcm32_clk_in_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_intf1_pcm32_clk_in_sel_END (10)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_intf1_pcm16_clk_in_sel_START (11)
#define SOC_ASP_AXI2TDM_INTF1_CLK_CTRL1_intf1_pcm16_clk_in_sel_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_i2s_sdi_line_sel : 2;
        unsigned int intf1_i2s_sdo_line_sel : 2;
        unsigned int intf1_i2s_direct_loop : 2;
        unsigned int intf1_i2s_func_mode : 3;
        unsigned int intf1_i2s_frame_mode : 1;
        unsigned int intf1_i2s_lrclk_mode : 1;
        unsigned int intf1_i2s_chnnl_mode : 1;
        unsigned int intf1_i2s_codec_data_format : 1;
        unsigned int intf1_i2s_codec_io_wordlength : 2;
        unsigned int reserved : 17;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_sdi_line_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_sdi_line_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_sdo_line_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_sdo_line_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_direct_loop_START (4)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_direct_loop_END (5)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_func_mode_START (6)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_func_mode_END (8)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_frame_mode_START (9)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_frame_mode_END (9)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_lrclk_mode_START (10)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_lrclk_mode_END (10)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_chnnl_mode_START (11)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_chnnl_mode_END (11)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_codec_data_format_START (12)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_codec_data_format_END (12)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_codec_io_wordlength_START (13)
#define SOC_ASP_AXI2TDM_INTF1_I2S_CTRL_intf1_i2s_codec_io_wordlength_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm128_sdi_line_sel : 2;
        unsigned int intf1_tdm128_sdo_line_sel : 2;
        unsigned int intf1_tdm128_frame_mode : 3;
        unsigned int intf1_tdm128_direct_loop : 2;
        unsigned int reserved : 23;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL0_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL0_intf1_tdm128_sdi_line_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL0_intf1_tdm128_sdi_line_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL0_intf1_tdm128_sdo_line_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL0_intf1_tdm128_sdo_line_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL0_intf1_tdm128_frame_mode_START (4)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL0_intf1_tdm128_frame_mode_END (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL0_intf1_tdm128_direct_loop_START (7)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL0_intf1_tdm128_direct_loop_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm128_tx0_ch3_sel : 2;
        unsigned int intf1_tdm128_tx0_ch2_sel : 2;
        unsigned int intf1_tdm128_tx0_ch1_sel : 2;
        unsigned int intf1_tdm128_tx0_ch0_sel : 2;
        unsigned int intf1_tdm128_tx1_ch3_sel : 2;
        unsigned int intf1_tdm128_tx1_ch2_sel : 2;
        unsigned int intf1_tdm128_tx1_ch1_sel : 2;
        unsigned int intf1_tdm128_tx1_ch0_sel : 2;
        unsigned int intf1_tdm128_tx2_ch3_sel : 2;
        unsigned int intf1_tdm128_tx2_ch2_sel : 2;
        unsigned int intf1_tdm128_tx2_ch1_sel : 2;
        unsigned int intf1_tdm128_tx2_ch0_sel : 2;
        unsigned int intf1_tdm128_tx3_ch3_sel : 2;
        unsigned int intf1_tdm128_tx3_ch2_sel : 2;
        unsigned int intf1_tdm128_tx3_ch1_sel : 2;
        unsigned int intf1_tdm128_tx3_ch0_sel : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx0_ch3_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx0_ch3_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx0_ch2_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx0_ch2_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx0_ch1_sel_START (4)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx0_ch1_sel_END (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx0_ch0_sel_START (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx0_ch0_sel_END (7)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx1_ch3_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx1_ch3_sel_END (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx1_ch2_sel_START (10)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx1_ch2_sel_END (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx1_ch1_sel_START (12)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx1_ch1_sel_END (13)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx1_ch0_sel_START (14)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx1_ch0_sel_END (15)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx2_ch3_sel_START (16)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx2_ch3_sel_END (17)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx2_ch2_sel_START (18)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx2_ch2_sel_END (19)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx2_ch1_sel_START (20)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx2_ch1_sel_END (21)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx2_ch0_sel_START (22)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx2_ch0_sel_END (23)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx3_ch3_sel_START (24)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx3_ch3_sel_END (25)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx3_ch2_sel_START (26)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx3_ch2_sel_END (27)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx3_ch1_sel_START (28)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx3_ch1_sel_END (29)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx3_ch0_sel_START (30)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL1_intf1_tdm128_tx3_ch0_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm128_rx0_slot_sel_v0 : 3;
        unsigned int intf1_tdm128_rx0_slot_sel_i0 : 3;
        unsigned int intf1_tdm128_rx0_slot_sel_v1 : 3;
        unsigned int intf1_tdm128_rx0_slot_sel_i1 : 3;
        unsigned int intf1_tdm128_rx0_slot_sel_v2 : 3;
        unsigned int intf1_tdm128_rx0_slot_sel_i2 : 3;
        unsigned int intf1_tdm128_rx0_slot_sel_v3 : 3;
        unsigned int intf1_tdm128_rx0_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL2_intf1_tdm128_rx0_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm128_rx1_slot_sel_v0 : 3;
        unsigned int intf1_tdm128_rx1_slot_sel_i0 : 3;
        unsigned int intf1_tdm128_rx1_slot_sel_v1 : 3;
        unsigned int intf1_tdm128_rx1_slot_sel_i1 : 3;
        unsigned int intf1_tdm128_rx1_slot_sel_v2 : 3;
        unsigned int intf1_tdm128_rx1_slot_sel_i2 : 3;
        unsigned int intf1_tdm128_rx1_slot_sel_v3 : 3;
        unsigned int intf1_tdm128_rx1_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL3_intf1_tdm128_rx1_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm128_rx2_slot_sel_v0 : 3;
        unsigned int intf1_tdm128_rx2_slot_sel_i0 : 3;
        unsigned int intf1_tdm128_rx2_slot_sel_v1 : 3;
        unsigned int intf1_tdm128_rx2_slot_sel_i1 : 3;
        unsigned int intf1_tdm128_rx2_slot_sel_v2 : 3;
        unsigned int intf1_tdm128_rx2_slot_sel_i2 : 3;
        unsigned int intf1_tdm128_rx2_slot_sel_v3 : 3;
        unsigned int intf1_tdm128_rx2_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL4_intf1_tdm128_rx2_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm128_rx3_slot_sel_v0 : 3;
        unsigned int intf1_tdm128_rx3_slot_sel_i0 : 3;
        unsigned int intf1_tdm128_rx3_slot_sel_v1 : 3;
        unsigned int intf1_tdm128_rx3_slot_sel_i1 : 3;
        unsigned int intf1_tdm128_rx3_slot_sel_v2 : 3;
        unsigned int intf1_tdm128_rx3_slot_sel_i2 : 3;
        unsigned int intf1_tdm128_rx3_slot_sel_v3 : 3;
        unsigned int intf1_tdm128_rx3_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF1_TDM128_CTRL5_intf1_tdm128_rx3_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm256_sdi_line_sel : 2;
        unsigned int intf1_tdm256_sdo_line_sel : 2;
        unsigned int intf1_tdm256_frame_mode : 2;
        unsigned int intf1_tdm256_direct_loop : 2;
        unsigned int intf1_tdm256_rx0_slot_sel : 1;
        unsigned int intf1_tdm256_rx1_slot_sel : 1;
        unsigned int intf1_tdm256_rx2_slot_sel : 1;
        unsigned int intf1_tdm256_rx3_slot_sel : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_sdi_line_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_sdi_line_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_sdo_line_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_sdo_line_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_frame_mode_START (4)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_frame_mode_END (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_direct_loop_START (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_direct_loop_END (7)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_rx0_slot_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_rx0_slot_sel_END (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_rx1_slot_sel_START (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_rx1_slot_sel_END (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_rx2_slot_sel_START (10)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_rx2_slot_sel_END (10)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_rx3_slot_sel_START (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL0_intf1_tdm256_rx3_slot_sel_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm256_rx0_slot_sel_v3_32 : 1;
        unsigned int intf1_tdm256_rx0_slot_sel_v2_32 : 1;
        unsigned int intf1_tdm256_rx0_slot_sel_v1_32 : 1;
        unsigned int intf1_tdm256_rx0_slot_sel_v0_32 : 1;
        unsigned int intf1_tdm256_rx0_slot_sel_i3_32 : 1;
        unsigned int intf1_tdm256_rx0_slot_sel_i2_32 : 1;
        unsigned int intf1_tdm256_rx0_slot_sel_i1_32 : 1;
        unsigned int intf1_tdm256_rx0_slot_sel_i0_32 : 1;
        unsigned int intf1_tdm256_rx1_slot_sel_v3_32 : 1;
        unsigned int intf1_tdm256_rx1_slot_sel_v2_32 : 1;
        unsigned int intf1_tdm256_rx1_slot_sel_v1_32 : 1;
        unsigned int intf1_tdm256_rx1_slot_sel_v0_32 : 1;
        unsigned int intf1_tdm256_rx1_slot_sel_i3_32 : 1;
        unsigned int intf1_tdm256_rx1_slot_sel_i2_32 : 1;
        unsigned int intf1_tdm256_rx1_slot_sel_i1_32 : 1;
        unsigned int intf1_tdm256_rx1_slot_sel_i0_32 : 1;
        unsigned int intf1_tdm256_rx2_slot_sel_v3_32 : 1;
        unsigned int intf1_tdm256_rx2_slot_sel_v2_32 : 1;
        unsigned int intf1_tdm256_rx2_slot_sel_v1_32 : 1;
        unsigned int intf1_tdm256_rx2_slot_sel_v0_32 : 1;
        unsigned int intf1_tdm256_rx2_slot_sel_i3_32 : 1;
        unsigned int intf1_tdm256_rx2_slot_sel_i2_32 : 1;
        unsigned int intf1_tdm256_rx2_slot_sel_i1_32 : 1;
        unsigned int intf1_tdm256_rx2_slot_sel_i0_32 : 1;
        unsigned int intf1_tdm256_rx3_slot_sel_v3_32 : 1;
        unsigned int intf1_tdm256_rx3_slot_sel_v2_32 : 1;
        unsigned int intf1_tdm256_rx3_slot_sel_v1_32 : 1;
        unsigned int intf1_tdm256_rx3_slot_sel_v0_32 : 1;
        unsigned int intf1_tdm256_rx3_slot_sel_i3_32 : 1;
        unsigned int intf1_tdm256_rx3_slot_sel_i2_32 : 1;
        unsigned int intf1_tdm256_rx3_slot_sel_i1_32 : 1;
        unsigned int intf1_tdm256_rx3_slot_sel_i0_32 : 1;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_v3_32_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_v3_32_END (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_v2_32_START (1)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_v2_32_END (1)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_v1_32_START (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_v1_32_END (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_v0_32_START (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_v0_32_END (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_i3_32_START (4)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_i3_32_END (4)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_i2_32_START (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_i2_32_END (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_i1_32_START (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_i1_32_END (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_i0_32_START (7)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx0_slot_sel_i0_32_END (7)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_v3_32_START (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_v3_32_END (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_v2_32_START (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_v2_32_END (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_v1_32_START (10)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_v1_32_END (10)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_v0_32_START (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_v0_32_END (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_i3_32_START (12)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_i3_32_END (12)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_i2_32_START (13)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_i2_32_END (13)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_i1_32_START (14)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_i1_32_END (14)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_i0_32_START (15)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx1_slot_sel_i0_32_END (15)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_v3_32_START (16)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_v3_32_END (16)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_v2_32_START (17)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_v2_32_END (17)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_v1_32_START (18)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_v1_32_END (18)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_v0_32_START (19)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_v0_32_END (19)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_i3_32_START (20)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_i3_32_END (20)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_i2_32_START (21)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_i2_32_END (21)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_i1_32_START (22)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_i1_32_END (22)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_i0_32_START (23)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx2_slot_sel_i0_32_END (23)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_v3_32_START (24)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_v3_32_END (24)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_v2_32_START (25)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_v2_32_END (25)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_v1_32_START (26)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_v1_32_END (26)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_v0_32_START (27)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_v0_32_END (27)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_i3_32_START (28)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_i3_32_END (28)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_i2_32_START (29)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_i2_32_END (29)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_i1_32_START (30)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_i1_32_END (30)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_i0_32_START (31)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL1_intf1_tdm256_rx3_slot_sel_i0_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm256_rx0_slot_sel_vb3_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_vb2_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_vb1_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_vb0_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_d3_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_d2_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_d1_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_d0_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_v3_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_v2_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_v1_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_v0_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_i3_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_i2_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_i1_16 : 2;
        unsigned int intf1_tdm256_rx0_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL2_intf1_tdm256_rx0_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm256_rx1_slot_sel_vb3_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_vb2_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_vb1_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_vb0_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_d3_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_d2_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_d1_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_d0_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_v3_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_v2_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_v1_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_v0_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_i3_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_i2_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_i1_16 : 2;
        unsigned int intf1_tdm256_rx1_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL3_intf1_tdm256_rx1_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm256_rx2_slot_sel_vb3_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_vb2_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_vb1_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_vb0_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_d3_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_d2_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_d1_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_d0_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_v3_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_v2_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_v1_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_v0_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_i3_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_i2_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_i1_16 : 2;
        unsigned int intf1_tdm256_rx2_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL4_intf1_tdm256_rx2_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf1_tdm256_rx3_slot_sel_vb3_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_vb2_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_vb1_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_vb0_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_d3_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_d2_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_d1_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_d0_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_v3_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_v2_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_v1_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_v0_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_i3_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_i2_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_i1_16 : 2;
        unsigned int intf1_tdm256_rx3_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF1_TDM256_CTRL5_intf1_tdm256_rx3_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_i2s_if_tx_ena : 1;
        unsigned int intf2_i2s_if_rx_ena : 1;
        unsigned int intf2_tdm128_if_en : 1;
        unsigned int intf2_tdm256_if_en : 1;
        unsigned int intf2_clk_en : 1;
        unsigned int intf2_i2s_tx_clk_sel : 1;
        unsigned int intf2_i2s_rx_clk_sel : 1;
        unsigned int intf2_tdm_tx_clk_sel : 1;
        unsigned int intf2_tdm_rx_clk_sel : 1;
        unsigned int intf2_i2s_fs : 3;
        unsigned int intf2_tdm_fs : 2;
        unsigned int intf2_mst_slv : 1;
        unsigned int intf2_i2s_tdm_mode : 2;
        unsigned int reserved : 15;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_if_tx_ena_START (0)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_if_tx_ena_END (0)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_if_rx_ena_START (1)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_if_rx_ena_END (1)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_tdm128_if_en_START (2)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_tdm128_if_en_END (2)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_tdm256_if_en_START (3)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_tdm256_if_en_END (3)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_clk_en_START (4)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_clk_en_END (4)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_tx_clk_sel_START (5)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_tx_clk_sel_END (5)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_rx_clk_sel_START (6)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_rx_clk_sel_END (6)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_tdm_tx_clk_sel_START (7)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_tdm_tx_clk_sel_END (7)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_tdm_rx_clk_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_tdm_rx_clk_sel_END (8)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_fs_START (9)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_fs_END (11)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_tdm_fs_START (12)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_tdm_fs_END (13)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_mst_slv_START (14)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_mst_slv_END (14)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_tdm_mode_START (15)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL0_intf2_i2s_tdm_mode_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm128_clk_in_sel : 2;
        unsigned int intf2_i2s64_clk_in_sel : 3;
        unsigned int intf2_i2s32_clk_in_sel : 3;
        unsigned int intf2_pcm32_clk_in_sel : 3;
        unsigned int intf2_pcm16_clk_in_sel : 3;
        unsigned int reserved : 18;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_intf2_tdm128_clk_in_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_intf2_tdm128_clk_in_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_intf2_i2s64_clk_in_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_intf2_i2s64_clk_in_sel_END (4)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_intf2_i2s32_clk_in_sel_START (5)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_intf2_i2s32_clk_in_sel_END (7)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_intf2_pcm32_clk_in_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_intf2_pcm32_clk_in_sel_END (10)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_intf2_pcm16_clk_in_sel_START (11)
#define SOC_ASP_AXI2TDM_INTF2_CLK_CTRL1_intf2_pcm16_clk_in_sel_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_i2s_sdi_line_sel : 2;
        unsigned int intf2_i2s_sdo_line_sel : 2;
        unsigned int intf2_i2s_direct_loop : 2;
        unsigned int intf2_i2s_func_mode : 3;
        unsigned int intf2_i2s_frame_mode : 1;
        unsigned int intf2_i2s_lrclk_mode : 1;
        unsigned int intf2_i2s_chnnl_mode : 1;
        unsigned int intf2_i2s_codec_data_format : 1;
        unsigned int intf2_i2s_codec_io_wordlength : 2;
        unsigned int reserved : 17;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_sdi_line_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_sdi_line_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_sdo_line_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_sdo_line_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_direct_loop_START (4)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_direct_loop_END (5)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_func_mode_START (6)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_func_mode_END (8)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_frame_mode_START (9)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_frame_mode_END (9)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_lrclk_mode_START (10)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_lrclk_mode_END (10)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_chnnl_mode_START (11)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_chnnl_mode_END (11)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_codec_data_format_START (12)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_codec_data_format_END (12)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_codec_io_wordlength_START (13)
#define SOC_ASP_AXI2TDM_INTF2_I2S_CTRL_intf2_i2s_codec_io_wordlength_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm128_sdi_line_sel : 2;
        unsigned int intf2_tdm128_sdo_line_sel : 2;
        unsigned int intf2_tdm128_frame_mode : 3;
        unsigned int intf2_tdm128_direct_loop : 2;
        unsigned int reserved : 23;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL0_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL0_intf2_tdm128_sdi_line_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL0_intf2_tdm128_sdi_line_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL0_intf2_tdm128_sdo_line_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL0_intf2_tdm128_sdo_line_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL0_intf2_tdm128_frame_mode_START (4)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL0_intf2_tdm128_frame_mode_END (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL0_intf2_tdm128_direct_loop_START (7)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL0_intf2_tdm128_direct_loop_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm128_tx0_ch3_sel : 2;
        unsigned int intf2_tdm128_tx0_ch2_sel : 2;
        unsigned int intf2_tdm128_tx0_ch1_sel : 2;
        unsigned int intf2_tdm128_tx0_ch0_sel : 2;
        unsigned int intf2_tdm128_tx1_ch3_sel : 2;
        unsigned int intf2_tdm128_tx1_ch2_sel : 2;
        unsigned int intf2_tdm128_tx1_ch1_sel : 2;
        unsigned int intf2_tdm128_tx1_ch0_sel : 2;
        unsigned int intf2_tdm128_tx2_ch3_sel : 2;
        unsigned int intf2_tdm128_tx2_ch2_sel : 2;
        unsigned int intf2_tdm128_tx2_ch1_sel : 2;
        unsigned int intf2_tdm128_tx2_ch0_sel : 2;
        unsigned int intf2_tdm128_tx3_ch3_sel : 2;
        unsigned int intf2_tdm128_tx3_ch2_sel : 2;
        unsigned int intf2_tdm128_tx3_ch1_sel : 2;
        unsigned int intf2_tdm128_tx3_ch0_sel : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx0_ch3_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx0_ch3_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx0_ch2_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx0_ch2_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx0_ch1_sel_START (4)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx0_ch1_sel_END (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx0_ch0_sel_START (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx0_ch0_sel_END (7)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx1_ch3_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx1_ch3_sel_END (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx1_ch2_sel_START (10)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx1_ch2_sel_END (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx1_ch1_sel_START (12)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx1_ch1_sel_END (13)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx1_ch0_sel_START (14)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx1_ch0_sel_END (15)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx2_ch3_sel_START (16)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx2_ch3_sel_END (17)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx2_ch2_sel_START (18)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx2_ch2_sel_END (19)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx2_ch1_sel_START (20)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx2_ch1_sel_END (21)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx2_ch0_sel_START (22)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx2_ch0_sel_END (23)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx3_ch3_sel_START (24)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx3_ch3_sel_END (25)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx3_ch2_sel_START (26)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx3_ch2_sel_END (27)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx3_ch1_sel_START (28)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx3_ch1_sel_END (29)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx3_ch0_sel_START (30)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL1_intf2_tdm128_tx3_ch0_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm128_rx0_slot_sel_v0 : 3;
        unsigned int intf2_tdm128_rx0_slot_sel_i0 : 3;
        unsigned int intf2_tdm128_rx0_slot_sel_v1 : 3;
        unsigned int intf2_tdm128_rx0_slot_sel_i1 : 3;
        unsigned int intf2_tdm128_rx0_slot_sel_v2 : 3;
        unsigned int intf2_tdm128_rx0_slot_sel_i2 : 3;
        unsigned int intf2_tdm128_rx0_slot_sel_v3 : 3;
        unsigned int intf2_tdm128_rx0_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL2_intf2_tdm128_rx0_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm128_rx1_slot_sel_v0 : 3;
        unsigned int intf2_tdm128_rx1_slot_sel_i0 : 3;
        unsigned int intf2_tdm128_rx1_slot_sel_v1 : 3;
        unsigned int intf2_tdm128_rx1_slot_sel_i1 : 3;
        unsigned int intf2_tdm128_rx1_slot_sel_v2 : 3;
        unsigned int intf2_tdm128_rx1_slot_sel_i2 : 3;
        unsigned int intf2_tdm128_rx1_slot_sel_v3 : 3;
        unsigned int intf2_tdm128_rx1_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL3_intf2_tdm128_rx1_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm128_rx2_slot_sel_v0 : 3;
        unsigned int intf2_tdm128_rx2_slot_sel_i0 : 3;
        unsigned int intf2_tdm128_rx2_slot_sel_v1 : 3;
        unsigned int intf2_tdm128_rx2_slot_sel_i1 : 3;
        unsigned int intf2_tdm128_rx2_slot_sel_v2 : 3;
        unsigned int intf2_tdm128_rx2_slot_sel_i2 : 3;
        unsigned int intf2_tdm128_rx2_slot_sel_v3 : 3;
        unsigned int intf2_tdm128_rx2_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL4_intf2_tdm128_rx2_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm128_rx3_slot_sel_v0 : 3;
        unsigned int intf2_tdm128_rx3_slot_sel_i0 : 3;
        unsigned int intf2_tdm128_rx3_slot_sel_v1 : 3;
        unsigned int intf2_tdm128_rx3_slot_sel_i1 : 3;
        unsigned int intf2_tdm128_rx3_slot_sel_v2 : 3;
        unsigned int intf2_tdm128_rx3_slot_sel_i2 : 3;
        unsigned int intf2_tdm128_rx3_slot_sel_v3 : 3;
        unsigned int intf2_tdm128_rx3_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF2_TDM128_CTRL5_intf2_tdm128_rx3_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm256_sdi_line_sel : 2;
        unsigned int intf2_tdm256_sdo_line_sel : 2;
        unsigned int intf2_tdm256_frame_mode : 2;
        unsigned int intf2_tdm256_direct_loop : 2;
        unsigned int intf2_tdm256_rx0_slot_sel : 1;
        unsigned int intf2_tdm256_rx1_slot_sel : 1;
        unsigned int intf2_tdm256_rx2_slot_sel : 1;
        unsigned int intf2_tdm256_rx3_slot_sel : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_sdi_line_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_sdi_line_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_sdo_line_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_sdo_line_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_frame_mode_START (4)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_frame_mode_END (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_direct_loop_START (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_direct_loop_END (7)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_rx0_slot_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_rx0_slot_sel_END (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_rx1_slot_sel_START (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_rx1_slot_sel_END (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_rx2_slot_sel_START (10)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_rx2_slot_sel_END (10)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_rx3_slot_sel_START (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL0_intf2_tdm256_rx3_slot_sel_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm256_rx0_slot_sel_v3_32 : 1;
        unsigned int intf2_tdm256_rx0_slot_sel_v2_32 : 1;
        unsigned int intf2_tdm256_rx0_slot_sel_v1_32 : 1;
        unsigned int intf2_tdm256_rx0_slot_sel_v0_32 : 1;
        unsigned int intf2_tdm256_rx0_slot_sel_i3_32 : 1;
        unsigned int intf2_tdm256_rx0_slot_sel_i2_32 : 1;
        unsigned int intf2_tdm256_rx0_slot_sel_i1_32 : 1;
        unsigned int intf2_tdm256_rx0_slot_sel_i0_32 : 1;
        unsigned int intf2_tdm256_rx1_slot_sel_v3_32 : 1;
        unsigned int intf2_tdm256_rx1_slot_sel_v2_32 : 1;
        unsigned int intf2_tdm256_rx1_slot_sel_v1_32 : 1;
        unsigned int intf2_tdm256_rx1_slot_sel_v0_32 : 1;
        unsigned int intf2_tdm256_rx1_slot_sel_i3_32 : 1;
        unsigned int intf2_tdm256_rx1_slot_sel_i2_32 : 1;
        unsigned int intf2_tdm256_rx1_slot_sel_i1_32 : 1;
        unsigned int intf2_tdm256_rx1_slot_sel_i0_32 : 1;
        unsigned int intf2_tdm256_rx2_slot_sel_v3_32 : 1;
        unsigned int intf2_tdm256_rx2_slot_sel_v2_32 : 1;
        unsigned int intf2_tdm256_rx2_slot_sel_v1_32 : 1;
        unsigned int intf2_tdm256_rx2_slot_sel_v0_32 : 1;
        unsigned int intf2_tdm256_rx2_slot_sel_i3_32 : 1;
        unsigned int intf2_tdm256_rx2_slot_sel_i2_32 : 1;
        unsigned int intf2_tdm256_rx2_slot_sel_i1_32 : 1;
        unsigned int intf2_tdm256_rx2_slot_sel_i0_32 : 1;
        unsigned int intf2_tdm256_rx3_slot_sel_v3_32 : 1;
        unsigned int intf2_tdm256_rx3_slot_sel_v2_32 : 1;
        unsigned int intf2_tdm256_rx3_slot_sel_v1_32 : 1;
        unsigned int intf2_tdm256_rx3_slot_sel_v0_32 : 1;
        unsigned int intf2_tdm256_rx3_slot_sel_i3_32 : 1;
        unsigned int intf2_tdm256_rx3_slot_sel_i2_32 : 1;
        unsigned int intf2_tdm256_rx3_slot_sel_i1_32 : 1;
        unsigned int intf2_tdm256_rx3_slot_sel_i0_32 : 1;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_v3_32_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_v3_32_END (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_v2_32_START (1)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_v2_32_END (1)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_v1_32_START (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_v1_32_END (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_v0_32_START (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_v0_32_END (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_i3_32_START (4)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_i3_32_END (4)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_i2_32_START (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_i2_32_END (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_i1_32_START (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_i1_32_END (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_i0_32_START (7)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx0_slot_sel_i0_32_END (7)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_v3_32_START (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_v3_32_END (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_v2_32_START (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_v2_32_END (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_v1_32_START (10)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_v1_32_END (10)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_v0_32_START (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_v0_32_END (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_i3_32_START (12)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_i3_32_END (12)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_i2_32_START (13)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_i2_32_END (13)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_i1_32_START (14)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_i1_32_END (14)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_i0_32_START (15)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx1_slot_sel_i0_32_END (15)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_v3_32_START (16)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_v3_32_END (16)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_v2_32_START (17)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_v2_32_END (17)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_v1_32_START (18)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_v1_32_END (18)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_v0_32_START (19)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_v0_32_END (19)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_i3_32_START (20)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_i3_32_END (20)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_i2_32_START (21)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_i2_32_END (21)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_i1_32_START (22)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_i1_32_END (22)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_i0_32_START (23)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx2_slot_sel_i0_32_END (23)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_v3_32_START (24)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_v3_32_END (24)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_v2_32_START (25)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_v2_32_END (25)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_v1_32_START (26)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_v1_32_END (26)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_v0_32_START (27)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_v0_32_END (27)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_i3_32_START (28)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_i3_32_END (28)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_i2_32_START (29)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_i2_32_END (29)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_i1_32_START (30)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_i1_32_END (30)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_i0_32_START (31)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL1_intf2_tdm256_rx3_slot_sel_i0_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm256_rx0_slot_sel_vb3_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_vb2_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_vb1_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_vb0_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_d3_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_d2_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_d1_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_d0_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_v3_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_v2_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_v1_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_v0_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_i3_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_i2_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_i1_16 : 2;
        unsigned int intf2_tdm256_rx0_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL2_intf2_tdm256_rx0_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm256_rx1_slot_sel_vb3_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_vb2_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_vb1_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_vb0_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_d3_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_d2_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_d1_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_d0_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_v3_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_v2_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_v1_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_v0_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_i3_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_i2_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_i1_16 : 2;
        unsigned int intf2_tdm256_rx1_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL3_intf2_tdm256_rx1_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm256_rx2_slot_sel_vb3_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_vb2_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_vb1_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_vb0_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_d3_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_d2_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_d1_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_d0_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_v3_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_v2_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_v1_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_v0_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_i3_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_i2_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_i1_16 : 2;
        unsigned int intf2_tdm256_rx2_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL4_intf2_tdm256_rx2_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf2_tdm256_rx3_slot_sel_vb3_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_vb2_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_vb1_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_vb0_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_d3_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_d2_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_d1_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_d0_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_v3_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_v2_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_v1_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_v0_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_i3_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_i2_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_i1_16 : 2;
        unsigned int intf2_tdm256_rx3_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF2_TDM256_CTRL5_intf2_tdm256_rx3_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_i2s_if_tx_ena : 1;
        unsigned int intf3_i2s_if_rx_ena : 1;
        unsigned int intf3_tdm128_if_en : 1;
        unsigned int intf3_tdm256_if_en : 1;
        unsigned int intf3_clk_en : 1;
        unsigned int intf3_i2s_tx_clk_sel : 1;
        unsigned int intf3_i2s_rx_clk_sel : 1;
        unsigned int intf3_tdm_tx_clk_sel : 1;
        unsigned int intf3_tdm_rx_clk_sel : 1;
        unsigned int intf3_i2s_fs : 3;
        unsigned int intf3_tdm_fs : 2;
        unsigned int intf3_mst_slv : 1;
        unsigned int intf3_i2s_tdm_mode : 2;
        unsigned int reserved : 15;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_if_tx_ena_START (0)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_if_tx_ena_END (0)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_if_rx_ena_START (1)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_if_rx_ena_END (1)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_tdm128_if_en_START (2)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_tdm128_if_en_END (2)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_tdm256_if_en_START (3)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_tdm256_if_en_END (3)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_clk_en_START (4)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_clk_en_END (4)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_tx_clk_sel_START (5)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_tx_clk_sel_END (5)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_rx_clk_sel_START (6)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_rx_clk_sel_END (6)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_tdm_tx_clk_sel_START (7)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_tdm_tx_clk_sel_END (7)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_tdm_rx_clk_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_tdm_rx_clk_sel_END (8)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_fs_START (9)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_fs_END (11)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_tdm_fs_START (12)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_tdm_fs_END (13)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_mst_slv_START (14)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_mst_slv_END (14)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_tdm_mode_START (15)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL0_intf3_i2s_tdm_mode_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm128_clk_in_sel : 2;
        unsigned int intf3_i2s64_clk_in_sel : 3;
        unsigned int intf3_i2s32_clk_in_sel : 3;
        unsigned int intf3_pcm32_clk_in_sel : 3;
        unsigned int intf3_pcm16_clk_in_sel : 3;
        unsigned int reserved : 18;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_intf3_tdm128_clk_in_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_intf3_tdm128_clk_in_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_intf3_i2s64_clk_in_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_intf3_i2s64_clk_in_sel_END (4)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_intf3_i2s32_clk_in_sel_START (5)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_intf3_i2s32_clk_in_sel_END (7)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_intf3_pcm32_clk_in_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_intf3_pcm32_clk_in_sel_END (10)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_intf3_pcm16_clk_in_sel_START (11)
#define SOC_ASP_AXI2TDM_INTF3_CLK_CTRL1_intf3_pcm16_clk_in_sel_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_i2s_sdi_line_sel : 2;
        unsigned int intf3_i2s_sdo_line_sel : 2;
        unsigned int intf3_i2s_direct_loop : 2;
        unsigned int intf3_i2s_func_mode : 3;
        unsigned int intf3_i2s_frame_mode : 1;
        unsigned int intf3_i2s_lrclk_mode : 1;
        unsigned int intf3_i2s_chnnl_mode : 1;
        unsigned int intf3_i2s_codec_data_format : 1;
        unsigned int intf3_i2s_codec_io_wordlength : 2;
        unsigned int reserved : 17;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_sdi_line_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_sdi_line_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_sdo_line_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_sdo_line_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_direct_loop_START (4)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_direct_loop_END (5)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_func_mode_START (6)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_func_mode_END (8)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_frame_mode_START (9)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_frame_mode_END (9)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_lrclk_mode_START (10)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_lrclk_mode_END (10)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_chnnl_mode_START (11)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_chnnl_mode_END (11)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_codec_data_format_START (12)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_codec_data_format_END (12)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_codec_io_wordlength_START (13)
#define SOC_ASP_AXI2TDM_INTF3_I2S_CTRL_intf3_i2s_codec_io_wordlength_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm128_sdi_line_sel : 2;
        unsigned int intf3_tdm128_sdo_line_sel : 2;
        unsigned int intf3_tdm128_frame_mode : 3;
        unsigned int intf3_tdm128_direct_loop : 2;
        unsigned int reserved : 23;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL0_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL0_intf3_tdm128_sdi_line_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL0_intf3_tdm128_sdi_line_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL0_intf3_tdm128_sdo_line_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL0_intf3_tdm128_sdo_line_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL0_intf3_tdm128_frame_mode_START (4)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL0_intf3_tdm128_frame_mode_END (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL0_intf3_tdm128_direct_loop_START (7)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL0_intf3_tdm128_direct_loop_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm128_tx0_ch3_sel : 2;
        unsigned int intf3_tdm128_tx0_ch2_sel : 2;
        unsigned int intf3_tdm128_tx0_ch1_sel : 2;
        unsigned int intf3_tdm128_tx0_ch0_sel : 2;
        unsigned int intf3_tdm128_tx1_ch3_sel : 2;
        unsigned int intf3_tdm128_tx1_ch2_sel : 2;
        unsigned int intf3_tdm128_tx1_ch1_sel : 2;
        unsigned int intf3_tdm128_tx1_ch0_sel : 2;
        unsigned int intf3_tdm128_tx2_ch3_sel : 2;
        unsigned int intf3_tdm128_tx2_ch2_sel : 2;
        unsigned int intf3_tdm128_tx2_ch1_sel : 2;
        unsigned int intf3_tdm128_tx2_ch0_sel : 2;
        unsigned int intf3_tdm128_tx3_ch3_sel : 2;
        unsigned int intf3_tdm128_tx3_ch2_sel : 2;
        unsigned int intf3_tdm128_tx3_ch1_sel : 2;
        unsigned int intf3_tdm128_tx3_ch0_sel : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx0_ch3_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx0_ch3_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx0_ch2_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx0_ch2_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx0_ch1_sel_START (4)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx0_ch1_sel_END (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx0_ch0_sel_START (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx0_ch0_sel_END (7)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx1_ch3_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx1_ch3_sel_END (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx1_ch2_sel_START (10)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx1_ch2_sel_END (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx1_ch1_sel_START (12)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx1_ch1_sel_END (13)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx1_ch0_sel_START (14)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx1_ch0_sel_END (15)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx2_ch3_sel_START (16)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx2_ch3_sel_END (17)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx2_ch2_sel_START (18)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx2_ch2_sel_END (19)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx2_ch1_sel_START (20)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx2_ch1_sel_END (21)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx2_ch0_sel_START (22)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx2_ch0_sel_END (23)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx3_ch3_sel_START (24)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx3_ch3_sel_END (25)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx3_ch2_sel_START (26)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx3_ch2_sel_END (27)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx3_ch1_sel_START (28)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx3_ch1_sel_END (29)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx3_ch0_sel_START (30)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL1_intf3_tdm128_tx3_ch0_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm128_rx0_slot_sel_v0 : 3;
        unsigned int intf3_tdm128_rx0_slot_sel_i0 : 3;
        unsigned int intf3_tdm128_rx0_slot_sel_v1 : 3;
        unsigned int intf3_tdm128_rx0_slot_sel_i1 : 3;
        unsigned int intf3_tdm128_rx0_slot_sel_v2 : 3;
        unsigned int intf3_tdm128_rx0_slot_sel_i2 : 3;
        unsigned int intf3_tdm128_rx0_slot_sel_v3 : 3;
        unsigned int intf3_tdm128_rx0_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL2_intf3_tdm128_rx0_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm128_rx1_slot_sel_v0 : 3;
        unsigned int intf3_tdm128_rx1_slot_sel_i0 : 3;
        unsigned int intf3_tdm128_rx1_slot_sel_v1 : 3;
        unsigned int intf3_tdm128_rx1_slot_sel_i1 : 3;
        unsigned int intf3_tdm128_rx1_slot_sel_v2 : 3;
        unsigned int intf3_tdm128_rx1_slot_sel_i2 : 3;
        unsigned int intf3_tdm128_rx1_slot_sel_v3 : 3;
        unsigned int intf3_tdm128_rx1_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL3_intf3_tdm128_rx1_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm128_rx2_slot_sel_v0 : 3;
        unsigned int intf3_tdm128_rx2_slot_sel_i0 : 3;
        unsigned int intf3_tdm128_rx2_slot_sel_v1 : 3;
        unsigned int intf3_tdm128_rx2_slot_sel_i1 : 3;
        unsigned int intf3_tdm128_rx2_slot_sel_v2 : 3;
        unsigned int intf3_tdm128_rx2_slot_sel_i2 : 3;
        unsigned int intf3_tdm128_rx2_slot_sel_v3 : 3;
        unsigned int intf3_tdm128_rx2_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL4_intf3_tdm128_rx2_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm128_rx3_slot_sel_v0 : 3;
        unsigned int intf3_tdm128_rx3_slot_sel_i0 : 3;
        unsigned int intf3_tdm128_rx3_slot_sel_v1 : 3;
        unsigned int intf3_tdm128_rx3_slot_sel_i1 : 3;
        unsigned int intf3_tdm128_rx3_slot_sel_v2 : 3;
        unsigned int intf3_tdm128_rx3_slot_sel_i2 : 3;
        unsigned int intf3_tdm128_rx3_slot_sel_v3 : 3;
        unsigned int intf3_tdm128_rx3_slot_sel_i3 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_v0_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_v0_END (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_i0_START (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_i0_END (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_v1_START (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_v1_END (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_i1_START (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_i1_END (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_v2_START (12)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_v2_END (14)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_i2_START (15)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_i2_END (17)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_v3_START (18)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_v3_END (20)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_i3_START (21)
#define SOC_ASP_AXI2TDM_INTF3_TDM128_CTRL5_intf3_tdm128_rx3_slot_sel_i3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm256_sdi_line_sel : 2;
        unsigned int intf3_tdm256_sdo_line_sel : 2;
        unsigned int intf3_tdm256_frame_mode : 2;
        unsigned int intf3_tdm256_direct_loop : 2;
        unsigned int intf3_tdm256_rx0_slot_sel : 1;
        unsigned int intf3_tdm256_rx1_slot_sel : 1;
        unsigned int intf3_tdm256_rx2_slot_sel : 1;
        unsigned int intf3_tdm256_rx3_slot_sel : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_sdi_line_sel_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_sdi_line_sel_END (1)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_sdo_line_sel_START (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_sdo_line_sel_END (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_frame_mode_START (4)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_frame_mode_END (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_direct_loop_START (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_direct_loop_END (7)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_rx0_slot_sel_START (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_rx0_slot_sel_END (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_rx1_slot_sel_START (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_rx1_slot_sel_END (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_rx2_slot_sel_START (10)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_rx2_slot_sel_END (10)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_rx3_slot_sel_START (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL0_intf3_tdm256_rx3_slot_sel_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm256_rx0_slot_sel_v3_32 : 1;
        unsigned int intf3_tdm256_rx0_slot_sel_v2_32 : 1;
        unsigned int intf3_tdm256_rx0_slot_sel_v1_32 : 1;
        unsigned int intf3_tdm256_rx0_slot_sel_v0_32 : 1;
        unsigned int intf3_tdm256_rx0_slot_sel_i3_32 : 1;
        unsigned int intf3_tdm256_rx0_slot_sel_i2_32 : 1;
        unsigned int intf3_tdm256_rx0_slot_sel_i1_32 : 1;
        unsigned int intf3_tdm256_rx0_slot_sel_i0_32 : 1;
        unsigned int intf3_tdm256_rx1_slot_sel_v3_32 : 1;
        unsigned int intf3_tdm256_rx1_slot_sel_v2_32 : 1;
        unsigned int intf3_tdm256_rx1_slot_sel_v1_32 : 1;
        unsigned int intf3_tdm256_rx1_slot_sel_v0_32 : 1;
        unsigned int intf3_tdm256_rx1_slot_sel_i3_32 : 1;
        unsigned int intf3_tdm256_rx1_slot_sel_i2_32 : 1;
        unsigned int intf3_tdm256_rx1_slot_sel_i1_32 : 1;
        unsigned int intf3_tdm256_rx1_slot_sel_i0_32 : 1;
        unsigned int intf3_tdm256_rx2_slot_sel_v3_32 : 1;
        unsigned int intf3_tdm256_rx2_slot_sel_v2_32 : 1;
        unsigned int intf3_tdm256_rx2_slot_sel_v1_32 : 1;
        unsigned int intf3_tdm256_rx2_slot_sel_v0_32 : 1;
        unsigned int intf3_tdm256_rx2_slot_sel_i3_32 : 1;
        unsigned int intf3_tdm256_rx2_slot_sel_i2_32 : 1;
        unsigned int intf3_tdm256_rx2_slot_sel_i1_32 : 1;
        unsigned int intf3_tdm256_rx2_slot_sel_i0_32 : 1;
        unsigned int intf3_tdm256_rx3_slot_sel_v3_32 : 1;
        unsigned int intf3_tdm256_rx3_slot_sel_v2_32 : 1;
        unsigned int intf3_tdm256_rx3_slot_sel_v1_32 : 1;
        unsigned int intf3_tdm256_rx3_slot_sel_v0_32 : 1;
        unsigned int intf3_tdm256_rx3_slot_sel_i3_32 : 1;
        unsigned int intf3_tdm256_rx3_slot_sel_i2_32 : 1;
        unsigned int intf3_tdm256_rx3_slot_sel_i1_32 : 1;
        unsigned int intf3_tdm256_rx3_slot_sel_i0_32 : 1;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_v3_32_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_v3_32_END (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_v2_32_START (1)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_v2_32_END (1)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_v1_32_START (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_v1_32_END (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_v0_32_START (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_v0_32_END (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_i3_32_START (4)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_i3_32_END (4)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_i2_32_START (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_i2_32_END (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_i1_32_START (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_i1_32_END (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_i0_32_START (7)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx0_slot_sel_i0_32_END (7)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_v3_32_START (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_v3_32_END (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_v2_32_START (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_v2_32_END (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_v1_32_START (10)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_v1_32_END (10)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_v0_32_START (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_v0_32_END (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_i3_32_START (12)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_i3_32_END (12)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_i2_32_START (13)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_i2_32_END (13)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_i1_32_START (14)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_i1_32_END (14)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_i0_32_START (15)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx1_slot_sel_i0_32_END (15)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_v3_32_START (16)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_v3_32_END (16)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_v2_32_START (17)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_v2_32_END (17)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_v1_32_START (18)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_v1_32_END (18)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_v0_32_START (19)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_v0_32_END (19)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_i3_32_START (20)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_i3_32_END (20)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_i2_32_START (21)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_i2_32_END (21)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_i1_32_START (22)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_i1_32_END (22)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_i0_32_START (23)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx2_slot_sel_i0_32_END (23)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_v3_32_START (24)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_v3_32_END (24)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_v2_32_START (25)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_v2_32_END (25)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_v1_32_START (26)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_v1_32_END (26)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_v0_32_START (27)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_v0_32_END (27)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_i3_32_START (28)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_i3_32_END (28)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_i2_32_START (29)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_i2_32_END (29)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_i1_32_START (30)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_i1_32_END (30)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_i0_32_START (31)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL1_intf3_tdm256_rx3_slot_sel_i0_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm256_rx0_slot_sel_vb3_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_vb2_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_vb1_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_vb0_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_d3_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_d2_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_d1_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_d0_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_v3_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_v2_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_v1_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_v0_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_i3_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_i2_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_i1_16 : 2;
        unsigned int intf3_tdm256_rx0_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL2_intf3_tdm256_rx0_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm256_rx1_slot_sel_vb3_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_vb2_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_vb1_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_vb0_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_d3_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_d2_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_d1_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_d0_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_v3_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_v2_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_v1_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_v0_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_i3_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_i2_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_i1_16 : 2;
        unsigned int intf3_tdm256_rx1_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL3_intf3_tdm256_rx1_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm256_rx2_slot_sel_vb3_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_vb2_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_vb1_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_vb0_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_d3_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_d2_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_d1_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_d0_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_v3_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_v2_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_v1_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_v0_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_i3_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_i2_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_i1_16 : 2;
        unsigned int intf3_tdm256_rx2_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL4_intf3_tdm256_rx2_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intf3_tdm256_rx3_slot_sel_vb3_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_vb2_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_vb1_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_vb0_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_d3_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_d2_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_d1_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_d0_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_v3_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_v2_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_v1_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_v0_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_i3_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_i2_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_i1_16 : 2;
        unsigned int intf3_tdm256_rx3_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_UNION;
#endif
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_vb3_16_START (0)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_vb3_16_END (1)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_vb2_16_START (2)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_vb2_16_END (3)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_vb1_16_START (4)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_vb1_16_END (5)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_vb0_16_START (6)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_vb0_16_END (7)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_d3_16_START (8)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_d3_16_END (9)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_d2_16_START (10)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_d2_16_END (11)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_d1_16_START (12)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_d1_16_END (13)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_d0_16_START (14)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_d0_16_END (15)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_v3_16_START (16)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_v3_16_END (17)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_v2_16_START (18)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_v2_16_END (19)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_v1_16_START (20)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_v1_16_END (21)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_v0_16_START (22)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_v0_16_END (23)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_i3_16_START (24)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_i3_16_END (25)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_i2_16_START (26)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_i2_16_END (27)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_i1_16_START (28)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_i1_16_END (29)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_i0_16_START (30)
#define SOC_ASP_AXI2TDM_INTF3_TDM256_CTRL5_intf3_tdm256_rx3_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp_if0_fifo_thre_up : 8;
        unsigned int dsp_if0_fifo_thre_dn : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_0_UNION;
#endif
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_0_dsp_if0_fifo_thre_up_START (0)
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_0_dsp_if0_fifo_thre_up_END (7)
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_0_dsp_if0_fifo_thre_dn_START (8)
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_0_dsp_if0_fifo_thre_dn_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp_if1_fifo_thre_up : 8;
        unsigned int dsp_if1_fifo_thre_dn : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_1_UNION;
#endif
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_1_dsp_if1_fifo_thre_up_START (0)
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_1_dsp_if1_fifo_thre_up_END (7)
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_1_dsp_if1_fifo_thre_dn_START (8)
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_1_dsp_if1_fifo_thre_dn_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp_if2_fifo_thre_up : 8;
        unsigned int dsp_if2_fifo_thre_dn : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_2_UNION;
#endif
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_2_dsp_if2_fifo_thre_up_START (0)
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_2_dsp_if2_fifo_thre_up_END (7)
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_2_dsp_if2_fifo_thre_dn_START (8)
#define SOC_ASP_AXI2TDM_DSPIF_AFIFO_THRE_CTRL_2_dsp_if2_fifo_thre_dn_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_AXI2TDM_MEM_CTRL_UNION;
#endif
#define SOC_ASP_AXI2TDM_MEM_CTRL_mem_ctrl_d1w2r_START (0)
#define SOC_ASP_AXI2TDM_MEM_CTRL_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi2tdm_fifo_empty_dn_index_en : 3;
        unsigned int axi2tdm_fifo_empty_up_index_en : 3;
        unsigned int axi2tdm_fifo_full_dn_index_en : 3;
        unsigned int axi2tdm_fifo_full_up_index_en : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG1_UNION;
#endif
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG1_axi2tdm_fifo_empty_dn_index_en_START (0)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG1_axi2tdm_fifo_empty_dn_index_en_END (2)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG1_axi2tdm_fifo_empty_up_index_en_START (3)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG1_axi2tdm_fifo_empty_up_index_en_END (5)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG1_axi2tdm_fifo_full_dn_index_en_START (6)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG1_axi2tdm_fifo_full_dn_index_en_END (8)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG1_axi2tdm_fifo_full_up_index_en_START (9)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG1_axi2tdm_fifo_full_up_index_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi2tdm_fifo_empty_dn_index : 3;
        unsigned int axi2tdm_fifo_empty_up_index : 3;
        unsigned int axi2tdm_fifo_full_dn_index : 3;
        unsigned int axi2tdm_fifo_full_up_index : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG2_UNION;
#endif
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG2_axi2tdm_fifo_empty_dn_index_START (0)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG2_axi2tdm_fifo_empty_dn_index_END (2)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG2_axi2tdm_fifo_empty_up_index_START (3)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG2_axi2tdm_fifo_empty_up_index_END (5)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG2_axi2tdm_fifo_full_dn_index_START (6)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG2_axi2tdm_fifo_full_dn_index_END (8)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG2_axi2tdm_fifo_full_up_index_START (9)
#define SOC_ASP_AXI2TDM_DSPIF_FIFO_DBG2_axi2tdm_fifo_full_up_index_END (11)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
