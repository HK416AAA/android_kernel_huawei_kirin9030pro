#ifndef __SOC_DDR_BPG_INTERFACE_H__
#define __SOC_DDR_BPG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_BPG_BPG_CTRL_ADDR(base) ((base) + (0x0000UL))
#define SOC_DDR_BPG_BPG_CMD_DYN_ADDR(base) ((base) + (0x0004UL))
#define SOC_DDR_BPG_BPG_CMD_STA_ADDR(base) ((base) + (0x0008UL))
#define SOC_DDR_BPG_BPG_REG_SETS_ADDR(base) ((base) + (0x000CUL))
#define SOC_DDR_BPG_TIMING_CMD1_ADDR(base) ((base) + (0x0010UL))
#define SOC_DDR_BPG_TIMING_CMD2_ADDR(base) ((base) + (0x0014UL))
#define SOC_DDR_BPG_BPG_CMD_STA2_ADDR(base) ((base) + (0x0018UL))
#define SOC_DDR_BPG_DFI_CTRL_ADDR(base) ((base) + (0x001CUL))
#define SOC_DDR_BPG_BPG_CFIFO_CFG_ADDR(base) ((base) + (0x0020UL))
#define SOC_DDR_BPG_BPG_CFIFO_INT_ADDR(base) ((base) + (0x0024UL))
#define SOC_DDR_BPG_CFIFO_STAT_CMD1_ADDR(base) ((base) + (0x0028UL))
#define SOC_DDR_BPG_CFIFO_STAT_CMD2_ADDR(base) ((base) + (0x002cUL))
#define SOC_DDR_BPG_RDATA_INT_CFG1_ADDR(base) ((base) + (0x0030UL))
#define SOC_DDR_BPG_RDATA_INT_CFG2_ADDR(base) ((base) + (0x0034UL))
#define SOC_DDR_BPG_RDATA_CONTRL_ADDR(base) ((base) + (0x0038UL))
#define SOC_DDR_BPG_RDATA_INT_ADDR(base) ((base) + (0x003cUL))
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG1_ADDR(base) ((base) + (0x0040UL))
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG2_ADDR(base) ((base) + (0x0044UL))
#define SOC_DDR_BPG_TICK_EN_ADDR(base) ((base) + (0x0048UL))
#define SOC_DDR_BPG_TIMING_CMD3_ADDR(base) ((base) + (0x004cUL))
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_ADDR(base) ((base) + (0x0050UL))
#define SOC_DDR_BPG_EDC_RDATA_PATTERN_MASK_ADDR(base) ((base) + (0x0060+0x4*EDC_PATTERN_MASK_NUM))
#define SOC_DDR_BPG_AMP_H_CFG_ADDR(base) ((base) + (0x0074UL))
#define SOC_DDR_BPG_PRBS0_CFG_ADDR(base) ((base) + (0x0800+0x4*POLY_GROUP))
#define SOC_DDR_BPG_PRBS1_CFG_ADDR(base) ((base) + (0x0900+0x4*POLY_GROUP))
#define SOC_DDR_BPG_PRBS7_SEED_ADDR(base) ((base) + (0x0078UL))
#define SOC_DDR_BPG_PRBS6_SEED_ADDR(base) ((base) + (0x007cUL))
#define SOC_DDR_BPG_PRBS5_SEED_ADDR(base) ((base) + (0x0080UL))
#define SOC_DDR_BPG_PRBS4_SEED_ADDR(base) ((base) + (0x0084UL))
#define SOC_DDR_BPG_PRBS3_SEED_ADDR(base) ((base) + (0x0088UL))
#define SOC_DDR_BPG_PRBS2_SEED_ADDR(base) ((base) + (0x008cUL))
#define SOC_DDR_BPG_PRBS0_SEED_ADDR(base) ((base) + (0x0090UL))
#define SOC_DDR_BPG_PRBS1_SEED_ADDR(base) ((base) + (0x0094UL))
#define SOC_DDR_BPG_AMP_L_CFG_ADDR(base) ((base) + (0x0098UL))
#define SOC_DDR_BPG_PRBS0_LAT_ADDR(base) ((base) + (0x009CUL))
#define SOC_DDR_BPG_RDATA_LAT_ADDR(base) ((base) + (0x0100+0x4*DFI_DATA_NUM))
#define SOC_DDR_BPG_RDATA_LAT_RESULT_ADDR(base) ((base) + (0x0180+0x4*DFI_DATA_NUM))
#define SOC_DDR_BPG_RDBI_LAT_ADDR(base) ((base) + (0x0700+0x4*DFI_DBI_NUM))
#define SOC_DDR_BPG_RDBI_LAT_RESULT_ADDR(base) ((base) + (0x0740+0x4*DFI_DBI_NUM))
#define SOC_DDR_BPG_PATTERN_CFG_DATA_ADDR(base) ((base) + (0x0200+0x4*PATTERN_CFG_DATA_NUM))
#define SOC_DDR_BPG_PATTERN_CFG_MASK_ADDR(base) ((base) + (0x0300+0x4*PATTERN_CFG_MASK_NUM))
#define SOC_DDR_BPG_RDATA_PATTERN_MASK_ADDR(base) ((base) + (0x0380+0x4*PATTERN_MASK_NUM))
#define SOC_DDR_BPG_RDBI_PATTERN_MASK_ADDR(base) ((base) + (0x0780+0x4*PATTERN_DBI_MASK_NUM))
#define SOC_DDR_BPG_PATTERN_AMP_BIT_ADDR(base) ((base) + (0x0400+0x4*AMP_BIT_NUM))
#define SOC_DDR_BPG_PATTERN_AMP_MASK_ADDR(base) ((base) + (0x0480+0x4*AMP_MASK_NUM))
#define SOC_DDR_BPG_PHY_CTRL0_ADDR(base) ((base) + (0x0500UL))
#define SOC_DDR_BPG_PHY_CTRL1_ADDR(base) ((base) + (0x0504UL))
#define SOC_DDR_BPG_PHY_CTRL2_ADDR(base) ((base) + (0x0508UL))
#define SOC_DDR_BPG_PHY_CTRL3_ADDR(base) ((base) + (0x050CUL))
#define SOC_DDR_BPG_PHY_CTRL4_ADDR(base) ((base) + (0x0510UL))
#define SOC_DDR_BPG_PHY_CTRL5_ADDR(base) ((base) + (0x0514UL))
#define SOC_DDR_BPG_PHY_CTRL6_ADDR(base) ((base) + (0x0518UL))
#define SOC_DDR_BPG_PHY_CTRL7_ADDR(base) ((base) + (0x051CUL))
#define SOC_DDR_BPG_PHY_CTRL8_ADDR(base) ((base) + (0x0520UL))
#define SOC_DDR_BPG_PHY_CTRL9_ADDR(base) ((base) + (0x0524UL))
#define SOC_DDR_BPG_PHY_STATUS0_ADDR(base) ((base) + (0x0580UL))
#define SOC_DDR_BPG_PHY_STATUS1_ADDR(base) ((base) + (0x0584UL))
#define SOC_DDR_BPG_PHY_INT_ADDR(base) ((base) + (0x05C0UL))
#define SOC_DDR_BPG_PHY_PULSE_CFG_ADDR(base) ((base) + (0x05D0UL))
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_ADDR(base) ((base) + (0x05D4UL))
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_ADDR(base) ((base) + (0x05D8UL))
#define SOC_DDR_BPG_SYS_INT_MASK_ADDR(base) ((base) + (0x05E0UL))
#define SOC_DDR_BPG_SYS_CTRL_ADDR(base) ((base) + (0x0600UL))
#define SOC_DDR_BPG_SYS_STATUS_ADDR(base) ((base) + (0x0604UL))
#define SOC_DDR_BPG_IRAM_CFG_ADDR(base) ((base) + (0x0608UL))
#define SOC_DDR_BPG_DRAM_CFG_ADDR(base) ((base) + (0x060CUL))
#define SOC_DDR_BPG_SYS_CLOCK_DIS_ADDR(base) ((base) + (0x0610UL))
#define SOC_DDR_BPG_RDATA_CNT_ADDR(base) ((base) + (0x061CUL))
#define SOC_DDR_BPG_TIMER0_ADDR(base) ((base) + (0x0620UL))
#define SOC_DDR_BPG_TIMER0_CFG_ADDR(base) ((base) + (0x0624UL))
#define SOC_DDR_BPG_TIMER1_ADDR(base) ((base) + (0x0628UL))
#define SOC_DDR_BPG_TIMER1_CFG_ADDR(base) ((base) + (0x062CUL))
#define SOC_DDR_BPG_TIMER2_ADDR(base) ((base) + (0x0630UL))
#define SOC_DDR_BPG_TIMER2_CFG_ADDR(base) ((base) + (0x0634UL))
#define SOC_DDR_BPG_TIMER3_ADDR(base) ((base) + (0x0638UL))
#define SOC_DDR_BPG_TIMER3_CFG_ADDR(base) ((base) + (0x063CUL))
#define SOC_DDR_BPG_DMC_PBUF_ADDR(base) ((base) + (0x8000+£¨£¨0x04*£¨PBUF_DEPTH£©£©*PBUF_DATA_MWIDTH£©+0x04*£¨PBUF_DEPTH£©))
#define SOC_DDR_BPG_DMC_PBUF_EDC_ADDR(base) ((base) + (0xC000+£¨0x80*PBUF_DATA_MWIDTH£©+0x04*£¨PBUF_DEPTH£©))
#else
#define SOC_DDR_BPG_BPG_CTRL_ADDR(base) ((base) + (0x0000))
#define SOC_DDR_BPG_BPG_CMD_DYN_ADDR(base) ((base) + (0x0004))
#define SOC_DDR_BPG_BPG_CMD_STA_ADDR(base) ((base) + (0x0008))
#define SOC_DDR_BPG_BPG_REG_SETS_ADDR(base) ((base) + (0x000C))
#define SOC_DDR_BPG_TIMING_CMD1_ADDR(base) ((base) + (0x0010))
#define SOC_DDR_BPG_TIMING_CMD2_ADDR(base) ((base) + (0x0014))
#define SOC_DDR_BPG_BPG_CMD_STA2_ADDR(base) ((base) + (0x0018))
#define SOC_DDR_BPG_DFI_CTRL_ADDR(base) ((base) + (0x001C))
#define SOC_DDR_BPG_BPG_CFIFO_CFG_ADDR(base) ((base) + (0x0020))
#define SOC_DDR_BPG_BPG_CFIFO_INT_ADDR(base) ((base) + (0x0024))
#define SOC_DDR_BPG_CFIFO_STAT_CMD1_ADDR(base) ((base) + (0x0028))
#define SOC_DDR_BPG_CFIFO_STAT_CMD2_ADDR(base) ((base) + (0x002c))
#define SOC_DDR_BPG_RDATA_INT_CFG1_ADDR(base) ((base) + (0x0030))
#define SOC_DDR_BPG_RDATA_INT_CFG2_ADDR(base) ((base) + (0x0034))
#define SOC_DDR_BPG_RDATA_CONTRL_ADDR(base) ((base) + (0x0038))
#define SOC_DDR_BPG_RDATA_INT_ADDR(base) ((base) + (0x003c))
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG1_ADDR(base) ((base) + (0x0040))
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG2_ADDR(base) ((base) + (0x0044))
#define SOC_DDR_BPG_TICK_EN_ADDR(base) ((base) + (0x0048))
#define SOC_DDR_BPG_TIMING_CMD3_ADDR(base) ((base) + (0x004c))
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_ADDR(base) ((base) + (0x0050))
#define SOC_DDR_BPG_EDC_RDATA_PATTERN_MASK_ADDR(base) ((base) + (0x0060+0x4*EDC_PATTERN_MASK_NUM))
#define SOC_DDR_BPG_AMP_H_CFG_ADDR(base) ((base) + (0x0074))
#define SOC_DDR_BPG_PRBS0_CFG_ADDR(base) ((base) + (0x0800+0x4*POLY_GROUP))
#define SOC_DDR_BPG_PRBS1_CFG_ADDR(base) ((base) + (0x0900+0x4*POLY_GROUP))
#define SOC_DDR_BPG_PRBS7_SEED_ADDR(base) ((base) + (0x0078))
#define SOC_DDR_BPG_PRBS6_SEED_ADDR(base) ((base) + (0x007c))
#define SOC_DDR_BPG_PRBS5_SEED_ADDR(base) ((base) + (0x0080))
#define SOC_DDR_BPG_PRBS4_SEED_ADDR(base) ((base) + (0x0084))
#define SOC_DDR_BPG_PRBS3_SEED_ADDR(base) ((base) + (0x0088))
#define SOC_DDR_BPG_PRBS2_SEED_ADDR(base) ((base) + (0x008c))
#define SOC_DDR_BPG_PRBS0_SEED_ADDR(base) ((base) + (0x0090))
#define SOC_DDR_BPG_PRBS1_SEED_ADDR(base) ((base) + (0x0094))
#define SOC_DDR_BPG_AMP_L_CFG_ADDR(base) ((base) + (0x0098))
#define SOC_DDR_BPG_PRBS0_LAT_ADDR(base) ((base) + (0x009C))
#define SOC_DDR_BPG_RDATA_LAT_ADDR(base) ((base) + (0x0100+0x4*DFI_DATA_NUM))
#define SOC_DDR_BPG_RDATA_LAT_RESULT_ADDR(base) ((base) + (0x0180+0x4*DFI_DATA_NUM))
#define SOC_DDR_BPG_RDBI_LAT_ADDR(base) ((base) + (0x0700+0x4*DFI_DBI_NUM))
#define SOC_DDR_BPG_RDBI_LAT_RESULT_ADDR(base) ((base) + (0x0740+0x4*DFI_DBI_NUM))
#define SOC_DDR_BPG_PATTERN_CFG_DATA_ADDR(base) ((base) + (0x0200+0x4*PATTERN_CFG_DATA_NUM))
#define SOC_DDR_BPG_PATTERN_CFG_MASK_ADDR(base) ((base) + (0x0300+0x4*PATTERN_CFG_MASK_NUM))
#define SOC_DDR_BPG_RDATA_PATTERN_MASK_ADDR(base) ((base) + (0x0380+0x4*PATTERN_MASK_NUM))
#define SOC_DDR_BPG_RDBI_PATTERN_MASK_ADDR(base) ((base) + (0x0780+0x4*PATTERN_DBI_MASK_NUM))
#define SOC_DDR_BPG_PATTERN_AMP_BIT_ADDR(base) ((base) + (0x0400+0x4*AMP_BIT_NUM))
#define SOC_DDR_BPG_PATTERN_AMP_MASK_ADDR(base) ((base) + (0x0480+0x4*AMP_MASK_NUM))
#define SOC_DDR_BPG_PHY_CTRL0_ADDR(base) ((base) + (0x0500))
#define SOC_DDR_BPG_PHY_CTRL1_ADDR(base) ((base) + (0x0504))
#define SOC_DDR_BPG_PHY_CTRL2_ADDR(base) ((base) + (0x0508))
#define SOC_DDR_BPG_PHY_CTRL3_ADDR(base) ((base) + (0x050C))
#define SOC_DDR_BPG_PHY_CTRL4_ADDR(base) ((base) + (0x0510))
#define SOC_DDR_BPG_PHY_CTRL5_ADDR(base) ((base) + (0x0514))
#define SOC_DDR_BPG_PHY_CTRL6_ADDR(base) ((base) + (0x0518))
#define SOC_DDR_BPG_PHY_CTRL7_ADDR(base) ((base) + (0x051C))
#define SOC_DDR_BPG_PHY_CTRL8_ADDR(base) ((base) + (0x0520))
#define SOC_DDR_BPG_PHY_CTRL9_ADDR(base) ((base) + (0x0524))
#define SOC_DDR_BPG_PHY_STATUS0_ADDR(base) ((base) + (0x0580))
#define SOC_DDR_BPG_PHY_STATUS1_ADDR(base) ((base) + (0x0584))
#define SOC_DDR_BPG_PHY_INT_ADDR(base) ((base) + (0x05C0))
#define SOC_DDR_BPG_PHY_PULSE_CFG_ADDR(base) ((base) + (0x05D0))
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_ADDR(base) ((base) + (0x05D4))
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_ADDR(base) ((base) + (0x05D8))
#define SOC_DDR_BPG_SYS_INT_MASK_ADDR(base) ((base) + (0x05E0))
#define SOC_DDR_BPG_SYS_CTRL_ADDR(base) ((base) + (0x0600))
#define SOC_DDR_BPG_SYS_STATUS_ADDR(base) ((base) + (0x0604))
#define SOC_DDR_BPG_IRAM_CFG_ADDR(base) ((base) + (0x0608))
#define SOC_DDR_BPG_DRAM_CFG_ADDR(base) ((base) + (0x060C))
#define SOC_DDR_BPG_SYS_CLOCK_DIS_ADDR(base) ((base) + (0x0610))
#define SOC_DDR_BPG_RDATA_CNT_ADDR(base) ((base) + (0x061C))
#define SOC_DDR_BPG_TIMER0_ADDR(base) ((base) + (0x0620))
#define SOC_DDR_BPG_TIMER0_CFG_ADDR(base) ((base) + (0x0624))
#define SOC_DDR_BPG_TIMER1_ADDR(base) ((base) + (0x0628))
#define SOC_DDR_BPG_TIMER1_CFG_ADDR(base) ((base) + (0x062C))
#define SOC_DDR_BPG_TIMER2_ADDR(base) ((base) + (0x0630))
#define SOC_DDR_BPG_TIMER2_CFG_ADDR(base) ((base) + (0x0634))
#define SOC_DDR_BPG_TIMER3_ADDR(base) ((base) + (0x0638))
#define SOC_DDR_BPG_TIMER3_CFG_ADDR(base) ((base) + (0x063C))
#define SOC_DDR_BPG_DMC_PBUF_ADDR(base) ((base) + (0x8000+£¨£¨0x04*£¨PBUF_DEPTH£©£©*PBUF_DATA_MWIDTH£©+0x04*£¨PBUF_DEPTH£©))
#define SOC_DDR_BPG_DMC_PBUF_EDC_ADDR(base) ((base) + (0xC000+£¨0x80*PBUF_DATA_MWIDTH£©+0x04*£¨PBUF_DEPTH£©))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfifo_start : 1;
        unsigned int cfifo_wptr_clr : 1;
        unsigned int cfifo_reg_sets_wptr_clr : 1;
        unsigned int cfifo_reg_sets_wptr_fix : 1;
        unsigned int cfifo_wptr_fix : 1;
        unsigned int reserved_0 : 3;
        unsigned int cfifo_reg_sets_wptr_f : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_DDR_BPG_BPG_CTRL_UNION;
#endif
#define SOC_DDR_BPG_BPG_CTRL_cfifo_start_START (0)
#define SOC_DDR_BPG_BPG_CTRL_cfifo_start_END (0)
#define SOC_DDR_BPG_BPG_CTRL_cfifo_wptr_clr_START (1)
#define SOC_DDR_BPG_BPG_CTRL_cfifo_wptr_clr_END (1)
#define SOC_DDR_BPG_BPG_CTRL_cfifo_reg_sets_wptr_clr_START (2)
#define SOC_DDR_BPG_BPG_CTRL_cfifo_reg_sets_wptr_clr_END (2)
#define SOC_DDR_BPG_BPG_CTRL_cfifo_reg_sets_wptr_fix_START (3)
#define SOC_DDR_BPG_BPG_CTRL_cfifo_reg_sets_wptr_fix_END (3)
#define SOC_DDR_BPG_BPG_CTRL_cfifo_wptr_fix_START (4)
#define SOC_DDR_BPG_BPG_CTRL_cfifo_wptr_fix_END (4)
#define SOC_DDR_BPG_BPG_CTRL_cfifo_reg_sets_wptr_f_START (8)
#define SOC_DDR_BPG_BPG_CTRL_cfifo_reg_sets_wptr_f_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_type : 2;
        unsigned int payload : 7;
        unsigned int r_index : 2;
        unsigned int rsvd : 1;
        unsigned int j_offset : 4;
        unsigned int a_bit : 1;
        unsigned int j_bit : 1;
        unsigned int cs0145_cid0 : 4;
        unsigned int odt : 4;
        unsigned int ac_tim_width : 6;
    } reg;
} SOC_DDR_BPG_BPG_CMD_DYN_UNION;
#endif
#define SOC_DDR_BPG_BPG_CMD_DYN_cmd_type_START (0)
#define SOC_DDR_BPG_BPG_CMD_DYN_cmd_type_END (1)
#define SOC_DDR_BPG_BPG_CMD_DYN_payload_START (2)
#define SOC_DDR_BPG_BPG_CMD_DYN_payload_END (8)
#define SOC_DDR_BPG_BPG_CMD_DYN_r_index_START (9)
#define SOC_DDR_BPG_BPG_CMD_DYN_r_index_END (10)
#define SOC_DDR_BPG_BPG_CMD_DYN_rsvd_START (11)
#define SOC_DDR_BPG_BPG_CMD_DYN_rsvd_END (11)
#define SOC_DDR_BPG_BPG_CMD_DYN_j_offset_START (12)
#define SOC_DDR_BPG_BPG_CMD_DYN_j_offset_END (15)
#define SOC_DDR_BPG_BPG_CMD_DYN_a_bit_START (16)
#define SOC_DDR_BPG_BPG_CMD_DYN_a_bit_END (16)
#define SOC_DDR_BPG_BPG_CMD_DYN_j_bit_START (17)
#define SOC_DDR_BPG_BPG_CMD_DYN_j_bit_END (17)
#define SOC_DDR_BPG_BPG_CMD_DYN_cs0145_cid0_START (18)
#define SOC_DDR_BPG_BPG_CMD_DYN_cs0145_cid0_END (21)
#define SOC_DDR_BPG_BPG_CMD_DYN_odt_START (22)
#define SOC_DDR_BPG_BPG_CMD_DYN_odt_END (25)
#define SOC_DDR_BPG_BPG_CMD_DYN_ac_tim_width_START (26)
#define SOC_DDR_BPG_BPG_CMD_DYN_ac_tim_width_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_sta_rodt_w : 2;
        unsigned int ac_sta_dfi_wodt_w : 2;
        unsigned int ac_sta_dfi_rddata_en_w : 2;
        unsigned int ac_sta_dfi_wrdata_en_w : 2;
        unsigned int ac_sta_csremap : 1;
        unsigned int ac_sta_cmdmode : 1;
        unsigned int ac_sta_rst : 1;
        unsigned int ac_sta_pardly : 1;
        unsigned int ac_sta_parcfg : 1;
        unsigned int ac_sta_cspol : 1;
        unsigned int ac_sta_cmd2t : 1;
        unsigned int ac_sta_acprbs : 1;
        unsigned int ac_sta_csprbs : 1;
        unsigned int ac_sta_mode : 3;
        unsigned int ac_sta_edcen : 1;
        unsigned int ac_sta_wdbien : 1;
        unsigned int ac_sta_rdbien : 1;
        unsigned int ac_sta_adbied : 1;
        unsigned int ac_sta_halfdly : 1;
        unsigned int ac_sta_crcmode : 1;
        unsigned int ac_sta_crcstore : 1;
        unsigned int ac_sta_wcken : 1;
        unsigned int ac_sta_rdatbuf_mode : 1;
        unsigned int ac_sta_edcbuf_mode : 1;
        unsigned int ac_sta_single_pw : 1;
        unsigned int ac_sta_lpddrx_split : 1;
    } reg;
} SOC_DDR_BPG_BPG_CMD_STA_UNION;
#endif
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_rodt_w_START (0)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_rodt_w_END (1)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_dfi_wodt_w_START (2)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_dfi_wodt_w_END (3)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_dfi_rddata_en_w_START (4)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_dfi_rddata_en_w_END (5)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_dfi_wrdata_en_w_START (6)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_dfi_wrdata_en_w_END (7)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_csremap_START (8)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_csremap_END (8)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_cmdmode_START (9)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_cmdmode_END (9)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_rst_START (10)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_rst_END (10)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_pardly_START (11)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_pardly_END (11)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_parcfg_START (12)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_parcfg_END (12)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_cspol_START (13)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_cspol_END (13)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_cmd2t_START (14)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_cmd2t_END (14)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_acprbs_START (15)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_acprbs_END (15)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_csprbs_START (16)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_csprbs_END (16)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_mode_START (17)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_mode_END (19)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_edcen_START (20)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_edcen_END (20)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_wdbien_START (21)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_wdbien_END (21)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_rdbien_START (22)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_rdbien_END (22)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_adbied_START (23)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_adbied_END (23)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_halfdly_START (24)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_halfdly_END (24)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_crcmode_START (25)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_crcmode_END (25)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_crcstore_START (26)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_crcstore_END (26)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_wcken_START (27)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_wcken_END (27)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_rdatbuf_mode_START (28)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_rdatbuf_mode_END (28)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_edcbuf_mode_START (29)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_edcbuf_mode_END (29)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_single_pw_START (30)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_single_pw_END (30)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_lpddrx_split_START (31)
#define SOC_DDR_BPG_BPG_CMD_STA_ac_sta_lpddrx_split_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfifo_reg_sets_h : 28;
        unsigned int cfifo_reg_sets_cs : 4;
    } reg;
} SOC_DDR_BPG_BPG_REG_SETS_UNION;
#endif
#define SOC_DDR_BPG_BPG_REG_SETS_cfifo_reg_sets_h_START (0)
#define SOC_DDR_BPG_BPG_REG_SETS_cfifo_reg_sets_h_END (27)
#define SOC_DDR_BPG_BPG_REG_SETS_cfifo_reg_sets_cs_START (28)
#define SOC_DDR_BPG_BPG_REG_SETS_cfifo_reg_sets_cs_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timing_cmd_rodt : 8;
        unsigned int timing_cmd_wodt : 8;
        unsigned int timing_cmd_ren : 8;
        unsigned int timing_cmd_wen : 8;
    } reg;
} SOC_DDR_BPG_TIMING_CMD1_UNION;
#endif
#define SOC_DDR_BPG_TIMING_CMD1_timing_cmd_rodt_START (0)
#define SOC_DDR_BPG_TIMING_CMD1_timing_cmd_rodt_END (7)
#define SOC_DDR_BPG_TIMING_CMD1_timing_cmd_wodt_START (8)
#define SOC_DDR_BPG_TIMING_CMD1_timing_cmd_wodt_END (15)
#define SOC_DDR_BPG_TIMING_CMD1_timing_cmd_ren_START (16)
#define SOC_DDR_BPG_TIMING_CMD1_timing_cmd_ren_END (23)
#define SOC_DDR_BPG_TIMING_CMD1_timing_cmd_wen_START (24)
#define SOC_DDR_BPG_TIMING_CMD1_timing_cmd_wen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timing_cmd_rcs : 8;
        unsigned int timing_cmd_wcs : 8;
        unsigned int timing_cmd_wdata : 8;
        unsigned int timing_wdata_valid : 4;
        unsigned int timing_rdata_valid : 4;
    } reg;
} SOC_DDR_BPG_TIMING_CMD2_UNION;
#endif
#define SOC_DDR_BPG_TIMING_CMD2_timing_cmd_rcs_START (0)
#define SOC_DDR_BPG_TIMING_CMD2_timing_cmd_rcs_END (7)
#define SOC_DDR_BPG_TIMING_CMD2_timing_cmd_wcs_START (8)
#define SOC_DDR_BPG_TIMING_CMD2_timing_cmd_wcs_END (15)
#define SOC_DDR_BPG_TIMING_CMD2_timing_cmd_wdata_START (16)
#define SOC_DDR_BPG_TIMING_CMD2_timing_cmd_wdata_END (23)
#define SOC_DDR_BPG_TIMING_CMD2_timing_wdata_valid_START (24)
#define SOC_DDR_BPG_TIMING_CMD2_timing_wdata_valid_END (27)
#define SOC_DDR_BPG_TIMING_CMD2_timing_rdata_valid_START (28)
#define SOC_DDR_BPG_TIMING_CMD2_timing_rdata_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_sta2_mode : 3;
        unsigned int ac_sta2_rdbi_pol : 1;
        unsigned int ac_sta2_wdbi_pol : 1;
        unsigned int ac_sta2_par_mode : 1;
        unsigned int ac_sta2_odtprbs : 1;
        unsigned int ac_sta2_multi_cs_mode : 1;
        unsigned int ac_sta2_qdr_mode : 1;
        unsigned int ac_sta2_mrdimm_mode : 1;
        unsigned int ac_sta2_split : 2;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_BPG_BPG_CMD_STA2_UNION;
#endif
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_mode_START (0)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_mode_END (2)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_rdbi_pol_START (3)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_rdbi_pol_END (3)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_wdbi_pol_START (4)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_wdbi_pol_END (4)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_par_mode_START (5)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_par_mode_END (5)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_odtprbs_START (6)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_odtprbs_END (6)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_multi_cs_mode_START (7)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_multi_cs_mode_END (7)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_qdr_mode_START (8)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_qdr_mode_END (8)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_mrdimm_mode_START (9)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_mrdimm_mode_END (9)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_split_START (10)
#define SOC_DDR_BPG_BPG_CMD_STA2_ac_sta2_split_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfi_ctrl_cmd_en : 1;
        unsigned int dfi_ctrl_phyupd : 1;
        unsigned int dfi_ctrl_pbuf_ren0 : 1;
        unsigned int dfi_ctrl_pbuf_ren1 : 1;
        unsigned int dfi_ctrl_time : 6;
        unsigned int dfi_ctrl_phyupd_type : 2;
        unsigned int dfi_ctrl_err_clr0 : 1;
        unsigned int dfi_ctrl_err_clr1 : 1;
        unsigned int dfi_ctrl_reserved_15_14 : 2;
        unsigned int dfi_ctrl_pbuf_ptr0 : 5;
        unsigned int dfi_ctrl_reserved_23_21 : 3;
        unsigned int dfi_ctrl_pbuf_ptr1 : 5;
        unsigned int dfi_ctrl_reserved_31_29 : 3;
    } reg;
} SOC_DDR_BPG_DFI_CTRL_UNION;
#endif
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_cmd_en_START (0)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_cmd_en_END (0)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_phyupd_START (1)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_phyupd_END (1)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_pbuf_ren0_START (2)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_pbuf_ren0_END (2)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_pbuf_ren1_START (3)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_pbuf_ren1_END (3)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_time_START (4)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_time_END (9)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_phyupd_type_START (10)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_phyupd_type_END (11)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_err_clr0_START (12)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_err_clr0_END (12)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_err_clr1_START (13)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_err_clr1_END (13)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_reserved_15_14_START (14)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_reserved_15_14_END (15)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_pbuf_ptr0_START (16)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_pbuf_ptr0_END (20)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_reserved_23_21_START (21)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_reserved_23_21_END (23)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_pbuf_ptr1_START (24)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_pbuf_ptr1_END (28)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_reserved_31_29_START (29)
#define SOC_DDR_BPG_DFI_CTRL_dfi_ctrl_reserved_31_29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfifo_alempty_th : 4;
        unsigned int reserved_0 : 4;
        unsigned int cfifo_cnt : 4;
        unsigned int reserved_1 : 18;
        unsigned int cfifo_alempty_hold_en : 1;
        unsigned int cfifo_alempty_int_en : 1;
    } reg;
} SOC_DDR_BPG_BPG_CFIFO_CFG_UNION;
#endif
#define SOC_DDR_BPG_BPG_CFIFO_CFG_cfifo_alempty_th_START (0)
#define SOC_DDR_BPG_BPG_CFIFO_CFG_cfifo_alempty_th_END (3)
#define SOC_DDR_BPG_BPG_CFIFO_CFG_cfifo_cnt_START (8)
#define SOC_DDR_BPG_BPG_CFIFO_CFG_cfifo_cnt_END (11)
#define SOC_DDR_BPG_BPG_CFIFO_CFG_cfifo_alempty_hold_en_START (30)
#define SOC_DDR_BPG_BPG_CFIFO_CFG_cfifo_alempty_hold_en_END (30)
#define SOC_DDR_BPG_BPG_CFIFO_CFG_cfifo_alempty_int_en_START (31)
#define SOC_DDR_BPG_BPG_CFIFO_CFG_cfifo_alempty_int_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfifo_alempty_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_BPG_BPG_CFIFO_INT_UNION;
#endif
#define SOC_DDR_BPG_BPG_CFIFO_INT_cfifo_alempty_int_START (0)
#define SOC_DDR_BPG_BPG_CFIFO_INT_cfifo_alempty_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfifo_stat_cmd_th : 31;
        unsigned int cfifo_stat_cmd_int_en : 1;
    } reg;
} SOC_DDR_BPG_CFIFO_STAT_CMD1_UNION;
#endif
#define SOC_DDR_BPG_CFIFO_STAT_CMD1_cfifo_stat_cmd_th_START (0)
#define SOC_DDR_BPG_CFIFO_STAT_CMD1_cfifo_stat_cmd_th_END (30)
#define SOC_DDR_BPG_CFIFO_STAT_CMD1_cfifo_stat_cmd_int_en_START (31)
#define SOC_DDR_BPG_CFIFO_STAT_CMD1_cfifo_stat_cmd_int_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfifo_stat_cmd : 31;
        unsigned int cfifo_stat_cmd_int : 1;
    } reg;
} SOC_DDR_BPG_CFIFO_STAT_CMD2_UNION;
#endif
#define SOC_DDR_BPG_CFIFO_STAT_CMD2_cfifo_stat_cmd_START (0)
#define SOC_DDR_BPG_CFIFO_STAT_CMD2_cfifo_stat_cmd_END (30)
#define SOC_DDR_BPG_CFIFO_STAT_CMD2_cfifo_stat_cmd_int_START (31)
#define SOC_DDR_BPG_CFIFO_STAT_CMD2_cfifo_stat_cmd_int_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_err_th : 31;
        unsigned int rdata_err_int_en : 1;
    } reg;
} SOC_DDR_BPG_RDATA_INT_CFG1_UNION;
#endif
#define SOC_DDR_BPG_RDATA_INT_CFG1_rdata_err_th_START (0)
#define SOC_DDR_BPG_RDATA_INT_CFG1_rdata_err_th_END (30)
#define SOC_DDR_BPG_RDATA_INT_CFG1_rdata_err_int_en_START (31)
#define SOC_DDR_BPG_RDATA_INT_CFG1_rdata_err_int_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_err_cnt : 31;
        unsigned int rdata_err_int : 1;
    } reg;
} SOC_DDR_BPG_RDATA_INT_CFG2_UNION;
#endif
#define SOC_DDR_BPG_RDATA_INT_CFG2_rdata_err_cnt_START (0)
#define SOC_DDR_BPG_RDATA_INT_CFG2_rdata_err_cnt_END (30)
#define SOC_DDR_BPG_RDATA_INT_CFG2_rdata_err_int_START (31)
#define SOC_DDR_BPG_RDATA_INT_CFG2_rdata_err_int_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_lat_idx : 16;
        unsigned int reserved : 4;
        unsigned int rdata_msk_preamble : 5;
        unsigned int rdata_pbuf_en : 1;
        unsigned int rdata_pass_through : 1;
        unsigned int rdata_lat_result_type : 1;
        unsigned int rdata_prbs_round_en : 1;
        unsigned int rdata_err_lat_lst : 1;
        unsigned int rdata_err_lat_fst : 1;
        unsigned int rdata_lat_index : 1;
    } reg;
} SOC_DDR_BPG_RDATA_CONTRL_UNION;
#endif
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_lat_idx_START (0)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_lat_idx_END (15)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_msk_preamble_START (20)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_msk_preamble_END (24)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_pbuf_en_START (25)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_pbuf_en_END (25)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_pass_through_START (26)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_pass_through_END (26)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_lat_result_type_START (27)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_lat_result_type_END (27)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_prbs_round_en_START (28)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_prbs_round_en_END (28)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_err_lat_lst_START (29)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_err_lat_lst_END (29)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_err_lat_fst_START (30)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_err_lat_fst_END (30)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_lat_index_START (31)
#define SOC_DDR_BPG_RDATA_CONTRL_rdata_lat_index_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_err_lat_lst_int : 1;
        unsigned int rdata_err_lat_fst_int : 1;
        unsigned int rdata_lat_index_int : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_BPG_RDATA_INT_UNION;
#endif
#define SOC_DDR_BPG_RDATA_INT_rdata_err_lat_lst_int_START (0)
#define SOC_DDR_BPG_RDATA_INT_rdata_err_lat_lst_int_END (0)
#define SOC_DDR_BPG_RDATA_INT_rdata_err_lat_fst_int_START (1)
#define SOC_DDR_BPG_RDATA_INT_rdata_err_lat_fst_int_END (1)
#define SOC_DDR_BPG_RDATA_INT_rdata_lat_index_int_START (2)
#define SOC_DDR_BPG_RDATA_INT_rdata_lat_index_int_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int edc_err_th : 31;
        unsigned int edc_err_int_en : 1;
    } reg;
} SOC_DDR_BPG_EDC_RDATA_INT_CFG1_UNION;
#endif
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG1_edc_err_th_START (0)
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG1_edc_err_th_END (30)
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG1_edc_err_int_en_START (31)
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG1_edc_err_int_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int edc_err_cnt : 31;
        unsigned int edc_err_int : 1;
    } reg;
} SOC_DDR_BPG_EDC_RDATA_INT_CFG2_UNION;
#endif
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG2_edc_err_cnt_START (0)
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG2_edc_err_cnt_END (30)
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG2_edc_err_int_START (31)
#define SOC_DDR_BPG_EDC_RDATA_INT_CFG2_edc_err_int_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bpg_ofreq_tick_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_BPG_TICK_EN_UNION;
#endif
#define SOC_DDR_BPG_TICK_EN_bpg_ofreq_tick_on_START (0)
#define SOC_DDR_BPG_TICK_EN_bpg_ofreq_tick_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timing_cmd_wck : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_BPG_TIMING_CMD3_UNION;
#endif
#define SOC_DDR_BPG_TIMING_CMD3_timing_cmd_wck_START (0)
#define SOC_DDR_BPG_TIMING_CMD3_timing_cmd_wck_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_data_window : 8;
        unsigned int rdata_mask_window_l : 8;
        unsigned int rdata_mask_window_h : 8;
        unsigned int rdata_mask_window_inv : 1;
        unsigned int rdata_mask_skip_en : 1;
        unsigned int rdata_mask_single_en : 1;
        unsigned int rdata_mask_window_reset : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_BPG_RDATA_MASK_WINDOW_UNION;
#endif
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_data_window_START (0)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_data_window_END (7)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_window_l_START (8)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_window_l_END (15)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_window_h_START (16)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_window_h_END (23)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_window_inv_START (24)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_window_inv_END (24)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_skip_en_START (25)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_skip_en_END (25)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_single_en_START (26)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_single_en_END (26)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_window_reset_START (27)
#define SOC_DDR_BPG_RDATA_MASK_WINDOW_rdata_mask_window_reset_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int edc_mask_bit : 32;
    } reg;
} SOC_DDR_BPG_EDC_RDATA_PATTERN_MASK_UNION;
#endif
#define SOC_DDR_BPG_EDC_RDATA_PATTERN_MASK_edc_mask_bit_START (0)
#define SOC_DDR_BPG_EDC_RDATA_PATTERN_MASK_edc_mask_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int amp_h_cfg : 32;
    } reg;
} SOC_DDR_BPG_AMP_H_CFG_UNION;
#endif
#define SOC_DDR_BPG_AMP_H_CFG_amp_h_cfg_START (0)
#define SOC_DDR_BPG_AMP_H_CFG_amp_h_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prbs0_poly : 32;
    } reg;
} SOC_DDR_BPG_PRBS0_CFG_UNION;
#endif
#define SOC_DDR_BPG_PRBS0_CFG_prbs0_poly_START (0)
#define SOC_DDR_BPG_PRBS0_CFG_prbs0_poly_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prbs1_poly : 32;
    } reg;
} SOC_DDR_BPG_PRBS1_CFG_UNION;
#endif
#define SOC_DDR_BPG_PRBS1_CFG_prbs1_poly_START (0)
#define SOC_DDR_BPG_PRBS1_CFG_prbs1_poly_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prbs7_seed : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_BPG_PRBS7_SEED_UNION;
#endif
#define SOC_DDR_BPG_PRBS7_SEED_prbs7_seed_START (0)
#define SOC_DDR_BPG_PRBS7_SEED_prbs7_seed_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prbs6_seed : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_BPG_PRBS6_SEED_UNION;
#endif
#define SOC_DDR_BPG_PRBS6_SEED_prbs6_seed_START (0)
#define SOC_DDR_BPG_PRBS6_SEED_prbs6_seed_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prbs5_seed : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_BPG_PRBS5_SEED_UNION;
#endif
#define SOC_DDR_BPG_PRBS5_SEED_prbs5_seed_START (0)
#define SOC_DDR_BPG_PRBS5_SEED_prbs5_seed_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prbs4_seed : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_BPG_PRBS4_SEED_UNION;
#endif
#define SOC_DDR_BPG_PRBS4_SEED_prbs4_seed_START (0)
#define SOC_DDR_BPG_PRBS4_SEED_prbs4_seed_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prbs3_seed : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_BPG_PRBS3_SEED_UNION;
#endif
#define SOC_DDR_BPG_PRBS3_SEED_prbs3_seed_START (0)
#define SOC_DDR_BPG_PRBS3_SEED_prbs3_seed_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prbs2_seed : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_BPG_PRBS2_SEED_UNION;
#endif
#define SOC_DDR_BPG_PRBS2_SEED_prbs2_seed_START (0)
#define SOC_DDR_BPG_PRBS2_SEED_prbs2_seed_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prbs0_seed : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_BPG_PRBS0_SEED_UNION;
#endif
#define SOC_DDR_BPG_PRBS0_SEED_prbs0_seed_START (0)
#define SOC_DDR_BPG_PRBS0_SEED_prbs0_seed_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prbs1_seed : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_BPG_PRBS1_SEED_UNION;
#endif
#define SOC_DDR_BPG_PRBS1_SEED_prbs1_seed_START (0)
#define SOC_DDR_BPG_PRBS1_SEED_prbs1_seed_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int amp_l_cfg : 32;
    } reg;
} SOC_DDR_BPG_AMP_L_CFG_UNION;
#endif
#define SOC_DDR_BPG_AMP_L_CFG_amp_l_cfg_START (0)
#define SOC_DDR_BPG_AMP_L_CFG_amp_l_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prbs0_lat : 32;
    } reg;
} SOC_DDR_BPG_PRBS0_LAT_UNION;
#endif
#define SOC_DDR_BPG_PRBS0_LAT_prbs0_lat_START (0)
#define SOC_DDR_BPG_PRBS0_LAT_prbs0_lat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_lat : 32;
    } reg;
} SOC_DDR_BPG_RDATA_LAT_UNION;
#endif
#define SOC_DDR_BPG_RDATA_LAT_rdata_lat_START (0)
#define SOC_DDR_BPG_RDATA_LAT_rdata_lat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_lat_result : 32;
    } reg;
} SOC_DDR_BPG_RDATA_LAT_RESULT_UNION;
#endif
#define SOC_DDR_BPG_RDATA_LAT_RESULT_rdata_lat_result_START (0)
#define SOC_DDR_BPG_RDATA_LAT_RESULT_rdata_lat_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdbi_lat : 32;
    } reg;
} SOC_DDR_BPG_RDBI_LAT_UNION;
#endif
#define SOC_DDR_BPG_RDBI_LAT_rdbi_lat_START (0)
#define SOC_DDR_BPG_RDBI_LAT_rdbi_lat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdbi_lat_result : 32;
    } reg;
} SOC_DDR_BPG_RDBI_LAT_RESULT_UNION;
#endif
#define SOC_DDR_BPG_RDBI_LAT_RESULT_rdbi_lat_result_START (0)
#define SOC_DDR_BPG_RDBI_LAT_RESULT_rdbi_lat_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pattern_cfg_data : 32;
    } reg;
} SOC_DDR_BPG_PATTERN_CFG_DATA_UNION;
#endif
#define SOC_DDR_BPG_PATTERN_CFG_DATA_pattern_cfg_data_START (0)
#define SOC_DDR_BPG_PATTERN_CFG_DATA_pattern_cfg_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pattern_cfg_mask : 32;
    } reg;
} SOC_DDR_BPG_PATTERN_CFG_MASK_UNION;
#endif
#define SOC_DDR_BPG_PATTERN_CFG_MASK_pattern_cfg_mask_START (0)
#define SOC_DDR_BPG_PATTERN_CFG_MASK_pattern_cfg_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pattern_mask_bit : 32;
    } reg;
} SOC_DDR_BPG_RDATA_PATTERN_MASK_UNION;
#endif
#define SOC_DDR_BPG_RDATA_PATTERN_MASK_pattern_mask_bit_START (0)
#define SOC_DDR_BPG_RDATA_PATTERN_MASK_pattern_mask_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pattern_dbi_mask_bit : 32;
    } reg;
} SOC_DDR_BPG_RDBI_PATTERN_MASK_UNION;
#endif
#define SOC_DDR_BPG_RDBI_PATTERN_MASK_pattern_dbi_mask_bit_START (0)
#define SOC_DDR_BPG_RDBI_PATTERN_MASK_pattern_dbi_mask_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pattern_amp_bit : 32;
    } reg;
} SOC_DDR_BPG_PATTERN_AMP_BIT_UNION;
#endif
#define SOC_DDR_BPG_PATTERN_AMP_BIT_pattern_amp_bit_START (0)
#define SOC_DDR_BPG_PATTERN_AMP_BIT_pattern_amp_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pattern_amp_mask : 32;
    } reg;
} SOC_DDR_BPG_PATTERN_AMP_MASK_UNION;
#endif
#define SOC_DDR_BPG_PATTERN_AMP_MASK_pattern_amp_mask_START (0)
#define SOC_DDR_BPG_PATTERN_AMP_MASK_pattern_amp_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bpg_dfi_phyupd_reg : 1;
        unsigned int bpg_dfi_ctrlupd_reg : 1;
        unsigned int reserved_0 : 2;
        unsigned int bpg_lpx_wck_enable : 1;
        unsigned int bpg_lpx_wck_bypass : 1;
        unsigned int reserved_1 : 2;
        unsigned int bpg_ahb_broadcast : 1;
        unsigned int reserved_2 : 3;
        unsigned int ca_train_mode : 3;
        unsigned int ca_train_en : 1;
        unsigned int ste_work_mode : 1;
        unsigned int reserved_3 : 5;
        unsigned int bpg_qdr_mode : 1;
        unsigned int phy_mode_sel : 3;
        unsigned int rdqs_train_mode : 1;
        unsigned int reserved_4 : 5;
    } reg;
} SOC_DDR_BPG_PHY_CTRL0_UNION;
#endif
#define SOC_DDR_BPG_PHY_CTRL0_bpg_dfi_phyupd_reg_START (0)
#define SOC_DDR_BPG_PHY_CTRL0_bpg_dfi_phyupd_reg_END (0)
#define SOC_DDR_BPG_PHY_CTRL0_bpg_dfi_ctrlupd_reg_START (1)
#define SOC_DDR_BPG_PHY_CTRL0_bpg_dfi_ctrlupd_reg_END (1)
#define SOC_DDR_BPG_PHY_CTRL0_bpg_lpx_wck_enable_START (4)
#define SOC_DDR_BPG_PHY_CTRL0_bpg_lpx_wck_enable_END (4)
#define SOC_DDR_BPG_PHY_CTRL0_bpg_lpx_wck_bypass_START (5)
#define SOC_DDR_BPG_PHY_CTRL0_bpg_lpx_wck_bypass_END (5)
#define SOC_DDR_BPG_PHY_CTRL0_bpg_ahb_broadcast_START (8)
#define SOC_DDR_BPG_PHY_CTRL0_bpg_ahb_broadcast_END (8)
#define SOC_DDR_BPG_PHY_CTRL0_ca_train_mode_START (12)
#define SOC_DDR_BPG_PHY_CTRL0_ca_train_mode_END (14)
#define SOC_DDR_BPG_PHY_CTRL0_ca_train_en_START (15)
#define SOC_DDR_BPG_PHY_CTRL0_ca_train_en_END (15)
#define SOC_DDR_BPG_PHY_CTRL0_ste_work_mode_START (16)
#define SOC_DDR_BPG_PHY_CTRL0_ste_work_mode_END (16)
#define SOC_DDR_BPG_PHY_CTRL0_bpg_qdr_mode_START (22)
#define SOC_DDR_BPG_PHY_CTRL0_bpg_qdr_mode_END (22)
#define SOC_DDR_BPG_PHY_CTRL0_phy_mode_sel_START (23)
#define SOC_DDR_BPG_PHY_CTRL0_phy_mode_sel_END (25)
#define SOC_DDR_BPG_PHY_CTRL0_rdqs_train_mode_START (26)
#define SOC_DDR_BPG_PHY_CTRL0_rdqs_train_mode_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bpg_work_mode : 1;
        unsigned int hdr2sdr_reset : 1;
        unsigned int icfg_dfi_mux_mode : 3;
        unsigned int icfg_spread_mode : 1;
        unsigned int icfg_duplicate_cs_mode : 2;
        unsigned int icfg_rfifo_en : 1;
        unsigned int icfg_rfifo_rst_n : 1;
        unsigned int icfg_ahb_broadcast_mode : 3;
        unsigned int icfg_ac_update : 1;
        unsigned int icfg_dx_update : 1;
        unsigned int icfg_phyupd_dual_ch : 2;
        unsigned int icfg_phyupd_bp_auto : 1;
        unsigned int ti_lbpk_dq_sel : 8;
        unsigned int ti_lbpk_phase_sel : 2;
        unsigned int icfg_dram_lb_en : 1;
        unsigned int icfg_dram_power_n : 1;
        unsigned int icfg_ac_training_mode : 1;
        unsigned int icfg_cke_share_dis : 1;
    } reg;
} SOC_DDR_BPG_PHY_CTRL1_UNION;
#endif
#define SOC_DDR_BPG_PHY_CTRL1_bpg_work_mode_START (0)
#define SOC_DDR_BPG_PHY_CTRL1_bpg_work_mode_END (0)
#define SOC_DDR_BPG_PHY_CTRL1_hdr2sdr_reset_START (1)
#define SOC_DDR_BPG_PHY_CTRL1_hdr2sdr_reset_END (1)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_dfi_mux_mode_START (2)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_dfi_mux_mode_END (4)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_spread_mode_START (5)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_spread_mode_END (5)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_duplicate_cs_mode_START (6)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_duplicate_cs_mode_END (7)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_rfifo_en_START (8)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_rfifo_en_END (8)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_rfifo_rst_n_START (9)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_rfifo_rst_n_END (9)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_ahb_broadcast_mode_START (10)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_ahb_broadcast_mode_END (12)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_ac_update_START (13)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_ac_update_END (13)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_dx_update_START (14)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_dx_update_END (14)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_phyupd_dual_ch_START (15)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_phyupd_dual_ch_END (16)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_phyupd_bp_auto_START (17)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_phyupd_bp_auto_END (17)
#define SOC_DDR_BPG_PHY_CTRL1_ti_lbpk_dq_sel_START (18)
#define SOC_DDR_BPG_PHY_CTRL1_ti_lbpk_dq_sel_END (25)
#define SOC_DDR_BPG_PHY_CTRL1_ti_lbpk_phase_sel_START (26)
#define SOC_DDR_BPG_PHY_CTRL1_ti_lbpk_phase_sel_END (27)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_dram_lb_en_START (28)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_dram_lb_en_END (28)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_dram_power_n_START (29)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_dram_power_n_END (29)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_ac_training_mode_START (30)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_ac_training_mode_END (30)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_cke_share_dis_START (31)
#define SOC_DDR_BPG_PHY_CTRL1_icfg_cke_share_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_cha_cs_matrix : 32;
    } reg;
} SOC_DDR_BPG_PHY_CTRL2_UNION;
#endif
#define SOC_DDR_BPG_PHY_CTRL2_icfg_cha_cs_matrix_START (0)
#define SOC_DDR_BPG_PHY_CTRL2_icfg_cha_cs_matrix_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_chb_cs_matrix : 32;
    } reg;
} SOC_DDR_BPG_PHY_CTRL3_UNION;
#endif
#define SOC_DDR_BPG_PHY_CTRL3_icfg_chb_cs_matrix_START (0)
#define SOC_DDR_BPG_PHY_CTRL3_icfg_chb_cs_matrix_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_byte_disable : 20;
        unsigned int icfg_clk_sel_cha : 4;
        unsigned int icfg_clk_sel_chb : 4;
        unsigned int icfg_dfi_mux_hdr_mode : 1;
        unsigned int icfg_bphy_lp_mode : 2;
        unsigned int icfg_data_cs_polity : 1;
    } reg;
} SOC_DDR_BPG_PHY_CTRL4_UNION;
#endif
#define SOC_DDR_BPG_PHY_CTRL4_icfg_byte_disable_START (0)
#define SOC_DDR_BPG_PHY_CTRL4_icfg_byte_disable_END (19)
#define SOC_DDR_BPG_PHY_CTRL4_icfg_clk_sel_cha_START (20)
#define SOC_DDR_BPG_PHY_CTRL4_icfg_clk_sel_cha_END (23)
#define SOC_DDR_BPG_PHY_CTRL4_icfg_clk_sel_chb_START (24)
#define SOC_DDR_BPG_PHY_CTRL4_icfg_clk_sel_chb_END (27)
#define SOC_DDR_BPG_PHY_CTRL4_icfg_dfi_mux_hdr_mode_START (28)
#define SOC_DDR_BPG_PHY_CTRL4_icfg_dfi_mux_hdr_mode_END (28)
#define SOC_DDR_BPG_PHY_CTRL4_icfg_bphy_lp_mode_START (29)
#define SOC_DDR_BPG_PHY_CTRL4_icfg_bphy_lp_mode_END (30)
#define SOC_DDR_BPG_PHY_CTRL4_icfg_data_cs_polity_START (31)
#define SOC_DDR_BPG_PHY_CTRL4_icfg_data_cs_polity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_lp_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_BPG_PHY_CTRL5_UNION;
#endif
#define SOC_DDR_BPG_PHY_CTRL5_phy_lp_disable_START (0)
#define SOC_DDR_BPG_PHY_CTRL5_phy_lp_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bphy_clk_open : 10;
        unsigned int icfg_bphy_peri_mode_switch : 1;
        unsigned int reserved_0 : 1;
        unsigned int icfg_bphy_lp_sft_wakeup : 4;
        unsigned int icfg_bphy_lp_sft_req : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_DDR_BPG_PHY_CTRL6_UNION;
#endif
#define SOC_DDR_BPG_PHY_CTRL6_bphy_clk_open_START (0)
#define SOC_DDR_BPG_PHY_CTRL6_bphy_clk_open_END (9)
#define SOC_DDR_BPG_PHY_CTRL6_icfg_bphy_peri_mode_switch_START (10)
#define SOC_DDR_BPG_PHY_CTRL6_icfg_bphy_peri_mode_switch_END (10)
#define SOC_DDR_BPG_PHY_CTRL6_icfg_bphy_lp_sft_wakeup_START (12)
#define SOC_DDR_BPG_PHY_CTRL6_icfg_bphy_lp_sft_wakeup_END (15)
#define SOC_DDR_BPG_PHY_CTRL6_icfg_bphy_lp_sft_req_START (16)
#define SOC_DDR_BPG_PHY_CTRL6_icfg_bphy_lp_sft_req_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bphy_ack_timeout : 10;
        unsigned int phy_ctrl7_reserved_11_10 : 2;
        unsigned int bphy_exit_prd : 10;
        unsigned int reserved_0 : 2;
        unsigned int bphy_lp_lvl : 4;
        unsigned int bphy_lp_gt_disable : 1;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DDR_BPG_PHY_CTRL7_UNION;
#endif
#define SOC_DDR_BPG_PHY_CTRL7_bphy_ack_timeout_START (0)
#define SOC_DDR_BPG_PHY_CTRL7_bphy_ack_timeout_END (9)
#define SOC_DDR_BPG_PHY_CTRL7_phy_ctrl7_reserved_11_10_START (10)
#define SOC_DDR_BPG_PHY_CTRL7_phy_ctrl7_reserved_11_10_END (11)
#define SOC_DDR_BPG_PHY_CTRL7_bphy_exit_prd_START (12)
#define SOC_DDR_BPG_PHY_CTRL7_bphy_exit_prd_END (21)
#define SOC_DDR_BPG_PHY_CTRL7_bphy_lp_lvl_START (24)
#define SOC_DDR_BPG_PHY_CTRL7_bphy_lp_lvl_END (27)
#define SOC_DDR_BPG_PHY_CTRL7_bphy_lp_gt_disable_START (28)
#define SOC_DDR_BPG_PHY_CTRL7_bphy_lp_gt_disable_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_volt_sel : 3;
        unsigned int icfg_freq_sel : 3;
        unsigned int icfg_pslverr_enable : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_BPG_PHY_CTRL8_UNION;
#endif
#define SOC_DDR_BPG_PHY_CTRL8_icfg_volt_sel_START (0)
#define SOC_DDR_BPG_PHY_CTRL8_icfg_volt_sel_END (2)
#define SOC_DDR_BPG_PHY_CTRL8_icfg_freq_sel_START (3)
#define SOC_DDR_BPG_PHY_CTRL8_icfg_freq_sel_END (5)
#define SOC_DDR_BPG_PHY_CTRL8_icfg_pslverr_enable_START (6)
#define SOC_DDR_BPG_PHY_CTRL8_icfg_pslverr_enable_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_BPG_PHY_CTRL9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_lp_ack : 1;
        unsigned int phy_status0 : 31;
    } reg;
} SOC_DDR_BPG_PHY_STATUS0_UNION;
#endif
#define SOC_DDR_BPG_PHY_STATUS0_phy_lp_ack_START (0)
#define SOC_DDR_BPG_PHY_STATUS0_phy_lp_ack_END (0)
#define SOC_DDR_BPG_PHY_STATUS0_phy_status0_START (1)
#define SOC_DDR_BPG_PHY_STATUS0_phy_status0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfi_lp_ack : 1;
        unsigned int phy_status1 : 31;
    } reg;
} SOC_DDR_BPG_PHY_STATUS1_UNION;
#endif
#define SOC_DDR_BPG_PHY_STATUS1_dfi_lp_ack_START (0)
#define SOC_DDR_BPG_PHY_STATUS1_dfi_lp_ack_END (0)
#define SOC_DDR_BPG_PHY_STATUS1_phy_status1_START (1)
#define SOC_DDR_BPG_PHY_STATUS1_phy_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_int_cfifo_alempty_int : 1;
        unsigned int phy_int_cfifo_stat_cmd_int : 1;
        unsigned int phy_int_rdata_err_int : 1;
        unsigned int phy_int_rdata_lat_index_int : 1;
        unsigned int phy_int_rdata_err_lat_fst_int : 1;
        unsigned int phy_int_rdata_err_lat_lst_int : 1;
        unsigned int phy_int_edc_err_int : 1;
        unsigned int phy_int_timer0_int : 1;
        unsigned int phy_int_timer1_int : 1;
        unsigned int phy_int_timer2_int : 1;
        unsigned int phy_int_timer3_int : 1;
        unsigned int dfi_phyupd_ack : 1;
        unsigned int phy_int_reserved_16_12 : 5;
        unsigned int pll_unlcok_int : 1;
        unsigned int ddrc_perf_int : 1;
        unsigned int uce_lp_int : 1;
        unsigned int ddrc_fatal_int : 1;
        unsigned int ddrc_err_int : 1;
        unsigned int ddrc_arer_eri : 1;
        unsigned int ddrc_arer_fhi : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_BPG_PHY_INT_UNION;
#endif
#define SOC_DDR_BPG_PHY_INT_phy_int_cfifo_alempty_int_START (0)
#define SOC_DDR_BPG_PHY_INT_phy_int_cfifo_alempty_int_END (0)
#define SOC_DDR_BPG_PHY_INT_phy_int_cfifo_stat_cmd_int_START (1)
#define SOC_DDR_BPG_PHY_INT_phy_int_cfifo_stat_cmd_int_END (1)
#define SOC_DDR_BPG_PHY_INT_phy_int_rdata_err_int_START (2)
#define SOC_DDR_BPG_PHY_INT_phy_int_rdata_err_int_END (2)
#define SOC_DDR_BPG_PHY_INT_phy_int_rdata_lat_index_int_START (3)
#define SOC_DDR_BPG_PHY_INT_phy_int_rdata_lat_index_int_END (3)
#define SOC_DDR_BPG_PHY_INT_phy_int_rdata_err_lat_fst_int_START (4)
#define SOC_DDR_BPG_PHY_INT_phy_int_rdata_err_lat_fst_int_END (4)
#define SOC_DDR_BPG_PHY_INT_phy_int_rdata_err_lat_lst_int_START (5)
#define SOC_DDR_BPG_PHY_INT_phy_int_rdata_err_lat_lst_int_END (5)
#define SOC_DDR_BPG_PHY_INT_phy_int_edc_err_int_START (6)
#define SOC_DDR_BPG_PHY_INT_phy_int_edc_err_int_END (6)
#define SOC_DDR_BPG_PHY_INT_phy_int_timer0_int_START (7)
#define SOC_DDR_BPG_PHY_INT_phy_int_timer0_int_END (7)
#define SOC_DDR_BPG_PHY_INT_phy_int_timer1_int_START (8)
#define SOC_DDR_BPG_PHY_INT_phy_int_timer1_int_END (8)
#define SOC_DDR_BPG_PHY_INT_phy_int_timer2_int_START (9)
#define SOC_DDR_BPG_PHY_INT_phy_int_timer2_int_END (9)
#define SOC_DDR_BPG_PHY_INT_phy_int_timer3_int_START (10)
#define SOC_DDR_BPG_PHY_INT_phy_int_timer3_int_END (10)
#define SOC_DDR_BPG_PHY_INT_dfi_phyupd_ack_START (11)
#define SOC_DDR_BPG_PHY_INT_dfi_phyupd_ack_END (11)
#define SOC_DDR_BPG_PHY_INT_phy_int_reserved_16_12_START (12)
#define SOC_DDR_BPG_PHY_INT_phy_int_reserved_16_12_END (16)
#define SOC_DDR_BPG_PHY_INT_pll_unlcok_int_START (17)
#define SOC_DDR_BPG_PHY_INT_pll_unlcok_int_END (17)
#define SOC_DDR_BPG_PHY_INT_ddrc_perf_int_START (18)
#define SOC_DDR_BPG_PHY_INT_ddrc_perf_int_END (18)
#define SOC_DDR_BPG_PHY_INT_uce_lp_int_START (19)
#define SOC_DDR_BPG_PHY_INT_uce_lp_int_END (19)
#define SOC_DDR_BPG_PHY_INT_ddrc_fatal_int_START (20)
#define SOC_DDR_BPG_PHY_INT_ddrc_fatal_int_END (20)
#define SOC_DDR_BPG_PHY_INT_ddrc_err_int_START (21)
#define SOC_DDR_BPG_PHY_INT_ddrc_err_int_END (21)
#define SOC_DDR_BPG_PHY_INT_ddrc_arer_eri_START (22)
#define SOC_DDR_BPG_PHY_INT_ddrc_arer_eri_END (22)
#define SOC_DDR_BPG_PHY_INT_ddrc_arer_fhi_START (23)
#define SOC_DDR_BPG_PHY_INT_ddrc_arer_fhi_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_pulse_width : 4;
        unsigned int phy_pulse_en : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_BPG_PHY_PULSE_CFG_UNION;
#endif
#define SOC_DDR_BPG_PHY_PULSE_CFG_phy_pulse_width_START (0)
#define SOC_DDR_BPG_PHY_PULSE_CFG_phy_pulse_width_END (3)
#define SOC_DDR_BPG_PHY_PULSE_CFG_phy_pulse_en_START (4)
#define SOC_DDR_BPG_PHY_PULSE_CFG_phy_pulse_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_lpx_wck_config_cnt0 : 12;
        unsigned int icfg_dfi_wck_toggle0 : 2;
        unsigned int icfg_lpx_wck_stable0 : 1;
        unsigned int icfg_dfi_wck_en0 : 1;
        unsigned int icfg_lpx_wck_config_cnt1 : 12;
        unsigned int icfg_dfi_wck_toggle1 : 2;
        unsigned int icfg_lpx_wck_stable1 : 1;
        unsigned int icfg_dfi_wck_en1 : 1;
    } reg;
} SOC_DDR_BPG_PHY_WCK_CONFIG0_UNION;
#endif
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_lpx_wck_config_cnt0_START (0)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_lpx_wck_config_cnt0_END (11)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_dfi_wck_toggle0_START (12)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_dfi_wck_toggle0_END (13)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_lpx_wck_stable0_START (14)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_lpx_wck_stable0_END (14)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_dfi_wck_en0_START (15)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_dfi_wck_en0_END (15)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_lpx_wck_config_cnt1_START (16)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_lpx_wck_config_cnt1_END (27)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_dfi_wck_toggle1_START (28)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_dfi_wck_toggle1_END (29)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_lpx_wck_stable1_START (30)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_lpx_wck_stable1_END (30)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_dfi_wck_en1_START (31)
#define SOC_DDR_BPG_PHY_WCK_CONFIG0_icfg_dfi_wck_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_lpx_wck_config_cnt2 : 12;
        unsigned int icfg_dfi_wck_toggle2 : 2;
        unsigned int icfg_lpx_wck_stable2 : 1;
        unsigned int icfg_dfi_wck_en2 : 1;
        unsigned int icfg_lpx_wck_config_cnt3 : 12;
        unsigned int icfg_dfi_wck_toggle3 : 2;
        unsigned int icfg_lpx_wck_stable3 : 1;
        unsigned int icfg_dfi_wck_en3 : 1;
    } reg;
} SOC_DDR_BPG_PHY_WCK_CONFIG1_UNION;
#endif
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_lpx_wck_config_cnt2_START (0)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_lpx_wck_config_cnt2_END (11)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_dfi_wck_toggle2_START (12)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_dfi_wck_toggle2_END (13)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_lpx_wck_stable2_START (14)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_lpx_wck_stable2_END (14)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_dfi_wck_en2_START (15)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_dfi_wck_en2_END (15)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_lpx_wck_config_cnt3_START (16)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_lpx_wck_config_cnt3_END (27)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_dfi_wck_toggle3_START (28)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_dfi_wck_toggle3_END (29)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_lpx_wck_stable3_START (30)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_lpx_wck_stable3_END (30)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_dfi_wck_en3_START (31)
#define SOC_DDR_BPG_PHY_WCK_CONFIG1_icfg_dfi_wck_en3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_int_cfifo_alempty_int_mask : 1;
        unsigned int phy_int_cfifo_stat_cmd_int_mask : 1;
        unsigned int phy_int_rdata_err_int_mask : 1;
        unsigned int phy_int_rdata_lat_index_int_mask : 1;
        unsigned int phy_int_rdata_err_lat_fst_int_mask : 1;
        unsigned int phy_int_rdata_err_lat_lst_int_mask : 1;
        unsigned int phy_int_edc_err_int_mask : 1;
        unsigned int phy_int_timer0_int_mask : 1;
        unsigned int phy_int_timer1_int_mask : 1;
        unsigned int phy_int_timer2_int_mask : 1;
        unsigned int phy_int_timer3_int_mask : 1;
        unsigned int dfi_phyupd_ack_mask : 1;
        unsigned int sys_int_mask_reserved_16_12 : 5;
        unsigned int pll_unlcok_int_mask : 1;
        unsigned int ddrc_perf_int_mask : 1;
        unsigned int uce_lp_int_mask : 1;
        unsigned int ddrc_fatal_int_mask : 1;
        unsigned int ddrc_err_int_mask : 1;
        unsigned int ddrc_arer_eri_mask : 1;
        unsigned int ddrc_arer_fhi_mask : 1;
        unsigned int sys_int_mask : 8;
    } reg;
} SOC_DDR_BPG_SYS_INT_MASK_UNION;
#endif
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_cfifo_alempty_int_mask_START (0)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_cfifo_alempty_int_mask_END (0)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_cfifo_stat_cmd_int_mask_START (1)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_cfifo_stat_cmd_int_mask_END (1)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_rdata_err_int_mask_START (2)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_rdata_err_int_mask_END (2)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_rdata_lat_index_int_mask_START (3)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_rdata_lat_index_int_mask_END (3)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_rdata_err_lat_fst_int_mask_START (4)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_rdata_err_lat_fst_int_mask_END (4)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_rdata_err_lat_lst_int_mask_START (5)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_rdata_err_lat_lst_int_mask_END (5)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_edc_err_int_mask_START (6)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_edc_err_int_mask_END (6)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_timer0_int_mask_START (7)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_timer0_int_mask_END (7)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_timer1_int_mask_START (8)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_timer1_int_mask_END (8)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_timer2_int_mask_START (9)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_timer2_int_mask_END (9)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_timer3_int_mask_START (10)
#define SOC_DDR_BPG_SYS_INT_MASK_phy_int_timer3_int_mask_END (10)
#define SOC_DDR_BPG_SYS_INT_MASK_dfi_phyupd_ack_mask_START (11)
#define SOC_DDR_BPG_SYS_INT_MASK_dfi_phyupd_ack_mask_END (11)
#define SOC_DDR_BPG_SYS_INT_MASK_sys_int_mask_reserved_16_12_START (12)
#define SOC_DDR_BPG_SYS_INT_MASK_sys_int_mask_reserved_16_12_END (16)
#define SOC_DDR_BPG_SYS_INT_MASK_pll_unlcok_int_mask_START (17)
#define SOC_DDR_BPG_SYS_INT_MASK_pll_unlcok_int_mask_END (17)
#define SOC_DDR_BPG_SYS_INT_MASK_ddrc_perf_int_mask_START (18)
#define SOC_DDR_BPG_SYS_INT_MASK_ddrc_perf_int_mask_END (18)
#define SOC_DDR_BPG_SYS_INT_MASK_uce_lp_int_mask_START (19)
#define SOC_DDR_BPG_SYS_INT_MASK_uce_lp_int_mask_END (19)
#define SOC_DDR_BPG_SYS_INT_MASK_ddrc_fatal_int_mask_START (20)
#define SOC_DDR_BPG_SYS_INT_MASK_ddrc_fatal_int_mask_END (20)
#define SOC_DDR_BPG_SYS_INT_MASK_ddrc_err_int_mask_START (21)
#define SOC_DDR_BPG_SYS_INT_MASK_ddrc_err_int_mask_END (21)
#define SOC_DDR_BPG_SYS_INT_MASK_ddrc_arer_eri_mask_START (22)
#define SOC_DDR_BPG_SYS_INT_MASK_ddrc_arer_eri_mask_END (22)
#define SOC_DDR_BPG_SYS_INT_MASK_ddrc_arer_fhi_mask_START (23)
#define SOC_DDR_BPG_SYS_INT_MASK_ddrc_arer_fhi_mask_END (23)
#define SOC_DDR_BPG_SYS_INT_MASK_sys_int_mask_START (24)
#define SOC_DDR_BPG_SYS_INT_MASK_sys_int_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_ctrl : 32;
    } reg;
} SOC_DDR_BPG_SYS_CTRL_UNION;
#endif
#define SOC_DDR_BPG_SYS_CTRL_sys_ctrl_START (0)
#define SOC_DDR_BPG_SYS_CTRL_sys_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_status : 32;
    } reg;
} SOC_DDR_BPG_SYS_STATUS_UNION;
#endif
#define SOC_DDR_BPG_SYS_STATUS_sys_status_START (0)
#define SOC_DDR_BPG_SYS_STATUS_sys_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iram_cfg : 23;
        unsigned int resverved : 9;
    } reg;
} SOC_DDR_BPG_IRAM_CFG_UNION;
#endif
#define SOC_DDR_BPG_IRAM_CFG_iram_cfg_START (0)
#define SOC_DDR_BPG_IRAM_CFG_iram_cfg_END (22)
#define SOC_DDR_BPG_IRAM_CFG_resverved_START (23)
#define SOC_DDR_BPG_IRAM_CFG_resverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dram_cfg : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_BPG_DRAM_CFG_UNION;
#endif
#define SOC_DDR_BPG_DRAM_CFG_dram_cfg_START (0)
#define SOC_DDR_BPG_DRAM_CFG_dram_cfg_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bpg_clk1x_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_BPG_SYS_CLOCK_DIS_UNION;
#endif
#define SOC_DDR_BPG_SYS_CLOCK_DIS_bpg_clk1x_dis_START (0)
#define SOC_DDR_BPG_SYS_CLOCK_DIS_bpg_clk1x_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_cnt : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_DDR_BPG_RDATA_CNT_UNION;
#endif
#define SOC_DDR_BPG_RDATA_CNT_rdata_cnt_START (0)
#define SOC_DDR_BPG_RDATA_CNT_rdata_cnt_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer0 : 32;
    } reg;
} SOC_DDR_BPG_TIMER0_UNION;
#endif
#define SOC_DDR_BPG_TIMER0_timer0_START (0)
#define SOC_DDR_BPG_TIMER0_timer0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer0_en : 1;
        unsigned int timer0_int_en : 1;
        unsigned int timer0_int : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_BPG_TIMER0_CFG_UNION;
#endif
#define SOC_DDR_BPG_TIMER0_CFG_timer0_en_START (0)
#define SOC_DDR_BPG_TIMER0_CFG_timer0_en_END (0)
#define SOC_DDR_BPG_TIMER0_CFG_timer0_int_en_START (1)
#define SOC_DDR_BPG_TIMER0_CFG_timer0_int_en_END (1)
#define SOC_DDR_BPG_TIMER0_CFG_timer0_int_START (2)
#define SOC_DDR_BPG_TIMER0_CFG_timer0_int_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer1 : 32;
    } reg;
} SOC_DDR_BPG_TIMER1_UNION;
#endif
#define SOC_DDR_BPG_TIMER1_timer1_START (0)
#define SOC_DDR_BPG_TIMER1_timer1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer1_en : 1;
        unsigned int timer1_int_en : 1;
        unsigned int timer1_int : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_BPG_TIMER1_CFG_UNION;
#endif
#define SOC_DDR_BPG_TIMER1_CFG_timer1_en_START (0)
#define SOC_DDR_BPG_TIMER1_CFG_timer1_en_END (0)
#define SOC_DDR_BPG_TIMER1_CFG_timer1_int_en_START (1)
#define SOC_DDR_BPG_TIMER1_CFG_timer1_int_en_END (1)
#define SOC_DDR_BPG_TIMER1_CFG_timer1_int_START (2)
#define SOC_DDR_BPG_TIMER1_CFG_timer1_int_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer2 : 32;
    } reg;
} SOC_DDR_BPG_TIMER2_UNION;
#endif
#define SOC_DDR_BPG_TIMER2_timer2_START (0)
#define SOC_DDR_BPG_TIMER2_timer2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer2_en : 1;
        unsigned int timer2_int_en : 1;
        unsigned int timer2_int : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_BPG_TIMER2_CFG_UNION;
#endif
#define SOC_DDR_BPG_TIMER2_CFG_timer2_en_START (0)
#define SOC_DDR_BPG_TIMER2_CFG_timer2_en_END (0)
#define SOC_DDR_BPG_TIMER2_CFG_timer2_int_en_START (1)
#define SOC_DDR_BPG_TIMER2_CFG_timer2_int_en_END (1)
#define SOC_DDR_BPG_TIMER2_CFG_timer2_int_START (2)
#define SOC_DDR_BPG_TIMER2_CFG_timer2_int_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer3 : 32;
    } reg;
} SOC_DDR_BPG_TIMER3_UNION;
#endif
#define SOC_DDR_BPG_TIMER3_timer3_START (0)
#define SOC_DDR_BPG_TIMER3_timer3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer3_en : 1;
        unsigned int timer3_int_en : 1;
        unsigned int timer3_int : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_BPG_TIMER3_CFG_UNION;
#endif
#define SOC_DDR_BPG_TIMER3_CFG_timer3_en_START (0)
#define SOC_DDR_BPG_TIMER3_CFG_timer3_en_END (0)
#define SOC_DDR_BPG_TIMER3_CFG_timer3_int_en_START (1)
#define SOC_DDR_BPG_TIMER3_CFG_timer3_int_en_END (1)
#define SOC_DDR_BPG_TIMER3_CFG_timer3_int_START (2)
#define SOC_DDR_BPG_TIMER3_CFG_timer3_int_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_pbuf : 32;
    } reg;
} SOC_DDR_BPG_DMC_PBUF_UNION;
#endif
#define SOC_DDR_BPG_DMC_PBUF_dmc_pbuf_START (0)
#define SOC_DDR_BPG_DMC_PBUF_dmc_pbuf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_pbuf_edc : 32;
    } reg;
} SOC_DDR_BPG_DMC_PBUF_EDC_UNION;
#endif
#define SOC_DDR_BPG_DMC_PBUF_EDC_dmc_pbuf_edc_START (0)
#define SOC_DDR_BPG_DMC_PBUF_EDC_dmc_pbuf_edc_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
