#ifndef __MEDIA_XPU_INFO_H__
#define __MEDIA_XPU_INFO_H__ 
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_media_dvs_stat_pmc2acpu : 1;
        unsigned int intr_xpu_aae_exception2acpu : 1;
        unsigned int intr_xpu_apb_cfg2acpu : 1;
        unsigned int intr_media1_fw_cfg2lpmcu : 1;
        unsigned int intr_xpu_apb_cfg2lpmcu : 1;
        unsigned int intr_media2_fw_cfg2lpmcu : 1;
        unsigned int intr_xpu_apb_cfg_to_cpu_xpu : 3;
        unsigned int intr_media_xpu_excption : 1;
        unsigned int intr_xpu_apb_cfg_to_gpu_xpu : 3;
        unsigned int intr_xpu_apb_cfg_to_ddr_xpu : 5;
        unsigned int intr_xpu_apb_cfg_to_media_xpu : 5;
        unsigned int reserved : 1;
        unsigned int intr_ap_clkendis_to_media_xpu : 1;
        unsigned int intr_iomcu_clkendis_to_media_xpu : 1;
        unsigned int intr_dump_dvfs_info : 1;
        unsigned int intr_dump_comb_dvfs_info : 1;
        unsigned int intr_media_xpu_suspend : 1;
        unsigned int intr_low_temp_enter_to_media_xpu : 1;
        unsigned int intr_fast_cfg_risc : 2;
    } reg;
} SOC_MEDIA_XPU_INTR_EN_UNION;
#define INTR_MEDIA_DVS_STAT_PMC2ACPU (0)
#define INTR_XPU_AAE_EXCEPTION2ACPU2ACPU (1)
#define INTR_MEDIA1_FW_CFG2LPMCU (3)
#define INTR_XPU_APB_CFG2LPMCU (4)
#define INTR_MEDIA2_FW_CFG2LPMCU (5)
#define INTR_MEDIA_XPU_EXCPTION (9)
#define INTR_AP_CLKENDIS_TO_MEDIA_XPU (24)
#define INTR_IOMCU_CLKENDIS_TO_MEDIA_XPU (25)
#define INTR_DUMP_DVFS_INFO (26)
#define INTR_DUMP_COMB_DVFS_INFO (27)
typedef union soc_media_xpu_base_data {
    unsigned int value;
    struct {
        unsigned int media_powup_stage : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MEDAI_XPU_BASE_DATA_UNION;
#define SOC_MEDAI_XPU_BASE_DATA_media_powup_stage_START (0)
#define SOC_MEDAI_XPU_BASE_DATA_media_powup_stage_END (2)
#define XPU_BASE_DATA_REG (*(volatile SOC_MEDAI_XPU_BASE_DATA_UNION*)(MEDIA_XPU_LP_CTRL_CFG_REG(XPU_LP_CTRL_DATA0)))
typedef union soc_media_xpu_freq_record_data0 {
    unsigned int value;
    struct {
        unsigned int dss_actual_freq : 12;
        unsigned int dss_freq_err_code : 4;
        unsigned int aae_actual_freq : 12;
        unsigned int aae_freq_err_code : 4;
    } reg;
} SOC_MEDAI_XPU_FREQ_RECORD_DATA0_UNION;
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA0_dss_actual_freq_START (0)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA0_dss_actual_freq_END (11)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA0_dss_freq_err_code_START (12)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA0_dss_freq_err_code_END (15)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA0_aae_actual_freq_START (16)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA0_aae_actual_freq_END (27)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA0_aae_freq_err_code_START (28)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA0_aae_freq_err_code_END (31)
typedef union soc_media_xpu_freq_record_data1 {
    unsigned int value;
    struct {
        unsigned int vdec_pxpc_actual_freq : 12;
        unsigned int vdec_pxpc_freq_err_code : 4;
        unsigned int venc_actual_freq : 12;
        unsigned int venc_freq_err_code : 4;
    } reg;
} SOC_MEDAI_XPU_FREQ_RECORD_DATA1_UNION;
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA1_vdec_pxpc_actual_freq_START (0)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA1_vdec_pxpc_actual_freq_END (11)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA1_vdec_pxpc_freq_err_code_START (12)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA1_vdec_pxpc_freq_err_code_END (15)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA1_venc_actual_freq_START (16)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA1_venc_actual_freq_END (27)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA1_venc_freq_err_code_START (28)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA1_venc_freq_err_code_END (31)
typedef union soc_media_xpu_freq_record_data2 {
    unsigned int value;
    struct {
        unsigned int isp_rt_actual_freq : 12;
        unsigned int isp_rt_freq_err_code : 4;
        unsigned int isp_nrt_actual_freq : 12;
        unsigned int isp_nrt_freq_err_code : 4;
    } reg;
} SOC_MEDAI_XPU_FREQ_RECORD_DATA2_UNION;
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA2_isp_rt_actual_freq_START (0)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA2_isp_rt_actual_freq_END (11)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA2_isp_rt_freq_err_code_START (12)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA2_isp_rt_freq_err_code_END (15)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA2_isp_nrt_actual_freq_START (16)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA2_isp_nrt_actual_freq_END (27)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA2_isp_nrt_freq_err_code_START (28)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA2_isp_nrt_freq_err_code_END (31)
typedef union soc_media_xpu_freq_record_data3 {
    unsigned int value;
    struct {
        unsigned int isp_srt_actual_freq : 12;
        unsigned int isp_srt_freq_err_code : 4;
        unsigned int oisp_actual_freq : 12;
        unsigned int oisp_freq_err_code : 4;
    } reg;
} SOC_MEDAI_XPU_FREQ_RECORD_DATA3_UNION;
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA3_isp_srt_actual_freq_START (0)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA3_isp_srt_actual_freq_END (11)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA3_isp_srt_freq_err_code_START (12)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA3_isp_srt_freq_err_code_END (15)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA3_oisp_actual_freq_START (16)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA3_oisp_actual_freq_END (27)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA3_oisp_freq_err_code_START (28)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA3_oisp_freq_err_code_END (31)
typedef union soc_media_xpu_freq_record_data4 {
    unsigned int value;
    struct {
        unsigned int ipp_actual_freq : 12;
        unsigned int ipp_freq_err_code : 4;
        unsigned int ispspi_actual_freq : 12;
        unsigned int ispspi_freq_err_code : 4;
    } reg;
} SOC_MEDAI_XPU_FREQ_RECORD_DATA4_UNION;
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA4_ipp_actual_freq_START (0)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA4_ipp_actual_freq_END (11)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA4_ipp_freq_err_code_START (12)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA4_ipp_freq_err_code_END (15)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA4_ispspi_actual_freq_START (16)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA4_ispspi_actual_freq_END (27)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA4_ispspi_freq_err_code_START (28)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA4_ispspi_freq_err_code_END (31)
typedef union soc_media_xpu_freq_record_data5 {
    unsigned int value;
    struct {
        unsigned int gic_ispcpu_actual_freq : 12;
        unsigned int gic_ispcpu_freq_err_code : 4;
        unsigned int periph_ispcpu_actual_freq : 12;
        unsigned int periph_ispcpu_freq_err_code : 4;
    } reg;
} SOC_MEDAI_XPU_FREQ_RECORD_DATA5_UNION;
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA5_gic_ispcpu_actual_freq_START (0)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA5_gic_ispcpu_actual_freq_END (11)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA5_gic_ispcpu_freq_err_code_START (12)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA5_gic_ispcpu_freq_err_code_END (15)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA5_periph_ispcpu_actual_freq_START (16)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA5_periph_ispcpu_actual_freq_END (27)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA5_periph_ispcpu_freq_err_code_START (28)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA5_periph_ispcpu_freq_err_code_END (31)
typedef union soc_media_xpu_freq_record_data6 {
    unsigned int value;
    struct {
        unsigned int csi_idi_actual_freq : 12;
        unsigned int csi_idi_freq_err_code : 4;
        unsigned int dss_vivo_actual_freq : 12;
        unsigned int dss_vivo_freq_err_code : 4;
    } reg;
} SOC_MEDAI_XPU_FREQ_RECORD_DATA6_UNION;
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA6_csi_idi_actual_freq_START (0)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA6_csi_idi_actual_freq_END (11)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA6_csi_idi_freq_err_code_START (12)
#define SOC_MEDAI_XPU_FREQ_RECORD_DATA6_csi_idi_freq_err_code_END (15)
typedef union soc_media_xpu_clock_op_data {
    unsigned int value;
    struct {
        unsigned int clk_id_to_xpu : 8;
        unsigned int clk_op_code : 8;
        unsigned int clk_op_stat : 16;
    } reg;
} SOC_MEDAI_XPU_CLOCK_OP_DATA_UNION;
#define SOC_MEDAI_XPU_CLOCK_OP_DATA_clk_id_to_xpu_START (0)
#define SOC_MEDAI_XPU_CLOCK_OP_DATA_clk_id_to_xpu_END (7)
#define SOC_MEDAI_XPU_CLOCK_OP_DATA_clk_op_code_START (8)
#define SOC_MEDAI_XPU_CLOCK_OP_DATA_clk_op_code_END (15)
#define SOC_MEDAI_XPU_CLOCK_OP_DATA_clk_op_stat_START (16)
#define SOC_MEDAI_XPU_CLOCK_OP_DATA_clk_op_stat_END (31)
typedef union {
    unsigned int value;
    struct {
        unsigned int dss_clk_state : 1;
        unsigned int ipp_clk_state : 1;
        unsigned int csi_clk_state : 1;
        unsigned int reserved : 13;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDAI_XPU_CLOCK_ENDIS_STATE_UNION;
#define SOC_MEDAI_XPU_CLOCK_ENDIS_STATE_dss_clk_state_START (0)
#define SOC_MEDAI_XPU_CLOCK_ENDIS_STATE_dss_clk_state_END (0)
#define SOC_MEDAI_XPU_CLOCK_ENDIS_STATE_ipp_clk_state_START (1)
#define SOC_MEDAI_XPU_CLOCK_ENDIS_STATE_ipp_clk_state_END (1)
#define SOC_MEDAI_XPU_CLOCK_ENDIS_STATE_csi_clk_state_START (2)
#define SOC_MEDAI_XPU_CLOCK_ENDIS_STATE_csi_clk_state_END (2)
#define SOC_MEDAI_XPU_CLOCK_ENDIS_STATE_bitmasken_START (16)
#define SOC_MEDAI_XPU_CLOCK_ENDIS_STATE_bitmasken_END (31)
#endif
