#ifndef __SOC_DDR_EMU_PHY_INTERFACE_H__
#define __SOC_DDR_EMU_PHY_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_EMU_PHY_CMD_TIMING_ADDR(base) (base)
#define SOC_DDR_EMU_PHY_WRITE_TIMING_ADDR(base) ((base) + 0x0004UL)
#define SOC_DDR_EMU_PHY_READ_TIMING_ADDR(base) ((base) + 0x0008UL)
#define SOC_DDR_EMU_PHY_WCK_TIMING_ADDR(base) ((base) + 0x000CUL)
#define SOC_DDR_EMU_PHY_PHASE_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_DDR_EMU_PHY_MISC_CTRL_ADDR(base) ((base) + 0x0100UL)
#define SOC_DDR_EMU_PHY_PS_CTRL_ADDR(base) ((base) + 0x0200UL)
#define SOC_DDR_EMU_PHY_PS_STATUS_ADDR(base) ((base) + 0x0204UL)
#define SOC_DDR_EMU_PHY_PS_CLR_ADDR(base) ((base) + 0x0208UL)
#else
#define SOC_DDR_EMU_PHY_CMD_TIMING_ADDR(base) (base)
#define SOC_DDR_EMU_PHY_WRITE_TIMING_ADDR(base) ((base) + 0x0004)
#define SOC_DDR_EMU_PHY_READ_TIMING_ADDR(base) ((base) + 0x0008)
#define SOC_DDR_EMU_PHY_WCK_TIMING_ADDR(base) ((base) + 0x000C)
#define SOC_DDR_EMU_PHY_PHASE_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_DDR_EMU_PHY_MISC_CTRL_ADDR(base) ((base) + 0x0100)
#define SOC_DDR_EMU_PHY_PS_CTRL_ADDR(base) ((base) + 0x0200)
#define SOC_DDR_EMU_PHY_PS_STATUS_ADDR(base) ((base) + 0x0204)
#define SOC_DDR_EMU_PHY_PS_CLR_ADDR(base) ((base) + 0x0208)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taddr : 8;
        unsigned int tcke : 8;
        unsigned int tck_dis : 8;
        unsigned int taddr_tick : 8;
    } reg;
} SOC_DDR_EMU_PHY_CMD_TIMING_UNION;
#endif
#define SOC_DDR_EMU_PHY_CMD_TIMING_taddr_START (0)
#define SOC_DDR_EMU_PHY_CMD_TIMING_taddr_END (7)
#define SOC_DDR_EMU_PHY_CMD_TIMING_tcke_START (8)
#define SOC_DDR_EMU_PHY_CMD_TIMING_tcke_END (15)
#define SOC_DDR_EMU_PHY_CMD_TIMING_tck_dis_START (16)
#define SOC_DDR_EMU_PHY_CMD_TIMING_tck_dis_END (23)
#define SOC_DDR_EMU_PHY_CMD_TIMING_taddr_tick_START (24)
#define SOC_DDR_EMU_PHY_CMD_TIMING_taddr_tick_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int twrdata : 8;
        unsigned int twren : 8;
        unsigned int twren_ext : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_DDR_EMU_PHY_WRITE_TIMING_UNION;
#endif
#define SOC_DDR_EMU_PHY_WRITE_TIMING_twrdata_START (0)
#define SOC_DDR_EMU_PHY_WRITE_TIMING_twrdata_END (7)
#define SOC_DDR_EMU_PHY_WRITE_TIMING_twren_START (8)
#define SOC_DDR_EMU_PHY_WRITE_TIMING_twren_END (15)
#define SOC_DDR_EMU_PHY_WRITE_TIMING_twren_ext_START (16)
#define SOC_DDR_EMU_PHY_WRITE_TIMING_twren_ext_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trddata : 8;
        unsigned int trden : 8;
        unsigned int tphy_gate_sel : 1;
        unsigned int trdata_align : 2;
        unsigned int reserved : 13;
    } reg;
} SOC_DDR_EMU_PHY_READ_TIMING_UNION;
#endif
#define SOC_DDR_EMU_PHY_READ_TIMING_trddata_START (0)
#define SOC_DDR_EMU_PHY_READ_TIMING_trddata_END (7)
#define SOC_DDR_EMU_PHY_READ_TIMING_trden_START (8)
#define SOC_DDR_EMU_PHY_READ_TIMING_trden_END (15)
#define SOC_DDR_EMU_PHY_READ_TIMING_tphy_gate_sel_START (16)
#define SOC_DDR_EMU_PHY_READ_TIMING_tphy_gate_sel_END (16)
#define SOC_DDR_EMU_PHY_READ_TIMING_trdata_align_START (17)
#define SOC_DDR_EMU_PHY_READ_TIMING_trdata_align_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int twck_en : 8;
        unsigned int twck_tog : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_EMU_PHY_WCK_TIMING_UNION;
#endif
#define SOC_DDR_EMU_PHY_WCK_TIMING_twck_en_START (0)
#define SOC_DDR_EMU_PHY_WCK_TIMING_twck_en_END (7)
#define SOC_DDR_EMU_PHY_WCK_TIMING_twck_tog_START (8)
#define SOC_DDR_EMU_PHY_WCK_TIMING_twck_tog_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrdata_en_phase : 2;
        unsigned int wrdata_phase : 2;
        unsigned int rddata_en_phase : 2;
        unsigned int wck_phase : 2;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_EMU_PHY_PHASE_CTRL_UNION;
#endif
#define SOC_DDR_EMU_PHY_PHASE_CTRL_wrdata_en_phase_START (0)
#define SOC_DDR_EMU_PHY_PHASE_CTRL_wrdata_en_phase_END (1)
#define SOC_DDR_EMU_PHY_PHASE_CTRL_wrdata_phase_START (2)
#define SOC_DDR_EMU_PHY_PHASE_CTRL_wrdata_phase_END (3)
#define SOC_DDR_EMU_PHY_PHASE_CTRL_rddata_en_phase_START (4)
#define SOC_DDR_EMU_PHY_PHASE_CTRL_rddata_en_phase_END (5)
#define SOC_DDR_EMU_PHY_PHASE_CTRL_wck_phase_START (6)
#define SOC_DDR_EMU_PHY_PHASE_CTRL_wck_phase_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wck_alwayson : 1;
        unsigned int overclock_en : 1;
        unsigned int overclock_phase : 1;
        unsigned int lecc_wr_en : 1;
        unsigned int lp4_mode : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_EMU_PHY_MISC_CTRL_UNION;
#endif
#define SOC_DDR_EMU_PHY_MISC_CTRL_wck_alwayson_START (0)
#define SOC_DDR_EMU_PHY_MISC_CTRL_wck_alwayson_END (0)
#define SOC_DDR_EMU_PHY_MISC_CTRL_overclock_en_START (1)
#define SOC_DDR_EMU_PHY_MISC_CTRL_overclock_en_END (1)
#define SOC_DDR_EMU_PHY_MISC_CTRL_overclock_phase_START (2)
#define SOC_DDR_EMU_PHY_MISC_CTRL_overclock_phase_END (2)
#define SOC_DDR_EMU_PHY_MISC_CTRL_lecc_wr_en_START (3)
#define SOC_DDR_EMU_PHY_MISC_CTRL_lecc_wr_en_END (3)
#define SOC_DDR_EMU_PHY_MISC_CTRL_lp4_mode_START (4)
#define SOC_DDR_EMU_PHY_MISC_CTRL_lp4_mode_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ps_start : 1;
        unsigned int reserved_0 : 3;
        unsigned int psincdec : 1;
        unsigned int reserved_1 : 11;
        unsigned int phase_shift : 13;
        unsigned int reserved_2 : 2;
        unsigned int train_type : 1;
    } reg;
} SOC_DDR_EMU_PHY_PS_CTRL_UNION;
#endif
#define SOC_DDR_EMU_PHY_PS_CTRL_ps_start_START (0)
#define SOC_DDR_EMU_PHY_PS_CTRL_ps_start_END (0)
#define SOC_DDR_EMU_PHY_PS_CTRL_psincdec_START (4)
#define SOC_DDR_EMU_PHY_PS_CTRL_psincdec_END (4)
#define SOC_DDR_EMU_PHY_PS_CTRL_phase_shift_START (16)
#define SOC_DDR_EMU_PHY_PS_CTRL_phase_shift_END (28)
#define SOC_DDR_EMU_PHY_PS_CTRL_train_type_START (31)
#define SOC_DDR_EMU_PHY_PS_CTRL_train_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ps_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EMU_PHY_PS_STATUS_UNION;
#endif
#define SOC_DDR_EMU_PHY_PS_STATUS_ps_status_START (0)
#define SOC_DDR_EMU_PHY_PS_STATUS_ps_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ps_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EMU_PHY_PS_CLR_UNION;
#endif
#define SOC_DDR_EMU_PHY_PS_CLR_ps_clr_START (0)
#define SOC_DDR_EMU_PHY_PS_CLR_ps_clr_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
