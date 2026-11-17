#ifndef __SOC_HSDT0_XCTRL_INTERFACE_H__
#define __SOC_HSDT0_XCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_ADDR(base) (base)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_0_ADDR(base) ((base) + 0x004UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_1_ADDR(base) ((base) + 0x008UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_0_ADDR(base) ((base) + 0x00CUL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_0_ADDR(base) ((base) + 0x010UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_0_ADDR(base) ((base) + 0x014UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_DFA_0_ADDR(base) ((base) + 0x018UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_DFA_0_ADDR(base) ((base) + 0x01CUL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_DFA_0_ADDR(base) ((base) + 0x020UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_DFA_0_ADDR(base) ((base) + 0x024UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x028UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x02CUL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x030UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_DFX_BUSY_0_ADDR(base) ((base) + 0x034UL)
#define SOC_HSDT0_XCTRL_HSDT0_INTR_EM_QIC_BUS_0_ADDR(base) ((base) + 0x038UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_0_ADDR(base) ((base) + 0x03CUL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_DFA_0_ADDR(base) ((base) + 0x040UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_MUDP_0_ADDR(base) ((base) + 0x044UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PROBE_ADDR(base) ((base) + 0x048UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDMS_NOPENDING_0_ADDR(base) ((base) + 0x050UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDMS_NOPENDING_1_ADDR(base) ((base) + 0x054UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_0_ADDR(base) ((base) + 0x058UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_1_ADDR(base) ((base) + 0x05CUL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_2_ADDR(base) ((base) + 0x060UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_3_ADDR(base) ((base) + 0x064UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_4_ADDR(base) ((base) + 0x068UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_0_ADDR(base) ((base) + 0x06CUL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_1_ADDR(base) ((base) + 0x070UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_2_ADDR(base) ((base) + 0x074UL)
#define SOC_HSDT0_XCTRL_HSDT0_DFA_QIC_PDM_PDS_STATE_DFA_0_ADDR(base) ((base) + 0x078UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_ADDR(base) ((base) + 0x100UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_0_ADDR(base) ((base) + 0x104UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_1_ADDR(base) ((base) + 0x108UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_0_ADDR(base) ((base) + 0x10CUL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_0_ADDR(base) ((base) + 0x110UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_0_ADDR(base) ((base) + 0x114UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_DFA_0_ADDR(base) ((base) + 0x118UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_DFA_0_ADDR(base) ((base) + 0x11CUL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_DFA_0_ADDR(base) ((base) + 0x120UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_DFA_0_ADDR(base) ((base) + 0x124UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x128UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x12CUL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x130UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_DFX_BUSY_0_ADDR(base) ((base) + 0x134UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_INTR_EM_QIC_BUS_0_ADDR(base) ((base) + 0x138UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_0_ADDR(base) ((base) + 0x13CUL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_DFA_0_ADDR(base) ((base) + 0x140UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_MUDP_0_ADDR(base) ((base) + 0x144UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PROBE_ADDR(base) ((base) + 0x148UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDMS_NOPENDING_0_ADDR(base) ((base) + 0x150UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDMS_NOPENDING_1_ADDR(base) ((base) + 0x154UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_0_ADDR(base) ((base) + 0x158UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_1_ADDR(base) ((base) + 0x15CUL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_2_ADDR(base) ((base) + 0x160UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_3_ADDR(base) ((base) + 0x164UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_4_ADDR(base) ((base) + 0x168UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_0_ADDR(base) ((base) + 0x16CUL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_1_ADDR(base) ((base) + 0x170UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_2_ADDR(base) ((base) + 0x174UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_DFA_QIC_PDM_PDS_STATE_DFA_0_ADDR(base) ((base) + 0x178UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_ADDR(base) ((base) + 0x1F8UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_ADDR(base) ((base) + 0x1FCUL)
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_TB_ADDR(base) ((base) + 0x208UL)
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_TB_HSDT02DDR_ADDR(base) ((base) + 0x218UL)
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_IB_SYS2HSDT0_ADDR(base) ((base) + 0x21CUL)
#define SOC_HSDT0_XCTRL_DFA_QIC_TIMEOUT_EN_TB_ADDR(base) ((base) + 0x220UL)
#define SOC_HSDT0_XCTRL_DFA_QIC_TIMEOUT_EN_IB_ADDR(base) ((base) + 0x224UL)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_ADDR(base) ((base) + 0x228UL)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_1_ADDR(base) ((base) + 0x22CUL)
#define SOC_HSDT0_XCTRL_nopending_mask_ADDR(base) ((base) + 0x230UL)
#define SOC_HSDT0_XCTRL_busy_mask_ADDR(base) ((base) + 0x234UL)
#define SOC_HSDT0_XCTRL_idlereq_mask_ADDR(base) ((base) + 0x238UL)
#define SOC_HSDT0_XCTRL_idleack_mask_ADDR(base) ((base) + 0x23CUL)
#define SOC_HSDT0_XCTRL_intr_qic_mask_ADDR(base) ((base) + 0x240UL)
#define SOC_HSDT0_XCTRL_nopending_lpcm_mask_ADDR(base) ((base) + 0x244UL)
#define SOC_HSDT0_XCTRL_nopending_mux_sel_ADDR(base) ((base) + 0x260UL)
#define SOC_HSDT0_XCTRL_busy_mux_sel_ADDR(base) ((base) + 0x264UL)
#define SOC_HSDT0_XCTRL_idle_req_mux_sel1_ADDR(base) ((base) + 0x268UL)
#define SOC_HSDT0_XCTRL_idleack_mux_sel1_ADDR(base) ((base) + 0x26CUL)
#define SOC_HSDT0_XCTRL_intr_qic_mux_sel_ADDR(base) ((base) + 0x270UL)
#define SOC_HSDT0_XCTRL_nopending_lpcm_mux_sel_ADDR(base) ((base) + 0x274UL)
#define SOC_HSDT0_XCTRL_hsdt0_tp_sel_ADDR(base) ((base) + 0x400UL)
#define SOC_HSDT0_XCTRL_hsdt0_jtag_sel_ADDR(base) ((base) + 0x408UL)
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_ckg_en_ADDR(base) ((base) + 0x40CUL)
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_dlock_and_dbg_clr_ADDR(base) ((base) + 0x410UL)
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_idle_ADDR(base) ((base) + 0x420UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_ADDR(base) ((base) + 0x424UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_ADDR(base) ((base) + 0x428UL)
#define SOC_HSDT0_XCTRL_MEM_CTRL_0_ADDR(base) ((base) + 0x42CUL)
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_ARVC_CTRL_ADDR(base) ((base) + 0x430UL)
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_AWVC_CTRL_ADDR(base) ((base) + 0x434UL)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_ARVC_CTRL_ADDR(base) ((base) + 0x438UL)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_AWVC_CTRL_ADDR(base) ((base) + 0x43CUL)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_ARVC_CTRL_ADDR(base) ((base) + 0x440UL)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_AWVC_CTRL_ADDR(base) ((base) + 0x444UL)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE_PARALLEL_TEST_EN_ADDR(base) ((base) + 0x448UL)
#define SOC_HSDT0_XCTRL_hsdt0_qic_soft_lock_dis_ADDR(base) ((base) + 0x800UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_ADDR(base) ((base) + 0xC00UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_ADDR(base) ((base) + 0xC04UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_ADDR(base) ((base) + 0xC08UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_ADDR(base) ((base) + 0xC0CUL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_ADDR(base) ((base) + 0xC10UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_ADDR(base) ((base) + 0xC14UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_EN_ADDR(base) ((base) + 0xC18UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_DIS_ADDR(base) ((base) + 0xC1CUL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_STA_ADDR(base) ((base) + 0xC20UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_EN_ADDR(base) ((base) + 0xC24UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_DIS_ADDR(base) ((base) + 0xC28UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_STA_ADDR(base) ((base) + 0xC2CUL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_EN_ADDR(base) ((base) + 0xC30UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_DIS_ADDR(base) ((base) + 0xC34UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_STA_ADDR(base) ((base) + 0xC38UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_EN_ADDR(base) ((base) + 0xC3CUL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_DIS_ADDR(base) ((base) + 0xC40UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_STA_ADDR(base) ((base) + 0xC44UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_ADDR(base) ((base) + 0xC48UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_ADDR(base) ((base) + 0xC4CUL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_ADDR(base) ((base) + 0xC50UL)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_LOCK_ADDR(base) ((base) + 0xD00UL)
#define SOC_HSDT0_XCTRL_qic_timeout_en_tb_mspe_tee_ADDR(base) ((base) + 0xD04UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_TEE_ADDR(base) ((base) + 0xD08UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_TEE_ADDR(base) ((base) + 0xD0CUL)
#define SOC_HSDT0_XCTRL_MEM_CTRL_QIC_TEE_ADDR(base) ((base) + 0xD10UL)
#define SOC_HSDT0_XCTRL_pctrl2hieps_ctrl_ADDR(base) ((base) + 0xE00UL)
#define SOC_HSDT0_XCTRL_hiesp2pctrl_state_l_ADDR(base) ((base) + 0xE04UL)
#define SOC_HSDT0_XCTRL_hiesp2pctrl_state_h_ADDR(base) ((base) + 0xE08UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_ADDR(base) ((base) + 0xE0CUL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_ADDR(base) ((base) + 0xE10UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_ADDR(base) ((base) + 0xE14UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_ADDR(base) ((base) + 0xE18UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_ADDR(base) ((base) + 0xE1CUL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_ADDR(base) ((base) + 0xE20UL)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_TIMEOUT_ST_TB_0_ADDR(base) ((base) + 0xE24UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_TIMEOUT_ST_TB_0_ADDR(base) ((base) + 0xE28UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_SYSPDC_REQ_ADDR(base) ((base) + 0xE34UL)
#define SOC_HSDT0_XCTRL_HSDT0_SC_QIC_EPS_TEE_SYSPDC_ACK_ADDR(base) ((base) + 0xE38UL)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_SYSPDC_ACK_ADDR(base) ((base) + 0xE3CUL)
#else
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_ADDR(base) (base)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_0_ADDR(base) ((base) + 0x004)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_1_ADDR(base) ((base) + 0x008)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_0_ADDR(base) ((base) + 0x00C)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_0_ADDR(base) ((base) + 0x010)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_0_ADDR(base) ((base) + 0x014)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_DFA_0_ADDR(base) ((base) + 0x018)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_DFA_0_ADDR(base) ((base) + 0x01C)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_DFA_0_ADDR(base) ((base) + 0x020)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_DFA_0_ADDR(base) ((base) + 0x024)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x028)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x02C)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x030)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_DFX_BUSY_0_ADDR(base) ((base) + 0x034)
#define SOC_HSDT0_XCTRL_HSDT0_INTR_EM_QIC_BUS_0_ADDR(base) ((base) + 0x038)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_0_ADDR(base) ((base) + 0x03C)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_DFA_0_ADDR(base) ((base) + 0x040)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_MUDP_0_ADDR(base) ((base) + 0x044)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PROBE_ADDR(base) ((base) + 0x048)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDMS_NOPENDING_0_ADDR(base) ((base) + 0x050)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDMS_NOPENDING_1_ADDR(base) ((base) + 0x054)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_0_ADDR(base) ((base) + 0x058)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_1_ADDR(base) ((base) + 0x05C)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_2_ADDR(base) ((base) + 0x060)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_3_ADDR(base) ((base) + 0x064)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_4_ADDR(base) ((base) + 0x068)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_0_ADDR(base) ((base) + 0x06C)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_1_ADDR(base) ((base) + 0x070)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_2_ADDR(base) ((base) + 0x074)
#define SOC_HSDT0_XCTRL_HSDT0_DFA_QIC_PDM_PDS_STATE_DFA_0_ADDR(base) ((base) + 0x078)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_ADDR(base) ((base) + 0x100)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_0_ADDR(base) ((base) + 0x104)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_1_ADDR(base) ((base) + 0x108)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_0_ADDR(base) ((base) + 0x10C)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_0_ADDR(base) ((base) + 0x110)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_0_ADDR(base) ((base) + 0x114)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_DFA_0_ADDR(base) ((base) + 0x118)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_DFA_0_ADDR(base) ((base) + 0x11C)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_DFA_0_ADDR(base) ((base) + 0x120)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_DFA_0_ADDR(base) ((base) + 0x124)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x128)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x12C)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_MUDP_0_ADDR(base) ((base) + 0x130)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_DFX_BUSY_0_ADDR(base) ((base) + 0x134)
#define SOC_HSDT0_XCTRL_HSDT0_WC_INTR_EM_QIC_BUS_0_ADDR(base) ((base) + 0x138)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_0_ADDR(base) ((base) + 0x13C)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_DFA_0_ADDR(base) ((base) + 0x140)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_MUDP_0_ADDR(base) ((base) + 0x144)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PROBE_ADDR(base) ((base) + 0x148)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDMS_NOPENDING_0_ADDR(base) ((base) + 0x150)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDMS_NOPENDING_1_ADDR(base) ((base) + 0x154)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_0_ADDR(base) ((base) + 0x158)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_1_ADDR(base) ((base) + 0x15C)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_2_ADDR(base) ((base) + 0x160)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_3_ADDR(base) ((base) + 0x164)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_4_ADDR(base) ((base) + 0x168)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_0_ADDR(base) ((base) + 0x16C)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_1_ADDR(base) ((base) + 0x170)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_2_ADDR(base) ((base) + 0x174)
#define SOC_HSDT0_XCTRL_HSDT0_WC_DFA_QIC_PDM_PDS_STATE_DFA_0_ADDR(base) ((base) + 0x178)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_ADDR(base) ((base) + 0x1F8)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_ADDR(base) ((base) + 0x1FC)
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_TB_ADDR(base) ((base) + 0x208)
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_TB_HSDT02DDR_ADDR(base) ((base) + 0x218)
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_IB_SYS2HSDT0_ADDR(base) ((base) + 0x21C)
#define SOC_HSDT0_XCTRL_DFA_QIC_TIMEOUT_EN_TB_ADDR(base) ((base) + 0x220)
#define SOC_HSDT0_XCTRL_DFA_QIC_TIMEOUT_EN_IB_ADDR(base) ((base) + 0x224)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_ADDR(base) ((base) + 0x228)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_1_ADDR(base) ((base) + 0x22C)
#define SOC_HSDT0_XCTRL_nopending_mask_ADDR(base) ((base) + 0x230)
#define SOC_HSDT0_XCTRL_busy_mask_ADDR(base) ((base) + 0x234)
#define SOC_HSDT0_XCTRL_idlereq_mask_ADDR(base) ((base) + 0x238)
#define SOC_HSDT0_XCTRL_idleack_mask_ADDR(base) ((base) + 0x23C)
#define SOC_HSDT0_XCTRL_intr_qic_mask_ADDR(base) ((base) + 0x240)
#define SOC_HSDT0_XCTRL_nopending_lpcm_mask_ADDR(base) ((base) + 0x244)
#define SOC_HSDT0_XCTRL_nopending_mux_sel_ADDR(base) ((base) + 0x260)
#define SOC_HSDT0_XCTRL_busy_mux_sel_ADDR(base) ((base) + 0x264)
#define SOC_HSDT0_XCTRL_idle_req_mux_sel1_ADDR(base) ((base) + 0x268)
#define SOC_HSDT0_XCTRL_idleack_mux_sel1_ADDR(base) ((base) + 0x26C)
#define SOC_HSDT0_XCTRL_intr_qic_mux_sel_ADDR(base) ((base) + 0x270)
#define SOC_HSDT0_XCTRL_nopending_lpcm_mux_sel_ADDR(base) ((base) + 0x274)
#define SOC_HSDT0_XCTRL_hsdt0_tp_sel_ADDR(base) ((base) + 0x400)
#define SOC_HSDT0_XCTRL_hsdt0_jtag_sel_ADDR(base) ((base) + 0x408)
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_ckg_en_ADDR(base) ((base) + 0x40C)
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_dlock_and_dbg_clr_ADDR(base) ((base) + 0x410)
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_idle_ADDR(base) ((base) + 0x420)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_ADDR(base) ((base) + 0x424)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_ADDR(base) ((base) + 0x428)
#define SOC_HSDT0_XCTRL_MEM_CTRL_0_ADDR(base) ((base) + 0x42C)
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_ARVC_CTRL_ADDR(base) ((base) + 0x430)
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_AWVC_CTRL_ADDR(base) ((base) + 0x434)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_ARVC_CTRL_ADDR(base) ((base) + 0x438)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_AWVC_CTRL_ADDR(base) ((base) + 0x43C)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_ARVC_CTRL_ADDR(base) ((base) + 0x440)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_AWVC_CTRL_ADDR(base) ((base) + 0x444)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE_PARALLEL_TEST_EN_ADDR(base) ((base) + 0x448)
#define SOC_HSDT0_XCTRL_hsdt0_qic_soft_lock_dis_ADDR(base) ((base) + 0x800)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_ADDR(base) ((base) + 0xC00)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_ADDR(base) ((base) + 0xC04)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_ADDR(base) ((base) + 0xC08)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_ADDR(base) ((base) + 0xC0C)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_ADDR(base) ((base) + 0xC10)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_ADDR(base) ((base) + 0xC14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_EN_ADDR(base) ((base) + 0xC18)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_DIS_ADDR(base) ((base) + 0xC1C)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_STA_ADDR(base) ((base) + 0xC20)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_EN_ADDR(base) ((base) + 0xC24)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_DIS_ADDR(base) ((base) + 0xC28)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_STA_ADDR(base) ((base) + 0xC2C)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_EN_ADDR(base) ((base) + 0xC30)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_DIS_ADDR(base) ((base) + 0xC34)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_STA_ADDR(base) ((base) + 0xC38)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_EN_ADDR(base) ((base) + 0xC3C)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_DIS_ADDR(base) ((base) + 0xC40)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_STA_ADDR(base) ((base) + 0xC44)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_ADDR(base) ((base) + 0xC48)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_ADDR(base) ((base) + 0xC4C)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_ADDR(base) ((base) + 0xC50)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_LOCK_ADDR(base) ((base) + 0xD00)
#define SOC_HSDT0_XCTRL_qic_timeout_en_tb_mspe_tee_ADDR(base) ((base) + 0xD04)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_TEE_ADDR(base) ((base) + 0xD08)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_TEE_ADDR(base) ((base) + 0xD0C)
#define SOC_HSDT0_XCTRL_MEM_CTRL_QIC_TEE_ADDR(base) ((base) + 0xD10)
#define SOC_HSDT0_XCTRL_pctrl2hieps_ctrl_ADDR(base) ((base) + 0xE00)
#define SOC_HSDT0_XCTRL_hiesp2pctrl_state_l_ADDR(base) ((base) + 0xE04)
#define SOC_HSDT0_XCTRL_hiesp2pctrl_state_h_ADDR(base) ((base) + 0xE08)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_ADDR(base) ((base) + 0xE0C)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_ADDR(base) ((base) + 0xE10)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_ADDR(base) ((base) + 0xE14)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_ADDR(base) ((base) + 0xE18)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_ADDR(base) ((base) + 0xE1C)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_ADDR(base) ((base) + 0xE20)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_TIMEOUT_ST_TB_0_ADDR(base) ((base) + 0xE24)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_TIMEOUT_ST_TB_0_ADDR(base) ((base) + 0xE28)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_SYSPDC_REQ_ADDR(base) ((base) + 0xE34)
#define SOC_HSDT0_XCTRL_HSDT0_SC_QIC_EPS_TEE_SYSPDC_ACK_ADDR(base) ((base) + 0xE38)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_SYSPDC_ACK_ADDR(base) ((base) + 0xE3C)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_bus_qic_nopending_combo : 1;
        unsigned int qic_dfa_qic_nopending_combo : 1;
        unsigned int qic_nopending_pcie1_slv_combo : 1;
        unsigned int qic_mudp_qic_nopending_combo : 1;
        unsigned int qic_nopending_pcie1_slv : 5;
        unsigned int reserved : 23;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_qic_bus_qic_nopending_combo_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_qic_bus_qic_nopending_combo_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_qic_dfa_qic_nopending_combo_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_qic_dfa_qic_nopending_combo_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_qic_nopending_pcie1_slv_combo_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_qic_nopending_pcie1_slv_combo_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_qic_mudp_qic_nopending_combo_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_qic_mudp_qic_nopending_combo_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_qic_nopending_pcie1_slv_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_NOPENDING_COMBO_qic_nopending_pcie1_slv_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rt_nopending_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_0_qic_rt_nopending_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_0_qic_rt_nopending_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rt_nopending_qic_bus_1 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_1_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_1_qic_rt_nopending_qic_bus_1_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_1_qic_rt_nopending_qic_bus_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_wr_nopending_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_0_qic_wr_nopending_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_0_qic_wr_nopending_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rd_nopending_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_0_qic_rd_nopending_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_0_qic_rd_nopending_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_tb_nopending_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_0_qic_tb_nopending_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_0_qic_tb_nopending_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rd_nopending_qic_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_DFA_0_qic_rd_nopending_qic_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_DFA_0_qic_rd_nopending_qic_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_wr_nopending_qic_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_DFA_0_qic_wr_nopending_qic_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_DFA_0_qic_wr_nopending_qic_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rt_nopending_qic_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_DFA_0_qic_rt_nopending_qic_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RT_NOPENDING_DFA_0_qic_rt_nopending_qic_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_tb_nopending_qic_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_DFA_0_qic_tb_nopending_qic_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_DFA_0_qic_tb_nopending_qic_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rd_nopending_qic_mudp_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_MUDP_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_MUDP_0_qic_rd_nopending_qic_mudp_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_RD_NOPENDING_MUDP_0_qic_rd_nopending_qic_mudp_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_wr_nopending_qic_mudp_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_MUDP_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_MUDP_0_qic_wr_nopending_qic_mudp_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_WR_NOPENDING_MUDP_0_qic_wr_nopending_qic_mudp_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_tb_nopending_qic_mudp_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_MUDP_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_MUDP_0_qic_tb_nopending_qic_mudp_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TB_NOPENDING_MUDP_0_qic_tb_nopending_qic_mudp_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_busy_ca_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_DFX_BUSY_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_DFX_BUSY_0_dfx_busy_ca_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_DFX_BUSY_0_dfx_busy_ca_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_em_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_INTR_EM_QIC_BUS_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_INTR_EM_QIC_BUS_0_intr_em_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_INTR_EM_QIC_BUS_0_intr_em_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_0_qic_timeout_st_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_0_qic_timeout_st_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_qic_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_DFA_0_qic_timeout_st_qic_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_DFA_0_qic_timeout_st_qic_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_qic_mudp_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_MUDP_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_MUDP_0_qic_timeout_st_qic_mudp_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_TIMEOUT_ST_MUDP_0_qic_timeout_st_qic_mudp_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_qic_probe_qic_bus : 1;
        unsigned int intr_dfa_qic_intr_emc : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_PROBE_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PROBE_intr_qic_probe_qic_bus_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PROBE_intr_qic_probe_qic_bus_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PROBE_intr_dfa_qic_intr_emc_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PROBE_intr_dfa_qic_intr_emc_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdms_nopending_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_PDMS_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDMS_NOPENDING_0_qic_pdms_nopending_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDMS_NOPENDING_0_qic_pdms_nopending_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdms_nopending_qic_bus_1 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_PDMS_NOPENDING_1_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDMS_NOPENDING_1_qic_pdms_nopending_qic_bus_1_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDMS_NOPENDING_1_qic_pdms_nopending_qic_bus_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_0_qic_pdm_state_pdm_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_0_qic_pdm_state_pdm_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_qic_bus_1 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_1_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_1_qic_pdm_state_pdm_qic_bus_1_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_1_qic_pdm_state_pdm_qic_bus_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_qic_bus_2 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_2_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_2_qic_pdm_state_pdm_qic_bus_2_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_2_qic_pdm_state_pdm_qic_bus_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_qic_bus_3 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_3_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_3_qic_pdm_state_pdm_qic_bus_3_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_3_qic_pdm_state_pdm_qic_bus_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_qic_bus_4 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_4_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_4_qic_pdm_state_pdm_qic_bus_4_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDM_STATE_QIC_BUS_4_qic_pdm_state_pdm_qic_bus_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pds_state_pds_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_0_qic_pds_state_pds_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_0_qic_pds_state_pds_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pds_state_pds_qic_bus_1 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_1_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_1_qic_pds_state_pds_qic_bus_1_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_1_qic_pds_state_pds_qic_bus_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pds_state_pds_qic_bus_2 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_2_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_2_qic_pds_state_pds_qic_bus_2_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_PDS_STATE_QIC_BUS_2_qic_pds_state_pds_qic_bus_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_qic_pdm_pds_state_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_DFA_QIC_PDM_PDS_STATE_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_DFA_QIC_PDM_PDS_STATE_DFA_0_dfa_qic_pdm_pds_state_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_DFA_QIC_PDM_PDS_STATE_DFA_0_dfa_qic_pdm_pds_state_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_bus_qic_nopending_combo : 1;
        unsigned int wc_qic_dfa_qic_nopending_combo : 1;
        unsigned int wc_qic_nopending_pcie1_slv_combo : 1;
        unsigned int wc_qic_mudp_qic_nopending_combo : 1;
        unsigned int wc_qic_nopending_pcie1_slv : 5;
        unsigned int reserved : 23;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_wc_qic_bus_qic_nopending_combo_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_wc_qic_bus_qic_nopending_combo_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_wc_qic_dfa_qic_nopending_combo_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_wc_qic_dfa_qic_nopending_combo_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_wc_qic_nopending_pcie1_slv_combo_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_wc_qic_nopending_pcie1_slv_combo_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_wc_qic_mudp_qic_nopending_combo_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_wc_qic_mudp_qic_nopending_combo_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_wc_qic_nopending_pcie1_slv_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_NOPENDING_COMBO_wc_qic_nopending_pcie1_slv_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rt_nopending_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_0_wc_qic_rt_nopending_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_0_wc_qic_rt_nopending_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rt_nopending_qic_bus_1 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_1_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_1_wc_qic_rt_nopending_qic_bus_1_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_1_wc_qic_rt_nopending_qic_bus_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_wr_nopending_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_0_wc_qic_wr_nopending_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_0_wc_qic_wr_nopending_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rd_nopending_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_0_wc_qic_rd_nopending_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_0_wc_qic_rd_nopending_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_tb_nopending_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_0_wc_qic_tb_nopending_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_0_wc_qic_tb_nopending_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rd_nopending_qic_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_DFA_0_wc_qic_rd_nopending_qic_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_DFA_0_wc_qic_rd_nopending_qic_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_wr_nopending_qic_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_DFA_0_wc_qic_wr_nopending_qic_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_DFA_0_wc_qic_wr_nopending_qic_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rt_nopending_qic_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_DFA_0_wc_qic_rt_nopending_qic_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RT_NOPENDING_DFA_0_wc_qic_rt_nopending_qic_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_tb_nopending_qic_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_DFA_0_wc_qic_tb_nopending_qic_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_DFA_0_wc_qic_tb_nopending_qic_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rd_nopending_qic_mudp_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_MUDP_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_MUDP_0_wc_qic_rd_nopending_qic_mudp_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_RD_NOPENDING_MUDP_0_wc_qic_rd_nopending_qic_mudp_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_wr_nopending_qic_mudp_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_MUDP_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_MUDP_0_wc_qic_wr_nopending_qic_mudp_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_WR_NOPENDING_MUDP_0_wc_qic_wr_nopending_qic_mudp_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_tb_nopending_qic_mudp_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_MUDP_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_MUDP_0_wc_qic_tb_nopending_qic_mudp_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TB_NOPENDING_MUDP_0_wc_qic_tb_nopending_qic_mudp_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_dfx_busy_ca_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_DFX_BUSY_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_DFX_BUSY_0_wc_dfx_busy_ca_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_DFX_BUSY_0_wc_dfx_busy_ca_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_em_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_INTR_EM_QIC_BUS_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_INTR_EM_QIC_BUS_0_wc_intr_em_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_INTR_EM_QIC_BUS_0_wc_intr_em_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_timeout_st_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_0_wc_qic_timeout_st_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_0_wc_qic_timeout_st_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_timeout_st_qic_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_DFA_0_wc_qic_timeout_st_qic_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_DFA_0_wc_qic_timeout_st_qic_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_timeout_st_qic_mudp_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_MUDP_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_MUDP_0_wc_qic_timeout_st_qic_mudp_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_TIMEOUT_ST_MUDP_0_wc_qic_timeout_st_qic_mudp_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_qic_probe_qic_bus : 1;
        unsigned int wc_intr_dfa_qic_intr_emc : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PROBE_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PROBE_wc_intr_qic_probe_qic_bus_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PROBE_wc_intr_qic_probe_qic_bus_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PROBE_wc_intr_dfa_qic_intr_emc_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PROBE_wc_intr_dfa_qic_intr_emc_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdms_nopending_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDMS_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDMS_NOPENDING_0_wc_qic_pdms_nopending_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDMS_NOPENDING_0_wc_qic_pdms_nopending_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdms_nopending_qic_bus_1 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDMS_NOPENDING_1_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDMS_NOPENDING_1_wc_qic_pdms_nopending_qic_bus_1_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDMS_NOPENDING_1_wc_qic_pdms_nopending_qic_bus_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_0_wc_qic_pdm_state_pdm_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_0_wc_qic_pdm_state_pdm_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_qic_bus_1 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_1_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_1_wc_qic_pdm_state_pdm_qic_bus_1_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_1_wc_qic_pdm_state_pdm_qic_bus_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_qic_bus_2 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_2_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_2_wc_qic_pdm_state_pdm_qic_bus_2_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_2_wc_qic_pdm_state_pdm_qic_bus_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_qic_bus_3 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_3_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_3_wc_qic_pdm_state_pdm_qic_bus_3_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_3_wc_qic_pdm_state_pdm_qic_bus_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_qic_bus_4 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_4_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_4_wc_qic_pdm_state_pdm_qic_bus_4_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDM_STATE_QIC_BUS_4_wc_qic_pdm_state_pdm_qic_bus_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pds_state_pds_qic_bus_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_0_wc_qic_pds_state_pds_qic_bus_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_0_wc_qic_pds_state_pds_qic_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pds_state_pds_qic_bus_1 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_1_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_1_wc_qic_pds_state_pds_qic_bus_1_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_1_wc_qic_pds_state_pds_qic_bus_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pds_state_pds_qic_bus_2 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_2_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_2_wc_qic_pds_state_pds_qic_bus_2_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_PDS_STATE_QIC_BUS_2_wc_qic_pds_state_pds_qic_bus_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_dfa_qic_pdm_pds_state_dfa_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_DFA_QIC_PDM_PDS_STATE_DFA_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_DFA_QIC_PDM_PDS_STATE_DFA_0_wc_dfa_qic_pdm_pds_state_dfa_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_DFA_QIC_PDM_PDS_STATE_DFA_0_wc_dfa_qic_pdm_pds_state_dfa_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_pdc_hsdt0_syspdc_pwrd_req : 1;
        unsigned int wc_pdc_mudp_syspdc_pwrd_req : 1;
        unsigned int wc_pdc_dfa_syspdc_pwrd_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int wc_pdc_pcie_m0_syspdc_pwrd_req : 1;
        unsigned int wc_pdc_pcie_m1_syspdc_pwrd_req : 1;
        unsigned int wc_pdc_eps_ree_syspdc_pwrd_req : 1;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_hsdt0_syspdc_pwrd_req_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_hsdt0_syspdc_pwrd_req_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_mudp_syspdc_pwrd_req_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_mudp_syspdc_pwrd_req_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_dfa_syspdc_pwrd_req_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_dfa_syspdc_pwrd_req_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_pcie_m0_syspdc_pwrd_req_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_pcie_m0_syspdc_pwrd_req_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_pcie_m1_syspdc_pwrd_req_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_pcie_m1_syspdc_pwrd_req_END (5)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_eps_ree_syspdc_pwrd_req_START (6)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_REQ_wc_pdc_eps_ree_syspdc_pwrd_req_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_pdc_hsdt0_syspdc_pwrd_ack : 1;
        unsigned int wc_pdc_mudp_syspdc_pwrd_ack : 1;
        unsigned int wc_pdc_dfa_syspdc_pwrd_ack : 1;
        unsigned int reserved_0 : 1;
        unsigned int wc_pdc_pcie_m0_syspdc_pwrd_ack : 1;
        unsigned int wc_pdc_pcie_m1_syspdc_pwrd_ack : 1;
        unsigned int wc_pdc_eps_ree_syspdc_pwrd_ack : 1;
        unsigned int wc_dfa_qic_pdc_dfa_syspdc_pwrd_ack : 1;
        unsigned int wc_dfa_qic_pdc_qcp_syspdc_pwrd_ack : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_hsdt0_syspdc_pwrd_ack_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_hsdt0_syspdc_pwrd_ack_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_mudp_syspdc_pwrd_ack_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_mudp_syspdc_pwrd_ack_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_dfa_syspdc_pwrd_ack_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_dfa_syspdc_pwrd_ack_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_pcie_m0_syspdc_pwrd_ack_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_pcie_m0_syspdc_pwrd_ack_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_pcie_m1_syspdc_pwrd_ack_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_pcie_m1_syspdc_pwrd_ack_END (5)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_eps_ree_syspdc_pwrd_ack_START (6)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_pdc_eps_ree_syspdc_pwrd_ack_END (6)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_dfa_qic_pdc_dfa_syspdc_pwrd_ack_START (7)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_dfa_qic_pdc_dfa_syspdc_pwrd_ack_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_dfa_qic_pdc_qcp_syspdc_pwrd_ack_START (8)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_SYSPDC_ACK_wc_dfa_qic_pdc_qcp_syspdc_pwrd_ack_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en_tb : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_TB_UNION;
#endif
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_TB_qic_timeout_en_tb_START (0)
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_TB_qic_timeout_en_tb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en_tb_hsdt02ddr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_TB_HSDT02DDR_UNION;
#endif
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_TB_HSDT02DDR_qic_timeout_en_tb_hsdt02ddr_START (0)
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_TB_HSDT02DDR_qic_timeout_en_tb_hsdt02ddr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en_ib_sys2hsdt0 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_IB_SYS2HSDT0_UNION;
#endif
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_IB_SYS2HSDT0_qic_timeout_en_ib_sys2hsdt0_START (0)
#define SOC_HSDT0_XCTRL_QIC_TIMEOUT_EN_IB_SYS2HSDT0_qic_timeout_en_ib_sys2hsdt0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_qic_timeout_en_tb : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_DFA_QIC_TIMEOUT_EN_TB_UNION;
#endif
#define SOC_HSDT0_XCTRL_DFA_QIC_TIMEOUT_EN_TB_dfa_qic_timeout_en_tb_START (0)
#define SOC_HSDT0_XCTRL_DFA_QIC_TIMEOUT_EN_TB_dfa_qic_timeout_en_tb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_qic_timeout_en_ib : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_DFA_QIC_TIMEOUT_EN_IB_UNION;
#endif
#define SOC_HSDT0_XCTRL_DFA_QIC_TIMEOUT_EN_IB_dfa_qic_timeout_en_ib_START (0)
#define SOC_HSDT0_XCTRL_DFA_QIC_TIMEOUT_EN_IB_dfa_qic_timeout_en_ib_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_qic_axi0_awpush : 3;
        unsigned int dfa_qic_axi0_arpush : 3;
        unsigned int dfa_qic_axi1_awpush : 3;
        unsigned int dfa_qic_axi1_arpush : 3;
        unsigned int dfa_qic_axi2_awpush : 3;
        unsigned int dfa_qic_axi2_arpush : 3;
        unsigned int dfa_qic_axi3_awpush : 3;
        unsigned int dfa_qic_axi3_arpush : 3;
        unsigned int dfa_qic_axi4_awpush : 3;
        unsigned int dfa_qic_axi4_arpush : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi0_awpush_START (0)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi0_awpush_END (2)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi0_arpush_START (3)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi0_arpush_END (5)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi1_awpush_START (6)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi1_awpush_END (8)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi1_arpush_START (9)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi1_arpush_END (11)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi2_awpush_START (12)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi2_awpush_END (14)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi2_arpush_START (15)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi2_arpush_END (17)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi3_awpush_START (18)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi3_awpush_END (20)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi3_arpush_START (21)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi3_arpush_END (23)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi4_awpush_START (24)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi4_awpush_END (26)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi4_arpush_START (27)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_0_dfa_qic_axi4_arpush_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_qic_axi6_awpush : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_1_UNION;
#endif
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_1_dfa_qic_axi6_awpush_START (0)
#define SOC_HSDT0_XCTRL_DFA_QIC_CTRL_PUSH_1_dfa_qic_axi6_awpush_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_mask : 32;
    } reg;
} SOC_HSDT0_XCTRL_nopending_mask_UNION;
#endif
#define SOC_HSDT0_XCTRL_nopending_mask_nopending_mask_START (0)
#define SOC_HSDT0_XCTRL_nopending_mask_nopending_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int busy_mask : 32;
    } reg;
} SOC_HSDT0_XCTRL_busy_mask_UNION;
#endif
#define SOC_HSDT0_XCTRL_busy_mask_busy_mask_START (0)
#define SOC_HSDT0_XCTRL_busy_mask_busy_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idlereq_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_idlereq_mask_UNION;
#endif
#define SOC_HSDT0_XCTRL_idlereq_mask_idlereq_mask_START (0)
#define SOC_HSDT0_XCTRL_idlereq_mask_idlereq_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idleack_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_idleack_mask_UNION;
#endif
#define SOC_HSDT0_XCTRL_idleack_mask_idleack_mask_START (0)
#define SOC_HSDT0_XCTRL_idleack_mask_idleack_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_qic_mask : 32;
    } reg;
} SOC_HSDT0_XCTRL_intr_qic_mask_UNION;
#endif
#define SOC_HSDT0_XCTRL_intr_qic_mask_intr_qic_mask_START (0)
#define SOC_HSDT0_XCTRL_intr_qic_mask_intr_qic_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_lpcm_mask : 32;
    } reg;
} SOC_HSDT0_XCTRL_nopending_lpcm_mask_UNION;
#endif
#define SOC_HSDT0_XCTRL_nopending_lpcm_mask_nopending_lpcm_mask_START (0)
#define SOC_HSDT0_XCTRL_nopending_lpcm_mask_nopending_lpcm_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_mux_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT0_XCTRL_nopending_mux_sel_UNION;
#endif
#define SOC_HSDT0_XCTRL_nopending_mux_sel_nopending_mux_sel_START (0)
#define SOC_HSDT0_XCTRL_nopending_mux_sel_nopending_mux_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int busy_mux_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT0_XCTRL_busy_mux_sel_UNION;
#endif
#define SOC_HSDT0_XCTRL_busy_mux_sel_busy_mux_sel_START (0)
#define SOC_HSDT0_XCTRL_busy_mux_sel_busy_mux_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idle_req_mux_sel1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_idle_req_mux_sel1_UNION;
#endif
#define SOC_HSDT0_XCTRL_idle_req_mux_sel1_idle_req_mux_sel1_START (0)
#define SOC_HSDT0_XCTRL_idle_req_mux_sel1_idle_req_mux_sel1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idleack_mux_sel1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_idleack_mux_sel1_UNION;
#endif
#define SOC_HSDT0_XCTRL_idleack_mux_sel1_idleack_mux_sel1_START (0)
#define SOC_HSDT0_XCTRL_idleack_mux_sel1_idleack_mux_sel1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_qic_mux_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT0_XCTRL_intr_qic_mux_sel_UNION;
#endif
#define SOC_HSDT0_XCTRL_intr_qic_mux_sel_intr_qic_mux_sel_START (0)
#define SOC_HSDT0_XCTRL_intr_qic_mux_sel_intr_qic_mux_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_lpcm_mux_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT0_XCTRL_nopending_lpcm_mux_sel_UNION;
#endif
#define SOC_HSDT0_XCTRL_nopending_lpcm_mux_sel_nopending_lpcm_mux_sel_START (0)
#define SOC_HSDT0_XCTRL_nopending_lpcm_mux_sel_nopending_lpcm_mux_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt0_tp_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT0_XCTRL_hsdt0_tp_sel_UNION;
#endif
#define SOC_HSDT0_XCTRL_hsdt0_tp_sel_hsdt0_tp_sel_START (0)
#define SOC_HSDT0_XCTRL_hsdt0_tp_sel_hsdt0_tp_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt0_jtag_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT0_XCTRL_hsdt0_jtag_sel_UNION;
#endif
#define SOC_HSDT0_XCTRL_hsdt0_jtag_sel_hsdt0_jtag_sel_START (0)
#define SOC_HSDT0_XCTRL_hsdt0_jtag_sel_hsdt0_jtag_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt0_himinibus_ckg_en : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_HSDT0_XCTRL_hsdt0_himinibus_ckg_en_UNION;
#endif
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_ckg_en_hsdt0_himinibus_ckg_en_START (0)
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_ckg_en_hsdt0_himinibus_ckg_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt0_himinibus_dlock_and_dbg_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_hsdt0_himinibus_dlock_and_dbg_clr_UNION;
#endif
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_dlock_and_dbg_clr_hsdt0_himinibus_dlock_and_dbg_clr_START (0)
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_dlock_and_dbg_clr_hsdt0_himinibus_dlock_and_dbg_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt0_himinibus_idle : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_HSDT0_XCTRL_hsdt0_himinibus_idle_UNION;
#endif
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_idle_hsdt0_himinibus_idle_START (0)
#define SOC_HSDT0_XCTRL_hsdt0_himinibus_idle_hsdt0_himinibus_idle_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_hsdt0_syspdc_pwrd_req : 1;
        unsigned int pdc_mudp_syspdc_pwrd_req : 1;
        unsigned int pdc_dfa_syspdc_pwrd_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int pdc_pcie_m0_syspdc_pwrd_req : 1;
        unsigned int pdc_pcie_m1_syspdc_pwrd_req : 1;
        unsigned int pdc_eps_ree_syspdc_pwrd_req : 1;
        unsigned int reserved_1 : 9;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_hsdt0_syspdc_pwrd_req_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_hsdt0_syspdc_pwrd_req_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_mudp_syspdc_pwrd_req_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_mudp_syspdc_pwrd_req_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_dfa_syspdc_pwrd_req_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_dfa_syspdc_pwrd_req_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_pcie_m0_syspdc_pwrd_req_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_pcie_m0_syspdc_pwrd_req_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_pcie_m1_syspdc_pwrd_req_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_pcie_m1_syspdc_pwrd_req_END (5)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_eps_ree_syspdc_pwrd_req_START (6)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_pdc_eps_ree_syspdc_pwrd_req_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_hsdt0_syspdc_pwrd_ack : 1;
        unsigned int pdc_mudp_syspdc_pwrd_ack : 1;
        unsigned int pdc_dfa_syspdc_pwrd_ack : 1;
        unsigned int reserved_0 : 1;
        unsigned int pdc_pcie_m0_syspdc_pwrd_ack : 1;
        unsigned int pdc_pcie_m1_syspdc_pwrd_ack : 1;
        unsigned int pdc_eps_ree_syspdc_pwrd_ack : 1;
        unsigned int dfa_qic_pdc_dfa_syspdc_pwrd_ack : 1;
        unsigned int dfa_qic_pdc_qcp_syspdc_pwrd_ack : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_hsdt0_syspdc_pwrd_ack_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_hsdt0_syspdc_pwrd_ack_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_mudp_syspdc_pwrd_ack_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_mudp_syspdc_pwrd_ack_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_dfa_syspdc_pwrd_ack_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_dfa_syspdc_pwrd_ack_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_pcie_m0_syspdc_pwrd_ack_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_pcie_m0_syspdc_pwrd_ack_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_pcie_m1_syspdc_pwrd_ack_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_pcie_m1_syspdc_pwrd_ack_END (5)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_eps_ree_syspdc_pwrd_ack_START (6)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_pdc_eps_ree_syspdc_pwrd_ack_END (6)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_dfa_qic_pdc_dfa_syspdc_pwrd_ack_START (7)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_dfa_qic_pdc_dfa_syspdc_pwrd_ack_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_dfa_qic_pdc_qcp_syspdc_pwrd_ack_START (8)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_dfa_qic_pdc_qcp_syspdc_pwrd_ack_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_MEM_CTRL_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_MEM_CTRL_0_mem_ctrl_START (0)
#define SOC_HSDT0_XCTRL_MEM_CTRL_0_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps_ree_icfg_arvcidx_ddr : 8;
        unsigned int eps_ree_icfg_arvcidx_device : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_EPS_REE_ARVC_CTRL_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_ARVC_CTRL_eps_ree_icfg_arvcidx_ddr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_ARVC_CTRL_eps_ree_icfg_arvcidx_ddr_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_ARVC_CTRL_eps_ree_icfg_arvcidx_device_START (8)
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_ARVC_CTRL_eps_ree_icfg_arvcidx_device_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps_ree_icfg_awvcidx_ddr : 8;
        unsigned int eps_ree_icfg_awvcidx_device : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_EPS_REE_AWVC_CTRL_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_AWVC_CTRL_eps_ree_icfg_awvcidx_ddr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_AWVC_CTRL_eps_ree_icfg_awvcidx_ddr_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_AWVC_CTRL_eps_ree_icfg_awvcidx_device_START (8)
#define SOC_HSDT0_XCTRL_HSDT0_EPS_REE_AWVC_CTRL_eps_ree_icfg_awvcidx_device_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie0_icfg_arvcidx_ddr : 8;
        unsigned int pcie0_icfg_arvcidx_device : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_PCIE0_ARVC_CTRL_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_ARVC_CTRL_pcie0_icfg_arvcidx_ddr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_ARVC_CTRL_pcie0_icfg_arvcidx_ddr_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_ARVC_CTRL_pcie0_icfg_arvcidx_device_START (8)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_ARVC_CTRL_pcie0_icfg_arvcidx_device_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie0_icfg_awvcidx_ddr : 8;
        unsigned int pcie0_icfg_awvcidx_device : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_PCIE0_AWVC_CTRL_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_AWVC_CTRL_pcie0_icfg_awvcidx_ddr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_AWVC_CTRL_pcie0_icfg_awvcidx_ddr_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_AWVC_CTRL_pcie0_icfg_awvcidx_device_START (8)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE0_AWVC_CTRL_pcie0_icfg_awvcidx_device_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie1_icfg_arvcidx_ddr : 8;
        unsigned int pcie1_icfg_arvcidx_device : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_PCIE1_ARVC_CTRL_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_ARVC_CTRL_pcie1_icfg_arvcidx_ddr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_ARVC_CTRL_pcie1_icfg_arvcidx_ddr_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_ARVC_CTRL_pcie1_icfg_arvcidx_device_START (8)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_ARVC_CTRL_pcie1_icfg_arvcidx_device_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie1_icfg_awvcidx_ddr : 8;
        unsigned int pcie1_icfg_awvcidx_device : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_PCIE1_AWVC_CTRL_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_AWVC_CTRL_pcie1_icfg_awvcidx_ddr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_AWVC_CTRL_pcie1_icfg_awvcidx_ddr_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_AWVC_CTRL_pcie1_icfg_awvcidx_device_START (8)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE1_AWVC_CTRL_pcie1_icfg_awvcidx_device_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_phy_parallel_test_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_PCIE_PARALLEL_TEST_EN_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_PCIE_PARALLEL_TEST_EN_pcie_phy_parallel_test_en_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_PCIE_PARALLEL_TEST_EN_pcie_phy_parallel_test_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt0_qic_soft_lock_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_hsdt0_qic_soft_lock_dis_UNION;
#endif
#define SOC_HSDT0_XCTRL_hsdt0_qic_soft_lock_dis_hsdt0_qic_soft_lock_dis_START (0)
#define SOC_HSDT0_XCTRL_hsdt0_qic_soft_lock_dis_hsdt0_qic_soft_lock_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_pcie0_dbi_set : 1;
        unsigned int tz_secure_n_pcie0_phy_set : 1;
        unsigned int tz_secure_n_pcie0_sctrl_set : 1;
        unsigned int tz_secure_n_pcie0_xsecure_n_set : 1;
        unsigned int tz_secure_n_pcie1_dbi_set : 1;
        unsigned int tz_secure_n_pcie1_phy_set : 1;
        unsigned int tz_secure_n_pcie1_sctrl_set : 1;
        unsigned int tz_secure_n_pcie1_xsecure_n_set : 1;
        unsigned int reserved_0 : 1;
        unsigned int tz_secure_n_hsdt0_qic_qcp_set : 1;
        unsigned int tz_secure_n_hsdt0_xctrl_ns_set : 1;
        unsigned int tz_secure_n_hsdt0_xctrl_s_set : 1;
        unsigned int tz_secure_n_hsdt0_sctrl_ns_set : 1;
        unsigned int tz_secure_n_hsdt0_sctrl_s_set : 1;
        unsigned int tz_secure_n_hsdt0_crg_ns_set : 1;
        unsigned int tz_secure_n_hsdt0_crg_s_set : 1;
        unsigned int tz_secure_n_hsdt0_crg_fnpll_pcie_ns_set : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie0_dbi_set_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie0_dbi_set_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie0_phy_set_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie0_phy_set_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie0_sctrl_set_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie0_sctrl_set_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie0_xsecure_n_set_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie0_xsecure_n_set_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie1_dbi_set_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie1_dbi_set_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie1_phy_set_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie1_phy_set_END (5)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie1_sctrl_set_START (6)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie1_sctrl_set_END (6)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie1_xsecure_n_set_START (7)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_pcie1_xsecure_n_set_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_qic_qcp_set_START (9)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_qic_qcp_set_END (9)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_xctrl_ns_set_START (10)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_xctrl_ns_set_END (10)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_xctrl_s_set_START (11)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_xctrl_s_set_END (11)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_sctrl_ns_set_START (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_sctrl_ns_set_END (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_sctrl_s_set_START (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_sctrl_s_set_END (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_crg_ns_set_START (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_crg_ns_set_END (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_crg_s_set_START (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_crg_s_set_END (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_crg_fnpll_pcie_ns_set_START (16)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt0_crg_fnpll_pcie_ns_set_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_pcie0_dbi_clr : 1;
        unsigned int tz_secure_n_pcie0_phy_clr : 1;
        unsigned int tz_secure_n_pcie0_sctrl_clr : 1;
        unsigned int tz_secure_n_pcie0_xsecure_n_clr : 1;
        unsigned int tz_secure_n_pcie1_dbi_clr : 1;
        unsigned int tz_secure_n_pcie1_phy_clr : 1;
        unsigned int tz_secure_n_pcie1_sctrl_clr : 1;
        unsigned int tz_secure_n_pcie1_xsecure_n_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int tz_secure_n_hsdt0_qic_qcp_clr : 1;
        unsigned int tz_secure_n_hsdt0_xctrl_ns_clr : 1;
        unsigned int tz_secure_n_hsdt0_xctrl_s_clr : 1;
        unsigned int tz_secure_n_hsdt0_sctrl_ns_clr : 1;
        unsigned int tz_secure_n_hsdt0_sctrl_s_clr : 1;
        unsigned int tz_secure_n_hsdt0_crg_ns_clr : 1;
        unsigned int tz_secure_n_hsdt0_crg_s_clr : 1;
        unsigned int tz_secure_n_hsdt0_crg_fnpll_pcie_ns_clr : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie0_dbi_clr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie0_dbi_clr_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie0_phy_clr_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie0_phy_clr_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie0_sctrl_clr_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie0_sctrl_clr_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie0_xsecure_n_clr_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie0_xsecure_n_clr_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie1_dbi_clr_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie1_dbi_clr_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie1_phy_clr_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie1_phy_clr_END (5)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie1_sctrl_clr_START (6)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie1_sctrl_clr_END (6)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie1_xsecure_n_clr_START (7)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_pcie1_xsecure_n_clr_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_qic_qcp_clr_START (9)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_qic_qcp_clr_END (9)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_xctrl_ns_clr_START (10)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_xctrl_ns_clr_END (10)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_xctrl_s_clr_START (11)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_xctrl_s_clr_END (11)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_sctrl_ns_clr_START (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_sctrl_ns_clr_END (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_sctrl_s_clr_START (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_sctrl_s_clr_END (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_crg_ns_clr_START (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_crg_ns_clr_END (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_crg_s_clr_START (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_crg_s_clr_END (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_crg_fnpll_pcie_ns_clr_START (16)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt0_crg_fnpll_pcie_ns_clr_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_pcie0_dbi : 1;
        unsigned int tz_secure_n_pcie0_phy : 1;
        unsigned int tz_secure_n_pcie0_sctrl : 1;
        unsigned int tz_secure_n_pcie0_xsecure_n : 1;
        unsigned int tz_secure_n_pcie1_dbi : 1;
        unsigned int tz_secure_n_pcie1_phy : 1;
        unsigned int tz_secure_n_pcie1_sctrl : 1;
        unsigned int tz_secure_n_pcie1_xsecure_n : 1;
        unsigned int reserved_0 : 1;
        unsigned int tz_secure_n_hsdt0_qic_qcp : 1;
        unsigned int tz_secure_n_hsdt0_xctrl_ns : 1;
        unsigned int tz_secure_n_hsdt0_xctrl_s : 1;
        unsigned int tz_secure_n_hsdt0_sctrl_ns : 1;
        unsigned int tz_secure_n_hsdt0_sctrl_s : 1;
        unsigned int tz_secure_n_hsdt0_crg_ns : 1;
        unsigned int tz_secure_n_hsdt0_crg_s : 1;
        unsigned int tz_secure_n_hsdt0_crg_fnpll_pcie_ns : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie0_dbi_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie0_dbi_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie0_phy_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie0_phy_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie0_sctrl_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie0_sctrl_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie0_xsecure_n_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie0_xsecure_n_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie1_dbi_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie1_dbi_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie1_phy_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie1_phy_END (5)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie1_sctrl_START (6)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie1_sctrl_END (6)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie1_xsecure_n_START (7)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_pcie1_xsecure_n_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_qic_qcp_START (9)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_qic_qcp_END (9)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_xctrl_ns_START (10)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_xctrl_ns_END (10)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_xctrl_s_START (11)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_xctrl_s_END (11)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_sctrl_ns_START (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_sctrl_ns_END (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_sctrl_s_START (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_sctrl_s_END (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_crg_ns_START (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_crg_ns_END (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_crg_s_START (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_crg_s_END (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_crg_fnpll_pcie_ns_START (16)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt0_crg_fnpll_pcie_ns_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ufs_sctrl_set : 1;
        unsigned int tz_secure_n_ufs_trace_set : 1;
        unsigned int tz_secure_n_ufs_ufshc_set : 1;
        unsigned int tz_secure_n_ufs_unipro_set : 1;
        unsigned int tz_secure_n_dfa_set : 8;
        unsigned int tz_secure_n_ufs_hmb_xsecure_n_set : 1;
        unsigned int tz_secure_n_ufs_trace_xsecure_n_set : 1;
        unsigned int tz_secure_n_ufs_xsecure_n_set : 1;
        unsigned int tz_secure_n_dfa_cpu_xsecure_n_set : 1;
        unsigned int tz_secure_n_dfa_mop_xsecure_n_set : 1;
        unsigned int tz_secure_n_dfa_wop_xsecure_n_set : 1;
        unsigned int tz_secure_n_ufs_mphy_set : 1;
        unsigned int reserved : 13;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_sctrl_set_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_sctrl_set_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_trace_set_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_trace_set_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_ufshc_set_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_ufshc_set_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_unipro_set_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_unipro_set_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_dfa_set_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_dfa_set_END (11)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_hmb_xsecure_n_set_START (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_hmb_xsecure_n_set_END (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_trace_xsecure_n_set_START (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_trace_xsecure_n_set_END (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_xsecure_n_set_START (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_xsecure_n_set_END (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_dfa_cpu_xsecure_n_set_START (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_dfa_cpu_xsecure_n_set_END (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_dfa_mop_xsecure_n_set_START (16)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_dfa_mop_xsecure_n_set_END (16)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_dfa_wop_xsecure_n_set_START (17)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_dfa_wop_xsecure_n_set_END (17)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_mphy_set_START (18)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_EN_tz_secure_n_ufs_mphy_set_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ufs_sctrl_clr : 1;
        unsigned int tz_secure_n_ufs_trace_clr : 1;
        unsigned int tz_secure_n_ufs_ufshc_clr : 1;
        unsigned int tz_secure_n_ufs_unipro_clr : 1;
        unsigned int tz_secure_n_dfa_clr : 8;
        unsigned int tz_secure_n_ufs_hmb_xsecure_n_clr : 1;
        unsigned int tz_secure_n_ufs_trace_xsecure_n_clr : 1;
        unsigned int tz_secure_n_ufs_xsecure_n_clr : 1;
        unsigned int tz_secure_n_dfa_cpu_xsecure_n_clr : 1;
        unsigned int tz_secure_n_dfa_mop_xsecure_n_clr : 1;
        unsigned int tz_secure_n_dfa_wop_xsecure_n_clr : 1;
        unsigned int tz_secure_n_ufs_mphy_clr : 1;
        unsigned int reserved : 13;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_sctrl_clr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_sctrl_clr_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_trace_clr_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_trace_clr_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_ufshc_clr_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_ufshc_clr_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_unipro_clr_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_unipro_clr_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_dfa_clr_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_dfa_clr_END (11)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_hmb_xsecure_n_clr_START (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_hmb_xsecure_n_clr_END (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_trace_xsecure_n_clr_START (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_trace_xsecure_n_clr_END (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_xsecure_n_clr_START (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_xsecure_n_clr_END (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_dfa_cpu_xsecure_n_clr_START (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_dfa_cpu_xsecure_n_clr_END (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_dfa_mop_xsecure_n_clr_START (16)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_dfa_mop_xsecure_n_clr_END (16)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_dfa_wop_xsecure_n_clr_START (17)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_dfa_wop_xsecure_n_clr_END (17)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_mphy_clr_START (18)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_DIS_tz_secure_n_ufs_mphy_clr_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ufs_sctrl : 1;
        unsigned int tz_secure_n_ufs_trace : 1;
        unsigned int tz_secure_n_ufs_ufshc : 1;
        unsigned int tz_secure_n_ufs_unipro : 1;
        unsigned int tz_secure_n_dfa : 8;
        unsigned int tz_secure_n_ufs_hmb_xsecure_n : 1;
        unsigned int tz_secure_n_ufs_trace_xsecure_n : 1;
        unsigned int tz_secure_n_ufs_xsecure_n : 1;
        unsigned int tz_secure_n_dfa_cpu_xsecure_n : 1;
        unsigned int tz_secure_n_dfa_mop_xsecure_n : 1;
        unsigned int tz_secure_n_dfa_wop_xsecure_n : 1;
        unsigned int tz_secure_n_ufs_mphy : 1;
        unsigned int reserved : 13;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_sctrl_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_sctrl_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_trace_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_trace_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_ufshc_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_ufshc_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_unipro_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_unipro_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_dfa_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_dfa_END (11)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_hmb_xsecure_n_START (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_hmb_xsecure_n_END (12)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_trace_xsecure_n_START (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_trace_xsecure_n_END (13)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_xsecure_n_START (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_xsecure_n_END (14)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_dfa_cpu_xsecure_n_START (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_dfa_cpu_xsecure_n_END (15)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_dfa_mop_xsecure_n_START (16)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_dfa_mop_xsecure_n_END (16)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_dfa_wop_xsecure_n_START (17)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_dfa_wop_xsecure_n_END (17)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_mphy_START (18)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP1_LOCK_STA_tz_secure_n_ufs_mphy_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie0_firewall_mainslv_sec_flag_set : 8;
        unsigned int pcie1_firewall_mainslv_sec_flag_set : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_EN_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_EN_pcie0_firewall_mainslv_sec_flag_set_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_EN_pcie0_firewall_mainslv_sec_flag_set_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_EN_pcie1_firewall_mainslv_sec_flag_set_START (8)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_EN_pcie1_firewall_mainslv_sec_flag_set_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie0_firewall_mainslv_sec_flag_clr : 8;
        unsigned int pcie1_firewall_mainslv_sec_flag_clr : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_DIS_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_DIS_pcie0_firewall_mainslv_sec_flag_clr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_DIS_pcie0_firewall_mainslv_sec_flag_clr_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_DIS_pcie1_firewall_mainslv_sec_flag_clr_START (8)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_DIS_pcie1_firewall_mainslv_sec_flag_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie0_firewall_mainslv_sec_flag : 8;
        unsigned int pcie1_firewall_mainslv_sec_flag : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_STA_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_STA_pcie0_firewall_mainslv_sec_flag_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_STA_pcie0_firewall_mainslv_sec_flag_END (7)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_STA_pcie1_firewall_mainslv_sec_flag_START (8)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP2_LOCK_STA_pcie1_firewall_mainslv_sec_flag_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_hsdt0_ioc_set : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_EN_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_EN_tz_secure_n_hsdt0_ioc_set_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_EN_tz_secure_n_hsdt0_ioc_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_hsdt0_ioc_clr : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_DIS_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_DIS_tz_secure_n_hsdt0_ioc_clr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_DIS_tz_secure_n_hsdt0_ioc_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_hsdt0_ioc : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_STA_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_STA_tz_secure_n_hsdt0_ioc_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP3_LOCK_STA_tz_secure_n_hsdt0_ioc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_firewall_tzpc_pcie1_slv_31_0_set : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_EN_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_EN_qic_firewall_tzpc_pcie1_slv_31_0_set_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_EN_qic_firewall_tzpc_pcie1_slv_31_0_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_firewall_tzpc_pcie1_slv_31_0_clr : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_DIS_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_DIS_qic_firewall_tzpc_pcie1_slv_31_0_clr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_DIS_qic_firewall_tzpc_pcie1_slv_31_0_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_firewall_tzpc_pcie1_slv_31_0 : 32;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_STA_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_STA_qic_firewall_tzpc_pcie1_slv_31_0_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP4_LOCK_STA_qic_firewall_tzpc_pcie1_slv_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_firewall_tzpc_pcie1_slv_61_32_set : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_EN_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_EN_qic_firewall_tzpc_pcie1_slv_61_32_set_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_EN_qic_firewall_tzpc_pcie1_slv_61_32_set_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_firewall_tzpc_pcie1_slv_61_32_clr : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_DIS_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_DIS_qic_firewall_tzpc_pcie1_slv_61_32_clr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_DIS_qic_firewall_tzpc_pcie1_slv_61_32_clr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_firewall_tzpc_pcie1_slv_61_32 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_STA_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_STA_qic_firewall_tzpc_pcie1_slv_61_32_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP5_LOCK_STA_qic_firewall_tzpc_pcie1_slv_61_32_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_intr_par_iomcu_set : 1;
        unsigned int tz_secure_n_intr_par_asp_set : 1;
        unsigned int tz_secure_n_intr_par_acpu_tee_set : 1;
        unsigned int tz_secure_n_intr_par_acpu_ree_set : 1;
        unsigned int tz_secure_n_intr_par_isp_set : 1;
        unsigned int tz_secure_n_intr_par_modem_set : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_iomcu_set_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_iomcu_set_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_asp_set_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_asp_set_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_acpu_tee_set_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_acpu_tee_set_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_acpu_ree_set_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_acpu_ree_set_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_isp_set_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_isp_set_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_modem_set_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_EN_tz_secure_n_intr_par_modem_set_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_intr_par_iomcu_clr : 1;
        unsigned int tz_secure_n_intr_par_asp_clr : 1;
        unsigned int tz_secure_n_intr_par_acpu_tee_clr : 1;
        unsigned int tz_secure_n_intr_par_acpu_ree_clr : 1;
        unsigned int tz_secure_n_intr_par_isp_clr : 1;
        unsigned int tz_secure_n_intr_par_modem_clr : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_iomcu_clr_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_iomcu_clr_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_asp_clr_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_asp_clr_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_acpu_tee_clr_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_acpu_tee_clr_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_acpu_ree_clr_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_acpu_ree_clr_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_isp_clr_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_isp_clr_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_modem_clr_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_DIS_tz_secure_n_intr_par_modem_clr_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_intr_par_iomcu : 1;
        unsigned int tz_secure_n_intr_par_asp : 1;
        unsigned int tz_secure_n_intr_par_acpu_tee : 1;
        unsigned int tz_secure_n_intr_par_acpu_ree : 1;
        unsigned int tz_secure_n_intr_par_isp : 1;
        unsigned int tz_secure_n_intr_par_modem : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_iomcu_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_iomcu_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_asp_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_asp_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_acpu_tee_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_acpu_tee_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_acpu_ree_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_acpu_ree_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_isp_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_isp_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_modem_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_GRP6_LOCK_STA_tz_secure_n_intr_par_modem_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lock : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_TZPC_LOCK_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_LOCK_lock_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_TZPC_LOCK_lock_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en_tb_mspe_tee : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_qic_timeout_en_tb_mspe_tee_UNION;
#endif
#define SOC_HSDT0_XCTRL_qic_timeout_en_tb_mspe_tee_qic_timeout_en_tb_mspe_tee_START (0)
#define SOC_HSDT0_XCTRL_qic_timeout_en_tb_mspe_tee_qic_timeout_en_tb_mspe_tee_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_eps_tee_syspdc_pwrd_req : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_TEE_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_TEE_pdc_eps_tee_syspdc_pwrd_req_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_REQ_TEE_pdc_eps_tee_syspdc_pwrd_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_eps_tee_syspdc_pwrd_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_TEE_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_TEE_pdc_eps_tee_syspdc_pwrd_ack_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_TEE_pdc_eps_tee_syspdc_pwrd_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_qic_tee : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_XCTRL_MEM_CTRL_QIC_TEE_UNION;
#endif
#define SOC_HSDT0_XCTRL_MEM_CTRL_QIC_TEE_mem_ctrl_qic_tee_START (0)
#define SOC_HSDT0_XCTRL_MEM_CTRL_QIC_TEE_mem_ctrl_qic_tee_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl2hieps_ctrl : 32;
    } reg;
} SOC_HSDT0_XCTRL_pctrl2hieps_ctrl_UNION;
#endif
#define SOC_HSDT0_XCTRL_pctrl2hieps_ctrl_pctrl2hieps_ctrl_START (0)
#define SOC_HSDT0_XCTRL_pctrl2hieps_ctrl_pctrl2hieps_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiesp2pctrl_state_l : 32;
    } reg;
} SOC_HSDT0_XCTRL_hiesp2pctrl_state_l_UNION;
#endif
#define SOC_HSDT0_XCTRL_hiesp2pctrl_state_l_hiesp2pctrl_state_l_START (0)
#define SOC_HSDT0_XCTRL_hiesp2pctrl_state_l_hiesp2pctrl_state_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiesp2pctrl_state_h : 32;
    } reg;
} SOC_HSDT0_XCTRL_hiesp2pctrl_state_h_UNION;
#endif
#define SOC_HSDT0_XCTRL_hiesp2pctrl_state_h_hiesp2pctrl_state_h_START (0)
#define SOC_HSDT0_XCTRL_hiesp2pctrl_state_h_hiesp2pctrl_state_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_qic_nopending_rt_fw_eps_tee_rsp : 1;
        unsigned int sc_qic_nopending_rt_fw_eps_tee_req : 1;
        unsigned int sc_qic_nopending_rt_eps_tee_rsp : 1;
        unsigned int sc_qic_nopending_rt_eps_tee_req : 1;
        unsigned int sc_qic_nopending_wr_ib_eps_tee : 1;
        unsigned int sc_qic_nopending_rd_ib_eps_tee : 1;
        unsigned int sc_qic_nopending_tb_eps_tee : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_rt_fw_eps_tee_rsp_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_rt_fw_eps_tee_rsp_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_rt_fw_eps_tee_req_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_rt_fw_eps_tee_req_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_rt_eps_tee_rsp_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_rt_eps_tee_rsp_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_rt_eps_tee_req_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_rt_eps_tee_req_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_wr_ib_eps_tee_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_wr_ib_eps_tee_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_rd_ib_eps_tee_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_rd_ib_eps_tee_END (5)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_tb_eps_tee_START (6)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_NOPENDING_0_sc_qic_nopending_tb_eps_tee_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_nopending_rt_fw_eps_tee_rsp : 1;
        unsigned int wc_qic_nopending_rt_fw_eps_tee_req : 1;
        unsigned int wc_qic_nopending_rt_eps_tee_rsp : 1;
        unsigned int wc_qic_nopending_rt_eps_tee_req : 1;
        unsigned int wc_qic_nopending_wr_ib_eps_tee : 1;
        unsigned int wc_qic_nopending_rd_ib_eps_tee : 1;
        unsigned int wc_qic_nopending_tb_eps_tee : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_rt_fw_eps_tee_rsp_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_rt_fw_eps_tee_rsp_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_rt_fw_eps_tee_req_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_rt_fw_eps_tee_req_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_rt_eps_tee_rsp_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_rt_eps_tee_rsp_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_rt_eps_tee_req_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_rt_eps_tee_req_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_wr_ib_eps_tee_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_wr_ib_eps_tee_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_rd_ib_eps_tee_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_rd_ib_eps_tee_END (5)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_tb_eps_tee_START (6)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_NOPENDING_0_wc_qic_nopending_tb_eps_tee_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_qic_nopending_pds_qcp_tee : 1;
        unsigned int sc_qic_nopending_pds_eps_tee_mst : 1;
        unsigned int sc_qic_nopending_pds_eps_tee_cfg : 1;
        unsigned int sc_qic_nopending_pdm_qcp_tee : 1;
        unsigned int sc_qic_nopending_pdm_eps_tee_mst : 1;
        unsigned int sc_qic_nopending_pdm_eps_tee_cfg : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pds_qcp_tee_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pds_qcp_tee_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pds_eps_tee_mst_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pds_eps_tee_mst_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pds_eps_tee_cfg_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pds_eps_tee_cfg_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pdm_qcp_tee_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pdm_qcp_tee_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pdm_eps_tee_mst_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pdm_eps_tee_mst_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pdm_eps_tee_cfg_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_NOPENDING_PDMS_0_sc_qic_nopending_pdm_eps_tee_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_nopending_pds_qcp_tee : 1;
        unsigned int wc_qic_nopending_pds_eps_tee_mst : 1;
        unsigned int wc_qic_nopending_pds_eps_tee_cfg : 1;
        unsigned int wc_qic_nopending_pdm_qcp_tee : 1;
        unsigned int wc_qic_nopending_pdm_eps_tee_mst : 1;
        unsigned int wc_qic_nopending_pdm_eps_tee_cfg : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pds_qcp_tee_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pds_qcp_tee_END (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pds_eps_tee_mst_START (1)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pds_eps_tee_mst_END (1)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pds_eps_tee_cfg_START (2)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pds_eps_tee_cfg_END (2)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pdm_qcp_tee_START (3)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pdm_qcp_tee_END (3)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pdm_eps_tee_mst_START (4)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pdm_eps_tee_mst_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pdm_eps_tee_cfg_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_NOPENDING_PDMS_0_wc_qic_nopending_pdm_eps_tee_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_qic_pdm_state_pdm_qcp_tee : 5;
        unsigned int sc_qic_pdm_state_pdm_qcp_tee_mst : 5;
        unsigned int sc_qic_pdm_state_pdm_qcp_tee_cfg : 5;
        unsigned int sc_qic_pds_state_pds_qcp_tee : 3;
        unsigned int sc_qic_pds_state_pds_qcp_tee_mst : 3;
        unsigned int sc_qic_pds_state_pds_qcp_tee_cfg : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pdm_state_pdm_qcp_tee_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pdm_state_pdm_qcp_tee_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pdm_state_pdm_qcp_tee_mst_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pdm_state_pdm_qcp_tee_mst_END (9)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pdm_state_pdm_qcp_tee_cfg_START (10)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pdm_state_pdm_qcp_tee_cfg_END (14)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pds_state_pds_qcp_tee_START (15)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pds_state_pds_qcp_tee_END (17)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pds_state_pds_qcp_tee_mst_START (18)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pds_state_pds_qcp_tee_mst_END (20)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pds_state_pds_qcp_tee_cfg_START (21)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_PDMS_STATE_0_sc_qic_pds_state_pds_qcp_tee_cfg_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_qcp_tee : 5;
        unsigned int wc_qic_pdm_state_pdm_qcp_tee_mst : 5;
        unsigned int wc_qic_pdm_state_pdm_qcp_tee_cfg : 5;
        unsigned int wc_qic_pds_state_pds_qcp_tee : 3;
        unsigned int wc_qic_pds_state_pds_qcp_tee_mst : 3;
        unsigned int wc_qic_pds_state_pds_qcp_tee_cfg : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pdm_state_pdm_qcp_tee_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pdm_state_pdm_qcp_tee_END (4)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pdm_state_pdm_qcp_tee_mst_START (5)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pdm_state_pdm_qcp_tee_mst_END (9)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pdm_state_pdm_qcp_tee_cfg_START (10)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pdm_state_pdm_qcp_tee_cfg_END (14)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pds_state_pds_qcp_tee_START (15)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pds_state_pds_qcp_tee_END (17)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pds_state_pds_qcp_tee_mst_START (18)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pds_state_pds_qcp_tee_mst_END (20)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pds_state_pds_qcp_tee_cfg_START (21)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_PDMS_STATE_0_wc_qic_pds_state_pds_qcp_tee_cfg_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_qic_timeout_st_tb_eps_tee : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_TIMEOUT_ST_TB_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_TIMEOUT_ST_TB_0_sc_qic_timeout_st_tb_eps_tee_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_QIC_EPS_TEE_TIMEOUT_ST_TB_0_sc_qic_timeout_st_tb_eps_tee_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_timeout_st_tb_eps_tee : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_TIMEOUT_ST_TB_0_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_TIMEOUT_ST_TB_0_wc_qic_timeout_st_tb_eps_tee_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_TIMEOUT_ST_TB_0_wc_qic_timeout_st_tb_eps_tee_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_sc_pdc_eps_tee_syspdc_pwrd_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_SYSPDC_REQ_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_SYSPDC_REQ_wc_sc_pdc_eps_tee_syspdc_pwrd_req_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_SYSPDC_REQ_wc_sc_pdc_eps_tee_syspdc_pwrd_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_pdc_eps_tee_syspdc_pwrd_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_SC_QIC_EPS_TEE_SYSPDC_ACK_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_SC_QIC_EPS_TEE_SYSPDC_ACK_sc_pdc_eps_tee_syspdc_pwrd_ack_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_SC_QIC_EPS_TEE_SYSPDC_ACK_sc_pdc_eps_tee_syspdc_pwrd_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_sc_pdc_eps_tee_syspdc_pwrd_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_SYSPDC_ACK_UNION;
#endif
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_SYSPDC_ACK_wc_sc_pdc_eps_tee_syspdc_pwrd_ack_START (0)
#define SOC_HSDT0_XCTRL_HSDT0_WC_QIC_EPS_TEE_SYSPDC_ACK_wc_sc_pdc_eps_tee_syspdc_pwrd_ack_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
