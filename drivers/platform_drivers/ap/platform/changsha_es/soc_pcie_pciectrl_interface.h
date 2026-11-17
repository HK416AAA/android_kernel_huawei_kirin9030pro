#ifndef __SOC_PCIE_PCIECTRL_INTERFACE_H__
#define __SOC_PCIE_PCIECTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL0_ADDR(base) ((base) + (0x000UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL1_ADDR(base) ((base) + (0x004UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL2_ADDR(base) ((base) + (0x008UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_ADDR(base) ((base) + (0x00CUL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL4_ADDR(base) ((base) + (0x010UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL5_ADDR(base) ((base) + (0x014UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_ADDR(base) ((base) + (0x018UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_ADDR(base) ((base) + (0x01CUL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_ADDR(base) ((base) + (0x020UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_ADDR(base) ((base) + (0x024UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_ADDR(base) ((base) + (0x028UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_ADDR(base) ((base) + (0x02CUL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_ADDR(base) ((base) + (0x030UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_ADDR(base) ((base) + (0x034UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL14_ADDR(base) ((base) + (0x038UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_ADDR(base) ((base) + (0x03CUL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL16_ADDR(base) ((base) + (0x040UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL17_ADDR(base) ((base) + (0x044UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL18_ADDR(base) ((base) + (0x048UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_ADDR(base) ((base) + (0x04CUL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_ADDR(base) ((base) + (0x50UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_ADDR(base) ((base) + (0x054UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL22_ADDR(base) ((base) + (0x0058UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL23_ADDR(base) ((base) + (0x05CUL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL24_ADDR(base) ((base) + (0x060UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL25_ADDR(base) ((base) + (0x064UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_ADDR(base) ((base) + (0x0068UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL27_ADDR(base) ((base) + (0x006CUL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL28_ADDR(base) ((base) + (0x0070UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL29_ADDR(base) ((base) + (0x0074UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL30_ADDR(base) ((base) + (0x0078UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_ADDR(base) ((base) + (0x400UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_ADDR(base) ((base) + (0x404UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT2_ADDR(base) ((base) + (0x408UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT3_ADDR(base) ((base) + (0x40CUL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_ADDR(base) ((base) + (0x410UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_ADDR(base) ((base) + (0x414UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_ADDR(base) ((base) + (0x418UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT7_ADDR(base) ((base) + (0x41CUL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT8_ADDR(base) ((base) + (0x420UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT9_ADDR(base) ((base) + (0x424UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_ADDR(base) ((base) + (0x428UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT11_ADDR(base) ((base) + (0x42CUL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT12_ADDR(base) ((base) + (0x430UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT13_ADDR(base) ((base) + (0x434UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT14_ADDR(base) ((base) + (0x438UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_ADDR(base) ((base) + (0x43CUL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT16_ADDR(base) ((base) + (0x440UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT17_ADDR(base) ((base) + (0x444UL))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT18_ADDR(base) ((base) + (0x448UL))
#else
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL0_ADDR(base) ((base) + (0x000))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL1_ADDR(base) ((base) + (0x004))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL2_ADDR(base) ((base) + (0x008))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_ADDR(base) ((base) + (0x00C))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL4_ADDR(base) ((base) + (0x010))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL5_ADDR(base) ((base) + (0x014))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_ADDR(base) ((base) + (0x018))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_ADDR(base) ((base) + (0x01C))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_ADDR(base) ((base) + (0x020))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_ADDR(base) ((base) + (0x024))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_ADDR(base) ((base) + (0x028))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_ADDR(base) ((base) + (0x02C))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_ADDR(base) ((base) + (0x030))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_ADDR(base) ((base) + (0x034))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL14_ADDR(base) ((base) + (0x038))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_ADDR(base) ((base) + (0x03C))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL16_ADDR(base) ((base) + (0x040))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL17_ADDR(base) ((base) + (0x044))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL18_ADDR(base) ((base) + (0x048))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_ADDR(base) ((base) + (0x04C))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_ADDR(base) ((base) + (0x50))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_ADDR(base) ((base) + (0x054))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL22_ADDR(base) ((base) + (0x0058))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL23_ADDR(base) ((base) + (0x05C))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL24_ADDR(base) ((base) + (0x060))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL25_ADDR(base) ((base) + (0x064))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_ADDR(base) ((base) + (0x0068))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL27_ADDR(base) ((base) + (0x006C))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL28_ADDR(base) ((base) + (0x0070))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL29_ADDR(base) ((base) + (0x0074))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL30_ADDR(base) ((base) + (0x0078))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_ADDR(base) ((base) + (0x400))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_ADDR(base) ((base) + (0x404))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT2_ADDR(base) ((base) + (0x408))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT3_ADDR(base) ((base) + (0x40C))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_ADDR(base) ((base) + (0x410))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_ADDR(base) ((base) + (0x414))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_ADDR(base) ((base) + (0x418))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT7_ADDR(base) ((base) + (0x41C))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT8_ADDR(base) ((base) + (0x420))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT9_ADDR(base) ((base) + (0x424))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_ADDR(base) ((base) + (0x428))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT11_ADDR(base) ((base) + (0x42C))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT12_ADDR(base) ((base) + (0x430))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT13_ADDR(base) ((base) + (0x434))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT14_ADDR(base) ((base) + (0x438))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_ADDR(base) ((base) + (0x43C))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT16_ADDR(base) ((base) + (0x440))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT17_ADDR(base) ((base) + (0x444))
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT18_ADDR(base) ((base) + (0x448))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_slv_awmisc_info : 22;
        unsigned int reserved_0 : 2;
        unsigned int app_sris_mode : 1;
        unsigned int reserved_1 : 3;
        unsigned int pcie_device_type : 4;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL0_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL0_pcie_slv_awmisc_info_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL0_pcie_slv_awmisc_info_END (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL0_app_sris_mode_START (24)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL0_app_sris_mode_END (24)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL0_pcie_device_type_START (28)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL0_pcie_device_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_slv_armisc_info : 22;
        unsigned int reserved : 1;
        unsigned int pcie_app_clk_req_n : 1;
        unsigned int pcie_ven_msg_code : 8;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL1_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL1_pcie_slv_armisc_info_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL1_pcie_slv_armisc_info_END (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL1_pcie_app_clk_req_n_START (23)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL1_pcie_app_clk_req_n_END (23)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL1_pcie_ven_msg_code_START (24)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL1_pcie_ven_msg_code_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 14;
        unsigned int pcie_mstr_rmisc_info : 12;
        unsigned int pcie_ven_msi_req : 1;
        unsigned int pcie_ven_msi_vector : 5;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL2_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL2_pcie_mstr_rmisc_info_START (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL2_pcie_mstr_rmisc_info_END (25)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL2_pcie_ven_msi_req_START (26)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL2_pcie_ven_msi_req_END (26)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL2_pcie_ven_msi_vector_START (27)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL2_pcie_ven_msi_vector_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_ven_msg_req : 1;
        unsigned int pcie_ven_msg_fmt : 2;
        unsigned int pcie_ven_msg_type : 5;
        unsigned int pcie_ven_msg_td : 1;
        unsigned int pcie_ven_msg_ep : 1;
        unsigned int pcie_ven_msg_attr : 2;
        unsigned int pcie_ven_msg_len : 10;
        unsigned int pcie_ven_msg_tag : 8;
        unsigned int reserved : 2;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_req_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_req_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_fmt_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_fmt_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_type_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_type_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_td_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_td_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_ep_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_ep_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_attr_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_attr_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_len_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_len_END (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_tag_START (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL3_pcie_ven_msg_tag_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pice_ven_msg_data_low : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL4_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL4_pice_ven_msg_data_low_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL4_pice_ven_msg_data_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pice_ven_msg_data_high : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL5_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL5_pice_ven_msg_data_high_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL5_pice_ven_msg_data_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_postpone_hotreset : 1;
        unsigned int sc_postpone_retrain : 1;
        unsigned int sc_exit_flushing : 1;
        unsigned int sc_link_retrain : 1;
        unsigned int reserved_0 : 4;
        unsigned int sc_app_xfer_pending : 1;
        unsigned int reserved_1 : 7;
        unsigned int wake_deass_pulse : 1;
        unsigned int wake_deass_sel : 2;
        unsigned int reserved_2 : 1;
        unsigned int wake_mask_for_obff_dec : 1;
        unsigned int wake_intr_clear_sel : 1;
        unsigned int app_dbi_ro_wr_disable : 1;
        unsigned int reserved_3 : 9;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_sc_postpone_hotreset_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_sc_postpone_hotreset_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_sc_postpone_retrain_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_sc_postpone_retrain_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_sc_exit_flushing_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_sc_exit_flushing_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_sc_link_retrain_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_sc_link_retrain_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_sc_app_xfer_pending_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_sc_app_xfer_pending_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_wake_deass_pulse_START (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_wake_deass_pulse_END (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_wake_deass_sel_START (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_wake_deass_sel_END (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_wake_mask_for_obff_dec_START (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_wake_mask_for_obff_dec_END (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_wake_intr_clear_sel_START (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_wake_intr_clear_sel_END (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_app_dbi_ro_wr_disable_START (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL6_app_dbi_ro_wr_disable_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_app_init_rst : 1;
        unsigned int pcie_app_req_entr_l1 : 1;
        unsigned int pcie_app_ready_entr_l23 : 1;
        unsigned int pcie_app_req_exit_l1 : 1;
        unsigned int pcie_app_req_retry_en : 1;
        unsigned int pcie_sys_int : 1;
        unsigned int pcie_outband_pwrup_cmd : 1;
        unsigned int pcie_app_unlock_msg : 1;
        unsigned int pcie_apps_pm_xmt_turnoff : 1;
        unsigned int pcie_apps_pm_xmt_pme : 1;
        unsigned int pcie_sys_aux_pwr_det : 1;
        unsigned int pcie_app_ltssm_enable : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int pcie_sys_mrl_sensor_state : 1;
        unsigned int pcie_sys_pwr_fault_det : 1;
        unsigned int pcie_sys_mrl_sensor_chged : 1;
        unsigned int reserved_2 : 1;
        unsigned int pcie_sys_cmd_cpled_int : 1;
        unsigned int pcie_sys_eml_interlock_engaged : 1;
        unsigned int reserved_3 : 1;
        unsigned int pcie_int_ctrl : 8;
        unsigned int reserved_4 : 1;
        unsigned int pcie_err_bresp_enable : 1;
        unsigned int pipe_err_rresp_enable : 1;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_init_rst_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_init_rst_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_req_entr_l1_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_req_entr_l1_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_ready_entr_l23_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_ready_entr_l23_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_req_exit_l1_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_req_exit_l1_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_req_retry_en_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_req_retry_en_END (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_int_START (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_int_END (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_outband_pwrup_cmd_START (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_outband_pwrup_cmd_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_unlock_msg_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_unlock_msg_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_apps_pm_xmt_turnoff_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_apps_pm_xmt_turnoff_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_apps_pm_xmt_pme_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_apps_pm_xmt_pme_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_aux_pwr_det_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_aux_pwr_det_END (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_ltssm_enable_START (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_app_ltssm_enable_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_mrl_sensor_state_START (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_mrl_sensor_state_END (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_pwr_fault_det_START (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_pwr_fault_det_END (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_mrl_sensor_chged_START (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_mrl_sensor_chged_END (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_cmd_cpled_int_START (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_cmd_cpled_int_END (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_eml_interlock_engaged_START (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_sys_eml_interlock_engaged_END (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_int_ctrl_START (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_int_ctrl_END (28)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_err_bresp_enable_START (30)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pcie_err_bresp_enable_END (30)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pipe_err_rresp_enable_START (31)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL7_pipe_err_rresp_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int pcie_state2_sel : 2;
        unsigned int pcie_state3_sel : 2;
        unsigned int reserved_3 : 1;
        unsigned int cfg_crs_sw_vis_en_mask : 1;
        unsigned int flush_done_mask : 1;
        unsigned int cfg_br_ctrl_serren_mask : 1;
        unsigned int cfg_hp_slot_ctrl_access_mask : 1;
        unsigned int cfg_dll_state_chged_en_mask : 1;
        unsigned int cfg_cmd_cpled_int_en_mask : 1;
        unsigned int cfg_hp_int_en_mask : 1;
        unsigned int cfg_pre_det_chged_en_mask : 1;
        unsigned int cfg_mrl_sensor_chged_en_mask : 1;
        unsigned int cfg_pwr_fault_det_en_mask : 1;
        unsigned int cfg_atten_button_pressed_en_mask : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_pcie_state2_sel_START (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_pcie_state2_sel_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_pcie_state3_sel_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_pcie_state3_sel_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_crs_sw_vis_en_mask_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_crs_sw_vis_en_mask_END (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_flush_done_mask_START (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_flush_done_mask_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_br_ctrl_serren_mask_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_br_ctrl_serren_mask_END (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_hp_slot_ctrl_access_mask_START (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_hp_slot_ctrl_access_mask_END (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_dll_state_chged_en_mask_START (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_dll_state_chged_en_mask_END (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_cmd_cpled_int_en_mask_START (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_cmd_cpled_int_en_mask_END (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_hp_int_en_mask_START (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_hp_int_en_mask_END (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_pre_det_chged_en_mask_START (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_pre_det_chged_en_mask_END (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_mrl_sensor_chged_en_mask_START (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_mrl_sensor_chged_en_mask_END (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_pwr_fault_det_en_mask_START (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_pwr_fault_det_en_mask_END (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_atten_button_pressed_en_mask_START (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL8_cfg_atten_button_pressed_en_mask_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 10;
        unsigned int cfg_crs_sw_vis_en : 1;
        unsigned int flush_done : 1;
        unsigned int cfg_br_ctrl_serren : 1;
        unsigned int cfg_hp_slot_ctrl_access : 1;
        unsigned int cfg_dll_state_chged_en : 1;
        unsigned int cfg_cmd_cpled_int_en : 1;
        unsigned int cfg_hp_int_en : 1;
        unsigned int cfg_pre_det_chged_en : 1;
        unsigned int cfg_mrl_sensor_chged_en : 1;
        unsigned int cfg_pwr_fault_det_en : 1;
        unsigned int cfg_atten_button_pressed_en : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_crs_sw_vis_en_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_crs_sw_vis_en_END (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_flush_done_START (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_flush_done_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_br_ctrl_serren_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_br_ctrl_serren_END (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_hp_slot_ctrl_access_START (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_hp_slot_ctrl_access_END (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_dll_state_chged_en_START (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_dll_state_chged_en_END (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_cmd_cpled_int_en_START (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_cmd_cpled_int_en_END (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_hp_int_en_START (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_hp_int_en_END (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_pre_det_chged_en_START (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_pre_det_chged_en_END (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_mrl_sensor_chged_en_START (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_mrl_sensor_chged_en_END (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_pwr_fault_det_en_START (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_pwr_fault_det_en_END (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_atten_button_pressed_en_START (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL9_cfg_atten_button_pressed_en_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_aer_rc_err_msi_mask : 1;
        unsigned int cfg_sys_err_rc_mask : 1;
        unsigned int radm_correctable_err_mask : 1;
        unsigned int radm_nonfatal_err_mask : 1;
        unsigned int radm_fatal_err_mask : 1;
        unsigned int radm_pm_pme_mask : 1;
        unsigned int radm_pm_to_ack_mask : 1;
        unsigned int ven_msg_int_mask : 1;
        unsigned int radm_cpl_timeout_mask : 1;
        unsigned int radm_msg_unlock_mask : 1;
        unsigned int cfg_pme_msi_mask : 1;
        unsigned int smlh_req_rst_not_intr_mask : 1;
        unsigned int link_req_rst_not_mask : 1;
        unsigned int pcie_p2_exit_reg_mask : 1;
        unsigned int reserved_0 : 7;
        unsigned int pcie_radm_pm_turnoff_mask : 1;
        unsigned int pcie_axi_timeout_mask : 1;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_cfg_aer_rc_err_msi_mask_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_cfg_aer_rc_err_msi_mask_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_cfg_sys_err_rc_mask_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_cfg_sys_err_rc_mask_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_correctable_err_mask_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_correctable_err_mask_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_nonfatal_err_mask_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_nonfatal_err_mask_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_fatal_err_mask_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_fatal_err_mask_END (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_pm_pme_mask_START (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_pm_pme_mask_END (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_pm_to_ack_mask_START (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_pm_to_ack_mask_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_ven_msg_int_mask_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_ven_msg_int_mask_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_cpl_timeout_mask_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_cpl_timeout_mask_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_msg_unlock_mask_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_radm_msg_unlock_mask_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_cfg_pme_msi_mask_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_cfg_pme_msi_mask_END (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_smlh_req_rst_not_intr_mask_START (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_smlh_req_rst_not_intr_mask_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_link_req_rst_not_mask_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_link_req_rst_not_mask_END (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_pcie_p2_exit_reg_mask_START (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_pcie_p2_exit_reg_mask_END (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_pcie_radm_pm_turnoff_mask_START (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_pcie_radm_pm_turnoff_mask_END (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_pcie_axi_timeout_mask_START (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL10_pcie_axi_timeout_mask_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_cfg_aer_rc_msi_clr : 1;
        unsigned int pcie_cfg_sys_err_rc_clr : 1;
        unsigned int pcie_radm_corretable_err_clr : 1;
        unsigned int pcie_radm_nonfatal_err_clr : 1;
        unsigned int pcie_radm_fatal_err_clr : 1;
        unsigned int pcie_radm_pm_pme_clr : 1;
        unsigned int pcie_radm_pm_to_ack_clr : 1;
        unsigned int pcie_ven_msg_int_clr : 1;
        unsigned int pcie_radm_cpl_timeout_clr : 1;
        unsigned int pcie_radm_msg_unlock_clr : 1;
        unsigned int pcie_cfg_pme_msi_clr : 1;
        unsigned int shlm_req_rst_not_intr_clr : 1;
        unsigned int pcie_link_req_rst_not_clr : 1;
        unsigned int pcie_p2_exit_int_clr : 1;
        unsigned int pcie_slv_err_int_clr : 1;
        unsigned int pcie_ven_msi_func_num : 3;
        unsigned int pcie_ven_msg_func_num : 3;
        unsigned int pcie_radm_pm_turnoff_clr : 1;
        unsigned int pcie_ax_timeout_clr : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_cfg_aer_rc_msi_clr_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_cfg_aer_rc_msi_clr_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_cfg_sys_err_rc_clr_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_cfg_sys_err_rc_clr_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_corretable_err_clr_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_corretable_err_clr_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_nonfatal_err_clr_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_nonfatal_err_clr_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_fatal_err_clr_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_fatal_err_clr_END (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_pm_pme_clr_START (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_pm_pme_clr_END (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_pm_to_ack_clr_START (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_pm_to_ack_clr_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_ven_msg_int_clr_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_ven_msg_int_clr_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_cpl_timeout_clr_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_cpl_timeout_clr_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_msg_unlock_clr_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_msg_unlock_clr_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_cfg_pme_msi_clr_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_cfg_pme_msi_clr_END (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_shlm_req_rst_not_intr_clr_START (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_shlm_req_rst_not_intr_clr_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_link_req_rst_not_clr_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_link_req_rst_not_clr_END (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_p2_exit_int_clr_START (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_p2_exit_int_clr_END (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_slv_err_int_clr_START (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_slv_err_int_clr_END (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_ven_msi_func_num_START (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_ven_msi_func_num_END (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_ven_msg_func_num_START (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_ven_msg_func_num_END (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_pm_turnoff_clr_START (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_radm_pm_turnoff_clr_END (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_ax_timeout_clr_START (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL11_pcie_ax_timeout_clr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_perst_out_n : 1;
        unsigned int pcie_perst_oe : 1;
        unsigned int pcie_perst_in_n_ctrl : 2;
        unsigned int reserved_0 : 8;
        unsigned int rc_wake_n_ctrl : 1;
        unsigned int ep_wake_n_ctrl : 1;
        unsigned int obff_enc_owre_wake_ctrl : 1;
        unsigned int dwc_pcie_dm_wake_n_ctrl : 2;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 5;
        unsigned int reserved_3 : 7;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_pcie_perst_out_n_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_pcie_perst_out_n_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_pcie_perst_oe_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_pcie_perst_oe_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_pcie_perst_in_n_ctrl_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_pcie_perst_in_n_ctrl_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_rc_wake_n_ctrl_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_rc_wake_n_ctrl_END (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_ep_wake_n_ctrl_START (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_ep_wake_n_ctrl_END (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_obff_enc_owre_wake_ctrl_START (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_obff_enc_owre_wake_ctrl_END (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_dwc_pcie_dm_wake_n_ctrl_START (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL12_dwc_pcie_dm_wake_n_ctrl_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int obff_dec_app_init : 1;
        unsigned int obff_dec_app_idle : 1;
        unsigned int obff_dec_app_obff : 1;
        unsigned int obff_dec_app_cpu_act : 1;
        unsigned int obff_enc_app_owre_idle : 1;
        unsigned int obff_enc_app_owre_obff : 1;
        unsigned int obff_enc_app_owre_cpu_act : 1;
        unsigned int app_obff_idle_msg_req : 1;
        unsigned int app_obff_obff_msg_req : 1;
        unsigned int app_obff_cpu_active_msg_req : 1;
        unsigned int app_ltr_msg_req : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_dec_app_init_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_dec_app_init_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_dec_app_idle_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_dec_app_idle_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_dec_app_obff_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_dec_app_obff_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_dec_app_cpu_act_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_dec_app_cpu_act_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_enc_app_owre_idle_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_enc_app_owre_idle_END (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_enc_app_owre_obff_START (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_enc_app_owre_obff_END (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_enc_app_owre_cpu_act_START (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_obff_enc_app_owre_cpu_act_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_app_obff_idle_msg_req_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_app_obff_idle_msg_req_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_app_obff_obff_msg_req_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_app_obff_obff_msg_req_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_app_obff_cpu_active_msg_req_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_app_obff_cpu_active_msg_req_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_app_ltr_msg_req_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL13_app_ltr_msg_req_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int obff_cfg_wk_max_pls_wdt : 8;
        unsigned int obff_cfg_wk_min_pls_wdt : 8;
        unsigned int obff_cfg_wk_max_f2f_wdt : 8;
        unsigned int obff_cfg_wk_min_f2f_wdt : 8;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL14_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL14_obff_cfg_wk_max_pls_wdt_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL14_obff_cfg_wk_max_pls_wdt_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL14_obff_cfg_wk_min_pls_wdt_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL14_obff_cfg_wk_min_pls_wdt_END (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL14_obff_cfg_wk_max_f2f_wdt_START (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL14_obff_cfg_wk_max_f2f_wdt_END (23)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL14_obff_cfg_wk_min_f2f_wdt_START (24)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL14_obff_cfg_wk_min_f2f_wdt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int obff_dec_idle_intr_mask : 1;
        unsigned int obff_dec_obff_intr_mask : 1;
        unsigned int obff_dec_cpu_active_intr_mask : 1;
        unsigned int obff_dec_err_intr_mask : 1;
        unsigned int obff_msg_idle_intr_mask : 1;
        unsigned int obff_msg_obff_intr_mask : 1;
        unsigned int obff_msg_cpu_active_intr_mask : 1;
        unsigned int radm_msg_ltr_intr_mask : 1;
        unsigned int cfg_msi_mask_chg_intr_mask : 1;
        unsigned int radm_qoverflow_intr_mask : 1;
        unsigned int wake_intr_mask : 1;
        unsigned int pcie_clkreq_in_n_intr_mask : 1;
        unsigned int pcie_clkreq_in_n_inv_intr_mask : 1;
        unsigned int pcie_v7r3_intr_mask : 1;
        unsigned int reserved_0 : 2;
        unsigned int obff_dec_idle_intr_clear : 1;
        unsigned int obff_dec_obff_intr_clear : 1;
        unsigned int obff_dec_cpu_active_intr_clear : 1;
        unsigned int obff_dec_err_intr_clear : 1;
        unsigned int obff_msg_idle_intr_clear : 1;
        unsigned int obff_msg_obff_intr_clear : 1;
        unsigned int obff_msg_cpu_active_intr_clear : 1;
        unsigned int radm_msg_ltr_intr_clear : 1;
        unsigned int cfg_msi_mask_chg_intr_clear : 1;
        unsigned int radm_qoverflow_intr_clear : 1;
        unsigned int wake_intr_clear : 1;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_idle_intr_mask_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_idle_intr_mask_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_obff_intr_mask_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_obff_intr_mask_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_cpu_active_intr_mask_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_cpu_active_intr_mask_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_err_intr_mask_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_err_intr_mask_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_idle_intr_mask_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_idle_intr_mask_END (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_obff_intr_mask_START (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_obff_intr_mask_END (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_cpu_active_intr_mask_START (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_cpu_active_intr_mask_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_radm_msg_ltr_intr_mask_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_radm_msg_ltr_intr_mask_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_cfg_msi_mask_chg_intr_mask_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_cfg_msi_mask_chg_intr_mask_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_radm_qoverflow_intr_mask_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_radm_qoverflow_intr_mask_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_wake_intr_mask_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_wake_intr_mask_END (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_pcie_clkreq_in_n_intr_mask_START (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_pcie_clkreq_in_n_intr_mask_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_pcie_clkreq_in_n_inv_intr_mask_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_pcie_clkreq_in_n_inv_intr_mask_END (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_pcie_v7r3_intr_mask_START (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_pcie_v7r3_intr_mask_END (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_idle_intr_clear_START (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_idle_intr_clear_END (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_obff_intr_clear_START (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_obff_intr_clear_END (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_cpu_active_intr_clear_START (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_cpu_active_intr_clear_END (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_err_intr_clear_START (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_dec_err_intr_clear_END (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_idle_intr_clear_START (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_idle_intr_clear_END (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_obff_intr_clear_START (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_obff_intr_clear_END (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_cpu_active_intr_clear_START (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_obff_msg_cpu_active_intr_clear_END (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_radm_msg_ltr_intr_clear_START (23)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_radm_msg_ltr_intr_clear_END (23)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_cfg_msi_mask_chg_intr_clear_START (24)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_cfg_msi_mask_chg_intr_clear_END (24)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_radm_qoverflow_intr_clear_START (25)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_radm_qoverflow_intr_clear_END (25)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_wake_intr_clear_START (26)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL15_wake_intr_clear_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_msi_pending : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL16_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL16_cfg_msi_pending_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL16_cfg_msi_pending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int app_ltr_msg_latency : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL17_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL17_app_ltr_msg_latency_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL17_app_ltr_msg_latency_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pwr_budget_data_reg : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL18_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL18_cfg_pwr_budget_data_reg_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL18_cfg_pwr_budget_data_reg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int app_ltr_msg_func_num : 3;
        unsigned int reserved_0 : 1;
        unsigned int cfg_pwr_budget_func_num : 3;
        unsigned int slv_awmisc_info_atu_bypass : 1;
        unsigned int slv_armisc_info_atu_bypass : 1;
        unsigned int app_clk_pm_en : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_app_ltr_msg_func_num_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_app_ltr_msg_func_num_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_cfg_pwr_budget_func_num_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_cfg_pwr_budget_func_num_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_slv_awmisc_info_atu_bypass_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_slv_awmisc_info_atu_bypass_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_slv_armisc_info_atu_bypass_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_slv_armisc_info_atu_bypass_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_app_clk_pm_en_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL19_app_clk_pm_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_sys_ctrl20_15_0_1_0 : 2;
        unsigned int pcie_sys_ctrl20_15_0_3_2 : 2;
        unsigned int pcie_sys_ctrl20_15_0_5_4 : 2;
        unsigned int pcie_sys_ctrl20_15_0_7_6 : 2;
        unsigned int reserved : 8;
        unsigned int mem_ctrl_d1w2r : 16;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_pcie_sys_ctrl20_15_0_1_0_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_pcie_sys_ctrl20_15_0_1_0_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_pcie_sys_ctrl20_15_0_3_2_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_pcie_sys_ctrl20_15_0_3_2_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_pcie_sys_ctrl20_15_0_5_4_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_pcie_sys_ctrl20_15_0_5_4_END (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_pcie_sys_ctrl20_15_0_7_6_START (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_pcie_sys_ctrl20_15_0_7_6_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_mem_ctrl_d1w2r_START (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL20_mem_ctrl_d1w2r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DS0 : 3;
        unsigned int ODT[1:0] : 2;
        unsigned int ODT_EN : 1;
        unsigned int PE : 1;
        unsigned int PSN : 1;
        unsigned int PSP : 1;
        unsigned int SPU : 1;
        unsigned int SR : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_DS0_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_DS0_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_ODT [1:0]_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_ODT [1:0]_END (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_ODT_EN_START (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_ODT_EN_END (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_PE_START (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_PE_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_PSN_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_PSN_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_PSP_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_PSP_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_SPU_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_SPU_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_SR_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL21_SR_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_clkreq_out_n_ctrl_0 : 1;
        unsigned int pcie_clkreq_out_n_ctrl_1 : 1;
        unsigned int reserved_0 : 14;
        unsigned int pcie_ctrl_por_n_ctrl : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL22_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL22_pcie_clkreq_out_n_ctrl_0_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL22_pcie_clkreq_out_n_ctrl_0_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL22_pcie_clkreq_out_n_ctrl_1_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL22_pcie_clkreq_out_n_ctrl_1_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL22_pcie_ctrl_por_n_ctrl_START (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL22_pcie_ctrl_por_n_ctrl_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL23_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL23_mem_ctrl_s_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL23_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_ctrl_sys_ctrl24[0] : 1;
        unsigned int pcie_ctrl_sys_ctrl24[1] : 1;
        unsigned int pcie_ctrl_sys_ctrl24[2] : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL24_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL24_pcie_ctrl_sys_ctrl24 [0]_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL24_pcie_ctrl_sys_ctrl24 [0]_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL24_pcie_ctrl_sys_ctrl24 [1]_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL24_pcie_ctrl_sys_ctrl24 [1]_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL24_pcie_ctrl_sys_ctrl24 [2]_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL24_pcie_ctrl_sys_ctrl24 [2]_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_ctrl_bus_timeout_bypass : 1;
        unsigned int pcie_ctrl_bus_timeout_value : 6;
        unsigned int pcie_ctrl_bus_timeout_div : 8;
        unsigned int pcie_ctrl_bus_timeout_unit_sel : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL25_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL25_pcie_ctrl_bus_timeout_bypass_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL25_pcie_ctrl_bus_timeout_bypass_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL25_pcie_ctrl_bus_timeout_value_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL25_pcie_ctrl_bus_timeout_value_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL25_pcie_ctrl_bus_timeout_div_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL25_pcie_ctrl_bus_timeout_div_END (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL25_pcie_ctrl_bus_timeout_unit_sel_START (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL25_pcie_ctrl_bus_timeout_unit_sel_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1ss_cnt_en : 1;
        unsigned int pcie_100ms_idle_timeout_mask_en : 1;
        unsigned int pcie_l12_wake_int_en : 1;
        unsigned int pcie_l12_wake_mask_en : 1;
        unsigned int cmdq_aw_hs_sel : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_l1ss_cnt_en_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_l1ss_cnt_en_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_pcie_100ms_idle_timeout_mask_en_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_pcie_100ms_idle_timeout_mask_en_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_pcie_l12_wake_int_en_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_pcie_l12_wake_int_en_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_pcie_l12_wake_mask_en_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_pcie_l12_wake_mask_en_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_cmdq_aw_hs_sel_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL26_cmdq_aw_hs_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_100ms_idle_timeout_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL27_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL27_pcie_100ms_idle_timeout_int_clr_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL27_pcie_100ms_idle_timeout_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_l12_wake_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL28_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL28_pcie_l12_wake_int_clr_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL28_pcie_l12_wake_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1ss_cnt_base : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL29_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL29_l1ss_cnt_base_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL29_l1ss_cnt_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_splt_en : 1;
        unsigned int pcie_splt_bypass : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL30_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL30_pcie_splt_en_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL30_pcie_splt_en_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL30_pcie_splt_bypass_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_CTRL30_pcie_splt_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_gm_cmposer_lookup_err : 1;
        unsigned int reserved_0 : 1;
        unsigned int pcie_pm_xtlh_block_tlp : 1;
        unsigned int pcie_cfg_mem_space_en : 1;
        unsigned int pcie_cfg_rcb : 1;
        unsigned int pcie_rdlh_link_up : 1;
        unsigned int pcie_pm_curnt_state : 3;
        unsigned int pcie_cfg_aer_rc_err_int : 1;
        unsigned int pcie_cfg_aer_int_msg_num : 5;
        unsigned int pcie_xmlh_link_up : 1;
        unsigned int reserved_1 : 1;
        unsigned int pcie_cfg_eml_control : 1;
        unsigned int pcie_hp_pme : 1;
        unsigned int pcie_hp_int : 1;
        unsigned int pcie_hp_msi : 1;
        unsigned int pcie_pm_status : 1;
        unsigned int pcie_ref_clk_req_n : 1;
        unsigned int mac_phy_powerdown_p2_exit_reg : 1;
        unsigned int radm_msg_req_id_low : 8;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_gm_cmposer_lookup_err_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_gm_cmposer_lookup_err_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_pm_xtlh_block_tlp_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_pm_xtlh_block_tlp_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_cfg_mem_space_en_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_cfg_mem_space_en_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_cfg_rcb_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_cfg_rcb_END (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_rdlh_link_up_START (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_rdlh_link_up_END (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_pm_curnt_state_START (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_pm_curnt_state_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_cfg_aer_rc_err_int_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_cfg_aer_rc_err_int_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_cfg_aer_int_msg_num_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_cfg_aer_int_msg_num_END (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_xmlh_link_up_START (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_xmlh_link_up_END (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_cfg_eml_control_START (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_cfg_eml_control_END (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_hp_pme_START (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_hp_pme_END (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_hp_int_START (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_hp_int_END (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_hp_msi_START (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_hp_msi_END (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_pm_status_START (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_pm_status_END (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_ref_clk_req_n_START (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_pcie_ref_clk_req_n_END (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_mac_phy_powerdown_p2_exit_reg_START (23)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_mac_phy_powerdown_p2_exit_reg_END (23)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_radm_msg_req_id_low_START (24)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT0_radm_msg_req_id_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_parity_errs_reg : 4;
        unsigned int app_parity_errs_reg : 3;
        unsigned int pm_linkst_in_l1 : 1;
        unsigned int pm_linkst_in_l2 : 1;
        unsigned int pm_linkst_l2_exit : 1;
        unsigned int mac_phy_power_down : 2;
        unsigned int radm_correctabl_err_reg : 1;
        unsigned int radm_nonfatal_err_reg : 1;
        unsigned int radm_fatal_err_reg : 1;
        unsigned int radm_pm_to_pme_reg : 1;
        unsigned int radm_pm_to_ack_reg : 1;
        unsigned int radm_cpl_timeout_reg : 1;
        unsigned int radm_msg_unlock_reg : 1;
        unsigned int cfg_pme_msi_reg : 1;
        unsigned int smlh_req_rst_not_intr_status : 1;
        unsigned int link_req_rst_not_reg : 1;
        unsigned int pcie_cfg_aer_rc_err_msi : 1;
        unsigned int pcie_cfg_sys_err_rc : 1;
        unsigned int radm_msg_req_id_high : 8;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_axi_parity_errs_reg_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_axi_parity_errs_reg_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_app_parity_errs_reg_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_app_parity_errs_reg_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_pm_linkst_in_l1_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_pm_linkst_in_l1_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_pm_linkst_in_l2_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_pm_linkst_in_l2_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_pm_linkst_l2_exit_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_pm_linkst_l2_exit_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_mac_phy_power_down_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_mac_phy_power_down_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_correctabl_err_reg_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_correctabl_err_reg_END (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_nonfatal_err_reg_START (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_nonfatal_err_reg_END (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_fatal_err_reg_START (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_fatal_err_reg_END (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_pm_to_pme_reg_START (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_pm_to_pme_reg_END (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_pm_to_ack_reg_START (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_pm_to_ack_reg_END (16)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_cpl_timeout_reg_START (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_cpl_timeout_reg_END (17)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_msg_unlock_reg_START (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_msg_unlock_reg_END (18)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_cfg_pme_msi_reg_START (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_cfg_pme_msi_reg_END (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_smlh_req_rst_not_intr_status_START (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_smlh_req_rst_not_intr_status_END (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_link_req_rst_not_reg_START (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_link_req_rst_not_reg_END (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_pcie_cfg_aer_rc_err_msi_START (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_pcie_cfg_aer_rc_err_msi_END (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_pcie_cfg_sys_err_rc_START (23)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_pcie_cfg_sys_err_rc_END (23)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_msg_req_id_high_START (24)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT1_radm_msg_req_id_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_stat2 : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT2_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT2_pcie_stat2_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT2_pcie_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_stat3 : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT3_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT3_pcie_stat3_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT3_pcie_stat3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ltssm_state : 6;
        unsigned int mac_phy_rate : 2;
        unsigned int pcie_slv_err_int : 1;
        unsigned int trgt_lookup_empty : 1;
        unsigned int trgt_cpl_timeout_reg : 1;
        unsigned int reserved_0 : 8;
        unsigned int brdg_slv_xfer_pending : 1;
        unsigned int brdg_dbi_xfer_pending : 1;
        unsigned int edma_xfer_pending : 1;
        unsigned int radm_xfer_pending : 1;
        unsigned int pcie_axi_timeout_regr : 1;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_ltssm_state_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_ltssm_state_END (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_mac_phy_rate_START (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_mac_phy_rate_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_pcie_slv_err_int_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_pcie_slv_err_int_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_trgt_lookup_empty_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_trgt_lookup_empty_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_trgt_cpl_timeout_reg_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_trgt_cpl_timeout_reg_END (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_brdg_slv_xfer_pending_START (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_brdg_slv_xfer_pending_END (19)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_brdg_dbi_xfer_pending_START (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_brdg_dbi_xfer_pending_END (20)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_edma_xfer_pending_START (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_edma_xfer_pending_END (21)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_radm_xfer_pending_START (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_radm_xfer_pending_END (22)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_pcie_axi_timeout_regr_START (23)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT4_pcie_axi_timeout_regr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int obff_dec_idle_intr_status : 1;
        unsigned int obff_dec_obff_intr_status : 1;
        unsigned int obff_dec_cpu_active_intr_status : 1;
        unsigned int obff_dec_err_intr_status : 1;
        unsigned int obff_msg_idle_intr_status : 1;
        unsigned int obff_msg_obff_intr_status : 1;
        unsigned int obff_msg_cpu_active_intr_status : 1;
        unsigned int radm_msg_ltr_intr_status : 1;
        unsigned int cfg_msi_mask_chg_intr_status : 1;
        unsigned int radm_qoverflow_intr_status : 1;
        unsigned int wake_intr_status : 1;
        unsigned int pcie_clkreq_in_n_intr_status : 1;
        unsigned int pcie_clkreq_in_n_inv_intr_status : 1;
        unsigned int radm_vendor_msg_intr_status : 1;
        unsigned int mac_phy_rxelecidle_disable : 1;
        unsigned int mac_phy_txcommonmode_disable : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_dec_idle_intr_status_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_dec_idle_intr_status_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_dec_obff_intr_status_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_dec_obff_intr_status_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_dec_cpu_active_intr_status_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_dec_cpu_active_intr_status_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_dec_err_intr_status_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_dec_err_intr_status_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_msg_idle_intr_status_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_msg_idle_intr_status_END (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_msg_obff_intr_status_START (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_msg_obff_intr_status_END (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_msg_cpu_active_intr_status_START (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_obff_msg_cpu_active_intr_status_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_radm_msg_ltr_intr_status_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_radm_msg_ltr_intr_status_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_cfg_msi_mask_chg_intr_status_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_cfg_msi_mask_chg_intr_status_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_radm_qoverflow_intr_status_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_radm_qoverflow_intr_status_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_wake_intr_status_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_wake_intr_status_END (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_pcie_clkreq_in_n_intr_status_START (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_pcie_clkreq_in_n_intr_status_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_pcie_clkreq_in_n_inv_intr_status_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_pcie_clkreq_in_n_inv_intr_status_END (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_radm_vendor_msg_intr_status_START (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_radm_vendor_msg_intr_status_END (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_mac_phy_rxelecidle_disable_START (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_mac_phy_rxelecidle_disable_END (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_mac_phy_txcommonmode_disable_START (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT5_mac_phy_txcommonmode_disable_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int obff_dec_owrd_cur_state : 4;
        unsigned int obff_enc_owre_cur_state : 4;
        unsigned int cfg_obff_en : 2;
        unsigned int cfg_ltr_m_en : 1;
        unsigned int cfg_pwr_budget_sel : 1;
        unsigned int smlh_in_rl0s : 1;
        unsigned int radm_qoverflow : 1;
        unsigned int reserved_0 : 1;
        unsigned int pcie_pm_linkst_in_l1sub : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_obff_dec_owrd_cur_state_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_obff_dec_owrd_cur_state_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_obff_enc_owre_cur_state_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_obff_enc_owre_cur_state_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_cfg_obff_en_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_cfg_obff_en_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_cfg_ltr_m_en_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_cfg_ltr_m_en_END (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_cfg_pwr_budget_sel_START (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_cfg_pwr_budget_sel_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_smlh_in_rl0s_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_smlh_in_rl0s_END (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_radm_qoverflow_START (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_radm_qoverflow_END (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_pcie_pm_linkst_in_l1sub_START (15)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT6_pcie_pm_linkst_in_l1sub_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_msi_mask : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT7_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT7_cfg_msi_mask_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT7_cfg_msi_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ltr_max_latency : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT8_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT8_cfg_ltr_max_latency_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT8_cfg_ltr_max_latency_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int app_ltr_latency : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT9_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT9_app_ltr_latency_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT9_app_ltr_latency_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_down_flushing_fsm_state : 4;
        unsigned int cfg_crs_sw_vis_en_state : 1;
        unsigned int flush_done_state : 1;
        unsigned int cfg_br_ctrl_serren_state : 1;
        unsigned int cfg_hp_slot_ctrl_access_state : 1;
        unsigned int cfg_dll_state_chged_en_state : 1;
        unsigned int cfg_cmd_cpled_int_en_state : 1;
        unsigned int cfg_hp_int_en_state : 1;
        unsigned int cfg_pre_det_chged_en_state : 1;
        unsigned int cfg_mrl_sensor_chged_en_state : 1;
        unsigned int cfg_pwr_fault_det_en_state : 1;
        unsigned int cfg_atten_button_pressed_en_state : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_link_down_flushing_fsm_state_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_link_down_flushing_fsm_state_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_crs_sw_vis_en_state_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_crs_sw_vis_en_state_END (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_flush_done_state_START (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_flush_done_state_END (5)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_br_ctrl_serren_state_START (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_br_ctrl_serren_state_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_hp_slot_ctrl_access_state_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_hp_slot_ctrl_access_state_END (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_dll_state_chged_en_state_START (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_dll_state_chged_en_state_END (8)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_cmd_cpled_int_en_state_START (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_cmd_cpled_int_en_state_END (9)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_hp_int_en_state_START (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_hp_int_en_state_END (10)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_pre_det_chged_en_state_START (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_pre_det_chged_en_state_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_mrl_sensor_chged_en_state_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_mrl_sensor_chged_en_state_END (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_pwr_fault_det_en_state_START (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_pwr_fault_det_en_state_END (13)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_atten_button_pressed_en_state_START (14)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT10_cfg_atten_button_pressed_en_state_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_axi_read_pending_request : 1;
        unsigned int pcie_axi_write_pending_request : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT11_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT11_pcie_axi_read_pending_request_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT11_pcie_axi_read_pending_request_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT11_pcie_axi_write_pending_request_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT11_pcie_axi_write_pending_request_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int TX_P_DATA_FC_CREDIT : 12;
        unsigned int TX_P_HEADER_FC_CREDIT : 8;
        unsigned int reserved : 12;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT12_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT12_TX_P_DATA_FC_CREDIT_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT12_TX_P_DATA_FC_CREDIT_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT12_TX_P_HEADER_FC_CREDIT_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT12_TX_P_HEADER_FC_CREDIT_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int TX_NP_DATA_FC_CREDIT : 12;
        unsigned int TX_NP_HEADER_FC_CREDIT : 8;
        unsigned int reserved : 12;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT13_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT13_TX_NP_DATA_FC_CREDIT_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT13_TX_NP_DATA_FC_CREDIT_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT13_TX_NP_HEADER_FC_CREDIT_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT13_TX_NP_HEADER_FC_CREDIT_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int TX_CPL_DATA_FC_CREDIT : 12;
        unsigned int TX_CPL_HEADER_FC_CREDIT : 8;
        unsigned int reserved : 12;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT14_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT14_TX_CPL_DATA_FC_CREDIT_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT14_TX_CPL_DATA_FC_CREDIT_END (11)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT14_TX_CPL_HEADER_FC_CREDIT_START (12)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT14_TX_CPL_HEADER_FC_CREDIT_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xdlh_nodllp_pending : 1;
        unsigned int xdlh_not_expecting_ack : 1;
        unsigned int xadm_had_enough_credit : 1;
        unsigned int xadm_notlp_pending : 1;
        unsigned int xadm_no_fc_credit : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_xdlh_nodllp_pending_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_xdlh_nodllp_pending_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_xdlh_not_expecting_ack_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_xdlh_not_expecting_ack_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_xadm_had_enough_credit_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_xadm_had_enough_credit_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_xadm_notlp_pending_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_xadm_notlp_pending_END (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_xadm_no_fc_credit_START (4)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT15_xadm_no_fc_credit_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pm_l1sub_state : 3;
        unsigned int pm_slave_state : 4;
        unsigned int pm_master_state : 5;
        unsigned int reserved : 20;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT16_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT16_pm_l1sub_state_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT16_pm_l1sub_state_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT16_pm_slave_state_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT16_pm_slave_state_END (6)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT16_pm_master_state_START (7)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT16_pm_master_state_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_100ms_idle_timeout_intr : 1;
        unsigned int pcie_100ms_idle_timeout_intr_mask : 1;
        unsigned int pcie_l12_wake_int : 1;
        unsigned int pcie_l12_wake_int_mask : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT17_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT17_pcie_100ms_idle_timeout_intr_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT17_pcie_100ms_idle_timeout_intr_END (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT17_pcie_100ms_idle_timeout_intr_mask_START (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT17_pcie_100ms_idle_timeout_intr_mask_END (1)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT17_pcie_l12_wake_int_START (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT17_pcie_l12_wake_int_END (2)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT17_pcie_l12_wake_int_mask_START (3)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT17_pcie_l12_wake_int_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1ss_cnt_reg : 32;
    } reg;
} SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT18_UNION;
#endif
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT18_l1ss_cnt_reg_START (0)
#define SOC_PCIE_PCIECTRL_SC_PCIECTRL_STAT18_l1ss_cnt_reg_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
