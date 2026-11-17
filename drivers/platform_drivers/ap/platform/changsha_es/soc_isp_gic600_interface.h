#ifndef __SOC_ISP_GIC600_INTERFACE_H__
#define __SOC_ISP_GIC600_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ISP_GIC600_GICD_CTLR_ADDR(base) (base)
#define SOC_ISP_GIC600_GICD_TYPER_ADDR(base) ((base) + 0x0004UL)
#define SOC_ISP_GIC600_GICD_IIDR_ADDR(base) ((base) + 0x0008UL)
#define SOC_ISP_GIC600_GICD_FCTLR_ADDR(base) ((base) + 0x0020UL)
#define SOC_ISP_GIC600_GICD_SAC_ADDR(base) ((base) + 0x0024UL)
#define SOC_ISP_GIC600_GICD_SETSPI_NSR_ADDR(base) ((base) + 0x0040UL)
#define SOC_ISP_GIC600_GICD_CLRSPI_NSR_ADDR(base) ((base) + 0x0048UL)
#define SOC_ISP_GIC600_GICD_SETSPI_SR_ADDR(base) ((base) + 0x0050UL)
#define SOC_ISP_GIC600_GICD_CLRSPI_SR_ADDR(base) ((base) + 0x0058UL)
#define SOC_ISP_GIC600_GICD_IGROUPRn_ADDR(base,N) (base) + 0x0080 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ISENABLERn_ADDR(base,N) (base) + 0x0100 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ICENABLERn_ADDR(base,N) (base) + 0x0180 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ISPENDRn_ADDR(base,N) (base) + 0x0200 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ICPENDRn_ADDR(base,N) (base) + 0x0280 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ISACTIVERn_ADDR(base,N) (base) + 0x0300 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ICACTIVERn_ADDR(base,N) (base) + 0x0380 + (4 * (N))
#define SOC_ISP_GIC600_GICD_IPRIORITYRn_ADDR(base,N) (base) + 0x0400 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ICFGRn_ADDR(base,N) (base) + 0x0C00 + (4 * (N))
#define SOC_ISP_GIC600_GICD_IGRPMODRn_ADDR(base,N) (base) + 0x0D00 + (4 * (N))
#define SOC_ISP_GIC600_GICD_NSACRn_ADDR(base,N) (base) + 0x0E00 + (4 * (N))
#define SOC_ISP_GIC600_GICD_IROUTERN_ADDR(base,N) (base) + 0x6100 + (8 * (N))
#define SOC_ISP_GIC600_GICD_CHIPSR_ADDR(base) ((base) + 0xC000UL)
#define SOC_ISP_GIC600_GICD_DCHIPR_ADDR(base) ((base) + 0xC004UL)
#define SOC_ISP_GIC600_GICD_CHIPR0_ADDR(base) ((base) + 0xC008UL)
#define SOC_ISP_GIC600_GICD_CHIPR1_ADDR(base) ((base) + 0xC010UL)
#define SOC_ISP_GIC600_GICD_IERRRn_ADDR(base,N) (base) + 0xE108 + (4 * (N))
#define SOC_ISP_GIC600_GICD_CFGID_ADDR(base) ((base) + 0xF000UL)
#define SOC_ISP_GIC600_GICD_PIDR4_ADDR(base) ((base) + 0xFFD0UL)
#define SOC_ISP_GIC600_GICD_PIDR5_ADDR(base) ((base) + 0xFFD4UL)
#define SOC_ISP_GIC600_GICD_PIDR6_ADDR(base) ((base) + 0xFFD8UL)
#define SOC_ISP_GIC600_GICD_PIDR7_ADDR(base) ((base) + 0xFFDCUL)
#define SOC_ISP_GIC600_GICD_PIDR0_ADDR(base) ((base) + 0xFFE0UL)
#define SOC_ISP_GIC600_GICD_PIDR1_ADDR(base) ((base) + 0xFFE4UL)
#define SOC_ISP_GIC600_GICD_PIDR2_ADDR(base) ((base) + 0xFFE8UL)
#define SOC_ISP_GIC600_GICD_PIDR3_ADDR(base) ((base) + 0xFFECUL)
#define SOC_ISP_GIC600_GICD_CIDR0_ADDR(base) ((base) + 0xFFF0UL)
#define SOC_ISP_GIC600_GICD_CIDR1_ADDR(base) ((base) + 0xFFF4UL)
#define SOC_ISP_GIC600_GICD_CIDR2_ADDR(base) ((base) + 0xFFF8UL)
#define SOC_ISP_GIC600_GICD_CIDR3_ADDR(base) ((base) + 0xFFFCUL)
#define SOC_ISP_GIC600_GICA_SETSPI_NSR_ADDR(base) ((base) + 0x00010040UL)
#define SOC_ISP_GIC600_GICA_CLRSPI_NSR_ADDR(base) ((base) + 0x00010048UL)
#define SOC_ISP_GIC600_GICA_SETSPI_SR_ADDR(base) ((base) + 0x00010050UL)
#define SOC_ISP_GIC600_GICA_CLRSPI_SR_ADDR(base) ((base) + 0x00010058UL)
#define SOC_ISP_GIC600_GICR_CTLR_ADDR(base,RDnum,ITScount) (base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL)
#define SOC_ISP_GIC600_GICR_IIDR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0x0004UL)
#define SOC_ISP_GIC600_GICR_TYPER_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0x0008UL)
#define SOC_ISP_GIC600_GICR_WAKER_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0x0014UL)
#define SOC_ISP_GIC600_GICR_FCTLR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0x0020UL)
#define SOC_ISP_GIC600_GICR_PWRR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0x0024UL)
#define SOC_ISP_GIC600_GICR_CLASS_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0x0028UL)
#define SOC_ISP_GIC600_GICR_PROPBASER_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0x0070UL)
#define SOC_ISP_GIC600_GICR_PENDBASER_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0x0078UL)
#define SOC_ISP_GIC600_GICR_PIDR4_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFD0UL)
#define SOC_ISP_GIC600_GICR_PIDR5_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFD4UL)
#define SOC_ISP_GIC600_GICR_PIDR6_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFD8UL)
#define SOC_ISP_GIC600_GICR_PIDR7_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFDCUL)
#define SOC_ISP_GIC600_GICR_PIDR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFE0UL)
#define SOC_ISP_GIC600_GICR_PIDR1_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFE4UL)
#define SOC_ISP_GIC600_GICR_PIDR2_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFE8UL)
#define SOC_ISP_GIC600_GICR_PIDR3_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFECUL)
#define SOC_ISP_GIC600_GICR_CIDR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFF0UL)
#define SOC_ISP_GIC600_GICR_CIDR1_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFF4UL)
#define SOC_ISP_GIC600_GICR_CIDR2_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFF8UL)
#define SOC_ISP_GIC600_GICR_CIDR3_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000UL) + 0xFFFCUL)
#define SOC_ISP_GIC600_GICR_IGROUPR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0080UL)
#define SOC_ISP_GIC600_GICR_ISENABLER0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0100UL)
#define SOC_ISP_GIC600_GICR_ICENABLER0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0180UL)
#define SOC_ISP_GIC600_GICR_ISPENDR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0200UL)
#define SOC_ISP_GIC600_GICR_ICPENDR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0280UL)
#define SOC_ISP_GIC600_GICR_ISACTIVER0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0300UL)
#define SOC_ISP_GIC600_GICR_ICACTIVER0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0380UL)
#define SOC_ISP_GIC600_GICR_IPRIORITYRn_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0400UL)
#define SOC_ISP_GIC600_GICR_ICFGR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0C00UL)
#define SOC_ISP_GIC600_GICR_ICFGR1_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0C04UL)
#define SOC_ISP_GIC600_GICR_IGRPMODR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0D00UL)
#define SOC_ISP_GIC600_GICR_NSACR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0x0E00UL)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0xC000UL)
#define SOC_ISP_GIC600_GICR_IERRVR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0xC008UL)
#define SOC_ISP_GIC600_GICR_CFGID0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0xF000UL)
#define SOC_ISP_GIC600_GICR_CFGID1_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000UL) + 0xF004UL)
#else
#define SOC_ISP_GIC600_GICD_CTLR_ADDR(base) (base)
#define SOC_ISP_GIC600_GICD_TYPER_ADDR(base) ((base) + 0x0004)
#define SOC_ISP_GIC600_GICD_IIDR_ADDR(base) ((base) + 0x0008)
#define SOC_ISP_GIC600_GICD_FCTLR_ADDR(base) ((base) + 0x0020)
#define SOC_ISP_GIC600_GICD_SAC_ADDR(base) ((base) + 0x0024)
#define SOC_ISP_GIC600_GICD_SETSPI_NSR_ADDR(base) ((base) + 0x0040)
#define SOC_ISP_GIC600_GICD_CLRSPI_NSR_ADDR(base) ((base) + 0x0048)
#define SOC_ISP_GIC600_GICD_SETSPI_SR_ADDR(base) ((base) + 0x0050)
#define SOC_ISP_GIC600_GICD_CLRSPI_SR_ADDR(base) ((base) + 0x0058)
#define SOC_ISP_GIC600_GICD_IGROUPRn_ADDR(base,N) (base) + 0x0080 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ISENABLERn_ADDR(base,N) (base) + 0x0100 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ICENABLERn_ADDR(base,N) (base) + 0x0180 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ISPENDRn_ADDR(base,N) (base) + 0x0200 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ICPENDRn_ADDR(base,N) (base) + 0x0280 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ISACTIVERn_ADDR(base,N) (base) + 0x0300 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ICACTIVERn_ADDR(base,N) (base) + 0x0380 + (4 * (N))
#define SOC_ISP_GIC600_GICD_IPRIORITYRn_ADDR(base,N) (base) + 0x0400 + (4 * (N))
#define SOC_ISP_GIC600_GICD_ICFGRn_ADDR(base,N) (base) + 0x0C00 + (4 * (N))
#define SOC_ISP_GIC600_GICD_IGRPMODRn_ADDR(base,N) (base) + 0x0D00 + (4 * (N))
#define SOC_ISP_GIC600_GICD_NSACRn_ADDR(base,N) (base) + 0x0E00 + (4 * (N))
#define SOC_ISP_GIC600_GICD_IROUTERN_ADDR(base,N) (base) + 0x6100 + (8 * (N))
#define SOC_ISP_GIC600_GICD_CHIPSR_ADDR(base) ((base) + 0xC000)
#define SOC_ISP_GIC600_GICD_DCHIPR_ADDR(base) ((base) + 0xC004)
#define SOC_ISP_GIC600_GICD_CHIPR0_ADDR(base) ((base) + 0xC008)
#define SOC_ISP_GIC600_GICD_CHIPR1_ADDR(base) ((base) + 0xC010)
#define SOC_ISP_GIC600_GICD_IERRRn_ADDR(base,N) (base) + 0xE108 + (4 * (N))
#define SOC_ISP_GIC600_GICD_CFGID_ADDR(base) ((base) + 0xF000)
#define SOC_ISP_GIC600_GICD_PIDR4_ADDR(base) ((base) + 0xFFD0)
#define SOC_ISP_GIC600_GICD_PIDR5_ADDR(base) ((base) + 0xFFD4)
#define SOC_ISP_GIC600_GICD_PIDR6_ADDR(base) ((base) + 0xFFD8)
#define SOC_ISP_GIC600_GICD_PIDR7_ADDR(base) ((base) + 0xFFDC)
#define SOC_ISP_GIC600_GICD_PIDR0_ADDR(base) ((base) + 0xFFE0)
#define SOC_ISP_GIC600_GICD_PIDR1_ADDR(base) ((base) + 0xFFE4)
#define SOC_ISP_GIC600_GICD_PIDR2_ADDR(base) ((base) + 0xFFE8)
#define SOC_ISP_GIC600_GICD_PIDR3_ADDR(base) ((base) + 0xFFEC)
#define SOC_ISP_GIC600_GICD_CIDR0_ADDR(base) ((base) + 0xFFF0)
#define SOC_ISP_GIC600_GICD_CIDR1_ADDR(base) ((base) + 0xFFF4)
#define SOC_ISP_GIC600_GICD_CIDR2_ADDR(base) ((base) + 0xFFF8)
#define SOC_ISP_GIC600_GICD_CIDR3_ADDR(base) ((base) + 0xFFFC)
#define SOC_ISP_GIC600_GICA_SETSPI_NSR_ADDR(base) ((base) + 0x00010040)
#define SOC_ISP_GIC600_GICA_CLRSPI_NSR_ADDR(base) ((base) + 0x00010048)
#define SOC_ISP_GIC600_GICA_SETSPI_SR_ADDR(base) ((base) + 0x00010050)
#define SOC_ISP_GIC600_GICA_CLRSPI_SR_ADDR(base) ((base) + 0x00010058)
#define SOC_ISP_GIC600_GICR_CTLR_ADDR(base,RDnum,ITScount) (base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000)
#define SOC_ISP_GIC600_GICR_IIDR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0x0004)
#define SOC_ISP_GIC600_GICR_TYPER_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0x0008)
#define SOC_ISP_GIC600_GICR_WAKER_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0x0014)
#define SOC_ISP_GIC600_GICR_FCTLR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0x0020)
#define SOC_ISP_GIC600_GICR_PWRR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0x0024)
#define SOC_ISP_GIC600_GICR_CLASS_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0x0028)
#define SOC_ISP_GIC600_GICR_PROPBASER_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0x0070)
#define SOC_ISP_GIC600_GICR_PENDBASER_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0x0078)
#define SOC_ISP_GIC600_GICR_PIDR4_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFD0)
#define SOC_ISP_GIC600_GICR_PIDR5_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFD4)
#define SOC_ISP_GIC600_GICR_PIDR6_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFD8)
#define SOC_ISP_GIC600_GICR_PIDR7_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFDC)
#define SOC_ISP_GIC600_GICR_PIDR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFE0)
#define SOC_ISP_GIC600_GICR_PIDR1_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFE4)
#define SOC_ISP_GIC600_GICR_PIDR2_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFE8)
#define SOC_ISP_GIC600_GICR_PIDR3_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFEC)
#define SOC_ISP_GIC600_GICR_CIDR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFF0)
#define SOC_ISP_GIC600_GICR_CIDR1_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFF4)
#define SOC_ISP_GIC600_GICR_CIDR2_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFF8)
#define SOC_ISP_GIC600_GICR_CIDR3_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 4) * 0x00010000) + 0xFFFC)
#define SOC_ISP_GIC600_GICR_IGROUPR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0080)
#define SOC_ISP_GIC600_GICR_ISENABLER0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0100)
#define SOC_ISP_GIC600_GICR_ICENABLER0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0180)
#define SOC_ISP_GIC600_GICR_ISPENDR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0200)
#define SOC_ISP_GIC600_GICR_ICPENDR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0280)
#define SOC_ISP_GIC600_GICR_ISACTIVER0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0300)
#define SOC_ISP_GIC600_GICR_ICACTIVER0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0380)
#define SOC_ISP_GIC600_GICR_IPRIORITYRn_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0400)
#define SOC_ISP_GIC600_GICR_ICFGR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0C00)
#define SOC_ISP_GIC600_GICR_ICFGR1_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0C04)
#define SOC_ISP_GIC600_GICR_IGRPMODR0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0D00)
#define SOC_ISP_GIC600_GICR_NSACR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0x0E00)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0xC000)
#define SOC_ISP_GIC600_GICR_IERRVR_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0xC008)
#define SOC_ISP_GIC600_GICR_CFGID0_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0xF000)
#define SOC_ISP_GIC600_GICR_CFGID1_ADDR(base,RDnum,ITScount) ((base) + (((RDnum) * 2 + (ITScount) * 2 + 5) * 0x00010000) + 0xF004)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_ISP_GIC600_GICD_CTLR_UNION;
#endif
#define SOC_ISP_GIC600_GICD_CTLR_EnableGrp0_START (0)
#define SOC_ISP_GIC600_GICD_CTLR_EnableGrp0_END (0)
#define SOC_ISP_GIC600_GICD_CTLR_EnableGrp1NS_START (1)
#define SOC_ISP_GIC600_GICD_CTLR_EnableGrp1NS_END (1)
#define SOC_ISP_GIC600_GICD_CTLR_EnableGrp1S_START (2)
#define SOC_ISP_GIC600_GICD_CTLR_EnableGrp1S_END (2)
#define SOC_ISP_GIC600_GICD_CTLR_ARE_S_START (4)
#define SOC_ISP_GIC600_GICD_CTLR_ARE_S_END (4)
#define SOC_ISP_GIC600_GICD_CTLR_ARE_NS_START (5)
#define SOC_ISP_GIC600_GICD_CTLR_ARE_NS_END (5)
#define SOC_ISP_GIC600_GICD_CTLR_DS_START (6)
#define SOC_ISP_GIC600_GICD_CTLR_DS_END (6)
#define SOC_ISP_GIC600_GICD_CTLR_E1NWF_START (7)
#define SOC_ISP_GIC600_GICD_CTLR_E1NWF_END (7)
#define SOC_ISP_GIC600_GICD_CTLR_RWP_START (31)
#define SOC_ISP_GIC600_GICD_CTLR_RWP_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_ISP_GIC600_GICD_TYPER_UNION;
#endif
#define SOC_ISP_GIC600_GICD_TYPER_ITLinesNumber_START (0)
#define SOC_ISP_GIC600_GICD_TYPER_ITLinesNumber_END (4)
#define SOC_ISP_GIC600_GICD_TYPER_SecurityExtn_START (10)
#define SOC_ISP_GIC600_GICD_TYPER_SecurityExtn_END (10)
#define SOC_ISP_GIC600_GICD_TYPER_MBIS_START (16)
#define SOC_ISP_GIC600_GICD_TYPER_MBIS_END (16)
#define SOC_ISP_GIC600_GICD_TYPER_LPIS_START (17)
#define SOC_ISP_GIC600_GICD_TYPER_LPIS_END (17)
#define SOC_ISP_GIC600_GICD_TYPER_DVIS_START (18)
#define SOC_ISP_GIC600_GICD_TYPER_DVIS_END (18)
#define SOC_ISP_GIC600_GICD_TYPER_Idbits_START (19)
#define SOC_ISP_GIC600_GICD_TYPER_Idbits_END (23)
#define SOC_ISP_GIC600_GICD_TYPER_A3V_START (24)
#define SOC_ISP_GIC600_GICD_TYPER_A3V_END (24)
#define SOC_ISP_GIC600_GICD_TYPER_No1N_START (25)
#define SOC_ISP_GIC600_GICD_TYPER_No1N_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Implementer : 12;
        unsigned int Revision : 4;
        unsigned int Variant : 4;
        unsigned int reserved : 4;
        unsigned int ProductID : 8;
    } reg;
} SOC_ISP_GIC600_GICD_IIDR_UNION;
#endif
#define SOC_ISP_GIC600_GICD_IIDR_Implementer_START (0)
#define SOC_ISP_GIC600_GICD_IIDR_Implementer_END (11)
#define SOC_ISP_GIC600_GICD_IIDR_Revision_START (12)
#define SOC_ISP_GIC600_GICD_IIDR_Revision_END (15)
#define SOC_ISP_GIC600_GICD_IIDR_Variant_START (16)
#define SOC_ISP_GIC600_GICD_IIDR_Variant_END (19)
#define SOC_ISP_GIC600_GICD_IIDR_ProductID_START (24)
#define SOC_ISP_GIC600_GICD_IIDR_ProductID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_ISP_GIC600_GICD_FCTLR_UNION;
#endif
#define SOC_ISP_GIC600_GICD_FCTLR_SIP_START (0)
#define SOC_ISP_GIC600_GICD_FCTLR_SIP_END (0)
#define SOC_ISP_GIC600_GICD_FCTLR_CGO_START (4)
#define SOC_ISP_GIC600_GICD_FCTLR_CGO_END (13)
#define SOC_ISP_GIC600_GICD_FCTLR_NSACR_START (16)
#define SOC_ISP_GIC600_GICD_FCTLR_NSACR_END (17)
#define SOC_ISP_GIC600_GICD_FCTLR_DCC_START (21)
#define SOC_ISP_GIC600_GICD_FCTLR_DCC_END (21)
#define SOC_ISP_GIC600_GICD_FCTLR_QDENY_START (25)
#define SOC_ISP_GIC600_GICD_FCTLR_QDENY_END (25)
#define SOC_ISP_GIC600_GICD_FCTLR_POS_START (26)
#define SOC_ISP_GIC600_GICD_FCTLR_POS_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DSL : 1;
        unsigned int GICTNS : 1;
        unsigned int GICPNS : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_GIC600_GICD_SAC_UNION;
#endif
#define SOC_ISP_GIC600_GICD_SAC_DSL_START (0)
#define SOC_ISP_GIC600_GICD_SAC_DSL_END (0)
#define SOC_ISP_GIC600_GICD_SAC_GICTNS_START (1)
#define SOC_ISP_GIC600_GICD_SAC_GICTNS_END (1)
#define SOC_ISP_GIC600_GICD_SAC_GICPNS_START (2)
#define SOC_ISP_GIC600_GICD_SAC_GICPNS_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int INTID_set_ns : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_GIC600_GICD_SETSPI_NSR_UNION;
#endif
#define SOC_ISP_GIC600_GICD_SETSPI_NSR_INTID_set_ns_START (0)
#define SOC_ISP_GIC600_GICD_SETSPI_NSR_INTID_set_ns_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int INTID_clr_ns : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_GIC600_GICD_CLRSPI_NSR_UNION;
#endif
#define SOC_ISP_GIC600_GICD_CLRSPI_NSR_INTID_clr_ns_START (0)
#define SOC_ISP_GIC600_GICD_CLRSPI_NSR_INTID_clr_ns_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int INTID_set_s : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_GIC600_GICD_SETSPI_SR_UNION;
#endif
#define SOC_ISP_GIC600_GICD_SETSPI_SR_INTID_set_s_START (0)
#define SOC_ISP_GIC600_GICD_SETSPI_SR_INTID_set_s_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int INTID_clr_s : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_GIC600_GICD_CLRSPI_SR_UNION;
#endif
#define SOC_ISP_GIC600_GICD_CLRSPI_SR_INTID_clr_s_START (0)
#define SOC_ISP_GIC600_GICD_CLRSPI_SR_INTID_clr_s_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int groupstatus : 32;
    } reg;
} SOC_ISP_GIC600_GICD_IGROUPRn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_IGROUPRn_groupstatus_START (0)
#define SOC_ISP_GIC600_GICD_IGROUPRn_groupstatus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int setenable : 32;
    } reg;
} SOC_ISP_GIC600_GICD_ISENABLERn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_ISENABLERn_setenable_START (0)
#define SOC_ISP_GIC600_GICD_ISENABLERn_setenable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clrenable : 32;
    } reg;
} SOC_ISP_GIC600_GICD_ICENABLERn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_ICENABLERn_clrenable_START (0)
#define SOC_ISP_GIC600_GICD_ICENABLERn_clrenable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SetPending : 32;
    } reg;
} SOC_ISP_GIC600_GICD_ISPENDRn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_ISPENDRn_SetPending_START (0)
#define SOC_ISP_GIC600_GICD_ISPENDRn_SetPending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ClearPending : 32;
    } reg;
} SOC_ISP_GIC600_GICD_ICPENDRn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_ICPENDRn_ClearPending_START (0)
#define SOC_ISP_GIC600_GICD_ICPENDRn_ClearPending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SetActive : 32;
    } reg;
} SOC_ISP_GIC600_GICD_ISACTIVERn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_ISACTIVERn_SetActive_START (0)
#define SOC_ISP_GIC600_GICD_ISACTIVERn_SetActive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ClearActive : 32;
    } reg;
} SOC_ISP_GIC600_GICD_ICACTIVERn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_ICACTIVERn_ClearActive_START (0)
#define SOC_ISP_GIC600_GICD_ICACTIVERn_ClearActive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Priority_offset_0B : 8;
        unsigned int Priority_offset_1B : 8;
        unsigned int Priority_offset_2B : 8;
        unsigned int Priority_offset_3B : 8;
    } reg;
} SOC_ISP_GIC600_GICD_IPRIORITYRn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_IPRIORITYRn_Priority_offset_0B_START (0)
#define SOC_ISP_GIC600_GICD_IPRIORITYRn_Priority_offset_0B_END (7)
#define SOC_ISP_GIC600_GICD_IPRIORITYRn_Priority_offset_1B_START (8)
#define SOC_ISP_GIC600_GICD_IPRIORITYRn_Priority_offset_1B_END (15)
#define SOC_ISP_GIC600_GICD_IPRIORITYRn_Priority_offset_2B_START (16)
#define SOC_ISP_GIC600_GICD_IPRIORITYRn_Priority_offset_2B_END (23)
#define SOC_ISP_GIC600_GICD_IPRIORITYRn_Priority_offset_3B_START (24)
#define SOC_ISP_GIC600_GICD_IPRIORITYRn_Priority_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int IntConfig : 32;
    } reg;
} SOC_ISP_GIC600_GICD_ICFGRn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_ICFGRn_IntConfig_START (0)
#define SOC_ISP_GIC600_GICD_ICFGRn_IntConfig_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Group_modifier_bit : 32;
    } reg;
} SOC_ISP_GIC600_GICD_IGRPMODRn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_IGRPMODRn_Group_modifier_bit_START (0)
#define SOC_ISP_GIC600_GICD_IGRPMODRn_Group_modifier_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ns_access : 32;
    } reg;
} SOC_ISP_GIC600_GICD_NSACRn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_NSACRn_ns_access_START (0)
#define SOC_ISP_GIC600_GICD_NSACRn_ns_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long aff0 : 8;
        unsigned long long aff1 : 8;
        unsigned long long aff2 : 8;
        unsigned long long reserved_0 : 7;
        unsigned long long Interrupt_Routing_Mode : 1;
        unsigned long long aff3 : 8;
        unsigned long long reserved_1 : 24;
    } reg;
} SOC_ISP_GIC600_GICD_IROUTERN_UNION;
#endif
#define SOC_ISP_GIC600_GICD_IROUTERN_aff0_START (0)
#define SOC_ISP_GIC600_GICD_IROUTERN_aff0_END (7)
#define SOC_ISP_GIC600_GICD_IROUTERN_aff1_START (8)
#define SOC_ISP_GIC600_GICD_IROUTERN_aff1_END (15)
#define SOC_ISP_GIC600_GICD_IROUTERN_aff2_START (16)
#define SOC_ISP_GIC600_GICD_IROUTERN_aff2_END (23)
#define SOC_ISP_GIC600_GICD_IROUTERN_Interrupt_Routing_Mode_START (31)
#define SOC_ISP_GIC600_GICD_IROUTERN_Interrupt_Routing_Mode_END (31)
#define SOC_ISP_GIC600_GICD_IROUTERN_aff3_START (32)
#define SOC_ISP_GIC600_GICD_IROUTERN_aff3_END (39)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GTR : 1;
        unsigned int GTS : 1;
        unsigned int GTO : 1;
        unsigned int reserved_0: 1;
        unsigned int RTS : 2;
        unsigned int reserved_1: 26;
    } reg;
} SOC_ISP_GIC600_GICD_CHIPSR_UNION;
#endif
#define SOC_ISP_GIC600_GICD_CHIPSR_GTR_START (0)
#define SOC_ISP_GIC600_GICD_CHIPSR_GTR_END (0)
#define SOC_ISP_GIC600_GICD_CHIPSR_GTS_START (1)
#define SOC_ISP_GIC600_GICD_CHIPSR_GTS_END (1)
#define SOC_ISP_GIC600_GICD_CHIPSR_GTO_START (2)
#define SOC_ISP_GIC600_GICD_CHIPSR_GTO_END (2)
#define SOC_ISP_GIC600_GICD_CHIPSR_RTS_START (4)
#define SOC_ISP_GIC600_GICD_CHIPSR_RTS_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int PUP : 1;
        unsigned int reserved_0: 3;
        unsigned int rt_owner : 4;
        unsigned int reserved_1: 24;
    } reg;
} SOC_ISP_GIC600_GICD_DCHIPR_UNION;
#endif
#define SOC_ISP_GIC600_GICD_DCHIPR_PUP_START (0)
#define SOC_ISP_GIC600_GICD_DCHIPR_PUP_END (0)
#define SOC_ISP_GIC600_GICD_DCHIPR_rt_owner_START (4)
#define SOC_ISP_GIC600_GICD_DCHIPR_rt_owner_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long SocketState : 1;
        unsigned long long PUP_CHIPR0 : 1;
        unsigned long long reserved_0 : 3;
        unsigned long long SPI_BLOCKS : 5;
        unsigned long long SPI_BLOCK_MIN : 6;
        unsigned long long ADDR : 32;
        unsigned long long reserved_1 : 16;
    } reg;
} SOC_ISP_GIC600_GICD_CHIPR0_UNION;
#endif
#define SOC_ISP_GIC600_GICD_CHIPR0_SocketState_START (0)
#define SOC_ISP_GIC600_GICD_CHIPR0_SocketState_END (0)
#define SOC_ISP_GIC600_GICD_CHIPR0_PUP_CHIPR0_START (1)
#define SOC_ISP_GIC600_GICD_CHIPR0_PUP_CHIPR0_END (1)
#define SOC_ISP_GIC600_GICD_CHIPR0_SPI_BLOCKS_START (5)
#define SOC_ISP_GIC600_GICD_CHIPR0_SPI_BLOCKS_END (9)
#define SOC_ISP_GIC600_GICD_CHIPR0_SPI_BLOCK_MIN_START (10)
#define SOC_ISP_GIC600_GICD_CHIPR0_SPI_BLOCK_MIN_END (15)
#define SOC_ISP_GIC600_GICD_CHIPR0_ADDR_START (16)
#define SOC_ISP_GIC600_GICD_CHIPR0_ADDR_END (47)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long SocketState_CHIPR1 : 1;
        unsigned long long PUP_CHIPR1 : 1;
        unsigned long long reserved_0 : 3;
        unsigned long long SPI_BLOCKS_CHIPR1 : 5;
        unsigned long long SPI_BLOCK_MIN_CHIPR1 : 6;
        unsigned long long ADDR_CHIPR1 : 32;
        unsigned long long reserved_1 : 16;
    } reg;
} SOC_ISP_GIC600_GICD_CHIPR1_UNION;
#endif
#define SOC_ISP_GIC600_GICD_CHIPR1_SocketState_CHIPR1_START (0)
#define SOC_ISP_GIC600_GICD_CHIPR1_SocketState_CHIPR1_END (0)
#define SOC_ISP_GIC600_GICD_CHIPR1_PUP_CHIPR1_START (1)
#define SOC_ISP_GIC600_GICD_CHIPR1_PUP_CHIPR1_END (1)
#define SOC_ISP_GIC600_GICD_CHIPR1_SPI_BLOCKS_CHIPR1_START (5)
#define SOC_ISP_GIC600_GICD_CHIPR1_SPI_BLOCKS_CHIPR1_END (9)
#define SOC_ISP_GIC600_GICD_CHIPR1_SPI_BLOCK_MIN_CHIPR1_START (10)
#define SOC_ISP_GIC600_GICD_CHIPR1_SPI_BLOCK_MIN_CHIPR1_END (15)
#define SOC_ISP_GIC600_GICD_CHIPR1_ADDR_CHIPR1_START (16)
#define SOC_ISP_GIC600_GICD_CHIPR1_ADDR_CHIPR1_END (47)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Status : 32;
    } reg;
} SOC_ISP_GIC600_GICD_IERRRn_UNION;
#endif
#define SOC_ISP_GIC600_GICD_IERRRn_Status_START (0)
#define SOC_ISP_GIC600_GICD_IERRRn_Status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
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
} SOC_ISP_GIC600_GICD_CFGID_UNION;
#endif
#define SOC_ISP_GIC600_GICD_CFGID_SO_START (0)
#define SOC_ISP_GIC600_GICD_CFGID_SO_END (0)
#define SOC_ISP_GIC600_GICD_CFGID_SNUM_START (4)
#define SOC_ISP_GIC600_GICD_CFGID_SNUM_END (7)
#define SOC_ISP_GIC600_GICD_CFGID_LPIS_CFGID_START (12)
#define SOC_ISP_GIC600_GICD_CFGID_LPIS_CFGID_END (12)
#define SOC_ISP_GIC600_GICD_CFGID_DLPI_START (13)
#define SOC_ISP_GIC600_GICD_CFGID_DLPI_END (13)
#define SOC_ISP_GIC600_GICD_CFGID_AFSL_START (14)
#define SOC_ISP_GIC600_GICD_CFGID_AFSL_END (14)
#define SOC_ISP_GIC600_GICD_CFGID_SPIS_START (15)
#define SOC_ISP_GIC600_GICD_CFGID_SPIS_END (20)
#define SOC_ISP_GIC600_GICD_CFGID_AFF0_START (32)
#define SOC_ISP_GIC600_GICD_CFGID_AFF0_END (35)
#define SOC_ISP_GIC600_GICD_CFGID_AFF1_START (36)
#define SOC_ISP_GIC600_GICD_CFGID_AFF1_END (39)
#define SOC_ISP_GIC600_GICD_CFGID_AFF2_START (40)
#define SOC_ISP_GIC600_GICD_CFGID_AFF2_END (43)
#define SOC_ISP_GIC600_GICD_CFGID_AFF3_START (44)
#define SOC_ISP_GIC600_GICD_CFGID_AFF3_END (47)
#define SOC_ISP_GIC600_GICD_CFGID_PEW_START (48)
#define SOC_ISP_GIC600_GICD_CFGID_PEW_END (52)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DES_2 : 4;
        unsigned int SIZE : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_GIC600_GICD_PIDR4_UNION;
#endif
#define SOC_ISP_GIC600_GICD_PIDR4_DES_2_START (0)
#define SOC_ISP_GIC600_GICD_PIDR4_DES_2_END (3)
#define SOC_ISP_GIC600_GICD_PIDR4_SIZE_START (4)
#define SOC_ISP_GIC600_GICD_PIDR4_SIZE_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICD_PIDR5 : 32;
    } reg;
} SOC_ISP_GIC600_GICD_PIDR5_UNION;
#endif
#define SOC_ISP_GIC600_GICD_PIDR5_GICD_PIDR5_START (0)
#define SOC_ISP_GIC600_GICD_PIDR5_GICD_PIDR5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICD_PIDR6 : 32;
    } reg;
} SOC_ISP_GIC600_GICD_PIDR6_UNION;
#endif
#define SOC_ISP_GIC600_GICD_PIDR6_GICD_PIDR6_START (0)
#define SOC_ISP_GIC600_GICD_PIDR6_GICD_PIDR6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICD_PIDR7 : 32;
    } reg;
} SOC_ISP_GIC600_GICD_PIDR7_UNION;
#endif
#define SOC_ISP_GIC600_GICD_PIDR7_GICD_PIDR7_START (0)
#define SOC_ISP_GIC600_GICD_PIDR7_GICD_PIDR7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int PART_0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_GIC600_GICD_PIDR0_UNION;
#endif
#define SOC_ISP_GIC600_GICD_PIDR0_PART_0_START (0)
#define SOC_ISP_GIC600_GICD_PIDR0_PART_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int PART_1 : 4;
        unsigned int DES_0 : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_GIC600_GICD_PIDR1_UNION;
#endif
#define SOC_ISP_GIC600_GICD_PIDR1_PART_1_START (0)
#define SOC_ISP_GIC600_GICD_PIDR1_PART_1_END (3)
#define SOC_ISP_GIC600_GICD_PIDR1_DES_0_START (4)
#define SOC_ISP_GIC600_GICD_PIDR1_DES_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DES_1 : 3;
        unsigned int JEDEC : 1;
        unsigned int ArchRev : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_GIC600_GICD_PIDR2_UNION;
#endif
#define SOC_ISP_GIC600_GICD_PIDR2_DES_1_START (0)
#define SOC_ISP_GIC600_GICD_PIDR2_DES_1_END (2)
#define SOC_ISP_GIC600_GICD_PIDR2_JEDEC_START (3)
#define SOC_ISP_GIC600_GICD_PIDR2_JEDEC_END (3)
#define SOC_ISP_GIC600_GICD_PIDR2_ArchRev_START (4)
#define SOC_ISP_GIC600_GICD_PIDR2_ArchRev_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int CMOD : 4;
        unsigned int REVAND : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_GIC600_GICD_PIDR3_UNION;
#endif
#define SOC_ISP_GIC600_GICD_PIDR3_CMOD_START (0)
#define SOC_ISP_GIC600_GICD_PIDR3_CMOD_END (3)
#define SOC_ISP_GIC600_GICD_PIDR3_REVAND_START (4)
#define SOC_ISP_GIC600_GICD_PIDR3_REVAND_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICD_CIDR0 : 32;
    } reg;
} SOC_ISP_GIC600_GICD_CIDR0_UNION;
#endif
#define SOC_ISP_GIC600_GICD_CIDR0_GICD_CIDR0_START (0)
#define SOC_ISP_GIC600_GICD_CIDR0_GICD_CIDR0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICD_CIDR1 : 32;
    } reg;
} SOC_ISP_GIC600_GICD_CIDR1_UNION;
#endif
#define SOC_ISP_GIC600_GICD_CIDR1_GICD_CIDR1_START (0)
#define SOC_ISP_GIC600_GICD_CIDR1_GICD_CIDR1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICD_CIDR2 : 32;
    } reg;
} SOC_ISP_GIC600_GICD_CIDR2_UNION;
#endif
#define SOC_ISP_GIC600_GICD_CIDR2_GICD_CIDR2_START (0)
#define SOC_ISP_GIC600_GICD_CIDR2_GICD_CIDR2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICD_CIDR3 : 32;
    } reg;
} SOC_ISP_GIC600_GICD_CIDR3_UNION;
#endif
#define SOC_ISP_GIC600_GICD_CIDR3_GICD_CIDR3_START (0)
#define SOC_ISP_GIC600_GICD_CIDR3_GICD_CIDR3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICA_SETSPI_NSR : 32;
    } reg;
} SOC_ISP_GIC600_GICA_SETSPI_NSR_UNION;
#endif
#define SOC_ISP_GIC600_GICA_SETSPI_NSR_GICA_SETSPI_NSR_START (0)
#define SOC_ISP_GIC600_GICA_SETSPI_NSR_GICA_SETSPI_NSR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICA_CLRSPI_NSR : 32;
    } reg;
} SOC_ISP_GIC600_GICA_CLRSPI_NSR_UNION;
#endif
#define SOC_ISP_GIC600_GICA_CLRSPI_NSR_GICA_CLRSPI_NSR_START (0)
#define SOC_ISP_GIC600_GICA_CLRSPI_NSR_GICA_CLRSPI_NSR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICA_SETSPI_SR : 32;
    } reg;
} SOC_ISP_GIC600_GICA_SETSPI_SR_UNION;
#endif
#define SOC_ISP_GIC600_GICA_SETSPI_SR_GICA_SETSPI_SR_START (0)
#define SOC_ISP_GIC600_GICA_SETSPI_SR_GICA_SETSPI_SR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICA_CLRSPI_SR : 32;
    } reg;
} SOC_ISP_GIC600_GICA_CLRSPI_SR_UNION;
#endif
#define SOC_ISP_GIC600_GICA_CLRSPI_SR_GICA_CLRSPI_SR_START (0)
#define SOC_ISP_GIC600_GICA_CLRSPI_SR_GICA_CLRSPI_SR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_ISP_GIC600_GICR_CTLR_UNION;
#endif
#define SOC_ISP_GIC600_GICR_CTLR_Enable_LPIs_START (0)
#define SOC_ISP_GIC600_GICR_CTLR_Enable_LPIs_END (0)
#define SOC_ISP_GIC600_GICR_CTLR_CES_START (1)
#define SOC_ISP_GIC600_GICR_CTLR_CES_END (1)
#define SOC_ISP_GIC600_GICR_CTLR_IR_START (2)
#define SOC_ISP_GIC600_GICR_CTLR_IR_END (2)
#define SOC_ISP_GIC600_GICR_CTLR_RWP_GICR_START (3)
#define SOC_ISP_GIC600_GICR_CTLR_RWP_GICR_END (3)
#define SOC_ISP_GIC600_GICR_CTLR_DPG0_START (24)
#define SOC_ISP_GIC600_GICR_CTLR_DPG0_END (24)
#define SOC_ISP_GIC600_GICR_CTLR_DPG1NS_START (25)
#define SOC_ISP_GIC600_GICR_CTLR_DPG1NS_END (25)
#define SOC_ISP_GIC600_GICR_CTLR_DPG1S_START (26)
#define SOC_ISP_GIC600_GICR_CTLR_DPG1S_END (26)
#define SOC_ISP_GIC600_GICR_CTLR_UWP_START (31)
#define SOC_ISP_GIC600_GICR_CTLR_UWP_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Implementer_GICR : 12;
        unsigned int Revision_GICR : 4;
        unsigned int Variant_GICR : 4;
        unsigned int reserved : 4;
        unsigned int ProductID_GICR : 8;
    } reg;
} SOC_ISP_GIC600_GICR_IIDR_UNION;
#endif
#define SOC_ISP_GIC600_GICR_IIDR_Implementer_GICR_START (0)
#define SOC_ISP_GIC600_GICR_IIDR_Implementer_GICR_END (11)
#define SOC_ISP_GIC600_GICR_IIDR_Revision_GICR_START (12)
#define SOC_ISP_GIC600_GICR_IIDR_Revision_GICR_END (15)
#define SOC_ISP_GIC600_GICR_IIDR_Variant_GICR_START (16)
#define SOC_ISP_GIC600_GICR_IIDR_Variant_GICR_END (19)
#define SOC_ISP_GIC600_GICR_IIDR_ProductID_GICR_START (24)
#define SOC_ISP_GIC600_GICR_IIDR_ProductID_GICR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
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
} SOC_ISP_GIC600_GICR_TYPER_UNION;
#endif
#define SOC_ISP_GIC600_GICR_TYPER_PLPIS_START (0)
#define SOC_ISP_GIC600_GICR_TYPER_PLPIS_END (0)
#define SOC_ISP_GIC600_GICR_TYPER_VLPIS_START (1)
#define SOC_ISP_GIC600_GICR_TYPER_VLPIS_END (1)
#define SOC_ISP_GIC600_GICR_TYPER_DirectLPI_START (3)
#define SOC_ISP_GIC600_GICR_TYPER_DirectLPI_END (3)
#define SOC_ISP_GIC600_GICR_TYPER_Last_START (4)
#define SOC_ISP_GIC600_GICR_TYPER_Last_END (4)
#define SOC_ISP_GIC600_GICR_TYPER_DPGS_START (5)
#define SOC_ISP_GIC600_GICR_TYPER_DPGS_END (5)
#define SOC_ISP_GIC600_GICR_TYPER_ProcessorNumber_START (8)
#define SOC_ISP_GIC600_GICR_TYPER_ProcessorNumber_END (23)
#define SOC_ISP_GIC600_GICR_TYPER_CommonLPIAff_START (24)
#define SOC_ISP_GIC600_GICR_TYPER_CommonLPIAff_END (25)
#define SOC_ISP_GIC600_GICR_TYPER_AffinityValue_START (32)
#define SOC_ISP_GIC600_GICR_TYPER_AffinityValue_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Sleep : 1;
        unsigned int ProcessorSleep : 1;
        unsigned int ChildrenAsleep : 1;
        unsigned int reserved : 28;
        unsigned int Quiescent_GICR : 1;
    } reg;
} SOC_ISP_GIC600_GICR_WAKER_UNION;
#endif
#define SOC_ISP_GIC600_GICR_WAKER_Sleep_START (0)
#define SOC_ISP_GIC600_GICR_WAKER_Sleep_END (0)
#define SOC_ISP_GIC600_GICR_WAKER_ProcessorSleep_START (1)
#define SOC_ISP_GIC600_GICR_WAKER_ProcessorSleep_END (1)
#define SOC_ISP_GIC600_GICR_WAKER_ChildrenAsleep_START (2)
#define SOC_ISP_GIC600_GICR_WAKER_ChildrenAsleep_END (2)
#define SOC_ISP_GIC600_GICR_WAKER_Quiescent_GICR_START (31)
#define SOC_ISP_GIC600_GICR_WAKER_Quiescent_GICR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SIP_GICR : 1;
        unsigned int reserved_0: 3;
        unsigned int CGO_GICR : 3;
        unsigned int reserved_1: 24;
        unsigned int QD_GICR : 1;
    } reg;
} SOC_ISP_GIC600_GICR_FCTLR_UNION;
#endif
#define SOC_ISP_GIC600_GICR_FCTLR_SIP_GICR_START (0)
#define SOC_ISP_GIC600_GICR_FCTLR_SIP_GICR_END (0)
#define SOC_ISP_GIC600_GICR_FCTLR_CGO_GICR_START (4)
#define SOC_ISP_GIC600_GICR_FCTLR_CGO_GICR_END (6)
#define SOC_ISP_GIC600_GICR_FCTLR_QD_GICR_START (31)
#define SOC_ISP_GIC600_GICR_FCTLR_QD_GICR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RDPD : 1;
        unsigned int RDAG : 1;
        unsigned int RDGPD : 1;
        unsigned int RDGPO : 1;
        unsigned int reserved_0: 4;
        unsigned int RDGO : 8;
        unsigned int RDG : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_ISP_GIC600_GICR_PWRR_UNION;
#endif
#define SOC_ISP_GIC600_GICR_PWRR_RDPD_START (0)
#define SOC_ISP_GIC600_GICR_PWRR_RDPD_END (0)
#define SOC_ISP_GIC600_GICR_PWRR_RDAG_START (1)
#define SOC_ISP_GIC600_GICR_PWRR_RDAG_END (1)
#define SOC_ISP_GIC600_GICR_PWRR_RDGPD_START (2)
#define SOC_ISP_GIC600_GICR_PWRR_RDGPD_END (2)
#define SOC_ISP_GIC600_GICR_PWRR_RDGPO_START (3)
#define SOC_ISP_GIC600_GICR_PWRR_RDGPO_END (3)
#define SOC_ISP_GIC600_GICR_PWRR_RDGO_START (8)
#define SOC_ISP_GIC600_GICR_PWRR_RDGO_END (15)
#define SOC_ISP_GIC600_GICR_PWRR_RDG_START (16)
#define SOC_ISP_GIC600_GICR_PWRR_RDG_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Class : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_GIC600_GICR_CLASS_UNION;
#endif
#define SOC_ISP_GIC600_GICR_CLASS_Class_START (0)
#define SOC_ISP_GIC600_GICR_CLASS_Class_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long IDbits : 5;
        unsigned long long reserved_0 : 2;
        unsigned long long InnerCache_GICR_PROP : 3;
        unsigned long long Shareability_GICR_PROP : 2;
        unsigned long long Physical_Address_GICR_PROP : 40;
        unsigned long long reserved_1 : 4;
        unsigned long long OuterCache_GICR_PROP : 3;
        unsigned long long reserved_2 : 5;
    } reg;
} SOC_ISP_GIC600_GICR_PROPBASER_UNION;
#endif
#define SOC_ISP_GIC600_GICR_PROPBASER_IDbits_START (0)
#define SOC_ISP_GIC600_GICR_PROPBASER_IDbits_END (4)
#define SOC_ISP_GIC600_GICR_PROPBASER_InnerCache_GICR_PROP_START (7)
#define SOC_ISP_GIC600_GICR_PROPBASER_InnerCache_GICR_PROP_END (9)
#define SOC_ISP_GIC600_GICR_PROPBASER_Shareability_GICR_PROP_START (10)
#define SOC_ISP_GIC600_GICR_PROPBASER_Shareability_GICR_PROP_END (11)
#define SOC_ISP_GIC600_GICR_PROPBASER_Physical_Address_GICR_PROP_START (12)
#define SOC_ISP_GIC600_GICR_PROPBASER_Physical_Address_GICR_PROP_END (51)
#define SOC_ISP_GIC600_GICR_PROPBASER_OuterCache_GICR_PROP_START (56)
#define SOC_ISP_GIC600_GICR_PROPBASER_OuterCache_GICR_PROP_END (58)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
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
} SOC_ISP_GIC600_GICR_PENDBASER_UNION;
#endif
#define SOC_ISP_GIC600_GICR_PENDBASER_InnerCache_GICR_PEND_START (7)
#define SOC_ISP_GIC600_GICR_PENDBASER_InnerCache_GICR_PEND_END (9)
#define SOC_ISP_GIC600_GICR_PENDBASER_Shareability_GICR_PEND_START (10)
#define SOC_ISP_GIC600_GICR_PENDBASER_Shareability_GICR_PEND_END (11)
#define SOC_ISP_GIC600_GICR_PENDBASER_Physical_Address_GICR_PEND_START (16)
#define SOC_ISP_GIC600_GICR_PENDBASER_Physical_Address_GICR_PEND_END (51)
#define SOC_ISP_GIC600_GICR_PENDBASER_OuterCache_GICR_PEND_START (56)
#define SOC_ISP_GIC600_GICR_PENDBASER_OuterCache_GICR_PEND_END (58)
#define SOC_ISP_GIC600_GICR_PENDBASER_PTZ_START (62)
#define SOC_ISP_GIC600_GICR_PENDBASER_PTZ_END (62)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_PIDR4 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_PIDR4_UNION;
#endif
#define SOC_ISP_GIC600_GICR_PIDR4_GICR_PIDR4_START (0)
#define SOC_ISP_GIC600_GICR_PIDR4_GICR_PIDR4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_PIDR5 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_PIDR5_UNION;
#endif
#define SOC_ISP_GIC600_GICR_PIDR5_GICR_PIDR5_START (0)
#define SOC_ISP_GIC600_GICR_PIDR5_GICR_PIDR5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_PIDR6 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_PIDR6_UNION;
#endif
#define SOC_ISP_GIC600_GICR_PIDR6_GICR_PIDR6_START (0)
#define SOC_ISP_GIC600_GICR_PIDR6_GICR_PIDR6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_PIDR7 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_PIDR7_UNION;
#endif
#define SOC_ISP_GIC600_GICR_PIDR7_GICR_PIDR7_START (0)
#define SOC_ISP_GIC600_GICR_PIDR7_GICR_PIDR7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_PIDR0 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_PIDR0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_PIDR0_GICR_PIDR0_START (0)
#define SOC_ISP_GIC600_GICR_PIDR0_GICR_PIDR0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_PIDR1 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_PIDR1_UNION;
#endif
#define SOC_ISP_GIC600_GICR_PIDR1_GICR_PIDR1_START (0)
#define SOC_ISP_GIC600_GICR_PIDR1_GICR_PIDR1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_PIDR2 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_PIDR2_UNION;
#endif
#define SOC_ISP_GIC600_GICR_PIDR2_GICR_PIDR2_START (0)
#define SOC_ISP_GIC600_GICR_PIDR2_GICR_PIDR2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_PIDR3 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_PIDR3_UNION;
#endif
#define SOC_ISP_GIC600_GICR_PIDR3_GICR_PIDR3_START (0)
#define SOC_ISP_GIC600_GICR_PIDR3_GICR_PIDR3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_CIDR0 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_CIDR0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_CIDR0_GICR_CIDR0_START (0)
#define SOC_ISP_GIC600_GICR_CIDR0_GICR_CIDR0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_CIDR1 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_CIDR1_UNION;
#endif
#define SOC_ISP_GIC600_GICR_CIDR1_GICR_CIDR1_START (0)
#define SOC_ISP_GIC600_GICR_CIDR1_GICR_CIDR1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_CIDR2 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_CIDR2_UNION;
#endif
#define SOC_ISP_GIC600_GICR_CIDR2_GICR_CIDR2_START (0)
#define SOC_ISP_GIC600_GICR_CIDR2_GICR_CIDR2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int GICR_CIDR3 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_CIDR3_UNION;
#endif
#define SOC_ISP_GIC600_GICR_CIDR3_GICR_CIDR3_START (0)
#define SOC_ISP_GIC600_GICR_CIDR3_GICR_CIDR3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Redistributor_group_status_bit : 32;
    } reg;
} SOC_ISP_GIC600_GICR_IGROUPR0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_IGROUPR0_Redistributor_group_status_bit_START (0)
#define SOC_ISP_GIC600_GICR_IGROUPR0_Redistributor_group_status_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Set_enable_bit : 32;
    } reg;
} SOC_ISP_GIC600_GICR_ISENABLER0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_ISENABLER0_Set_enable_bit_START (0)
#define SOC_ISP_GIC600_GICR_ISENABLER0_Set_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Clear_enable_bit : 32;
    } reg;
} SOC_ISP_GIC600_GICR_ICENABLER0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_ICENABLER0_Clear_enable_bit_START (0)
#define SOC_ISP_GIC600_GICR_ICENABLER0_Clear_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Set_pending_bit : 32;
    } reg;
} SOC_ISP_GIC600_GICR_ISPENDR0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_ISPENDR0_Set_pending_bit_START (0)
#define SOC_ISP_GIC600_GICR_ISPENDR0_Set_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Clear_pending_bit : 32;
    } reg;
} SOC_ISP_GIC600_GICR_ICPENDR0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_ICPENDR0_Clear_pending_bit_START (0)
#define SOC_ISP_GIC600_GICR_ICPENDR0_Clear_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Set_active_bit : 32;
    } reg;
} SOC_ISP_GIC600_GICR_ISACTIVER0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_ISACTIVER0_Set_active_bit_START (0)
#define SOC_ISP_GIC600_GICR_ISACTIVER0_Set_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Clear_active_bit : 32;
    } reg;
} SOC_ISP_GIC600_GICR_ICACTIVER0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_ICACTIVER0_Clear_active_bit_START (0)
#define SOC_ISP_GIC600_GICR_ICACTIVER0_Clear_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Priority_offset_0B_GICR : 8;
        unsigned int Priority_offset_1B_GICR : 8;
        unsigned int Priority_offset_2B_GICR : 8;
        unsigned int Priority_offset_3B_GICR : 8;
    } reg;
} SOC_ISP_GIC600_GICR_IPRIORITYRn_UNION;
#endif
#define SOC_ISP_GIC600_GICR_IPRIORITYRn_Priority_offset_0B_GICR_START (0)
#define SOC_ISP_GIC600_GICR_IPRIORITYRn_Priority_offset_0B_GICR_END (7)
#define SOC_ISP_GIC600_GICR_IPRIORITYRn_Priority_offset_1B_GICR_START (8)
#define SOC_ISP_GIC600_GICR_IPRIORITYRn_Priority_offset_1B_GICR_END (15)
#define SOC_ISP_GIC600_GICR_IPRIORITYRn_Priority_offset_2B_GICR_START (16)
#define SOC_ISP_GIC600_GICR_IPRIORITYRn_Priority_offset_2B_GICR_END (23)
#define SOC_ISP_GIC600_GICR_IPRIORITYRn_Priority_offset_3B_GICR_START (24)
#define SOC_ISP_GIC600_GICR_IPRIORITYRn_Priority_offset_3B_GICR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Int_config : 32;
    } reg;
} SOC_ISP_GIC600_GICR_ICFGR0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_ICFGR0_Int_config_START (0)
#define SOC_ISP_GIC600_GICR_ICFGR0_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Int_config_ICFGR1 : 32;
    } reg;
} SOC_ISP_GIC600_GICR_ICFGR1_UNION;
#endif
#define SOC_ISP_GIC600_GICR_ICFGR1_Int_config_ICFGR1_START (0)
#define SOC_ISP_GIC600_GICR_ICFGR1_Int_config_ICFGR1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Group_modifier_bit_GICR : 32;
    } reg;
} SOC_ISP_GIC600_GICR_IGRPMODR0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_IGRPMODR0_Group_modifier_bit_GICR_START (0)
#define SOC_ISP_GIC600_GICR_IGRPMODR0_Group_modifier_bit_GICR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int NS_access : 32;
    } reg;
} SOC_ISP_GIC600_GICR_NSACR_UNION;
#endif
#define SOC_ISP_GIC600_GICR_NSACR_NS_access_START (0)
#define SOC_ISP_GIC600_GICR_NSACR_NS_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int EnableGrp0_GICR : 1;
        unsigned int EnableGrp1NSecure : 1;
        unsigned int EnableGrp1Secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int AccessType : 1;
        unsigned int reserved_1 : 25;
        unsigned int wake_request : 1;
        unsigned int cpu_active : 1;
    } reg;
} SOC_ISP_GIC600_GICR_MISCSTATUSR_UNION;
#endif
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_EnableGrp0_GICR_START (0)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_EnableGrp0_GICR_END (0)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_EnableGrp1NSecure_START (1)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_EnableGrp1NSecure_END (1)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_EnableGrp1Secure_START (2)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_EnableGrp1Secure_END (2)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_AccessType_START (4)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_AccessType_END (4)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_wake_request_START (30)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_wake_request_END (30)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_cpu_active_START (31)
#define SOC_ISP_GIC600_GICR_MISCSTATUSR_cpu_active_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int valid_n : 32;
    } reg;
} SOC_ISP_GIC600_GICR_IERRVR_UNION;
#endif
#define SOC_ISP_GIC600_GICR_IERRVR_valid_n_START (0)
#define SOC_ISP_GIC600_GICR_IERRVR_valid_n_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int PPINumber : 9;
        unsigned int reserved : 2;
        unsigned int ECCSupport : 1;
        unsigned int TGT0ListWidth : 4;
        unsigned int Af0Width : 4;
        unsigned int Af1Width : 4;
        unsigned int Af2Width : 4;
        unsigned int Af3Width : 4;
    } reg;
} SOC_ISP_GIC600_GICR_CFGID0_UNION;
#endif
#define SOC_ISP_GIC600_GICR_CFGID0_PPINumber_START (0)
#define SOC_ISP_GIC600_GICR_CFGID0_PPINumber_END (8)
#define SOC_ISP_GIC600_GICR_CFGID0_ECCSupport_START (11)
#define SOC_ISP_GIC600_GICR_CFGID0_ECCSupport_END (11)
#define SOC_ISP_GIC600_GICR_CFGID0_TGT0ListWidth_START (12)
#define SOC_ISP_GIC600_GICR_CFGID0_TGT0ListWidth_END (15)
#define SOC_ISP_GIC600_GICR_CFGID0_Af0Width_START (16)
#define SOC_ISP_GIC600_GICR_CFGID0_Af0Width_END (19)
#define SOC_ISP_GIC600_GICR_CFGID0_Af1Width_START (20)
#define SOC_ISP_GIC600_GICR_CFGID0_Af1Width_END (23)
#define SOC_ISP_GIC600_GICR_CFGID0_Af2Width_START (24)
#define SOC_ISP_GIC600_GICR_CFGID0_Af2Width_END (27)
#define SOC_ISP_GIC600_GICR_CFGID0_Af3Width_START (28)
#define SOC_ISP_GIC600_GICR_CFGID0_Af3Width_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int NumCPUs : 8;
        unsigned int DirectUpstream : 1;
        unsigned int reserved_1 : 3;
        unsigned int PPIs_per_Processor : 4;
        unsigned int reserved_2 : 4;
        unsigned int UserValue : 4;
        unsigned int Version : 4;
    } reg;
} SOC_ISP_GIC600_GICR_CFGID1_UNION;
#endif
#define SOC_ISP_GIC600_GICR_CFGID1_NumCPUs_START (4)
#define SOC_ISP_GIC600_GICR_CFGID1_NumCPUs_END (11)
#define SOC_ISP_GIC600_GICR_CFGID1_DirectUpstream_START (12)
#define SOC_ISP_GIC600_GICR_CFGID1_DirectUpstream_END (12)
#define SOC_ISP_GIC600_GICR_CFGID1_PPIs_per_Processor_START (16)
#define SOC_ISP_GIC600_GICR_CFGID1_PPIs_per_Processor_END (19)
#define SOC_ISP_GIC600_GICR_CFGID1_UserValue_START (24)
#define SOC_ISP_GIC600_GICR_CFGID1_UserValue_END (27)
#define SOC_ISP_GIC600_GICR_CFGID1_Version_START (28)
#define SOC_ISP_GIC600_GICR_CFGID1_Version_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
