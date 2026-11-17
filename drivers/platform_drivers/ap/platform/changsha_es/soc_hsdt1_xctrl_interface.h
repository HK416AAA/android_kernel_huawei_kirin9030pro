#ifndef __SOC_HSDT1_XCTRL_INTERFACE_H__
#define __SOC_HSDT1_XCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_0_ADDR(base) (base)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_PDMS_ADDR(base) ((base) + 0x004UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_RD_ADDR(base) ((base) + 0x008UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_WR_ADDR(base) ((base) + 0x00CUL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_RT_ADDR(base) ((base) + 0x010UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_TB_ADDR(base) ((base) + 0x014UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_DFX_BUSY_0_ADDR(base) ((base) + 0x018UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_INTR_EM_ADDR(base) ((base) + 0x020UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_INTR_PROBE_ADDR(base) ((base) + 0x024UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_TIMEOUT_ST_ADDR(base) ((base) + 0x028UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDM_STATE_0_ADDR(base) ((base) + 0x02CUL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDM_STATE_1_ADDR(base) ((base) + 0x030UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDS_STATE_0_ADDR(base) ((base) + 0x034UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_REQ_ADDR(base) ((base) + 0x038UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_ACK_ADDR(base) ((base) + 0x03CUL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_0_ADDR(base) ((base) + 0x100UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_PDMS_ADDR(base) ((base) + 0x104UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_RD_ADDR(base) ((base) + 0x108UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_WR_ADDR(base) ((base) + 0x10CUL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_RT_ADDR(base) ((base) + 0x110UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_TB_ADDR(base) ((base) + 0x114UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_DFX_BUSY_0_ADDR(base) ((base) + 0x118UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_INTR_EM_ADDR(base) ((base) + 0x120UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_INTR_PROBE_ADDR(base) ((base) + 0x124UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_TIMEOUT_ST_ADDR(base) ((base) + 0x128UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDM_STATE_0_ADDR(base) ((base) + 0x12CUL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDM_STATE_1_ADDR(base) ((base) + 0x130UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDS_STATE_0_ADDR(base) ((base) + 0x134UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_REQ_ADDR(base) ((base) + 0x138UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_ACK_ADDR(base) ((base) + 0x13CUL)
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_IB_QSP_SYS2H1_ADDR(base) ((base) + 0x200)
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_TB_QSP_H12SYS_ADDR(base) ((base) + 0x204UL)
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_TB_ADDR(base) ((base) + 0x208UL)
#define SOC_HSDT1_XCTRL_nopending_mask_ADDR(base) ((base) + 0x230UL)
#define SOC_HSDT1_XCTRL_busy_mask_ADDR(base) ((base) + 0x234UL)
#define SOC_HSDT1_XCTRL_idlereq_mask_ADDR(base) ((base) + 0x238UL)
#define SOC_HSDT1_XCTRL_idleack_mask_ADDR(base) ((base) + 0x23CUL)
#define SOC_HSDT1_XCTRL_intr_qic_mask_ADDR(base) ((base) + 0x240UL)
#define SOC_HSDT1_XCTRL_nopending_lpcm_mask_ADDR(base) ((base) + 0x244UL)
#define SOC_HSDT1_XCTRL_nopending_mux_sel_ADDR(base) ((base) + 0x260UL)
#define SOC_HSDT1_XCTRL_busy_mux_sel_ADDR(base) ((base) + 0x264UL)
#define SOC_HSDT1_XCTRL_idle_req_mux_sel1_ADDR(base) ((base) + 0x268UL)
#define SOC_HSDT1_XCTRL_idleack_mux_sel1_ADDR(base) ((base) + 0x26CUL)
#define SOC_HSDT1_XCTRL_intr_qic_mux_sel_ADDR(base) ((base) + 0x270UL)
#define SOC_HSDT1_XCTRL_nopending_lpcm_mux_sel_ADDR(base) ((base) + 0x274UL)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp0_ADDR(base) ((base) + 0x300UL)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp1_ADDR(base) ((base) + 0x304UL)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp2_ADDR(base) ((base) + 0x308UL)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp3_ADDR(base) ((base) + 0x30CUL)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp4_ADDR(base) ((base) + 0x310UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_REQ_CTRL_ADDR(base) ((base) + 0x314UL)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_ACK_CTRL_ADDR(base) ((base) + 0x318UL)
#define SOC_HSDT1_XCTRL_HSDT1_TP_SEL_ADDR(base) ((base) + 0x400UL)
#define SOC_HSDT1_XCTRL_HSDT1_HIMINIBUS_CKG_EN_ADDR(base) ((base) + 0x404UL)
#define SOC_HSDT1_XCTRL_hsdt1_himinibus_dlock_and_dbg_clr_ADDR(base) ((base) + 0x410UL)
#define SOC_HSDT1_XCTRL_HSDT1_HIMINIBUS_IDLE_ADDR(base) ((base) + 0x420UL)
#define SOC_HSDT1_XCTRL_HSDT1_MEM_CTRL_0_ADDR(base) ((base) + 0x424UL)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_DEVICE_ADDR(base) ((base) + 0x430UL)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_DEVICE_ADDR(base) ((base) + 0x434UL)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_DDR_ADDR(base) ((base) + 0x438UL)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_DDR_ADDR(base) ((base) + 0x43CUL)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_ADDR(base) ((base) + 0x440UL)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_ADDR(base) ((base) + 0x444UL)
#define SOC_HSDT1_XCTRL_hsdt1_qic_soft_lock_dis_ADDR(base) ((base) + 0x800UL)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_ARVCIDX_DEVICE_ADDR(base) ((base) + 0x810UL)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_AWVCIDX_DEVICE_ADDR(base) ((base) + 0x814UL)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_ARVCIDX_DDR_ADDR(base) ((base) + 0x818UL)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_AWVCIDX_DDR_ADDR(base) ((base) + 0x81CUL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_ADDR(base) ((base) + 0xC00UL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_ADDR(base) ((base) + 0xC04UL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_ADDR(base) ((base) + 0xC08UL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_EN_ADDR(base) ((base) + 0xC0CUL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_DIS_ADDR(base) ((base) + 0xC10UL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_STA_ADDR(base) ((base) + 0xC14UL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_ADDR(base) ((base) + 0xC18UL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_ADDR(base) ((base) + 0xC1CUL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_ADDR(base) ((base) + 0xC20UL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_ADDR(base) ((base) + 0xC24UL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_ADDR(base) ((base) + 0xC28UL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_ADDR(base) ((base) + 0xC2CUL)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_LOCK_ADDR(base) ((base) + 0xD00UL)
#else
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_0_ADDR(base) (base)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_PDMS_ADDR(base) ((base) + 0x004)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_RD_ADDR(base) ((base) + 0x008)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_WR_ADDR(base) ((base) + 0x00C)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_RT_ADDR(base) ((base) + 0x010)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_TB_ADDR(base) ((base) + 0x014)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_DFX_BUSY_0_ADDR(base) ((base) + 0x018)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_INTR_EM_ADDR(base) ((base) + 0x020)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_INTR_PROBE_ADDR(base) ((base) + 0x024)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_TIMEOUT_ST_ADDR(base) ((base) + 0x028)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDM_STATE_0_ADDR(base) ((base) + 0x02C)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDM_STATE_1_ADDR(base) ((base) + 0x030)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDS_STATE_0_ADDR(base) ((base) + 0x034)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_REQ_ADDR(base) ((base) + 0x038)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_ACK_ADDR(base) ((base) + 0x03C)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_0_ADDR(base) ((base) + 0x100)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_PDMS_ADDR(base) ((base) + 0x104)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_RD_ADDR(base) ((base) + 0x108)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_WR_ADDR(base) ((base) + 0x10C)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_RT_ADDR(base) ((base) + 0x110)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_TB_ADDR(base) ((base) + 0x114)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_DFX_BUSY_0_ADDR(base) ((base) + 0x118)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_INTR_EM_ADDR(base) ((base) + 0x120)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_INTR_PROBE_ADDR(base) ((base) + 0x124)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_TIMEOUT_ST_ADDR(base) ((base) + 0x128)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDM_STATE_0_ADDR(base) ((base) + 0x12C)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDM_STATE_1_ADDR(base) ((base) + 0x130)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDS_STATE_0_ADDR(base) ((base) + 0x134)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_REQ_ADDR(base) ((base) + 0x138)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_ACK_ADDR(base) ((base) + 0x13C)
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_IB_QSP_SYS2H1_ADDR(base) ((base) + 0x200)
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_TB_QSP_H12SYS_ADDR(base) ((base) + 0x204)
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_TB_ADDR(base) ((base) + 0x208)
#define SOC_HSDT1_XCTRL_nopending_mask_ADDR(base) ((base) + 0x230)
#define SOC_HSDT1_XCTRL_busy_mask_ADDR(base) ((base) + 0x234)
#define SOC_HSDT1_XCTRL_idlereq_mask_ADDR(base) ((base) + 0x238)
#define SOC_HSDT1_XCTRL_idleack_mask_ADDR(base) ((base) + 0x23C)
#define SOC_HSDT1_XCTRL_intr_qic_mask_ADDR(base) ((base) + 0x240)
#define SOC_HSDT1_XCTRL_nopending_lpcm_mask_ADDR(base) ((base) + 0x244)
#define SOC_HSDT1_XCTRL_nopending_mux_sel_ADDR(base) ((base) + 0x260)
#define SOC_HSDT1_XCTRL_busy_mux_sel_ADDR(base) ((base) + 0x264)
#define SOC_HSDT1_XCTRL_idle_req_mux_sel1_ADDR(base) ((base) + 0x268)
#define SOC_HSDT1_XCTRL_idleack_mux_sel1_ADDR(base) ((base) + 0x26C)
#define SOC_HSDT1_XCTRL_intr_qic_mux_sel_ADDR(base) ((base) + 0x270)
#define SOC_HSDT1_XCTRL_nopending_lpcm_mux_sel_ADDR(base) ((base) + 0x274)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp0_ADDR(base) ((base) + 0x300)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp1_ADDR(base) ((base) + 0x304)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp2_ADDR(base) ((base) + 0x308)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp3_ADDR(base) ((base) + 0x30C)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp4_ADDR(base) ((base) + 0x310)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_REQ_CTRL_ADDR(base) ((base) + 0x314)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_ACK_CTRL_ADDR(base) ((base) + 0x318)
#define SOC_HSDT1_XCTRL_HSDT1_TP_SEL_ADDR(base) ((base) + 0x400)
#define SOC_HSDT1_XCTRL_HSDT1_HIMINIBUS_CKG_EN_ADDR(base) ((base) + 0x404)
#define SOC_HSDT1_XCTRL_hsdt1_himinibus_dlock_and_dbg_clr_ADDR(base) ((base) + 0x410)
#define SOC_HSDT1_XCTRL_HSDT1_HIMINIBUS_IDLE_ADDR(base) ((base) + 0x420)
#define SOC_HSDT1_XCTRL_HSDT1_MEM_CTRL_0_ADDR(base) ((base) + 0x424)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_DEVICE_ADDR(base) ((base) + 0x430)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_DEVICE_ADDR(base) ((base) + 0x434)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_DDR_ADDR(base) ((base) + 0x438)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_DDR_ADDR(base) ((base) + 0x43C)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_ADDR(base) ((base) + 0x440)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_ADDR(base) ((base) + 0x444)
#define SOC_HSDT1_XCTRL_hsdt1_qic_soft_lock_dis_ADDR(base) ((base) + 0x800)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_ARVCIDX_DEVICE_ADDR(base) ((base) + 0x810)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_AWVCIDX_DEVICE_ADDR(base) ((base) + 0x814)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_ARVCIDX_DDR_ADDR(base) ((base) + 0x818)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_AWVCIDX_DDR_ADDR(base) ((base) + 0x81C)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_ADDR(base) ((base) + 0xC00)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_ADDR(base) ((base) + 0xC04)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_ADDR(base) ((base) + 0xC08)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_EN_ADDR(base) ((base) + 0xC0C)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_DIS_ADDR(base) ((base) + 0xC10)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_STA_ADDR(base) ((base) + 0xC14)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_ADDR(base) ((base) + 0xC18)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_ADDR(base) ((base) + 0xC1C)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_ADDR(base) ((base) + 0xC20)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_ADDR(base) ((base) + 0xC24)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_ADDR(base) ((base) + 0xC28)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_ADDR(base) ((base) + 0xC2C)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_LOCK_ADDR(base) ((base) + 0xD00)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt1bus_qic_nopending_combo : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_0_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_0_hsdt1bus_qic_nopending_combo_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_0_hsdt1bus_qic_nopending_combo_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdms_nopending_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_PDMS_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_PDMS_qic_pdms_nopending_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_PDMS_qic_pdms_nopending_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rd_nopending_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_RD_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_RD_qic_rd_nopending_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_RD_qic_rd_nopending_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_wr_nopending_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_WR_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_WR_qic_wr_nopending_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_WR_qic_wr_nopending_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rt_nopending_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_RT_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_RT_qic_rt_nopending_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_RT_qic_rt_nopending_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_tb_nopending_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_TB_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_TB_qic_tb_nopending_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_NOPENDING_TB_qic_tb_nopending_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_busy_ca_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_DFX_BUSY_0_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_DFX_BUSY_0_dfx_busy_ca_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_DFX_BUSY_0_dfx_busy_ca_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_em_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_INTR_EM_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_INTR_EM_intr_em_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_INTR_EM_intr_em_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_qic_probe_hsdt1bus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_INTR_PROBE_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_INTR_PROBE_intr_qic_probe_hsdt1bus_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_INTR_PROBE_intr_qic_probe_hsdt1bus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_TIMEOUT_ST_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_TIMEOUT_ST_qic_timeout_st_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_TIMEOUT_ST_qic_timeout_st_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_PDM_STATE_0_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDM_STATE_0_qic_pdm_state_pdm_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDM_STATE_0_qic_pdm_state_pdm_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_hsdt1bus_1 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_PDM_STATE_1_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDM_STATE_1_qic_pdm_state_pdm_hsdt1bus_1_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDM_STATE_1_qic_pdm_state_pdm_hsdt1bus_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pds_state_pdm_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_PDS_STATE_0_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDS_STATE_0_qic_pds_state_pdm_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDS_STATE_0_qic_pds_state_pdm_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdc_h1bus_syspdc_pwrd_req : 1;
        unsigned int qic_pdc_usb3_syspdc_pwrd_req : 1;
        unsigned int qic_pdc_ufs_hci_syspdc_pwrd_req : 1;
        unsigned int qic_pdc_ufs_trace_syspdc_pwrd_req : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_REQ_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_REQ_qic_pdc_h1bus_syspdc_pwrd_req_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_REQ_qic_pdc_h1bus_syspdc_pwrd_req_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_REQ_qic_pdc_usb3_syspdc_pwrd_req_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_REQ_qic_pdc_usb3_syspdc_pwrd_req_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_REQ_qic_pdc_ufs_hci_syspdc_pwrd_req_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_REQ_qic_pdc_ufs_hci_syspdc_pwrd_req_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_REQ_qic_pdc_ufs_trace_syspdc_pwrd_req_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_REQ_qic_pdc_ufs_trace_syspdc_pwrd_req_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdc_h1bus_syspdc_pwrd_ack : 1;
        unsigned int qic_pdc_usb3_syspdc_pwrd_ack : 1;
        unsigned int qic_pdc_ufs_hci_syspdc_pwrd_ack : 1;
        unsigned int qic_pdc_ufs_trace_syspdc_pwrd_ack : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_ACK_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_ACK_qic_pdc_h1bus_syspdc_pwrd_ack_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_ACK_qic_pdc_h1bus_syspdc_pwrd_ack_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_ACK_qic_pdc_usb3_syspdc_pwrd_ack_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_ACK_qic_pdc_usb3_syspdc_pwrd_ack_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_ACK_qic_pdc_ufs_hci_syspdc_pwrd_ack_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_ACK_qic_pdc_ufs_hci_syspdc_pwrd_ack_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_ACK_qic_pdc_ufs_trace_syspdc_pwrd_ack_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_SYSPDC_PWRD_ACK_qic_pdc_ufs_trace_syspdc_pwrd_ack_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_hsdt1bus_qic_nopending_combo : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_0_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_0_wc_hsdt1bus_qic_nopending_combo_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_0_wc_hsdt1bus_qic_nopending_combo_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdms_nopending_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_PDMS_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_PDMS_wc_qic_pdms_nopending_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_PDMS_wc_qic_pdms_nopending_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rd_nopending_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_RD_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_RD_wc_qic_rd_nopending_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_RD_wc_qic_rd_nopending_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_wr_nopending_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_WR_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_WR_wc_qic_wr_nopending_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_WR_wc_qic_wr_nopending_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rt_nopending_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_RT_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_RT_wc_qic_rt_nopending_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_RT_wc_qic_rt_nopending_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_tb_nopending_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_TB_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_TB_wc_qic_tb_nopending_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_NOPENDING_TB_wc_qic_tb_nopending_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_dfx_busy_ca_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_DFX_BUSY_0_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_DFX_BUSY_0_wc_dfx_busy_ca_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_DFX_BUSY_0_wc_dfx_busy_ca_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_em_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_INTR_EM_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_INTR_EM_wc_intr_em_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_INTR_EM_wc_intr_em_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_qic_probe_hsdt1bus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_INTR_PROBE_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_INTR_PROBE_wc_intr_qic_probe_hsdt1bus_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_INTR_PROBE_wc_intr_qic_probe_hsdt1bus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_timeout_st_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_TIMEOUT_ST_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_TIMEOUT_ST_wc_qic_timeout_st_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_TIMEOUT_ST_wc_qic_timeout_st_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDM_STATE_0_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDM_STATE_0_wc_qic_pdm_state_pdm_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDM_STATE_0_wc_qic_pdm_state_pdm_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_hsdt1bus_1 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDM_STATE_1_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDM_STATE_1_wc_qic_pdm_state_pdm_hsdt1bus_1_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDM_STATE_1_wc_qic_pdm_state_pdm_hsdt1bus_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pds_state_pdm_hsdt1bus_0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDS_STATE_0_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDS_STATE_0_wc_qic_pds_state_pdm_hsdt1bus_0_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_PDS_STATE_0_wc_qic_pds_state_pdm_hsdt1bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdc_h1bus_syspdc_pwrd_req : 1;
        unsigned int wc_qic_pdc_usb3_syspdc_pwrd_req : 1;
        unsigned int wc_qic_pdc_ufs_hci_syspdc_pwrd_req : 1;
        unsigned int wc_qic_pdc_ufs_trace_syspdc_pwrd_req : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_REQ_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_REQ_wc_qic_pdc_h1bus_syspdc_pwrd_req_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_REQ_wc_qic_pdc_h1bus_syspdc_pwrd_req_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_REQ_wc_qic_pdc_usb3_syspdc_pwrd_req_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_REQ_wc_qic_pdc_usb3_syspdc_pwrd_req_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_REQ_wc_qic_pdc_ufs_hci_syspdc_pwrd_req_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_REQ_wc_qic_pdc_ufs_hci_syspdc_pwrd_req_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_REQ_wc_qic_pdc_ufs_trace_syspdc_pwrd_req_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_REQ_wc_qic_pdc_ufs_trace_syspdc_pwrd_req_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdc_h1bus_syspdc_pwrd_ack : 1;
        unsigned int wc_qic_pdc_usb3_syspdc_pwrd_ack : 1;
        unsigned int wc_qic_pdc_ufs_hci_syspdc_pwrd_ack : 1;
        unsigned int wc_qic_pdc_ufs_trace_syspdc_pwrd_ack : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_ACK_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_ACK_wc_qic_pdc_h1bus_syspdc_pwrd_ack_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_ACK_wc_qic_pdc_h1bus_syspdc_pwrd_ack_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_ACK_wc_qic_pdc_usb3_syspdc_pwrd_ack_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_ACK_wc_qic_pdc_usb3_syspdc_pwrd_ack_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_ACK_wc_qic_pdc_ufs_hci_syspdc_pwrd_ack_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_ACK_wc_qic_pdc_ufs_hci_syspdc_pwrd_ack_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_ACK_wc_qic_pdc_ufs_trace_syspdc_pwrd_ack_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_WC_SYSPDC_PWRD_ACK_wc_qic_pdc_ufs_trace_syspdc_pwrd_ack_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en_ib_qsp_sys2h1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_IB_QSP_SYS2H1_UNION;
#endif
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_IB_QSP_SYS2H1_qic_timeout_en_ib_qsp_sys2h1_START (0)
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_IB_QSP_SYS2H1_qic_timeout_en_ib_qsp_sys2h1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en_tb_qsp_h12sys : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_TB_QSP_H12SYS_UNION;
#endif
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_TB_QSP_H12SYS_qic_timeout_en_tb_qsp_h12sys_START (0)
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_TB_QSP_H12SYS_qic_timeout_en_tb_qsp_h12sys_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en_tb_h1bus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_TB_UNION;
#endif
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_TB_qic_timeout_en_tb_h1bus_START (0)
#define SOC_HSDT1_XCTRL_QIC_TIMEOUT_EN_TB_qic_timeout_en_tb_h1bus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_mask : 32;
    } reg;
} SOC_HSDT1_XCTRL_nopending_mask_UNION;
#endif
#define SOC_HSDT1_XCTRL_nopending_mask_nopending_mask_START (0)
#define SOC_HSDT1_XCTRL_nopending_mask_nopending_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int busy_mask : 32;
    } reg;
} SOC_HSDT1_XCTRL_busy_mask_UNION;
#endif
#define SOC_HSDT1_XCTRL_busy_mask_busy_mask_START (0)
#define SOC_HSDT1_XCTRL_busy_mask_busy_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idlereq_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_XCTRL_idlereq_mask_UNION;
#endif
#define SOC_HSDT1_XCTRL_idlereq_mask_idlereq_mask_START (0)
#define SOC_HSDT1_XCTRL_idlereq_mask_idlereq_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idleack_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_XCTRL_idleack_mask_UNION;
#endif
#define SOC_HSDT1_XCTRL_idleack_mask_idleack_mask_START (0)
#define SOC_HSDT1_XCTRL_idleack_mask_idleack_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_qic_mask : 32;
    } reg;
} SOC_HSDT1_XCTRL_intr_qic_mask_UNION;
#endif
#define SOC_HSDT1_XCTRL_intr_qic_mask_intr_qic_mask_START (0)
#define SOC_HSDT1_XCTRL_intr_qic_mask_intr_qic_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_lpcm_mask : 32;
    } reg;
} SOC_HSDT1_XCTRL_nopending_lpcm_mask_UNION;
#endif
#define SOC_HSDT1_XCTRL_nopending_lpcm_mask_nopending_lpcm_mask_START (0)
#define SOC_HSDT1_XCTRL_nopending_lpcm_mask_nopending_lpcm_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_mux_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_XCTRL_nopending_mux_sel_UNION;
#endif
#define SOC_HSDT1_XCTRL_nopending_mux_sel_nopending_mux_sel_START (0)
#define SOC_HSDT1_XCTRL_nopending_mux_sel_nopending_mux_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int busy_mux_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_XCTRL_busy_mux_sel_UNION;
#endif
#define SOC_HSDT1_XCTRL_busy_mux_sel_busy_mux_sel_START (0)
#define SOC_HSDT1_XCTRL_busy_mux_sel_busy_mux_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idle_req_mux_sel1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_XCTRL_idle_req_mux_sel1_UNION;
#endif
#define SOC_HSDT1_XCTRL_idle_req_mux_sel1_idle_req_mux_sel1_START (0)
#define SOC_HSDT1_XCTRL_idle_req_mux_sel1_idle_req_mux_sel1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idleack_mux_sel1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_XCTRL_idleack_mux_sel1_UNION;
#endif
#define SOC_HSDT1_XCTRL_idleack_mux_sel1_idleack_mux_sel1_START (0)
#define SOC_HSDT1_XCTRL_idleack_mux_sel1_idleack_mux_sel1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_qic_mux_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_XCTRL_intr_qic_mux_sel_UNION;
#endif
#define SOC_HSDT1_XCTRL_intr_qic_mux_sel_intr_qic_mux_sel_START (0)
#define SOC_HSDT1_XCTRL_intr_qic_mux_sel_intr_qic_mux_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_lpcm_mux_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_XCTRL_nopending_lpcm_mux_sel_UNION;
#endif
#define SOC_HSDT1_XCTRL_nopending_lpcm_mux_sel_nopending_lpcm_mux_sel_START (0)
#define SOC_HSDT1_XCTRL_nopending_lpcm_mux_sel_nopending_lpcm_mux_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hsdt1_hiahb_top_grp0 : 32;
    } reg;
} SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp0_UNION;
#endif
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp0_dbg_hsdt1_hiahb_top_grp0_START (0)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp0_dbg_hsdt1_hiahb_top_grp0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hsdt1_hiahb_top_grp1 : 32;
    } reg;
} SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp1_UNION;
#endif
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp1_dbg_hsdt1_hiahb_top_grp1_START (0)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp1_dbg_hsdt1_hiahb_top_grp1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hsdt1_hiahb_top_grp2 : 32;
    } reg;
} SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp2_UNION;
#endif
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp2_dbg_hsdt1_hiahb_top_grp2_START (0)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp2_dbg_hsdt1_hiahb_top_grp2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hsdt1_hiahb_top_grp3 : 32;
    } reg;
} SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp3_UNION;
#endif
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp3_dbg_hsdt1_hiahb_top_grp3_START (0)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp3_dbg_hsdt1_hiahb_top_grp3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hsdt1_hiahb_top_grp4 : 32;
    } reg;
} SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp4_UNION;
#endif
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp4_dbg_hsdt1_hiahb_top_grp4_START (0)
#define SOC_HSDT1_XCTRL_dbg_hsdt1_hiahb_dcdr_grp4_dbg_hsdt1_hiahb_top_grp4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_h1bus_syspdc_pwrd_req : 1;
        unsigned int pdc_usb3_syspdc_pwrd_req : 1;
        unsigned int pdc_ufs_hci_syspdc_pwrd_req : 1;
        unsigned int pdc_ufs_trace_syspdc_pwrd_req : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_REQ_CTRL_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_REQ_CTRL_pdc_h1bus_syspdc_pwrd_req_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_REQ_CTRL_pdc_h1bus_syspdc_pwrd_req_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_REQ_CTRL_pdc_usb3_syspdc_pwrd_req_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_REQ_CTRL_pdc_usb3_syspdc_pwrd_req_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_REQ_CTRL_pdc_ufs_hci_syspdc_pwrd_req_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_REQ_CTRL_pdc_ufs_hci_syspdc_pwrd_req_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_REQ_CTRL_pdc_ufs_trace_syspdc_pwrd_req_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_REQ_CTRL_pdc_ufs_trace_syspdc_pwrd_req_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_h1bus_syspdc_pwrd_ack : 1;
        unsigned int pdc_usb3_syspdc_pwrd_ack : 1;
        unsigned int pdc_ufs_hci_syspdc_pwrd_ack : 1;
        unsigned int pdc_ufs_trace_syspdc_pwrd_ack : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_ACK_CTRL_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_ACK_CTRL_pdc_h1bus_syspdc_pwrd_ack_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_ACK_CTRL_pdc_h1bus_syspdc_pwrd_ack_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_ACK_CTRL_pdc_usb3_syspdc_pwrd_ack_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_ACK_CTRL_pdc_usb3_syspdc_pwrd_ack_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_ACK_CTRL_pdc_ufs_hci_syspdc_pwrd_ack_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_ACK_CTRL_pdc_ufs_hci_syspdc_pwrd_ack_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_ACK_CTRL_pdc_ufs_trace_syspdc_pwrd_ack_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_QIC_PDC_ACK_CTRL_pdc_ufs_trace_syspdc_pwrd_ack_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt1_tp_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TP_SEL_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TP_SEL_hsdt1_tp_sel_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TP_SEL_hsdt1_tp_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt1_himinibus_ckg_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_HIMINIBUS_CKG_EN_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_HIMINIBUS_CKG_EN_hsdt1_himinibus_ckg_en_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_HIMINIBUS_CKG_EN_hsdt1_himinibus_ckg_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt1_himinibus_dlock_and_dbg_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_XCTRL_hsdt1_himinibus_dlock_and_dbg_clr_UNION;
#endif
#define SOC_HSDT1_XCTRL_hsdt1_himinibus_dlock_and_dbg_clr_hsdt1_himinibus_dlock_and_dbg_clr_START (0)
#define SOC_HSDT1_XCTRL_hsdt1_himinibus_dlock_and_dbg_clr_hsdt1_himinibus_dlock_and_dbg_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt1_himinibus_idle : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_HIMINIBUS_IDLE_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_HIMINIBUS_IDLE_hsdt1_himinibus_idle_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_HIMINIBUS_IDLE_hsdt1_himinibus_idle_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_MEM_CTRL_0_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_MEM_CTRL_0_mem_ctrl_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_MEM_CTRL_0_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_ufs_hci_icfg_arvcidx_device : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_DEVICE_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_DEVICE_ib_ufs_hci_icfg_arvcidx_device_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_DEVICE_ib_ufs_hci_icfg_arvcidx_device_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_ufs_hci_icfg_awvcidx_device : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_DEVICE_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_DEVICE_ib_ufs_hci_icfg_awvcidx_device_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_DEVICE_ib_ufs_hci_icfg_awvcidx_device_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_ufs_hci_icfg_arvcidx_ddr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_DDR_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_DDR_ib_ufs_hci_icfg_arvcidx_ddr_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_DDR_ib_ufs_hci_icfg_arvcidx_ddr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_ufs_hci_icfg_awvcidx_ddr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_DDR_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_DDR_ib_ufs_hci_icfg_awvcidx_ddr_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_DDR_ib_ufs_hci_icfg_awvcidx_ddr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_ufs_hci_arvcidx : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_ib_ufs_hci_arvcidx_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_ARVCIDX_ib_ufs_hci_arvcidx_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_ufs_hci_awvcidx : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_ib_ufs_hci_awvcidx_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_IB_UFS_HCI_AWVCIDX_ib_ufs_hci_awvcidx_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt1_qic_soft_lock_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_XCTRL_hsdt1_qic_soft_lock_dis_UNION;
#endif
#define SOC_HSDT1_XCTRL_hsdt1_qic_soft_lock_dis_hsdt1_qic_soft_lock_dis_START (0)
#define SOC_HSDT1_XCTRL_hsdt1_qic_soft_lock_dis_hsdt1_qic_soft_lock_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_usb3_icfg_arvcidx_device : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_IB_USB3_ARVCIDX_DEVICE_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_ARVCIDX_DEVICE_ib_usb3_icfg_arvcidx_device_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_ARVCIDX_DEVICE_ib_usb3_icfg_arvcidx_device_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_usb3_icfg_awvcidx_device : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_IB_USB3_AWVCIDX_DEVICE_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_AWVCIDX_DEVICE_ib_usb3_icfg_awvcidx_device_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_AWVCIDX_DEVICE_ib_usb3_icfg_awvcidx_device_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_usb3_icfg_arvcidx_ddr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_IB_USB3_ARVCIDX_DDR_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_ARVCIDX_DDR_ib_usb3_icfg_arvcidx_ddr_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_ARVCIDX_DDR_ib_usb3_icfg_arvcidx_ddr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_usb3_icfg_awvcidx_ddr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_IB_USB3_AWVCIDX_DDR_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_AWVCIDX_DDR_ib_usb3_icfg_awvcidx_ddr_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_IB_USB3_AWVCIDX_DDR_ib_usb3_icfg_awvcidx_ddr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_sd_set : 1;
        unsigned int tz_secure_n_h1bus_qcp_set : 1;
        unsigned int tz_secure_n_hidptx_set : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int tz_secure_n_hsdt1_crg_s_set : 1;
        unsigned int tz_secure_n_hsdt1_crg_ns_set : 1;
        unsigned int tz_secure_n_hsdt1_sctrl_s_set : 1;
        unsigned int tz_secure_n_hsdt1_sctrl_ns_set : 1;
        unsigned int tz_secure_n_sd_xsecure_n_set : 1;
        unsigned int tz_secure_n_hsdt1_xctrl_s_set : 1;
        unsigned int tz_secure_n_hsdt1_xctrl_ns_set : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int tz_secure_n_sd_dfx_tzpc_set : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 10;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_sd_set_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_sd_set_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_h1bus_qcp_set_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_h1bus_qcp_set_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hidptx_set_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hidptx_set_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_crg_s_set_START (10)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_crg_s_set_END (10)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_crg_ns_set_START (11)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_crg_ns_set_END (11)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_sctrl_s_set_START (12)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_sctrl_s_set_END (12)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_sctrl_ns_set_START (13)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_sctrl_ns_set_END (13)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_sd_xsecure_n_set_START (14)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_sd_xsecure_n_set_END (14)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_xctrl_s_set_START (15)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_xctrl_s_set_END (15)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_xctrl_ns_set_START (16)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_hsdt1_xctrl_ns_set_END (16)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_sd_dfx_tzpc_set_START (20)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_EN_tz_secure_n_sd_dfx_tzpc_set_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_sd_clr : 1;
        unsigned int tz_secure_n_h1bus_clr : 1;
        unsigned int tz_secure_n_hidptx_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int tz_secure_n_hsdt1_crg_s_clr : 1;
        unsigned int tz_secure_n_hsdt1_crg_ns_clr : 1;
        unsigned int tz_secure_n_hsdt1_sctrl_s_clr : 1;
        unsigned int tz_secure_n_hsdt1_sctrl_ns_clr : 1;
        unsigned int tz_secure_n_sd_xsecure_n_clr : 1;
        unsigned int tz_secure_n_hsdt1_xctrl_s_clr : 1;
        unsigned int tz_secure_n_hsdt1_xctrl_ns_clr : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int tz_secure_n_sd_dfx_tzpc_clr : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 10;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_sd_clr_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_sd_clr_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_h1bus_clr_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_h1bus_clr_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hidptx_clr_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hidptx_clr_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_crg_s_clr_START (10)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_crg_s_clr_END (10)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_crg_ns_clr_START (11)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_crg_ns_clr_END (11)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_sctrl_s_clr_START (12)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_sctrl_s_clr_END (12)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_sctrl_ns_clr_START (13)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_sctrl_ns_clr_END (13)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_sd_xsecure_n_clr_START (14)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_sd_xsecure_n_clr_END (14)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_xctrl_s_clr_START (15)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_xctrl_s_clr_END (15)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_xctrl_ns_clr_START (16)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_hsdt1_xctrl_ns_clr_END (16)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_sd_dfx_tzpc_clr_START (20)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_DIS_tz_secure_n_sd_dfx_tzpc_clr_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_sd : 1;
        unsigned int tz_secure_n_h1bus : 1;
        unsigned int tz_secure_n_hidptx : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int tz_secure_n_hsdt1_crg_s : 1;
        unsigned int tz_secure_n_hsdt1_crg_ns : 1;
        unsigned int tz_secure_n_hsdt1_sctrl_s : 1;
        unsigned int tz_secure_n_hsdt1_sctrl_ns : 1;
        unsigned int tz_secure_n_sd_xsecure_n : 1;
        unsigned int tz_secure_n_hsdt1_xctrl_s : 1;
        unsigned int tz_secure_n_hsdt1_xctrl_ns : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int tz_secure_n_sd_dfx_tzpc : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 10;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_sd_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_sd_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_h1bus_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_h1bus_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hidptx_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hidptx_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_crg_s_START (10)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_crg_s_END (10)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_crg_ns_START (11)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_crg_ns_END (11)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_sctrl_s_START (12)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_sctrl_s_END (12)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_sctrl_ns_START (13)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_sctrl_ns_END (13)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_sd_xsecure_n_START (14)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_sd_xsecure_n_END (14)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_xctrl_s_START (15)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_xctrl_s_END (15)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_xctrl_ns_START (16)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_hsdt1_xctrl_ns_END (16)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_sd_dfx_tzpc_START (20)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP0_LOCK_STA_tz_secure_n_sd_dfx_tzpc_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_hsdt1_ioc_set : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_EN_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_EN_tz_secure_n_hsdt1_ioc_set_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_EN_tz_secure_n_hsdt1_ioc_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_hsdt1_ioc_clr : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_DIS_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_DIS_tz_secure_n_hsdt1_ioc_clr_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_DIS_tz_secure_n_hsdt1_ioc_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_hsdt1_ioc : 32;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_STA_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_STA_tz_secure_n_hsdt1_ioc_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP1_LOCK_STA_tz_secure_n_hsdt1_ioc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ufs_sctrl_set : 1;
        unsigned int tz_secure_n_ufs_trace_set : 1;
        unsigned int tz_secure_n_ufs_ufshc_set : 1;
        unsigned int tz_secure_n_ufs_uipro_set : 1;
        unsigned int tz_secure_n_ufs_xsecure_n_set : 1;
        unsigned int tz_secure_n_ufs_trace_xsecure_n_set : 1;
        unsigned int tz_secure_n_ufs_mhpy_set : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_sctrl_set_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_sctrl_set_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_trace_set_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_trace_set_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_ufshc_set_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_ufshc_set_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_uipro_set_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_uipro_set_END (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_xsecure_n_set_START (4)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_xsecure_n_set_END (4)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_trace_xsecure_n_set_START (5)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_trace_xsecure_n_set_END (5)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_mhpy_set_START (6)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_EN_tz_secure_n_ufs_mhpy_set_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ufs_sctrl_clr : 1;
        unsigned int tz_secure_n_ufs_trace_clr : 1;
        unsigned int tz_secure_n_ufs_ufshc_clr : 1;
        unsigned int tz_secure_n_ufs_uipro_clr : 1;
        unsigned int tz_secure_n_ufs_xsecure_n_clr : 1;
        unsigned int tz_secure_n_ufs_trace_xsecure_n_clr : 1;
        unsigned int tz_secure_n_ufs_mhpy_clr : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_sctrl_clr_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_sctrl_clr_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_trace_clr_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_trace_clr_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_ufshc_clr_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_ufshc_clr_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_uipro_clr_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_uipro_clr_END (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_xsecure_n_clr_START (4)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_xsecure_n_clr_END (4)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_trace_xsecure_n_clr_START (5)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_trace_xsecure_n_clr_END (5)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_mhpy_clr_START (6)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_DIS_tz_secure_n_ufs_mhpy_clr_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ufs_sctrl : 1;
        unsigned int tz_secure_n_ufs_trace : 1;
        unsigned int tz_secure_n_ufs_ufshc : 1;
        unsigned int tz_secure_n_ufs_uipro : 1;
        unsigned int tz_secure_n_ufs_xsecure_n : 1;
        unsigned int tz_secure_n_ufs_trace_xsecure_n : 1;
        unsigned int tz_secure_n_ufs_mhpy : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_sctrl_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_sctrl_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_trace_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_trace_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_ufshc_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_ufshc_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_uipro_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_uipro_END (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_xsecure_n_START (4)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_xsecure_n_END (4)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_trace_xsecure_n_START (5)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_trace_xsecure_n_END (5)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_mhpy_START (6)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP2_LOCK_STA_tz_secure_n_ufs_mhpy_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_combophy_set : 1;
        unsigned int tz_secure_n_hiusb20phy_set : 1;
        unsigned int tz_secure_n_usb_ctrl_set : 1;
        unsigned int tz_secure_n_usb_sctrl_set : 1;
        unsigned int tz_secure_n_usb_xsecure_n_set : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_tz_secure_n_combophy_set_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_tz_secure_n_combophy_set_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_tz_secure_n_hiusb20phy_set_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_tz_secure_n_hiusb20phy_set_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_tz_secure_n_usb_ctrl_set_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_tz_secure_n_usb_ctrl_set_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_tz_secure_n_usb_sctrl_set_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_tz_secure_n_usb_sctrl_set_END (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_tz_secure_n_usb_xsecure_n_set_START (4)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_EN_tz_secure_n_usb_xsecure_n_set_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_combophy_clr : 1;
        unsigned int tz_secure_n_hiusb20phy_clr : 1;
        unsigned int tz_secure_n_usb_ctrl_clr : 1;
        unsigned int tz_secure_n_usb_sctrl_clr : 1;
        unsigned int tz_secure_n_usb_xsecure_n_clr : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_tz_secure_n_combophy_clr_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_tz_secure_n_combophy_clr_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_tz_secure_n_hiusb20phy_clr_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_tz_secure_n_hiusb20phy_clr_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_tz_secure_n_usb_ctrl_clr_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_tz_secure_n_usb_ctrl_clr_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_tz_secure_n_usb_sctrl_clr_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_tz_secure_n_usb_sctrl_clr_END (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_tz_secure_n_usb_xsecure_n_clr_START (4)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_DIS_tz_secure_n_usb_xsecure_n_clr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_combophy : 1;
        unsigned int tz_secure_n_hiusb20phy : 1;
        unsigned int tz_secure_n_usb_ctrl : 1;
        unsigned int tz_secure_n_usb_sctrl : 1;
        unsigned int tz_secure_n_usb_xsecure_n : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_tz_secure_n_combophy_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_tz_secure_n_combophy_END (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_tz_secure_n_hiusb20phy_START (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_tz_secure_n_hiusb20phy_END (1)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_tz_secure_n_usb_ctrl_START (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_tz_secure_n_usb_ctrl_END (2)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_tz_secure_n_usb_sctrl_START (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_tz_secure_n_usb_sctrl_END (3)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_tz_secure_n_usb_xsecure_n_START (4)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_GRP3_LOCK_STA_tz_secure_n_usb_xsecure_n_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT1_XCTRL_HSDT1_TZPC_LOCK_UNION;
#endif
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_LOCK_lock_START (0)
#define SOC_HSDT1_XCTRL_HSDT1_TZPC_LOCK_lock_END (3)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
