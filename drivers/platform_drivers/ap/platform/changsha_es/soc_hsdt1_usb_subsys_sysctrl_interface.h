#ifndef __SOC_HSDT1_USB_SUBSYS_SYSCTRL_INTERFACE_H__
#define __SOC_HSDT1_USB_SUBSYS_SYSCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HSDT1_usb_subsys_sysctrl_usb_controller_sel_ADDR(base) (base)
#define SOC_HSDT1_usb_subsys_sysctrl_dbg_utmi_rst_n_ADDR(base) ((base) + 0x0004UL)
#define SOC_HSDT1_usb_subsys_sysctrl_dbg_utmi_refresh_ADDR(base) ((base) + 0x0008UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_ADDR(base) ((base) + 0x000CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txdata_ADDR(base) ((base) + 0x0010UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_h_ADDR(base) ((base) + 0x0014UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txdata_h_ADDR(base) ((base) + 0x0018UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_ADDR(base) ((base) + 0x001CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txvalid_ADDR(base) ((base) + 0x0020UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_h_ADDR(base) ((base) + 0x0024UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txvalid_h_ADDR(base) ((base) + 0x0028UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txready_ADDR(base) ((base) + 0x002CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txready_ADDR(base) ((base) + 0x0030UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_ADDR(base) ((base) + 0x0034UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxdata_ADDR(base) ((base) + 0x0038UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_h_ADDR(base) ((base) + 0x003CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxdata_h_ADDR(base) ((base) + 0x0040UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_ADDR(base) ((base) + 0x0044UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxvalid_ADDR(base) ((base) + 0x0048UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_h_ADDR(base) ((base) + 0x004CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxvalid_h_ADDR(base) ((base) + 0x0050UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxerror_ADDR(base) ((base) + 0x0054UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxerror_ADDR(base) ((base) + 0x0058UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxactive_ADDR(base) ((base) + 0x005CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxactive_ADDR(base) ((base) + 0x0060UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_linerate_ADDR(base) ((base) + 0x0064UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_linerate_ADDR(base) ((base) + 0x0068UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_hostdisconnect_ADDR(base) ((base) + 0x006CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_hostdisconnect_ADDR(base) ((base) + 0x0070UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_xcvrselect_ADDR(base) ((base) + 0x0074UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_xcvrselect_ADDR(base) ((base) + 0x0078UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_termselect_ADDR(base) ((base) + 0x007CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_termselect_ADDR(base) ((base) + 0x0080UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_opmode_ADDR(base) ((base) + 0x0084UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_opmode_ADDR(base) ((base) + 0x0088UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_ADDR(base) ((base) + 0x008CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_ADDR(base) ((base) + 0x0090UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_h_ADDR(base) ((base) + 0x0094UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_h_ADDR(base) ((base) + 0x0098UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_suspend_n_ADDR(base) ((base) + 0x009CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_suspend_n_ADDR(base) ((base) + 0x00A0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_sleep_n_ADDR(base) ((base) + 0x00A4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_sleep_n_ADDR(base) ((base) + 0x00A8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dmpulldown_ADDR(base) ((base) + 0x00ACUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_dmpulldown_ADDR(base) ((base) + 0x00B0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dppulldown_ADDR(base) ((base) + 0x00B4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_dppulldown_ADDR(base) ((base) + 0x00B8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_vbusvalid_ADDR(base) ((base) + 0x00BCUL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_vbusvalid_ADDR(base) ((base) + 0x00C0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2p_otgsessvld_ADDR(base) ((base) + 0x0218UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2p_pll_lock_ADDR(base) ((base) + 0x0244UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2t5p_usb_test_bus_ADDR(base) ((base) + 0x0250UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_port_oca_ADDR(base) ((base) + 0x0268UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_logic_trace_31_0_ADDR(base) ((base) + 0x026CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_logic_trace_63_32_ADDR(base) ((base) + 0x0270UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_interrupt_ADDR(base) ((base) + 0x0274UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_sys_error_ADDR(base) ((base) + 0x0278UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_u2_disable_ADDR(base) ((base) + 0x027CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_u3_disable_ADDR(base) ((base) + 0x0280UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_utmi_ulpi_sel_ADDR(base) ((base) + 0x0284UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_utmi8bit_en_ADDR(base) ((base) + 0x0288UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_low_power_ADDR(base) ((base) + 0x028CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_ahbs_bigendian_ADDR(base) ((base) + 0x0290UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_axim_bigendian_ADDR(base) ((base) + 0x0294UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usbc_utmi_drvvbus_ADDR(base) ((base) + 0x0298UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxsyncheader_ADDR(base) ((base) + 0x029CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxstartblock_ADDR(base) ((base) + 0x02A0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_elasticbufferlocation_ADDR(base) ((base) + 0x02A4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_phy_mode_ADDR(base) ((base) + 0x02A8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_elasticity_buffer_mode_ADDR(base) ((base) + 0x02ACUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_width_ADDR(base) ((base) + 0x02B0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_pclk_rate_ADDR(base) ((base) + 0x02B4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txstartblock_ADDR(base) ((base) + 0x02B8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txmargin_ADDR(base) ((base) + 0x02BCUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txswing_ADDR(base) ((base) + 0x02C0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txsyncheader_ADDR(base) ((base) + 0x02C4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_blockaligncontrol_ADDR(base) ((base) + 0x02C8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxstandby_ADDR(base) ((base) + 0x02CCUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_encodedecodebypass_ADDR(base) ((base) + 0x02D0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usb_axi_arprd_qos_ADDR(base) ((base) + 0x02D4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usb_axi_awprd_qos_ADDR(base) ((base) + 0x02D8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_l1_suspend_n_ADDR(base) ((base) + 0x02DCUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_l1_suspend_com_n_ADDR(base) ((base) + 0x02E0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_suspend_com_n_ADDR(base) ((base) + 0x02E4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_word_if_ADDR(base) ((base) + 0x02E8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_fsls_low_power_ADDR(base) ((base) + 0x02ECUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_fslsserialmode_ADDR(base) ((base) + 0x02F0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_DataBusWidth_ADDR(base) ((base) + 0x02F4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_PHY_Mode_ADDR(base) ((base) + 0x02F8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_ElasBufferMode_ADDR(base) ((base) + 0x02FCUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_TxMargin_ADDR(base) ((base) + 0x0300UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_TxSwing_ADDR(base) ((base) + 0x0304UL)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_ADDR(base) ((base) + 0x0308UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_eop_timer_update_ADDR(base) ((base) + 0x0310UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_8bit_ls_eop_timer_ADDR(base) ((base) + 0x0314UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_16bit_ls_eop_timer_ADDR(base) ((base) + 0x0318UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_8bit_nols_eop_timer_ADDR(base) ((base) + 0x031CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_16bit_nols_eop_timer_ADDR(base) ((base) + 0x0320UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_valid_update_ADDR(base) ((base) + 0x0324UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_vbusvalid_ADDR(base) ((base) + 0x0328UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bvalid_ADDR(base) ((base) + 0x032CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_sessend_ADDR(base) ((base) + 0x0330UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bigendian_gs_ADDR(base) ((base) + 0x0334UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_31_0_ADDR(base) ((base) + 0x0338UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_63_32_ADDR(base) ((base) + 0x033CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_66_64_ADDR(base) ((base) + 0x0340UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_logic_analyzer_trace_31_0_ADDR(base) ((base) + 0x0344UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_logic_analyzer_trace_63_32_ADDR(base) ((base) + 0x0348UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_current_belt_ADDR(base) ((base) + 0x034CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_gp_out_ADDR(base) ((base) + 0x0350UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_gp_in_ADDR(base) ((base) + 0x0354UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pme_generation_ADDR(base) ((base) + 0x0358UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pme_en_ADDR(base) ((base) + 0x035CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_operational_mode_ADDR(base) ((base) + 0x0360UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_clk_gate_ctrl_ADDR(base) ((base) + 0x0364UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_vbus_ctrl_ADDR(base) ((base) + 0x0368UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_port_overcurrent_ADDR(base) ((base) + 0x036CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_port_perm_attach_ADDR(base) ((base) + 0x0370UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_num_u2_port_ADDR(base) ((base) + 0x0374UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_num_u3_port_ADDR(base) ((base) + 0x0378UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_u2_port_disable_ADDR(base) ((base) + 0x037CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_u3_port_disable_ADDR(base) ((base) + 0x0380UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_StartRxDetU3RxDet_ADDR(base) ((base) + 0x0384UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_DisRxDetU3RxDet_ADDR(base) ((base) + 0x0388UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_DisRxDetU3RxDet_ack_ADDR(base) ((base) + 0x038CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_port_power_control_present_ADDR(base) ((base) + 0x0390UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_msi_enable_ADDR(base) ((base) + 0x0394UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_pci_cmd_reg_wr_ADDR(base) ((base) + 0x0398UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_bar_wr_ADDR(base) ((base) + 0x039CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_interrupt_ADDR(base) ((base) + 0x03A0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_fladj_30mhz_reg_ADDR(base) ((base) + 0x03A4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xhc_bme_ADDR(base) ((base) + 0x03A8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_linestate_glitch_mark_ADDR(base) ((base) + 0x03ACUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bus_clken_gs_ADDR(base) ((base) + 0x03B0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bus_clken_gm_ADDR(base) ((base) + 0x03B4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_csysreq_ADDR(base) ((base) + 0x03B8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_csysack_ADDR(base) ((base) + 0x03BCUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_cactive_ADDR(base) ((base) + 0x03C0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram0_mem_ctrl_ADDR(base) ((base) + 0x03C4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram1_mem_ctrl_ADDR(base) ((base) + 0x03C8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram2_mem_ctrl_ADDR(base) ((base) + 0x03CCUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram0_mem_ctrl_ADDR(base) ((base) + 0x03D0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram1_mem_ctrl_ADDR(base) ((base) + 0x03D4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram2_mem_ctrl_ADDR(base) ((base) + 0x03D8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram3_mem_ctrl_ADDR(base) ((base) + 0x03DCUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram4_mem_ctrl_ADDR(base) ((base) + 0x03E0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_bandwidth_ADDR(base) ((base) + 0x03E4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_saturation_ADDR(base) ((base) + 0x03E8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_en_ADDR(base) ((base) + 0x03ECUL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_flux_ctrl_ADDR(base) ((base) + 0x03F0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_bandwidth_ADDR(base) ((base) + 0x03F4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_saturation_ADDR(base) ((base) + 0x03F8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_en_ADDR(base) ((base) + 0x03FCUL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_flux_ctrl_ADDR(base) ((base) + 0x0400UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_ADDR(base) ((base) + 0x0404UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_set_ADDR(base) ((base) + 0x0408UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_ADDR(base) ((base) + 0x040CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_set_ADDR(base) ((base) + 0x0410UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_ADDR(base) ((base) + 0x0414UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb3_testpoint_sel_ADDR(base) ((base) + 0x0418UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb3_testpoint_ADDR(base) ((base) + 0x041CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_cfg_pipe_powerpresent_ADDR(base) ((base) + 0x0420UL)
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_reset_n_ADDR(base) ((base) + 0x0424UL)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_port_reset_ADDR(base) ((base) + 0x0428UL)
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_phystatus_ADDR(base) ((base) + 0x042CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_his_usbc_pipe_compliance_ADDR(base) ((base) + 0x0430UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb3_u3_vbus_enable_ADDR(base) ((base) + 0x0434UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usbc_dbg_utmisrp_bvalid_ADDR(base) ((base) + 0x0438UL)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_snp_usbc_dbg_utmisrp_bvalid_ADDR(base) ((base) + 0x043CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb3_dbg_trace_mem_ctrl_bp_d1w2r_ADDR(base) ((base) + 0x0440UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20phy_rsv_in_ADDR(base) ((base) + 0x0444UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20phy_rsv_out_ADDR(base) ((base) + 0x0448UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_ok_ADDR(base) ((base) + 0x044CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_req_n_ADDR(base) ((base) + 0x0450UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_off_ADDR(base) ((base) + 0x0454UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_pclk_rate_ADDR(base) ((base) + 0x0458UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_width_ADDR(base) ((base) + 0x045CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_blkalignctrl_ADDR(base) ((base) + 0x0460UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_encodedecodebypass_ADDR(base) ((base) + 0x0464UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_txstartblock_ADDR(base) ((base) + 0x0468UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_txsyncheader_ADDR(base) ((base) + 0x046CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstartblock_ADDR(base) ((base) + 0x0470UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxsyncheader_ADDR(base) ((base) + 0x0474UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_elasticbufferlocation_ADDR(base) ((base) + 0x0478UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstandbystatus_ADDR(base) ((base) + 0x047CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstandby_ADDR(base) ((base) + 0x0480UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_host_force_gen1_speed_ADDR(base) ((base) + 0x0484UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_ptm_time_vld_ADDR(base) ((base) + 0x0488UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_ptm_time_ADDR(base) ((base) + 0x048CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_bus_filter_bypass_ADDR(base) ((base) + 0x0490UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_common_rd_wr_bus_ADDR(base) ((base) + 0x0494UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_rd_uF_kB_bandwidth_ADDR(base) ((base) + 0x0498UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_wr_uF_kB_bandwidth_ADDR(base) ((base) + 0x049CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_trace_sample_ctrl_ADDR(base) ((base) + 0x04A0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_qic_bus_usbc_axi_low_latency_ADDR(base) ((base) + 0x04A4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_ADDR(base) ((base) + 0x04A8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SNPS USB Controller QOS_ADDR(base) ((base) + 0x04ACUL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wakup_ctrl_ADDR(base) ((base) + 0x04B0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_linestate_filtter_time_ADDR(base) ((base) + 0x04B4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_wakup_int_ADDR(base) ((base) + 0x04B8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb20_utni_drvvbus_ADDR(base) ((base) + 0x04C0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb20_ram0_mem_ctrl_ADDR(base) ((base) + 0x04C4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_ADDR(base) ((base) + 0x04C8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_dbg_trace_mem_ctrl_bp_d1w2r_ADDR(base) ((base) + 0x04D0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram0_mem_ctrl_ADDR(base) ((base) + 0x04D4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram1_mem_ctrl_ADDR(base) ((base) + 0x04D8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram2_mem_ctrl_ADDR(base) ((base) + 0x04DCUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram3_mem_ctrl_ADDR(base) ((base) + 0x04E0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram4_mem_ctrl_ADDR(base) ((base) + 0x04E4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_err_inj_en_ADDR(base) ((base) + 0x04E8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_msi_en_ADDR(base) ((base) + 0x04ECUL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_bme_ADDR(base) ((base) + 0x04F0UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_axi_ruser_poison_ADDR(base) ((base) + 0x04F4UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_axi_wuser_poison_ADDR(base) ((base) + 0x04F8UL)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_inr_error_ADDR(base) ((base) + 0x04FCUL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnec_chk_cfg_ADDR(base) ((base) + 0x0500UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_chk_min_ADDR(base) ((base) + 0x0504UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_chk_max_ADDR(base) ((base) + 0x0508UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_int_ADDR(base) ((base) + 0x050CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_arvcidx_ADDR(base) ((base) + 0x0510UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_arvcidx_sel_ADDR(base) ((base) + 0x0514UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_awvcidx_ADDR(base) ((base) + 0x0518UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_awvcidx_sel_ADDR(base) ((base) + 0x051cUL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_idle_ADDR(base) ((base) + 0x0530UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wusr_ADDR(base) ((base) + 0x0540UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rusr_ADDR(base) ((base) + 0x0544UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wake_mode_ADDR(base) ((base) + 0x0550UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wake_clr_ADDR(base) ((base) + 0x0554UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_ADDR(base) ((base) + 0x0558UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_status_ADDR(base) ((base) + 0x055cUL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_status_aft_mask_ADDR(base) ((base) + 0x0560UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_mask_ADDR(base) ((base) + 0x0564UL)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_status_aft_mask_ADDR(base) ((base) + 0x0568UL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_ulpi_sel_indicator_ADDR(base) ((base) + 0x056cUL)
#define SOC_HSDT1_usb_subsys_sysctrl_usb20phy_ulpi_rst_ADDR(base) ((base) + 0x0570UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_ADDR(base) ((base) + 0x0A00UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_str_h_ADDR(base) ((base) + 0x0A04UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_str_l_ADDR(base) ((base) + 0x0A08UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_end_h_ADDR(base) ((base) + 0x0A0CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_end_l_ADDR(base) ((base) + 0x0A10UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_str_h_ADDR(base) ((base) + 0x0A14UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_str_l_ADDR(base) ((base) + 0x0A18UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_end_h_ADDR(base) ((base) + 0x0A1CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_end_l_ADDR(base) ((base) + 0x0A20UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_str_h_ADDR(base) ((base) + 0x0A24UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_str_l_ADDR(base) ((base) + 0x0A28UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_end_h_ADDR(base) ((base) + 0x0A2CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_end_l_ADDR(base) ((base) + 0x0A30UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_str_h_ADDR(base) ((base) + 0x0A34UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_str_l_ADDR(base) ((base) + 0x0A38UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_end_h_ADDR(base) ((base) + 0x0A3CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_end_l_ADDR(base) ((base) + 0x0A40UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_str_h_ADDR(base) ((base) + 0x0A44UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_str_l_ADDR(base) ((base) + 0x0A48UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_end_h_ADDR(base) ((base) + 0x0A4CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_end_l_ADDR(base) ((base) + 0x0A50UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_str_h_ADDR(base) ((base) + 0x0A54UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_str_l_ADDR(base) ((base) + 0x0A58UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_end_h_ADDR(base) ((base) + 0x0A5CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_end_l_ADDR(base) ((base) + 0x0A60UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_str_h_ADDR(base) ((base) + 0x0A64UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_str_l_ADDR(base) ((base) + 0x0A68UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_end_h_ADDR(base) ((base) + 0x0A6CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_end_l_ADDR(base) ((base) + 0x0A70UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_str_h_ADDR(base) ((base) + 0x0A74UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_str_l_ADDR(base) ((base) + 0x0A78UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_end_h_ADDR(base) ((base) + 0x0A7CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_end_l_ADDR(base) ((base) + 0x0A80UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr_remap_h_ADDR(base) ((base) + 0x0A84UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr_remap_l_ADDR(base) ((base) + 0x0A88UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr_remap_h_ADDR(base) ((base) + 0x0A8CUL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr_remap_l_ADDR(base) ((base) + 0x0A90UL)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_remap_ADDR(base) ((base) + 0x0A94UL)
#else
#define SOC_HSDT1_usb_subsys_sysctrl_usb_controller_sel_ADDR(base) (base)
#define SOC_HSDT1_usb_subsys_sysctrl_dbg_utmi_rst_n_ADDR(base) ((base) + 0x0004)
#define SOC_HSDT1_usb_subsys_sysctrl_dbg_utmi_refresh_ADDR(base) ((base) + 0x0008)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_ADDR(base) ((base) + 0x000C)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txdata_ADDR(base) ((base) + 0x0010)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_h_ADDR(base) ((base) + 0x0014)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txdata_h_ADDR(base) ((base) + 0x0018)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_ADDR(base) ((base) + 0x001C)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txvalid_ADDR(base) ((base) + 0x0020)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_h_ADDR(base) ((base) + 0x0024)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txvalid_h_ADDR(base) ((base) + 0x0028)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txready_ADDR(base) ((base) + 0x002C)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txready_ADDR(base) ((base) + 0x0030)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_ADDR(base) ((base) + 0x0034)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxdata_ADDR(base) ((base) + 0x0038)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_h_ADDR(base) ((base) + 0x003C)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxdata_h_ADDR(base) ((base) + 0x0040)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_ADDR(base) ((base) + 0x0044)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxvalid_ADDR(base) ((base) + 0x0048)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_h_ADDR(base) ((base) + 0x004C)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxvalid_h_ADDR(base) ((base) + 0x0050)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxerror_ADDR(base) ((base) + 0x0054)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxerror_ADDR(base) ((base) + 0x0058)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxactive_ADDR(base) ((base) + 0x005C)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxactive_ADDR(base) ((base) + 0x0060)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_linerate_ADDR(base) ((base) + 0x0064)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_linerate_ADDR(base) ((base) + 0x0068)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_hostdisconnect_ADDR(base) ((base) + 0x006C)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_hostdisconnect_ADDR(base) ((base) + 0x0070)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_xcvrselect_ADDR(base) ((base) + 0x0074)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_xcvrselect_ADDR(base) ((base) + 0x0078)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_termselect_ADDR(base) ((base) + 0x007C)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_termselect_ADDR(base) ((base) + 0x0080)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_opmode_ADDR(base) ((base) + 0x0084)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_opmode_ADDR(base) ((base) + 0x0088)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_ADDR(base) ((base) + 0x008C)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_ADDR(base) ((base) + 0x0090)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_h_ADDR(base) ((base) + 0x0094)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_h_ADDR(base) ((base) + 0x0098)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_suspend_n_ADDR(base) ((base) + 0x009C)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_suspend_n_ADDR(base) ((base) + 0x00A0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_sleep_n_ADDR(base) ((base) + 0x00A4)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_sleep_n_ADDR(base) ((base) + 0x00A8)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dmpulldown_ADDR(base) ((base) + 0x00AC)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_dmpulldown_ADDR(base) ((base) + 0x00B0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dppulldown_ADDR(base) ((base) + 0x00B4)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_dppulldown_ADDR(base) ((base) + 0x00B8)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_vbusvalid_ADDR(base) ((base) + 0x00BC)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_vbusvalid_ADDR(base) ((base) + 0x00C0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2p_otgsessvld_ADDR(base) ((base) + 0x0218)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2p_pll_lock_ADDR(base) ((base) + 0x0244)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2t5p_usb_test_bus_ADDR(base) ((base) + 0x0250)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_port_oca_ADDR(base) ((base) + 0x0268)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_logic_trace_31_0_ADDR(base) ((base) + 0x026C)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_logic_trace_63_32_ADDR(base) ((base) + 0x0270)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_interrupt_ADDR(base) ((base) + 0x0274)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_sys_error_ADDR(base) ((base) + 0x0278)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_u2_disable_ADDR(base) ((base) + 0x027C)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_u3_disable_ADDR(base) ((base) + 0x0280)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_utmi_ulpi_sel_ADDR(base) ((base) + 0x0284)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_utmi8bit_en_ADDR(base) ((base) + 0x0288)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_low_power_ADDR(base) ((base) + 0x028C)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_ahbs_bigendian_ADDR(base) ((base) + 0x0290)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_axim_bigendian_ADDR(base) ((base) + 0x0294)
#define SOC_HSDT1_usb_subsys_sysctrl_usbc_utmi_drvvbus_ADDR(base) ((base) + 0x0298)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxsyncheader_ADDR(base) ((base) + 0x029C)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxstartblock_ADDR(base) ((base) + 0x02A0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_elasticbufferlocation_ADDR(base) ((base) + 0x02A4)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_phy_mode_ADDR(base) ((base) + 0x02A8)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_elasticity_buffer_mode_ADDR(base) ((base) + 0x02AC)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_width_ADDR(base) ((base) + 0x02B0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_pclk_rate_ADDR(base) ((base) + 0x02B4)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txstartblock_ADDR(base) ((base) + 0x02B8)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txmargin_ADDR(base) ((base) + 0x02BC)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txswing_ADDR(base) ((base) + 0x02C0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txsyncheader_ADDR(base) ((base) + 0x02C4)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_blockaligncontrol_ADDR(base) ((base) + 0x02C8)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxstandby_ADDR(base) ((base) + 0x02CC)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_encodedecodebypass_ADDR(base) ((base) + 0x02D0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usb_axi_arprd_qos_ADDR(base) ((base) + 0x02D4)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usb_axi_awprd_qos_ADDR(base) ((base) + 0x02D8)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_l1_suspend_n_ADDR(base) ((base) + 0x02DC)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_l1_suspend_com_n_ADDR(base) ((base) + 0x02E0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_suspend_com_n_ADDR(base) ((base) + 0x02E4)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_word_if_ADDR(base) ((base) + 0x02E8)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_fsls_low_power_ADDR(base) ((base) + 0x02EC)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_fslsserialmode_ADDR(base) ((base) + 0x02F0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_DataBusWidth_ADDR(base) ((base) + 0x02F4)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_PHY_Mode_ADDR(base) ((base) + 0x02F8)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_ElasBufferMode_ADDR(base) ((base) + 0x02FC)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_TxMargin_ADDR(base) ((base) + 0x0300)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_TxSwing_ADDR(base) ((base) + 0x0304)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_ADDR(base) ((base) + 0x0308)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_eop_timer_update_ADDR(base) ((base) + 0x0310)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_8bit_ls_eop_timer_ADDR(base) ((base) + 0x0314)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_16bit_ls_eop_timer_ADDR(base) ((base) + 0x0318)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_8bit_nols_eop_timer_ADDR(base) ((base) + 0x031C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_16bit_nols_eop_timer_ADDR(base) ((base) + 0x0320)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_valid_update_ADDR(base) ((base) + 0x0324)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_vbusvalid_ADDR(base) ((base) + 0x0328)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bvalid_ADDR(base) ((base) + 0x032C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_sessend_ADDR(base) ((base) + 0x0330)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bigendian_gs_ADDR(base) ((base) + 0x0334)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_31_0_ADDR(base) ((base) + 0x0338)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_63_32_ADDR(base) ((base) + 0x033C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_66_64_ADDR(base) ((base) + 0x0340)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_logic_analyzer_trace_31_0_ADDR(base) ((base) + 0x0344)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_logic_analyzer_trace_63_32_ADDR(base) ((base) + 0x0348)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_current_belt_ADDR(base) ((base) + 0x034C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_gp_out_ADDR(base) ((base) + 0x0350)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_gp_in_ADDR(base) ((base) + 0x0354)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pme_generation_ADDR(base) ((base) + 0x0358)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pme_en_ADDR(base) ((base) + 0x035C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_operational_mode_ADDR(base) ((base) + 0x0360)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_clk_gate_ctrl_ADDR(base) ((base) + 0x0364)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_vbus_ctrl_ADDR(base) ((base) + 0x0368)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_port_overcurrent_ADDR(base) ((base) + 0x036C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_port_perm_attach_ADDR(base) ((base) + 0x0370)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_num_u2_port_ADDR(base) ((base) + 0x0374)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_num_u3_port_ADDR(base) ((base) + 0x0378)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_u2_port_disable_ADDR(base) ((base) + 0x037C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_u3_port_disable_ADDR(base) ((base) + 0x0380)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_StartRxDetU3RxDet_ADDR(base) ((base) + 0x0384)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_DisRxDetU3RxDet_ADDR(base) ((base) + 0x0388)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_DisRxDetU3RxDet_ack_ADDR(base) ((base) + 0x038C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_port_power_control_present_ADDR(base) ((base) + 0x0390)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_msi_enable_ADDR(base) ((base) + 0x0394)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_pci_cmd_reg_wr_ADDR(base) ((base) + 0x0398)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_bar_wr_ADDR(base) ((base) + 0x039C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_interrupt_ADDR(base) ((base) + 0x03A0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_fladj_30mhz_reg_ADDR(base) ((base) + 0x03A4)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xhc_bme_ADDR(base) ((base) + 0x03A8)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_linestate_glitch_mark_ADDR(base) ((base) + 0x03AC)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bus_clken_gs_ADDR(base) ((base) + 0x03B0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bus_clken_gm_ADDR(base) ((base) + 0x03B4)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_csysreq_ADDR(base) ((base) + 0x03B8)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_csysack_ADDR(base) ((base) + 0x03BC)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_cactive_ADDR(base) ((base) + 0x03C0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram0_mem_ctrl_ADDR(base) ((base) + 0x03C4)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram1_mem_ctrl_ADDR(base) ((base) + 0x03C8)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram2_mem_ctrl_ADDR(base) ((base) + 0x03CC)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram0_mem_ctrl_ADDR(base) ((base) + 0x03D0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram1_mem_ctrl_ADDR(base) ((base) + 0x03D4)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram2_mem_ctrl_ADDR(base) ((base) + 0x03D8)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram3_mem_ctrl_ADDR(base) ((base) + 0x03DC)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram4_mem_ctrl_ADDR(base) ((base) + 0x03E0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_bandwidth_ADDR(base) ((base) + 0x03E4)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_saturation_ADDR(base) ((base) + 0x03E8)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_en_ADDR(base) ((base) + 0x03EC)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_flux_ctrl_ADDR(base) ((base) + 0x03F0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_bandwidth_ADDR(base) ((base) + 0x03F4)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_saturation_ADDR(base) ((base) + 0x03F8)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_en_ADDR(base) ((base) + 0x03FC)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_flux_ctrl_ADDR(base) ((base) + 0x0400)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_ADDR(base) ((base) + 0x0404)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_set_ADDR(base) ((base) + 0x0408)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_ADDR(base) ((base) + 0x040C)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_set_ADDR(base) ((base) + 0x0410)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_ADDR(base) ((base) + 0x0414)
#define SOC_HSDT1_usb_subsys_sysctrl_usb3_testpoint_sel_ADDR(base) ((base) + 0x0418)
#define SOC_HSDT1_usb_subsys_sysctrl_usb3_testpoint_ADDR(base) ((base) + 0x041C)
#define SOC_HSDT1_usb_subsys_sysctrl_cfg_pipe_powerpresent_ADDR(base) ((base) + 0x0420)
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_reset_n_ADDR(base) ((base) + 0x0424)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_port_reset_ADDR(base) ((base) + 0x0428)
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_phystatus_ADDR(base) ((base) + 0x042C)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_his_usbc_pipe_compliance_ADDR(base) ((base) + 0x0430)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb3_u3_vbus_enable_ADDR(base) ((base) + 0x0434)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usbc_dbg_utmisrp_bvalid_ADDR(base) ((base) + 0x0438)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_snp_usbc_dbg_utmisrp_bvalid_ADDR(base) ((base) + 0x043C)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb3_dbg_trace_mem_ctrl_bp_d1w2r_ADDR(base) ((base) + 0x0440)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20phy_rsv_in_ADDR(base) ((base) + 0x0444)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20phy_rsv_out_ADDR(base) ((base) + 0x0448)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_ok_ADDR(base) ((base) + 0x044C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_req_n_ADDR(base) ((base) + 0x0450)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_off_ADDR(base) ((base) + 0x0454)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_pclk_rate_ADDR(base) ((base) + 0x0458)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_width_ADDR(base) ((base) + 0x045C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_blkalignctrl_ADDR(base) ((base) + 0x0460)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_encodedecodebypass_ADDR(base) ((base) + 0x0464)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_txstartblock_ADDR(base) ((base) + 0x0468)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_txsyncheader_ADDR(base) ((base) + 0x046C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstartblock_ADDR(base) ((base) + 0x0470)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxsyncheader_ADDR(base) ((base) + 0x0474)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_elasticbufferlocation_ADDR(base) ((base) + 0x0478)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstandbystatus_ADDR(base) ((base) + 0x047C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstandby_ADDR(base) ((base) + 0x0480)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_host_force_gen1_speed_ADDR(base) ((base) + 0x0484)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_ptm_time_vld_ADDR(base) ((base) + 0x0488)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_ptm_time_ADDR(base) ((base) + 0x048C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_bus_filter_bypass_ADDR(base) ((base) + 0x0490)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_common_rd_wr_bus_ADDR(base) ((base) + 0x0494)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_rd_uF_kB_bandwidth_ADDR(base) ((base) + 0x0498)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_wr_uF_kB_bandwidth_ADDR(base) ((base) + 0x049C)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_trace_sample_ctrl_ADDR(base) ((base) + 0x04A0)
#define SOC_HSDT1_usb_subsys_sysctrl_qic_bus_usbc_axi_low_latency_ADDR(base) ((base) + 0x04A4)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_ADDR(base) ((base) + 0x04A8)
#define SOC_HSDT1_usb_subsys_sysctrl_SNPS USB Controller QOS_ADDR(base) ((base) + 0x04AC)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wakup_ctrl_ADDR(base) ((base) + 0x04B0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_linestate_filtter_time_ADDR(base) ((base) + 0x04B4)
#define SOC_HSDT1_usb_subsys_sysctrl_wakup_int_ADDR(base) ((base) + 0x04B8)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb20_utni_drvvbus_ADDR(base) ((base) + 0x04C0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb20_ram0_mem_ctrl_ADDR(base) ((base) + 0x04C4)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_ADDR(base) ((base) + 0x04C8)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_dbg_trace_mem_ctrl_bp_d1w2r_ADDR(base) ((base) + 0x04D0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram0_mem_ctrl_ADDR(base) ((base) + 0x04D4)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram1_mem_ctrl_ADDR(base) ((base) + 0x04D8)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram2_mem_ctrl_ADDR(base) ((base) + 0x04DC)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram3_mem_ctrl_ADDR(base) ((base) + 0x04E0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram4_mem_ctrl_ADDR(base) ((base) + 0x04E4)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_err_inj_en_ADDR(base) ((base) + 0x04E8)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_msi_en_ADDR(base) ((base) + 0x04EC)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_bme_ADDR(base) ((base) + 0x04F0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_axi_ruser_poison_ADDR(base) ((base) + 0x04F4)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_axi_wuser_poison_ADDR(base) ((base) + 0x04F8)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_inr_error_ADDR(base) ((base) + 0x04FC)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnec_chk_cfg_ADDR(base) ((base) + 0x0500)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_chk_min_ADDR(base) ((base) + 0x0504)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_chk_max_ADDR(base) ((base) + 0x0508)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_int_ADDR(base) ((base) + 0x050C)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_arvcidx_ADDR(base) ((base) + 0x0510)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_arvcidx_sel_ADDR(base) ((base) + 0x0514)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_awvcidx_ADDR(base) ((base) + 0x0518)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_awvcidx_sel_ADDR(base) ((base) + 0x051c)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_idle_ADDR(base) ((base) + 0x0530)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wusr_ADDR(base) ((base) + 0x0540)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rusr_ADDR(base) ((base) + 0x0544)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wake_mode_ADDR(base) ((base) + 0x0550)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wake_clr_ADDR(base) ((base) + 0x0554)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_ADDR(base) ((base) + 0x0558)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_status_ADDR(base) ((base) + 0x055c)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_status_aft_mask_ADDR(base) ((base) + 0x0560)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_mask_ADDR(base) ((base) + 0x0564)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_status_aft_mask_ADDR(base) ((base) + 0x0568)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_ulpi_sel_indicator_ADDR(base) ((base) + 0x056c)
#define SOC_HSDT1_usb_subsys_sysctrl_usb20phy_ulpi_rst_ADDR(base) ((base) + 0x0570)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_ADDR(base) ((base) + 0x0A00)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_str_h_ADDR(base) ((base) + 0x0A04)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_str_l_ADDR(base) ((base) + 0x0A08)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_end_h_ADDR(base) ((base) + 0x0A0C)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_end_l_ADDR(base) ((base) + 0x0A10)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_str_h_ADDR(base) ((base) + 0x0A14)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_str_l_ADDR(base) ((base) + 0x0A18)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_end_h_ADDR(base) ((base) + 0x0A1C)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_end_l_ADDR(base) ((base) + 0x0A20)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_str_h_ADDR(base) ((base) + 0x0A24)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_str_l_ADDR(base) ((base) + 0x0A28)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_end_h_ADDR(base) ((base) + 0x0A2C)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_end_l_ADDR(base) ((base) + 0x0A30)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_str_h_ADDR(base) ((base) + 0x0A34)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_str_l_ADDR(base) ((base) + 0x0A38)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_end_h_ADDR(base) ((base) + 0x0A3C)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_end_l_ADDR(base) ((base) + 0x0A40)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_str_h_ADDR(base) ((base) + 0x0A44)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_str_l_ADDR(base) ((base) + 0x0A48)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_end_h_ADDR(base) ((base) + 0x0A4C)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_end_l_ADDR(base) ((base) + 0x0A50)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_str_h_ADDR(base) ((base) + 0x0A54)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_str_l_ADDR(base) ((base) + 0x0A58)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_end_h_ADDR(base) ((base) + 0x0A5C)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_end_l_ADDR(base) ((base) + 0x0A60)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_str_h_ADDR(base) ((base) + 0x0A64)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_str_l_ADDR(base) ((base) + 0x0A68)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_end_h_ADDR(base) ((base) + 0x0A6C)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_end_l_ADDR(base) ((base) + 0x0A70)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_str_h_ADDR(base) ((base) + 0x0A74)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_str_l_ADDR(base) ((base) + 0x0A78)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_end_h_ADDR(base) ((base) + 0x0A7C)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_end_l_ADDR(base) ((base) + 0x0A80)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr_remap_h_ADDR(base) ((base) + 0x0A84)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr_remap_l_ADDR(base) ((base) + 0x0A88)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr_remap_h_ADDR(base) ((base) + 0x0A8C)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr_remap_l_ADDR(base) ((base) + 0x0A90)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_remap_ADDR(base) ((base) + 0x0A94)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_controller_software_sel : 2;
        unsigned int STATUS_efuse_usb_controller_sel : 2;
        unsigned int STATUS_usb_controller_sel : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_controller_sel_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_controller_sel_SET_usb_controller_software_sel_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_controller_sel_SET_usb_controller_software_sel_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_controller_sel_STATUS_efuse_usb_controller_sel_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_controller_sel_STATUS_efuse_usb_controller_sel_END (3)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_controller_sel_STATUS_usb_controller_sel_START (4)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_controller_sel_STATUS_usb_controller_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_dbg_utmi_rst_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_dbg_utmi_rst_n_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_dbg_utmi_rst_n_SET_dbg_utmi_rst_n_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_dbg_utmi_rst_n_SET_dbg_utmi_rst_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_dbg_utmi_refresh : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_dbg_utmi_refresh_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_dbg_utmi_refresh_SET_dbg_utmi_refresh_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_dbg_utmi_refresh_SET_dbg_utmi_refresh_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_txdata : 8;
        unsigned int SEL_utmi_txdata : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_SET_utmi_txdata_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_SET_utmi_txdata_END (7)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_SEL_utmi_txdata_START (8)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_SEL_utmi_txdata_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_txdata : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txdata_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txdata_STATUS_utmi_txdata_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txdata_STATUS_utmi_txdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_txdata_h : 8;
        unsigned int SEL_utmi_txdata_h : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_h_SET_utmi_txdata_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_h_SET_utmi_txdata_h_END (7)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_h_SEL_utmi_txdata_h_START (8)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txdata_h_SEL_utmi_txdata_h_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_txdata_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txdata_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txdata_h_STATUS_utmi_txdata_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txdata_h_STATUS_utmi_txdata_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_txvalid : 1;
        unsigned int SEL_utmi_txvalid : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_SET_utmi_txvalid_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_SET_utmi_txvalid_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_SEL_utmi_txvalid_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_SEL_utmi_txvalid_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_txvalid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txvalid_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txvalid_STATUS_utmi_txvalid_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txvalid_STATUS_utmi_txvalid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_txvalid_h : 1;
        unsigned int SEL_utmi_txvalid_h : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_h_SET_utmi_txvalid_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_h_SET_utmi_txvalid_h_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_h_SEL_utmi_txvalid_h_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txvalid_h_SEL_utmi_txvalid_h_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_txvalid_h : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txvalid_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txvalid_h_STATUS_utmi_txvalid_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txvalid_h_STATUS_utmi_txvalid_h_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_txready : 1;
        unsigned int SEL_utmi_txready : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_txready_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txready_SET_utmi_txready_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txready_SET_utmi_txready_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txready_SEL_utmi_txready_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txready_SEL_utmi_txready_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_txready : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txready_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txready_STATUS_utmi_txready_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txready_STATUS_utmi_txready_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_rxdata : 8;
        unsigned int SEL_utmi_rxdata : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_SET_utmi_rxdata_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_SET_utmi_rxdata_END (7)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_SEL_utmi_rxdata_START (8)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_SEL_utmi_rxdata_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_rxdata : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxdata_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxdata_STATUS_utmi_rxdata_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxdata_STATUS_utmi_rxdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_rxdata_h : 8;
        unsigned int SEL_utmi_rxdata_h : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_h_SET_utmi_rxdata_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_h_SET_utmi_rxdata_h_END (7)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_h_SEL_utmi_rxdata_h_START (8)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxdata_h_SEL_utmi_rxdata_h_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_rxdata_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxdata_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxdata_h_STATUS_utmi_rxdata_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxdata_h_STATUS_utmi_rxdata_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_rxvalid : 1;
        unsigned int SEL_utmi_rxvalid : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_SET_utmi_rxvalid_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_SET_utmi_rxvalid_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_SEL_utmi_rxvalid_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_SEL_utmi_rxvalid_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_rxvalid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxvalid_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxvalid_STATUS_utmi_rxvalid_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxvalid_STATUS_utmi_rxvalid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_rxvalid_h : 1;
        unsigned int SEL_utmi_rxvalid_h : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_h_SET_utmi_rxvalid_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_h_SET_utmi_rxvalid_h_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_h_SEL_utmi_rxvalid_h_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxvalid_h_SEL_utmi_rxvalid_h_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_rxvalid_h : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxvalid_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxvalid_h_STATUS_utmi_rxvalid_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxvalid_h_STATUS_utmi_rxvalid_h_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_rxerror : 1;
        unsigned int SEL_utmi_rxerror : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_rxerror_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxerror_SET_utmi_rxerror_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxerror_SET_utmi_rxerror_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxerror_SEL_utmi_rxerror_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxerror_SEL_utmi_rxerror_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_rxerror : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxerror_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxerror_STATUS_utmi_rxerror_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxerror_STATUS_utmi_rxerror_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_rxactive : 1;
        unsigned int SEL_utmi_rxactive : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_rxactive_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxactive_SET_utmi_rxactive_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxactive_SET_utmi_rxactive_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxactive_SEL_utmi_rxactive_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_rxactive_SEL_utmi_rxactive_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_rxactive : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxactive_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxactive_STATUS_utmi_rxactive_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_rxactive_STATUS_utmi_rxactive_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_linerate : 2;
        unsigned int SEL_utmi_linerate : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_linerate_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_linerate_SET_utmi_linerate_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_linerate_SET_utmi_linerate_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_linerate_SEL_utmi_linerate_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_linerate_SEL_utmi_linerate_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_linerate : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_linerate_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_linerate_STATUS_utmi_linerate_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_linerate_STATUS_utmi_linerate_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_hostdisconnect : 1;
        unsigned int SEL_utmi_hostdisconnect : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_hostdisconnect_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_hostdisconnect_SET_utmi_hostdisconnect_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_hostdisconnect_SET_utmi_hostdisconnect_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_hostdisconnect_SEL_utmi_hostdisconnect_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_hostdisconnect_SEL_utmi_hostdisconnect_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_hostdisconnect : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_hostdisconnect_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_hostdisconnect_STATUS_utmi_hostdisconnect_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_hostdisconnect_STATUS_utmi_hostdisconnect_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_xcvrselect : 2;
        unsigned int SEL_utmi_xcvrselect : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_xcvrselect_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_xcvrselect_SET_utmi_xcvrselect_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_xcvrselect_SET_utmi_xcvrselect_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_xcvrselect_SEL_utmi_xcvrselect_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_xcvrselect_SEL_utmi_xcvrselect_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_xcvrselect : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_xcvrselect_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_xcvrselect_STATUS_utmi_xcvrselect_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_xcvrselect_STATUS_utmi_xcvrselect_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_termselect : 1;
        unsigned int SEL_utmi_termselect : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_termselect_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_termselect_SET_utmi_termselect_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_termselect_SET_utmi_termselect_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_termselect_SEL_utmi_termselect_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_termselect_SEL_utmi_termselect_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_termselect : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_termselect_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_termselect_STATUS_utmi_termselect_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_termselect_STATUS_utmi_termselect_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_opmode : 2;
        unsigned int SEL_utmi_opmode : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_opmode_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_opmode_SET_utmi_opmode_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_opmode_SET_utmi_opmode_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_opmode_SEL_utmi_opmode_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_opmode_SEL_utmi_opmode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_opmode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_opmode_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_opmode_STATUS_utmi_opmode_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_opmode_STATUS_utmi_opmode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_txbitstuffenable : 1;
        unsigned int SEL_utmi_txbitstuffenable : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_SET_utmi_txbitstuffenable_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_SET_utmi_txbitstuffenable_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_SEL_utmi_txbitstuffenable_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_SEL_utmi_txbitstuffenable_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_txbitstuffenable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_STATUS_utmi_txbitstuffenable_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_STATUS_utmi_txbitstuffenable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_txbitstuffenable_h : 1;
        unsigned int SEL_utmi_txbitstuffenable_h : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_h_SET_utmi_txbitstuffenable_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_h_SET_utmi_txbitstuffenable_h_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_h_SEL_utmi_txbitstuffenable_h_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_txbitstuffenable_h_SEL_utmi_txbitstuffenable_h_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_txbitstuffenable_h : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_h_STATUS_utmi_txbitstuffenable_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_h_STATUS_utmi_txbitstuffenable_h_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_suspend_n : 1;
        unsigned int SEL_utmi_suspend_n : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_suspend_n_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_suspend_n_SET_utmi_suspend_n_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_suspend_n_SET_utmi_suspend_n_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_suspend_n_SEL_utmi_suspend_n_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_suspend_n_SEL_utmi_suspend_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_suspend_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_suspend_n_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_suspend_n_STATUS_utmi_suspend_n_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_suspend_n_STATUS_utmi_suspend_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_sleep_n : 1;
        unsigned int SEL_utmi_sleep_n : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_sleep_n_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_sleep_n_SET_utmi_sleep_n_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_sleep_n_SET_utmi_sleep_n_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_sleep_n_SEL_utmi_sleep_n_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_sleep_n_SEL_utmi_sleep_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_sleep_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_sleep_n_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_sleep_n_STATUS_utmi_sleep_n_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_sleep_n_STATUS_utmi_sleep_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_dmpulldown : 1;
        unsigned int SEL_utmi_dmpulldown : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_dmpulldown_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dmpulldown_SET_utmi_dmpulldown_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dmpulldown_SET_utmi_dmpulldown_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dmpulldown_SEL_utmi_dmpulldown_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dmpulldown_SEL_utmi_dmpulldown_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_dmpulldown : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_dmpulldown_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_dmpulldown_STATUS_utmi_dmpulldown_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_dmpulldown_STATUS_utmi_dmpulldown_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_dppulldown : 1;
        unsigned int SEL_utmi_dppulldown : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_dppulldown_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dppulldown_SET_utmi_dppulldown_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dppulldown_SET_utmi_dppulldown_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dppulldown_SEL_utmi_dppulldown_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_dppulldown_SEL_utmi_dppulldown_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_dppulldown : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_dppulldown_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_dppulldown_STATUS_utmi_dppulldown_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_dppulldown_STATUS_utmi_dppulldown_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_utmi_vbusvalid : 1;
        unsigned int SEL_utmi_vbusvalid : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_vbusvalid_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_vbusvalid_SET_utmi_vbusvalid_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_vbusvalid_SET_utmi_vbusvalid_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_vbusvalid_SEL_utmi_vbusvalid_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_vbusvalid_SEL_utmi_vbusvalid_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_utmi_vbusvalid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_vbusvalid_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_vbusvalid_STATUS_utmi_vbusvalid_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_utmi_vbusvalid_STATUS_utmi_vbusvalid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_usb2p_otgsessvld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb2p_otgsessvld_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb2p_otgsessvld_STATUS_usb2p_otgsessvld_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2p_otgsessvld_STATUS_usb2p_otgsessvld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_usb2p_pll_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb2p_pll_lock_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb2p_pll_lock_STATUS_usb2p_pll_lock_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2p_pll_lock_STATUS_usb2p_pll_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_usb2p_usb_test_bus : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb2t5p_usb_test_bus_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb2t5p_usb_test_bus_STATUS_usb2p_usb_test_bus_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2t5p_usb_test_bus_STATUS_usb2p_usb_test_bus_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_dbg_usbc_port_oca : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_port_oca_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_port_oca_SET_his_dbg_usbc_port_oca_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_port_oca_SET_his_dbg_usbc_port_oca_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_usbc_logic_trace_31_0 : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_logic_trace_31_0_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_logic_trace_31_0_STATUS_his_dbg_usbc_logic_trace_31_0_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_logic_trace_31_0_STATUS_his_dbg_usbc_logic_trace_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_usbc_logic_trace_63_32 : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_logic_trace_63_32_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_logic_trace_63_32_STATUS_his_dbg_usbc_logic_trace_63_32_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_logic_trace_63_32_STATUS_his_dbg_usbc_logic_trace_63_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_usbc_interrupt : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usbc_interrupt_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_interrupt_STATUS_his_usbc_interrupt_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_interrupt_STATUS_his_usbc_interrupt_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_usbc_sys_error : 1;
        unsigned int SET_his_usbc_sys_error : 1;
        unsigned int SEL_his_usbc_sys_error : 1;
        unsigned int STATUS_his_usbc_sys_error_after_mask : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usbc_sys_error_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_sys_error_STATUS_his_usbc_sys_error_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_sys_error_STATUS_his_usbc_sys_error_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_sys_error_SET_his_usbc_sys_error_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_sys_error_SET_his_usbc_sys_error_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_sys_error_SEL_his_usbc_sys_error_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_sys_error_SEL_his_usbc_sys_error_END (2)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_sys_error_STATUS_his_usbc_sys_error_after_mask_START (3)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usbc_sys_error_STATUS_his_usbc_sys_error_after_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_dbg_usbc_u2_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_u2_disable_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_u2_disable_SET_his_dbg_usbc_u2_disable_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_u2_disable_SET_his_dbg_usbc_u2_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_dbg_usbc_u3_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_u3_disable_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_u3_disable_SET_his_dbg_usbc_u3_disable_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_u3_disable_SET_his_dbg_usbc_u3_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_dbg_usbc_utmi_ulpi_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_utmi_ulpi_sel_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_utmi_ulpi_sel_SET_his_dbg_usbc_utmi_ulpi_sel_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_utmi_ulpi_sel_SET_his_dbg_usbc_utmi_ulpi_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_dbg_usbc_utmi8bit_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_utmi8bit_en_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_utmi8bit_en_SET_his_dbg_usbc_utmi8bit_en_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_utmi8bit_en_SET_his_dbg_usbc_utmi8bit_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_usbc_low_power : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_low_power_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_low_power_STATUS_his_dbg_usbc_low_power_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_low_power_STATUS_his_dbg_usbc_low_power_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_dbg_usbc_ahbs_bigendian : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_ahbs_bigendian_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_ahbs_bigendian_SET_his_dbg_usbc_ahbs_bigendian_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_ahbs_bigendian_SET_his_dbg_usbc_ahbs_bigendian_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_dbg_usbc_axim_bigendian : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_axim_bigendian_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_axim_bigendian_SET_his_dbg_usbc_axim_bigendian_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usbc_axim_bigendian_SET_his_dbg_usbc_axim_bigendian_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_usbc_utmi_drvvbus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usbc_utmi_drvvbus_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usbc_utmi_drvvbus_STATUS_usbc_utmi_drvvbus_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usbc_utmi_drvvbus_STATUS_usbc_utmi_drvvbus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_dbg_pipe_rxsyncheader : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxsyncheader_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxsyncheader_SET_his_dbg_pipe_rxsyncheader_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxsyncheader_SET_his_dbg_pipe_rxsyncheader_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_dbg_pipe_rxstartblock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxstartblock_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxstartblock_SET_his_dbg_pipe_rxstartblock_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxstartblock_SET_his_dbg_pipe_rxstartblock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_dbg_pipe_elasticbufferlocation : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_elasticbufferlocation_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_elasticbufferlocation_SET_his_dbg_pipe_elasticbufferlocation_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_elasticbufferlocation_SET_his_dbg_pipe_elasticbufferlocation_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_pipe_phy_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_phy_mode_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_phy_mode_STATUS_his_dbg_pipe_phy_mode_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_phy_mode_STATUS_his_dbg_pipe_phy_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_pipe_elasticity_buffer_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_elasticity_buffer_mode_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_elasticity_buffer_mode_STATUS_his_dbg_pipe_elasticity_buffer_mode_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_elasticity_buffer_mode_STATUS_his_dbg_pipe_elasticity_buffer_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_pipe_width : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_width_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_width_STATUS_his_dbg_pipe_width_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_width_STATUS_his_dbg_pipe_width_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_pipe_pclk_rate : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_pclk_rate_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_pclk_rate_STATUS_his_dbg_pipe_pclk_rate_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_pclk_rate_STATUS_his_dbg_pipe_pclk_rate_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_pipe_txstartblock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txstartblock_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txstartblock_STATUS_his_dbg_pipe_txstartblock_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txstartblock_STATUS_his_dbg_pipe_txstartblock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_pipe_txmargin : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txmargin_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txmargin_STATUS_his_dbg_pipe_txmargin_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txmargin_STATUS_his_dbg_pipe_txmargin_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_pipe_txswing : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txswing_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txswing_STATUS_his_dbg_pipe_txswing_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txswing_STATUS_his_dbg_pipe_txswing_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_pipe_txsyncheader : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txsyncheader_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txsyncheader_STATUS_his_dbg_pipe_txsyncheader_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_txsyncheader_STATUS_his_dbg_pipe_txsyncheader_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_pipe_blockaligncontrol : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_blockaligncontrol_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_blockaligncontrol_STATUS_his_dbg_pipe_blockaligncontrol_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_blockaligncontrol_STATUS_his_dbg_pipe_blockaligncontrol_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_pipe_rxstandby : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxstandby_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxstandby_STATUS_his_dbg_pipe_rxstandby_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_rxstandby_STATUS_his_dbg_pipe_rxstandby_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_pipe_encodedecodebypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_encodedecodebypass_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_encodedecodebypass_STATUS_his_dbg_pipe_encodedecodebypass_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_pipe_encodedecodebypass_STATUS_his_dbg_pipe_encodedecodebypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_usb_axi_arprd_qos : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usb_axi_arprd_qos_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usb_axi_arprd_qos_STATUS_his_dbg_usb_axi_arprd_qos_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usb_axi_arprd_qos_STATUS_his_dbg_usb_axi_arprd_qos_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_dbg_usb_axi_awprd_qos : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usb_axi_awprd_qos_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usb_axi_awprd_qos_STATUS_his_dbg_usb_axi_awprd_qos_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_dbg_usb_axi_awprd_qos_STATUS_his_dbg_usb_axi_awprd_qos_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_utmi_l1_suspend_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_l1_suspend_n_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_l1_suspend_n_STATUS_snp_dbg_utmi_l1_suspend_n_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_l1_suspend_n_STATUS_snp_dbg_utmi_l1_suspend_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_utmi_l1_suspend_com_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_l1_suspend_com_n_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_l1_suspend_com_n_STATUS_snp_dbg_utmi_l1_suspend_com_n_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_l1_suspend_com_n_STATUS_snp_dbg_utmi_l1_suspend_com_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_utmi_suspend_com_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_suspend_com_n_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_suspend_com_n_STATUS_snp_dbg_utmi_suspend_com_n_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_suspend_com_n_STATUS_snp_dbg_utmi_suspend_com_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_utmi_word_if : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_word_if_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_word_if_STATUS_snp_dbg_utmi_word_if_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_word_if_STATUS_snp_dbg_utmi_word_if_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_utmi_fsls_low_power : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_fsls_low_power_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_fsls_low_power_STATUS_snp_dbg_utmi_fsls_low_power_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_fsls_low_power_STATUS_snp_dbg_utmi_fsls_low_power_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_utmi_fslsserialmode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_fslsserialmode_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_fslsserialmode_STATUS_snp_dbg_utmi_fslsserialmode_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_utmi_fslsserialmode_STATUS_snp_dbg_utmi_fslsserialmode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_pipe3_DataBusWidth : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_DataBusWidth_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_DataBusWidth_SET_snp_dbg_pipe3_DataBusWidth_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_DataBusWidth_SET_snp_dbg_pipe3_DataBusWidth_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_pipe3_PHY_Mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_PHY_Mode_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_PHY_Mode_STATUS_snp_dbg_pipe3_PHY_Mode_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_PHY_Mode_STATUS_snp_dbg_pipe3_PHY_Mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_pipe3_ElasBufferMode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_ElasBufferMode_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_ElasBufferMode_STATUS_snp_dbg_pipe3_ElasBufferMode_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_ElasBufferMode_STATUS_snp_dbg_pipe3_ElasBufferMode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_pipe3_TxMargin : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_TxMargin_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_TxMargin_STATUS_snp_dbg_pipe3_TxMargin_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_TxMargin_STATUS_snp_dbg_pipe3_TxMargin_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_pipe3_TxSwing : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_TxSwing_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_TxSwing_STATUS_snp_dbg_pipe3_TxSwing_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pipe3_TxSwing_STATUS_snp_dbg_pipe3_TxSwing_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_intr_usb_sum_gic_lpmcu_iomcu : 1;
        unsigned int STATUS_intr_usb_controller_0 : 1;
        unsigned int STATUS_intr_usb_controller_1 : 1;
        unsigned int STATUS_intr_usb_controller_pme : 1;
        unsigned int STATUS_intr_usb_controller_system_err : 1;
        unsigned int STATUS_intr_usbdp_combophy_pcs : 1;
        unsigned int STATUS_intr_usb_sum_asp : 1;
        unsigned int STATUS_intr_usb_controller_0_event_ring_1 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_sum_gic_lpmcu_iomcu_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_sum_gic_lpmcu_iomcu_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_controller_0_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_controller_0_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_controller_1_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_controller_1_END (2)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_controller_pme_START (3)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_controller_pme_END (3)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_controller_system_err_START (4)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_controller_system_err_END (4)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usbdp_combophy_pcs_START (5)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usbdp_combophy_pcs_END (5)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_sum_asp_START (6)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_sum_asp_END (6)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_controller_0_event_ring_1_START (7)
#define SOC_HSDT1_usb_subsys_sysctrl_intr_usb_controller_STATUS_intr_usb_controller_0_event_ring_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_eop_timer_update : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_eop_timer_update_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_eop_timer_update_SET_snp_dbg_eop_timer_update_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_eop_timer_update_SET_snp_dbg_eop_timer_update_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_usb20phy_8bit_ls_eop_timer : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_8bit_ls_eop_timer_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_8bit_ls_eop_timer_SET_snp_dbg_usb20phy_8bit_ls_eop_timer_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_8bit_ls_eop_timer_SET_snp_dbg_usb20phy_8bit_ls_eop_timer_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_usb20phy_16bit_ls_eop_timer : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_16bit_ls_eop_timer_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_16bit_ls_eop_timer_SET_snp_dbg_usb20phy_16bit_ls_eop_timer_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_16bit_ls_eop_timer_SET_snp_dbg_usb20phy_16bit_ls_eop_timer_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_usb20phy_8bit_nols_eop_timer : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_8bit_nols_eop_timer_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_8bit_nols_eop_timer_SET_snp_dbg_usb20phy_8bit_nols_eop_timer_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_8bit_nols_eop_timer_SET_snp_dbg_usb20phy_8bit_nols_eop_timer_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_usb20phy_16bit_nols_eop_timer : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_16bit_nols_eop_timer_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_16bit_nols_eop_timer_SET_snp_dbg_usb20phy_16bit_nols_eop_timer_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_16bit_nols_eop_timer_SET_snp_dbg_usb20phy_16bit_nols_eop_timer_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_usb20phy_valid_update : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_valid_update_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_valid_update_SET_snp_dbg_usb20phy_valid_update_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_usb20phy_valid_update_SET_snp_dbg_usb20phy_valid_update_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_vbusvalid : 1;
        unsigned int SET_snp_dbg_vbusvalid_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_vbusvalid_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_vbusvalid_SET_snp_dbg_vbusvalid_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_vbusvalid_SET_snp_dbg_vbusvalid_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_vbusvalid_SET_snp_dbg_vbusvalid_sel_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_vbusvalid_SET_snp_dbg_vbusvalid_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_bvalid : 1;
        unsigned int SET_snp_dbg_bvalid_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bvalid_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bvalid_SET_snp_dbg_bvalid_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bvalid_SET_snp_dbg_bvalid_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bvalid_SET_snp_dbg_bvalid_sel_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bvalid_SET_snp_dbg_bvalid_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_sessend : 1;
        unsigned int SET_snp_dbg_sessend_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_sessend_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_sessend_SET_snp_dbg_sessend_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_sessend_SET_snp_dbg_sessend_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_sessend_SET_snp_dbg_sessend_sel_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_sessend_SET_snp_dbg_sessend_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_bigendian_gs : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bigendian_gs_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bigendian_gs_SET_snp_dbg_bigendian_gs_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bigendian_gs_SET_snp_dbg_bigendian_gs_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_debug_31_0 : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_31_0_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_31_0_STATUS_snp_dbg_debug_31_0_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_31_0_STATUS_snp_dbg_debug_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_debug_63_32 : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_63_32_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_63_32_STATUS_snp_dbg_debug_63_32_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_63_32_STATUS_snp_dbg_debug_63_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_debug_66_64 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_66_64_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_66_64_STATUS_snp_dbg_debug_66_64_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_debug_66_64_STATUS_snp_dbg_debug_66_64_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_logic_analyzer_trace_31_0 : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_logic_analyzer_trace_31_0_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_logic_analyzer_trace_31_0_STATUS_snp_dbg_logic_analyzer_trace_31_0_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_logic_analyzer_trace_31_0_STATUS_snp_dbg_logic_analyzer_trace_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_logic_analyzer_trace_63_32 : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_logic_analyzer_trace_63_32_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_logic_analyzer_trace_63_32_STATUS_snp_dbg_logic_analyzer_trace_63_32_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_logic_analyzer_trace_63_32_STATUS_snp_dbg_logic_analyzer_trace_63_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_host_current_belt : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_current_belt_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_current_belt_STATUS_snp_dbg_host_current_belt_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_current_belt_STATUS_snp_dbg_host_current_belt_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_gp_out : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_gp_out_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_gp_out_STATUS_snp_dbg_gp_out_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_gp_out_STATUS_snp_dbg_gp_out_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_gp_in : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_gp_in_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_gp_in_SET_snp_dbg_gp_in_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_gp_in_SET_snp_dbg_gp_in_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_pme_generation : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pme_generation_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pme_generation_STATUS_snp_dbg_pme_generation_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pme_generation_STATUS_snp_dbg_pme_generation_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_pme_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pme_en_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pme_en_SET_snp_dbg_pme_en_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_pme_en_SET_snp_dbg_pme_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_operational_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_operational_mode_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_operational_mode_STATUS_snp_dbg_operational_mode_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_operational_mode_STATUS_snp_dbg_operational_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_clk_gate_ctrl : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_clk_gate_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_clk_gate_ctrl_STATUS_snp_dbg_clk_gate_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_clk_gate_ctrl_STATUS_snp_dbg_clk_gate_ctrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_hub_vbus_ctrl : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_vbus_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_vbus_ctrl_STATUS_snp_dbg_hub_vbus_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_vbus_ctrl_STATUS_snp_dbg_hub_vbus_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_hub_port_overcurrent : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_port_overcurrent_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_port_overcurrent_SET_snp_dbg_hub_port_overcurrent_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_port_overcurrent_SET_snp_dbg_hub_port_overcurrent_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_hub_port_perm_attach : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_port_perm_attach_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_port_perm_attach_SET_snp_dbg_hub_port_perm_attach_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_hub_port_perm_attach_SET_snp_dbg_hub_port_perm_attach_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_host_num_u2_port : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_num_u2_port_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_num_u2_port_SET_snp_dbg_host_num_u2_port_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_num_u2_port_SET_snp_dbg_host_num_u2_port_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_host_num_u3_port : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_num_u3_port_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_num_u3_port_SET_snp_dbg_host_num_u3_port_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_num_u3_port_SET_snp_dbg_host_num_u3_port_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_host_u2_port_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_u2_port_disable_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_u2_port_disable_SET_snp_dbg_host_u2_port_disable_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_u2_port_disable_SET_snp_dbg_host_u2_port_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_host_u3_port_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_u3_port_disable_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_u3_port_disable_SET_snp_dbg_host_u3_port_disable_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_u3_port_disable_SET_snp_dbg_host_u3_port_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_StartRxDetU3RxDet : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_StartRxDetU3RxDet_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_StartRxDetU3RxDet_SET_snp_dbg_StartRxDetU3RxDet_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_StartRxDetU3RxDet_SET_snp_dbg_StartRxDetU3RxDet_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_DisRxDetU3RxDet : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_DisRxDetU3RxDet_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_DisRxDetU3RxDet_SET_snp_dbg_DisRxDetU3RxDet_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_DisRxDetU3RxDet_SET_snp_dbg_DisRxDetU3RxDet_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_DisRxDetU3RxDet_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_DisRxDetU3RxDet_ack_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_DisRxDetU3RxDet_ack_STATUS_snp_dbg_DisRxDetU3RxDet_ack_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_DisRxDetU3RxDet_ack_STATUS_snp_dbg_DisRxDetU3RxDet_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_host_port_power_control_present : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_port_power_control_present_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_port_power_control_present_SET_snp_dbg_host_port_power_control_present_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_port_power_control_present_SET_snp_dbg_host_port_power_control_present_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_host_msi_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_msi_enable_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_msi_enable_SET_snp_dbg_host_msi_enable_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_msi_enable_SET_snp_dbg_host_msi_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_host_legacy_smi_pci_cmd_reg_wr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_pci_cmd_reg_wr_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_pci_cmd_reg_wr_SET_snp_dbg_host_legacy_smi_pci_cmd_reg_wr_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_pci_cmd_reg_wr_SET_snp_dbg_host_legacy_smi_pci_cmd_reg_wr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_host_legacy_smi_bar_wr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_bar_wr_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_bar_wr_SET_snp_dbg_host_legacy_smi_bar_wr_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_bar_wr_SET_snp_dbg_host_legacy_smi_bar_wr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_host_legacy_smi_interrupt : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_interrupt_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_interrupt_STATUS_snp_dbg_host_legacy_smi_interrupt_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_host_legacy_smi_interrupt_STATUS_snp_dbg_host_legacy_smi_interrupt_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_fladj_30mhz_reg : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_fladj_30mhz_reg_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_fladj_30mhz_reg_SET_snp_dbg_fladj_30mhz_reg_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_fladj_30mhz_reg_SET_snp_dbg_fladj_30mhz_reg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_sysctrl_snp_dbg_xhc_bme : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xhc_bme_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xhc_bme_SET_sysctrl_snp_dbg_xhc_bme_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xhc_bme_SET_sysctrl_snp_dbg_xhc_bme_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_linestate_glitch_mark_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_bus_clken_gs : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bus_clken_gs_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bus_clken_gs_SET_snp_dbg_bus_clken_gs_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bus_clken_gs_SET_snp_dbg_bus_clken_gs_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_bus_clken_gm : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bus_clken_gm_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bus_clken_gm_SET_snp_dbg_bus_clken_gm_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_bus_clken_gm_SET_snp_dbg_bus_clken_gm_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_dbg_xm_csysreq : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_csysreq_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_csysreq_SET_snp_dbg_xm_csysreq_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_csysreq_SET_snp_dbg_xm_csysreq_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_xm_csysack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_csysack_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_csysack_STATUS_snp_dbg_xm_csysack_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_csysack_STATUS_snp_dbg_xm_csysack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_dbg_xm_cactive : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_cactive_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_cactive_STATUS_snp_dbg_xm_cactive_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_dbg_xm_cactive_STATUS_snp_dbg_xm_cactive_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb_ram0_half_a_mem_ctrl : 16;
        unsigned int SET_snp_usb_ram0_half_b_mem_ctrl : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram0_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram0_mem_ctrl_SET_snp_usb_ram0_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram0_mem_ctrl_SET_snp_usb_ram0_half_a_mem_ctrl_END (15)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram0_mem_ctrl_SET_snp_usb_ram0_half_b_mem_ctrl_START (16)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram0_mem_ctrl_SET_snp_usb_ram0_half_b_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb_ram1_half_a_mem_ctrl : 16;
        unsigned int SET_snp_usb_ram1_half_b_mem_ctrl : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram1_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram1_mem_ctrl_SET_snp_usb_ram1_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram1_mem_ctrl_SET_snp_usb_ram1_half_a_mem_ctrl_END (15)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram1_mem_ctrl_SET_snp_usb_ram1_half_b_mem_ctrl_START (16)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram1_mem_ctrl_SET_snp_usb_ram1_half_b_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb_ram2_half_a_mem_ctrl : 16;
        unsigned int SET_snp_usb_ram2_half_b_mem_ctrl : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram2_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram2_mem_ctrl_SET_snp_usb_ram2_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram2_mem_ctrl_SET_snp_usb_ram2_half_a_mem_ctrl_END (15)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram2_mem_ctrl_SET_snp_usb_ram2_half_b_mem_ctrl_START (16)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb_ram2_mem_ctrl_SET_snp_usb_ram2_half_b_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb_ram0_half_a_mem_ctrl : 16;
        unsigned int SET_his_usb_ram0_half_b_mem_ctrl : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram0_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram0_mem_ctrl_SET_his_usb_ram0_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram0_mem_ctrl_SET_his_usb_ram0_half_a_mem_ctrl_END (15)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram0_mem_ctrl_SET_his_usb_ram0_half_b_mem_ctrl_START (16)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram0_mem_ctrl_SET_his_usb_ram0_half_b_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb_ram1_half_a_mem_ctrl : 16;
        unsigned int SET_his_usb_ram1_half_b_mem_ctrl : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram1_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram1_mem_ctrl_SET_his_usb_ram1_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram1_mem_ctrl_SET_his_usb_ram1_half_a_mem_ctrl_END (15)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram1_mem_ctrl_SET_his_usb_ram1_half_b_mem_ctrl_START (16)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram1_mem_ctrl_SET_his_usb_ram1_half_b_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb_ram2_half_a_mem_ctrl : 16;
        unsigned int SET_his_usb_ram2_half_b_mem_ctrl : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram2_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram2_mem_ctrl_SET_his_usb_ram2_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram2_mem_ctrl_SET_his_usb_ram2_half_a_mem_ctrl_END (15)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram2_mem_ctrl_SET_his_usb_ram2_half_b_mem_ctrl_START (16)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram2_mem_ctrl_SET_his_usb_ram2_half_b_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb_ram3_half_a_mem_ctrl : 16;
        unsigned int SET_his_usb_ram3_half_b_mem_ctrl : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram3_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram3_mem_ctrl_SET_his_usb_ram3_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram3_mem_ctrl_SET_his_usb_ram3_half_a_mem_ctrl_END (15)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram3_mem_ctrl_SET_his_usb_ram3_half_b_mem_ctrl_START (16)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram3_mem_ctrl_SET_his_usb_ram3_half_b_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb_ram4_half_a_mem_ctrl : 16;
        unsigned int SET_his_usb_ram4_half_b_mem_ctrl : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram4_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram4_mem_ctrl_SET_his_usb_ram4_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram4_mem_ctrl_SET_his_usb_ram4_half_a_mem_ctrl_END (15)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram4_mem_ctrl_SET_his_usb_ram4_half_b_mem_ctrl_START (16)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb_ram4_mem_ctrl_SET_his_usb_ram4_half_b_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_axi_wr_bc_icfg_bwc_bandwidth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_bandwidth_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_bandwidth_SET_usb_axi_wr_bc_icfg_bwc_bandwidth_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_bandwidth_SET_usb_axi_wr_bc_icfg_bwc_bandwidth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_axi_wr_bc_icfg_bwc_saturation : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_saturation_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_saturation_SET_usb_axi_wr_bc_icfg_bwc_saturation_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_saturation_SET_usb_axi_wr_bc_icfg_bwc_saturation_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_axi_wr_bc_icfg_bwc_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_en_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_en_SET_usb_axi_wr_bc_icfg_bwc_en_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_icfg_bwc_en_SET_usb_axi_wr_bc_icfg_bwc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_axi_wr_bc_flux_ctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_flux_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_flux_ctrl_SET_usb_axi_wr_bc_flux_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wr_bc_flux_ctrl_SET_usb_axi_wr_bc_flux_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_axi_rd_bc_icfg_bwc_bandwidth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_bandwidth_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_bandwidth_SET_usb_axi_rd_bc_icfg_bwc_bandwidth_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_bandwidth_SET_usb_axi_rd_bc_icfg_bwc_bandwidth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_axi_rd_bc_icfg_bwc_saturation : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_saturation_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_saturation_SET_usb_axi_rd_bc_icfg_bwc_saturation_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_saturation_SET_usb_axi_rd_bc_icfg_bwc_saturation_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_axi_rd_bc_icfg_bwc_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_en_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_en_SET_usb_axi_rd_bc_icfg_bwc_en_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_icfg_bwc_en_SET_usb_axi_rd_bc_icfg_bwc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_axi_rd_bc_flux_ctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_flux_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_flux_ctrl_SET_usb_axi_rd_bc_flux_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rd_bc_flux_ctrl_SET_usb_axi_rd_bc_flux_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_usb2_phy_work_mom : 1;
        unsigned int STATUS_usb2_phy_suspend_mom : 1;
        unsigned int STATUS_usb2_phy_sleep_mom : 1;
        unsigned int STATUS_combophy_usb_p0_mom : 1;
        unsigned int STATUS_combophy_usb_p1_mom : 1;
        unsigned int STATUS_combophy_usb_p2_mom : 1;
        unsigned int STATUS_combophy_usb_p3_mom : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_usb2_phy_work_mom_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_usb2_phy_work_mom_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_usb2_phy_suspend_mom_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_usb2_phy_suspend_mom_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_usb2_phy_sleep_mom_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_usb2_phy_sleep_mom_END (2)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_combophy_usb_p0_mom_START (3)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_combophy_usb_p0_mom_END (3)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_combophy_usb_p1_mom_START (4)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_combophy_usb_p1_mom_END (4)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_combophy_usb_p2_mom_START (5)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_combophy_usb_p2_mom_END (5)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_combophy_usb_p3_mom_START (6)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_powerstatus_STATUS_combophy_usb_p3_mom_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb2_phy_rxerror_detect_cnt_clear : 1;
        unsigned int SET_usb2_phy_rxerror_detect_cnt_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_set_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_set_SET_usb2_phy_rxerror_detect_cnt_clear_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_set_SET_usb2_phy_rxerror_detect_cnt_clear_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_set_SET_usb2_phy_rxerror_detect_cnt_en_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_set_SET_usb2_phy_rxerror_detect_cnt_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_usb2_phy_rxerror_detect_cnt : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_STATUS_usb2_phy_rxerror_detect_cnt_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_rxerror_detect_cnt_STATUS_usb2_phy_rxerror_detect_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb2_phy_pll_unlock_cnt_clear : 1;
        unsigned int SET_usb2_phy_pll_unlock_cnt_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_set_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_set_SET_usb2_phy_pll_unlock_cnt_clear_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_set_SET_usb2_phy_pll_unlock_cnt_clear_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_set_SET_usb2_phy_pll_unlock_cnt_en_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_set_SET_usb2_phy_pll_unlock_cnt_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_usb2_phy_pll_unlock_cnt : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_STATUS_usb2_phy_pll_unlock_cnt_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb2_phy_pll_unlock_cnt_STATUS_usb2_phy_pll_unlock_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb3_testpoint_sel : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb3_testpoint_sel_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb3_testpoint_sel_SET_usb3_testpoint_sel_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb3_testpoint_sel_SET_usb3_testpoint_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_usb3_testpoint : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb3_testpoint_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb3_testpoint_STATUS_usb3_testpoint_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb3_testpoint_STATUS_usb3_testpoint_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_sysctrl_combophy_ready : 1;
        unsigned int SET_sysctrl_combophy_ready_sel : 1;
        unsigned int SET_sysctrl_pipe_powerpresent_sel : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_cfg_pipe_powerpresent_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_cfg_pipe_powerpresent_SET_sysctrl_combophy_ready_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_cfg_pipe_powerpresent_SET_sysctrl_combophy_ready_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_cfg_pipe_powerpresent_SET_sysctrl_combophy_ready_sel_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_cfg_pipe_powerpresent_SET_sysctrl_combophy_ready_sel_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_cfg_pipe_powerpresent_SET_sysctrl_pipe_powerpresent_sel_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_cfg_pipe_powerpresent_SET_sysctrl_pipe_powerpresent_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_sysctrl_pipe_reset_n_sel : 1;
        unsigned int SET_sysctrl_pipe_reset_n : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_pipe_reset_n_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_reset_n_SET_sysctrl_pipe_reset_n_sel_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_reset_n_SET_sysctrl_pipe_reset_n_sel_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_reset_n_SET_sysctrl_pipe_reset_n_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_reset_n_SET_sysctrl_pipe_reset_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_sysctrl_utmi_port_reset_sel : 1;
        unsigned int SET_sysctrl_utmi_port_reset : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_utmi_port_reset_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_port_reset_SET_sysctrl_utmi_port_reset_sel_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_port_reset_SET_sysctrl_utmi_port_reset_sel_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_port_reset_SET_sysctrl_utmi_port_reset_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_utmi_port_reset_SET_sysctrl_utmi_port_reset_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_sysctrl_pipe_phystatus_sel : 1;
        unsigned int SET_sysctrl_pipe_phystatus : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_pipe_phystatus_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_phystatus_SET_sysctrl_pipe_phystatus_sel_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_phystatus_SET_sysctrl_pipe_phystatus_sel_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_phystatus_SET_sysctrl_pipe_phystatus_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_pipe_phystatus_SET_sysctrl_pipe_phystatus_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usbc_pipe_compliance : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_his_usbc_pipe_compliance_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_his_usbc_pipe_compliance_SET_his_usbc_pipe_compliance_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_his_usbc_pipe_compliance_SET_his_usbc_pipe_compliance_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_usb3_u3_vbus_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb3_u3_vbus_enable_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb3_u3_vbus_enable_STATUS_his_usb3_u3_vbus_enable_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb3_u3_vbus_enable_STATUS_his_usb3_u3_vbus_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usbc_dbg_utmisrp_bvalid : 1;
        unsigned int SEL_snp_usbc_dbg_utmisrp_bvalid : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usbc_dbg_utmisrp_bvalid_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usbc_dbg_utmisrp_bvalid_SET_snp_usbc_dbg_utmisrp_bvalid_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usbc_dbg_utmisrp_bvalid_SET_snp_usbc_dbg_utmisrp_bvalid_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usbc_dbg_utmisrp_bvalid_SEL_snp_usbc_dbg_utmisrp_bvalid_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usbc_dbg_utmisrp_bvalid_SEL_snp_usbc_dbg_utmisrp_bvalid_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_usbc_dbg_utmisrp_bvalid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_STATUS_snp_usbc_dbg_utmisrp_bvalid_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_snp_usbc_dbg_utmisrp_bvalid_STATUS_snp_usbc_dbg_utmisrp_bvalid_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_STATUS_snp_usbc_dbg_utmisrp_bvalid_STATUS_snp_usbc_dbg_utmisrp_bvalid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb3_dbg_trace_mem_ctrl_bp_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb3_dbg_trace_mem_ctrl_bp_d1w2r_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb3_dbg_trace_mem_ctrl_bp_d1w2r_SET_his_usb3_dbg_trace_mem_ctrl_bp_d1w2r_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb3_dbg_trace_mem_ctrl_bp_d1w2r_SET_his_usb3_dbg_trace_mem_ctrl_bp_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb20phy_rsv_in : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20phy_rsv_in_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20phy_rsv_in_SET_his_usb20phy_rsv_in_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20phy_rsv_in_SET_his_usb20phy_rsv_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SATUS_his_usb20phy_rsv_out : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20phy_rsv_out_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20phy_rsv_out_SATUS_his_usb20phy_rsv_out_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20phy_rsv_out_SATUS_his_usb20phy_rsv_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_pmgt_ref_clk_ok : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_ok_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_ok_SET_snp_usb3_dbg_pmgt_ref_clk_ok_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_ok_SET_snp_usb3_dbg_pmgt_ref_clk_ok_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_pmgt_ref_clk_req_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_req_n_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_req_n_SET_snp_usb3_dbg_pmgt_ref_clk_req_n_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_req_n_SET_snp_usb3_dbg_pmgt_ref_clk_req_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_usb3_dbg_pmgt_ref_clk_off : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_off_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_off_STATUS_snp_usb3_dbg_pmgt_ref_clk_off_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pmgt_ref_clk_off_STATUS_snp_usb3_dbg_pmgt_ref_clk_off_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_usb3_dbg_pipe4_pclk_rate : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_pclk_rate_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_pclk_rate_STATUS_snp_usb3_dbg_pipe4_pclk_rate_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_pclk_rate_STATUS_snp_usb3_dbg_pipe4_pclk_rate_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_usb3_dbg_pipe4_width : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_width_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_width_STATUS_snp_usb3_dbg_pipe4_width_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_width_STATUS_snp_usb3_dbg_pipe4_width_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_usb3_dbg_pipe4_blkalignctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_blkalignctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_blkalignctrl_STATUS_snp_usb3_dbg_pipe4_blkalignctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_blkalignctrl_STATUS_snp_usb3_dbg_pipe4_blkalignctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_usb3_dbg_pipe4_encodedecodebypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_encodedecodebypass_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_encodedecodebypass_STATUS_snp_usb3_dbg_pipe4_encodedecodebypass_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_encodedecodebypass_STATUS_snp_usb3_dbg_pipe4_encodedecodebypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_usb3_dbg_pipe4_txstartblock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_txstartblock_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_txstartblock_STATUS_snp_usb3_dbg_pipe4_txstartblock_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_txstartblock_STATUS_snp_usb3_dbg_pipe4_txstartblock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_usb3_dbg_pipe4_txsyncheader : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_txsyncheader_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_txsyncheader_STATUS_snp_usb3_dbg_pipe4_txsyncheader_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_txsyncheader_STATUS_snp_usb3_dbg_pipe4_txsyncheader_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_pipe4_rxstartblock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstartblock_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstartblock_SET_snp_usb3_dbg_pipe4_rxstartblock_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstartblock_SET_snp_usb3_dbg_pipe4_rxstartblock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_pipe4_rxsyncheader : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxsyncheader_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxsyncheader_SET_snp_usb3_dbg_pipe4_rxsyncheader_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxsyncheader_SET_snp_usb3_dbg_pipe4_rxsyncheader_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_pipe4_elasticbufferlocation : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_elasticbufferlocation_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_elasticbufferlocation_SET_snp_usb3_dbg_pipe4_elasticbufferlocation_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_elasticbufferlocation_SET_snp_usb3_dbg_pipe4_elasticbufferlocation_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_pipe4_rxstandbystatus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstandbystatus_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstandbystatus_SET_snp_usb3_dbg_pipe4_rxstandbystatus_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstandbystatus_SET_snp_usb3_dbg_pipe4_rxstandbystatus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_snp_usb3_dbg_pipe4_rxstandby : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstandby_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstandby_STATUS_snp_usb3_dbg_pipe4_rxstandby_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_pipe4_rxstandby_STATUS_snp_usb3_dbg_pipe4_rxstandby_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_host_force_gen1_speed : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_host_force_gen1_speed_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_host_force_gen1_speed_SET_snp_usb3_dbg_host_force_gen1_speed_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_host_force_gen1_speed_SET_snp_usb3_dbg_host_force_gen1_speed_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_ptm_time_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_ptm_time_vld_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_ptm_time_vld_SET_snp_usb3_dbg_ptm_time_vld_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_ptm_time_vld_SET_snp_usb3_dbg_ptm_time_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_ptm_time : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_ptm_time_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_ptm_time_SET_snp_usb3_dbg_ptm_time_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_ptm_time_SET_snp_usb3_dbg_ptm_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_bus_filter_bypass : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_bus_filter_bypass_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_bus_filter_bypass_SET_snp_usb3_dbg_bus_filter_bypass_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_bus_filter_bypass_SET_snp_usb3_dbg_bus_filter_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_soc_common_rd_wr_bus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_common_rd_wr_bus_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_common_rd_wr_bus_SET_snp_usb3_dbg_soc_common_rd_wr_bus_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_common_rd_wr_bus_SET_snp_usb3_dbg_soc_common_rd_wr_bus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_soc_rd_uF_kB_bandwidth : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_rd_uF_kB_bandwidth_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_rd_uF_kB_bandwidth_SET_snp_usb3_dbg_soc_rd_uF_kB_bandwidth_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_rd_uF_kB_bandwidth_SET_snp_usb3_dbg_soc_rd_uF_kB_bandwidth_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_soc_wr_uF_kB_bandwidth : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_wr_uF_kB_bandwidth_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_wr_uF_kB_bandwidth_SET_snp_usb3_dbg_soc_wr_uF_kB_bandwidth_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_soc_wr_uF_kB_bandwidth_SET_snp_usb3_dbg_soc_wr_uF_kB_bandwidth_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb3_dbg_trace_sample_ctrl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_trace_sample_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_trace_sample_ctrl_SET_snp_usb3_dbg_trace_sample_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb3_dbg_trace_sample_ctrl_SET_snp_usb3_dbg_trace_sample_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_qic_usb_axi_rt_sw_req_frm_reg : 1;
        unsigned int STATUS_qic_usb_axi_rt_sw_st : 1;
        unsigned int SET_bp_sw_rt_sw_mode : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_qic_bus_usbc_axi_low_latency_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_qic_bus_usbc_axi_low_latency_SET_qic_usb_axi_rt_sw_req_frm_reg_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_qic_bus_usbc_axi_low_latency_SET_qic_usb_axi_rt_sw_req_frm_reg_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_qic_bus_usbc_axi_low_latency_STATUS_qic_usb_axi_rt_sw_st_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_qic_bus_usbc_axi_low_latency_STATUS_qic_usb_axi_rt_sw_st_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_qic_bus_usbc_axi_low_latency_SET_bp_sw_rt_sw_mode_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_qic_bus_usbc_axi_low_latency_SET_bp_sw_rt_sw_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_axi_mst_axuser_awschint : 4;
        unsigned int SET_usb_axi_mst_axuser_arschint : 4;
        unsigned int SET_usb_axi_mst_axuser_aw_ptlasful : 1;
        unsigned int SET_usb_axi_mst_axuser_ar_ptlasful : 1;
        unsigned int SET_usb_axi_mst_axuser_awdomain : 2;
        unsigned int SET_usb_axi_mst_axuser_ardomain : 2;
        unsigned int SET_usb_axi_mst_axuser_awcache : 4;
        unsigned int SET_usb_axi_mst_axuser_arcache : 4;
        unsigned int reserved : 10;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_awschint_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_awschint_END (3)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_arschint_START (4)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_arschint_END (7)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_aw_ptlasful_START (8)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_aw_ptlasful_END (8)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_ar_ptlasful_START (9)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_ar_ptlasful_END (9)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_awdomain_START (10)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_awdomain_END (11)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_ardomain_START (12)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_ardomain_END (13)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_awcache_START (14)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_awcache_END (17)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_arcache_START (18)
#define SOC_HSDT1_usb_subsys_sysctrl_USB_AXI_Master_axuser_SET_usb_axi_mst_axuser_arcache_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int snps_usb_axi_master_awqos : 4;
        unsigned int snps_usb_axi_master_arqos : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SNPS USB Controller QOS_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SNPS USB Controller QOS_snps_usb_axi_master_awqos_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SNPS USB Controller QOS_snps_usb_axi_master_awqos_END (3)
#define SOC_HSDT1_usb_subsys_sysctrl_SNPS USB Controller QOS_snps_usb_axi_master_arqos_START (4)
#define SOC_HSDT1_usb_subsys_sysctrl_SNPS USB Controller QOS_snps_usb_axi_master_arqos_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_remote_wakup_disable : 1;
        unsigned int reg_linestate_fitter_en : 1;
        unsigned int reg_utmi_suspendm_mask_n : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wakup_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wakup_ctrl_reg_remote_wakup_disable_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wakup_ctrl_reg_remote_wakup_disable_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wakup_ctrl_reg_linestate_fitter_en_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wakup_ctrl_reg_linestate_fitter_en_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wakup_ctrl_reg_utmi_suspendm_mask_n_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wakup_ctrl_reg_utmi_suspendm_mask_n_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_linestate_filtter_time : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_linestate_filtter_time_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_linestate_filtter_time_reg_linestate_filtter_time_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_linestate_filtter_time_reg_linestate_filtter_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wakup_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_wakup_int_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_wakup_int_wakup_int_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_wakup_int_wakup_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb20_utmi_drvvbus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb20_utni_drvvbus_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb20_utni_drvvbus_SET_snp_usb20_utmi_drvvbus_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb20_utni_drvvbus_SET_snp_usb20_utmi_drvvbus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_snp_usb20_ram0_mem_ctrl : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_snp_usb20_ram0_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb20_ram0_mem_ctrl_SET_snp_usb20_ram0_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_snp_usb20_ram0_mem_ctrl_SET_snp_usb20_ram0_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb20_axi_mst_axuser_awschint : 4;
        unsigned int SET_usb20_axi_mst_axuser_arschint : 4;
        unsigned int SET_usb20_axi_mst_axuser_aw_ptlasful : 1;
        unsigned int SET_usb20_axi_mst_axuser_ar_ptlasful : 1;
        unsigned int SET_usb20_axi_mst_axuser_awdomain : 2;
        unsigned int SET_usb20_axi_mst_axuser_ardomain : 2;
        unsigned int SET_usb20_axi_mst_axuser_awcache : 4;
        unsigned int SET_usb20_axi_mst_axuser_arcache : 4;
        unsigned int reserved : 10;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_awschint_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_awschint_END (3)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_arschint_START (4)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_arschint_END (7)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_aw_ptlasful_START (8)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_aw_ptlasful_END (8)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_ar_ptlasful_START (9)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_ar_ptlasful_END (9)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_awdomain_START (10)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_awdomain_END (11)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_ardomain_START (12)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_ardomain_END (13)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_awcache_START (14)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_awcache_END (17)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_arcache_START (18)
#define SOC_HSDT1_usb_subsys_sysctrl_SNP_USB20_AXI_Master_axuser0_SET_usb20_axi_mst_axuser_arcache_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb20_dbg_trace_mem_ctrl_bp_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_dbg_trace_mem_ctrl_bp_d1w2r_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_dbg_trace_mem_ctrl_bp_d1w2r_SET_his_usb20_dbg_trace_mem_ctrl_bp_d1w2r_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_dbg_trace_mem_ctrl_bp_d1w2r_SET_his_usb20_dbg_trace_mem_ctrl_bp_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb20_ram0_half_a_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram0_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram0_mem_ctrl_SET_his_usb20_ram0_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram0_mem_ctrl_SET_his_usb20_ram0_half_a_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb20_ram1_half_a_mem_ctrl : 16;
        unsigned int SET_his_usb20_ram1_half_b_mem_ctrl : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram1_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram1_mem_ctrl_SET_his_usb20_ram1_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram1_mem_ctrl_SET_his_usb20_ram1_half_a_mem_ctrl_END (15)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram1_mem_ctrl_SET_his_usb20_ram1_half_b_mem_ctrl_START (16)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram1_mem_ctrl_SET_his_usb20_ram1_half_b_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb20_ram2_half_a_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram2_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram2_mem_ctrl_SET_his_usb20_ram2_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram2_mem_ctrl_SET_his_usb20_ram2_half_a_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb20_ram3_half_a_mem_ctrl : 16;
        unsigned int SET_his_usb20_ram3_half_b_mem_ctrl : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram3_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram3_mem_ctrl_SET_his_usb20_ram3_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram3_mem_ctrl_SET_his_usb20_ram3_half_a_mem_ctrl_END (15)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram3_mem_ctrl_SET_his_usb20_ram3_half_b_mem_ctrl_START (16)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram3_mem_ctrl_SET_his_usb20_ram3_half_b_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usb20_ram4_half_a_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram4_mem_ctrl_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram4_mem_ctrl_SET_his_usb20_ram4_half_a_mem_ctrl_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_ram4_mem_ctrl_SET_his_usb20_ram4_half_a_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usbc_err_inj_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_err_inj_en_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_err_inj_en_SET_his_usbc_err_inj_en_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_err_inj_en_SET_his_usbc_err_inj_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usbc_msi_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_msi_en_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_msi_en_SET_his_usbc_msi_en_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_msi_en_SET_his_usbc_msi_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usbc_bme : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_bme_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_bme_SET_his_usbc_bme_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_bme_SET_his_usbc_bme_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_his_usbc_axi_ruser_poison : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_axi_ruser_poison_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_axi_ruser_poison_SET_his_usbc_axi_ruser_poison_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_axi_ruser_poison_SET_his_usbc_axi_ruser_poison_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_usbc_axi_wuser_poison : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_axi_wuser_poison_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_axi_wuser_poison_STATUS_his_usbc_axi_wuser_poison_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_axi_wuser_poison_STATUS_his_usbc_axi_wuser_poison_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_his_usbc_inr_error : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_inr_error_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_inr_error_STATUS_his_usbc_inr_error_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_his_usb20_usbc_inr_error_STATUS_his_usbc_inr_error_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_disconnect_chk_disable : 1;
        unsigned int reg_disconnect_chk_int_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_disconnec_chk_cfg_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnec_chk_cfg_reg_disconnect_chk_disable_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnec_chk_cfg_reg_disconnect_chk_disable_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnec_chk_cfg_reg_disconnect_chk_int_clr_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnec_chk_cfg_reg_disconnect_chk_int_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_disconnect_chk_min : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_chk_min_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_chk_min_reg_disconnect_chk_min_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_chk_min_reg_disconnect_chk_min_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_disconnect_chk_max : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_chk_max_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_chk_max_reg_disconnect_chk_max_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_chk_max_reg_disconnect_chk_max_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_disconnect_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_int_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_int_reg_disconnect_int_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_disconnect_int_reg_disconnect_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int set_axi_arvcidx : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_axi_arvcidx_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_arvcidx_set_axi_arvcidx_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_arvcidx_set_axi_arvcidx_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_axi_arvcidx_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_axi_arvcidx_sel_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_arvcidx_sel_reg_axi_arvcidx_sel_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_arvcidx_sel_reg_axi_arvcidx_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int set_axi_awvcidx : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_axi_awvcidx_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_awvcidx_set_axi_awvcidx_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_awvcidx_set_axi_awvcidx_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_axi_awvcidx_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_axi_awvcidx_sel_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_awvcidx_sel_reg_axi_awvcidx_sel_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_axi_awvcidx_sel_reg_axi_awvcidx_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int usb_idle : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_idle_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_idle_usb_idle_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_idle_usb_idle_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_axi_wusr : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wusr_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wusr_SET_usb_axi_wusr_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_wusr_SET_usb_axi_wusr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb_axi_rusr : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rusr_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rusr_SET_usb_axi_rusr_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_axi_rusr_SET_usb_axi_rusr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_remote_wake_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wake_mode_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wake_mode_reg_remote_wake_mode_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wake_mode_reg_remote_wake_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_remote_wake_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wake_clr_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wake_clr_reg_remote_wake_clr_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_remote_wake_clr_reg_remote_wake_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_usb_func0_int_mask_n : 1;
        unsigned int reg_usb_func1_int_mask_n : 1;
        unsigned int reg_usb_func2_int_mask_n : 1;
        unsigned int reg_usb_syserr_int_mask_n : 1;
        unsigned int reg_usb_remote_int_mask_n : 1;
        unsigned int reg_usb_disconnect_int_mask_n : 1;
        unsigned int reg_usbdp_combophy_int_mask_n : 1;
        unsigned int reg_usb_func0_int_mask_n_event_ring_1 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_func0_int_mask_n_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_func0_int_mask_n_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_func1_int_mask_n_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_func1_int_mask_n_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_func2_int_mask_n_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_func2_int_mask_n_END (2)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_syserr_int_mask_n_START (3)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_syserr_int_mask_n_END (3)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_remote_int_mask_n_START (4)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_remote_int_mask_n_END (4)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_disconnect_int_mask_n_START (5)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_disconnect_int_mask_n_END (5)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usbdp_combophy_int_mask_n_START (6)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usbdp_combophy_int_mask_n_END (6)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_func0_int_mask_n_event_ring_1_START (7)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_mask_reg_usb_func0_int_mask_n_event_ring_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_usb_int_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_int_status_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_status_reg_usb_int_status_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_status_reg_usb_int_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_usb_int_status_aft_mask : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_int_status_aft_mask_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_status_aft_mask_reg_usb_int_status_aft_mask_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_status_aft_mask_reg_usb_int_status_aft_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_usb_func0_int_event_ring_0_for_asp_mask_n : 1;
        unsigned int reg_usb_func0_int_event_ring_1_for_asp_mask_n : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_mask_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_mask_reg_usb_func0_int_event_ring_0_for_asp_mask_n_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_mask_reg_usb_func0_int_event_ring_0_for_asp_mask_n_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_mask_reg_usb_func0_int_event_ring_1_for_asp_mask_n_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_mask_reg_usb_func0_int_event_ring_1_for_asp_mask_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_usb_int_for_asp_status_aft_mask : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_status_aft_mask_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_status_aft_mask_reg_usb_int_for_asp_status_aft_mask_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_reg_int_for_asp_status_aft_mask_reg_usb_int_for_asp_status_aft_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int STATUS_usb_ulpi_sel_indicator : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb_ulpi_sel_indicator_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb_ulpi_sel_indicator_STATUS_usb_ulpi_sel_indicator_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb_ulpi_sel_indicator_STATUS_usb_ulpi_sel_indicator_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_usb20phy_ulpi_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_usb20phy_ulpi_rst_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_usb20phy_ulpi_rst_SET_usb20phy_ulpi_rst_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_usb20phy_ulpi_rst_SET_usb20phy_ulpi_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_en0 : 1;
        unsigned int SET_asp_sec_en1 : 1;
        unsigned int SET_asp_sec_en2 : 1;
        unsigned int SET_asp_sec_en3 : 1;
        unsigned int SET_asp_sec_remap_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_SET_asp_sec_en0_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_SET_asp_sec_en0_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_SET_asp_sec_en1_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_SET_asp_sec_en1_END (1)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_SET_asp_sec_en2_START (2)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_SET_asp_sec_en2_END (2)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_SET_asp_sec_en3_START (3)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_SET_asp_sec_en3_END (3)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_SET_asp_sec_remap_en_START (4)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_en0_SET_asp_sec_remap_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr0_str_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_str_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_str_h_SET_asp_sec_awaddr0_str_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_str_h_SET_asp_sec_awaddr0_str_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr0_str_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_str_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_str_l_SET_asp_sec_awaddr0_str_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_str_l_SET_asp_sec_awaddr0_str_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr0_end_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_end_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_end_h_SET_asp_sec_awaddr0_end_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_end_h_SET_asp_sec_awaddr0_end_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr0_end_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_end_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_end_l_SET_asp_sec_awaddr0_end_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr0_end_l_SET_asp_sec_awaddr0_end_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr0_str_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_str_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_str_h_SET_asp_sec_araddr0_str_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_str_h_SET_asp_sec_araddr0_str_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr0_str_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_str_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_str_l_SET_asp_sec_araddr0_str_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_str_l_SET_asp_sec_araddr0_str_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr0_end_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_end_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_end_h_SET_asp_sec_araddr0_end_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_end_h_SET_asp_sec_araddr0_end_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr0_end_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_end_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_end_l_SET_asp_sec_araddr0_end_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr0_end_l_SET_asp_sec_araddr0_end_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr1_str_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_str_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_str_h_SET_asp_sec_awaddr1_str_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_str_h_SET_asp_sec_awaddr1_str_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr1_str_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_str_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_str_l_SET_asp_sec_awaddr1_str_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_str_l_SET_asp_sec_awaddr1_str_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr1_end_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_end_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_end_h_SET_asp_sec_awaddr1_end_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_end_h_SET_asp_sec_awaddr1_end_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr1_end_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_end_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_end_l_SET_asp_sec_awaddr1_end_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr1_end_l_SET_asp_sec_awaddr1_end_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr1_str_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_str_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_str_h_SET_asp_sec_araddr1_str_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_str_h_SET_asp_sec_araddr1_str_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr1_str_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_str_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_str_l_SET_asp_sec_araddr1_str_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_str_l_SET_asp_sec_araddr1_str_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr1_end_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_end_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_end_h_SET_asp_sec_araddr1_end_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_end_h_SET_asp_sec_araddr1_end_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr1_end_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_end_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_end_l_SET_asp_sec_araddr1_end_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr1_end_l_SET_asp_sec_araddr1_end_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr2_str_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_str_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_str_h_SET_asp_sec_awaddr2_str_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_str_h_SET_asp_sec_awaddr2_str_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr2_str_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_str_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_str_l_SET_asp_sec_awaddr2_str_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_str_l_SET_asp_sec_awaddr2_str_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr2_end_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_end_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_end_h_SET_asp_sec_awaddr2_end_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_end_h_SET_asp_sec_awaddr2_end_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr2_end_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_end_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_end_l_SET_asp_sec_awaddr2_end_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr2_end_l_SET_asp_sec_awaddr2_end_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr2_str_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_str_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_str_h_SET_asp_sec_araddr2_str_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_str_h_SET_asp_sec_araddr2_str_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr2_str_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_str_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_str_l_SET_asp_sec_araddr2_str_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_str_l_SET_asp_sec_araddr2_str_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr2_end_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_end_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_end_h_SET_asp_sec_araddr2_end_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_end_h_SET_asp_sec_araddr2_end_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr2_end_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_end_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_end_l_SET_asp_sec_araddr2_end_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr2_end_l_SET_asp_sec_araddr2_end_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr3_str_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_str_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_str_h_SET_asp_sec_awaddr3_str_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_str_h_SET_asp_sec_awaddr3_str_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr3_str_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_str_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_str_l_SET_asp_sec_awaddr3_str_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_str_l_SET_asp_sec_awaddr3_str_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr3_end_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_end_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_end_h_SET_asp_sec_awaddr3_end_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_end_h_SET_asp_sec_awaddr3_end_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr3_end_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_end_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_end_l_SET_asp_sec_awaddr3_end_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr3_end_l_SET_asp_sec_awaddr3_end_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr3_str_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_str_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_str_h_SET_asp_sec_araddr3_str_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_str_h_SET_asp_sec_araddr3_str_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr3_str_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_str_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_str_l_SET_asp_sec_araddr3_str_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_str_l_SET_asp_sec_araddr3_str_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr3_end_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_end_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_end_h_SET_asp_sec_araddr3_end_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_end_h_SET_asp_sec_araddr3_end_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr3_end_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_end_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_end_l_SET_asp_sec_araddr3_end_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr3_end_l_SET_asp_sec_araddr3_end_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr_remap_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr_remap_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr_remap_h_SET_asp_sec_awaddr_remap_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr_remap_h_SET_asp_sec_awaddr_remap_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_awaddr_remap_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr_remap_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr_remap_l_SET_asp_sec_awaddr_remap_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_awaddr_remap_l_SET_asp_sec_awaddr_remap_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr_remap_h : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr_remap_h_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr_remap_h_SET_asp_sec_araddr_remap_h_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr_remap_h_SET_asp_sec_araddr_remap_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_sec_araddr_remap_l : 32;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr_remap_l_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr_remap_l_SET_asp_sec_araddr_remap_l_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_araddr_remap_l_SET_asp_sec_araddr_remap_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SET_asp_awsec_remap : 1;
        unsigned int SET_asp_arsec_remap : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_remap_UNION;
#endif
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_remap_SET_asp_awsec_remap_START (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_remap_SET_asp_awsec_remap_END (0)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_remap_SET_asp_arsec_remap_START (1)
#define SOC_HSDT1_usb_subsys_sysctrl_SET_asp_sec_remap_SET_asp_arsec_remap_END (1)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
