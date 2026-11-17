#ifndef __SOC_SMMUv3_TCU_INTERFACE_H__
#define __SOC_SMMUv3_TCU_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUv3_TCU_SMMU_IDR0_ADDR(base) ((base) + (0x0000UL))
#define SOC_SMMUv3_TCU_SMMU_IDR1_ADDR(base) ((base) + (0x0004UL))
#define SOC_SMMUv3_TCU_SMMU_IDR2_ADDR(base) ((base) + (0x0008UL))
#define SOC_SMMUv3_TCU_SMMU_IDR3_ADDR(base) ((base) + (0x000CUL))
#define SOC_SMMUv3_TCU_SMMU_IDR4_ADDR(base) ((base) + (0x0010UL))
#define SOC_SMMUv3_TCU_SMMU_IDR5_ADDR(base) ((base) + (0x0014UL))
#define SOC_SMMUv3_TCU_SMMU_IIDR_ADDR(base) ((base) + (0x0018UL))
#define SOC_SMMUv3_TCU_SMMU_AIDR_ADDR(base) ((base) + (0x001CUL))
#define SOC_SMMUv3_TCU_SMMU_CR0_ADDR(base) ((base) + (0x0020UL))
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_ADDR(base) ((base) + (0x0024UL))
#define SOC_SMMUv3_TCU_SMMU_CR1_ADDR(base) ((base) + (0x0028UL))
#define SOC_SMMUv3_TCU_SMMU_CR2_ADDR(base) ((base) + (0x002CUL))
#define SOC_SMMUv3_TCU_SMMU_STATUSR_ADDR(base) ((base) + (0x0040UL))
#define SOC_SMMUv3_TCU_SMMU_GBPA_ADDR(base) ((base) + (0x0044UL))
#define SOC_SMMUv3_TCU_SMMU_AGBPA_ADDR(base) ((base) + (0x0048UL))
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRL_ADDR(base) ((base) + (0x0050UL))
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRLACK_ADDR(base) ((base) + (0x0054UL))
#define SOC_SMMUv3_TCU_SMMU_GERROR_ADDR(base) ((base) + (0x0060UL))
#define SOC_SMMUv3_TCU_SMMU_GERRORN_ADDR(base) ((base) + (0x0064UL))
#define SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG0_0_ADDR(base) ((base) + (0x0068UL))
#define SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG0_1_ADDR(base) ((base) + (0x006CUL))
#define SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG1_ADDR(base) ((base) + (0x0070UL))
#define SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG2_ADDR(base) ((base) + (0x0074UL))
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE0_ADDR(base) ((base) + (0x0080UL))
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE1_ADDR(base) ((base) + (0x0084UL))
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE_CFG_ADDR(base) ((base) + (0x0088UL))
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE0_ADDR(base) ((base) + (0x0090UL))
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE1_ADDR(base) ((base) + (0x0094UL))
#define SOC_SMMUv3_TCU_SMMU_CMDQ_PROD_ADDR(base) ((base) + (0x0098UL))
#define SOC_SMMUv3_TCU_SMMU_CMDQ_CONS_ADDR(base) ((base) + (0x009CUL))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE0_ADDR(base) ((base) + (0x00A0UL))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE1_ADDR(base) ((base) + (0x00A4UL))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_PROD_ADDR(base) ((base) + (0x100A8UL))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_CONS_ADDR(base) ((base) + (0x100ACUL))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x00B0UL))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x00B4UL))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG1_ADDR(base) ((base) + (0x00B8UL))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG2_ADDR(base) ((base) + (0x00BCUL))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_BASE0_ADDR(base) ((base) + (0x00C0UL))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_BASE1_ADDR(base) ((base) + (0x00C4UL))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_PROD_ADDR(base) ((base) + (0x100C8UL))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_CONS_ADDR(base) ((base) + (0x100CCUL))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x00D0UL))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x00D4UL))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG1_ADDR(base) ((base) + (0x00D8UL))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG2_ADDR(base) ((base) + (0x00DCUL))
#define SOC_SMMUv3_TCU_SMMU_MPAMIDR_ADDR(base) ((base) + (0x0130UL))
#define SOC_SMMUv3_TCU_SMMU_GMPAM_ADDR(base) ((base) + (0x0138UL))
#define SOC_SMMUv3_TCU_SMMU_GBPMPAM_ADDR(base) ((base) + (0x013CUL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVCNTR_ADDR(base,i) ((base) + (0x22000+(i)*4UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER0_ADDR(base) ((base) + (0x2400UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER_ADDR(base,t) ((base) + (0x2404+(t)*4UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_SVR_ADDR(base,i) ((base) + (0x22600+(i)*4UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_SMR_ADDR(base,j) ((base) + (0x2A00+(j)*4UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENSET0_0_ADDR(base) ((base) + (0x2C00UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENSET0_1_ADDR(base) ((base) + (0x2C04UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENCLR0_0_ADDR(base) ((base) + (0x2C20UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENCLR0_1_ADDR(base) ((base) + (0x2C24UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENSET0_0_ADDR(base) ((base) + (0x2C40UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENSET0_1_ADDR(base) ((base) + (0x2C44UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENCLR0_0_ADDR(base) ((base) + (0x2C60UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENCLR0_1_ADDR(base) ((base) + (0x2C64UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSCLR0_0_ADDR(base) ((base) + (0x22C80UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSCLR0_1_ADDR(base) ((base) + (0x22C84UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSSET0_0_ADDR(base) ((base) + (0x22CC0UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSSET0_1_ADDR(base) ((base) + (0x22CC4UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CAPR_ADDR(base) ((base) + (0x22D88UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_SCR_ADDR(base) ((base) + (0x2DF8UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_ADDR(base) ((base) + (0x2E00UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CR_ADDR(base) ((base) + (0x2E04UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID0_0_ADDR(base) ((base) + (0x2E20UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID0_1_ADDR(base) ((base) + (0x2E24UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID1_0_ADDR(base) ((base) + (0x2E28UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID1_1_ADDR(base) ((base) + (0x2E2CUL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CTRL_ADDR(base) ((base) + (0x2E50UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CTRLACK_ADDR(base) ((base) + (0x2E54UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG0_0_ADDR(base) ((base) + (0x2E58UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG0_1_ADDR(base) ((base) + (0x2E5CUL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG1_ADDR(base) ((base) + (0x2E60UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG2_ADDR(base) ((base) + (0x2E64UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_STATUS_ADDR(base) ((base) + (0x2E68UL))
#define SOC_SMMUv3_TCU_SMMU_PMCG_AIDR_ADDR(base) ((base) + (0x2E70UL))
#define SOC_SMMUv3_TCU_SMMU_S_IDR0_ADDR(base) ((base) + (0x8000UL))
#define SOC_SMMUv3_TCU_SMMU_S_IDR1_ADDR(base) ((base) + (0x8004UL))
#define SOC_SMMUv3_TCU_SMMU_S_IDR2_ADDR(base) ((base) + (0x8008UL))
#define SOC_SMMUv3_TCU_SMMU_S_IDR3_ADDR(base) ((base) + (0x800CUL))
#define SOC_SMMUv3_TCU_SMMU_S_IDR4_ADDR(base) ((base) + (0x8010UL))
#define SOC_SMMUv3_TCU_SMMU_S_CR0_ADDR(base) ((base) + (0x8020UL))
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_ADDR(base) ((base) + (0x8024UL))
#define SOC_SMMUv3_TCU_SMMU_S_CR1_ADDR(base) ((base) + (0x8028UL))
#define SOC_SMMUv3_TCU_SMMU_S_CR2_ADDR(base) ((base) + (0x802CUL))
#define SOC_SMMUv3_TCU_SMMU_S_INIT_ADDR(base) ((base) + (0x803CUL))
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_ADDR(base) ((base) + (0x8044UL))
#define SOC_SMMUv3_TCU_SMMU_S_AGBPA_ADDR(base) ((base) + (0x8048UL))
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRL_ADDR(base) ((base) + (0x8050UL))
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRLACK_ADDR(base) ((base) + (0x8054UL))
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_ADDR(base) ((base) + (0x8060UL))
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_ADDR(base) ((base) + (0x8064UL))
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG0_0_ADDR(base) ((base) + (0x8068UL))
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG0_1_ADDR(base) ((base) + (0x806CUL))
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG1_ADDR(base) ((base) + (0x8070UL))
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG2_ADDR(base) ((base) + (0x8074UL))
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE0_ADDR(base) ((base) + (0x8080UL))
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE1_ADDR(base) ((base) + (0x8084UL))
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE_CFG_ADDR(base) ((base) + (0x8088UL))
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE0_ADDR(base) ((base) + (0x8090UL))
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE1_ADDR(base) ((base) + (0x8094UL))
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_PROD_ADDR(base) ((base) + (0x8098UL))
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_CONS_ADDR(base) ((base) + (0x809CUL))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE0_ADDR(base) ((base) + (0x80A0UL))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE1_ADDR(base) ((base) + (0x80A4UL))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_PROD_ADDR(base) ((base) + (0x80A8UL))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_CONS_ADDR(base) ((base) + (0x80ACUL))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x80B0UL))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x80B4UL))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG1_ADDR(base) ((base) + (0x80B8UL))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG2_ADDR(base) ((base) + (0x80BCUL))
#define SOC_SMMUv3_TCU_SMMU_S_MPAMIDR_ADDR(base) ((base) + (0x8130UL))
#define SOC_SMMUv3_TCU_SMMU_S_GMPAM_ADDR(base) ((base) + (0x8138UL))
#define SOC_SMMUv3_TCU_SMMU_S_GBPMPAM_ADDR(base) ((base) + (0x813CUL))
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_ADDR(base) ((base) + (0x8E00UL))
#define SOC_SMMUv3_TCU_SMMU_QOS_ADDR(base) ((base) + (0x8E04UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_TRANS_ADDR(base) ((base) + (0x8E08UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_ALLOC_ADDR(base) ((base) + (0x8E10UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_SCR_ADDR(base) ((base) + (0x8E18UL))
#define SOC_SMMUv3_TCU_SMMU_RAS_ERRFR_ADDR(base) ((base) + (0x8E80UL))
#define SOC_SMMUv3_TCU_SMMU_RAS_ERRCTRL_ADDR(base) ((base) + (0x8E88UL))
#define SOC_SMMUv3_TCU_SMMU_RAS_ERRSTATUS_ADDR(base) ((base) + (0x8E90UL))
#define SOC_SMMUv3_TCU_SMMU_RAS_ERRGEN_ADDR(base) ((base) + (0x8EC0UL))
#define SOC_SMMUv3_TCU_SMMU_MST_CTRL_ADDR(base,n) ((base) + (0x9000+(n)*4UL))
#define SOC_SMMUv3_TCU_SMMU_MST_LINK_ADDR(base,n) ((base) + (0x9400+(n)*4UL))
#define SOC_SMMUv3_TCU_SMMU_TTW_CACHE_CTRL_ADDR(base) ((base) + (0x9804UL))
#else
#define SOC_SMMUv3_TCU_SMMU_IDR0_ADDR(base) ((base) + (0x0000))
#define SOC_SMMUv3_TCU_SMMU_IDR1_ADDR(base) ((base) + (0x0004))
#define SOC_SMMUv3_TCU_SMMU_IDR2_ADDR(base) ((base) + (0x0008))
#define SOC_SMMUv3_TCU_SMMU_IDR3_ADDR(base) ((base) + (0x000C))
#define SOC_SMMUv3_TCU_SMMU_IDR4_ADDR(base) ((base) + (0x0010))
#define SOC_SMMUv3_TCU_SMMU_IDR5_ADDR(base) ((base) + (0x0014))
#define SOC_SMMUv3_TCU_SMMU_IIDR_ADDR(base) ((base) + (0x0018))
#define SOC_SMMUv3_TCU_SMMU_AIDR_ADDR(base) ((base) + (0x001C))
#define SOC_SMMUv3_TCU_SMMU_CR0_ADDR(base) ((base) + (0x0020))
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_ADDR(base) ((base) + (0x0024))
#define SOC_SMMUv3_TCU_SMMU_CR1_ADDR(base) ((base) + (0x0028))
#define SOC_SMMUv3_TCU_SMMU_CR2_ADDR(base) ((base) + (0x002C))
#define SOC_SMMUv3_TCU_SMMU_STATUSR_ADDR(base) ((base) + (0x0040))
#define SOC_SMMUv3_TCU_SMMU_GBPA_ADDR(base) ((base) + (0x0044))
#define SOC_SMMUv3_TCU_SMMU_AGBPA_ADDR(base) ((base) + (0x0048))
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRL_ADDR(base) ((base) + (0x0050))
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRLACK_ADDR(base) ((base) + (0x0054))
#define SOC_SMMUv3_TCU_SMMU_GERROR_ADDR(base) ((base) + (0x0060))
#define SOC_SMMUv3_TCU_SMMU_GERRORN_ADDR(base) ((base) + (0x0064))
#define SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG0_0_ADDR(base) ((base) + (0x0068))
#define SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG0_1_ADDR(base) ((base) + (0x006C))
#define SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG1_ADDR(base) ((base) + (0x0070))
#define SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG2_ADDR(base) ((base) + (0x0074))
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE0_ADDR(base) ((base) + (0x0080))
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE1_ADDR(base) ((base) + (0x0084))
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE_CFG_ADDR(base) ((base) + (0x0088))
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE0_ADDR(base) ((base) + (0x0090))
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE1_ADDR(base) ((base) + (0x0094))
#define SOC_SMMUv3_TCU_SMMU_CMDQ_PROD_ADDR(base) ((base) + (0x0098))
#define SOC_SMMUv3_TCU_SMMU_CMDQ_CONS_ADDR(base) ((base) + (0x009C))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE0_ADDR(base) ((base) + (0x00A0))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE1_ADDR(base) ((base) + (0x00A4))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_PROD_ADDR(base) ((base) + (0x100A8))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_CONS_ADDR(base) ((base) + (0x100AC))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x00B0))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x00B4))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG1_ADDR(base) ((base) + (0x00B8))
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG2_ADDR(base) ((base) + (0x00BC))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_BASE0_ADDR(base) ((base) + (0x00C0))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_BASE1_ADDR(base) ((base) + (0x00C4))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_PROD_ADDR(base) ((base) + (0x100C8))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_CONS_ADDR(base) ((base) + (0x100CC))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x00D0))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x00D4))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG1_ADDR(base) ((base) + (0x00D8))
#define SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG2_ADDR(base) ((base) + (0x00DC))
#define SOC_SMMUv3_TCU_SMMU_MPAMIDR_ADDR(base) ((base) + (0x0130))
#define SOC_SMMUv3_TCU_SMMU_GMPAM_ADDR(base) ((base) + (0x0138))
#define SOC_SMMUv3_TCU_SMMU_GBPMPAM_ADDR(base) ((base) + (0x013C))
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVCNTR_ADDR(base,i) ((base) + (0x22000+(i)*4))
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER0_ADDR(base) ((base) + (0x2400))
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER_ADDR(base,t) ((base) + (0x2404+(t)*4))
#define SOC_SMMUv3_TCU_SMMU_PMCG_SVR_ADDR(base,i) ((base) + (0x22600+(i)*4))
#define SOC_SMMUv3_TCU_SMMU_PMCG_SMR_ADDR(base,j) ((base) + (0x2A00+(j)*4))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENSET0_0_ADDR(base) ((base) + (0x2C00))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENSET0_1_ADDR(base) ((base) + (0x2C04))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENCLR0_0_ADDR(base) ((base) + (0x2C20))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENCLR0_1_ADDR(base) ((base) + (0x2C24))
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENSET0_0_ADDR(base) ((base) + (0x2C40))
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENSET0_1_ADDR(base) ((base) + (0x2C44))
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENCLR0_0_ADDR(base) ((base) + (0x2C60))
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENCLR0_1_ADDR(base) ((base) + (0x2C64))
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSCLR0_0_ADDR(base) ((base) + (0x22C80))
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSCLR0_1_ADDR(base) ((base) + (0x22C84))
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSSET0_0_ADDR(base) ((base) + (0x22CC0))
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSSET0_1_ADDR(base) ((base) + (0x22CC4))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CAPR_ADDR(base) ((base) + (0x22D88))
#define SOC_SMMUv3_TCU_SMMU_PMCG_SCR_ADDR(base) ((base) + (0x2DF8))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_ADDR(base) ((base) + (0x2E00))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CR_ADDR(base) ((base) + (0x2E04))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID0_0_ADDR(base) ((base) + (0x2E20))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID0_1_ADDR(base) ((base) + (0x2E24))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID1_0_ADDR(base) ((base) + (0x2E28))
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID1_1_ADDR(base) ((base) + (0x2E2C))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CTRL_ADDR(base) ((base) + (0x2E50))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CTRLACK_ADDR(base) ((base) + (0x2E54))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG0_0_ADDR(base) ((base) + (0x2E58))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG0_1_ADDR(base) ((base) + (0x2E5C))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG1_ADDR(base) ((base) + (0x2E60))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG2_ADDR(base) ((base) + (0x2E64))
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_STATUS_ADDR(base) ((base) + (0x2E68))
#define SOC_SMMUv3_TCU_SMMU_PMCG_AIDR_ADDR(base) ((base) + (0x2E70))
#define SOC_SMMUv3_TCU_SMMU_S_IDR0_ADDR(base) ((base) + (0x8000))
#define SOC_SMMUv3_TCU_SMMU_S_IDR1_ADDR(base) ((base) + (0x8004))
#define SOC_SMMUv3_TCU_SMMU_S_IDR2_ADDR(base) ((base) + (0x8008))
#define SOC_SMMUv3_TCU_SMMU_S_IDR3_ADDR(base) ((base) + (0x800C))
#define SOC_SMMUv3_TCU_SMMU_S_IDR4_ADDR(base) ((base) + (0x8010))
#define SOC_SMMUv3_TCU_SMMU_S_CR0_ADDR(base) ((base) + (0x8020))
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_ADDR(base) ((base) + (0x8024))
#define SOC_SMMUv3_TCU_SMMU_S_CR1_ADDR(base) ((base) + (0x8028))
#define SOC_SMMUv3_TCU_SMMU_S_CR2_ADDR(base) ((base) + (0x802C))
#define SOC_SMMUv3_TCU_SMMU_S_INIT_ADDR(base) ((base) + (0x803C))
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_ADDR(base) ((base) + (0x8044))
#define SOC_SMMUv3_TCU_SMMU_S_AGBPA_ADDR(base) ((base) + (0x8048))
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRL_ADDR(base) ((base) + (0x8050))
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRLACK_ADDR(base) ((base) + (0x8054))
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_ADDR(base) ((base) + (0x8060))
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_ADDR(base) ((base) + (0x8064))
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG0_0_ADDR(base) ((base) + (0x8068))
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG0_1_ADDR(base) ((base) + (0x806C))
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG1_ADDR(base) ((base) + (0x8070))
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG2_ADDR(base) ((base) + (0x8074))
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE0_ADDR(base) ((base) + (0x8080))
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE1_ADDR(base) ((base) + (0x8084))
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE_CFG_ADDR(base) ((base) + (0x8088))
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE0_ADDR(base) ((base) + (0x8090))
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE1_ADDR(base) ((base) + (0x8094))
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_PROD_ADDR(base) ((base) + (0x8098))
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_CONS_ADDR(base) ((base) + (0x809C))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE0_ADDR(base) ((base) + (0x80A0))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE1_ADDR(base) ((base) + (0x80A4))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_PROD_ADDR(base) ((base) + (0x80A8))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_CONS_ADDR(base) ((base) + (0x80AC))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x80B0))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x80B4))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG1_ADDR(base) ((base) + (0x80B8))
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG2_ADDR(base) ((base) + (0x80BC))
#define SOC_SMMUv3_TCU_SMMU_S_MPAMIDR_ADDR(base) ((base) + (0x8130))
#define SOC_SMMUv3_TCU_SMMU_S_GMPAM_ADDR(base) ((base) + (0x8138))
#define SOC_SMMUv3_TCU_SMMU_S_GBPMPAM_ADDR(base) ((base) + (0x813C))
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_ADDR(base) ((base) + (0x8E00))
#define SOC_SMMUv3_TCU_SMMU_QOS_ADDR(base) ((base) + (0x8E04))
#define SOC_SMMUv3_TCU_SMMU_TCU_TRANS_ADDR(base) ((base) + (0x8E08))
#define SOC_SMMUv3_TCU_SMMU_TCU_ALLOC_ADDR(base) ((base) + (0x8E10))
#define SOC_SMMUv3_TCU_SMMU_TCU_SCR_ADDR(base) ((base) + (0x8E18))
#define SOC_SMMUv3_TCU_SMMU_RAS_ERRFR_ADDR(base) ((base) + (0x8E80))
#define SOC_SMMUv3_TCU_SMMU_RAS_ERRCTRL_ADDR(base) ((base) + (0x8E88))
#define SOC_SMMUv3_TCU_SMMU_RAS_ERRSTATUS_ADDR(base) ((base) + (0x8E90))
#define SOC_SMMUv3_TCU_SMMU_RAS_ERRGEN_ADDR(base) ((base) + (0x8EC0))
#define SOC_SMMUv3_TCU_SMMU_MST_CTRL_ADDR(base,n) ((base) + (0x9000+(n)*4))
#define SOC_SMMUv3_TCU_SMMU_MST_LINK_ADDR(base,n) ((base) + (0x9400+(n)*4))
#define SOC_SMMUv3_TCU_SMMU_TTW_CACHE_CTRL_ADDR(base) ((base) + (0x9804))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUv3_TCU_SMMU_TCU_LP_REQ_ADDR(base) ((base) + (0x0000UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_LP_ACK_ADDR(base) ((base) + (0x0004UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_ADDR(base) ((base) + (0x0008UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_EVENTO_WIDTH_ADDR(base) ((base) + (0x000CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_S_DR_ADDR(base) ((base) + (0x0014UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_B_DR_ADDR(base) ((base) + (0x0018UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_T_DR_ADDR(base) ((base) + (0x001CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_SPC_DR_ADDR(base) ((base) + (0x0020UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_S_SR_ADDR(base) ((base) + (0x0024UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_B_SR_ADDR(base) ((base) + (0x0028UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_T_SR_ADDR(base) ((base) + (0x002CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_SPC_SR_ADDR(base) ((base) + (0x0030UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_ADDR(base) ((base) + (0x0070UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_ADDR(base) ((base) + (0x0074UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_ADDR(base) ((base) + (0x0078UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_ADDR(base) ((base) + (0x007CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_S_ADDR(base) ((base) + (0x0080UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_S_ADDR(base) ((base) + (0x0084UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_S_ADDR(base) ((base) + (0x0088UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_S_ADDR(base) ((base) + (0x008CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_CTRL_SCR_ADDR(base) ((base) + (0x0090UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_ADDR(base) ((base) + (0x0200UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_ADDR(base) ((base) + (0x0204UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_0_ADDR(base) ((base) + (0x0208UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_1_ADDR(base) ((base) + (0x020CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_0_ADDR(base) ((base) + (0x0210UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_1_ADDR(base) ((base) + (0x0214UL))
#else
#define SOC_SMMUv3_TCU_SMMU_TCU_LP_REQ_ADDR(base) ((base) + (0x0000))
#define SOC_SMMUv3_TCU_SMMU_TCU_LP_ACK_ADDR(base) ((base) + (0x0004))
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_ADDR(base) ((base) + (0x0008))
#define SOC_SMMUv3_TCU_SMMU_TCU_EVENTO_WIDTH_ADDR(base) ((base) + (0x000C))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_S_DR_ADDR(base) ((base) + (0x0014))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_B_DR_ADDR(base) ((base) + (0x0018))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_T_DR_ADDR(base) ((base) + (0x001C))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_SPC_DR_ADDR(base) ((base) + (0x0020))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_S_SR_ADDR(base) ((base) + (0x0024))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_B_SR_ADDR(base) ((base) + (0x0028))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_T_SR_ADDR(base) ((base) + (0x002C))
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_SPC_SR_ADDR(base) ((base) + (0x0030))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_ADDR(base) ((base) + (0x0070))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_ADDR(base) ((base) + (0x0074))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_ADDR(base) ((base) + (0x0078))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_ADDR(base) ((base) + (0x007C))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_S_ADDR(base) ((base) + (0x0080))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_S_ADDR(base) ((base) + (0x0084))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_S_ADDR(base) ((base) + (0x0088))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_S_ADDR(base) ((base) + (0x008C))
#define SOC_SMMUv3_TCU_SMMU_TCU_CTRL_SCR_ADDR(base) ((base) + (0x0090))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_ADDR(base) ((base) + (0x0200))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_ADDR(base) ((base) + (0x0204))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_0_ADDR(base) ((base) + (0x0208))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_1_ADDR(base) ((base) + (0x020C))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_0_ADDR(base) ((base) + (0x0210))
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_1_ADDR(base) ((base) + (0x0214))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TRB_IN_ADDR(base) ((base) + (0x000UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_ADDR(base) ((base) + (0x004UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT1_ADDR(base) ((base) + (0x008UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT2_ADDR(base) ((base) + (0x00CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT3_ADDR(base) ((base) + (0x010UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT0_ADDR(base) ((base) + (0x014UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT1_ADDR(base) ((base) + (0x018UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT2_ADDR(base) ((base) + (0x01CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT3_ADDR(base) ((base) + (0x020UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_INDEX_IN_ADDR(base) ((base) + (0x050UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT0_ADDR(base) ((base) + (0x054UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_ADDR(base) ((base) + (0x058UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT2_ADDR(base) ((base) + (0x05CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT3_ADDR(base) ((base) + (0x060UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT4_ADDR(base) ((base) + (0x064UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT5_ADDR(base) ((base) + (0x068UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT6_ADDR(base) ((base) + (0x06CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT7_ADDR(base) ((base) + (0x070UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_ADDR(base) ((base) + (0x074UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_ADDR(base) ((base) + (0x078UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT2_ADDR(base) ((base) + (0x07CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT3_ADDR(base) ((base) + (0x080UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_ADDR(base) ((base) + (0x084UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT1_ADDR(base) ((base) + (0x088UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT2_ADDR(base) ((base) + (0x08CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT3_ADDR(base) ((base) + (0x090UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT0_ADDR(base) ((base) + (0x94UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT1_ADDR(base) ((base) + (0x98UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT2_ADDR(base) ((base) + (0x9CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT3_ADDR(base) ((base) + (0x100UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_ADDR(base) ((base) + (0x104UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_ADDR(base) ((base) + (0x108UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT6_ADDR(base) ((base) + (0x10CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_ADDR(base) ((base) + (0x110UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_ADDR(base) ((base) + (0x114UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT1_ADDR(base) ((base) + (0x118UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT2_ADDR(base) ((base) + (0x11CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT3_ADDR(base) ((base) + (0x120UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_ADDR(base) ((base) + (0x124UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_ADDR(base) ((base) + (0x128UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT2_ADDR(base) ((base) + (0x12CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_ADDR(base) ((base) + (0x130UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_ADDR(base) ((base) + (0x134UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_ADDR(base) ((base) + (0x138UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT06_ADDR(base) ((base) + (0x13CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT7_ADDR(base) ((base) + (0x140UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_ADDR(base) ((base) + (0x144UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT1_ADDR(base) ((base) + (0x148UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT2_ADDR(base) ((base) + (0x14CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT3_ADDR(base) ((base) + (0x150UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_ADDR(base) ((base) + (0x154UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT1_ADDR(base) ((base) + (0x158UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT2_ADDR(base) ((base) + (0x15CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT3_ADDR(base) ((base) + (0x160UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TTWC_IN_ADDR(base) ((base) + (0x164UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_ADDR(base) ((base) + (0x168UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT1_ADDR(base) ((base) + (0x16CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT2_ADDR(base) ((base) + (0x170UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT3_ADDR(base) ((base) + (0x174UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT0_ADDR(base) ((base) + (0x178UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT1_ADDR(base) ((base) + (0x17CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT2_ADDR(base) ((base) + (0x180UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT3_ADDR(base) ((base) + (0x184UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_IN_ADDR(base) ((base) + (0x200UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_0_ADDR(base) ((base) + (0x204UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_1_ADDR(base) ((base) + (0x208UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_2_ADDR(base) ((base) + (0x20CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_3_ADDR(base) ((base) + (0x210UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_4_ADDR(base) ((base) + (0x214UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_5_ADDR(base) ((base) + (0x218UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_6_ADDR(base) ((base) + (0x21CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_7_ADDR(base) ((base) + (0x220UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_8_ADDR(base) ((base) + (0x224UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_ADDR(base) ((base) + (0x228UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_ADDR(base) ((base) + (0x22CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_ADDR(base) ((base) + (0x230UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_OTHER_ADDR(base) ((base) + (0x234UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_IN_ADDR(base) ((base) + (0x250UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_0_ADDR(base) ((base) + (0x254UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_1_ADDR(base) ((base) + (0x258UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_2_ADDR(base) ((base) + (0x25CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_3_ADDR(base) ((base) + (0x260UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_LKP_0_ADDR(base) ((base) + (0x264UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_LKP_1_ADDR(base) ((base) + (0x268UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_UPD_0_ADDR(base) ((base) + (0x26CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_UPD_1_ADDR(base) ((base) + (0x270UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_INV_0_ADDR(base) ((base) + (0x274UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_INV_1_ADDR(base) ((base) + (0x278UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_OTHER_ADDR(base) ((base) + (0x27CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CU_IN_ADDR(base) ((base) + (0x300UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_0_ADDR(base) ((base) + (0x304UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_1_ADDR(base) ((base) + (0x308UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_2_ADDR(base) ((base) + (0x30CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_3_ADDR(base) ((base) + (0x310UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_4_ADDR(base) ((base) + (0x314UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_IN_ADDR(base) ((base) + (0x400UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_ADDR(base) ((base) + (0x404UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_ADDR(base) ((base) + (0x408UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA1_ADDR(base) ((base) + (0x40CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA2_ADDR(base) ((base) + (0x410UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA3_ADDR(base) ((base) + (0x414UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_IN_ADDR(base) ((base) + (0x450UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_ADDR(base) ((base) + (0x454UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_ADDR(base) ((base) + (0x458UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA1_ADDR(base) ((base) + (0x45CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA2_ADDR(base) ((base) + (0x460UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_ADDR(base) ((base) + (0x464UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_IN_ADDR(base) ((base) + (0x500UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA0_ADDR(base) ((base) + (0x504UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA1_ADDR(base) ((base) + (0x508UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA2_ADDR(base) ((base) + (0x50CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA3_ADDR(base) ((base) + (0x510UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_IN_ADDR(base) ((base) + (0x514UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_ADDR(base) ((base) + (0x518UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_ADDR(base) ((base) + (0x51CUL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA1_ADDR(base) ((base) + (0x520UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA2_ADDR(base) ((base) + (0x524UL))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA3_ADDR(base) ((base) + (0x528UL))
#else
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TRB_IN_ADDR(base) ((base) + (0x000))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_ADDR(base) ((base) + (0x004))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT1_ADDR(base) ((base) + (0x008))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT2_ADDR(base) ((base) + (0x00C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT3_ADDR(base) ((base) + (0x010))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT0_ADDR(base) ((base) + (0x014))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT1_ADDR(base) ((base) + (0x018))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT2_ADDR(base) ((base) + (0x01C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT3_ADDR(base) ((base) + (0x020))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_INDEX_IN_ADDR(base) ((base) + (0x050))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT0_ADDR(base) ((base) + (0x054))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_ADDR(base) ((base) + (0x058))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT2_ADDR(base) ((base) + (0x05C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT3_ADDR(base) ((base) + (0x060))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT4_ADDR(base) ((base) + (0x064))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT5_ADDR(base) ((base) + (0x068))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT6_ADDR(base) ((base) + (0x06C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT7_ADDR(base) ((base) + (0x070))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_ADDR(base) ((base) + (0x074))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_ADDR(base) ((base) + (0x078))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT2_ADDR(base) ((base) + (0x07C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT3_ADDR(base) ((base) + (0x080))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_ADDR(base) ((base) + (0x084))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT1_ADDR(base) ((base) + (0x088))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT2_ADDR(base) ((base) + (0x08C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT3_ADDR(base) ((base) + (0x090))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT0_ADDR(base) ((base) + (0x94))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT1_ADDR(base) ((base) + (0x98))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT2_ADDR(base) ((base) + (0x9C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT3_ADDR(base) ((base) + (0x100))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_ADDR(base) ((base) + (0x104))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_ADDR(base) ((base) + (0x108))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT6_ADDR(base) ((base) + (0x10C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_ADDR(base) ((base) + (0x110))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_ADDR(base) ((base) + (0x114))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT1_ADDR(base) ((base) + (0x118))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT2_ADDR(base) ((base) + (0x11C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT3_ADDR(base) ((base) + (0x120))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_ADDR(base) ((base) + (0x124))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_ADDR(base) ((base) + (0x128))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT2_ADDR(base) ((base) + (0x12C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_ADDR(base) ((base) + (0x130))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_ADDR(base) ((base) + (0x134))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_ADDR(base) ((base) + (0x138))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT06_ADDR(base) ((base) + (0x13C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT7_ADDR(base) ((base) + (0x140))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_ADDR(base) ((base) + (0x144))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT1_ADDR(base) ((base) + (0x148))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT2_ADDR(base) ((base) + (0x14C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT3_ADDR(base) ((base) + (0x150))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_ADDR(base) ((base) + (0x154))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT1_ADDR(base) ((base) + (0x158))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT2_ADDR(base) ((base) + (0x15C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT3_ADDR(base) ((base) + (0x160))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TTWC_IN_ADDR(base) ((base) + (0x164))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_ADDR(base) ((base) + (0x168))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT1_ADDR(base) ((base) + (0x16C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT2_ADDR(base) ((base) + (0x170))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT3_ADDR(base) ((base) + (0x174))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT0_ADDR(base) ((base) + (0x178))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT1_ADDR(base) ((base) + (0x17C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT2_ADDR(base) ((base) + (0x180))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT3_ADDR(base) ((base) + (0x184))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_IN_ADDR(base) ((base) + (0x200))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_0_ADDR(base) ((base) + (0x204))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_1_ADDR(base) ((base) + (0x208))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_2_ADDR(base) ((base) + (0x20C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_3_ADDR(base) ((base) + (0x210))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_4_ADDR(base) ((base) + (0x214))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_5_ADDR(base) ((base) + (0x218))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_6_ADDR(base) ((base) + (0x21C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_7_ADDR(base) ((base) + (0x220))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_8_ADDR(base) ((base) + (0x224))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_ADDR(base) ((base) + (0x228))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_ADDR(base) ((base) + (0x22C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_ADDR(base) ((base) + (0x230))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_OTHER_ADDR(base) ((base) + (0x234))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_IN_ADDR(base) ((base) + (0x250))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_0_ADDR(base) ((base) + (0x254))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_1_ADDR(base) ((base) + (0x258))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_2_ADDR(base) ((base) + (0x25C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_3_ADDR(base) ((base) + (0x260))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_LKP_0_ADDR(base) ((base) + (0x264))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_LKP_1_ADDR(base) ((base) + (0x268))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_UPD_0_ADDR(base) ((base) + (0x26C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_UPD_1_ADDR(base) ((base) + (0x270))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_INV_0_ADDR(base) ((base) + (0x274))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_INV_1_ADDR(base) ((base) + (0x278))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_OTHER_ADDR(base) ((base) + (0x27C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CU_IN_ADDR(base) ((base) + (0x300))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_0_ADDR(base) ((base) + (0x304))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_1_ADDR(base) ((base) + (0x308))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_2_ADDR(base) ((base) + (0x30C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_3_ADDR(base) ((base) + (0x310))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_4_ADDR(base) ((base) + (0x314))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_IN_ADDR(base) ((base) + (0x400))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_ADDR(base) ((base) + (0x404))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_ADDR(base) ((base) + (0x408))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA1_ADDR(base) ((base) + (0x40C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA2_ADDR(base) ((base) + (0x410))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA3_ADDR(base) ((base) + (0x414))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_IN_ADDR(base) ((base) + (0x450))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_ADDR(base) ((base) + (0x454))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_ADDR(base) ((base) + (0x458))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA1_ADDR(base) ((base) + (0x45C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA2_ADDR(base) ((base) + (0x460))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_ADDR(base) ((base) + (0x464))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_IN_ADDR(base) ((base) + (0x500))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA0_ADDR(base) ((base) + (0x504))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA1_ADDR(base) ((base) + (0x508))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA2_ADDR(base) ((base) + (0x50C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA3_ADDR(base) ((base) + (0x510))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_IN_ADDR(base) ((base) + (0x514))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_ADDR(base) ((base) + (0x518))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_ADDR(base) ((base) + (0x51C))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA1_ADDR(base) ((base) + (0x520))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA2_ADDR(base) ((base) + (0x524))
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA3_ADDR(base) ((base) + (0x528))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s2p : 1;
        unsigned int s1p : 1;
        unsigned int ttf : 2;
        unsigned int cohacc : 1;
        unsigned int btm : 1;
        unsigned int httu : 2;
        unsigned int dormhint : 1;
        unsigned int hyp : 1;
        unsigned int ats : 1;
        unsigned int ns1ats : 1;
        unsigned int asid16 : 1;
        unsigned int msi : 1;
        unsigned int sev : 1;
        unsigned int atos : 1;
        unsigned int pri : 1;
        unsigned int vmw : 1;
        unsigned int vmid16 : 1;
        unsigned int cd2l : 1;
        unsigned int vatos : 1;
        unsigned int ttendian : 2;
        unsigned int reserved_0 : 1;
        unsigned int stall_model : 2;
        unsigned int term_model : 1;
        unsigned int st_level : 2;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_SMMUv3_TCU_SMMU_IDR0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_IDR0_s2p_START (0)
#define SOC_SMMUv3_TCU_SMMU_IDR0_s2p_END (0)
#define SOC_SMMUv3_TCU_SMMU_IDR0_s1p_START (1)
#define SOC_SMMUv3_TCU_SMMU_IDR0_s1p_END (1)
#define SOC_SMMUv3_TCU_SMMU_IDR0_ttf_START (2)
#define SOC_SMMUv3_TCU_SMMU_IDR0_ttf_END (3)
#define SOC_SMMUv3_TCU_SMMU_IDR0_cohacc_START (4)
#define SOC_SMMUv3_TCU_SMMU_IDR0_cohacc_END (4)
#define SOC_SMMUv3_TCU_SMMU_IDR0_btm_START (5)
#define SOC_SMMUv3_TCU_SMMU_IDR0_btm_END (5)
#define SOC_SMMUv3_TCU_SMMU_IDR0_httu_START (6)
#define SOC_SMMUv3_TCU_SMMU_IDR0_httu_END (7)
#define SOC_SMMUv3_TCU_SMMU_IDR0_dormhint_START (8)
#define SOC_SMMUv3_TCU_SMMU_IDR0_dormhint_END (8)
#define SOC_SMMUv3_TCU_SMMU_IDR0_hyp_START (9)
#define SOC_SMMUv3_TCU_SMMU_IDR0_hyp_END (9)
#define SOC_SMMUv3_TCU_SMMU_IDR0_ats_START (10)
#define SOC_SMMUv3_TCU_SMMU_IDR0_ats_END (10)
#define SOC_SMMUv3_TCU_SMMU_IDR0_ns1ats_START (11)
#define SOC_SMMUv3_TCU_SMMU_IDR0_ns1ats_END (11)
#define SOC_SMMUv3_TCU_SMMU_IDR0_asid16_START (12)
#define SOC_SMMUv3_TCU_SMMU_IDR0_asid16_END (12)
#define SOC_SMMUv3_TCU_SMMU_IDR0_msi_START (13)
#define SOC_SMMUv3_TCU_SMMU_IDR0_msi_END (13)
#define SOC_SMMUv3_TCU_SMMU_IDR0_sev_START (14)
#define SOC_SMMUv3_TCU_SMMU_IDR0_sev_END (14)
#define SOC_SMMUv3_TCU_SMMU_IDR0_atos_START (15)
#define SOC_SMMUv3_TCU_SMMU_IDR0_atos_END (15)
#define SOC_SMMUv3_TCU_SMMU_IDR0_pri_START (16)
#define SOC_SMMUv3_TCU_SMMU_IDR0_pri_END (16)
#define SOC_SMMUv3_TCU_SMMU_IDR0_vmw_START (17)
#define SOC_SMMUv3_TCU_SMMU_IDR0_vmw_END (17)
#define SOC_SMMUv3_TCU_SMMU_IDR0_vmid16_START (18)
#define SOC_SMMUv3_TCU_SMMU_IDR0_vmid16_END (18)
#define SOC_SMMUv3_TCU_SMMU_IDR0_cd2l_START (19)
#define SOC_SMMUv3_TCU_SMMU_IDR0_cd2l_END (19)
#define SOC_SMMUv3_TCU_SMMU_IDR0_vatos_START (20)
#define SOC_SMMUv3_TCU_SMMU_IDR0_vatos_END (20)
#define SOC_SMMUv3_TCU_SMMU_IDR0_ttendian_START (21)
#define SOC_SMMUv3_TCU_SMMU_IDR0_ttendian_END (22)
#define SOC_SMMUv3_TCU_SMMU_IDR0_stall_model_START (24)
#define SOC_SMMUv3_TCU_SMMU_IDR0_stall_model_END (25)
#define SOC_SMMUv3_TCU_SMMU_IDR0_term_model_START (26)
#define SOC_SMMUv3_TCU_SMMU_IDR0_term_model_END (26)
#define SOC_SMMUv3_TCU_SMMU_IDR0_st_level_START (27)
#define SOC_SMMUv3_TCU_SMMU_IDR0_st_level_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sidsize : 6;
        unsigned int ssidsize : 5;
        unsigned int priqs : 5;
        unsigned int eventqs : 5;
        unsigned int cmdqs : 5;
        unsigned int attr_perms_ovr : 1;
        unsigned int attr_types_ovr : 1;
        unsigned int rel : 1;
        unsigned int queues_preset : 1;
        unsigned int tables_preset : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_IDR1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_IDR1_sidsize_START (0)
#define SOC_SMMUv3_TCU_SMMU_IDR1_sidsize_END (5)
#define SOC_SMMUv3_TCU_SMMU_IDR1_ssidsize_START (6)
#define SOC_SMMUv3_TCU_SMMU_IDR1_ssidsize_END (10)
#define SOC_SMMUv3_TCU_SMMU_IDR1_priqs_START (11)
#define SOC_SMMUv3_TCU_SMMU_IDR1_priqs_END (15)
#define SOC_SMMUv3_TCU_SMMU_IDR1_eventqs_START (16)
#define SOC_SMMUv3_TCU_SMMU_IDR1_eventqs_END (20)
#define SOC_SMMUv3_TCU_SMMU_IDR1_cmdqs_START (21)
#define SOC_SMMUv3_TCU_SMMU_IDR1_cmdqs_END (25)
#define SOC_SMMUv3_TCU_SMMU_IDR1_attr_perms_ovr_START (26)
#define SOC_SMMUv3_TCU_SMMU_IDR1_attr_perms_ovr_END (26)
#define SOC_SMMUv3_TCU_SMMU_IDR1_attr_types_ovr_START (27)
#define SOC_SMMUv3_TCU_SMMU_IDR1_attr_types_ovr_END (27)
#define SOC_SMMUv3_TCU_SMMU_IDR1_rel_START (28)
#define SOC_SMMUv3_TCU_SMMU_IDR1_rel_END (28)
#define SOC_SMMUv3_TCU_SMMU_IDR1_queues_preset_START (29)
#define SOC_SMMUv3_TCU_SMMU_IDR1_queues_preset_END (29)
#define SOC_SMMUv3_TCU_SMMU_IDR1_tables_preset_START (30)
#define SOC_SMMUv3_TCU_SMMU_IDR1_tables_preset_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ba_vatos : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_SMMUv3_TCU_SMMU_IDR2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_IDR2_ba_vatos_START (0)
#define SOC_SMMUv3_TCU_SMMU_IDR2_ba_vatos_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 2;
        unsigned int had : 1;
        unsigned int pbha : 1;
        unsigned int xnx : 1;
        unsigned int reserved_1: 2;
        unsigned int mpam : 1;
        unsigned int reserved_2: 2;
        unsigned int ril : 1;
        unsigned int reserved_3: 21;
    } reg;
} SOC_SMMUv3_TCU_SMMU_IDR3_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_IDR3_had_START (2)
#define SOC_SMMUv3_TCU_SMMU_IDR3_had_END (2)
#define SOC_SMMUv3_TCU_SMMU_IDR3_pbha_START (3)
#define SOC_SMMUv3_TCU_SMMU_IDR3_pbha_END (3)
#define SOC_SMMUv3_TCU_SMMU_IDR3_xnx_START (4)
#define SOC_SMMUv3_TCU_SMMU_IDR3_xnx_END (4)
#define SOC_SMMUv3_TCU_SMMU_IDR3_mpam_START (7)
#define SOC_SMMUv3_TCU_SMMU_IDR3_mpam_END (7)
#define SOC_SMMUv3_TCU_SMMU_IDR3_ril_START (10)
#define SOC_SMMUv3_TCU_SMMU_IDR3_ril_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_IDR4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int oas : 3;
        unsigned int reserved_0: 1;
        unsigned int gran4k : 1;
        unsigned int gran16k : 1;
        unsigned int gran64k : 1;
        unsigned int reserved_1: 3;
        unsigned int vax : 2;
        unsigned int reserved_2: 4;
        unsigned int stall_max : 16;
    } reg;
} SOC_SMMUv3_TCU_SMMU_IDR5_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_IDR5_oas_START (0)
#define SOC_SMMUv3_TCU_SMMU_IDR5_oas_END (2)
#define SOC_SMMUv3_TCU_SMMU_IDR5_gran4k_START (4)
#define SOC_SMMUv3_TCU_SMMU_IDR5_gran4k_END (4)
#define SOC_SMMUv3_TCU_SMMU_IDR5_gran16k_START (5)
#define SOC_SMMUv3_TCU_SMMU_IDR5_gran16k_END (5)
#define SOC_SMMUv3_TCU_SMMU_IDR5_gran64k_START (6)
#define SOC_SMMUv3_TCU_SMMU_IDR5_gran64k_END (6)
#define SOC_SMMUv3_TCU_SMMU_IDR5_vax_START (10)
#define SOC_SMMUv3_TCU_SMMU_IDR5_vax_END (11)
#define SOC_SMMUv3_TCU_SMMU_IDR5_stall_max_START (16)
#define SOC_SMMUv3_TCU_SMMU_IDR5_stall_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int implementer : 12;
        unsigned int revision : 4;
        unsigned int variant : 4;
        unsigned int productid : 12;
    } reg;
} SOC_SMMUv3_TCU_SMMU_IIDR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_IIDR_implementer_START (0)
#define SOC_SMMUv3_TCU_SMMU_IIDR_implementer_END (11)
#define SOC_SMMUv3_TCU_SMMU_IIDR_revision_START (12)
#define SOC_SMMUv3_TCU_SMMU_IIDR_revision_END (15)
#define SOC_SMMUv3_TCU_SMMU_IIDR_variant_START (16)
#define SOC_SMMUv3_TCU_SMMU_IIDR_variant_END (19)
#define SOC_SMMUv3_TCU_SMMU_IIDR_productid_START (20)
#define SOC_SMMUv3_TCU_SMMU_IIDR_productid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int archminorrev : 4;
        unsigned int archmajorrev : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_SMMUv3_TCU_SMMU_AIDR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_AIDR_archminorrev_START (0)
#define SOC_SMMUv3_TCU_SMMU_AIDR_archminorrev_END (3)
#define SOC_SMMUv3_TCU_SMMU_AIDR_archmajorrev_START (4)
#define SOC_SMMUv3_TCU_SMMU_AIDR_archmajorrev_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmuen : 1;
        unsigned int priqen : 1;
        unsigned int eventqen : 1;
        unsigned int cmdqen : 1;
        unsigned int atschk : 1;
        unsigned int reserved_0 : 1;
        unsigned int vmw_wildcard : 3;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_SMMUv3_TCU_SMMU_CR0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_CR0_smmuen_START (0)
#define SOC_SMMUv3_TCU_SMMU_CR0_smmuen_END (0)
#define SOC_SMMUv3_TCU_SMMU_CR0_priqen_START (1)
#define SOC_SMMUv3_TCU_SMMU_CR0_priqen_END (1)
#define SOC_SMMUv3_TCU_SMMU_CR0_eventqen_START (2)
#define SOC_SMMUv3_TCU_SMMU_CR0_eventqen_END (2)
#define SOC_SMMUv3_TCU_SMMU_CR0_cmdqen_START (3)
#define SOC_SMMUv3_TCU_SMMU_CR0_cmdqen_END (3)
#define SOC_SMMUv3_TCU_SMMU_CR0_atschk_START (4)
#define SOC_SMMUv3_TCU_SMMU_CR0_atschk_END (4)
#define SOC_SMMUv3_TCU_SMMU_CR0_vmw_wildcard_START (6)
#define SOC_SMMUv3_TCU_SMMU_CR0_vmw_wildcard_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmuen_ack : 1;
        unsigned int priqen_ack : 1;
        unsigned int eventqen_ack : 1;
        unsigned int cmdqen_ack : 1;
        unsigned int atschk_ack : 1;
        unsigned int reserved_0 : 1;
        unsigned int vmw_ack : 3;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_SMMUv3_TCU_SMMU_CR0ACK_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_smmuen_ack_START (0)
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_smmuen_ack_END (0)
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_priqen_ack_START (1)
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_priqen_ack_END (1)
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_eventqen_ack_START (2)
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_eventqen_ack_END (2)
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_cmdqen_ack_START (3)
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_cmdqen_ack_END (3)
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_atschk_ack_START (4)
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_atschk_ack_END (4)
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_vmw_ack_START (6)
#define SOC_SMMUv3_TCU_SMMU_CR0ACK_vmw_ack_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int queue_ic : 2;
        unsigned int queue_oc : 2;
        unsigned int queue_sh : 2;
        unsigned int table_ic : 2;
        unsigned int table_oc : 2;
        unsigned int table_sh : 2;
        unsigned int reserved : 20;
    } reg;
} SOC_SMMUv3_TCU_SMMU_CR1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_CR1_queue_ic_START (0)
#define SOC_SMMUv3_TCU_SMMU_CR1_queue_ic_END (1)
#define SOC_SMMUv3_TCU_SMMU_CR1_queue_oc_START (2)
#define SOC_SMMUv3_TCU_SMMU_CR1_queue_oc_END (3)
#define SOC_SMMUv3_TCU_SMMU_CR1_queue_sh_START (4)
#define SOC_SMMUv3_TCU_SMMU_CR1_queue_sh_END (5)
#define SOC_SMMUv3_TCU_SMMU_CR1_table_ic_START (6)
#define SOC_SMMUv3_TCU_SMMU_CR1_table_ic_END (7)
#define SOC_SMMUv3_TCU_SMMU_CR1_table_oc_START (8)
#define SOC_SMMUv3_TCU_SMMU_CR1_table_oc_END (9)
#define SOC_SMMUv3_TCU_SMMU_CR1_table_sh_START (10)
#define SOC_SMMUv3_TCU_SMMU_CR1_table_sh_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2h : 1;
        unsigned int recinvsid : 1;
        unsigned int ptm : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUv3_TCU_SMMU_CR2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_CR2_e2h_START (0)
#define SOC_SMMUv3_TCU_SMMU_CR2_e2h_END (0)
#define SOC_SMMUv3_TCU_SMMU_CR2_recinvsid_START (1)
#define SOC_SMMUv3_TCU_SMMU_CR2_recinvsid_END (1)
#define SOC_SMMUv3_TCU_SMMU_CR2_ptm_START (2)
#define SOC_SMMUv3_TCU_SMMU_CR2_ptm_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dormant : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_STATUSR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_STATUSR_dormant_START (0)
#define SOC_SMMUv3_TCU_SMMU_STATUSR_dormant_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int memattr : 4;
        unsigned int mtcfg : 1;
        unsigned int reserved_0: 3;
        unsigned int alloccfg : 4;
        unsigned int shcfg : 2;
        unsigned int reserved_1: 2;
        unsigned int privcfg : 2;
        unsigned int instcfg : 2;
        unsigned int abort : 1;
        unsigned int reserved_2: 10;
        unsigned int update : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_GBPA_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_GBPA_memattr_START (0)
#define SOC_SMMUv3_TCU_SMMU_GBPA_memattr_END (3)
#define SOC_SMMUv3_TCU_SMMU_GBPA_mtcfg_START (4)
#define SOC_SMMUv3_TCU_SMMU_GBPA_mtcfg_END (4)
#define SOC_SMMUv3_TCU_SMMU_GBPA_alloccfg_START (8)
#define SOC_SMMUv3_TCU_SMMU_GBPA_alloccfg_END (11)
#define SOC_SMMUv3_TCU_SMMU_GBPA_shcfg_START (12)
#define SOC_SMMUv3_TCU_SMMU_GBPA_shcfg_END (13)
#define SOC_SMMUv3_TCU_SMMU_GBPA_privcfg_START (16)
#define SOC_SMMUv3_TCU_SMMU_GBPA_privcfg_END (17)
#define SOC_SMMUv3_TCU_SMMU_GBPA_instcfg_START (18)
#define SOC_SMMUv3_TCU_SMMU_GBPA_instcfg_END (19)
#define SOC_SMMUv3_TCU_SMMU_GBPA_abort_START (20)
#define SOC_SMMUv3_TCU_SMMU_GBPA_abort_END (20)
#define SOC_SMMUv3_TCU_SMMU_GBPA_update_START (31)
#define SOC_SMMUv3_TCU_SMMU_GBPA_update_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_AGBPA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gerror_irqen : 1;
        unsigned int priq_irqen : 1;
        unsigned int eventq_irqen : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUv3_TCU_SMMU_IRQ_CTRL_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRL_gerror_irqen_START (0)
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRL_gerror_irqen_END (0)
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRL_priq_irqen_START (1)
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRL_priq_irqen_END (1)
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRL_eventq_irqen_START (2)
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRL_eventq_irqen_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gerror_irqen_ack : 1;
        unsigned int priq_irqen_ack : 1;
        unsigned int eventq_irqen_ack : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUv3_TCU_SMMU_IRQ_CTRLACK_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRLACK_gerror_irqen_ack_START (0)
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRLACK_gerror_irqen_ack_END (0)
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRLACK_priq_irqen_ack_START (1)
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRLACK_priq_irqen_ack_END (1)
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRLACK_eventq_irqen_ack_START (2)
#define SOC_SMMUv3_TCU_SMMU_IRQ_CTRLACK_eventq_irqen_ack_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_err : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_abt_err : 1;
        unsigned int priq_abt_err : 1;
        unsigned int msi_cmdq_abt_err : 1;
        unsigned int msi_eventq_abt_err : 1;
        unsigned int msi_priq_abt_err : 1;
        unsigned int msi_gerror_abt_err : 1;
        unsigned int sfm_err : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_SMMUv3_TCU_SMMU_GERROR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_GERROR_cmdq_err_START (0)
#define SOC_SMMUv3_TCU_SMMU_GERROR_cmdq_err_END (0)
#define SOC_SMMUv3_TCU_SMMU_GERROR_eventq_abt_err_START (2)
#define SOC_SMMUv3_TCU_SMMU_GERROR_eventq_abt_err_END (2)
#define SOC_SMMUv3_TCU_SMMU_GERROR_priq_abt_err_START (3)
#define SOC_SMMUv3_TCU_SMMU_GERROR_priq_abt_err_END (3)
#define SOC_SMMUv3_TCU_SMMU_GERROR_msi_cmdq_abt_err_START (4)
#define SOC_SMMUv3_TCU_SMMU_GERROR_msi_cmdq_abt_err_END (4)
#define SOC_SMMUv3_TCU_SMMU_GERROR_msi_eventq_abt_err_START (5)
#define SOC_SMMUv3_TCU_SMMU_GERROR_msi_eventq_abt_err_END (5)
#define SOC_SMMUv3_TCU_SMMU_GERROR_msi_priq_abt_err_START (6)
#define SOC_SMMUv3_TCU_SMMU_GERROR_msi_priq_abt_err_END (6)
#define SOC_SMMUv3_TCU_SMMU_GERROR_msi_gerror_abt_err_START (7)
#define SOC_SMMUv3_TCU_SMMU_GERROR_msi_gerror_abt_err_END (7)
#define SOC_SMMUv3_TCU_SMMU_GERROR_sfm_err_START (8)
#define SOC_SMMUv3_TCU_SMMU_GERROR_sfm_err_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_errn : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_abt_errn : 1;
        unsigned int priq_abt_errn : 1;
        unsigned int msi_cmdq_abt_errn : 1;
        unsigned int msi_eventq_abt_errn : 1;
        unsigned int msi_priq_abt_errn : 1;
        unsigned int msi_gerror_abt_errn : 1;
        unsigned int sfm_errn : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_SMMUv3_TCU_SMMU_GERRORN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_GERRORN_cmdq_errn_START (0)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_cmdq_errn_END (0)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_eventq_abt_errn_START (2)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_eventq_abt_errn_END (2)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_priq_abt_errn_START (3)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_priq_abt_errn_END (3)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_msi_cmdq_abt_errn_START (4)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_msi_cmdq_abt_errn_END (4)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_msi_eventq_abt_errn_START (5)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_msi_eventq_abt_errn_END (5)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_msi_priq_abt_errn_START (6)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_msi_priq_abt_errn_END (6)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_msi_gerror_abt_errn_START (7)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_msi_gerror_abt_errn_END (7)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_sfm_errn_START (8)
#define SOC_SMMUv3_TCU_SMMU_GERRORN_sfm_errn_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_GERROR_IRQ_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 6;
        unsigned int st_base_addr0 : 26;
    } reg;
} SOC_SMMUv3_TCU_SMMU_STRTAB_BASE0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE0_st_base_addr0_START (6)
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE0_st_base_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_base_addr1 : 20;
        unsigned int reserved_0 : 10;
        unsigned int st_ra : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_STRTAB_BASE1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE1_st_base_addr1_START (0)
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE1_st_base_addr1_END (19)
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE1_st_ra_START (30)
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE1_st_ra_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_log2size : 6;
        unsigned int st_split : 5;
        unsigned int reserved_0 : 5;
        unsigned int st_fmt : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_SMMUv3_TCU_SMMU_STRTAB_BASE_CFG_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE_CFG_st_log2size_START (0)
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE_CFG_st_log2size_END (5)
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE_CFG_st_split_START (6)
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE_CFG_st_split_END (10)
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE_CFG_st_fmt_START (16)
#define SOC_SMMUv3_TCU_SMMU_STRTAB_BASE_CFG_st_fmt_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_log2size : 5;
        unsigned int cmdq_base_addr0 : 27;
    } reg;
} SOC_SMMUv3_TCU_SMMU_CMDQ_BASE0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE0_cmdq_log2size_START (0)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE0_cmdq_log2size_END (4)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE0_cmdq_base_addr0_START (5)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE0_cmdq_base_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_base_addr1 : 20;
        unsigned int reserved_0 : 10;
        unsigned int cmdq_ra : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_CMDQ_BASE1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE1_cmdq_base_addr1_START (0)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE1_cmdq_base_addr1_END (19)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE1_cmdq_ra_START (30)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_BASE1_cmdq_ra_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_wr : 19;
        unsigned int cmdq_wr_wrap : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_SMMUv3_TCU_SMMU_CMDQ_PROD_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_CMDQ_PROD_cmdq_wr_START (0)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_PROD_cmdq_wr_END (18)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_PROD_cmdq_wr_wrap_START (19)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_PROD_cmdq_wr_wrap_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_rd : 19;
        unsigned int cmdq_rd_wrap : 1;
        unsigned int reserved_0 : 4;
        unsigned int err : 7;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_CMDQ_CONS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_CMDQ_CONS_cmdq_rd_START (0)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_CONS_cmdq_rd_END (18)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_CONS_cmdq_rd_wrap_START (19)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_CONS_cmdq_rd_wrap_END (19)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_CONS_err_START (24)
#define SOC_SMMUv3_TCU_SMMU_CMDQ_CONS_err_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eventq_log2size : 5;
        unsigned int eventq_base_addr0 : 27;
    } reg;
} SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE0_eventq_log2size_START (0)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE0_eventq_log2size_END (4)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE0_eventq_base_addr0_START (5)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE0_eventq_base_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eventq_base_addr1 : 20;
        unsigned int reserved_0 : 10;
        unsigned int eventq_wa : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE1_eventq_base_addr1_START (0)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE1_eventq_base_addr1_END (19)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE1_eventq_wa_START (30)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_BASE1_eventq_wa_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eventq_wr : 19;
        unsigned int eventq_wr_wrap : 1;
        unsigned int reserved : 11;
        unsigned int ovflg : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_EVENTQ_PROD_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_PROD_eventq_wr_START (0)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_PROD_eventq_wr_END (18)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_PROD_eventq_wr_wrap_START (19)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_PROD_eventq_wr_wrap_END (19)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_PROD_ovflg_START (31)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_PROD_ovflg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eventq_rd : 19;
        unsigned int eventq_rd_wrap : 1;
        unsigned int reserved : 11;
        unsigned int ovackflg : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_EVENTQ_CONS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_CONS_eventq_rd_START (0)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_CONS_eventq_rd_END (18)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_CONS_eventq_rd_wrap_START (19)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_CONS_eventq_rd_wrap_END (19)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_CONS_ovackflg_START (31)
#define SOC_SMMUv3_TCU_SMMU_EVENTQ_CONS_ovackflg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_EVENTQ_IRQ_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PRIQ_BASE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PRIQ_BASE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PRIQ_PROD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PRIQ_CONS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PRIQ_IRQ_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int partid_max : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUv3_TCU_SMMU_MPAMIDR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_MPAMIDR_partid_max_START (0)
#define SOC_SMMUv3_TCU_SMMU_MPAMIDR_partid_max_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int so_partid : 16;
        unsigned int reserved : 15;
        unsigned int gmpam_update : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_GMPAM_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_GMPAM_so_partid_START (0)
#define SOC_SMMUv3_TCU_SMMU_GMPAM_so_partid_END (15)
#define SOC_SMMUv3_TCU_SMMU_GMPAM_gmpam_update_START (31)
#define SOC_SMMUv3_TCU_SMMU_GMPAM_gmpam_update_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gbp_partid : 16;
        unsigned int reserved : 15;
        unsigned int gbpmpam_update : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_GBPMPAM_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_GBPMPAM_gbp_partid_START (0)
#define SOC_SMMUv3_TCU_SMMU_GBPMPAM_gbp_partid_END (15)
#define SOC_SMMUv3_TCU_SMMU_GBPMPAM_gbpmpam_update_START (31)
#define SOC_SMMUv3_TCU_SMMU_GBPMPAM_gbpmpam_update_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evcntr : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_EVCNTR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVCNTR_evcntr_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVCNTR_evcntr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_r0 : 8;
        unsigned int reserved : 21;
        unsigned int filter_sid_span : 1;
        unsigned int filter_sec_sid : 1;
        unsigned int ovfcap_r0 : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER0_event_r0_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER0_event_r0_END (7)
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER0_filter_sid_span_START (29)
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER0_filter_sid_span_END (29)
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER0_filter_sec_sid_START (30)
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER0_filter_sec_sid_END (30)
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER0_ovfcap_r0_START (31)
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER0_ovfcap_r0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_rn : 8;
        unsigned int reserved : 23;
        unsigned int ovfcap_rn : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER_event_rn_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER_event_rn_END (7)
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER_ovfcap_rn_START (31)
#define SOC_SMMUv3_TCU_SMMU_PMCG_EVTYPER_ovfcap_rn_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int svr : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_SVR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_SVR_svr_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_SVR_svr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int streamid : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_SMR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_SMR_streamid_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_SMR_streamid_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnten : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_CNTENSET0_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENSET0_0_cnten_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENSET0_0_cnten_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_CNTENSET0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cntclr : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_CNTENCLR0_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENCLR0_0_cntclr_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CNTENCLR0_0_cntclr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_CNTENCLR0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inten : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_INTENSET0_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENSET0_0_inten_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENSET0_0_inten_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_INTENSET0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intclr : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_INTENCLR0_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENCLR0_0_intclr_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_INTENCLR0_0_intclr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_INTENCLR0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ovsclr : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_OVSCLR0_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSCLR0_0_ovsclr_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSCLR0_0_ovsclr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_OVSCLR0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ovsset : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_OVSSET0_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSSET0_0_ovsset_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_OVSSET0_0_ovsset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_OVSSET0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int capture : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_CAPR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_CAPR_capture_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CAPR_capture_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int so : 1;
        unsigned int nsra : 1;
        unsigned int nsmsi : 1;
        unsigned int reserved : 28;
        unsigned int read_as_one : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_SCR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_SCR_so_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_SCR_so_END (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_SCR_nsra_START (1)
#define SOC_SMMUv3_TCU_SMMU_PMCG_SCR_nsra_END (1)
#define SOC_SMMUv3_TCU_SMMU_PMCG_SCR_nsmsi_START (2)
#define SOC_SMMUv3_TCU_SMMU_PMCG_SCR_nsmsi_END (2)
#define SOC_SMMUv3_TCU_SMMU_PMCG_SCR_read_as_one_START (31)
#define SOC_SMMUv3_TCU_SMMU_PMCG_SCR_read_as_one_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int num_ctrs : 6;
        unsigned int reserved_0 : 2;
        unsigned int ctr_size : 6;
        unsigned int reserved_1 : 6;
        unsigned int reloc_ctrs : 1;
        unsigned int ctr_msi_en : 1;
        unsigned int ctr_capture_en : 1;
        unsigned int sid_filter_type : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_num_ctrs_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_num_ctrs_END (5)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_ctr_size_START (8)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_ctr_size_END (13)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_reloc_ctrs_START (20)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_reloc_ctrs_END (20)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_ctr_msi_en_START (21)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_ctr_msi_en_END (21)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_ctr_capture_en_START (22)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_ctr_capture_en_END (22)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_sid_filter_type_START (23)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CFGR_sid_filter_type_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int glb_cntr_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_CR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_CR_glb_cntr_en_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CR_glb_cntr_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ceid0_event_en0 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_CEID0_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID0_0_ceid0_event_en0_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID0_0_ceid0_event_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ceid0_event_en1 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_CEID0_1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID0_1_ceid0_event_en1_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID0_1_ceid0_event_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ceid1_event_en0 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_CEID1_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID1_0_ceid1_event_en0_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID1_0_ceid1_event_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ceid1_event_en1 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_CEID1_1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID1_1_ceid1_event_en1_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_CEID1_1_ceid1_event_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_irqen : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CTRL_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CTRL_pmu_irqen_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CTRL_pmu_irqen_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_irqen_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CTRLACK_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CTRLACK_pmu_irqen_ack_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CTRLACK_pmu_irqen_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_IRQ_STATUS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_archminorrev : 4;
        unsigned int pmu_archmajorrev : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_SMMUv3_TCU_SMMU_PMCG_AIDR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_PMCG_AIDR_pmu_archminorrev_START (0)
#define SOC_SMMUv3_TCU_SMMU_PMCG_AIDR_pmu_archminorrev_END (3)
#define SOC_SMMUv3_TCU_SMMU_PMCG_AIDR_pmu_archmajorrev_START (4)
#define SOC_SMMUv3_TCU_SMMU_PMCG_AIDR_pmu_archmajorrev_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 13;
        unsigned int msi_s : 1;
        unsigned int reserved_1 : 10;
        unsigned int stall_model_s : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_IDR0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_IDR0_msi_s_START (13)
#define SOC_SMMUv3_TCU_SMMU_S_IDR0_msi_s_END (13)
#define SOC_SMMUv3_TCU_SMMU_S_IDR0_stall_model_s_START (24)
#define SOC_SMMUv3_TCU_SMMU_S_IDR0_stall_model_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s_sidsize_s : 6;
        unsigned int reserved : 25;
        unsigned int secure_impl_s : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_IDR1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_IDR1_s_sidsize_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_IDR1_s_sidsize_s_END (5)
#define SOC_SMMUv3_TCU_SMMU_S_IDR1_secure_impl_s_START (31)
#define SOC_SMMUv3_TCU_SMMU_S_IDR1_secure_impl_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_IDR2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_IDR3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_IDR4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmuen_s : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventqen_s : 1;
        unsigned int cmdqen_s : 1;
        unsigned int reserved_1 : 1;
        unsigned int sif_s : 1;
        unsigned int reserved_2 : 3;
        unsigned int nsstalld_s : 1;
        unsigned int reserved_3 : 22;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_CR0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_CR0_smmuen_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_CR0_smmuen_s_END (0)
#define SOC_SMMUv3_TCU_SMMU_S_CR0_eventqen_s_START (2)
#define SOC_SMMUv3_TCU_SMMU_S_CR0_eventqen_s_END (2)
#define SOC_SMMUv3_TCU_SMMU_S_CR0_cmdqen_s_START (3)
#define SOC_SMMUv3_TCU_SMMU_S_CR0_cmdqen_s_END (3)
#define SOC_SMMUv3_TCU_SMMU_S_CR0_sif_s_START (5)
#define SOC_SMMUv3_TCU_SMMU_S_CR0_sif_s_END (5)
#define SOC_SMMUv3_TCU_SMMU_S_CR0_nsstalld_s_START (9)
#define SOC_SMMUv3_TCU_SMMU_S_CR0_nsstalld_s_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmuen_ack_s : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventqen_ack_s : 1;
        unsigned int cmdqen_ack_s : 1;
        unsigned int reserved_1 : 1;
        unsigned int sif_ack_s : 1;
        unsigned int reserved_2 : 3;
        unsigned int nsstalld_ack_s : 1;
        unsigned int reserved_3 : 22;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_CR0ACK_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_smmuen_ack_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_smmuen_ack_s_END (0)
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_eventqen_ack_s_START (2)
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_eventqen_ack_s_END (2)
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_cmdqen_ack_s_START (3)
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_cmdqen_ack_s_END (3)
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_sif_ack_s_START (5)
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_sif_ack_s_END (5)
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_nsstalld_ack_s_START (9)
#define SOC_SMMUv3_TCU_SMMU_S_CR0ACK_nsstalld_ack_s_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int queue_ic_s : 2;
        unsigned int queue_oc_s : 2;
        unsigned int queue_sh_s : 2;
        unsigned int table_ic_s : 2;
        unsigned int table_oc_s : 2;
        unsigned int table_sh_s : 2;
        unsigned int reserved : 20;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_CR1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_CR1_queue_ic_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_CR1_queue_ic_s_END (1)
#define SOC_SMMUv3_TCU_SMMU_S_CR1_queue_oc_s_START (2)
#define SOC_SMMUv3_TCU_SMMU_S_CR1_queue_oc_s_END (3)
#define SOC_SMMUv3_TCU_SMMU_S_CR1_queue_sh_s_START (4)
#define SOC_SMMUv3_TCU_SMMU_S_CR1_queue_sh_s_END (5)
#define SOC_SMMUv3_TCU_SMMU_S_CR1_table_ic_s_START (6)
#define SOC_SMMUv3_TCU_SMMU_S_CR1_table_ic_s_END (7)
#define SOC_SMMUv3_TCU_SMMU_S_CR1_table_oc_s_START (8)
#define SOC_SMMUv3_TCU_SMMU_S_CR1_table_oc_s_END (9)
#define SOC_SMMUv3_TCU_SMMU_S_CR1_table_sh_s_START (10)
#define SOC_SMMUv3_TCU_SMMU_S_CR1_table_sh_s_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int recinvsid_s : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 29;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_CR2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_CR2_recinvsid_s_START (1)
#define SOC_SMMUv3_TCU_SMMU_S_CR2_recinvsid_s_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inv_all : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_INIT_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_INIT_inv_all_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_INIT_inv_all_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int memattr_s : 4;
        unsigned int mtcfg_s : 1;
        unsigned int reserved_0 : 3;
        unsigned int alloccfg_s : 4;
        unsigned int shcfg_s : 2;
        unsigned int nscfg_s : 2;
        unsigned int privcfg_s : 2;
        unsigned int instcfg_s : 2;
        unsigned int abort_s : 1;
        unsigned int reserved_1 : 10;
        unsigned int update_s : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_GBPA_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_memattr_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_memattr_s_END (3)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_mtcfg_s_START (4)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_mtcfg_s_END (4)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_alloccfg_s_START (8)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_alloccfg_s_END (11)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_shcfg_s_START (12)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_shcfg_s_END (13)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_nscfg_s_START (14)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_nscfg_s_END (15)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_privcfg_s_START (16)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_privcfg_s_END (17)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_instcfg_s_START (18)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_instcfg_s_END (19)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_abort_s_START (20)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_abort_s_END (20)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_update_s_START (31)
#define SOC_SMMUv3_TCU_SMMU_S_GBPA_update_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_AGBPA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gerror_irqen_s : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_irqen_s : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRL_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRL_gerror_irqen_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRL_gerror_irqen_s_END (0)
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRL_eventq_irqen_s_START (2)
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRL_eventq_irqen_s_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gerror_irqen_ack_s : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_irqen_ack_s : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRLACK_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRLACK_gerror_irqen_ack_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRLACK_gerror_irqen_ack_s_END (0)
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRLACK_eventq_irqen_ack_s_START (2)
#define SOC_SMMUv3_TCU_SMMU_S_IRQ_CTRLACK_eventq_irqen_ack_s_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_err_s : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_abt_err_s : 1;
        unsigned int reserved_1 : 1;
        unsigned int msi_cmdq_abt_err_s : 1;
        unsigned int msi_eventq_abt_err_s : 1;
        unsigned int reserved_2 : 1;
        unsigned int msi_gerror_abt_err_s : 1;
        unsigned int sfm_err_s : 1;
        unsigned int reserved_3 : 23;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_GERROR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_cmdq_err_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_cmdq_err_s_END (0)
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_eventq_abt_err_s_START (2)
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_eventq_abt_err_s_END (2)
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_msi_cmdq_abt_err_s_START (4)
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_msi_cmdq_abt_err_s_END (4)
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_msi_eventq_abt_err_s_START (5)
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_msi_eventq_abt_err_s_END (5)
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_msi_gerror_abt_err_s_START (7)
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_msi_gerror_abt_err_s_END (7)
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_sfm_err_s_START (8)
#define SOC_SMMUv3_TCU_SMMU_S_GERROR_sfm_err_s_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_errn_s : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_abt_errn_s : 1;
        unsigned int reserved_1 : 1;
        unsigned int msi_cmdq_abt_errn_s : 1;
        unsigned int msi_eventq_abt_errn_s : 1;
        unsigned int reserved_2 : 1;
        unsigned int msi_gerror_abt_errn_s : 1;
        unsigned int sfm_errn_s : 1;
        unsigned int reserved_3 : 23;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_GERRORN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_cmdq_errn_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_cmdq_errn_s_END (0)
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_eventq_abt_errn_s_START (2)
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_eventq_abt_errn_s_END (2)
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_msi_cmdq_abt_errn_s_START (4)
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_msi_cmdq_abt_errn_s_END (4)
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_msi_eventq_abt_errn_s_START (5)
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_msi_eventq_abt_errn_s_END (5)
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_msi_gerror_abt_errn_s_START (7)
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_msi_gerror_abt_errn_s_END (7)
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_sfm_errn_s_START (8)
#define SOC_SMMUv3_TCU_SMMU_S_GERRORN_sfm_errn_s_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_GERROR_IRQ_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 6;
        unsigned int st_base_addr0_s : 26;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE0_st_base_addr0_s_START (6)
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE0_st_base_addr0_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_base_addr1_s : 20;
        unsigned int reserved_0 : 10;
        unsigned int st_ra_s : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE1_st_base_addr1_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE1_st_base_addr1_s_END (19)
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE1_st_ra_s_START (30)
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE1_st_ra_s_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_log2size_s : 6;
        unsigned int st_split_s : 5;
        unsigned int reserved_0 : 5;
        unsigned int st_fmt_s : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE_CFG_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE_CFG_st_log2size_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE_CFG_st_log2size_s_END (5)
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE_CFG_st_split_s_START (6)
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE_CFG_st_split_s_END (10)
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE_CFG_st_fmt_s_START (16)
#define SOC_SMMUv3_TCU_SMMU_S_STRTAB_BASE_CFG_st_fmt_s_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_log2size_s : 5;
        unsigned int cmdq_base_addr0_s : 27;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE0_cmdq_log2size_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE0_cmdq_log2size_s_END (4)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE0_cmdq_base_addr0_s_START (5)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE0_cmdq_base_addr0_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_base_addr1_s : 20;
        unsigned int reserved_0 : 10;
        unsigned int cmdq_ra_s : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE1_cmdq_base_addr1_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE1_cmdq_base_addr1_s_END (19)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE1_cmdq_ra_s_START (30)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_BASE1_cmdq_ra_s_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_wr_s : 19;
        unsigned int cmdq_wr_wrap_s : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_CMDQ_PROD_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_PROD_cmdq_wr_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_PROD_cmdq_wr_s_END (18)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_PROD_cmdq_wr_wrap_s_START (19)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_PROD_cmdq_wr_wrap_s_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_rd_s : 19;
        unsigned int cmdq_rd_wrap_s : 1;
        unsigned int reserved_0 : 4;
        unsigned int err_s : 7;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_CMDQ_CONS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_CONS_cmdq_rd_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_CONS_cmdq_rd_s_END (18)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_CONS_cmdq_rd_wrap_s_START (19)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_CONS_cmdq_rd_wrap_s_END (19)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_CONS_err_s_START (24)
#define SOC_SMMUv3_TCU_SMMU_S_CMDQ_CONS_err_s_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eventq_log2size_s : 5;
        unsigned int eventq_base_addr0_s : 27;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE0_eventq_log2size_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE0_eventq_log2size_s_END (4)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE0_eventq_base_addr0_s_START (5)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE0_eventq_base_addr0_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eventq_base_addr1_s : 20;
        unsigned int reserved_0 : 10;
        unsigned int eventq_wa_s : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE1_eventq_base_addr1_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE1_eventq_base_addr1_s_END (19)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE1_eventq_wa_s_START (30)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_BASE1_eventq_wa_s_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eventq_wr_s : 19;
        unsigned int eventq_wr_wrap_s : 1;
        unsigned int reserved : 11;
        unsigned int ovflg_s : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_EVENTQ_PROD_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_PROD_eventq_wr_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_PROD_eventq_wr_s_END (18)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_PROD_eventq_wr_wrap_s_START (19)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_PROD_eventq_wr_wrap_s_END (19)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_PROD_ovflg_s_START (31)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_PROD_ovflg_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eventq_rd_s : 19;
        unsigned int eventq_rd_wrap_s : 1;
        unsigned int reserved : 11;
        unsigned int ovackflg_s : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_EVENTQ_CONS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_CONS_eventq_rd_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_CONS_eventq_rd_s_END (18)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_CONS_eventq_rd_wrap_s_START (19)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_CONS_eventq_rd_wrap_s_END (19)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_CONS_ovackflg_s_START (31)
#define SOC_SMMUv3_TCU_SMMU_S_EVENTQ_CONS_ovackflg_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_EVENTQ_IRQ_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int partid_max_s : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_MPAMIDR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_MPAMIDR_partid_max_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_MPAMIDR_partid_max_s_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int so_partid_s : 16;
        unsigned int reserved : 15;
        unsigned int gmpam_update_s : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_GMPAM_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_GMPAM_so_partid_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_GMPAM_so_partid_s_END (15)
#define SOC_SMMUv3_TCU_SMMU_S_GMPAM_gmpam_update_s_START (31)
#define SOC_SMMUv3_TCU_SMMU_S_GMPAM_gmpam_update_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gbp_partid_s : 16;
        unsigned int reserved : 15;
        unsigned int gbpmpam_update_s : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_S_GBPMPAM_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_S_GBPMPAM_gbp_partid_s_START (0)
#define SOC_SMMUv3_TCU_SMMU_S_GBPMPAM_gbp_partid_s_END (15)
#define SOC_SMMUv3_TCU_SMMU_S_GBPMPAM_gbpmpam_update_s_START (31)
#define SOC_SMMUv3_TCU_SMMU_S_GBPMPAM_gbpmpam_update_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_hazard_dis : 1;
        unsigned int addr_hazard_dis : 1;
        unsigned int reserved_0 : 4;
        unsigned int wc_cache_st_dis : 1;
        unsigned int reserved_1 : 1;
        unsigned int wcs1l0_dis : 1;
        unsigned int wcs1l1_dis : 1;
        unsigned int wcs1l2_dis : 1;
        unsigned int wcs1l3_dis : 1;
        unsigned int wcs2l0_dis : 1;
        unsigned int wcs2l1_dis : 1;
        unsigned int wcs2l2_dis : 1;
        unsigned int wcs2l3_dis : 1;
        unsigned int cc_inv : 1;
        unsigned int wc_inv : 1;
        unsigned int ttwc_inv : 1;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_cfg_hazard_dis_START (0)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_cfg_hazard_dis_END (0)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_addr_hazard_dis_START (1)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_addr_hazard_dis_END (1)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wc_cache_st_dis_START (6)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wc_cache_st_dis_END (6)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs1l0_dis_START (8)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs1l0_dis_END (8)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs1l1_dis_START (9)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs1l1_dis_END (9)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs1l2_dis_START (10)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs1l2_dis_END (10)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs1l3_dis_START (11)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs1l3_dis_END (11)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs2l0_dis_START (12)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs2l0_dis_END (12)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs2l1_dis_START (13)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs2l1_dis_END (13)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs2l2_dis_START (14)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs2l2_dis_END (14)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs2l3_dis_START (15)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wcs2l3_dis_END (15)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_cc_inv_START (16)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_cc_inv_END (16)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wc_inv_START (17)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_wc_inv_END (17)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_ttwc_inv_START (18)
#define SOC_SMMUv3_TCU_SMMU_CACHE_CTRL_ttwc_inv_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_QOS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int trans_req_num : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_TRANS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_TRANS_trans_req_num_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_TRANS_trans_req_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int alloc_trans_num : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_ALLOC_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_ALLOC_alloc_trans_num_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_ALLOC_alloc_trans_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_SCR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_RAS_ERRFR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_RAS_ERRCTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_RAS_ERRSTATUS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_RAS_ERRGEN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_MST_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mst_connected : 1;
        unsigned int tbu_ats : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SMMUv3_TCU_SMMU_MST_LINK_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_MST_LINK_mst_connected_START (0)
#define SOC_SMMUv3_TCU_SMMU_MST_LINK_mst_connected_END (0)
#define SOC_SMMUv3_TCU_SMMU_MST_LINK_tbu_ats_START (1)
#define SOC_SMMUv3_TCU_SMMU_MST_LINK_tbu_ats_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int replace_policy_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TTW_CACHE_CTRL_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TTW_CACHE_CTRL_replace_policy_sel_START (0)
#define SOC_SMMUv3_TCU_SMMU_TTW_CACHE_CTRL_replace_policy_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_en_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int clk_gt_ctrl : 2;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_LP_REQ_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_LP_REQ_tcu_en_req_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_LP_REQ_tcu_en_req_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_LP_REQ_clk_gt_ctrl_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_LP_REQ_clk_gt_ctrl_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int tcu_en_ack : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_LP_ACK_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_LP_ACK_tcu_en_ack_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_LP_ACK_tcu_en_ack_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_rd_gid : 6;
        unsigned int tcu_rd_e_bit : 1;
        unsigned int tcu_rd_ptl_as_ful : 1;
        unsigned int tcu_wr_gid : 6;
        unsigned int tcu_wr_e_bit : 1;
        unsigned int tcu_wr_ptl_as_ful : 1;
        unsigned int tcu_rd_hint : 4;
        unsigned int reserved_0 : 3;
        unsigned int tcu_wr_hint : 4;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_rd_gid_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_rd_gid_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_rd_e_bit_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_rd_e_bit_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_rd_ptl_as_ful_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_rd_ptl_as_ful_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_wr_gid_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_wr_gid_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_wr_e_bit_START (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_wr_e_bit_END (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_wr_ptl_as_ful_START (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_wr_ptl_as_ful_END (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_rd_hint_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_rd_hint_END (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_wr_hint_START (23)
#define SOC_SMMUv3_TCU_SMMU_TCU_SYSCACHE_HINT_tcu_wr_hint_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_evento_width : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_EVENTO_WIDTH_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_EVENTO_WIDTH_tcu_evento_width_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_EVENTO_WIDTH_tcu_evento_width_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_s_dr : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_S_DR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_S_DR_mem_ctrl_s_dr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_S_DR_mem_ctrl_s_dr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_bp_d1w2r_dr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_B_DR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_B_DR_mem_ctrl_bp_d1w2r_dr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_B_DR_mem_ctrl_bp_d1w2r_dr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_tp_d1w2r_dr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_T_DR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_T_DR_mem_ctrl_tp_d1w2r_dr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_T_DR_mem_ctrl_tp_d1w2r_dr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_spc_dr : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_SPC_DR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_SPC_DR_mem_ctrl_spc_dr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_SPC_DR_mem_ctrl_spc_dr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_s_sr : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_S_SR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_S_SR_mem_ctrl_s_sr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_S_SR_mem_ctrl_s_sr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_bp_d1w2r_sr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_B_SR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_B_SR_mem_ctrl_bp_d1w2r_sr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_B_SR_mem_ctrl_bp_d1w2r_sr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_tp_d1w2r_sr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_T_SR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_T_SR_mem_ctrl_tp_d1w2r_sr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_T_SR_mem_ctrl_tp_d1w2r_sr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_spc_sr : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_SPC_SR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_SPC_SR_mem_ctrl_spc_sr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_MEM_CTRL_SPC_SR_mem_ctrl_spc_sr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_event_q_irpt_mask : 1;
        unsigned int tcu_cmd_sync_irpt_mask : 1;
        unsigned int tcu_global_irpt_mask : 1;
        unsigned int tcu_ras_irpt_mask : 1;
        unsigned int tcu_pmu_irpt_mask : 1;
        unsigned int tcu_evento_mask : 1;
        unsigned int tcu_cd_spec_chk_mask : 1;
        unsigned int tcu_ste_spec_chk_mask : 1;
        unsigned int tcu_ttw_read_rsp_err_mask : 1;
        unsigned int tcu_ttw_write_rsp_err_mask : 1;
        unsigned int mem_err_multpl_mask : 1;
        unsigned int mem_err_detect_mask : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_event_q_irpt_mask_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_event_q_irpt_mask_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_cmd_sync_irpt_mask_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_cmd_sync_irpt_mask_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_global_irpt_mask_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_global_irpt_mask_END (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_ras_irpt_mask_START (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_ras_irpt_mask_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_pmu_irpt_mask_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_pmu_irpt_mask_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_evento_mask_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_evento_mask_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_cd_spec_chk_mask_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_cd_spec_chk_mask_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_ste_spec_chk_mask_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_ste_spec_chk_mask_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_ttw_read_rsp_err_mask_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_ttw_read_rsp_err_mask_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_ttw_write_rsp_err_mask_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_tcu_ttw_write_rsp_err_mask_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_mem_err_multpl_mask_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_mem_err_multpl_mask_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_mem_err_detect_mask_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_NS_mem_err_detect_mask_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_event_q_irpt_raw : 1;
        unsigned int tcu_cmd_sync_irpt_raw : 1;
        unsigned int tcu_global_irpt_raw : 1;
        unsigned int tcu_ras_irpt_raw : 1;
        unsigned int tcu_pmu_irpt_raw : 1;
        unsigned int tcu_evento_raw : 1;
        unsigned int tcu_cd_spec_chk_raw : 1;
        unsigned int tcu_ste_spec_chk_raw : 1;
        unsigned int tcu_ttw_read_rsp_err_raw : 1;
        unsigned int tcu_ttw_write_rsp_err_raw : 1;
        unsigned int mem_err_multpl_raw : 1;
        unsigned int mem_err_detect_raw : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_event_q_irpt_raw_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_event_q_irpt_raw_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_cmd_sync_irpt_raw_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_cmd_sync_irpt_raw_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_global_irpt_raw_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_global_irpt_raw_END (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_ras_irpt_raw_START (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_ras_irpt_raw_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_pmu_irpt_raw_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_pmu_irpt_raw_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_evento_raw_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_evento_raw_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_cd_spec_chk_raw_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_cd_spec_chk_raw_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_ste_spec_chk_raw_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_ste_spec_chk_raw_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_ttw_read_rsp_err_raw_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_ttw_read_rsp_err_raw_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_ttw_write_rsp_err_raw_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_tcu_ttw_write_rsp_err_raw_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_mem_err_multpl_raw_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_mem_err_multpl_raw_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_mem_err_detect_raw_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_NS_mem_err_detect_raw_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_event_q_irpt_stat : 1;
        unsigned int tcu_cmd_sync_irpt_stat : 1;
        unsigned int tcu_global_irpt_stat : 1;
        unsigned int tcu_ras_irpt_stat : 1;
        unsigned int tcu_pmu_irpt_stat : 1;
        unsigned int tcu_evento_stat : 1;
        unsigned int tcu_cd_spec_chk_stat : 1;
        unsigned int tcu_ste_spec_chk_stat : 1;
        unsigned int tcu_ttw_read_rsp_err_stat : 1;
        unsigned int tcu_ttw_write_rsp_err_stat : 1;
        unsigned int mem_err_multpl_stat : 1;
        unsigned int mem_err_detect_stat : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_event_q_irpt_stat_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_event_q_irpt_stat_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_cmd_sync_irpt_stat_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_cmd_sync_irpt_stat_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_global_irpt_stat_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_global_irpt_stat_END (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_ras_irpt_stat_START (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_ras_irpt_stat_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_pmu_irpt_stat_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_pmu_irpt_stat_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_evento_stat_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_evento_stat_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_cd_spec_chk_stat_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_cd_spec_chk_stat_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_ste_spec_chk_stat_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_ste_spec_chk_stat_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_ttw_read_rsp_err_stat_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_ttw_read_rsp_err_stat_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_ttw_write_rsp_err_stat_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_tcu_ttw_write_rsp_err_stat_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_mem_err_multpl_stat_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_mem_err_multpl_stat_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_mem_err_detect_stat_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_NS_mem_err_detect_stat_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_event_q_irpt_clr : 1;
        unsigned int tcu_cmd_sync_irpt_clr : 1;
        unsigned int tcu_global_irpt_clr : 1;
        unsigned int tcu_ras_irpt_clr : 1;
        unsigned int tcu_pmu_irpt_clr : 1;
        unsigned int tcu_evento_clr : 1;
        unsigned int tcu_cd_spec_chk_clr : 1;
        unsigned int tcu_ste_spec_chk_clr : 1;
        unsigned int tcu_ttw_read_rsp_err_clr : 1;
        unsigned int tcu_ttw_write_rsp_err_clr : 1;
        unsigned int mem_err_multpl_clr : 1;
        unsigned int mem_err_detect_clr : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_event_q_irpt_clr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_event_q_irpt_clr_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_cmd_sync_irpt_clr_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_cmd_sync_irpt_clr_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_global_irpt_clr_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_global_irpt_clr_END (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_ras_irpt_clr_START (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_ras_irpt_clr_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_pmu_irpt_clr_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_pmu_irpt_clr_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_evento_clr_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_evento_clr_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_cd_spec_chk_clr_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_cd_spec_chk_clr_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_ste_spec_chk_clr_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_ste_spec_chk_clr_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_ttw_read_rsp_err_clr_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_ttw_read_rsp_err_clr_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_ttw_write_rsp_err_clr_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_tcu_ttw_write_rsp_err_clr_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_mem_err_multpl_clr_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_mem_err_multpl_clr_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_mem_err_detect_clr_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_NS_mem_err_detect_clr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_event_q_irpt_s_mask : 1;
        unsigned int tcu_cmd_sync_irpt_s_mask : 1;
        unsigned int tcu_global_irpt_s_mask : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_S_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_S_tcu_event_q_irpt_s_mask_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_S_tcu_event_q_irpt_s_mask_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_S_tcu_cmd_sync_irpt_s_mask_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_S_tcu_cmd_sync_irpt_s_mask_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_S_tcu_global_irpt_s_mask_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_MASK_S_tcu_global_irpt_s_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_event_q_irpt_s_raw : 1;
        unsigned int tcu_cmd_sync_irpt_s_raw : 1;
        unsigned int tcu_global_irpt_s_raw : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_S_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_S_tcu_event_q_irpt_s_raw_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_S_tcu_event_q_irpt_s_raw_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_S_tcu_cmd_sync_irpt_s_raw_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_S_tcu_cmd_sync_irpt_s_raw_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_S_tcu_global_irpt_s_raw_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_RAW_S_tcu_global_irpt_s_raw_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_event_q_irpt_s_stat : 1;
        unsigned int tcu_cmd_sync_irpt_s_stat : 1;
        unsigned int tcu_global_irpt_s_stat : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_S_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_S_tcu_event_q_irpt_s_stat_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_S_tcu_event_q_irpt_s_stat_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_S_tcu_cmd_sync_irpt_s_stat_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_S_tcu_cmd_sync_irpt_s_stat_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_S_tcu_global_irpt_s_stat_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STAT_S_tcu_global_irpt_s_stat_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_event_q_irpt_s_clr : 1;
        unsigned int tcu_cmd_sync_irpt_s_clr : 1;
        unsigned int tcu_global_irpt_s_clr : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_S_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_S_tcu_event_q_irpt_s_clr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_S_tcu_event_q_irpt_s_clr_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_S_tcu_cmd_sync_irpt_s_clr_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_S_tcu_cmd_sync_irpt_s_clr_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_S_tcu_global_irpt_s_clr_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CLR_S_tcu_global_irpt_s_clr_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ns_uarch : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_CTRL_SCR_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_CTRL_SCR_ns_uarch_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_CTRL_SCR_ns_uarch_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irpt_ste_pld_vld : 1;
        unsigned int irpt_ste_pld_sec_sid : 1;
        unsigned int irpt_ste_pld_sid : 6;
        unsigned int irpt_ste_pld_ssv : 1;
        unsigned int irpt_ste_pld_ssid : 12;
        unsigned int irpt_ste_pld_ste_strw : 2;
        unsigned int irpt_ste_pld_ste_partid : 4;
        unsigned int reserved : 5;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_vld_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_vld_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_sec_sid_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_sec_sid_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_sid_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_sid_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_ssv_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_ssv_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_ssid_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_ssid_END (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_ste_strw_START (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_ste_strw_END (22)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_ste_partid_START (23)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_STE_SPEC_FLT_PLD_irpt_ste_pld_ste_partid_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irpt_cd_pld_vld : 1;
        unsigned int irpt_cd_pld_sec_sid : 1;
        unsigned int irpt_cd_pld_sid : 6;
        unsigned int irpt_cd_pld_ssv : 1;
        unsigned int irpt_cd_pld_ssid : 12;
        unsigned int irpt_cd_pld_cd_aset : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_vld_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_vld_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_sec_sid_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_sec_sid_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_sid_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_sid_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_ssv_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_ssv_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_ssid_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_ssid_END (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_cd_aset_START (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_CD_SPEC_FLT_PLD_irpt_cd_pld_cd_aset_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irpt_ttw_read_rsp_err_pld_addr0 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_0_irpt_ttw_read_rsp_err_pld_addr0_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_0_irpt_ttw_read_rsp_err_pld_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irpt_ttw_read_rsp_err_pld_vld : 1;
        unsigned int irpt_ttw_read_rsp_err_pld_addr1 : 20;
        unsigned int reserved : 11;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_1_irpt_ttw_read_rsp_err_pld_vld_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_1_irpt_ttw_read_rsp_err_pld_vld_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_1_irpt_ttw_read_rsp_err_pld_addr1_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_READ_RSP_ERR_PLD_1_irpt_ttw_read_rsp_err_pld_addr1_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irpt_ttw_write_rsp_err_pld_addr0 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_0_irpt_ttw_write_rsp_err_pld_addr0_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_0_irpt_ttw_write_rsp_err_pld_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irpt_ttw_write_rsp_err_pld_vld : 1;
        unsigned int irpt_ttw_write_rsp_err_pld_addr1 : 20;
        unsigned int reserved : 11;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_1_irpt_ttw_write_rsp_err_pld_vld_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_1_irpt_ttw_write_rsp_err_pld_vld_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_1_irpt_ttw_write_rsp_err_pld_addr1_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_IRPT_TTW_WRITE_RSP_ERR_PLD_1_irpt_ttw_write_rsp_err_pld_addr1_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_trb_addr : 8;
        unsigned int dbg_cfg_trb_rd : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TRB_IN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TRB_IN_dbg_cfg_trb_addr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TRB_IN_dbg_cfg_trb_addr_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TRB_IN_dbg_cfg_trb_rd_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TRB_IN_dbg_cfg_trb_rd_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pref : 1;
        unsigned int pmu_en : 1;
        unsigned int tid : 3;
        unsigned int trans_id : 7;
        unsigned int pnu : 1;
        unsigned int ind : 1;
        unsigned int secsid : 1;
        unsigned int ssv : 1;
        unsigned int perm : 2;
        unsigned int ns : 1;
        unsigned int sid : 6;
        unsigned int ssid : 7;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_pref_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_pref_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_pmu_en_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_pmu_en_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_tid_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_tid_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_trans_id_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_trans_id_END (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_pnu_START (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_pnu_END (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_ind_START (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_ind_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_secsid_START (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_secsid_END (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_ssv_START (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_ssv_END (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_perm_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_perm_END (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_ns_START (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_ns_END (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_sid_START (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_sid_END (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_ssid_START (25)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT0_ssid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ssid : 1;
        unsigned int ia : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT1_ssid_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT1_ssid_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT1_ia_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT1_ia_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ia : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT2_ia_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT2_ia_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_MEM_OUT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int unwr_ns_stall_queue_cnt : 8;
        unsigned int unwr_s_stall_queue_cnt : 8;
        unsigned int wr_ns_stall_queue_cnt : 8;
        unsigned int wr_s_stall_queue_cnt : 8;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT0_unwr_ns_stall_queue_cnt_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT0_unwr_ns_stall_queue_cnt_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT0_unwr_s_stall_queue_cnt_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT0_unwr_s_stall_queue_cnt_END (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT0_wr_ns_stall_queue_cnt_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT0_wr_ns_stall_queue_cnt_END (23)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT0_wr_s_stall_queue_cnt_START (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT0_wr_s_stall_queue_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TRB_QUEUE_OUT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_tmu_addr : 8;
        unsigned int dbg_cfg_tmu_rd : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_INDEX_IN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_INDEX_IN_dbg_cfg_tmu_addr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_INDEX_IN_dbg_cfg_tmu_addr_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_INDEX_IN_dbg_cfg_tmu_rd_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_INDEX_IN_dbg_cfg_tmu_rd_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tid : 8;
        unsigned int trans_id : 8;
        unsigned int flt_rpt : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT0_tid_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT0_tid_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT0_trans_id_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT0_trans_id_END (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT0_flt_rpt_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT0_flt_rpt_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsp_msg_type : 3;
        unsigned int rsp_flt_type : 2;
        unsigned int rsp_do_not_cache : 1;
        unsigned int rsp_ns : 1;
        unsigned int rsp_allow_px_nsx : 1;
        unsigned int rsp_privcfg : 2;
        unsigned int rsp_instcfg : 2;
        unsigned int rsp_memattr : 3;
        unsigned int rsp_alloccfg : 3;
        unsigned int rsp_shcfg : 2;
        unsigned int reserved : 12;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_msg_type_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_msg_type_END (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_flt_type_START (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_flt_type_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_do_not_cache_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_do_not_cache_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_ns_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_ns_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_allow_px_nsx_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_allow_px_nsx_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_privcfg_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_privcfg_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_instcfg_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_instcfg_END (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_memattr_START (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_memattr_END (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_alloccfg_START (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_alloccfg_END (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_shcfg_START (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT1_rsp_shcfg_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int flt_number : 8;
        unsigned int reserved_0 : 12;
        unsigned int flt_secsid : 1;
        unsigned int flt_ssv : 1;
        unsigned int flt_rnw : 1;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT4_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT4_flt_number_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT4_flt_number_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT4_flt_secsid_START (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT4_flt_secsid_END (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT4_flt_ssv_START (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT4_flt_ssv_END (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT4_flt_rnw_START (22)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT4_flt_rnw_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int flt_sid : 6;
        unsigned int reserved_0: 2;
        unsigned int flt_ssid : 12;
        unsigned int reserved_1: 2;
        unsigned int flt_ia : 10;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT5_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT5_flt_sid_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT5_flt_sid_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT5_flt_ssid_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT5_flt_ssid_END (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT5_flt_ia_START (22)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT5_flt_ia_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int flt_ia : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT6_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT6_flt_ia_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT6_flt_ia_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CHECK_OUT7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idx_vld : 1;
        unsigned int flt_vld : 1;
        unsigned int cfg_vld : 1;
        unsigned int inv_vld : 1;
        unsigned int inv_leaf : 1;
        unsigned int inv_lvl : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_idx_vld_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_idx_vld_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_flt_vld_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_flt_vld_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_cfg_vld_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_cfg_vld_END (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_inv_vld_START (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_inv_vld_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_inv_leaf_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_inv_leaf_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_inv_lvl_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT0_inv_lvl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_en : 1;
        unsigned int tid : 4;
        unsigned int qos : 8;
        unsigned int trans_id : 8;
        unsigned int pnu : 1;
        unsigned int ind : 1;
        unsigned int secsid : 1;
        unsigned int ssv : 1;
        unsigned int ns : 1;
        unsigned int perm : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_pmu_en_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_pmu_en_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_tid_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_tid_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_qos_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_qos_END (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_trans_id_START (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_trans_id_END (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_pnu_START (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_pnu_END (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_ind_START (22)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_ind_END (22)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_secsid_START (23)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_secsid_END (23)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_ssv_START (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_ssv_END (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_ns_START (25)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_ns_END (25)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_perm_START (26)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT1_perm_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trans_sid : 8;
        unsigned int trans_ssid : 12;
        unsigned int trans_ia : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT2_trans_sid_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT2_trans_sid_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT2_trans_ssid_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT2_trans_ssid_END (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT2_trans_ia_START (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT2_trans_ia_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trans_ia : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT3_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT3_trans_ia_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TRANS_OUT3_trans_ia_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s1dss : 2;
        unsigned int s1cdmax : 5;
        unsigned int strw : 2;
        unsigned int vmid : 8;
        unsigned int ste_config : 3;
        unsigned int shcfg : 2;
        unsigned int alloccfg : 4;
        unsigned int mtcfg : 1;
        unsigned int reserved : 1;
        unsigned int memattr : 4;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_s1dss_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_s1dss_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_s1cdmax_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_s1cdmax_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_strw_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_strw_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_vmid_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_vmid_END (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_ste_config_START (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_ste_config_END (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_shcfg_START (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_shcfg_END (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_alloccfg_START (22)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_alloccfg_END (25)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_mtcfg_START (26)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_mtcfg_END (26)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_memattr_START (28)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT0_memattr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 10;
        unsigned int asid : 8;
        unsigned int asset : 1;
        unsigned int hwux : 4;
        unsigned int reserved_1: 9;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT1_asid_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT1_asid_END (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT1_asset_START (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT1_asset_END (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT1_hwux_START (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT1_hwux_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mair0 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT2_mair0_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT2_mair0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mair1 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT3_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT3_mair1_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CFG_OUT3_mair1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int oa : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT0_oa_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT0_oa_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsp_req : 1;
        unsigned int msg_type : 4;
        unsigned int tid : 4;
        unsigned int trans_id : 8;
        unsigned int do_not_cache : 1;
        unsigned int cont : 4;
        unsigned int bypass : 1;
        unsigned int strw_bp_type : 2;
        unsigned int dre : 1;
        unsigned int dcp : 1;
        unsigned int pricfg : 2;
        unsigned int instcfg : 2;
        unsigned int reserved : 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_rsp_req_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_rsp_req_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_msg_type_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_msg_type_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_tid_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_tid_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_trans_id_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_trans_id_END (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_do_not_cache_START (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_do_not_cache_END (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_cont_START (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_cont_END (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_bypass_START (22)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_bypass_END (22)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_strw_bp_type_START (23)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_strw_bp_type_END (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_dre_START (25)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_dre_END (25)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_dcp_START (26)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_dcp_END (26)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_pricfg_START (27)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_pricfg_END (28)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_instcfg_START (29)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT4_instcfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asset_nsovr : 1;
        unsigned int alloccfg : 4;
        unsigned int allow_ur : 1;
        unsigned int allow_uw : 1;
        unsigned int allow_ux : 1;
        unsigned int allow_pr : 1;
        unsigned int allow_pw : 1;
        unsigned int allow_px_nsx : 1;
        unsigned int ns : 1;
        unsigned int tbi : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_asset_nsovr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_asset_nsovr_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_alloccfg_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_alloccfg_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_ur_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_ur_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_uw_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_uw_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_ux_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_ux_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_pr_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_pr_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_pw_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_pw_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_px_nsx_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_allow_px_nsx_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_ns_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_ns_END (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_tbi_START (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT5_tbi_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vmid : 16;
        unsigned int asid_attr_ovr : 16;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT6_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT6_vmid_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT6_vmid_END (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT6_asid_attr_ovr_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT6_asid_attr_ovr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int glbl : 1;
        unsigned int trans_tng : 4;
        unsigned int inval_rng : 4;
        unsigned int s1hwattr : 4;
        unsigned int s2hwattr : 4;
        unsigned int attr : 8;
        unsigned int sh : 2;
        unsigned int reserved : 5;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_glbl_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_glbl_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_trans_tng_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_trans_tng_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_inval_rng_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_inval_rng_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_s1hwattr_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_s1hwattr_END (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_s2hwattr_START (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_s2hwattr_END (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_attr_START (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_attr_END (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_sh_START (25)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_RSP_OUT7_sh_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lkp_vld : 1;
        unsigned int granule : 2;
        unsigned int start_lvl : 2;
        unsigned int stage : 1;
        unsigned int ia : 10;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_lkp_vld_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_lkp_vld_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_granule_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_granule_END (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_start_lvl_START (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_start_lvl_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_stage_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_stage_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_ia_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT0_ia_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ia : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT1_ia_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT1_ia_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_LKP_OUT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int strw : 2;
        unsigned int s2affd : 1;
        unsigned int s2ps : 3;
        unsigned int s2ptw : 1;
        unsigned int s2r : 1;
        unsigned int s2s : 1;
        unsigned int s2tg : 2;
        unsigned int s2sh0 : 2;
        unsigned int s2or0 : 2;
        unsigned int s2ir0 : 6;
        unsigned int s2t0sz : 2;
        unsigned int s2sl0 : 2;
        unsigned int s2aa64 : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_strw_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_strw_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2affd_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2affd_END (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2ps_START (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2ps_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2ptw_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2ptw_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2r_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2r_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2s_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2s_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2tg_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2tg_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2sh0_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2sh0_END (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2or0_START (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2or0_END (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2ir0_START (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2ir0_END (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2t0sz_START (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2t0sz_END (22)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2sl0_START (23)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2sl0_END (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2aa64_START (25)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT0_s2aa64_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int privcfg : 2;
        unsigned int instcfg : 2;
        unsigned int cont : 4;
        unsigned int s2_enable : 1;
        unsigned int s1_enable : 1;
        unsigned int s2ttb : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_privcfg_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_privcfg_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_instcfg_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_instcfg_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_cont_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_cont_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_s2_enable_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_s2_enable_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_s1_enable_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_s1_enable_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_s2ttb_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT1_s2ttb_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s2ttb : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT2_s2ttb_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT2_s2ttb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ips : 3;
        unsigned int affd : 1;
        unsigned int had0 : 1;
        unsigned int nscfg0 : 1;
        unsigned int a : 1;
        unsigned int r : 1;
        unsigned int s : 1;
        unsigned int pan : 1;
        unsigned int uwxn : 1;
        unsigned int wxn : 1;
        unsigned int sh0 : 2;
        unsigned int or0 : 2;
        unsigned int ir0 : 2;
        unsigned int tg0 : 2;
        unsigned int t0sz : 6;
        unsigned int aa64 : 1;
        unsigned int asset : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_ips_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_ips_END (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_affd_START (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_affd_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_had0_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_had0_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_nscfg0_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_nscfg0_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_a_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_a_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_r_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_r_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_s_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_s_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_pan_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_pan_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_uwxn_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_uwxn_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_wxn_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_wxn_END (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_sh0_START (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_sh0_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_or0_START (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_or0_END (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_ir0_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_ir0_END (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_tg0_START (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_tg0_END (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_t0sz_START (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_t0sz_END (25)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_aa64_START (26)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_aa64_END (26)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_asset_START (27)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT3_asset_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s2_hwattr : 4;
        unsigned int s2_hint : 1;
        unsigned int s2_xn : 1;
        unsigned int s2_sh : 2;
        unsigned int s2_hap : 2;
        unsigned int s2_memattr : 4;
        unsigned int s1_hwattr : 4;
        unsigned int s1_hint : 1;
        unsigned int s1_pxn : 1;
        unsigned int s1_xn : 1;
        unsigned int s1_ng : 1;
        unsigned int s1_sh : 2;
        unsigned int s1_ap : 2;
        unsigned int s1_ns : 1;
        unsigned int s1_attindx : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_hwattr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_hwattr_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_hint_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_hint_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_xn_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_xn_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_sh_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_sh_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_hap_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_hap_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_memattr_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s2_memattr_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_hwattr_START (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_hwattr_END (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_hint_START (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_hint_END (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_pxn_START (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_pxn_END (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_xn_START (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_xn_END (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_ng_START (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_ng_END (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_sh_START (22)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_sh_END (23)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_ap_START (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_ap_END (25)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_ns_START (26)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_ns_END (26)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_attindx_START (27)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT4_s1_attindx_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inv_rng : 3;
        unsigned int trans_rng : 3;
        unsigned int s2_lvl : 2;
        unsigned int s1_lvl : 2;
        unsigned int s1_updated_n : 1;
        unsigned int s2_hint : 1;
        unsigned int cd_pa_access : 1;
        unsigned int s1_final_s2 : 1;
        unsigned int s2_access : 1;
        unsigned int s1_access : 1;
        unsigned int ttw_addr : 10;
        unsigned int reserved : 6;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_inv_rng_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_inv_rng_END (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_trans_rng_START (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_trans_rng_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s2_lvl_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s2_lvl_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s1_lvl_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s1_lvl_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s1_updated_n_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s1_updated_n_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s2_hint_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s2_hint_END (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_cd_pa_access_START (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_cd_pa_access_END (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s1_final_s2_START (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s1_final_s2_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s2_access_START (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s2_access_END (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s1_access_START (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_s1_access_END (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_ttw_addr_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT5_ttw_addr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ttw_addr : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT06_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT06_ttw_addr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT06_ttw_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_PROPS_OUT7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int flt_vld : 1;
        unsigned int flt_rpt : 1;
        unsigned int flt_type : 2;
        unsigned int do_not_cache : 1;
        unsigned int number : 8;
        unsigned int cont : 4;
        unsigned int stall : 1;
        unsigned int pnu : 1;
        unsigned int ind : 1;
        unsigned int s2 : 1;
        unsigned int clss : 2;
        unsigned int reserved : 9;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_flt_vld_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_flt_vld_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_flt_rpt_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_flt_rpt_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_flt_type_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_flt_type_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_do_not_cache_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_do_not_cache_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_number_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_number_END (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_cont_START (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_cont_END (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_stall_START (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_stall_END (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_pnu_START (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_pnu_END (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_ind_START (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_ind_END (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_s2_START (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_s2_END (20)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_clss_START (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT0_clss_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_FLT_OUT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ttw_vld : 1;
        unsigned int ttw_hazard_vld : 1;
        unsigned int domn : 2;
        unsigned int prot_ns : 1;
        unsigned int cache : 2;
        unsigned int size : 1;
        unsigned int len : 1;
        unsigned int addr : 10;
        unsigned int reserved : 13;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_ttw_vld_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_ttw_vld_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_ttw_hazard_vld_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_ttw_hazard_vld_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_domn_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_domn_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_prot_ns_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_prot_ns_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_cache_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_cache_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_size_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_size_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_len_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_len_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_addr_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT0_addr_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT1_addr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT1_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_TTW_OUT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_ttwc_addr : 9;
        unsigned int ttw_cache_bypass_en : 1;
        unsigned int dbg_cfg_ttwc_rd : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TTWC_IN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TTWC_IN_dbg_cfg_ttwc_addr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TTWC_IN_dbg_cfg_ttwc_addr_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TTWC_IN_ttw_cache_bypass_en_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TTWC_IN_ttw_cache_bypass_en_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TTWC_IN_dbg_cfg_ttwc_rd_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TTWC_IN_dbg_cfg_ttwc_rd_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inv_vld : 1;
        unsigned int updated_cnt : 8;
        unsigned int updating_id : 8;
        unsigned int updating_vld : 1;
        unsigned int tag_vld : 1;
        unsigned int tag_addr : 10;
        unsigned int reserved : 3;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_inv_vld_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_inv_vld_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_updated_cnt_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_updated_cnt_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_updating_id_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_updating_id_END (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_updating_vld_START (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_updating_vld_END (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_tag_vld_START (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_tag_vld_END (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_tag_addr_START (19)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT0_tag_addr_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tag_addr : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT1_tag_addr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT1_tag_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_TAG_OUT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_data : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT0_mem_data_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT0_mem_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_data : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT1_mem_data_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT1_mem_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_data : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT2_mem_data_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT2_mem_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_data : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT3_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT3_mem_data_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_PORT_TTWC_MEM_OUT3_mem_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_cc_addr : 16;
        unsigned int dbg_cfg_cc_rd : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_IN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_IN_dbg_cfg_cc_addr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_IN_dbg_cfg_cc_addr_END (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_IN_dbg_cfg_cc_rd_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_IN_dbg_cfg_cc_rd_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cc_rdata_0 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_0_cc_rdata_0_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_0_cc_rdata_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cc_rdata_1 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_1_cc_rdata_1_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_1_cc_rdata_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cc_rdata_2 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_2_cc_rdata_2_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_2_cc_rdata_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cc_rdata_3 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_3_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_3_cc_rdata_3_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_3_cc_rdata_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cc_rdata_4 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_4_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_4_cc_rdata_4_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_4_cc_rdata_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cc_rdata_5 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_5_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_5_cc_rdata_5_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_5_cc_rdata_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cc_rdata_6 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_6_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_6_cc_rdata_6_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_6_cc_rdata_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cc_rdata_7 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_7_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_7_cc_rdata_7_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_7_cc_rdata_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cc_rdata_8 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_8_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_8_cc_rdata_8_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_PORT_OUT_8_cc_rdata_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idx : 6;
        unsigned int pmu_en : 1;
        unsigned int secsid : 1;
        unsigned int sid : 6;
        unsigned int reserved_0: 2;
        unsigned int ssid : 6;
        unsigned int reserved_1: 2;
        unsigned int ssidv : 1;
        unsigned int hit : 1;
        unsigned int reserved_2: 6;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_idx_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_idx_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_pmu_en_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_pmu_en_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_secsid_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_secsid_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_sid_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_sid_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_ssid_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_ssid_END (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_ssidv_START (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_ssidv_END (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_hit_START (25)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_LKP_hit_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wr_entry_addr : 6;
        unsigned int reserved_0 : 1;
        unsigned int secsid : 1;
        unsigned int sid : 6;
        unsigned int reserved_1 : 2;
        unsigned int ssid : 6;
        unsigned int reserved_2 : 2;
        unsigned int ssidv : 1;
        unsigned int reserved_3 : 7;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_wr_entry_addr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_wr_entry_addr_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_secsid_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_secsid_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_sid_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_sid_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_ssid_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_ssid_END (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_ssidv_START (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_UPD_ssidv_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int operation : 8;
        unsigned int sid : 6;
        unsigned int reserved_0: 2;
        unsigned int ssid : 6;
        unsigned int reserved_1: 2;
        unsigned int range : 5;
        unsigned int inv_state : 2;
        unsigned int reserved_2: 1;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_operation_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_operation_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_sid_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_sid_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_ssid_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_ssid_END (21)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_range_START (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_range_END (28)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_inv_state_START (29)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_INV_inv_state_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CC_FOR_OTHER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_addr : 16;
        unsigned int wc_rd : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_IN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_IN_wc_addr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_IN_wc_addr_END (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_IN_wc_rd_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_IN_wc_rd_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_rdata_0 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_0_wc_rdata_0_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_0_wc_rdata_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_rdata_1 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_1_wc_rdata_1_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_1_wc_rdata_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_rdata_2 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_2_wc_rdata_2_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_2_wc_rdata_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_rdata_3 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_3_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_3_wc_rdata_3_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_PORT_OUT_3_wc_rdata_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_lkp_0 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_LKP_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_LKP_0_wc_lkp_0_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_LKP_0_wc_lkp_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_lkp_1 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_LKP_1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_LKP_1_wc_lkp_1_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_LKP_1_wc_lkp_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_upd_0 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_UPD_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_UPD_0_wc_upd_0_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_UPD_0_wc_upd_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_upd_1 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_UPD_1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_UPD_1_wc_upd_1_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_UPD_1_wc_upd_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_inv_0 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_INV_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_INV_0_wc_inv_0_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_INV_0_wc_inv_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_inv_1 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_INV_1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_INV_1_wc_inv_1_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_INV_1_wc_inv_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_WC_FOR_OTHER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_cu_addr : 6;
        unsigned int dbg_cfg_cu_rd : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CU_IN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CU_IN_dbg_cfg_cu_addr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CU_IN_dbg_cfg_cu_addr_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CU_IN_dbg_cfg_cu_rd_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CU_IN_dbg_cfg_cu_rd_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_tmu_cu_status_0 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_0_dbg_cfg_tmu_cu_status_0_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_0_dbg_cfg_tmu_cu_status_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_tmu_cu_status_1 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_1_dbg_cfg_tmu_cu_status_1_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_1_dbg_cfg_tmu_cu_status_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_tmu_cu_status_2 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_2_dbg_cfg_tmu_cu_status_2_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_2_dbg_cfg_tmu_cu_status_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_tmu_cu_status_3 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_3_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_3_dbg_cfg_tmu_cu_status_3_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_3_dbg_cfg_tmu_cu_status_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_tmu_cu_status_4 : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_4_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_4_dbg_cfg_tmu_cu_status_4_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_TMU_CU_STATUS_4_dbg_cfg_tmu_cu_status_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_cmu_rd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_IN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_IN_dbg_cfg_cmu_rd_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_IN_dbg_cfg_cmu_rd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cur_cmdq_state : 4;
        unsigned int cur_cmdq_sec : 1;
        unsigned int ill : 1;
        unsigned int err : 1;
        unsigned int cmdq_full : 2;
        unsigned int cmdq_empty : 2;
        unsigned int cmdq_ovflow : 2;
        unsigned int cmd_axi_rd_err : 1;
        unsigned int cmd_ignore : 1;
        unsigned int cmd_to_sync : 1;
        unsigned int cmd_to_inv : 1;
        unsigned int cmd_to_trb : 1;
        unsigned int cmd_to_pref : 1;
        unsigned int reserved : 13;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cur_cmdq_state_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cur_cmdq_state_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cur_cmdq_sec_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cur_cmdq_sec_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_ill_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_ill_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_err_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_err_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmdq_full_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmdq_full_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmdq_empty_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmdq_empty_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmdq_ovflow_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmdq_ovflow_END (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_axi_rd_err_START (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_axi_rd_err_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_ignore_START (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_ignore_END (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_to_sync_START (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_to_sync_END (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_to_inv_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_to_inv_END (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_to_trb_START (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_to_trb_END (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_to_pref_START (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_STATUS_cmd_to_pref_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ardomain : 2;
        unsigned int arport : 3;
        unsigned int arcache : 4;
        unsigned int rresp : 2;
        unsigned int rlast : 1;
        unsigned int cmd_opcode : 8;
        unsigned int reserved : 12;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_ardomain_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_ardomain_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_arport_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_arport_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_arcache_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_arcache_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_rresp_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_rresp_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_rlast_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_rlast_END (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_cmd_opcode_START (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA0_cmd_opcode_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA1_araddr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA1_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_err_stall : 2;
        unsigned int event_no_err_ack : 2;
        unsigned int araddr : 28;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA2_cmdq_err_stall_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA2_cmdq_err_stall_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA2_event_no_err_ack_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA2_event_no_err_ack_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA2_araddr_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA2_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_CMU_DATA3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_inv_rd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_IN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_IN_dbg_cfg_inv_rd_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_IN_dbg_cfg_inv_rd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inv_dec_fsm_cur_state : 4;
        unsigned int inv_tmu_vld : 1;
        unsigned int inv_cc_vld : 1;
        unsigned int inv_wc_vld : 1;
        unsigned int sync_dec_fsm_cur_state : 3;
        unsigned int inv_flag : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_inv_dec_fsm_cur_state_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_inv_dec_fsm_cur_state_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_inv_tmu_vld_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_inv_tmu_vld_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_inv_cc_vld_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_inv_cc_vld_END (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_inv_wc_vld_START (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_inv_wc_vld_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_sync_dec_fsm_cur_state_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_sync_dec_fsm_cur_state_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_inv_flag_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_STATUS_inv_flag_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int operation : 8;
        unsigned int inc_aset1 : 1;
        unsigned int leaf : 1;
        unsigned int ssid : 6;
        unsigned int vmid : 8;
        unsigned int asid : 8;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_operation_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_operation_END (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_inc_aset1_START (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_inc_aset1_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_leaf_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_leaf_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_ssid_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_ssid_END (15)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_vmid_START (16)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_vmid_END (23)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_asid_START (24)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA0_asid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int va : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA1_va_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA1_va_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int range : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA2_range_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA2_range_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int init_inv_req_vld : 1;
        unsigned int lp_inv_req_vld : 1;
        unsigned int cfg_req_inv_vld : 1;
        unsigned int cmu_req_inv_vld : 1;
        unsigned int cfg_req_sync_vld : 1;
        unsigned int cmu_req_sync_vld : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_init_inv_req_vld_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_init_inv_req_vld_END (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_lp_inv_req_vld_START (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_lp_inv_req_vld_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_cfg_req_inv_vld_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_cfg_req_inv_vld_END (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_cmu_req_inv_vld_START (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_cmu_req_inv_vld_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_cfg_req_sync_vld_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_cfg_req_sync_vld_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_cmu_req_sync_vld_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_INV_DATA3_cmu_req_sync_vld_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_diu_rd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_IN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_IN_dbg_cfg_diu_rd_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_IN_dbg_cfg_diu_rd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbu_condis_ack_vld_vec : 14;
        unsigned int tbu_ack_id : 4;
        unsigned int tbu_condis_ack_lock : 14;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA0_tbu_condis_ack_vld_vec_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA0_tbu_condis_ack_vld_vec_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA0_tbu_ack_id_START (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA0_tbu_ack_id_END (17)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA0_tbu_condis_ack_lock_START (18)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA0_tbu_condis_ack_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inv_brc_req_vec : 14;
        unsigned int inv_brc_ack_vec : 14;
        unsigned int inv_brc_dest : 4;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA1_inv_brc_req_vec_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA1_inv_brc_req_vec_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA1_inv_brc_ack_vec_START (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA1_inv_brc_ack_vec_END (27)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA1_inv_brc_dest_START (28)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA1_inv_brc_dest_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inv_brc_req_vec : 14;
        unsigned int inv_brc_ack_vec : 14;
        unsigned int sync_brc_dest : 4;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA2_inv_brc_req_vec_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA2_inv_brc_req_vec_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA2_inv_brc_ack_vec_START (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA2_inv_brc_ack_vec_END (27)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA2_sync_brc_dest_START (28)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA2_sync_brc_dest_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dti_uip_req_vec : 5;
        unsigned int dti_up_gnt_vec : 5;
        unsigned int dti_up_req_lock : 5;
        unsigned int reserved : 17;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA3_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA3_dti_uip_req_vec_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA3_dti_uip_req_vec_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA3_dti_up_gnt_vec_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA3_dti_up_gnt_vec_END (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA3_dti_up_req_lock_START (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_DIU_DATA3_dti_up_req_lock_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_event_rd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_IN_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_IN_dbg_cfg_event_rd_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_IN_dbg_cfg_event_rd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cur_event_state : 4;
        unsigned int cur_event_sec : 1;
        unsigned int event_full : 2;
        unsigned int event_empty : 2;
        unsigned int event_ovflow : 2;
        unsigned int event_qiu_aw_vld : 1;
        unsigned int event_qiu_aw_rdy : 1;
        unsigned int event_qiu_w_vld : 1;
        unsigned int event_qiu_w_rdy : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_cur_event_state_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_cur_event_state_END (3)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_cur_event_sec_START (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_cur_event_sec_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_full_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_full_END (6)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_empty_START (7)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_empty_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_ovflow_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_ovflow_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_qiu_aw_vld_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_qiu_aw_vld_END (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_qiu_aw_rdy_START (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_qiu_aw_rdy_END (12)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_qiu_w_vld_START (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_qiu_w_vld_END (13)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_qiu_w_rdy_START (14)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_STATUS_event_qiu_w_rdy_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awdomain : 2;
        unsigned int awport : 3;
        unsigned int awcache : 4;
        unsigned int resp : 2;
        unsigned int event_number : 8;
        unsigned int reserved : 13;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_awdomain_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_awdomain_END (1)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_awport_START (2)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_awport_END (4)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_awcache_START (5)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_awcache_END (8)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_resp_START (9)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_resp_END (10)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_event_number_START (11)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA0_event_number_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA1_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA1_araddr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA1_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA2_UNION;
#endif
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA2_araddr_START (0)
#define SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA2_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUv3_TCU_SMMU_TCU_DBG_EVENT_DATA3_UNION;
#endif
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
