#ifndef __CSI_WRAP_DRV_PRIV_H__
#define __CSI_WRAP_DRV_PRIV_H__ 
typedef union {
 struct {
  unsigned int cg_csia : 1 ;
  unsigned int cg_csib : 1 ;
  unsigned int cg_csic : 1 ;
  unsigned int rsv_0 : 29 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_CGR_0;
typedef union {
 struct {
  unsigned int cg_csia : 1 ;
  unsigned int cg_csib : 1 ;
  unsigned int cg_csic : 1 ;
  unsigned int rsv_1 : 29 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_CGR_0_SET;
typedef union {
 struct {
  unsigned int cg_csia : 1 ;
  unsigned int cg_csib : 1 ;
  unsigned int cg_csic : 1 ;
  unsigned int rsv_2 : 29 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_CGR_0_CLEAR;
typedef union {
 struct {
  unsigned int soft_rst_csia : 1 ;
  unsigned int soft_rst_csib : 1 ;
  unsigned int soft_rst_csic : 1 ;
  unsigned int rsv_3 : 29 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_RESET_0;
typedef union {
 struct {
  unsigned int phya_rxactivehs_0 : 1 ;
  unsigned int phya_rxactivehs_1 : 1 ;
  unsigned int phya_rxactivehs_2 : 1 ;
  unsigned int phya_rxactivehs_3 : 1 ;
  unsigned int phya_rxlpdtesc_0 : 1 ;
  unsigned int phya_rxlpdtesc_1 : 1 ;
  unsigned int phya_rxlpdtesc_2 : 1 ;
  unsigned int phya_rxlpdtesc_3 : 1 ;
  unsigned int phya_ulpsactivenot_0 : 1 ;
  unsigned int phya_ulpsactivenot_1 : 1 ;
  unsigned int phya_ulpsactivenot_2 : 1 ;
  unsigned int phya_ulpsactivenot_3 : 1 ;
  unsigned int phya_errsyncesc_0 : 1 ;
  unsigned int phya_errsyncesc_1 : 1 ;
  unsigned int phya_errsyncesc_2 : 1 ;
  unsigned int phya_errsyncesc_3 : 1 ;
  unsigned int phya_ulpsactivenotclk : 1 ;
  unsigned int rsv_4 : 3 ;
  unsigned int phya_rxinvalidcodehs_0 : 2 ;
  unsigned int phya_rxinvalidcodehs_1 : 2 ;
  unsigned int phya_rxinvalidcodehs_2 : 2 ;
  unsigned int rsv_5 : 6 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_PHY_CSI_A_DBG;
typedef union {
 struct {
  unsigned int phyb_rxactivehs_0 : 1 ;
  unsigned int phyb_rxactivehs_1 : 1 ;
  unsigned int phyb_rxactivehs_2 : 1 ;
  unsigned int phyb_rxactivehs_3 : 1 ;
  unsigned int phyb_rxlpdtesc_0 : 1 ;
  unsigned int phyb_rxlpdtesc_1 : 1 ;
  unsigned int phyb_rxlpdtesc_2 : 1 ;
  unsigned int phyb_rxlpdtesc_3 : 1 ;
  unsigned int phyb_ulpsactivenot_0 : 1 ;
  unsigned int phyb_ulpsactivenot_1 : 1 ;
  unsigned int phyb_ulpsactivenot_2 : 1 ;
  unsigned int phyb_ulpsactivenot_3 : 1 ;
  unsigned int phyb_errsyncesc_0 : 1 ;
  unsigned int phyb_errsyncesc_1 : 1 ;
  unsigned int phyb_errsyncesc_2 : 1 ;
  unsigned int phyb_errsyncesc_3 : 1 ;
  unsigned int phyb_ulpsactivenotclk : 1 ;
  unsigned int rsv_6 : 3 ;
  unsigned int phyb_rxinvalidcodehs_0 : 2 ;
  unsigned int phyb_rxinvalidcodehs_1 : 2 ;
  unsigned int phyb_rxinvalidcodehs_2 : 2 ;
  unsigned int rsv_7 : 6 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_PHY_CSI_B_DBG;
typedef union {
 struct {
  unsigned int phyc_rxactivehs_0 : 1 ;
  unsigned int phyc_rxactivehs_1 : 1 ;
  unsigned int phyc_rxactivehs_2 : 1 ;
  unsigned int phyc_rxactivehs_3 : 1 ;
  unsigned int phyc_rxlpdtesc_0 : 1 ;
  unsigned int phyc_rxlpdtesc_1 : 1 ;
  unsigned int phyc_rxlpdtesc_2 : 1 ;
  unsigned int phyc_rxlpdtesc_3 : 1 ;
  unsigned int phyc_ulpsactivenot_0 : 1 ;
  unsigned int phyc_ulpsactivenot_1 : 1 ;
  unsigned int phyc_ulpsactivenot_2 : 1 ;
  unsigned int phyc_ulpsactivenot_3 : 1 ;
  unsigned int phyc_errsyncesc_0 : 1 ;
  unsigned int phyc_errsyncesc_1 : 1 ;
  unsigned int phyc_errsyncesc_2 : 1 ;
  unsigned int phyc_errsyncesc_3 : 1 ;
  unsigned int phyc_ulpsactivenotclk : 1 ;
  unsigned int rsv_8 : 3 ;
  unsigned int phyc_rxinvalidcodehs_0 : 2 ;
  unsigned int phyc_rxinvalidcodehs_1 : 2 ;
  unsigned int phyc_rxinvalidcodehs_2 : 2 ;
  unsigned int rsv_9 : 6 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_PHY_CSI_C_DBG;
typedef union {
 struct {
  unsigned int idi_sel_a : 1 ;
  unsigned int idi_sel_b : 1 ;
  unsigned int idi_sel_c : 1 ;
  unsigned int rsv_10 : 29 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_ABC_IDI_SEL;
typedef union {
 struct {
  unsigned int csia_force_pclk_on : 1 ;
  unsigned int csib_force_pclk_on : 1 ;
  unsigned int csic_force_pclk_on : 1 ;
  unsigned int rsv_11 : 29 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_ABC_FORCE_PCLKON;
typedef union {
 struct {
  unsigned int csi_wrapper_secure_st : 32 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_WRAPPER_SECURE_ST;
typedef union {
 struct {
  unsigned int soft_rst_mudp : 1 ;
  unsigned int cg_en_mudp : 1 ;
  unsigned int rsv_12 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_MUDP_RS_CLKRST;
typedef union {
 struct {
  unsigned int reserved_0_sw : 32 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_RESERVED_0;
typedef union {
 struct {
  unsigned int reserved_1_sw : 32 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_RESERVED_1;
typedef union {
 struct {
  unsigned int cg_csid : 1 ;
  unsigned int rsv_13 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_CGR_1;
typedef union {
 struct {
  unsigned int cg_csid : 1 ;
  unsigned int rsv_14 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_CGR_1_SET;
typedef union {
 struct {
  unsigned int cg_csid : 1 ;
  unsigned int rsv_15 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_CGR_1_CLEAR;
typedef union {
 struct {
  unsigned int soft_rst_csid : 1 ;
  unsigned int rsv_16 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_RESET_1;
typedef union {
 struct {
  unsigned int phyd_rxactivehs_0 : 1 ;
  unsigned int phyd_rxactivehs_1 : 1 ;
  unsigned int phyd_rxactivehs_2 : 1 ;
  unsigned int phyd_rxactivehs_3 : 1 ;
  unsigned int phyd_rxlpdtesc_0 : 1 ;
  unsigned int phyd_rxlpdtesc_1 : 1 ;
  unsigned int phyd_rxlpdtesc_2 : 1 ;
  unsigned int phyd_rxlpdtesc_3 : 1 ;
  unsigned int phyd_ulpsactivenot_0 : 1 ;
  unsigned int phyd_ulpsactivenot_1 : 1 ;
  unsigned int phyd_ulpsactivenot_2 : 1 ;
  unsigned int phyd_ulpsactivenot_3 : 1 ;
  unsigned int phyd_errsyncesc_0 : 1 ;
  unsigned int phyd_errsyncesc_1 : 1 ;
  unsigned int phyd_errsyncesc_2 : 1 ;
  unsigned int phyd_errsyncesc_3 : 1 ;
  unsigned int phyd_ulpsactivenotclk : 1 ;
  unsigned int rsv_17 : 3 ;
  unsigned int phyd_rxinvalidcodehs_0 : 2 ;
  unsigned int phyd_rxinvalidcodehs_1 : 2 ;
  unsigned int phyd_rxinvalidcodehs_2 : 2 ;
  unsigned int rsv_18 : 6 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_PHY_CSI_D_DBG;
typedef union {
 struct {
  unsigned int csid_force_pclk_on : 1 ;
  unsigned int rsv_19 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_D_FORCE_PCLKON;
typedef union {
 struct {
  unsigned int cg_csie : 1 ;
  unsigned int rsv_20 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_CGR_2;
typedef union {
 struct {
  unsigned int cg_csie : 1 ;
  unsigned int rsv_21 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_CGR_2_SET;
typedef union {
 struct {
  unsigned int cg_csie : 1 ;
  unsigned int rsv_22 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_CGR_2_CLEAR;
typedef union {
 struct {
  unsigned int soft_rst_csie : 1 ;
  unsigned int rsv_23 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_RESET_2;
typedef union {
 struct {
  unsigned int phye_rxactivehs_0 : 1 ;
  unsigned int phye_rxactivehs_1 : 1 ;
  unsigned int phye_rxactivehs_2 : 1 ;
  unsigned int phye_rxactivehs_3 : 1 ;
  unsigned int phye_rxlpdtesc_0 : 1 ;
  unsigned int phye_rxlpdtesc_1 : 1 ;
  unsigned int phye_rxlpdtesc_2 : 1 ;
  unsigned int phye_rxlpdtesc_3 : 1 ;
  unsigned int phye_ulpsactivenot_0 : 1 ;
  unsigned int phye_ulpsactivenot_1 : 1 ;
  unsigned int phye_ulpsactivenot_2 : 1 ;
  unsigned int phye_ulpsactivenot_3 : 1 ;
  unsigned int phye_errsyncesc_0 : 1 ;
  unsigned int phye_errsyncesc_1 : 1 ;
  unsigned int phye_errsyncesc_2 : 1 ;
  unsigned int phye_errsyncesc_3 : 1 ;
  unsigned int phye_ulpsactivenotclk : 1 ;
  unsigned int rsv_24 : 3 ;
  unsigned int phye_rxinvalidcodehs_0 : 2 ;
  unsigned int phye_rxinvalidcodehs_1 : 2 ;
  unsigned int phye_rxinvalidcodehs_2 : 2 ;
  unsigned int rsv_25 : 6 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_PHY_CSI_E_DBG;
typedef union {
 struct {
  unsigned int csie_force_pclk_on : 1 ;
  unsigned int rsv_26 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_E_FORCE_PCLKON;
typedef union {
 struct {
  unsigned int rsv_27 : 25 ;
  unsigned int csia_en : 1 ;
  unsigned int csia_sensor : 1 ;
  unsigned int csia_cdphy_sensor_connection : 1 ;
  unsigned int rsv_28 : 1 ;
  unsigned int csia_cdphy_source : 3 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIA_CTRL;
typedef union {
 struct {
  unsigned int rsv_29 : 25 ;
  unsigned int csib_en : 1 ;
  unsigned int csib_sensor : 1 ;
  unsigned int csib_cdphy_sensor_connection : 1 ;
  unsigned int rsv_30 : 1 ;
  unsigned int csib_cdphy_source : 3 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIB_CTRL;
typedef union {
 struct {
  unsigned int rsv_31 : 25 ;
  unsigned int csic_en : 1 ;
  unsigned int csic_sensor : 1 ;
  unsigned int csic_cdphy_sensor_connection : 1 ;
  unsigned int rsv_32 : 1 ;
  unsigned int csic_cdphy_source : 3 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIC_CTRL;
typedef union {
 struct {
  unsigned int rsv_33 : 23 ;
  unsigned int csid_reformat_type : 1 ;
  unsigned int csid_reformat_enable : 1 ;
  unsigned int csid_en : 1 ;
  unsigned int csid_sensor : 1 ;
  unsigned int csid_cdphy_sensor_connection : 1 ;
  unsigned int rsv_34 : 1 ;
  unsigned int csid_cdphy_source : 3 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSID_CTRL;
typedef union {
 struct {
  unsigned int ipi_cfg_vc : 4 ;
  unsigned int in_pixel_type : 1 ;
  unsigned int round_type : 1 ;
  unsigned int reorder_err_en : 1 ;
  unsigned int rsv_35 : 10 ;
  unsigned int ipi_cfg_dt : 6 ;
  unsigned int rsv_36 : 2 ;
  unsigned int csie_en : 1 ;
  unsigned int csie_sensor : 1 ;
  unsigned int csie_cdphy_sensor_connection : 1 ;
  unsigned int rsv_37 : 1 ;
  unsigned int csie_cdphy_source : 3 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIE_CTRL;
typedef union {
 struct {
  unsigned int rsv_38 : 25 ;
  unsigned int csif_en : 1 ;
  unsigned int csif_sensor : 1 ;
  unsigned int csif_cdphy_sensor_connection : 1 ;
  unsigned int rsv_39 : 1 ;
  unsigned int csif_cdphy_source : 3 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIF_CTRL;
typedef union {
 struct {
  unsigned int rsv_40 : 25 ;
  unsigned int csig_en : 1 ;
  unsigned int csig_sensor : 1 ;
  unsigned int csig_cdphy_sensor_connection : 1 ;
  unsigned int rsv_41 : 1 ;
  unsigned int csig_cdphy_source : 3 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIG_CTRL;
typedef union {
 struct {
  unsigned int rsv_42 : 25 ;
  unsigned int csih_en : 1 ;
  unsigned int csih_sensor : 1 ;
  unsigned int csih_cdphy_sensor_connection : 1 ;
  unsigned int rsv_43 : 1 ;
  unsigned int csih_cdphy_source : 3 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIH_CTRL;
typedef union {
 struct {
  unsigned int csi_debug_en : 1 ;
  unsigned int csia_overflow : 1 ;
  unsigned int csib_overflow : 1 ;
  unsigned int csic_overflow : 1 ;
  unsigned int csid_overflow : 1 ;
  unsigned int csie_overflow : 1 ;
  unsigned int csif_overflow : 1 ;
  unsigned int csig_overflow : 1 ;
  unsigned int reorder_err : 1 ;
  unsigned int csih_overflow : 1 ;
  unsigned int rsv_44 : 22 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_DBG;
typedef union {
 struct {
  unsigned int csia_dbg_hcnt : 13 ;
  unsigned int csia_dbg_hcnt_max : 13 ;
  unsigned int csia_dbg_v_flag : 1 ;
  unsigned int rsv_45 : 5 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIA_DBG;
typedef union {
 struct {
  unsigned int csib_dbg_hcnt : 13 ;
  unsigned int csib_dbg_hcnt_max : 13 ;
  unsigned int csib_dbg_v_flag : 1 ;
  unsigned int rsv_46 : 5 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIB_DBG;
typedef union {
 struct {
  unsigned int csic_dbg_hcnt : 13 ;
  unsigned int csic_dbg_hcnt_max : 13 ;
  unsigned int csic_dbg_v_flag : 1 ;
  unsigned int rsv_47 : 5 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIC_DBG;
typedef union {
 struct {
  unsigned int csid_dbg_hcnt : 13 ;
  unsigned int csid_dbg_hcnt_max : 13 ;
  unsigned int csid_dbg_v_flag : 1 ;
  unsigned int rsv_48 : 5 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSID_DBG;
typedef union {
 struct {
  unsigned int csie_dbg_hcnt : 13 ;
  unsigned int csie_dbg_hcnt_max : 13 ;
  unsigned int csie_dbg_v_flag : 1 ;
  unsigned int rsv_49 : 5 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIE_DBG;
typedef union {
 struct {
  unsigned int csif_dbg_hcnt : 13 ;
  unsigned int csif_dbg_hcnt_max : 13 ;
  unsigned int csif_dbg_v_flag : 1 ;
  unsigned int rsv_50 : 5 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIF_DBG;
typedef union {
 struct {
  unsigned int csig_dbg_hcnt : 13 ;
  unsigned int csig_dbg_hcnt_max : 13 ;
  unsigned int csig_dbg_v_flag : 1 ;
  unsigned int rsv_51 : 5 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIG_DBG;
typedef union {
 struct {
  unsigned int phy_dbg_testdout_sel : 3 ;
  unsigned int rsv_52 : 29 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_PHY_DBG_TESTDOUT_SEL;
typedef union {
 struct {
  unsigned int csih_dbg_hcnt : 13 ;
  unsigned int csih_dbg_hcnt_max : 13 ;
  unsigned int csih_dbg_v_flag : 1 ;
  unsigned int rsv_53 : 5 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIH_DBG;
typedef union {
 struct {
  unsigned int cg_csif : 1 ;
  unsigned int rsv_54 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIF_CGR;
typedef union {
 struct {
  unsigned int cg_csif : 1 ;
  unsigned int rsv_55 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIF_CGR_SET;
typedef union {
 struct {
  unsigned int cg_csif : 1 ;
  unsigned int rsv_56 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIF_CGR_CLEAR;
typedef union {
 struct {
  unsigned int soft_rst_csif : 1 ;
  unsigned int rsv_57 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIF_RESET;
typedef union {
 struct {
  unsigned int phyf_rxactivehs_0 : 1 ;
  unsigned int phyf_rxactivehs_1 : 1 ;
  unsigned int phyf_rxactivehs_2 : 1 ;
  unsigned int phyf_rxactivehs_3 : 1 ;
  unsigned int phyf_rxlpdtesc_0 : 1 ;
  unsigned int phyf_rxlpdtesc_1 : 1 ;
  unsigned int phyf_rxlpdtesc_2 : 1 ;
  unsigned int phyf_rxlpdtesc_3 : 1 ;
  unsigned int phyf_ulpsactivenot_0 : 1 ;
  unsigned int phyf_ulpsactivenot_1 : 1 ;
  unsigned int phyf_ulpsactivenot_2 : 1 ;
  unsigned int phyf_ulpsactivenot_3 : 1 ;
  unsigned int phyf_errsyncesc_0 : 1 ;
  unsigned int phyf_errsyncesc_1 : 1 ;
  unsigned int phyf_errsyncesc_2 : 1 ;
  unsigned int phyf_errsyncesc_3 : 1 ;
  unsigned int phyf_ulpsactivenotclk : 1 ;
  unsigned int rsv_58 : 3 ;
  unsigned int phyf_rxinvalidcodehs_0 : 2 ;
  unsigned int phyf_rxinvalidcodehs_1 : 2 ;
  unsigned int phyf_rxinvalidcodehs_2 : 2 ;
  unsigned int rsv_59 : 6 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_PHY_CSI_F_DBG;
typedef union {
 struct {
  unsigned int idi_sel_f : 1 ;
  unsigned int rsv_60 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_F_IDI_SEL;
typedef union {
 struct {
  unsigned int csif_force_pclk_on : 1 ;
  unsigned int rsv_61 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_F_FORCE_PCLKON;
typedef union {
 struct {
  unsigned int cg_csig : 1 ;
  unsigned int rsv_62 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIG_CGR;
typedef union {
 struct {
  unsigned int cg_csig : 1 ;
  unsigned int rsv_63 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIG_CGR_SET;
typedef union {
 struct {
  unsigned int cg_csig : 1 ;
  unsigned int rsv_64 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIG_CGR_CLEAR;
typedef union {
 struct {
  unsigned int soft_rst_csig : 1 ;
  unsigned int rsv_65 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIG_RESET;
typedef union {
 struct {
  unsigned int phyg_rxactivehs_0 : 1 ;
  unsigned int phyg_rxactivehs_1 : 1 ;
  unsigned int phyg_rxactivehs_2 : 1 ;
  unsigned int phyg_rxactivehs_3 : 1 ;
  unsigned int phyg_rxlpdtesc_0 : 1 ;
  unsigned int phyg_rxlpdtesc_1 : 1 ;
  unsigned int phyg_rxlpdtesc_2 : 1 ;
  unsigned int phyg_rxlpdtesc_3 : 1 ;
  unsigned int phyg_ulpsactivenot_0 : 1 ;
  unsigned int phyg_ulpsactivenot_1 : 1 ;
  unsigned int phyg_ulpsactivenot_2 : 1 ;
  unsigned int phyg_ulpsactivenot_3 : 1 ;
  unsigned int phyg_errsyncesc_0 : 1 ;
  unsigned int phyg_errsyncesc_1 : 1 ;
  unsigned int phyg_errsyncesc_2 : 1 ;
  unsigned int phyg_errsyncesc_3 : 1 ;
  unsigned int phyg_ulpsactivenotclk : 1 ;
  unsigned int rsv_66 : 3 ;
  unsigned int phyg_rxinvalidcodehs_0 : 2 ;
  unsigned int phyg_rxinvalidcodehs_1 : 2 ;
  unsigned int phyg_rxinvalidcodehs_2 : 2 ;
  unsigned int rsv_67 : 6 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_PHY_CSI_G_DBG;
typedef union {
 struct {
  unsigned int idi_sel_g : 1 ;
  unsigned int rsv_68 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_G_IDI_SEL;
typedef union {
 struct {
  unsigned int csig_force_pclk_on : 1 ;
  unsigned int rsv_69 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_G_FORCE_PCLKON;
typedef union {
 struct {
  unsigned int phya_testdin : 10 ;
  unsigned int phya_testen : 1 ;
  unsigned int phya_testclr : 1 ;
  unsigned int phya_testclk : 1 ;
  unsigned int rsv_70 : 3 ;
  unsigned int bitmasken : 16 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_A_TEST_CTRL;
typedef union {
 struct {
  unsigned int phya_testdout : 10 ;
  unsigned int rsv_71 : 22 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_A_TEST_DOUT;
typedef union {
 struct {
  unsigned int phya_rstz : 1 ;
  unsigned int phya_shutdownz : 1 ;
  unsigned int rsv_72 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_A_SHUTDOWN_RST_CTRL;
typedef union {
 struct {
  unsigned int phya_enable_0 : 1 ;
  unsigned int phya_enable_1 : 1 ;
  unsigned int phya_enable_2 : 1 ;
  unsigned int phya_enable_3 : 1 ;
  unsigned int phya_enableclk_0 : 1 ;
  unsigned int phya_enableclk_1 : 1 ;
  unsigned int phya_cdphy_rx_sel : 1 ;
  unsigned int phya_lane1_clk_en : 1 ;
  unsigned int phya_rxdatawidthhs_0_cphy : 2 ;
  unsigned int phya_rxdatawidthhs_1_cphy : 2 ;
  unsigned int phya_rxdatawidthhs_2_cphy : 2 ;
  unsigned int phya_protocol_sel : 1 ;
  unsigned int rsv_73 : 1 ;
  unsigned int phya_rxdatawidthhs_0_dphy : 2 ;
  unsigned int phya_rxdatawidthhs_1_dphy : 2 ;
  unsigned int phya_vote_cnt : 2 ;
  unsigned int rsv_74 : 10 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_A_CTRL;
typedef union {
 struct {
  unsigned int phya_lock_wr_vld : 1 ;
  unsigned int phya_lock_mst_id : 3 ;
  unsigned int rsv_75 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_A_LOCK_CTRL;
typedef union {
 struct {
  unsigned int phya_unlock_wr_vld : 1 ;
  unsigned int phya_unlocked_mst_id : 3 ;
  unsigned int rsv_76 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_A_UNLOCK_CTRL;
typedef union {
 struct {
  unsigned int phya_lock_status : 1 ;
  unsigned int phya_locked_mst_id : 3 ;
  unsigned int rsv_77 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_A_LOCK_STATE;
typedef union {
 struct {
  unsigned int phya_rx_dbg_out : 24 ;
  unsigned int phya_clk_dbg_cnt : 8 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_A_DBG;
typedef union {
 struct {
  unsigned int soft_rst_phya : 1 ;
  unsigned int cg_phya : 1 ;
  unsigned int rsv_78 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_A_CLKRST;
typedef union {
 struct {
  unsigned int phyb_testdin : 10 ;
  unsigned int phyb_testen : 1 ;
  unsigned int phyb_testclr : 1 ;
  unsigned int phyb_testclk : 1 ;
  unsigned int rsv_79 : 3 ;
  unsigned int bitmasken : 16 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_B_TEST_CTRL;
typedef union {
 struct {
  unsigned int phyb_testdout : 10 ;
  unsigned int rsv_80 : 22 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_B_TEST_DOUT;
typedef union {
 struct {
  unsigned int phyb_rstz : 1 ;
  unsigned int phyb_shutdownz : 1 ;
  unsigned int rsv_81 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_B_SHUTDOWN_RST_CTRL;
typedef union {
 struct {
  unsigned int phyb_enable_0 : 1 ;
  unsigned int phyb_enable_1 : 1 ;
  unsigned int phyb_enable_2 : 1 ;
  unsigned int phyb_enable_3 : 1 ;
  unsigned int phyb_enableclk_0 : 1 ;
  unsigned int phyb_enableclk_1 : 1 ;
  unsigned int phyb_cdphy_rx_sel : 1 ;
  unsigned int phyb_lane1_clk_en : 1 ;
  unsigned int phyb_rxdatawidthhs_0_cphy : 2 ;
  unsigned int phyb_rxdatawidthhs_1_cphy : 2 ;
  unsigned int phyb_rxdatawidthhs_2_cphy : 2 ;
  unsigned int phyb_protocol_sel : 1 ;
  unsigned int rsv_82 : 1 ;
  unsigned int phyb_rxdatawidthhs_0_dphy : 2 ;
  unsigned int phyb_rxdatawidthhs_1_dphy : 2 ;
  unsigned int phyb_vote_cnt : 2 ;
  unsigned int rsv_83 : 10 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_B_CTRL;
typedef union {
 struct {
  unsigned int phyb_lock_wr_vld : 1 ;
  unsigned int phyb_lock_mst_id : 3 ;
  unsigned int rsv_84 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_B_LOCK_CTRL;
typedef union {
 struct {
  unsigned int phyb_unlock_wr_vld : 1 ;
  unsigned int phyb_unlocked_mst_id : 3 ;
  unsigned int rsv_85 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_B_UNLOCK_CTRL;
typedef union {
 struct {
  unsigned int phyb_lock_status : 1 ;
  unsigned int phyb_locked_mst_id : 3 ;
  unsigned int rsv_86 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_B_LOCK_STATE;
typedef union {
 struct {
  unsigned int phyb_rx_dbg_out : 24 ;
  unsigned int phyb_clk_dbg_cnt : 8 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_B_DBG;
typedef union {
 struct {
  unsigned int soft_rst_phyb : 1 ;
  unsigned int cg_phyb : 1 ;
  unsigned int rsv_87 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_B_CLKRST;
typedef union {
 struct {
  unsigned int phyc_testdin : 10 ;
  unsigned int phyc_testen : 1 ;
  unsigned int phyc_testclr : 1 ;
  unsigned int phyc_testclk : 1 ;
  unsigned int rsv_88 : 3 ;
  unsigned int bitmasken : 16 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_C_TEST_CTRL;
typedef union {
 struct {
  unsigned int phyc_testdout : 10 ;
  unsigned int rsv_89 : 22 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_C_TEST_DOUT;
typedef union {
 struct {
  unsigned int phyc_rstz : 1 ;
  unsigned int phyc_shutdownz : 1 ;
  unsigned int rsv_90 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_C_SHUTDOWN_RST_CTRL;
typedef union {
 struct {
  unsigned int phyc_enable_0 : 1 ;
  unsigned int phyc_enable_1 : 1 ;
  unsigned int phyc_enable_2 : 1 ;
  unsigned int phyc_enable_3 : 1 ;
  unsigned int phyc_enableclk_0 : 1 ;
  unsigned int phyc_enableclk_1 : 1 ;
  unsigned int phyc_cdphy_rx_sel : 1 ;
  unsigned int phyc_lane1_clk_en : 1 ;
  unsigned int phyc_rxdatawidthhs_0_cphy : 2 ;
  unsigned int phyc_rxdatawidthhs_1_cphy : 2 ;
  unsigned int phyc_rxdatawidthhs_2_cphy : 2 ;
  unsigned int phyc_protocol_sel : 1 ;
  unsigned int rsv_91 : 1 ;
  unsigned int phyc_rxdatawidthhs_0_dphy : 2 ;
  unsigned int phyc_rxdatawidthhs_1_dphy : 2 ;
  unsigned int phyc_vote_cnt : 2 ;
  unsigned int rsv_92 : 10 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_C_CTRL;
typedef union {
 struct {
  unsigned int phyc_lock_wr_vld : 1 ;
  unsigned int phyc_lock_mst_id : 3 ;
  unsigned int rsv_93 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_C_LOCK_CTRL;
typedef union {
 struct {
  unsigned int phyc_unlock_wr_vld : 1 ;
  unsigned int phyc_unlocked_mst_id : 3 ;
  unsigned int rsv_94 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_C_UNLOCK_CTRL;
typedef union {
 struct {
  unsigned int phyc_lock_status : 1 ;
  unsigned int phyc_locked_mst_id : 3 ;
  unsigned int rsv_95 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_C_LOCK_STATE;
typedef union {
 struct {
  unsigned int phyc_rx_dbg_out : 24 ;
  unsigned int phyc_clk_dbg_cnt : 8 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_C_DBG;
typedef union {
 struct {
  unsigned int soft_rst_phyc : 1 ;
  unsigned int cg_phyc : 1 ;
  unsigned int rsv_96 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_C_CLKRST;
typedef union {
 struct {
  unsigned int phyd_testdin : 10 ;
  unsigned int phyd_testen : 1 ;
  unsigned int phyd_testclr : 1 ;
  unsigned int phyd_testclk : 1 ;
  unsigned int rsv_97 : 3 ;
  unsigned int bitmasken : 16 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_D_TEST_CTRL;
typedef union {
 struct {
  unsigned int phyd_testdout : 10 ;
  unsigned int rsv_98 : 22 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_D_TEST_DOUT;
typedef union {
 struct {
  unsigned int phyd_rstz : 1 ;
  unsigned int phyd_shutdownz : 1 ;
  unsigned int rsv_99 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_D_SHUTDOWN_RST_CTRL;
typedef union {
 struct {
  unsigned int phyd_enable_0 : 1 ;
  unsigned int phyd_enable_1 : 1 ;
  unsigned int phyd_enable_2 : 1 ;
  unsigned int phyd_enable_3 : 1 ;
  unsigned int phyd_enableclk_0 : 1 ;
  unsigned int phyd_enableclk_1 : 1 ;
  unsigned int phyd_cdphy_rx_sel : 1 ;
  unsigned int phyd_lane1_clk_en : 1 ;
  unsigned int phyd_rxdatawidthhs_0_cphy : 2 ;
  unsigned int phyd_rxdatawidthhs_1_cphy : 2 ;
  unsigned int phyd_rxdatawidthhs_2_cphy : 2 ;
  unsigned int phyd_protocol_sel : 1 ;
  unsigned int rsv_100 : 1 ;
  unsigned int phyd_rxdatawidthhs_0_dphy : 2 ;
  unsigned int phyd_rxdatawidthhs_1_dphy : 2 ;
  unsigned int phyd_vote_cnt : 2 ;
  unsigned int rsv_101 : 10 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_D_CTRL;
typedef union {
 struct {
  unsigned int phyd_lock_wr_vld : 1 ;
  unsigned int phyd_lock_mst_id : 3 ;
  unsigned int rsv_102 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_D_LOCK_CTRL;
typedef union {
 struct {
  unsigned int phyd_unlock_wr_vld : 1 ;
  unsigned int phyd_unlocked_mst_id : 3 ;
  unsigned int rsv_103 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_D_UNLOCK_CTRL;
typedef union {
 struct {
  unsigned int phyd_lock_status : 1 ;
  unsigned int phyd_locked_mst_id : 3 ;
  unsigned int rsv_104 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_D_LOCK_STATE;
typedef union {
 struct {
  unsigned int phyd_rx_dbg_out : 24 ;
  unsigned int phyd_clk_dbg_cnt : 8 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_D_DBG;
typedef union {
 struct {
  unsigned int soft_rst_phyd : 1 ;
  unsigned int cg_phyd : 1 ;
  unsigned int rsv_105 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_D_CLKRST;
typedef union {
 struct {
  unsigned int phye_testdin : 10 ;
  unsigned int phye_testen : 1 ;
  unsigned int phye_testclr : 1 ;
  unsigned int phye_testclk : 1 ;
  unsigned int rsv_106 : 3 ;
  unsigned int bitmasken : 16 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_E_TEST_CTRL;
typedef union {
 struct {
  unsigned int phye_testdout : 10 ;
  unsigned int rsv_107 : 22 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_E_TEST_DOUT;
typedef union {
 struct {
  unsigned int phye_rstz : 1 ;
  unsigned int phye_shutdownz : 1 ;
  unsigned int rsv_108 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_E_SHUTDOWN_RST_CTRL;
typedef union {
 struct {
  unsigned int phye_enable_0 : 1 ;
  unsigned int phye_enable_1 : 1 ;
  unsigned int phye_enable_2 : 1 ;
  unsigned int phye_enable_3 : 1 ;
  unsigned int phye_enableclk_0 : 1 ;
  unsigned int phye_enableclk_1 : 1 ;
  unsigned int phye_cdphy_rx_sel : 1 ;
  unsigned int phye_lane1_clk_en : 1 ;
  unsigned int phye_rxdatawidthhs_0_cphy : 2 ;
  unsigned int phye_rxdatawidthhs_1_cphy : 2 ;
  unsigned int phye_rxdatawidthhs_2_cphy : 2 ;
  unsigned int phye_protocol_sel : 1 ;
  unsigned int rsv_109 : 1 ;
  unsigned int phye_rxdatawidthhs_0_dphy : 2 ;
  unsigned int phye_rxdatawidthhs_1_dphy : 2 ;
  unsigned int phye_vote_cnt : 2 ;
  unsigned int rsv_110 : 10 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_E_CTRL;
typedef union {
 struct {
  unsigned int phye_lock_wr_vld : 1 ;
  unsigned int phye_lock_mst_id : 3 ;
  unsigned int rsv_111 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_E_LOCK_CTRL;
typedef union {
 struct {
  unsigned int phye_unlock_wr_vld : 1 ;
  unsigned int phye_unlocked_mst_id : 3 ;
  unsigned int rsv_112 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_E_UNLOCK_CTRL;
typedef union {
 struct {
  unsigned int phye_lock_status : 1 ;
  unsigned int phye_locked_mst_id : 3 ;
  unsigned int rsv_113 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_E_LOCK_STATE;
typedef union {
 struct {
  unsigned int phye_rx_dbg_out : 24 ;
  unsigned int phye_clk_dbg_cnt : 8 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_E_DBG;
typedef union {
 struct {
  unsigned int soft_rst_phye : 1 ;
  unsigned int cg_phye : 1 ;
  unsigned int rsv_114 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_E_CLKRST;
typedef union {
 struct {
  unsigned int phyf_testdin : 10 ;
  unsigned int phyf_testen : 1 ;
  unsigned int phyf_testclr : 1 ;
  unsigned int phyf_testclk : 1 ;
  unsigned int rsv_115 : 3 ;
  unsigned int bitmasken : 16 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_F_TEST_CTRL;
typedef union {
 struct {
  unsigned int phyf_testdout : 10 ;
  unsigned int rsv_116 : 22 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_F_TEST_DOUT;
typedef union {
 struct {
  unsigned int phyf_rstz : 1 ;
  unsigned int phyf_shutdownz : 1 ;
  unsigned int rsv_117 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_F_SHUTDOWN_RST_CTRL;
typedef union {
 struct {
  unsigned int phyf_enable_0 : 1 ;
  unsigned int phyf_enable_1 : 1 ;
  unsigned int phyf_enable_2 : 1 ;
  unsigned int phyf_enable_3 : 1 ;
  unsigned int phyf_enableclk_0 : 1 ;
  unsigned int phyf_enableclk_1 : 1 ;
  unsigned int phyf_cdphy_rx_sel : 1 ;
  unsigned int phyf_lane1_clk_en : 1 ;
  unsigned int phyf_rxdatawidthhs_0_cphy : 2 ;
  unsigned int phyf_rxdatawidthhs_1_cphy : 2 ;
  unsigned int phyf_rxdatawidthhs_2_cphy : 2 ;
  unsigned int phyf_protocol_sel : 1 ;
  unsigned int rsv_118 : 1 ;
  unsigned int phyf_rxdatawidthhs_0_dphy : 2 ;
  unsigned int phyf_rxdatawidthhs_1_dphy : 2 ;
  unsigned int phyf_vote_cnt : 2 ;
  unsigned int rsv_119 : 10 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_F_CTRL;
typedef union {
 struct {
  unsigned int phyf_lock_wr_vld : 1 ;
  unsigned int phyf_lock_mst_id : 3 ;
  unsigned int rsv_120 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_F_LOCK_CTRL;
typedef union {
 struct {
  unsigned int phyf_unlock_wr_vld : 1 ;
  unsigned int phyf_unlocked_mst_id : 3 ;
  unsigned int rsv_121 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_F_UNLOCK_CTRL;
typedef union {
 struct {
  unsigned int phyf_lock_status : 1 ;
  unsigned int phyf_locked_mst_id : 3 ;
  unsigned int rsv_122 : 28 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_F_LOCK_STATE;
typedef union {
 struct {
  unsigned int phyf_rx_dbg_out : 24 ;
  unsigned int phyf_clk_dbg_cnt : 8 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_F_DBG;
typedef union {
 struct {
  unsigned int soft_rst_phyf : 1 ;
  unsigned int cg_phyf : 1 ;
  unsigned int rsv_123 : 30 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CDPHY_F_CLKRST;
typedef union {
 struct {
  unsigned int cg_csih : 1 ;
  unsigned int rsv_124 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIH_CGR;
typedef union {
 struct {
  unsigned int cg_csih : 1 ;
  unsigned int rsv_125 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIH_CGR_SET;
typedef union {
 struct {
  unsigned int cg_csih : 1 ;
  unsigned int rsv_126 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIH_CGR_CLEAR;
typedef union {
 struct {
  unsigned int soft_rst_csih : 1 ;
  unsigned int rsv_127 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSIH_RESET;
typedef union {
 struct {
  unsigned int phyh_rxactivehs_0 : 1 ;
  unsigned int phyh_rxactivehs_1 : 1 ;
  unsigned int phyh_rxactivehs_2 : 1 ;
  unsigned int phyh_rxactivehs_3 : 1 ;
  unsigned int phyh_rxlpdtesc_0 : 1 ;
  unsigned int phyh_rxlpdtesc_1 : 1 ;
  unsigned int phyh_rxlpdtesc_2 : 1 ;
  unsigned int phyh_rxlpdtesc_3 : 1 ;
  unsigned int phyh_ulpsactivenot_0 : 1 ;
  unsigned int phyh_ulpsactivenot_1 : 1 ;
  unsigned int phyh_ulpsactivenot_2 : 1 ;
  unsigned int phyh_ulpsactivenot_3 : 1 ;
  unsigned int phyh_errsyncesc_0 : 1 ;
  unsigned int phyh_errsyncesc_1 : 1 ;
  unsigned int phyh_errsyncesc_2 : 1 ;
  unsigned int phyh_errsyncesc_3 : 1 ;
  unsigned int phyh_ulpsactivenotclk : 1 ;
  unsigned int rsv_128 : 3 ;
  unsigned int phyh_rxinvalidcodehs_0 : 2 ;
  unsigned int phyh_rxinvalidcodehs_1 : 2 ;
  unsigned int phyh_rxinvalidcodehs_2 : 2 ;
  unsigned int rsv_129 : 6 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_PHY_CSI_H_DBG;
typedef union {
 struct {
  unsigned int csih_force_pclk_on : 1 ;
  unsigned int rsv_130 : 31 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_H_FORCE_PCLKON;
typedef union {
 struct {
  unsigned int csi_abc_secure : 1 ;
  unsigned int csi_d_secure : 1 ;
  unsigned int csi_e_secure : 1 ;
  unsigned int csi_dbg_secure : 1 ;
  unsigned int csi_h_secure : 1 ;
  unsigned int rsv_131 : 1 ;
  unsigned int csi_f_secure : 1 ;
  unsigned int csi_g_secure : 1 ;
  unsigned int phy_a_secure : 1 ;
  unsigned int phy_b_secure : 1 ;
  unsigned int phy_c_secure : 1 ;
  unsigned int phy_d_secure : 1 ;
  unsigned int phy_e_secure : 1 ;
  unsigned int phy_f_secure : 1 ;
  unsigned int rsv_132 : 18 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_WRAPPER_S;
typedef union {
 struct {
  unsigned int csia_idi_clk_sel : 1 ;
  unsigned int csib_idi_clk_sel : 1 ;
  unsigned int csic_idi_clk_sel : 1 ;
  unsigned int csid_idi_clk_sel : 1 ;
  unsigned int csie_idi_clk_sel : 1 ;
  unsigned int csif_idi_clk_sel : 1 ;
  unsigned int csig_idi_clk_sel : 1 ;
  unsigned int csih_idi_clk_sel : 1 ;
  unsigned int rsv_133 : 24 ;
 } bits;
 unsigned int u32;
} CSI_WRAP_CSI_WRAP_CLK_CTRL;
typedef struct {
 CSI_WRAP_CSI_CGR_0 CSI_CGR_0 ;
 CSI_WRAP_CSI_CGR_0_SET CSI_CGR_0_SET ;
 CSI_WRAP_CSI_CGR_0_CLEAR CSI_CGR_0_CLEAR ;
 CSI_WRAP_CSI_RESET_0 CSI_RESET_0 ;
 CSI_WRAP_PHY_CSI_A_DBG PHY_CSI_A_DBG ;
 CSI_WRAP_PHY_CSI_B_DBG PHY_CSI_B_DBG ;
 CSI_WRAP_PHY_CSI_C_DBG PHY_CSI_C_DBG ;
 CSI_WRAP_CSI_ABC_IDI_SEL CSI_ABC_IDI_SEL ;
 CSI_WRAP_CSI_ABC_FORCE_PCLKON CSI_ABC_FORCE_PCLKON ;
 CSI_WRAP_CSI_WRAPPER_SECURE_ST CSI_WRAPPER_SECURE_ST ;
 CSI_WRAP_CSI_MUDP_RS_CLKRST CSI_MUDP_RS_CLKRST ;
 CSI_WRAP_CSI_RESERVED_0 CSI_RESERVED_0 ;
 CSI_WRAP_CSI_RESERVED_1 CSI_RESERVED_1 ;
 CSI_WRAP_CSI_CGR_1 CSI_CGR_1 ;
 CSI_WRAP_CSI_CGR_1_SET CSI_CGR_1_SET ;
 CSI_WRAP_CSI_CGR_1_CLEAR CSI_CGR_1_CLEAR ;
 CSI_WRAP_CSI_RESET_1 CSI_RESET_1 ;
 CSI_WRAP_PHY_CSI_D_DBG PHY_CSI_D_DBG ;
 CSI_WRAP_CSI_D_FORCE_PCLKON CSI_D_FORCE_PCLKON ;
 CSI_WRAP_CSI_CGR_2 CSI_CGR_2 ;
 CSI_WRAP_CSI_CGR_2_SET CSI_CGR_2_SET ;
 CSI_WRAP_CSI_CGR_2_CLEAR CSI_CGR_2_CLEAR ;
 CSI_WRAP_CSI_RESET_2 CSI_RESET_2 ;
 CSI_WRAP_PHY_CSI_E_DBG PHY_CSI_E_DBG ;
 CSI_WRAP_CSI_E_FORCE_PCLKON CSI_E_FORCE_PCLKON ;
 CSI_WRAP_CSIA_CTRL CSIA_CTRL ;
 CSI_WRAP_CSIB_CTRL CSIB_CTRL ;
 CSI_WRAP_CSIC_CTRL CSIC_CTRL ;
 CSI_WRAP_CSID_CTRL CSID_CTRL ;
 CSI_WRAP_CSIE_CTRL CSIE_CTRL ;
 CSI_WRAP_CSIF_CTRL CSIF_CTRL ;
 CSI_WRAP_CSIG_CTRL CSIG_CTRL ;
 CSI_WRAP_CSIH_CTRL CSIH_CTRL ;
 CSI_WRAP_CSI_DBG CSI_DBG ;
 CSI_WRAP_CSIA_DBG CSIA_DBG ;
 CSI_WRAP_CSIB_DBG CSIB_DBG ;
 CSI_WRAP_CSIC_DBG CSIC_DBG ;
 CSI_WRAP_CSID_DBG CSID_DBG ;
 CSI_WRAP_CSIE_DBG CSIE_DBG ;
 CSI_WRAP_CSIF_DBG CSIF_DBG ;
 CSI_WRAP_CSIG_DBG CSIG_DBG ;
 CSI_WRAP_PHY_DBG_TESTDOUT_SEL PHY_DBG_TESTDOUT_SEL ;
 CSI_WRAP_CSIH_DBG CSIH_DBG ;
 CSI_WRAP_CSIF_CGR CSIF_CGR ;
 CSI_WRAP_CSIF_CGR_SET CSIF_CGR_SET ;
 CSI_WRAP_CSIF_CGR_CLEAR CSIF_CGR_CLEAR ;
 CSI_WRAP_CSIF_RESET CSIF_RESET ;
 CSI_WRAP_PHY_CSI_F_DBG PHY_CSI_F_DBG ;
 CSI_WRAP_CSI_F_IDI_SEL CSI_F_IDI_SEL ;
 CSI_WRAP_CSI_F_FORCE_PCLKON CSI_F_FORCE_PCLKON ;
 CSI_WRAP_CSIG_CGR CSIG_CGR ;
 CSI_WRAP_CSIG_CGR_SET CSIG_CGR_SET ;
 CSI_WRAP_CSIG_CGR_CLEAR CSIG_CGR_CLEAR ;
 CSI_WRAP_CSIG_RESET CSIG_RESET ;
 CSI_WRAP_PHY_CSI_G_DBG PHY_CSI_G_DBG ;
 CSI_WRAP_CSI_G_IDI_SEL CSI_G_IDI_SEL ;
 CSI_WRAP_CSI_G_FORCE_PCLKON CSI_G_FORCE_PCLKON ;
 CSI_WRAP_CDPHY_A_TEST_CTRL CDPHY_A_TEST_CTRL ;
 CSI_WRAP_CDPHY_A_TEST_DOUT CDPHY_A_TEST_DOUT ;
 CSI_WRAP_CDPHY_A_SHUTDOWN_RST_CTRL CDPHY_A_SHUTDOWN_RST_CTRL ;
 CSI_WRAP_CDPHY_A_CTRL CDPHY_A_CTRL ;
 CSI_WRAP_CDPHY_A_LOCK_CTRL CDPHY_A_LOCK_CTRL ;
 CSI_WRAP_CDPHY_A_UNLOCK_CTRL CDPHY_A_UNLOCK_CTRL ;
 CSI_WRAP_CDPHY_A_LOCK_STATE CDPHY_A_LOCK_STATE ;
 CSI_WRAP_CDPHY_A_DBG CDPHY_A_DBG ;
 CSI_WRAP_CDPHY_A_CLKRST CDPHY_A_CLKRST ;
 CSI_WRAP_CDPHY_B_TEST_CTRL CDPHY_B_TEST_CTRL ;
 CSI_WRAP_CDPHY_B_TEST_DOUT CDPHY_B_TEST_DOUT ;
 CSI_WRAP_CDPHY_B_SHUTDOWN_RST_CTRL CDPHY_B_SHUTDOWN_RST_CTRL ;
 CSI_WRAP_CDPHY_B_CTRL CDPHY_B_CTRL ;
 CSI_WRAP_CDPHY_B_LOCK_CTRL CDPHY_B_LOCK_CTRL ;
 CSI_WRAP_CDPHY_B_UNLOCK_CTRL CDPHY_B_UNLOCK_CTRL ;
 CSI_WRAP_CDPHY_B_LOCK_STATE CDPHY_B_LOCK_STATE ;
 CSI_WRAP_CDPHY_B_DBG CDPHY_B_DBG ;
 CSI_WRAP_CDPHY_B_CLKRST CDPHY_B_CLKRST ;
 CSI_WRAP_CDPHY_C_TEST_CTRL CDPHY_C_TEST_CTRL ;
 CSI_WRAP_CDPHY_C_TEST_DOUT CDPHY_C_TEST_DOUT ;
 CSI_WRAP_CDPHY_C_SHUTDOWN_RST_CTRL CDPHY_C_SHUTDOWN_RST_CTRL ;
 CSI_WRAP_CDPHY_C_CTRL CDPHY_C_CTRL ;
 CSI_WRAP_CDPHY_C_LOCK_CTRL CDPHY_C_LOCK_CTRL ;
 CSI_WRAP_CDPHY_C_UNLOCK_CTRL CDPHY_C_UNLOCK_CTRL ;
 CSI_WRAP_CDPHY_C_LOCK_STATE CDPHY_C_LOCK_STATE ;
 CSI_WRAP_CDPHY_C_DBG CDPHY_C_DBG ;
 CSI_WRAP_CDPHY_C_CLKRST CDPHY_C_CLKRST ;
 CSI_WRAP_CDPHY_D_TEST_CTRL CDPHY_D_TEST_CTRL ;
 CSI_WRAP_CDPHY_D_TEST_DOUT CDPHY_D_TEST_DOUT ;
 CSI_WRAP_CDPHY_D_SHUTDOWN_RST_CTRL CDPHY_D_SHUTDOWN_RST_CTRL ;
 CSI_WRAP_CDPHY_D_CTRL CDPHY_D_CTRL ;
 CSI_WRAP_CDPHY_D_LOCK_CTRL CDPHY_D_LOCK_CTRL ;
 CSI_WRAP_CDPHY_D_UNLOCK_CTRL CDPHY_D_UNLOCK_CTRL ;
 CSI_WRAP_CDPHY_D_LOCK_STATE CDPHY_D_LOCK_STATE ;
 CSI_WRAP_CDPHY_D_DBG CDPHY_D_DBG ;
 CSI_WRAP_CDPHY_D_CLKRST CDPHY_D_CLKRST ;
 CSI_WRAP_CDPHY_E_TEST_CTRL CDPHY_E_TEST_CTRL ;
 CSI_WRAP_CDPHY_E_TEST_DOUT CDPHY_E_TEST_DOUT ;
 CSI_WRAP_CDPHY_E_SHUTDOWN_RST_CTRL CDPHY_E_SHUTDOWN_RST_CTRL ;
 CSI_WRAP_CDPHY_E_CTRL CDPHY_E_CTRL ;
 CSI_WRAP_CDPHY_E_LOCK_CTRL CDPHY_E_LOCK_CTRL ;
 CSI_WRAP_CDPHY_E_UNLOCK_CTRL CDPHY_E_UNLOCK_CTRL ;
 CSI_WRAP_CDPHY_E_LOCK_STATE CDPHY_E_LOCK_STATE ;
 CSI_WRAP_CDPHY_E_DBG CDPHY_E_DBG ;
 CSI_WRAP_CDPHY_E_CLKRST CDPHY_E_CLKRST ;
 CSI_WRAP_CDPHY_F_TEST_CTRL CDPHY_F_TEST_CTRL ;
 CSI_WRAP_CDPHY_F_TEST_DOUT CDPHY_F_TEST_DOUT ;
 CSI_WRAP_CDPHY_F_SHUTDOWN_RST_CTRL CDPHY_F_SHUTDOWN_RST_CTRL ;
 CSI_WRAP_CDPHY_F_CTRL CDPHY_F_CTRL ;
 CSI_WRAP_CDPHY_F_LOCK_CTRL CDPHY_F_LOCK_CTRL ;
 CSI_WRAP_CDPHY_F_UNLOCK_CTRL CDPHY_F_UNLOCK_CTRL ;
 CSI_WRAP_CDPHY_F_LOCK_STATE CDPHY_F_LOCK_STATE ;
 CSI_WRAP_CDPHY_F_DBG CDPHY_F_DBG ;
 CSI_WRAP_CDPHY_F_CLKRST CDPHY_F_CLKRST ;
 CSI_WRAP_CSIH_CGR CSIH_CGR ;
 CSI_WRAP_CSIH_CGR_SET CSIH_CGR_SET ;
 CSI_WRAP_CSIH_CGR_CLEAR CSIH_CGR_CLEAR ;
 CSI_WRAP_CSIH_RESET CSIH_RESET ;
 CSI_WRAP_PHY_CSI_H_DBG PHY_CSI_H_DBG ;
 CSI_WRAP_CSI_H_FORCE_PCLKON CSI_H_FORCE_PCLKON ;
 CSI_WRAP_CSI_WRAPPER_S CSI_WRAPPER_S ;
 CSI_WRAP_CSI_WRAP_CLK_CTRL CSI_WRAP_CLK_CTRL ;
} S_CSI_WRAP_REGS_TYPE;
#endif
