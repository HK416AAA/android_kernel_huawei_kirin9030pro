#ifndef __SOC_QIC_FW_CTRL_INTERFACE_H__
#define __SOC_QIC_FW_CTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
enum tb_number {
        TB_0,
        TB_1,
        TB_2,
        TB_3,
        TB_4,
        TB_5,
        TB_6,
        TB_7,
};
#define SOC_TB_FW_CTRL_BASE_ADDR(fw_base,tb_num) ((fw_base) + 0x400UL * (tb_num))
#define TB_CFGBUS_QCP_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_0)
#define TB_DDRXPU_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_1)
#define TB_DMAC_CFG_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_2)
#define TB_FW_SYS_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_3)
#define TB_LPMCU_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_4)
#define TB_MEDIAXPU_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_5)
#define TB_SYS_PERI0_CFG_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_6)
#define TB_SYS_PERI1_CFG_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_7)
#define TB_SYS_PERI3_CFG_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_0)
#define IB_MDM2SYS_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_0)
#define IB_MDMPERI2SYS_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_1)
#define TB_CROSSBAR_QCP_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_2)
#define TB_FFTS_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_3)
#define TB_FW_CROSSBAR_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_4)
#define TB_HTS_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_5)
#define TB_SDCU_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_6)
#define TB_SYS2ACPU_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_7)
#define TB_SYS2GPU_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_0)
#define TB_SYS2MDMPERI_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_1)
#define TB_SYS2MDM_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_2)
#define TB_SYS2NPU_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_3)
#define TB_SYS2SC_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_4)
#define IB_MDM2SYS_1_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_5)
#define IB_MDMPERI2SYS_1_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_6)
#define TB_DFA_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_0)
#define TB_EPS_REE_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_1)
#define TB_EPS_TEE_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_2)
#define TB_HSDT0_FW_APB_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_3)
#define TB_HSDT0_APB_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_4)
#define TB_HSDT0_QCP_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_5)
#define TB_PCIE0_SLV0_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_6)
#define TB_PCIE0_SLV1_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_7)
#define TB_FW_HSDT1_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_0)
#define TB_HSDT1BUS_QCP_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_1)
#define TB_H1_AHB_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_2)
#define TB_H1_APB_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_3)
#define TB_AO2ASP_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_0)
#define TB_AO_APB_SLV_F_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_1)
#define TB_AO_APB_SLV_B_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_2)
#define TB_FW_AO_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_3)
#define TB_HIPHY_IO_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_4)
#define TB_MAD_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_5)
#define TB_QCP_AOBUS_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_6)
#define TB_QSPI_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_7)
#define TB_FW_IOMCU_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_0)
#define TB_IOMCU_AHB_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_1)
#define TB_IOMCU_APBH_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_2)
#define TB_IOMCU_APBL_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_3)
#define TB_IOMCU_HTS_MSG_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_4)
#define TB_QCP_IOMCUBUS_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_5)
#define TB_FW_MSPC_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_0)
#define TB_MSPC_SLV_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_1)
#define TB_QCP_MSPCBUS_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_2)
#define TB_FW_MEDIA1_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_0)
#define TB_M1_CFG_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_1)
#define TB_QCP_M1_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_2)
#define TB_VDEC_VENC_TCU_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_3)
#define TB_AAE_DSS_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_4)
#define TB_SYS2ISP_CFG_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_0)
#define TB_CFG_M2_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_1)
#define TB_QCP_M2_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_2)
#define TB_FW_MEDIA2_BASE_ADDR(base) SOC_TB_FW_CTRL_BASE_ADDR(base, TB_3)
#define TB0_FW_CTRL0_ADDR(base) (base)
#define TB0_FW_CTRL1_ADDR(base) ((base) + 0x4)
#define TB0_FW_COMMON_MID_ADDR(base,mid_reg_num) ((base) + 0x20 + 0x4 * (mid_reg_num))
#define TB0_FW_REGION_START_ADDR(base,region_num) ((base) + 0x40 + 0x8 * (region_num))
#define TB0_FW_REGION_END_ADDR(base,region_num) ((base) + 0x44 + 0x8 * (region_num))
#define TB0_FW_REGION_MID_ADDR(base,region_num,mid_reg_num) \
        ((base) + 0x100 + 0x20 * (region_num) + 0x4 * (mid_reg_num))
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
