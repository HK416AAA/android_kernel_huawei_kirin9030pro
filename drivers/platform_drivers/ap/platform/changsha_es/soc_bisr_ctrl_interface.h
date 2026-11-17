#ifndef __SOC_BISR_CTRL_INTERFACE_H__
#define __SOC_BISR_CTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_BISR_CTRL_REPAIR_AUTO_GT_DISABLE_ADDR(base) ((base) + 0x0008UL)
#define SOC_BISR_CTRL_REPAIR_FINISH_ADDR(base) ((base) + 0x00CUL)
#define SOC_BISR_CTRL_BISR_SRAM_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_BISR_CTRL_BISR_ROM_CTRL_ADDR(base) ((base) + 0x0014UL)
#define SOC_BISR_CTRL_REPAIR_DISABLE_0_ADDR(base) ((base) + 0x0020UL)
#define SOC_BISR_CTRL_REPAIR_DISABLE_1_ADDR(base) ((base) + 0x0024UL)
#define SOC_BISR_CTRL_MEDIA1_SUBSYS_ISO_ADDR(base) ((base) + 0x0030UL)
#define SOC_BISR_CTRL_MEDIA2_SUBSYS_ISO_ADDR(base) ((base) + 0x0034UL)
#define SOC_BISR_CTRL_REPAIR_BYPASS_ADDR(base) ((base) + 0x003CUL)
#define SOC_BISR_CTRL_MRB_BYPASS_0_ADDR(base) ((base) + 0x0040UL)
#define SOC_BISR_CTRL_MRB_BYPASS_1_ADDR(base) ((base) + 0x0044UL)
#define SOC_BISR_CTRL_MRB_BYPASS_2_ADDR(base) ((base) + 0x0048UL)
#define SOC_BISR_CTRL_MRB_BYPASS_3_ADDR(base) ((base) + 0x004CUL)
#define SOC_BISR_CTRL_REPAIR_ACK_0_ADDR(base) ((base) + 0x0050UL)
#define SOC_BISR_CTRL_REPAIR_ACK_1_ADDR(base) ((base) + 0x0054UL)
#define SOC_BISR_CTRL_REPAIR_ACK_2_ADDR(base) ((base) + 0x0058UL)
#define SOC_BISR_CTRL_REPAIR_ACK_3_ADDR(base) ((base) + 0x005CUL)
#define SOC_BISR_CTRL_MRB_BUSY_0_ADDR(base) ((base) + 0x0068UL)
#define SOC_BISR_CTRL_MRB_BUSY_1_ADDR(base) ((base) + 0x006CUL)
#define SOC_BISR_CTRL_REPAIR_DONE_0_ADDR(base) ((base) + 0x0080UL)
#define SOC_BISR_CTRL_REPAIR_DONE_1_ADDR(base) ((base) + 0x0084UL)
#define SOC_BISR_CTRL_BISR0_STATUS_ADDR(base) ((base) + 0x0098UL)
#define SOC_BISR_CTRL_BISR0_REPAIR_CTRL_ADDR(base) ((base) + 0x104UL)
#define SOC_BISR_CTRL_BISR0_SRAM_RD_SEL_ADDR(base) ((base) + 0x0110UL)
#define SOC_BISR_CTRL_BISR0_INTR_CTRL_ADDR(base) ((base) + 0x0114UL)
#define SOC_BISR_CTRL_BISR0_DBG_STATUS_0_ADDR(base) ((base) + 0x0118UL)
#define SOC_BISR_CTRL_BISR0_DBG_STATUS_1_ADDR(base) ((base) + 0x011CUL)
#define SOC_BISR_CTRL_BISR1_STATUS_ADDR(base) ((base) + 0x0124UL)
#define SOC_BISR_CTRL_BISR1_REPAIR_CTRL_ADDR(base) ((base) + 0x0130UL)
#define SOC_BISR_CTRL_BISR1_SRAM_RD_SEL_ADDR(base) ((base) + 0x013CUL)
#define SOC_BISR_CTRL_BISR1_INTR_CTRL_ADDR(base) ((base) + 0x0140UL)
#define SOC_BISR_CTRL_BISR1_DBG_STATUS_0_ADDR(base) ((base) + 0x0144UL)
#define SOC_BISR_CTRL_BISR1_DBG_STATUS_1_ADDR(base) ((base) + 0x0148UL)
#else
#define SOC_BISR_CTRL_REPAIR_AUTO_GT_DISABLE_ADDR(base) ((base) + 0x0008)
#define SOC_BISR_CTRL_REPAIR_FINISH_ADDR(base) ((base) + 0x00C)
#define SOC_BISR_CTRL_BISR_SRAM_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_BISR_CTRL_BISR_ROM_CTRL_ADDR(base) ((base) + 0x0014)
#define SOC_BISR_CTRL_REPAIR_DISABLE_0_ADDR(base) ((base) + 0x0020)
#define SOC_BISR_CTRL_REPAIR_DISABLE_1_ADDR(base) ((base) + 0x0024)
#define SOC_BISR_CTRL_MEDIA1_SUBSYS_ISO_ADDR(base) ((base) + 0x0030)
#define SOC_BISR_CTRL_MEDIA2_SUBSYS_ISO_ADDR(base) ((base) + 0x0034)
#define SOC_BISR_CTRL_REPAIR_BYPASS_ADDR(base) ((base) + 0x003C)
#define SOC_BISR_CTRL_MRB_BYPASS_0_ADDR(base) ((base) + 0x0040)
#define SOC_BISR_CTRL_MRB_BYPASS_1_ADDR(base) ((base) + 0x0044)
#define SOC_BISR_CTRL_MRB_BYPASS_2_ADDR(base) ((base) + 0x0048)
#define SOC_BISR_CTRL_MRB_BYPASS_3_ADDR(base) ((base) + 0x004C)
#define SOC_BISR_CTRL_REPAIR_ACK_0_ADDR(base) ((base) + 0x0050)
#define SOC_BISR_CTRL_REPAIR_ACK_1_ADDR(base) ((base) + 0x0054)
#define SOC_BISR_CTRL_REPAIR_ACK_2_ADDR(base) ((base) + 0x0058)
#define SOC_BISR_CTRL_REPAIR_ACK_3_ADDR(base) ((base) + 0x005C)
#define SOC_BISR_CTRL_MRB_BUSY_0_ADDR(base) ((base) + 0x0068)
#define SOC_BISR_CTRL_MRB_BUSY_1_ADDR(base) ((base) + 0x006C)
#define SOC_BISR_CTRL_REPAIR_DONE_0_ADDR(base) ((base) + 0x0080)
#define SOC_BISR_CTRL_REPAIR_DONE_1_ADDR(base) ((base) + 0x0084)
#define SOC_BISR_CTRL_BISR0_STATUS_ADDR(base) ((base) + 0x0098)
#define SOC_BISR_CTRL_BISR0_REPAIR_CTRL_ADDR(base) ((base) + 0x104)
#define SOC_BISR_CTRL_BISR0_SRAM_RD_SEL_ADDR(base) ((base) + 0x0110)
#define SOC_BISR_CTRL_BISR0_INTR_CTRL_ADDR(base) ((base) + 0x0114)
#define SOC_BISR_CTRL_BISR0_DBG_STATUS_0_ADDR(base) ((base) + 0x0118)
#define SOC_BISR_CTRL_BISR0_DBG_STATUS_1_ADDR(base) ((base) + 0x011C)
#define SOC_BISR_CTRL_BISR1_STATUS_ADDR(base) ((base) + 0x0124)
#define SOC_BISR_CTRL_BISR1_REPAIR_CTRL_ADDR(base) ((base) + 0x0130)
#define SOC_BISR_CTRL_BISR1_SRAM_RD_SEL_ADDR(base) ((base) + 0x013C)
#define SOC_BISR_CTRL_BISR1_INTR_CTRL_ADDR(base) ((base) + 0x0140)
#define SOC_BISR_CTRL_BISR1_DBG_STATUS_0_ADDR(base) ((base) + 0x0144)
#define SOC_BISR_CTRL_BISR1_DBG_STATUS_1_ADDR(base) ((base) + 0x0148)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_auto_gt_disable : 1;
        unsigned int bisr_reserve_in : 8;
        unsigned int reserved : 23;
    } reg;
} SOC_BISR_CTRL_REPAIR_AUTO_GT_DISABLE_UNION;
#endif
#define SOC_BISR_CTRL_REPAIR_AUTO_GT_DISABLE_repair_auto_gt_disable_START (0)
#define SOC_BISR_CTRL_REPAIR_AUTO_GT_DISABLE_repair_auto_gt_disable_END (0)
#define SOC_BISR_CTRL_REPAIR_AUTO_GT_DISABLE_bisr_reserve_in_START (1)
#define SOC_BISR_CTRL_REPAIR_AUTO_GT_DISABLE_bisr_reserve_in_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_finish : 1;
        unsigned int bisr_reserve_out : 8;
        unsigned int reserved : 23;
    } reg;
} SOC_BISR_CTRL_REPAIR_FINISH_UNION;
#endif
#define SOC_BISR_CTRL_REPAIR_FINISH_repair_finish_START (0)
#define SOC_BISR_CTRL_REPAIR_FINISH_repair_finish_END (0)
#define SOC_BISR_CTRL_REPAIR_FINISH_bisr_reserve_out_START (1)
#define SOC_BISR_CTRL_REPAIR_FINISH_bisr_reserve_out_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_spram_mem_ctrl : 32;
    } reg;
} SOC_BISR_CTRL_BISR_SRAM_CTRL_UNION;
#endif
#define SOC_BISR_CTRL_BISR_SRAM_CTRL_bisr_spram_mem_ctrl_START (0)
#define SOC_BISR_CTRL_BISR_SRAM_CTRL_bisr_spram_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_rom_mem_ctrl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_BISR_CTRL_BISR_ROM_CTRL_UNION;
#endif
#define SOC_BISR_CTRL_BISR_ROM_CTRL_bisr_rom_mem_ctrl_START (0)
#define SOC_BISR_CTRL_BISR_ROM_CTRL_bisr_rom_mem_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_disable_0 : 32;
    } reg;
} SOC_BISR_CTRL_REPAIR_DISABLE_0_UNION;
#endif
#define SOC_BISR_CTRL_REPAIR_DISABLE_0_repair_disable_0_START (0)
#define SOC_BISR_CTRL_REPAIR_DISABLE_0_repair_disable_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_disable_1 : 32;
    } reg;
} SOC_BISR_CTRL_REPAIR_DISABLE_1_UNION;
#endif
#define SOC_BISR_CTRL_REPAIR_DISABLE_1_repair_disable_1_START (0)
#define SOC_BISR_CTRL_REPAIR_DISABLE_1_repair_disable_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int media1_subsys_iso : 16;
        unsigned int iso_en_group_sec_msk : 16;
    } reg;
} SOC_BISR_CTRL_MEDIA1_SUBSYS_ISO_UNION;
#endif
#define SOC_BISR_CTRL_MEDIA1_SUBSYS_ISO_media1_subsys_iso_START (0)
#define SOC_BISR_CTRL_MEDIA1_SUBSYS_ISO_media1_subsys_iso_END (15)
#define SOC_BISR_CTRL_MEDIA1_SUBSYS_ISO_iso_en_group_sec_msk_START (16)
#define SOC_BISR_CTRL_MEDIA1_SUBSYS_ISO_iso_en_group_sec_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int media2_subsys_iso : 16;
        unsigned int iso_en_group_sec_msk : 16;
    } reg;
} SOC_BISR_CTRL_MEDIA2_SUBSYS_ISO_UNION;
#endif
#define SOC_BISR_CTRL_MEDIA2_SUBSYS_ISO_media2_subsys_iso_START (0)
#define SOC_BISR_CTRL_MEDIA2_SUBSYS_ISO_media2_subsys_iso_END (15)
#define SOC_BISR_CTRL_MEDIA2_SUBSYS_ISO_iso_en_group_sec_msk_START (16)
#define SOC_BISR_CTRL_MEDIA2_SUBSYS_ISO_iso_en_group_sec_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_BISR_CTRL_REPAIR_BYPASS_UNION;
#endif
#define SOC_BISR_CTRL_REPAIR_BYPASS_repair_bypass_START (0)
#define SOC_BISR_CTRL_REPAIR_BYPASS_repair_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mrb_bypass_0 : 32;
    } reg;
} SOC_BISR_CTRL_MRB_BYPASS_0_UNION;
#endif
#define SOC_BISR_CTRL_MRB_BYPASS_0_mrb_bypass_0_START (0)
#define SOC_BISR_CTRL_MRB_BYPASS_0_mrb_bypass_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mrb_bypass_1 : 32;
    } reg;
} SOC_BISR_CTRL_MRB_BYPASS_1_UNION;
#endif
#define SOC_BISR_CTRL_MRB_BYPASS_1_mrb_bypass_1_START (0)
#define SOC_BISR_CTRL_MRB_BYPASS_1_mrb_bypass_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mrb_bypass_2 : 32;
    } reg;
} SOC_BISR_CTRL_MRB_BYPASS_2_UNION;
#endif
#define SOC_BISR_CTRL_MRB_BYPASS_2_mrb_bypass_2_START (0)
#define SOC_BISR_CTRL_MRB_BYPASS_2_mrb_bypass_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mrb_bypass_3 : 32;
    } reg;
} SOC_BISR_CTRL_MRB_BYPASS_3_UNION;
#endif
#define SOC_BISR_CTRL_MRB_BYPASS_3_mrb_bypass_3_START (0)
#define SOC_BISR_CTRL_MRB_BYPASS_3_mrb_bypass_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_ack_0 : 32;
    } reg;
} SOC_BISR_CTRL_REPAIR_ACK_0_UNION;
#endif
#define SOC_BISR_CTRL_REPAIR_ACK_0_repair_ack_0_START (0)
#define SOC_BISR_CTRL_REPAIR_ACK_0_repair_ack_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_ack_1 : 32;
    } reg;
} SOC_BISR_CTRL_REPAIR_ACK_1_UNION;
#endif
#define SOC_BISR_CTRL_REPAIR_ACK_1_repair_ack_1_START (0)
#define SOC_BISR_CTRL_REPAIR_ACK_1_repair_ack_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_ack_2 : 32;
    } reg;
} SOC_BISR_CTRL_REPAIR_ACK_2_UNION;
#endif
#define SOC_BISR_CTRL_REPAIR_ACK_2_repair_ack_2_START (0)
#define SOC_BISR_CTRL_REPAIR_ACK_2_repair_ack_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_ack_3 : 32;
    } reg;
} SOC_BISR_CTRL_REPAIR_ACK_3_UNION;
#endif
#define SOC_BISR_CTRL_REPAIR_ACK_3_repair_ack_3_START (0)
#define SOC_BISR_CTRL_REPAIR_ACK_3_repair_ack_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mrb_busy_flag_0 : 32;
    } reg;
} SOC_BISR_CTRL_MRB_BUSY_0_UNION;
#endif
#define SOC_BISR_CTRL_MRB_BUSY_0_mrb_busy_flag_0_START (0)
#define SOC_BISR_CTRL_MRB_BUSY_0_mrb_busy_flag_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mrb_busy_flag_1 : 32;
    } reg;
} SOC_BISR_CTRL_MRB_BUSY_1_UNION;
#endif
#define SOC_BISR_CTRL_MRB_BUSY_1_mrb_busy_flag_1_START (0)
#define SOC_BISR_CTRL_MRB_BUSY_1_mrb_busy_flag_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_done_0 : 32;
    } reg;
} SOC_BISR_CTRL_REPAIR_DONE_0_UNION;
#endif
#define SOC_BISR_CTRL_REPAIR_DONE_0_repair_done_0_START (0)
#define SOC_BISR_CTRL_REPAIR_DONE_0_repair_done_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_done_1 : 32;
    } reg;
} SOC_BISR_CTRL_REPAIR_DONE_1_UNION;
#endif
#define SOC_BISR_CTRL_REPAIR_DONE_1_repair_done_1_START (0)
#define SOC_BISR_CTRL_REPAIR_DONE_1_repair_done_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_repair_finish_0 : 1;
        unsigned int efuse_full_0 : 1;
        unsigned int repair_start_point_err_0 : 1;
        unsigned int pack_is0_err_0 : 1;
        unsigned int dbg_efuse_diff_cnt_0 : 12;
        unsigned int reserved : 16;
    } reg;
} SOC_BISR_CTRL_BISR0_STATUS_UNION;
#endif
#define SOC_BISR_CTRL_BISR0_STATUS_bisr_repair_finish_0_START (0)
#define SOC_BISR_CTRL_BISR0_STATUS_bisr_repair_finish_0_END (0)
#define SOC_BISR_CTRL_BISR0_STATUS_efuse_full_0_START (1)
#define SOC_BISR_CTRL_BISR0_STATUS_efuse_full_0_END (1)
#define SOC_BISR_CTRL_BISR0_STATUS_repair_start_point_err_0_START (2)
#define SOC_BISR_CTRL_BISR0_STATUS_repair_start_point_err_0_END (2)
#define SOC_BISR_CTRL_BISR0_STATUS_pack_is0_err_0_START (3)
#define SOC_BISR_CTRL_BISR0_STATUS_pack_is0_err_0_END (3)
#define SOC_BISR_CTRL_BISR0_STATUS_dbg_efuse_diff_cnt_0_START (4)
#define SOC_BISR_CTRL_BISR0_STATUS_dbg_efuse_diff_cnt_0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iddq_0 : 1;
        unsigned int repair_hs_sw_0 : 1;
        unsigned int dbg_repair_frm_efu_0 : 1;
        unsigned int bisr_dbg_sel_0 : 4;
        unsigned int reserved : 25;
    } reg;
} SOC_BISR_CTRL_BISR0_REPAIR_CTRL_UNION;
#endif
#define SOC_BISR_CTRL_BISR0_REPAIR_CTRL_iddq_0_START (0)
#define SOC_BISR_CTRL_BISR0_REPAIR_CTRL_iddq_0_END (0)
#define SOC_BISR_CTRL_BISR0_REPAIR_CTRL_repair_hs_sw_0_START (1)
#define SOC_BISR_CTRL_BISR0_REPAIR_CTRL_repair_hs_sw_0_END (1)
#define SOC_BISR_CTRL_BISR0_REPAIR_CTRL_dbg_repair_frm_efu_0_START (2)
#define SOC_BISR_CTRL_BISR0_REPAIR_CTRL_dbg_repair_frm_efu_0_END (2)
#define SOC_BISR_CTRL_BISR0_REPAIR_CTRL_bisr_dbg_sel_0_START (3)
#define SOC_BISR_CTRL_BISR0_REPAIR_CTRL_bisr_dbg_sel_0_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_sram_sel_0 : 1;
        unsigned int apb_sram_clk_gt_0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_BISR_CTRL_BISR0_SRAM_RD_SEL_UNION;
#endif
#define SOC_BISR_CTRL_BISR0_SRAM_RD_SEL_bisr_sram_sel_0_START (0)
#define SOC_BISR_CTRL_BISR0_SRAM_RD_SEL_bisr_sram_sel_0_END (0)
#define SOC_BISR_CTRL_BISR0_SRAM_RD_SEL_apb_sram_clk_gt_0_START (1)
#define SOC_BISR_CTRL_BISR0_SRAM_RD_SEL_apb_sram_clk_gt_0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_repair_err_msk_0 : 1;
        unsigned int intr_repair_err_clr_0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_BISR_CTRL_BISR0_INTR_CTRL_UNION;
#endif
#define SOC_BISR_CTRL_BISR0_INTR_CTRL_intr_repair_err_msk_0_START (0)
#define SOC_BISR_CTRL_BISR0_INTR_CTRL_intr_repair_err_msk_0_END (0)
#define SOC_BISR_CTRL_BISR0_INTR_CTRL_intr_repair_err_clr_0_START (1)
#define SOC_BISR_CTRL_BISR0_INTR_CTRL_intr_repair_err_clr_0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_dbg_info_0_0 : 32;
    } reg;
} SOC_BISR_CTRL_BISR0_DBG_STATUS_0_UNION;
#endif
#define SOC_BISR_CTRL_BISR0_DBG_STATUS_0_bisr_dbg_info_0_0_START (0)
#define SOC_BISR_CTRL_BISR0_DBG_STATUS_0_bisr_dbg_info_0_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_dbg_info_0_1 : 32;
    } reg;
} SOC_BISR_CTRL_BISR0_DBG_STATUS_1_UNION;
#endif
#define SOC_BISR_CTRL_BISR0_DBG_STATUS_1_bisr_dbg_info_0_1_START (0)
#define SOC_BISR_CTRL_BISR0_DBG_STATUS_1_bisr_dbg_info_0_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_repair_finish_1 : 1;
        unsigned int efuse_full_1 : 1;
        unsigned int repair_start_point_err_1 : 1;
        unsigned int pack_is0_err_1 : 1;
        unsigned int dbg_efuse_diff_cnt_1 : 12;
        unsigned int reserved : 16;
    } reg;
} SOC_BISR_CTRL_BISR1_STATUS_UNION;
#endif
#define SOC_BISR_CTRL_BISR1_STATUS_bisr_repair_finish_1_START (0)
#define SOC_BISR_CTRL_BISR1_STATUS_bisr_repair_finish_1_END (0)
#define SOC_BISR_CTRL_BISR1_STATUS_efuse_full_1_START (1)
#define SOC_BISR_CTRL_BISR1_STATUS_efuse_full_1_END (1)
#define SOC_BISR_CTRL_BISR1_STATUS_repair_start_point_err_1_START (2)
#define SOC_BISR_CTRL_BISR1_STATUS_repair_start_point_err_1_END (2)
#define SOC_BISR_CTRL_BISR1_STATUS_pack_is0_err_1_START (3)
#define SOC_BISR_CTRL_BISR1_STATUS_pack_is0_err_1_END (3)
#define SOC_BISR_CTRL_BISR1_STATUS_dbg_efuse_diff_cnt_1_START (4)
#define SOC_BISR_CTRL_BISR1_STATUS_dbg_efuse_diff_cnt_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iddq_1 : 1;
        unsigned int repair_hs_sw_1 : 1;
        unsigned int dbg_repair_frm_efu_1 : 1;
        unsigned int bisr_dbg_sel_1 : 4;
        unsigned int reserved : 25;
    } reg;
} SOC_BISR_CTRL_BISR1_REPAIR_CTRL_UNION;
#endif
#define SOC_BISR_CTRL_BISR1_REPAIR_CTRL_iddq_1_START (0)
#define SOC_BISR_CTRL_BISR1_REPAIR_CTRL_iddq_1_END (0)
#define SOC_BISR_CTRL_BISR1_REPAIR_CTRL_repair_hs_sw_1_START (1)
#define SOC_BISR_CTRL_BISR1_REPAIR_CTRL_repair_hs_sw_1_END (1)
#define SOC_BISR_CTRL_BISR1_REPAIR_CTRL_dbg_repair_frm_efu_1_START (2)
#define SOC_BISR_CTRL_BISR1_REPAIR_CTRL_dbg_repair_frm_efu_1_END (2)
#define SOC_BISR_CTRL_BISR1_REPAIR_CTRL_bisr_dbg_sel_1_START (3)
#define SOC_BISR_CTRL_BISR1_REPAIR_CTRL_bisr_dbg_sel_1_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_sram_sel_1 : 1;
        unsigned int apb_sram_clk_gt_1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_BISR_CTRL_BISR1_SRAM_RD_SEL_UNION;
#endif
#define SOC_BISR_CTRL_BISR1_SRAM_RD_SEL_bisr_sram_sel_1_START (0)
#define SOC_BISR_CTRL_BISR1_SRAM_RD_SEL_bisr_sram_sel_1_END (0)
#define SOC_BISR_CTRL_BISR1_SRAM_RD_SEL_apb_sram_clk_gt_1_START (1)
#define SOC_BISR_CTRL_BISR1_SRAM_RD_SEL_apb_sram_clk_gt_1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_repair_err_msk_1 : 1;
        unsigned int intr_repair_err_clr_1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_BISR_CTRL_BISR1_INTR_CTRL_UNION;
#endif
#define SOC_BISR_CTRL_BISR1_INTR_CTRL_intr_repair_err_msk_1_START (0)
#define SOC_BISR_CTRL_BISR1_INTR_CTRL_intr_repair_err_msk_1_END (0)
#define SOC_BISR_CTRL_BISR1_INTR_CTRL_intr_repair_err_clr_1_START (1)
#define SOC_BISR_CTRL_BISR1_INTR_CTRL_intr_repair_err_clr_1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_dbg_info_1_0 : 32;
    } reg;
} SOC_BISR_CTRL_BISR1_DBG_STATUS_0_UNION;
#endif
#define SOC_BISR_CTRL_BISR1_DBG_STATUS_0_bisr_dbg_info_1_0_START (0)
#define SOC_BISR_CTRL_BISR1_DBG_STATUS_0_bisr_dbg_info_1_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bisr_dbg_info_1_1 : 32;
    } reg;
} SOC_BISR_CTRL_BISR1_DBG_STATUS_1_UNION;
#endif
#define SOC_BISR_CTRL_BISR1_DBG_STATUS_1_bisr_dbg_info_1_1_START (0)
#define SOC_BISR_CTRL_BISR1_DBG_STATUS_1_bisr_dbg_info_1_1_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
