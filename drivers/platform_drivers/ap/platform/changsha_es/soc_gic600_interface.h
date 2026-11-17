#ifndef __SOC_GIC600_INTERFACE_H__
#define __SOC_GIC600_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_GIC600_GICD_CTLR_ADDR(base) ((base) + (0x0000UL))
#define SOC_GIC600_GICD_TYPER_ADDR(base) ((base) + (0x0004UL))
#define SOC_GIC600_GICD_IIDR_ADDR(base) ((base) + (0x0008UL))
#define SOC_GIC600_GICD_FCTLR_ADDR(base) ((base) + (0x0020UL))
#define SOC_GIC600_GICD_SAC_ADDR(base) ((base) + (0x0024UL))
#define SOC_GIC600_GICD_SETSPI_NSR_ADDR(base) ((base) + (0x0040UL))
#define SOC_GIC600_GICD_CLRSPI_NSR_ADDR(base) ((base) + (0x0048UL))
#define SOC_GIC600_GICD_SETSPI_SR_ADDR(base) ((base) + (0x0050UL))
#define SOC_GIC600_GICD_CLRSPI_SR_ADDR(base) ((base) + (0x0058UL))
#define SOC_GIC600_GICD_IGROUPRn_ADDR(base,N) ((base) + (0x0080+(4*(N))))
#define SOC_GIC600_GICD_ISENABLERn_ADDR(base,N) ((base) + (0x0100+(4*(N))))
#define SOC_GIC600_GICD_ICENABLERn_ADDR(base,N) ((base) + (0x0180+(4*(N))))
#define SOC_GIC600_GICD_ISPENDRn_ADDR(base,N) ((base) + (0x0200+(4*(N))))
#define SOC_GIC600_GICD_ICPENDRn_ADDR(base,N) ((base) + (0x0280+(4*(N))))
#define SOC_GIC600_GICD_ISACTIVERn_ADDR(base,N) ((base) + (0x0300+(4*(N))))
#define SOC_GIC600_GICD_ICACTIVERn_ADDR(base,N) ((base) + (0x0380+(4*(N))))
#define SOC_GIC600_GICD_IPRIORITYRn_ADDR(base,N) ((base) + (0x0400+(4*(N))))
#define SOC_GIC600_GICD_ICFGRn_ADDR(base,N) ((base) + (0x0C00+(4*(N))))
#define SOC_GIC600_GICD_IGRPMODRn_ADDR(base,N) ((base) + (0x0D00+(4*(N))))
#define SOC_GIC600_GICD_NSACRn_ADDR(base,N) ((base) + (0x0E00+(4*(N))))
#define SOC_GIC600_GICD_IROUTERN_ADDR(base,N) ((base) + (0x6100+(8*(N))))
#define SOC_GIC600_GICD_CHIPSR_ADDR(base) ((base) + (0xC000UL))
#define SOC_GIC600_GICD_DCHIPR_ADDR(base) ((base) + (0xC004UL))
#define SOC_GIC600_GICD_CHIPR0_ADDR(base) ((base) + (0xC008UL))
#define SOC_GIC600_GICD_CHIPR1_ADDR(base) ((base) + (0xC010UL))
#define SOC_GIC600_GICD_IERRRn_ADDR(base,N) ((base) + (0xE108+(4*(N))))
#define SOC_GIC600_GICD_CFGID_ADDR(base) ((base) + (0xF000UL))
#define SOC_GIC600_GICD_PIDR4_ADDR(base) ((base) + (0xFFD0UL))
#define SOC_GIC600_GICD_PIDR5_ADDR(base) ((base) + (0xFFD4UL))
#define SOC_GIC600_GICD_PIDR6_ADDR(base) ((base) + (0xFFD8UL))
#define SOC_GIC600_GICD_PIDR7_ADDR(base) ((base) + (0xFFDCUL))
#define SOC_GIC600_GICD_PIDR0_ADDR(base) ((base) + (0xFFE0UL))
#define SOC_GIC600_GICD_PIDR1_ADDR(base) ((base) + (0xFFE4UL))
#define SOC_GIC600_GICD_PIDR2_ADDR(base) ((base) + (0xFFE8UL))
#define SOC_GIC600_GICD_PIDR3_ADDR(base) ((base) + (0xFFECUL))
#define SOC_GIC600_GICD_CIDR0_ADDR(base) ((base) + (0xFFF0UL))
#define SOC_GIC600_GICD_CIDR1_ADDR(base) ((base) + (0xFFF4UL))
#define SOC_GIC600_GICD_CIDR2_ADDR(base) ((base) + (0xFFF8UL))
#define SOC_GIC600_GICD_CIDR3_ADDR(base) ((base) + (0xFFFCUL))
#define SOC_GIC600_GICA_SETSPI_NSR_ADDR(base) ((base) + (0x00010040UL))
#define SOC_GIC600_GICA_CLRSPI_NSR_ADDR(base) ((base) + (0x00010048UL))
#define SOC_GIC600_GICA_SETSPI_SR_ADDR(base) ((base) + (0x00010050UL))
#define SOC_GIC600_GICA_CLRSPI_SR_ADDR(base) ((base) + (0x00010058UL))
#define SOC_GIC600_GITS_CTLR_ADDR(base) ((base) + (0x00040000UL))
#define SOC_GIC600_GITS_IIDR_ADDR(base) ((base) + (0x00040004UL))
#define SOC_GIC600_GITS_TYPER_ADDR(base) ((base) + (0x00040008UL))
#define SOC_GIC600_GITS_FCTLR_ADDR(base) ((base) + (0x00040020UL))
#define SOC_GIC600_GITS_OPR_ADDR(base) ((base) + (0x00040028UL))
#define SOC_GIC600_GITS_OPSR_ADDR(base) ((base) + (0x00040030UL))
#define SOC_GIC600_GITS_CBASER_ADDR(base) ((base) + (0x00040080UL))
#define SOC_GIC600_GITS_CWRITER_ADDR(base) ((base) + (0x00040088UL))
#define SOC_GIC600_GITS_CREADR_ADDR(base) ((base) + (0x00040090UL))
#define SOC_GIC600_GITS_BASER0_ADDR(base) ((base) + (0x00040100UL))
#define SOC_GIC600_GITS_BASER1_ADDR(base) ((base) + (0x00040108UL))
#define SOC_GIC600_GITS_CFGID_ADDR(base) ((base) + (0x0004F000UL))
#define SOC_GIC600_GITS_PIDR4_ADDR(base) ((base) + (0x0004FFD0UL))
#define SOC_GIC600_GITS_PIDR5_ADDR(base) ((base) + (0x0004FFD4UL))
#define SOC_GIC600_GITS_PIDR6_ADDR(base) ((base) + (0x0004FFD8UL))
#define SOC_GIC600_GITS_PIDR7_ADDR(base) ((base) + (0x0004FFDCUL))
#define SOC_GIC600_GITS_PIDR0_ADDR(base) ((base) + (0x0004FFE0UL))
#define SOC_GIC600_GITS_PIDR1_ADDR(base) ((base) + (0x0004FFE4UL))
#define SOC_GIC600_GITS_PIDR2_ADDR(base) ((base) + (0x0004FFE8UL))
#define SOC_GIC600_GITS_PIDR3_ADDR(base) ((base) + (0x0004FFECUL))
#define SOC_GIC600_GITS_CIDR0_ADDR(base) ((base) + (0x0004FFF0UL))
#define SOC_GIC600_GITS_CIDR1_ADDR(base) ((base) + (0x0004FFF4UL))
#define SOC_GIC600_GITS_CIDR2_ADDR(base) ((base) + (0x0004FFF8UL))
#define SOC_GIC600_GITS_CIDR3_ADDR(base) ((base) + (0x0004FFFCUL))
#define SOC_GIC600_GITS_TRANSLATER_ADDR(base) ((base) + (0x00050040UL))
#define SOC_GIC600_GICR_CTLR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0000UL))
#define SOC_GIC600_GICR_IIDR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0004UL))
#define SOC_GIC600_GICR_TYPER_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0008UL))
#define SOC_GIC600_GICR_WAKER_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0014UL))
#define SOC_GIC600_GICR_FCTLR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0020UL))
#define SOC_GIC600_GICR_PWRR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0024UL))
#define SOC_GIC600_GICR_CLASS_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0028UL))
#define SOC_GIC600_GICR_PROPBASER_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0070UL))
#define SOC_GIC600_GICR_PENDBASER_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0078UL))
#define SOC_GIC600_GICR_PIDR4_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFD0UL))
#define SOC_GIC600_GICR_PIDR5_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFD4UL))
#define SOC_GIC600_GICR_PIDR6_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFD8UL))
#define SOC_GIC600_GICR_PIDR7_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFDCUL))
#define SOC_GIC600_GICR_PIDR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFE0UL))
#define SOC_GIC600_GICR_PIDR1_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFE4UL))
#define SOC_GIC600_GICR_PIDR2_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFE8UL))
#define SOC_GIC600_GICR_PIDR3_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFECUL))
#define SOC_GIC600_GICR_CIDR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFF0UL))
#define SOC_GIC600_GICR_CIDR1_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFF4UL))
#define SOC_GIC600_GICR_CIDR2_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFF8UL))
#define SOC_GIC600_GICR_CIDR3_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFFCUL))
#define SOC_GIC600_GICR_IGROUPR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0080UL))
#define SOC_GIC600_GICR_ISENABLER0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0100UL))
#define SOC_GIC600_GICR_ICENABLER0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0180UL))
#define SOC_GIC600_GICR_ISPENDR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0200UL))
#define SOC_GIC600_GICR_ICPENDR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0280UL))
#define SOC_GIC600_GICR_ISACTIVER0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0300UL))
#define SOC_GIC600_GICR_ICACTIVER0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0380UL))
#define SOC_GIC600_GICR_IPRIORITYRn_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0400UL))
#define SOC_GIC600_GICR_ICFGR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0C00UL))
#define SOC_GIC600_GICR_ICFGR1_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0C04UL))
#define SOC_GIC600_GICR_IGRPMODR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0D00UL))
#define SOC_GIC600_GICR_NSACR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0E00UL))
#define SOC_GIC600_GICR_MISCSTATUSR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0xC000UL))
#define SOC_GIC600_GICR_IERRVR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0xC008UL))
#define SOC_GIC600_GICR_CFGID0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0xF000UL))
#define SOC_GIC600_GICR_CFGID1_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0xF004UL))
#else
#define SOC_GIC600_GICD_CTLR_ADDR(base) ((base) + (0x0000))
#define SOC_GIC600_GICD_TYPER_ADDR(base) ((base) + (0x0004))
#define SOC_GIC600_GICD_IIDR_ADDR(base) ((base) + (0x0008))
#define SOC_GIC600_GICD_FCTLR_ADDR(base) ((base) + (0x0020))
#define SOC_GIC600_GICD_SAC_ADDR(base) ((base) + (0x0024))
#define SOC_GIC600_GICD_SETSPI_NSR_ADDR(base) ((base) + (0x0040))
#define SOC_GIC600_GICD_CLRSPI_NSR_ADDR(base) ((base) + (0x0048))
#define SOC_GIC600_GICD_SETSPI_SR_ADDR(base) ((base) + (0x0050))
#define SOC_GIC600_GICD_CLRSPI_SR_ADDR(base) ((base) + (0x0058))
#define SOC_GIC600_GICD_IGROUPRn_ADDR(base,N) ((base) + (0x0080+(4*(N))))
#define SOC_GIC600_GICD_ISENABLERn_ADDR(base,N) ((base) + (0x0100+(4*(N))))
#define SOC_GIC600_GICD_ICENABLERn_ADDR(base,N) ((base) + (0x0180+(4*(N))))
#define SOC_GIC600_GICD_ISPENDRn_ADDR(base,N) ((base) + (0x0200+(4*(N))))
#define SOC_GIC600_GICD_ICPENDRn_ADDR(base,N) ((base) + (0x0280+(4*(N))))
#define SOC_GIC600_GICD_ISACTIVERn_ADDR(base,N) ((base) + (0x0300+(4*(N))))
#define SOC_GIC600_GICD_ICACTIVERn_ADDR(base,N) ((base) + (0x0380+(4*(N))))
#define SOC_GIC600_GICD_IPRIORITYRn_ADDR(base,N) ((base) + (0x0400+(4*(N))))
#define SOC_GIC600_GICD_ICFGRn_ADDR(base,N) ((base) + (0x0C00+(4*(N))))
#define SOC_GIC600_GICD_IGRPMODRn_ADDR(base,N) ((base) + (0x0D00+(4*(N))))
#define SOC_GIC600_GICD_NSACRn_ADDR(base,N) ((base) + (0x0E00+(4*(N))))
#define SOC_GIC600_GICD_IROUTERN_ADDR(base,N) ((base) + (0x6100+(8*(N))))
#define SOC_GIC600_GICD_CHIPSR_ADDR(base) ((base) + (0xC000))
#define SOC_GIC600_GICD_DCHIPR_ADDR(base) ((base) + (0xC004))
#define SOC_GIC600_GICD_CHIPR0_ADDR(base) ((base) + (0xC008))
#define SOC_GIC600_GICD_CHIPR1_ADDR(base) ((base) + (0xC010))
#define SOC_GIC600_GICD_IERRRn_ADDR(base,N) ((base) + (0xE108+(4*(N))))
#define SOC_GIC600_GICD_CFGID_ADDR(base) ((base) + (0xF000))
#define SOC_GIC600_GICD_PIDR4_ADDR(base) ((base) + (0xFFD0))
#define SOC_GIC600_GICD_PIDR5_ADDR(base) ((base) + (0xFFD4))
#define SOC_GIC600_GICD_PIDR6_ADDR(base) ((base) + (0xFFD8))
#define SOC_GIC600_GICD_PIDR7_ADDR(base) ((base) + (0xFFDC))
#define SOC_GIC600_GICD_PIDR0_ADDR(base) ((base) + (0xFFE0))
#define SOC_GIC600_GICD_PIDR1_ADDR(base) ((base) + (0xFFE4))
#define SOC_GIC600_GICD_PIDR2_ADDR(base) ((base) + (0xFFE8))
#define SOC_GIC600_GICD_PIDR3_ADDR(base) ((base) + (0xFFEC))
#define SOC_GIC600_GICD_CIDR0_ADDR(base) ((base) + (0xFFF0))
#define SOC_GIC600_GICD_CIDR1_ADDR(base) ((base) + (0xFFF4))
#define SOC_GIC600_GICD_CIDR2_ADDR(base) ((base) + (0xFFF8))
#define SOC_GIC600_GICD_CIDR3_ADDR(base) ((base) + (0xFFFC))
#define SOC_GIC600_GICA_SETSPI_NSR_ADDR(base) ((base) + (0x00010040))
#define SOC_GIC600_GICA_CLRSPI_NSR_ADDR(base) ((base) + (0x00010048))
#define SOC_GIC600_GICA_SETSPI_SR_ADDR(base) ((base) + (0x00010050))
#define SOC_GIC600_GICA_CLRSPI_SR_ADDR(base) ((base) + (0x00010058))
#define SOC_GIC600_GITS_CTLR_ADDR(base) ((base) + (0x00040000))
#define SOC_GIC600_GITS_IIDR_ADDR(base) ((base) + (0x00040004))
#define SOC_GIC600_GITS_TYPER_ADDR(base) ((base) + (0x00040008))
#define SOC_GIC600_GITS_FCTLR_ADDR(base) ((base) + (0x00040020))
#define SOC_GIC600_GITS_OPR_ADDR(base) ((base) + (0x00040028))
#define SOC_GIC600_GITS_OPSR_ADDR(base) ((base) + (0x00040030))
#define SOC_GIC600_GITS_CBASER_ADDR(base) ((base) + (0x00040080))
#define SOC_GIC600_GITS_CWRITER_ADDR(base) ((base) + (0x00040088))
#define SOC_GIC600_GITS_CREADR_ADDR(base) ((base) + (0x00040090))
#define SOC_GIC600_GITS_BASER0_ADDR(base) ((base) + (0x00040100))
#define SOC_GIC600_GITS_BASER1_ADDR(base) ((base) + (0x00040108))
#define SOC_GIC600_GITS_CFGID_ADDR(base) ((base) + (0x0004F000))
#define SOC_GIC600_GITS_PIDR4_ADDR(base) ((base) + (0x0004FFD0))
#define SOC_GIC600_GITS_PIDR5_ADDR(base) ((base) + (0x0004FFD4))
#define SOC_GIC600_GITS_PIDR6_ADDR(base) ((base) + (0x0004FFD8))
#define SOC_GIC600_GITS_PIDR7_ADDR(base) ((base) + (0x0004FFDC))
#define SOC_GIC600_GITS_PIDR0_ADDR(base) ((base) + (0x0004FFE0))
#define SOC_GIC600_GITS_PIDR1_ADDR(base) ((base) + (0x0004FFE4))
#define SOC_GIC600_GITS_PIDR2_ADDR(base) ((base) + (0x0004FFE8))
#define SOC_GIC600_GITS_PIDR3_ADDR(base) ((base) + (0x0004FFEC))
#define SOC_GIC600_GITS_CIDR0_ADDR(base) ((base) + (0x0004FFF0))
#define SOC_GIC600_GITS_CIDR1_ADDR(base) ((base) + (0x0004FFF4))
#define SOC_GIC600_GITS_CIDR2_ADDR(base) ((base) + (0x0004FFF8))
#define SOC_GIC600_GITS_CIDR3_ADDR(base) ((base) + (0x0004FFFC))
#define SOC_GIC600_GITS_TRANSLATER_ADDR(base) ((base) + (0x00050040))
#define SOC_GIC600_GICR_CTLR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0000))
#define SOC_GIC600_GICR_IIDR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0004))
#define SOC_GIC600_GICR_TYPER_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0008))
#define SOC_GIC600_GICR_WAKER_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0014))
#define SOC_GIC600_GICR_FCTLR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0020))
#define SOC_GIC600_GICR_PWRR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0024))
#define SOC_GIC600_GICR_CLASS_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0028))
#define SOC_GIC600_GICR_PROPBASER_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0070))
#define SOC_GIC600_GICR_PENDBASER_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0x0078))
#define SOC_GIC600_GICR_PIDR4_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFD0))
#define SOC_GIC600_GICR_PIDR5_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFD4))
#define SOC_GIC600_GICR_PIDR6_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFD8))
#define SOC_GIC600_GICR_PIDR7_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFDC))
#define SOC_GIC600_GICR_PIDR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFE0))
#define SOC_GIC600_GICR_PIDR1_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFE4))
#define SOC_GIC600_GICR_PIDR2_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFE8))
#define SOC_GIC600_GICR_PIDR3_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFEC))
#define SOC_GIC600_GICR_CIDR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFF0))
#define SOC_GIC600_GICR_CIDR1_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFF4))
#define SOC_GIC600_GICR_CIDR2_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFF8))
#define SOC_GIC600_GICR_CIDR3_ADDR(base,RDnum) ((base) + ((((RDnum)*2+6)*0x00010000)+0xFFFC))
#define SOC_GIC600_GICR_IGROUPR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0080))
#define SOC_GIC600_GICR_ISENABLER0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0100))
#define SOC_GIC600_GICR_ICENABLER0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0180))
#define SOC_GIC600_GICR_ISPENDR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0200))
#define SOC_GIC600_GICR_ICPENDR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0280))
#define SOC_GIC600_GICR_ISACTIVER0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0300))
#define SOC_GIC600_GICR_ICACTIVER0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0380))
#define SOC_GIC600_GICR_IPRIORITYRn_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0400))
#define SOC_GIC600_GICR_ICFGR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0C00))
#define SOC_GIC600_GICR_ICFGR1_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0C04))
#define SOC_GIC600_GICR_IGRPMODR0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0D00))
#define SOC_GIC600_GICR_NSACR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0x0E00))
#define SOC_GIC600_GICR_MISCSTATUSR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0xC000))
#define SOC_GIC600_GICR_IERRVR_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0xC008))
#define SOC_GIC600_GICR_CFGID0_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0xF000))
#define SOC_GIC600_GICR_CFGID1_ADDR(base,RDnum) ((base) + ((((RDnum)*2+7)*0x00010000)+0xF004))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EnableGrp0 : 1;
        unsigned int EnableGrp1NS : 1;
        unsigned int EnableGrp1S : 1;
        unsigned int reserved_0 : 1;
        unsigned int ARE_S : 1;
        unsigned int ARE_NS : 1;
        unsigned int DS : 1;
        unsigned int E1NWF : 1;
        unsigned int reserved_1 : 23;
        unsigned int RWP : 1;
    } reg;
} SOC_GIC600_GICD_CTLR_UNION;
#endif
#define SOC_GIC600_GICD_CTLR_EnableGrp0_START (0)
#define SOC_GIC600_GICD_CTLR_EnableGrp0_END (0)
#define SOC_GIC600_GICD_CTLR_EnableGrp1NS_START (1)
#define SOC_GIC600_GICD_CTLR_EnableGrp1NS_END (1)
#define SOC_GIC600_GICD_CTLR_EnableGrp1S_START (2)
#define SOC_GIC600_GICD_CTLR_EnableGrp1S_END (2)
#define SOC_GIC600_GICD_CTLR_ARE_S_START (4)
#define SOC_GIC600_GICD_CTLR_ARE_S_END (4)
#define SOC_GIC600_GICD_CTLR_ARE_NS_START (5)
#define SOC_GIC600_GICD_CTLR_ARE_NS_END (5)
#define SOC_GIC600_GICD_CTLR_DS_START (6)
#define SOC_GIC600_GICD_CTLR_DS_END (6)
#define SOC_GIC600_GICD_CTLR_E1NWF_START (7)
#define SOC_GIC600_GICD_CTLR_E1NWF_END (7)
#define SOC_GIC600_GICD_CTLR_RWP_START (31)
#define SOC_GIC600_GICD_CTLR_RWP_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ITLinesNumber : 5;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 2;
        unsigned int SecurityExtn : 1;
        unsigned int reserved_2 : 5;
        unsigned int MBIS : 1;
        unsigned int LPIS : 1;
        unsigned int DVIS : 1;
        unsigned int Idbits : 5;
        unsigned int A3V : 1;
        unsigned int No1N : 1;
        unsigned int reserved_3 : 6;
    } reg;
} SOC_GIC600_GICD_TYPER_UNION;
#endif
#define SOC_GIC600_GICD_TYPER_ITLinesNumber_START (0)
#define SOC_GIC600_GICD_TYPER_ITLinesNumber_END (4)
#define SOC_GIC600_GICD_TYPER_SecurityExtn_START (10)
#define SOC_GIC600_GICD_TYPER_SecurityExtn_END (10)
#define SOC_GIC600_GICD_TYPER_MBIS_START (16)
#define SOC_GIC600_GICD_TYPER_MBIS_END (16)
#define SOC_GIC600_GICD_TYPER_LPIS_START (17)
#define SOC_GIC600_GICD_TYPER_LPIS_END (17)
#define SOC_GIC600_GICD_TYPER_DVIS_START (18)
#define SOC_GIC600_GICD_TYPER_DVIS_END (18)
#define SOC_GIC600_GICD_TYPER_Idbits_START (19)
#define SOC_GIC600_GICD_TYPER_Idbits_END (23)
#define SOC_GIC600_GICD_TYPER_A3V_START (24)
#define SOC_GIC600_GICD_TYPER_A3V_END (24)
#define SOC_GIC600_GICD_TYPER_No1N_START (25)
#define SOC_GIC600_GICD_TYPER_No1N_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer : 12;
        unsigned int Revision : 4;
        unsigned int Variant : 4;
        unsigned int reserved : 4;
        unsigned int ProductID : 8;
    } reg;
} SOC_GIC600_GICD_IIDR_UNION;
#endif
#define SOC_GIC600_GICD_IIDR_Implementer_START (0)
#define SOC_GIC600_GICD_IIDR_Implementer_END (11)
#define SOC_GIC600_GICD_IIDR_Revision_START (12)
#define SOC_GIC600_GICD_IIDR_Revision_END (15)
#define SOC_GIC600_GICD_IIDR_Variant_START (16)
#define SOC_GIC600_GICD_IIDR_Variant_END (19)
#define SOC_GIC600_GICD_IIDR_ProductID_START (24)
#define SOC_GIC600_GICD_IIDR_ProductID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SIP : 1;
        unsigned int reserved_0: 3;
        unsigned int CGO : 10;
        unsigned int reserved_1: 2;
        unsigned int NSACR : 2;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 2;
        unsigned int DCC : 1;
        unsigned int reserved_4: 3;
        unsigned int QDENY : 1;
        unsigned int POS : 1;
        unsigned int reserved_5: 2;
        unsigned int reserved_6: 3;
    } reg;
} SOC_GIC600_GICD_FCTLR_UNION;
#endif
#define SOC_GIC600_GICD_FCTLR_SIP_START (0)
#define SOC_GIC600_GICD_FCTLR_SIP_END (0)
#define SOC_GIC600_GICD_FCTLR_CGO_START (4)
#define SOC_GIC600_GICD_FCTLR_CGO_END (13)
#define SOC_GIC600_GICD_FCTLR_NSACR_START (16)
#define SOC_GIC600_GICD_FCTLR_NSACR_END (17)
#define SOC_GIC600_GICD_FCTLR_DCC_START (21)
#define SOC_GIC600_GICD_FCTLR_DCC_END (21)
#define SOC_GIC600_GICD_FCTLR_QDENY_START (25)
#define SOC_GIC600_GICD_FCTLR_QDENY_END (25)
#define SOC_GIC600_GICD_FCTLR_POS_START (26)
#define SOC_GIC600_GICD_FCTLR_POS_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DSL : 1;
        unsigned int GICTNS : 1;
        unsigned int GICPNS : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_GIC600_GICD_SAC_UNION;
#endif
#define SOC_GIC600_GICD_SAC_DSL_START (0)
#define SOC_GIC600_GICD_SAC_DSL_END (0)
#define SOC_GIC600_GICD_SAC_GICTNS_START (1)
#define SOC_GIC600_GICD_SAC_GICTNS_END (1)
#define SOC_GIC600_GICD_SAC_GICPNS_START (2)
#define SOC_GIC600_GICD_SAC_GICPNS_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INTID_set_ns : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_GIC600_GICD_SETSPI_NSR_UNION;
#endif
#define SOC_GIC600_GICD_SETSPI_NSR_INTID_set_ns_START (0)
#define SOC_GIC600_GICD_SETSPI_NSR_INTID_set_ns_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INTID_clr_ns : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_GIC600_GICD_CLRSPI_NSR_UNION;
#endif
#define SOC_GIC600_GICD_CLRSPI_NSR_INTID_clr_ns_START (0)
#define SOC_GIC600_GICD_CLRSPI_NSR_INTID_clr_ns_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INTID_set_s : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_GIC600_GICD_SETSPI_SR_UNION;
#endif
#define SOC_GIC600_GICD_SETSPI_SR_INTID_set_s_START (0)
#define SOC_GIC600_GICD_SETSPI_SR_INTID_set_s_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INTID_clr_s : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_GIC600_GICD_CLRSPI_SR_UNION;
#endif
#define SOC_GIC600_GICD_CLRSPI_SR_INTID_clr_s_START (0)
#define SOC_GIC600_GICD_CLRSPI_SR_INTID_clr_s_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int groupstatus : 32;
    } reg;
} SOC_GIC600_GICD_IGROUPRn_UNION;
#endif
#define SOC_GIC600_GICD_IGROUPRn_groupstatus_START (0)
#define SOC_GIC600_GICD_IGROUPRn_groupstatus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int setenable : 32;
    } reg;
} SOC_GIC600_GICD_ISENABLERn_UNION;
#endif
#define SOC_GIC600_GICD_ISENABLERn_setenable_START (0)
#define SOC_GIC600_GICD_ISENABLERn_setenable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clrenable : 32;
    } reg;
} SOC_GIC600_GICD_ICENABLERn_UNION;
#endif
#define SOC_GIC600_GICD_ICENABLERn_clrenable_START (0)
#define SOC_GIC600_GICD_ICENABLERn_clrenable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SetPending : 32;
    } reg;
} SOC_GIC600_GICD_ISPENDRn_UNION;
#endif
#define SOC_GIC600_GICD_ISPENDRn_SetPending_START (0)
#define SOC_GIC600_GICD_ISPENDRn_SetPending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ClearPending : 32;
    } reg;
} SOC_GIC600_GICD_ICPENDRn_UNION;
#endif
#define SOC_GIC600_GICD_ICPENDRn_ClearPending_START (0)
#define SOC_GIC600_GICD_ICPENDRn_ClearPending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SetActive : 32;
    } reg;
} SOC_GIC600_GICD_ISACTIVERn_UNION;
#endif
#define SOC_GIC600_GICD_ISACTIVERn_SetActive_START (0)
#define SOC_GIC600_GICD_ISACTIVERn_SetActive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ClearActive : 32;
    } reg;
} SOC_GIC600_GICD_ICACTIVERn_UNION;
#endif
#define SOC_GIC600_GICD_ICACTIVERn_ClearActive_START (0)
#define SOC_GIC600_GICD_ICACTIVERn_ClearActive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Priority_offset_0B : 8;
        unsigned int Priority_offset_1B : 8;
        unsigned int Priority_offset_2B : 8;
        unsigned int Priority_offset_3B : 8;
    } reg;
} SOC_GIC600_GICD_IPRIORITYRn_UNION;
#endif
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_0B_START (0)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_0B_END (7)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_1B_START (8)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_1B_END (15)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_2B_START (16)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_2B_END (23)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_3B_START (24)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int IntConfig : 32;
    } reg;
} SOC_GIC600_GICD_ICFGRn_UNION;
#endif
#define SOC_GIC600_GICD_ICFGRn_IntConfig_START (0)
#define SOC_GIC600_GICD_ICFGRn_IntConfig_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Group_modifier_bit : 32;
    } reg;
} SOC_GIC600_GICD_IGRPMODRn_UNION;
#endif
#define SOC_GIC600_GICD_IGRPMODRn_Group_modifier_bit_START (0)
#define SOC_GIC600_GICD_IGRPMODRn_Group_modifier_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ns_access : 32;
    } reg;
} SOC_GIC600_GICD_NSACRn_UNION;
#endif
#define SOC_GIC600_GICD_NSACRn_ns_access_START (0)
#define SOC_GIC600_GICD_NSACRn_ns_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long aff0 : 8;
        unsigned long long aff1 : 8;
        unsigned long long aff2 : 8;
        unsigned long long reserved_0 : 7;
        unsigned long long Interrupt_Routing_Mode : 1;
        unsigned long long aff3 : 8;
        unsigned long long reserved_1 : 24;
    } reg;
} SOC_GIC600_GICD_IROUTERN_UNION;
#endif
#define SOC_GIC600_GICD_IROUTERN_aff0_START (0)
#define SOC_GIC600_GICD_IROUTERN_aff0_END (7)
#define SOC_GIC600_GICD_IROUTERN_aff1_START (8)
#define SOC_GIC600_GICD_IROUTERN_aff1_END (15)
#define SOC_GIC600_GICD_IROUTERN_aff2_START (16)
#define SOC_GIC600_GICD_IROUTERN_aff2_END (23)
#define SOC_GIC600_GICD_IROUTERN_Interrupt_Routing_Mode_START (31)
#define SOC_GIC600_GICD_IROUTERN_Interrupt_Routing_Mode_END (31)
#define SOC_GIC600_GICD_IROUTERN_aff3_START (32)
#define SOC_GIC600_GICD_IROUTERN_aff3_END (39)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GTR : 1;
        unsigned int GTS : 1;
        unsigned int GTO : 1;
        unsigned int reserved_0: 1;
        unsigned int RTS : 2;
        unsigned int reserved_1: 26;
    } reg;
} SOC_GIC600_GICD_CHIPSR_UNION;
#endif
#define SOC_GIC600_GICD_CHIPSR_GTR_START (0)
#define SOC_GIC600_GICD_CHIPSR_GTR_END (0)
#define SOC_GIC600_GICD_CHIPSR_GTS_START (1)
#define SOC_GIC600_GICD_CHIPSR_GTS_END (1)
#define SOC_GIC600_GICD_CHIPSR_GTO_START (2)
#define SOC_GIC600_GICD_CHIPSR_GTO_END (2)
#define SOC_GIC600_GICD_CHIPSR_RTS_START (4)
#define SOC_GIC600_GICD_CHIPSR_RTS_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PUP : 1;
        unsigned int reserved_0: 3;
        unsigned int rt_owner : 4;
        unsigned int reserved_1: 24;
    } reg;
} SOC_GIC600_GICD_DCHIPR_UNION;
#endif
#define SOC_GIC600_GICD_DCHIPR_PUP_START (0)
#define SOC_GIC600_GICD_DCHIPR_PUP_END (0)
#define SOC_GIC600_GICD_DCHIPR_rt_owner_START (4)
#define SOC_GIC600_GICD_DCHIPR_rt_owner_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long SocketState : 1;
        unsigned long long PUP_CHIPR0 : 1;
        unsigned long long reserved_0 : 3;
        unsigned long long SPI_BLOCKS : 5;
        unsigned long long SPI_BLOCK_MIN : 6;
        unsigned long long ADDR : 32;
        unsigned long long reserved_1 : 16;
    } reg;
} SOC_GIC600_GICD_CHIPR0_UNION;
#endif
#define SOC_GIC600_GICD_CHIPR0_SocketState_START (0)
#define SOC_GIC600_GICD_CHIPR0_SocketState_END (0)
#define SOC_GIC600_GICD_CHIPR0_PUP_CHIPR0_START (1)
#define SOC_GIC600_GICD_CHIPR0_PUP_CHIPR0_END (1)
#define SOC_GIC600_GICD_CHIPR0_SPI_BLOCKS_START (5)
#define SOC_GIC600_GICD_CHIPR0_SPI_BLOCKS_END (9)
#define SOC_GIC600_GICD_CHIPR0_SPI_BLOCK_MIN_START (10)
#define SOC_GIC600_GICD_CHIPR0_SPI_BLOCK_MIN_END (15)
#define SOC_GIC600_GICD_CHIPR0_ADDR_START (16)
#define SOC_GIC600_GICD_CHIPR0_ADDR_END (47)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long SocketState_CHIPR1 : 1;
        unsigned long long PUP_CHIPR1 : 1;
        unsigned long long reserved_0 : 3;
        unsigned long long SPI_BLOCKS_CHIPR1 : 5;
        unsigned long long SPI_BLOCK_MIN_CHIPR1 : 6;
        unsigned long long ADDR_CHIPR1 : 32;
        unsigned long long reserved_1 : 16;
    } reg;
} SOC_GIC600_GICD_CHIPR1_UNION;
#endif
#define SOC_GIC600_GICD_CHIPR1_SocketState_CHIPR1_START (0)
#define SOC_GIC600_GICD_CHIPR1_SocketState_CHIPR1_END (0)
#define SOC_GIC600_GICD_CHIPR1_PUP_CHIPR1_START (1)
#define SOC_GIC600_GICD_CHIPR1_PUP_CHIPR1_END (1)
#define SOC_GIC600_GICD_CHIPR1_SPI_BLOCKS_CHIPR1_START (5)
#define SOC_GIC600_GICD_CHIPR1_SPI_BLOCKS_CHIPR1_END (9)
#define SOC_GIC600_GICD_CHIPR1_SPI_BLOCK_MIN_CHIPR1_START (10)
#define SOC_GIC600_GICD_CHIPR1_SPI_BLOCK_MIN_CHIPR1_END (15)
#define SOC_GIC600_GICD_CHIPR1_ADDR_CHIPR1_START (16)
#define SOC_GIC600_GICD_CHIPR1_ADDR_CHIPR1_END (47)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Status : 32;
    } reg;
} SOC_GIC600_GICD_IERRRn_UNION;
#endif
#define SOC_GIC600_GICD_IERRRn_Status_START (0)
#define SOC_GIC600_GICD_IERRRn_Status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long SO : 1;
        unsigned long long reserved_0 : 3;
        unsigned long long SNUM : 4;
        unsigned long long reserved_1 : 4;
        unsigned long long LPIS_CFGID : 1;
        unsigned long long DLPI : 1;
        unsigned long long AFSL : 1;
        unsigned long long SPIS : 6;
        unsigned long long reserved_2 : 11;
        unsigned long long AFF0 : 4;
        unsigned long long AFF1 : 4;
        unsigned long long AFF2 : 4;
        unsigned long long AFF3 : 4;
        unsigned long long PEW : 5;
        unsigned long long reserved_3 : 11;
    } reg;
} SOC_GIC600_GICD_CFGID_UNION;
#endif
#define SOC_GIC600_GICD_CFGID_SO_START (0)
#define SOC_GIC600_GICD_CFGID_SO_END (0)
#define SOC_GIC600_GICD_CFGID_SNUM_START (4)
#define SOC_GIC600_GICD_CFGID_SNUM_END (7)
#define SOC_GIC600_GICD_CFGID_LPIS_CFGID_START (12)
#define SOC_GIC600_GICD_CFGID_LPIS_CFGID_END (12)
#define SOC_GIC600_GICD_CFGID_DLPI_START (13)
#define SOC_GIC600_GICD_CFGID_DLPI_END (13)
#define SOC_GIC600_GICD_CFGID_AFSL_START (14)
#define SOC_GIC600_GICD_CFGID_AFSL_END (14)
#define SOC_GIC600_GICD_CFGID_SPIS_START (15)
#define SOC_GIC600_GICD_CFGID_SPIS_END (20)
#define SOC_GIC600_GICD_CFGID_AFF0_START (32)
#define SOC_GIC600_GICD_CFGID_AFF0_END (35)
#define SOC_GIC600_GICD_CFGID_AFF1_START (36)
#define SOC_GIC600_GICD_CFGID_AFF1_END (39)
#define SOC_GIC600_GICD_CFGID_AFF2_START (40)
#define SOC_GIC600_GICD_CFGID_AFF2_END (43)
#define SOC_GIC600_GICD_CFGID_AFF3_START (44)
#define SOC_GIC600_GICD_CFGID_AFF3_END (47)
#define SOC_GIC600_GICD_CFGID_PEW_START (48)
#define SOC_GIC600_GICD_CFGID_PEW_END (52)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DES_2 : 4;
        unsigned int SIZE : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_GIC600_GICD_PIDR4_UNION;
#endif
#define SOC_GIC600_GICD_PIDR4_DES_2_START (0)
#define SOC_GIC600_GICD_PIDR4_DES_2_END (3)
#define SOC_GIC600_GICD_PIDR4_SIZE_START (4)
#define SOC_GIC600_GICD_PIDR4_SIZE_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICD_PIDR5 : 32;
    } reg;
} SOC_GIC600_GICD_PIDR5_UNION;
#endif
#define SOC_GIC600_GICD_PIDR5_GICD_PIDR5_START (0)
#define SOC_GIC600_GICD_PIDR5_GICD_PIDR5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICD_PIDR6 : 32;
    } reg;
} SOC_GIC600_GICD_PIDR6_UNION;
#endif
#define SOC_GIC600_GICD_PIDR6_GICD_PIDR6_START (0)
#define SOC_GIC600_GICD_PIDR6_GICD_PIDR6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICD_PIDR7 : 32;
    } reg;
} SOC_GIC600_GICD_PIDR7_UNION;
#endif
#define SOC_GIC600_GICD_PIDR7_GICD_PIDR7_START (0)
#define SOC_GIC600_GICD_PIDR7_GICD_PIDR7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PART_0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_GIC600_GICD_PIDR0_UNION;
#endif
#define SOC_GIC600_GICD_PIDR0_PART_0_START (0)
#define SOC_GIC600_GICD_PIDR0_PART_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PART_1 : 4;
        unsigned int DES_0 : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_GIC600_GICD_PIDR1_UNION;
#endif
#define SOC_GIC600_GICD_PIDR1_PART_1_START (0)
#define SOC_GIC600_GICD_PIDR1_PART_1_END (3)
#define SOC_GIC600_GICD_PIDR1_DES_0_START (4)
#define SOC_GIC600_GICD_PIDR1_DES_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DES_1 : 3;
        unsigned int JEDEC : 1;
        unsigned int ArchRev : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_GIC600_GICD_PIDR2_UNION;
#endif
#define SOC_GIC600_GICD_PIDR2_DES_1_START (0)
#define SOC_GIC600_GICD_PIDR2_DES_1_END (2)
#define SOC_GIC600_GICD_PIDR2_JEDEC_START (3)
#define SOC_GIC600_GICD_PIDR2_JEDEC_END (3)
#define SOC_GIC600_GICD_PIDR2_ArchRev_START (4)
#define SOC_GIC600_GICD_PIDR2_ArchRev_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CMOD : 4;
        unsigned int REVAND : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_GIC600_GICD_PIDR3_UNION;
#endif
#define SOC_GIC600_GICD_PIDR3_CMOD_START (0)
#define SOC_GIC600_GICD_PIDR3_CMOD_END (3)
#define SOC_GIC600_GICD_PIDR3_REVAND_START (4)
#define SOC_GIC600_GICD_PIDR3_REVAND_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICD_CIDR0 : 32;
    } reg;
} SOC_GIC600_GICD_CIDR0_UNION;
#endif
#define SOC_GIC600_GICD_CIDR0_GICD_CIDR0_START (0)
#define SOC_GIC600_GICD_CIDR0_GICD_CIDR0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICD_CIDR1 : 32;
    } reg;
} SOC_GIC600_GICD_CIDR1_UNION;
#endif
#define SOC_GIC600_GICD_CIDR1_GICD_CIDR1_START (0)
#define SOC_GIC600_GICD_CIDR1_GICD_CIDR1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICD_CIDR2 : 32;
    } reg;
} SOC_GIC600_GICD_CIDR2_UNION;
#endif
#define SOC_GIC600_GICD_CIDR2_GICD_CIDR2_START (0)
#define SOC_GIC600_GICD_CIDR2_GICD_CIDR2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICD_CIDR3 : 32;
    } reg;
} SOC_GIC600_GICD_CIDR3_UNION;
#endif
#define SOC_GIC600_GICD_CIDR3_GICD_CIDR3_START (0)
#define SOC_GIC600_GICD_CIDR3_GICD_CIDR3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICA_SETSPI_NSR : 32;
    } reg;
} SOC_GIC600_GICA_SETSPI_NSR_UNION;
#endif
#define SOC_GIC600_GICA_SETSPI_NSR_GICA_SETSPI_NSR_START (0)
#define SOC_GIC600_GICA_SETSPI_NSR_GICA_SETSPI_NSR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICA_CLRSPI_NSR : 32;
    } reg;
} SOC_GIC600_GICA_CLRSPI_NSR_UNION;
#endif
#define SOC_GIC600_GICA_CLRSPI_NSR_GICA_CLRSPI_NSR_START (0)
#define SOC_GIC600_GICA_CLRSPI_NSR_GICA_CLRSPI_NSR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICA_SETSPI_SR : 32;
    } reg;
} SOC_GIC600_GICA_SETSPI_SR_UNION;
#endif
#define SOC_GIC600_GICA_SETSPI_SR_GICA_SETSPI_SR_START (0)
#define SOC_GIC600_GICA_SETSPI_SR_GICA_SETSPI_SR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICA_CLRSPI_SR : 32;
    } reg;
} SOC_GIC600_GICA_CLRSPI_SR_UNION;
#endif
#define SOC_GIC600_GICA_CLRSPI_SR_GICA_CLRSPI_SR_START (0)
#define SOC_GIC600_GICA_CLRSPI_SR_GICA_CLRSPI_SR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enabled : 1;
        unsigned int ImDe : 1;
        unsigned int reserved_0 : 2;
        unsigned int ITS_Number : 4;
        unsigned int UMSIirq : 1;
        unsigned int reserved_1 : 22;
        unsigned int Quiescent : 1;
    } reg;
} SOC_GIC600_GITS_CTLR_UNION;
#endif
#define SOC_GIC600_GITS_CTLR_Enabled_START (0)
#define SOC_GIC600_GITS_CTLR_Enabled_END (0)
#define SOC_GIC600_GITS_CTLR_ImDe_START (1)
#define SOC_GIC600_GITS_CTLR_ImDe_END (1)
#define SOC_GIC600_GITS_CTLR_ITS_Number_START (4)
#define SOC_GIC600_GITS_CTLR_ITS_Number_END (7)
#define SOC_GIC600_GITS_CTLR_UMSIirq_START (8)
#define SOC_GIC600_GITS_CTLR_UMSIirq_END (8)
#define SOC_GIC600_GITS_CTLR_Quiescent_START (31)
#define SOC_GIC600_GITS_CTLR_Quiescent_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer_GITS : 12;
        unsigned int Revision_GITS : 4;
        unsigned int Variant_GITS : 4;
        unsigned int reserved : 4;
        unsigned int ProductID_GITS : 8;
    } reg;
} SOC_GIC600_GITS_IIDR_UNION;
#endif
#define SOC_GIC600_GITS_IIDR_Implementer_GITS_START (0)
#define SOC_GIC600_GITS_IIDR_Implementer_GITS_END (11)
#define SOC_GIC600_GITS_IIDR_Revision_GITS_START (12)
#define SOC_GIC600_GITS_IIDR_Revision_GITS_END (15)
#define SOC_GIC600_GITS_IIDR_Variant_GITS_START (16)
#define SOC_GIC600_GITS_IIDR_Variant_GITS_END (19)
#define SOC_GIC600_GITS_IIDR_ProductID_GITS_START (24)
#define SOC_GIC600_GITS_IIDR_ProductID_GITS_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long Physical : 1;
        unsigned long long Virtual : 1;
        unsigned long long CCT : 1;
        unsigned long long reserved_0 : 1;
        unsigned long long ITTEntrySize : 4;
        unsigned long long IDBits : 5;
        unsigned long long DevBits : 5;
        unsigned long long SEIS : 2;
        unsigned long long reserved_1 : 4;
        unsigned long long HCC : 8;
        unsigned long long CIDBits : 4;
        unsigned long long CIL : 1;
        unsigned long long reserved_2 : 27;
    } reg;
} SOC_GIC600_GITS_TYPER_UNION;
#endif
#define SOC_GIC600_GITS_TYPER_Physical_START (0)
#define SOC_GIC600_GITS_TYPER_Physical_END (0)
#define SOC_GIC600_GITS_TYPER_Virtual_START (1)
#define SOC_GIC600_GITS_TYPER_Virtual_END (1)
#define SOC_GIC600_GITS_TYPER_CCT_START (2)
#define SOC_GIC600_GITS_TYPER_CCT_END (2)
#define SOC_GIC600_GITS_TYPER_ITTEntrySize_START (4)
#define SOC_GIC600_GITS_TYPER_ITTEntrySize_END (7)
#define SOC_GIC600_GITS_TYPER_IDBits_START (8)
#define SOC_GIC600_GITS_TYPER_IDBits_END (12)
#define SOC_GIC600_GITS_TYPER_DevBits_START (13)
#define SOC_GIC600_GITS_TYPER_DevBits_END (17)
#define SOC_GIC600_GITS_TYPER_SEIS_START (18)
#define SOC_GIC600_GITS_TYPER_SEIS_END (19)
#define SOC_GIC600_GITS_TYPER_HCC_START (24)
#define SOC_GIC600_GITS_TYPER_HCC_END (31)
#define SOC_GIC600_GITS_TYPER_CIDBits_START (32)
#define SOC_GIC600_GITS_TYPER_CIDBits_END (35)
#define SOC_GIC600_GITS_TYPER_CIL_START (36)
#define SOC_GIC600_GITS_TYPER_CIL_END (36)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SIP_GITS : 1;
        unsigned int LTE : 1;
        unsigned int UEE : 1;
        unsigned int CEE : 1;
        unsigned int CGO_GITS : 4;
        unsigned int AEE : 1;
        unsigned int QD : 1;
        unsigned int reserved_0: 1;
        unsigned int DMA : 1;
        unsigned int reserved_1: 4;
        unsigned int ICC : 1;
        unsigned int IDC : 1;
        unsigned int IEC : 1;
        unsigned int reserved_2: 11;
        unsigned int PWE : 1;
        unsigned int DCC_FCTLR : 1;
    } reg;
} SOC_GIC600_GITS_FCTLR_UNION;
#endif
#define SOC_GIC600_GITS_FCTLR_SIP_GITS_START (0)
#define SOC_GIC600_GITS_FCTLR_SIP_GITS_END (0)
#define SOC_GIC600_GITS_FCTLR_LTE_START (1)
#define SOC_GIC600_GITS_FCTLR_LTE_END (1)
#define SOC_GIC600_GITS_FCTLR_UEE_START (2)
#define SOC_GIC600_GITS_FCTLR_UEE_END (2)
#define SOC_GIC600_GITS_FCTLR_CEE_START (3)
#define SOC_GIC600_GITS_FCTLR_CEE_END (3)
#define SOC_GIC600_GITS_FCTLR_CGO_GITS_START (4)
#define SOC_GIC600_GITS_FCTLR_CGO_GITS_END (7)
#define SOC_GIC600_GITS_FCTLR_AEE_START (8)
#define SOC_GIC600_GITS_FCTLR_AEE_END (8)
#define SOC_GIC600_GITS_FCTLR_QD_START (9)
#define SOC_GIC600_GITS_FCTLR_QD_END (9)
#define SOC_GIC600_GITS_FCTLR_DMA_START (11)
#define SOC_GIC600_GITS_FCTLR_DMA_END (11)
#define SOC_GIC600_GITS_FCTLR_ICC_START (16)
#define SOC_GIC600_GITS_FCTLR_ICC_END (16)
#define SOC_GIC600_GITS_FCTLR_IDC_START (17)
#define SOC_GIC600_GITS_FCTLR_IDC_END (17)
#define SOC_GIC600_GITS_FCTLR_IEC_START (18)
#define SOC_GIC600_GITS_FCTLR_IEC_END (18)
#define SOC_GIC600_GITS_FCTLR_PWE_START (30)
#define SOC_GIC600_GITS_FCTLR_PWE_END (30)
#define SOC_GIC600_GITS_FCTLR_DCC_FCTLR_START (31)
#define SOC_GIC600_GITS_FCTLR_DCC_FCTLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long EVENT_ID : 16;
        unsigned long long reserved_0: 16;
        unsigned long long DEVICE_ID : 20;
        unsigned long long reserved_1: 8;
        unsigned long long LOCK_TYPE : 4;
    } reg;
} SOC_GIC600_GITS_OPR_UNION;
#endif
#define SOC_GIC600_GITS_OPR_EVENT_ID_START (0)
#define SOC_GIC600_GITS_OPR_EVENT_ID_END (15)
#define SOC_GIC600_GITS_OPR_DEVICE_ID_START (32)
#define SOC_GIC600_GITS_OPR_DEVICE_ID_END (51)
#define SOC_GIC600_GITS_OPR_LOCK_TYPE_START (60)
#define SOC_GIC600_GITS_OPR_LOCK_TYPE_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long PID : 16;
        unsigned long long reserved_0 : 16;
        unsigned long long TARGET : 13;
        unsigned long long reserved_1 : 3;
        unsigned long long ENTRY_LOCKED : 1;
        unsigned long long reserved_2 : 12;
        unsigned long long REQUEST_IN_PROGRESS : 1;
        unsigned long long REQUEST_PASS : 1;
        unsigned long long REQUEST_COMPLETE : 1;
    } reg;
} SOC_GIC600_GITS_OPSR_UNION;
#endif
#define SOC_GIC600_GITS_OPSR_PID_START (0)
#define SOC_GIC600_GITS_OPSR_PID_END (15)
#define SOC_GIC600_GITS_OPSR_TARGET_START (32)
#define SOC_GIC600_GITS_OPSR_TARGET_END (44)
#define SOC_GIC600_GITS_OPSR_ENTRY_LOCKED_START (48)
#define SOC_GIC600_GITS_OPSR_ENTRY_LOCKED_END (48)
#define SOC_GIC600_GITS_OPSR_REQUEST_IN_PROGRESS_START (61)
#define SOC_GIC600_GITS_OPSR_REQUEST_IN_PROGRESS_END (61)
#define SOC_GIC600_GITS_OPSR_REQUEST_PASS_START (62)
#define SOC_GIC600_GITS_OPSR_REQUEST_PASS_END (62)
#define SOC_GIC600_GITS_OPSR_REQUEST_COMPLETE_START (63)
#define SOC_GIC600_GITS_OPSR_REQUEST_COMPLETE_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long Size : 8;
        unsigned long long reserved_0 : 2;
        unsigned long long Shareability : 2;
        unsigned long long Physical_Address : 20;
        unsigned long long reserved_1 : 21;
        unsigned long long OuterCache : 3;
        unsigned long long reserved_2 : 3;
        unsigned long long InnerCache : 3;
        unsigned long long reserved_3 : 1;
        unsigned long long Valid : 1;
    } reg;
} SOC_GIC600_GITS_CBASER_UNION;
#endif
#define SOC_GIC600_GITS_CBASER_Size_START (0)
#define SOC_GIC600_GITS_CBASER_Size_END (7)
#define SOC_GIC600_GITS_CBASER_Shareability_START (10)
#define SOC_GIC600_GITS_CBASER_Shareability_END (11)
#define SOC_GIC600_GITS_CBASER_Physical_Address_START (12)
#define SOC_GIC600_GITS_CBASER_Physical_Address_END (31)
#define SOC_GIC600_GITS_CBASER_OuterCache_START (53)
#define SOC_GIC600_GITS_CBASER_OuterCache_END (55)
#define SOC_GIC600_GITS_CBASER_InnerCache_START (59)
#define SOC_GIC600_GITS_CBASER_InnerCache_END (61)
#define SOC_GIC600_GITS_CBASER_Valid_START (63)
#define SOC_GIC600_GITS_CBASER_Valid_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long Retry : 1;
        unsigned long long reserved_0: 4;
        unsigned long long Offset : 15;
        unsigned long long reserved_1: 44;
    } reg;
} SOC_GIC600_GITS_CWRITER_UNION;
#endif
#define SOC_GIC600_GITS_CWRITER_Retry_START (0)
#define SOC_GIC600_GITS_CWRITER_Retry_END (0)
#define SOC_GIC600_GITS_CWRITER_Offset_START (5)
#define SOC_GIC600_GITS_CWRITER_Offset_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long Stalled : 1;
        unsigned long long reserved_0 : 4;
        unsigned long long Offset_CREADR : 15;
        unsigned long long reserved_1 : 44;
    } reg;
} SOC_GIC600_GITS_CREADR_UNION;
#endif
#define SOC_GIC600_GITS_CREADR_Stalled_START (0)
#define SOC_GIC600_GITS_CREADR_Stalled_END (0)
#define SOC_GIC600_GITS_CREADR_Offset_CREADR_START (5)
#define SOC_GIC600_GITS_CREADR_Offset_CREADR_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long GITS_BASER0 : 64;
    } reg;
} SOC_GIC600_GITS_BASER0_UNION;
#endif
#define SOC_GIC600_GITS_BASER0_GITS_BASER0_START (0)
#define SOC_GIC600_GITS_BASER0_GITS_BASER0_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long GITS_BASER1 : 64;
    } reg;
} SOC_GIC600_GITS_BASER1_UNION;
#endif
#define SOC_GIC600_GITS_BASER1_GITS_BASER1_START (0)
#define SOC_GIC600_GITS_BASER1_GITS_BASER1_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ITS_Number_GITS : 8;
        unsigned int LPI_Credit_Count : 4;
        unsigned int Target_Bits : 4;
        unsigned int MSI_64 : 1;
        unsigned int Low_Latency_Support : 1;
        unsigned int Cache_ECC : 1;
        unsigned int reserved : 1;
        unsigned int Collection_Cache_Index_Bits : 4;
        unsigned int Device_Cache_Index_Bits : 4;
        unsigned int Event_Cache_Index_Bits : 4;
    } reg;
} SOC_GIC600_GITS_CFGID_UNION;
#endif
#define SOC_GIC600_GITS_CFGID_ITS_Number_GITS_START (0)
#define SOC_GIC600_GITS_CFGID_ITS_Number_GITS_END (7)
#define SOC_GIC600_GITS_CFGID_LPI_Credit_Count_START (8)
#define SOC_GIC600_GITS_CFGID_LPI_Credit_Count_END (11)
#define SOC_GIC600_GITS_CFGID_Target_Bits_START (12)
#define SOC_GIC600_GITS_CFGID_Target_Bits_END (15)
#define SOC_GIC600_GITS_CFGID_MSI_64_START (16)
#define SOC_GIC600_GITS_CFGID_MSI_64_END (16)
#define SOC_GIC600_GITS_CFGID_Low_Latency_Support_START (17)
#define SOC_GIC600_GITS_CFGID_Low_Latency_Support_END (17)
#define SOC_GIC600_GITS_CFGID_Cache_ECC_START (18)
#define SOC_GIC600_GITS_CFGID_Cache_ECC_END (18)
#define SOC_GIC600_GITS_CFGID_Collection_Cache_Index_Bits_START (20)
#define SOC_GIC600_GITS_CFGID_Collection_Cache_Index_Bits_END (23)
#define SOC_GIC600_GITS_CFGID_Device_Cache_Index_Bits_START (24)
#define SOC_GIC600_GITS_CFGID_Device_Cache_Index_Bits_END (27)
#define SOC_GIC600_GITS_CFGID_Event_Cache_Index_Bits_START (28)
#define SOC_GIC600_GITS_CFGID_Event_Cache_Index_Bits_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_PIDR4 : 32;
    } reg;
} SOC_GIC600_GITS_PIDR4_UNION;
#endif
#define SOC_GIC600_GITS_PIDR4_GITS_PIDR4_START (0)
#define SOC_GIC600_GITS_PIDR4_GITS_PIDR4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_PIDR5 : 32;
    } reg;
} SOC_GIC600_GITS_PIDR5_UNION;
#endif
#define SOC_GIC600_GITS_PIDR5_GITS_PIDR5_START (0)
#define SOC_GIC600_GITS_PIDR5_GITS_PIDR5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_PIDR6 : 32;
    } reg;
} SOC_GIC600_GITS_PIDR6_UNION;
#endif
#define SOC_GIC600_GITS_PIDR6_GITS_PIDR6_START (0)
#define SOC_GIC600_GITS_PIDR6_GITS_PIDR6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_PIDR7 : 32;
    } reg;
} SOC_GIC600_GITS_PIDR7_UNION;
#endif
#define SOC_GIC600_GITS_PIDR7_GITS_PIDR7_START (0)
#define SOC_GIC600_GITS_PIDR7_GITS_PIDR7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_PIDR0 : 32;
    } reg;
} SOC_GIC600_GITS_PIDR0_UNION;
#endif
#define SOC_GIC600_GITS_PIDR0_GITS_PIDR0_START (0)
#define SOC_GIC600_GITS_PIDR0_GITS_PIDR0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_PIDR1 : 32;
    } reg;
} SOC_GIC600_GITS_PIDR1_UNION;
#endif
#define SOC_GIC600_GITS_PIDR1_GITS_PIDR1_START (0)
#define SOC_GIC600_GITS_PIDR1_GITS_PIDR1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DES_1_GITS : 3;
        unsigned int JEDEC_GITS : 1;
        unsigned int ArchRev_GITS : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_GIC600_GITS_PIDR2_UNION;
#endif
#define SOC_GIC600_GITS_PIDR2_DES_1_GITS_START (0)
#define SOC_GIC600_GITS_PIDR2_DES_1_GITS_END (2)
#define SOC_GIC600_GITS_PIDR2_JEDEC_GITS_START (3)
#define SOC_GIC600_GITS_PIDR2_JEDEC_GITS_END (3)
#define SOC_GIC600_GITS_PIDR2_ArchRev_GITS_START (4)
#define SOC_GIC600_GITS_PIDR2_ArchRev_GITS_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_PIDR3 : 32;
    } reg;
} SOC_GIC600_GITS_PIDR3_UNION;
#endif
#define SOC_GIC600_GITS_PIDR3_GITS_PIDR3_START (0)
#define SOC_GIC600_GITS_PIDR3_GITS_PIDR3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_CIDR0 : 32;
    } reg;
} SOC_GIC600_GITS_CIDR0_UNION;
#endif
#define SOC_GIC600_GITS_CIDR0_GITS_CIDR0_START (0)
#define SOC_GIC600_GITS_CIDR0_GITS_CIDR0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_CIDR1 : 32;
    } reg;
} SOC_GIC600_GITS_CIDR1_UNION;
#endif
#define SOC_GIC600_GITS_CIDR1_GITS_CIDR1_START (0)
#define SOC_GIC600_GITS_CIDR1_GITS_CIDR1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_CIDR2 : 32;
    } reg;
} SOC_GIC600_GITS_CIDR2_UNION;
#endif
#define SOC_GIC600_GITS_CIDR2_GITS_CIDR2_START (0)
#define SOC_GIC600_GITS_CIDR2_GITS_CIDR2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_CIDR3 : 32;
    } reg;
} SOC_GIC600_GITS_CIDR3_UNION;
#endif
#define SOC_GIC600_GITS_CIDR3_GITS_CIDR3_START (0)
#define SOC_GIC600_GITS_CIDR3_GITS_CIDR3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GITS_TRANSLATER : 32;
    } reg;
} SOC_GIC600_GITS_TRANSLATER_UNION;
#endif
#define SOC_GIC600_GITS_TRANSLATER_GITS_TRANSLATER_START (0)
#define SOC_GIC600_GITS_TRANSLATER_GITS_TRANSLATER_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enable_LPIs : 1;
        unsigned int CES : 1;
        unsigned int IR : 1;
        unsigned int RWP_GICR : 1;
        unsigned int reserved_0 : 20;
        unsigned int DPG0 : 1;
        unsigned int DPG1NS : 1;
        unsigned int DPG1S : 1;
        unsigned int reserved_1 : 4;
        unsigned int UWP : 1;
    } reg;
} SOC_GIC600_GICR_CTLR_UNION;
#endif
#define SOC_GIC600_GICR_CTLR_Enable_LPIs_START (0)
#define SOC_GIC600_GICR_CTLR_Enable_LPIs_END (0)
#define SOC_GIC600_GICR_CTLR_CES_START (1)
#define SOC_GIC600_GICR_CTLR_CES_END (1)
#define SOC_GIC600_GICR_CTLR_IR_START (2)
#define SOC_GIC600_GICR_CTLR_IR_END (2)
#define SOC_GIC600_GICR_CTLR_RWP_GICR_START (3)
#define SOC_GIC600_GICR_CTLR_RWP_GICR_END (3)
#define SOC_GIC600_GICR_CTLR_DPG0_START (24)
#define SOC_GIC600_GICR_CTLR_DPG0_END (24)
#define SOC_GIC600_GICR_CTLR_DPG1NS_START (25)
#define SOC_GIC600_GICR_CTLR_DPG1NS_END (25)
#define SOC_GIC600_GICR_CTLR_DPG1S_START (26)
#define SOC_GIC600_GICR_CTLR_DPG1S_END (26)
#define SOC_GIC600_GICR_CTLR_UWP_START (31)
#define SOC_GIC600_GICR_CTLR_UWP_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer_GICR : 12;
        unsigned int Revision_GICR : 4;
        unsigned int Variant_GICR : 4;
        unsigned int reserved : 4;
        unsigned int ProductID_GICR : 8;
    } reg;
} SOC_GIC600_GICR_IIDR_UNION;
#endif
#define SOC_GIC600_GICR_IIDR_Implementer_GICR_START (0)
#define SOC_GIC600_GICR_IIDR_Implementer_GICR_END (11)
#define SOC_GIC600_GICR_IIDR_Revision_GICR_START (12)
#define SOC_GIC600_GICR_IIDR_Revision_GICR_END (15)
#define SOC_GIC600_GICR_IIDR_Variant_GICR_START (16)
#define SOC_GIC600_GICR_IIDR_Variant_GICR_END (19)
#define SOC_GIC600_GICR_IIDR_ProductID_GICR_START (24)
#define SOC_GIC600_GICR_IIDR_ProductID_GICR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long PLPIS : 1;
        unsigned long long VLPIS : 1;
        unsigned long long reserved_0 : 1;
        unsigned long long DirectLPI : 1;
        unsigned long long Last : 1;
        unsigned long long DPGS : 1;
        unsigned long long reserved_1 : 2;
        unsigned long long ProcessorNumber : 16;
        unsigned long long CommonLPIAff : 2;
        unsigned long long reserved_2 : 6;
        unsigned long long AffinityValue : 32;
    } reg;
} SOC_GIC600_GICR_TYPER_UNION;
#endif
#define SOC_GIC600_GICR_TYPER_PLPIS_START (0)
#define SOC_GIC600_GICR_TYPER_PLPIS_END (0)
#define SOC_GIC600_GICR_TYPER_VLPIS_START (1)
#define SOC_GIC600_GICR_TYPER_VLPIS_END (1)
#define SOC_GIC600_GICR_TYPER_DirectLPI_START (3)
#define SOC_GIC600_GICR_TYPER_DirectLPI_END (3)
#define SOC_GIC600_GICR_TYPER_Last_START (4)
#define SOC_GIC600_GICR_TYPER_Last_END (4)
#define SOC_GIC600_GICR_TYPER_DPGS_START (5)
#define SOC_GIC600_GICR_TYPER_DPGS_END (5)
#define SOC_GIC600_GICR_TYPER_ProcessorNumber_START (8)
#define SOC_GIC600_GICR_TYPER_ProcessorNumber_END (23)
#define SOC_GIC600_GICR_TYPER_CommonLPIAff_START (24)
#define SOC_GIC600_GICR_TYPER_CommonLPIAff_END (25)
#define SOC_GIC600_GICR_TYPER_AffinityValue_START (32)
#define SOC_GIC600_GICR_TYPER_AffinityValue_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Sleep : 1;
        unsigned int ProcessorSleep : 1;
        unsigned int ChildrenAsleep : 1;
        unsigned int reserved : 28;
        unsigned int Quiescent_GICR : 1;
    } reg;
} SOC_GIC600_GICR_WAKER_UNION;
#endif
#define SOC_GIC600_GICR_WAKER_Sleep_START (0)
#define SOC_GIC600_GICR_WAKER_Sleep_END (0)
#define SOC_GIC600_GICR_WAKER_ProcessorSleep_START (1)
#define SOC_GIC600_GICR_WAKER_ProcessorSleep_END (1)
#define SOC_GIC600_GICR_WAKER_ChildrenAsleep_START (2)
#define SOC_GIC600_GICR_WAKER_ChildrenAsleep_END (2)
#define SOC_GIC600_GICR_WAKER_Quiescent_GICR_START (31)
#define SOC_GIC600_GICR_WAKER_Quiescent_GICR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SIP_GICR : 1;
        unsigned int reserved_0: 3;
        unsigned int CGO_GICR : 3;
        unsigned int reserved_1: 24;
        unsigned int QD_GICR : 1;
    } reg;
} SOC_GIC600_GICR_FCTLR_UNION;
#endif
#define SOC_GIC600_GICR_FCTLR_SIP_GICR_START (0)
#define SOC_GIC600_GICR_FCTLR_SIP_GICR_END (0)
#define SOC_GIC600_GICR_FCTLR_CGO_GICR_START (4)
#define SOC_GIC600_GICR_FCTLR_CGO_GICR_END (6)
#define SOC_GIC600_GICR_FCTLR_QD_GICR_START (31)
#define SOC_GIC600_GICR_FCTLR_QD_GICR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RDPD : 1;
        unsigned int RDAG : 1;
        unsigned int RDGPD : 1;
        unsigned int RDGPO : 1;
        unsigned int reserved_0: 4;
        unsigned int RDGO : 8;
        unsigned int RDG : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_GIC600_GICR_PWRR_UNION;
#endif
#define SOC_GIC600_GICR_PWRR_RDPD_START (0)
#define SOC_GIC600_GICR_PWRR_RDPD_END (0)
#define SOC_GIC600_GICR_PWRR_RDAG_START (1)
#define SOC_GIC600_GICR_PWRR_RDAG_END (1)
#define SOC_GIC600_GICR_PWRR_RDGPD_START (2)
#define SOC_GIC600_GICR_PWRR_RDGPD_END (2)
#define SOC_GIC600_GICR_PWRR_RDGPO_START (3)
#define SOC_GIC600_GICR_PWRR_RDGPO_END (3)
#define SOC_GIC600_GICR_PWRR_RDGO_START (8)
#define SOC_GIC600_GICR_PWRR_RDGO_END (15)
#define SOC_GIC600_GICR_PWRR_RDG_START (16)
#define SOC_GIC600_GICR_PWRR_RDG_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Class : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GIC600_GICR_CLASS_UNION;
#endif
#define SOC_GIC600_GICR_CLASS_Class_START (0)
#define SOC_GIC600_GICR_CLASS_Class_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long IDbits : 5;
        unsigned long long reserved_0 : 2;
        unsigned long long InnerCache_GICR_PROP : 3;
        unsigned long long Shareability_GICR_PROP : 2;
        unsigned long long Physical_Address_GICR_PROP : 40;
        unsigned long long reserved_1 : 4;
        unsigned long long OuterCache_GICR_PROP : 3;
        unsigned long long reserved_2 : 5;
    } reg;
} SOC_GIC600_GICR_PROPBASER_UNION;
#endif
#define SOC_GIC600_GICR_PROPBASER_IDbits_START (0)
#define SOC_GIC600_GICR_PROPBASER_IDbits_END (4)
#define SOC_GIC600_GICR_PROPBASER_InnerCache_GICR_PROP_START (7)
#define SOC_GIC600_GICR_PROPBASER_InnerCache_GICR_PROP_END (9)
#define SOC_GIC600_GICR_PROPBASER_Shareability_GICR_PROP_START (10)
#define SOC_GIC600_GICR_PROPBASER_Shareability_GICR_PROP_END (11)
#define SOC_GIC600_GICR_PROPBASER_Physical_Address_GICR_PROP_START (12)
#define SOC_GIC600_GICR_PROPBASER_Physical_Address_GICR_PROP_END (51)
#define SOC_GIC600_GICR_PROPBASER_OuterCache_GICR_PROP_START (56)
#define SOC_GIC600_GICR_PROPBASER_OuterCache_GICR_PROP_END (58)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long reserved_0 : 7;
        unsigned long long InnerCache_GICR_PEND : 3;
        unsigned long long Shareability_GICR_PEND : 2;
        unsigned long long reserved_1 : 4;
        unsigned long long Physical_Address_GICR_PEND : 36;
        unsigned long long reserved_2 : 4;
        unsigned long long OuterCache_GICR_PEND : 3;
        unsigned long long reserved_3 : 3;
        unsigned long long PTZ : 1;
        unsigned long long reserved_4 : 1;
    } reg;
} SOC_GIC600_GICR_PENDBASER_UNION;
#endif
#define SOC_GIC600_GICR_PENDBASER_InnerCache_GICR_PEND_START (7)
#define SOC_GIC600_GICR_PENDBASER_InnerCache_GICR_PEND_END (9)
#define SOC_GIC600_GICR_PENDBASER_Shareability_GICR_PEND_START (10)
#define SOC_GIC600_GICR_PENDBASER_Shareability_GICR_PEND_END (11)
#define SOC_GIC600_GICR_PENDBASER_Physical_Address_GICR_PEND_START (16)
#define SOC_GIC600_GICR_PENDBASER_Physical_Address_GICR_PEND_END (51)
#define SOC_GIC600_GICR_PENDBASER_OuterCache_GICR_PEND_START (56)
#define SOC_GIC600_GICR_PENDBASER_OuterCache_GICR_PEND_END (58)
#define SOC_GIC600_GICR_PENDBASER_PTZ_START (62)
#define SOC_GIC600_GICR_PENDBASER_PTZ_END (62)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_PIDR4 : 32;
    } reg;
} SOC_GIC600_GICR_PIDR4_UNION;
#endif
#define SOC_GIC600_GICR_PIDR4_GICR_PIDR4_START (0)
#define SOC_GIC600_GICR_PIDR4_GICR_PIDR4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_PIDR5 : 32;
    } reg;
} SOC_GIC600_GICR_PIDR5_UNION;
#endif
#define SOC_GIC600_GICR_PIDR5_GICR_PIDR5_START (0)
#define SOC_GIC600_GICR_PIDR5_GICR_PIDR5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_PIDR6 : 32;
    } reg;
} SOC_GIC600_GICR_PIDR6_UNION;
#endif
#define SOC_GIC600_GICR_PIDR6_GICR_PIDR6_START (0)
#define SOC_GIC600_GICR_PIDR6_GICR_PIDR6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_PIDR7 : 32;
    } reg;
} SOC_GIC600_GICR_PIDR7_UNION;
#endif
#define SOC_GIC600_GICR_PIDR7_GICR_PIDR7_START (0)
#define SOC_GIC600_GICR_PIDR7_GICR_PIDR7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_PIDR0 : 32;
    } reg;
} SOC_GIC600_GICR_PIDR0_UNION;
#endif
#define SOC_GIC600_GICR_PIDR0_GICR_PIDR0_START (0)
#define SOC_GIC600_GICR_PIDR0_GICR_PIDR0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_PIDR1 : 32;
    } reg;
} SOC_GIC600_GICR_PIDR1_UNION;
#endif
#define SOC_GIC600_GICR_PIDR1_GICR_PIDR1_START (0)
#define SOC_GIC600_GICR_PIDR1_GICR_PIDR1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_PIDR2 : 32;
    } reg;
} SOC_GIC600_GICR_PIDR2_UNION;
#endif
#define SOC_GIC600_GICR_PIDR2_GICR_PIDR2_START (0)
#define SOC_GIC600_GICR_PIDR2_GICR_PIDR2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_PIDR3 : 32;
    } reg;
} SOC_GIC600_GICR_PIDR3_UNION;
#endif
#define SOC_GIC600_GICR_PIDR3_GICR_PIDR3_START (0)
#define SOC_GIC600_GICR_PIDR3_GICR_PIDR3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_CIDR0 : 32;
    } reg;
} SOC_GIC600_GICR_CIDR0_UNION;
#endif
#define SOC_GIC600_GICR_CIDR0_GICR_CIDR0_START (0)
#define SOC_GIC600_GICR_CIDR0_GICR_CIDR0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_CIDR1 : 32;
    } reg;
} SOC_GIC600_GICR_CIDR1_UNION;
#endif
#define SOC_GIC600_GICR_CIDR1_GICR_CIDR1_START (0)
#define SOC_GIC600_GICR_CIDR1_GICR_CIDR1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_CIDR2 : 32;
    } reg;
} SOC_GIC600_GICR_CIDR2_UNION;
#endif
#define SOC_GIC600_GICR_CIDR2_GICR_CIDR2_START (0)
#define SOC_GIC600_GICR_CIDR2_GICR_CIDR2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GICR_CIDR3 : 32;
    } reg;
} SOC_GIC600_GICR_CIDR3_UNION;
#endif
#define SOC_GIC600_GICR_CIDR3_GICR_CIDR3_START (0)
#define SOC_GIC600_GICR_CIDR3_GICR_CIDR3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Redistributor_group_status_bit : 32;
    } reg;
} SOC_GIC600_GICR_IGROUPR0_UNION;
#endif
#define SOC_GIC600_GICR_IGROUPR0_Redistributor_group_status_bit_START (0)
#define SOC_GIC600_GICR_IGROUPR0_Redistributor_group_status_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR_ISENABLER0_UNION;
#endif
#define SOC_GIC600_GICR_ISENABLER0_Set_enable_bit_START (0)
#define SOC_GIC600_GICR_ISENABLER0_Set_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR_ICENABLER0_UNION;
#endif
#define SOC_GIC600_GICR_ICENABLER0_Clear_enable_bit_START (0)
#define SOC_GIC600_GICR_ICENABLER0_Clear_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR_ISPENDR0_UNION;
#endif
#define SOC_GIC600_GICR_ISPENDR0_Set_pending_bit_START (0)
#define SOC_GIC600_GICR_ISPENDR0_Set_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR_ICPENDR0_UNION;
#endif
#define SOC_GIC600_GICR_ICPENDR0_Clear_pending_bit_START (0)
#define SOC_GIC600_GICR_ICPENDR0_Clear_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_active_bit : 32;
    } reg;
} SOC_GIC600_GICR_ISACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR_ISACTIVER0_Set_active_bit_START (0)
#define SOC_GIC600_GICR_ISACTIVER0_Set_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_active_bit : 32;
    } reg;
} SOC_GIC600_GICR_ICACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR_ICACTIVER0_Clear_active_bit_START (0)
#define SOC_GIC600_GICR_ICACTIVER0_Clear_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Priority_offset_0B_GICR : 8;
        unsigned int Priority_offset_1B_GICR : 8;
        unsigned int Priority_offset_2B_GICR : 8;
        unsigned int Priority_offset_3B_GICR : 8;
    } reg;
} SOC_GIC600_GICR_IPRIORITYRn_UNION;
#endif
#define SOC_GIC600_GICR_IPRIORITYRn_Priority_offset_0B_GICR_START (0)
#define SOC_GIC600_GICR_IPRIORITYRn_Priority_offset_0B_GICR_END (7)
#define SOC_GIC600_GICR_IPRIORITYRn_Priority_offset_1B_GICR_START (8)
#define SOC_GIC600_GICR_IPRIORITYRn_Priority_offset_1B_GICR_END (15)
#define SOC_GIC600_GICR_IPRIORITYRn_Priority_offset_2B_GICR_START (16)
#define SOC_GIC600_GICR_IPRIORITYRn_Priority_offset_2B_GICR_END (23)
#define SOC_GIC600_GICR_IPRIORITYRn_Priority_offset_3B_GICR_START (24)
#define SOC_GIC600_GICR_IPRIORITYRn_Priority_offset_3B_GICR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR_ICFGR0_UNION;
#endif
#define SOC_GIC600_GICR_ICFGR0_Int_config_START (0)
#define SOC_GIC600_GICR_ICFGR0_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config_ICFGR1 : 32;
    } reg;
} SOC_GIC600_GICR_ICFGR1_UNION;
#endif
#define SOC_GIC600_GICR_ICFGR1_Int_config_ICFGR1_START (0)
#define SOC_GIC600_GICR_ICFGR1_Int_config_ICFGR1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Group_modifier_bit_GICR : 32;
    } reg;
} SOC_GIC600_GICR_IGRPMODR0_UNION;
#endif
#define SOC_GIC600_GICR_IGRPMODR0_Group_modifier_bit_GICR_START (0)
#define SOC_GIC600_GICR_IGRPMODR0_Group_modifier_bit_GICR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NS_access : 32;
    } reg;
} SOC_GIC600_GICR_NSACR_UNION;
#endif
#define SOC_GIC600_GICR_NSACR_NS_access_START (0)
#define SOC_GIC600_GICR_NSACR_NS_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EnableGrp0_GICR : 1;
        unsigned int EnableGrp1NSecure : 1;
        unsigned int EnableGrp1Secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int AccessType : 1;
        unsigned int reserved_1 : 25;
        unsigned int wake_request : 1;
        unsigned int cpu_active : 1;
    } reg;
} SOC_GIC600_GICR_MISCSTATUSR_UNION;
#endif
#define SOC_GIC600_GICR_MISCSTATUSR_EnableGrp0_GICR_START (0)
#define SOC_GIC600_GICR_MISCSTATUSR_EnableGrp0_GICR_END (0)
#define SOC_GIC600_GICR_MISCSTATUSR_EnableGrp1NSecure_START (1)
#define SOC_GIC600_GICR_MISCSTATUSR_EnableGrp1NSecure_END (1)
#define SOC_GIC600_GICR_MISCSTATUSR_EnableGrp1Secure_START (2)
#define SOC_GIC600_GICR_MISCSTATUSR_EnableGrp1Secure_END (2)
#define SOC_GIC600_GICR_MISCSTATUSR_AccessType_START (4)
#define SOC_GIC600_GICR_MISCSTATUSR_AccessType_END (4)
#define SOC_GIC600_GICR_MISCSTATUSR_wake_request_START (30)
#define SOC_GIC600_GICR_MISCSTATUSR_wake_request_END (30)
#define SOC_GIC600_GICR_MISCSTATUSR_cpu_active_START (31)
#define SOC_GIC600_GICR_MISCSTATUSR_cpu_active_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int valid_n : 32;
    } reg;
} SOC_GIC600_GICR_IERRVR_UNION;
#endif
#define SOC_GIC600_GICR_IERRVR_valid_n_START (0)
#define SOC_GIC600_GICR_IERRVR_valid_n_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PPINumber : 9;
        unsigned int reserved : 2;
        unsigned int ECCSupport : 1;
        unsigned int TGT0ListWidth : 4;
        unsigned int Af0Width : 4;
        unsigned int Af1Width : 4;
        unsigned int Af2Width : 4;
        unsigned int Af3Width : 4;
    } reg;
} SOC_GIC600_GICR_CFGID0_UNION;
#endif
#define SOC_GIC600_GICR_CFGID0_PPINumber_START (0)
#define SOC_GIC600_GICR_CFGID0_PPINumber_END (8)
#define SOC_GIC600_GICR_CFGID0_ECCSupport_START (11)
#define SOC_GIC600_GICR_CFGID0_ECCSupport_END (11)
#define SOC_GIC600_GICR_CFGID0_TGT0ListWidth_START (12)
#define SOC_GIC600_GICR_CFGID0_TGT0ListWidth_END (15)
#define SOC_GIC600_GICR_CFGID0_Af0Width_START (16)
#define SOC_GIC600_GICR_CFGID0_Af0Width_END (19)
#define SOC_GIC600_GICR_CFGID0_Af1Width_START (20)
#define SOC_GIC600_GICR_CFGID0_Af1Width_END (23)
#define SOC_GIC600_GICR_CFGID0_Af2Width_START (24)
#define SOC_GIC600_GICR_CFGID0_Af2Width_END (27)
#define SOC_GIC600_GICR_CFGID0_Af3Width_START (28)
#define SOC_GIC600_GICR_CFGID0_Af3Width_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int NumCPUs : 8;
        unsigned int DirectUpstream : 1;
        unsigned int reserved_1 : 3;
        unsigned int PPIs_per_Processor : 4;
        unsigned int reserved_2 : 4;
        unsigned int UserValue : 4;
        unsigned int Version : 4;
    } reg;
} SOC_GIC600_GICR_CFGID1_UNION;
#endif
#define SOC_GIC600_GICR_CFGID1_NumCPUs_START (4)
#define SOC_GIC600_GICR_CFGID1_NumCPUs_END (11)
#define SOC_GIC600_GICR_CFGID1_DirectUpstream_START (12)
#define SOC_GIC600_GICR_CFGID1_DirectUpstream_END (12)
#define SOC_GIC600_GICR_CFGID1_PPIs_per_Processor_START (16)
#define SOC_GIC600_GICR_CFGID1_PPIs_per_Processor_END (19)
#define SOC_GIC600_GICR_CFGID1_UserValue_START (24)
#define SOC_GIC600_GICR_CFGID1_UserValue_END (27)
#define SOC_GIC600_GICR_CFGID1_Version_START (28)
#define SOC_GIC600_GICR_CFGID1_Version_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
