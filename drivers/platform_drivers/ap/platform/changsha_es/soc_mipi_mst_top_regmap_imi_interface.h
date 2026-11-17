#ifndef __SOC_MIPI_MST_TOP_REGMAP_IMI_INTERFACE_H__
#define __SOC_MIPI_MST_TOP_REGMAP_IMI_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_CTRL_EN_ADDR(base) ((base) + (0x0UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_SEQ_EN_ADDR(base) ((base) + (0x4UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_EN_ADDR(base) ((base) + (0x8UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_READ_CMD_EN_ADDR(base) ((base) + (0xCUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_MIPI_CKG_ADDR(base) ((base) + (0x10UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_CKG_WAIT_NUM_ADDR(base) ((base) + (0x14UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_SDATA_OEN_ADDR(base) ((base) + (0x18UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_CTRL0_ADDR(base) ((base) + (0x1CUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_QUART_SPD_EN_ADDR(base) ((base) + (0x20UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_ST_RPT_ADDR(base) ((base) + (0x24UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_SEQ0_MIPI_CMD_ERR_RPT_ADDR(base) ((base) + (0x28UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_ALL_MIPI_IDLE_RPT_ADDR(base) ((base) + (0x2CUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_END_FLAG_ADDR(base) ((base) + (0x30UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_END_FLAG_CLR_ADDR(base) ((base) + (0x34UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_FIFO_STATUS_0_ADDR(base) ((base) + (0x38UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_FIFO_STATUS_1_ADDR(base) ((base) + (0x3CUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_DATA0_ADDR(base) ((base) + (0x40UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_DATA1_ADDR(base) ((base) + (0x44UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_DEPTH_CFG_ADDR(base) ((base) + (0x48UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_CLK_DIV_ADDR(base) ((base) + (0x4CUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_EN_ADDR(base) ((base) + (0x50UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_DIS_ADDR(base) ((base) + (0x54UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_STA_ADDR(base) ((base) + (0x58UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_CKG_EN_IND_ADDR(base) ((base) + (0x5CUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_EN_ADDR(base) ((base) + (0x60UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_DIS_ADDR(base) ((base) + (0x64UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_STA_ADDR(base) ((base) + (0x68UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_BASE_ADDR_ADDR(base) ((base) + (0x6CUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_SEQ_PRI_ADDR(base) ((base) + (0x70UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_CFG_PRI_ADDR(base) ((base) + (0x74UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_MASK_ADDR(base) ((base) + (0x78UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_CLR_ADDR(base) ((base) + (0x7CUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_RAW_ADDR(base) ((base) + (0x80UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_STA_ADDR(base) ((base) + (0x84UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_MASK_ADDR(base) ((base) + (0x88UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_CLR_ADDR(base) ((base) + (0x8CUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_RAW_ADDR(base) ((base) + (0x90UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_STA_ADDR(base) ((base) + (0x94UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_MASK_ADDR(base) ((base) + (0x98UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_CLR_ADDR(base) ((base) + (0x9CUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_RAW_ADDR(base) ((base) + (0xA0UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_STA_ADDR(base) ((base) + (0xA4UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_MASK_ADDR(base) ((base) + (0xA8UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_CLR_ADDR(base) ((base) + (0xACUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_RAW_ADDR(base) ((base) + (0xB0UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFOT_INT_STA_ADDR(base) ((base) + (0xB4UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_INT_CKG_BYPASS_ADDR(base) ((base) + (0xB8UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_ABNORMAL_PRI_BIT_IDX_RPT_ADDR(base) ((base) + (0xBCUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_BUSY_RPT_ADDR(base) ((base) + (0xC0UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_DISABLE_ST_RPT_ADDR(base) ((base) + (0xC4UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_SCLK_OEN_ADDR(base) ((base) + (0xC8UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_PRI_BIT_RAM_BADDR_ADDR(base) ((base) + (0xCCUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_PRI_BIT_RAM_CFG_ERR_ADDR(base) ((base) + (0xD0UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_CFG_ERR_ADDR(base) ((base) + (0xD4UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES0_CTRL_ADDR(base) ((base) + (0x300UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES1_CTRL_ADDR(base) ((base) + (0x304UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES2_CTRL_ADDR(base) ((base) + (0x308UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES3_CTRL_ADDR(base) ((base) + (0x30CUL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES4_CTRL_ADDR(base) ((base) + (0x310UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES5_CTRL_ADDR(base) ((base) + (0x314UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES6_CTRL_ADDR(base) ((base) + (0x318UL))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES7_CTRL_ADDR(base) ((base) + (0x31CUL))
#else
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_CTRL_EN_ADDR(base) ((base) + (0x0))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_SEQ_EN_ADDR(base) ((base) + (0x4))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_EN_ADDR(base) ((base) + (0x8))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_READ_CMD_EN_ADDR(base) ((base) + (0xC))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_MIPI_CKG_ADDR(base) ((base) + (0x10))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_CKG_WAIT_NUM_ADDR(base) ((base) + (0x14))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_SDATA_OEN_ADDR(base) ((base) + (0x18))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_CTRL0_ADDR(base) ((base) + (0x1C))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_QUART_SPD_EN_ADDR(base) ((base) + (0x20))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_ST_RPT_ADDR(base) ((base) + (0x24))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_SEQ0_MIPI_CMD_ERR_RPT_ADDR(base) ((base) + (0x28))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_ALL_MIPI_IDLE_RPT_ADDR(base) ((base) + (0x2C))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_END_FLAG_ADDR(base) ((base) + (0x30))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_END_FLAG_CLR_ADDR(base) ((base) + (0x34))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_FIFO_STATUS_0_ADDR(base) ((base) + (0x38))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_FIFO_STATUS_1_ADDR(base) ((base) + (0x3C))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_DATA0_ADDR(base) ((base) + (0x40))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_DATA1_ADDR(base) ((base) + (0x44))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_DEPTH_CFG_ADDR(base) ((base) + (0x48))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_CLK_DIV_ADDR(base) ((base) + (0x4C))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_EN_ADDR(base) ((base) + (0x50))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_DIS_ADDR(base) ((base) + (0x54))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_STA_ADDR(base) ((base) + (0x58))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_CKG_EN_IND_ADDR(base) ((base) + (0x5C))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_EN_ADDR(base) ((base) + (0x60))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_DIS_ADDR(base) ((base) + (0x64))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_STA_ADDR(base) ((base) + (0x68))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_BASE_ADDR_ADDR(base) ((base) + (0x6C))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_SEQ_PRI_ADDR(base) ((base) + (0x70))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_CFG_PRI_ADDR(base) ((base) + (0x74))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_MASK_ADDR(base) ((base) + (0x78))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_CLR_ADDR(base) ((base) + (0x7C))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_RAW_ADDR(base) ((base) + (0x80))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_STA_ADDR(base) ((base) + (0x84))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_MASK_ADDR(base) ((base) + (0x88))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_CLR_ADDR(base) ((base) + (0x8C))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_RAW_ADDR(base) ((base) + (0x90))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_STA_ADDR(base) ((base) + (0x94))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_MASK_ADDR(base) ((base) + (0x98))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_CLR_ADDR(base) ((base) + (0x9C))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_RAW_ADDR(base) ((base) + (0xA0))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_STA_ADDR(base) ((base) + (0xA4))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_MASK_ADDR(base) ((base) + (0xA8))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_CLR_ADDR(base) ((base) + (0xAC))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_RAW_ADDR(base) ((base) + (0xB0))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFOT_INT_STA_ADDR(base) ((base) + (0xB4))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_INT_CKG_BYPASS_ADDR(base) ((base) + (0xB8))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_ABNORMAL_PRI_BIT_IDX_RPT_ADDR(base) ((base) + (0xBC))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_BUSY_RPT_ADDR(base) ((base) + (0xC0))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_DISABLE_ST_RPT_ADDR(base) ((base) + (0xC4))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_SCLK_OEN_ADDR(base) ((base) + (0xC8))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_PRI_BIT_RAM_BADDR_ADDR(base) ((base) + (0xCC))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_PRI_BIT_RAM_CFG_ERR_ADDR(base) ((base) + (0xD0))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_CFG_ERR_ADDR(base) ((base) + (0xD4))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES0_CTRL_ADDR(base) ((base) + (0x300))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES1_CTRL_ADDR(base) ((base) + (0x304))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES2_CTRL_ADDR(base) ((base) + (0x308))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES3_CTRL_ADDR(base) ((base) + (0x30C))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES4_CTRL_ADDR(base) ((base) + (0x310))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES5_CTRL_ADDR(base) ((base) + (0x314))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES6_CTRL_ADDR(base) ((base) + (0x318))
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES7_CTRL_ADDR(base) ((base) + (0x31C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_rffe_ctrl_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_CTRL_EN_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_CTRL_EN_cpu_rffe_ctrl_en_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_CTRL_EN_cpu_rffe_ctrl_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_rffe_seq0_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 28;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_SEQ_EN_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_SEQ_EN_cpu_rffe_seq0_en_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_SEQ_EN_cpu_rffe_seq0_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi0_rffe_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 4;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 20;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_EN_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_EN_cpu_mipi0_rffe_en_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_EN_cpu_mipi0_rffe_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi_seq0_read_cmd_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 28;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_READ_CMD_EN_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_READ_CMD_EN_cpu_mipi_seq0_read_cmd_en_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_READ_CMD_EN_cpu_mipi_seq0_read_cmd_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int cpu_mipi_dbg_ckg_bypass : 1;
        unsigned int cpu_rb_rpt_ckg_bypass : 1;
        unsigned int cpu_mipi_cb_ckg_bypass : 1;
        unsigned int cpu_mipi0_sync_ckg_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 10;
        unsigned int reserved_8 : 11;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_MIPI_CKG_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_MIPI_CKG_cpu_mipi_dbg_ckg_bypass_START (1)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_MIPI_CKG_cpu_mipi_dbg_ckg_bypass_END (1)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_MIPI_CKG_cpu_rb_rpt_ckg_bypass_START (2)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_MIPI_CKG_cpu_rb_rpt_ckg_bypass_END (2)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_MIPI_CKG_cpu_mipi_cb_ckg_bypass_START (3)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_MIPI_CKG_cpu_mipi_cb_ckg_bypass_END (3)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_MIPI_CKG_cpu_mipi0_sync_ckg_bypass_START (4)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_MIPI_CKG_cpu_mipi0_sync_ckg_bypass_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_ckg_wait_num : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_CKG_WAIT_NUM_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_CKG_WAIT_NUM_cpu_ckg_wait_num_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_CKG_WAIT_NUM_cpu_ckg_wait_num_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi0_rffe_mst_sdata_oen_val : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 25;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_SDATA_OEN_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_SDATA_OEN_mipi0_rffe_mst_sdata_oen_val_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_SDATA_OEN_mipi0_rffe_mst_sdata_oen_val_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi0_rffe_dbg_ctrl : 10;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_CTRL0_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_CTRL0_cpu_mipi0_rffe_dbg_ctrl_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_CTRL0_cpu_mipi0_rffe_dbg_ctrl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi0_rffe_quart_spd_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 25;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_QUART_SPD_EN_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_QUART_SPD_EN_cpu_mipi0_rffe_quart_spd_en_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_QUART_SPD_EN_cpu_mipi0_rffe_quart_spd_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi0_rffe_st_rpt_cpu : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 3;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 3;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 3;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 3;
        unsigned int reserved_12 : 5;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_ST_RPT_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_ST_RPT_mipi0_rffe_st_rpt_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_ST_RPT_mipi0_rffe_st_rpt_cpu_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int seq0_mipi_cmd_err_rpt_cpu : 32;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_SEQ0_MIPI_CMD_ERR_RPT_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_SEQ0_MIPI_CMD_ERR_RPT_seq0_mipi_cmd_err_rpt_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_SEQ0_MIPI_CMD_ERR_RPT_seq0_mipi_cmd_err_rpt_cpu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int all_mipi_idle_rpt_cpu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_ALL_MIPI_IDLE_RPT_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_ALL_MIPI_IDLE_RPT_all_mipi_idle_rpt_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_ALL_MIPI_IDLE_RPT_all_mipi_idle_rpt_cpu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_rd_end_flag_cpu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_END_FLAG_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_END_FLAG_mipi_rd_end_flag_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_END_FLAG_mipi_rd_end_flag_cpu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi_rd_end_flag_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_END_FLAG_CLR_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_END_FLAG_CLR_cpu_mipi_rd_end_flag_clr_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_END_FLAG_CLR_cpu_mipi_rd_end_flag_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int master0_fifo_pre_full : 3;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 3;
        unsigned int reserved_5 : 3;
        unsigned int reserved_6 : 11;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_FIFO_STATUS_0_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_FIFO_STATUS_0_master0_fifo_pre_full_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_FIFO_STATUS_0_master0_fifo_pre_full_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int master0_fifo_empty : 3;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 3;
        unsigned int reserved_5 : 3;
        unsigned int reserved_6 : 11;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_FIFO_STATUS_1_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_FIFO_STATUS_1_master0_fifo_empty_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_FIFO_STATUS_1_master0_fifo_empty_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_rd_data0_cpu : 32;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_DATA0_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_DATA0_mipi_rd_data0_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_DATA0_mipi_rd_data0_cpu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_rd_data1_cpu : 32;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_DATA1_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_DATA1_mipi_rd_data1_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RD_DATA1_mipi_rd_data1_cpu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_fifo0_pri1_depth : 4;
        unsigned int reserved_0 : 4;
        unsigned int cpu_fifo0_pri2_depth : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_DEPTH_CFG_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_DEPTH_CFG_cpu_fifo0_pri1_depth_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_DEPTH_CFG_cpu_fifo0_pri1_depth_END (3)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_DEPTH_CFG_cpu_fifo0_pri2_depth_START (8)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_DEPTH_CFG_cpu_fifo0_pri2_depth_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi0_div_num : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_CLK_DIV_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_CLK_DIV_cpu_mipi0_div_num_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_CLK_DIV_cpu_mipi0_div_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rffe_mipi_rst_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_EN_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_EN_rffe_mipi_rst_en_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_EN_rffe_mipi_rst_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rffe_mipi_rst_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_DIS_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_DIS_rffe_mipi_rst_dis_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_DIS_rffe_mipi_rst_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rffe_mipi_rst_sta : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_STA_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_STA_rffe_mipi_rst_sta_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_RST_STA_rffe_mipi_rst_sta_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi_ckg_en_req_ind : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_CKG_EN_IND_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_CKG_EN_IND_cpu_mipi_ckg_en_req_ind_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_CKG_EN_IND_cpu_mipi_ckg_en_req_ind_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi_mst_disable_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_EN_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_EN_cpu_mipi_mst_disable_en_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_EN_cpu_mipi_mst_disable_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi_mst_disable_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_DIS_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_DIS_cpu_mipi_mst_disable_dis_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_DIS_cpu_mipi_mst_disable_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi_mst_disable_sta : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_STA_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_STA_cpu_mipi_mst_disable_sta_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_DISABLE_STA_cpu_mipi_mst_disable_sta_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi0_fifo_base_addr : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_BASE_ADDR_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_BASE_ADDR_cpu_mipi0_fifo_base_addr_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_FIFO_BASE_ADDR_cpu_mipi0_fifo_base_addr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_seq0_pri : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 28;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_SEQ_PRI_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_SEQ_PRI_cpu_seq0_pri_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_SEQ_PRI_cpu_seq0_pri_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi0_pri : 3;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 3;
        unsigned int reserved_5 : 3;
        unsigned int reserved_6 : 11;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_CFG_PRI_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_CFG_PRI_cpu_mipi0_pri_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_CFG_PRI_cpu_mipi0_pri_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi_master_int_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_MASK_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_MASK_cpu_mipi_master_int_mask_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_MASK_cpu_mipi_master_int_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi_master_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_CLR_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_CLR_cpu_mipi_master_int_clr_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_CLR_cpu_mipi_master_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_master_int_raw_cpu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_RAW_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_RAW_mipi_master_int_raw_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_RAW_mipi_master_int_raw_cpu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_master_int_sta_cpu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_STA_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_STA_mipi_master_int_sta_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_INT_STA_mipi_master_int_sta_cpu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_dbg_int_mask : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_MASK_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_MASK_cpu_dbg_int_mask_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_MASK_cpu_dbg_int_mask_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_dbg_int_clr : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_CLR_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_CLR_cpu_dbg_int_clr_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_CLR_cpu_dbg_int_clr_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_int_raw_cpu : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_RAW_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_RAW_dbg_int_raw_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_RAW_dbg_int_raw_cpu_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_int_sta_cpu : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_STA_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_STA_dbg_int_sta_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_DBG_INT_STA_dbg_int_sta_cpu_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_multi_mst_int_mask : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_MASK_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_MASK_cpu_multi_mst_int_mask_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_MASK_cpu_multi_mst_int_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_multi_mst_int_clr : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_CLR_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_CLR_cpu_multi_mst_int_clr_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_CLR_cpu_multi_mst_int_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int multi_mst_int_raw_cpu : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_RAW_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_RAW_multi_mst_int_raw_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_RAW_multi_mst_int_raw_cpu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int multi_mst_int_sta_cpu : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_STA_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_STA_multi_mst_int_sta_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MULTI_MST_INT_STA_multi_mst_int_sta_cpu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi_fifo_int_mask : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_MASK_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_MASK_cpu_mipi_fifo_int_mask_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_MASK_cpu_mipi_fifo_int_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi_fifo_int_clr : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_CLR_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_CLR_cpu_mipi_fifo_int_clr_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_CLR_cpu_mipi_fifo_int_clr_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_fifo_int_raw_cpu : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_RAW_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_RAW_mipi_fifo_int_raw_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_INT_RAW_mipi_fifo_int_raw_cpu_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_fifo_int_sta_cpu : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFOT_INT_STA_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFOT_INT_STA_mipi_fifo_int_sta_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFOT_INT_STA_mipi_fifo_int_sta_cpu_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi_int_ckg_bp : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 28;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_INT_CKG_BYPASS_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_INT_CKG_BYPASS_cpu_mipi_int_ckg_bp_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_INT_CKG_BYPASS_cpu_mipi_int_ckg_bp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi0_abnormal_pri_bit_index_rpt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_ABNORMAL_PRI_BIT_IDX_RPT_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_ABNORMAL_PRI_BIT_IDX_RPT_mipi0_abnormal_pri_bit_index_rpt_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_ABNORMAL_PRI_BIT_IDX_RPT_mipi0_abnormal_pri_bit_index_rpt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_ch_busy_rpt : 1;
        unsigned int reserved_0 : 6;
        unsigned int rffe_mipi_busy_rpt : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_BUSY_RPT_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_BUSY_RPT_mipi_ch_busy_rpt_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_BUSY_RPT_mipi_ch_busy_rpt_END (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_BUSY_RPT_rffe_mipi_busy_rpt_START (7)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RFFE_MIPI_BUSY_RPT_rffe_mipi_busy_rpt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_mst_disable_st_rpt_cpu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_DISABLE_ST_RPT_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_DISABLE_ST_RPT_mipi_mst_disable_st_rpt_cpu_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_MST_DISABLE_ST_RPT_mipi_mst_disable_st_rpt_cpu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi0_rffe_mst_sclk_oen_val : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 25;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_SCLK_OEN_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_SCLK_OEN_mipi0_rffe_mst_sclk_oen_val_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_RFFE_SCLK_OEN_mipi0_rffe_mst_sclk_oen_val_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mipi0_pri_bit_ram_baddr : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_PRI_BIT_RAM_BADDR_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_PRI_BIT_RAM_BADDR_cpu_mipi0_pri_bit_ram_baddr_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI0_PRI_BIT_RAM_BADDR_cpu_mipi0_pri_bit_ram_baddr_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri_bit_ram_cfg_err_rpt : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_PRI_BIT_RAM_CFG_ERR_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_PRI_BIT_RAM_CFG_ERR_pri_bit_ram_cfg_err_rpt_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_PRI_BIT_RAM_CFG_ERR_pri_bit_ram_cfg_err_rpt_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_fifo_cfg_err_rpt : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_CFG_ERR_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_CFG_ERR_mipi_fifo_cfg_err_rpt_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_MIPI_FIFO_CFG_ERR_mipi_fifo_cfg_err_rpt_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_res0 : 32;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RES0_CTRL_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES0_CTRL_mipi_res0_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES0_CTRL_mipi_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_res1 : 32;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RES1_CTRL_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES1_CTRL_mipi_res1_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES1_CTRL_mipi_res1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_res2 : 32;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RES2_CTRL_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES2_CTRL_mipi_res2_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES2_CTRL_mipi_res2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_res3 : 32;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RES3_CTRL_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES3_CTRL_mipi_res3_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES3_CTRL_mipi_res3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_res4 : 32;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RES4_CTRL_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES4_CTRL_mipi_res4_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES4_CTRL_mipi_res4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_res5 : 32;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RES5_CTRL_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES5_CTRL_mipi_res5_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES5_CTRL_mipi_res5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_res6 : 32;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RES6_CTRL_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES6_CTRL_mipi_res6_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES6_CTRL_mipi_res6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mipi_res7 : 32;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_IMI_RES7_CTRL_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES7_CTRL_mipi_res7_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_IMI_RES7_CTRL_mipi_res7_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
