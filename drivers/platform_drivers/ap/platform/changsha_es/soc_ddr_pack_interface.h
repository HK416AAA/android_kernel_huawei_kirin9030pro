#ifndef __SOC_DDR_PACK_INTERFACE_H__
#define __SOC_DDR_PACK_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_PACK_REVISION_ADDR(base) (base)
#define SOC_DDR_PACK_PHYINITCTRL_ADDR(base) ((base) + 0x004UL)
#define SOC_DDR_PACK_PHYINITSTATUS_ADDR(base) ((base) + 0x008UL)
#define SOC_DDR_PACK_PHYCLKGATED_ADDR(base) ((base) + 0x000CUL)
#define SOC_DDR_PACK_PHYTIMER0_ADDR(base) ((base) + 0x010UL)
#define SOC_DDR_PACK_PHYTIMER1_ADDR(base) ((base) + 0x014UL)
#define SOC_DDR_PACK_PLLCTRL_ADDR(base) ((base) + 0x018UL)
#define SOC_DDR_PACK_PLLTIMER_ADDR(base) ((base) + 0x01CUL)
#define SOC_DDR_PACK_DLYMEASCTRL_ADDR(base) ((base) + 0x020UL)
#define SOC_DDR_PACK_IMPCTRL_ADDR(base) ((base) + 0x024UL)
#define SOC_DDR_PACK_IMPSTATUS_ADDR(base) ((base) + 0x028UL)
#define SOC_DDR_PACK_DRAMCFG_ADDR(base) ((base) + 0x02CUL)
#define SOC_DDR_PACK_DRAMTIMER0_ADDR(base) ((base) + 0x030UL)
#define SOC_DDR_PACK_DRAMTIMER1_ADDR(base) ((base) + 0x034UL)
#define SOC_DDR_PACK_DRAMTIMER2_ADDR(base) ((base) + 0x038UL)
#define SOC_DDR_PACK_DRAMTIMER3_ADDR(base) ((base) + 0x03CUL)
#define SOC_DDR_PACK_DRAMTIMER4_ADDR(base) ((base) + 0x040UL)
#define SOC_DDR_PACK_ODTCR_ADDR(base) ((base) + 0x044UL)
#define SOC_DDR_PACK_TRAINCTRL0_ADDR(base) ((base) + 0x048UL)
#define SOC_DDR_PACK_RANKEN_ADDR(base) ((base) + 0x04CUL)
#define SOC_DDR_PACK_TRAINMADDR_ADDR(base) ((base) + 0x0050UL)
#define SOC_DDR_PACK_BISTCTRL_ADDR(base) ((base) + 0x0054UL)
#define SOC_DDR_PACK_BISTDATA0_ADDR(base) ((base) + 0x0058UL)
#define SOC_DDR_PACK_BISTDATA1_ADDR(base) ((base) + 0x005CUL)
#define SOC_DDR_PACK_BISTSTATUS_ADDR(base) ((base) + 0x0060UL)
#define SOC_DDR_PACK_MODEREG01_ADDR(base) ((base) + 0x0064UL)
#define SOC_DDR_PACK_MODEREG23_ADDR(base) ((base) + 0x0068UL)
#define SOC_DDR_PACK_DETPATTERN_ADDR(base) ((base) + 0x006CUL)
#define SOC_DDR_PACK_MISC_ADDR(base) ((base) + 0x0070UL)
#define SOC_DDR_PACK_RNK2RNK_ADDR(base) ((base) + 0x0074UL)
#define SOC_DDR_PACK_PHYCTRL0_ADDR(base) ((base) + 0x0078UL)
#define SOC_DDR_PACK_PHYDBG_ADDR(base) ((base) + 0x007CUL)
#define SOC_DDR_PACK_RETCTRL0_ADDR(base) ((base) + 0x0080UL)
#define SOC_DDR_PACK_DMSEL_ADDR(base) ((base) + 0x0084UL)
#define SOC_DDR_PACK_TRAINCTRL8_ADDR(base) ((base) + 0x0088UL)
#define SOC_DDR_PACK_LPCTRL2_ADDR(base) ((base) + 0x008CUL)
#define SOC_DDR_PACK_TRAINCTRL9_ADDR(base) ((base) + 0x0090UL)
#define SOC_DDR_PACK_TRAINCTRL10_ADDR(base) ((base) + 0x094UL)
#define SOC_DDR_PACK_PHYPLLCTRL_AC_ADDR(base) ((base) + 0x0098UL)
#define SOC_DDR_PACK_PHYPLLCTRL_DX_ADDR(base) ((base) + 0x009CUL)
#define SOC_DDR_PACK_SWTMODE_ADDR(base) ((base) + 0x00A0UL)
#define SOC_DDR_PACK_SWTWLDQS_ADDR(base) ((base) + 0x00A4UL)
#define SOC_DDR_PACK_SWTRLT_ADDR(base) ((base) + 0x00A8UL)
#define SOC_DDR_PACK_PHYRSCTRL_ADDR(base) ((base) + 0x0B0UL)
#define SOC_DDR_PACK_BISTCTRL2_ADDR(base) ((base) + 0x00B4UL)
#define SOC_DDR_PACK_TRAINMADDRTG1_ADDR(base) ((base) + 0x00B8UL)
#define SOC_DDR_PACK_DRAMTIMER5_ADDR(base) ((base) + 0x0BCUL)
#define SOC_DDR_PACK_VREFTCTRL_ADDR(base) ((base) + 0x00C0UL)
#define SOC_DDR_PACK_DVRFTCTRL_ADDR(base) ((base) + 0x00C4UL)
#define SOC_DDR_PACK_HVRFTCTRL_ADDR(base) ((base) + 0x00C8UL)
#define SOC_DDR_PACK_TRAINCTRL1_ADDR(base) ((base) + 0x00D0UL)
#define SOC_DDR_PACK_TRAINCTRL2_ADDR(base) ((base) + 0x00D4UL)
#define SOC_DDR_PACK_REGBANKCTRL_ADDR(base) ((base) + 0x00D8UL)
#define SOC_DDR_PACK_TRAINCTRL3_ADDR(base) ((base) + 0x00DCUL)
#define SOC_DDR_PACK_MODEREG45_ADDR(base) ((base) + 0x00E0UL)
#define SOC_DDR_PACK_MODEREG67_ADDR(base) ((base) + 0x00E4UL)
#define SOC_DDR_PACK_TRAINCTRL6_ADDR(base) ((base) + 0x0E8UL)
#define SOC_DDR_PACK_DETPATINDEX_ADDR(base) ((base) + 0x00ECUL)
#define SOC_DDR_PACK_TRAINSTEP0_ADDR(base) ((base) + 0x00F4UL)
#define SOC_DDR_PACK_TRAINSTEP1_ADDR(base) ((base) + 0x00F8UL)
#define SOC_DDR_PACK_TRAINSTEP2_ADDR(base) ((base) + 0x00FCUL)
#define SOC_DDR_PACK_ACBISTCTRL0_ADDR(base) ((base) + 0x100UL)
#define SOC_DDR_PACK_ACBISTCTRL1_ADDR(base) ((base) + 0x104UL)
#define SOC_DDR_PACK_ACBISTSTS0_ADDR(base) ((base) + 0x108UL)
#define SOC_DDR_PACK_ACBISTSTS1_ADDR(base) ((base) + 0x10CUL)
#define SOC_DDR_PACK_WDXBOUND_DFS_ADDR(base) ((base) + 0x110UL)
#define SOC_DDR_PACK_TRAINCTRL4_ADDR(base) ((base) + 0x114UL)
#define SOC_DDR_PACK_TRAINCTRL5_ADDR(base) ((base) + 0x118UL)
#define SOC_DDR_PACK_TRAINCTRL7_ADDR(base) ((base) + 0x11CUL)
#define SOC_DDR_PACK_ACCMDBDL0_ADDR(base) ((base) + 0x120UL)
#define SOC_DDR_PACK_IMPOFFSET_ADDR(base) ((base) + 0x124UL)
#define SOC_DDR_PACK_ACCMDBDL5_ADDR(base) ((base) + 0x134UL)
#define SOC_DDR_PACK_ACCMDBDL6_ADDR(base) ((base) + 0x138UL)
#define SOC_DDR_PACK_ACCMDBDL7_ADDR(base) ((base) + 0x13CUL)
#define SOC_DDR_PACK_ACADDRBDL8_ADDR(base) ((base) + 0x160UL)
#define SOC_DDR_PACK_ACADDRBDL9_ADDR(base) ((base) + 0x164UL)
#define SOC_DDR_PACK_ACBISTCTRL2_ADDR(base) ((base) + 0x168UL)
#define SOC_DDR_PACK_PLLJTMT_ADDR(base) ((base) + 0x16CUL)
#define SOC_DDR_PACK_IMP_CTRL1_ADDR(base) ((base) + 0x170UL)
#define SOC_DDR_PACK_IMP_STATUS1_ADDR(base) ((base) + 0x174UL)
#define SOC_DDR_PACK_IMP_OUT_ADDR(base) ((base) + 0x178UL)
#define SOC_DDR_PACK_TRAINCTRL11_ADDR(base) ((base) + 0x017CUL)
#define SOC_DDR_PACK_FASTGDSRESULT0_ADDR(base) ((base) + 0x0180UL)
#define SOC_DDR_PACK_FASTGDSRESULT1_ADDR(base) ((base) + 0x0184UL)
#define SOC_DDR_PACK_FASTGTRESULT_ADDR(base) ((base) + 0x0188UL)
#define SOC_DDR_PACK_TRKDBG_ADDR(base) ((base) + 0x18CUL)
#define SOC_DDR_PACK_PACKDEBUG_ADDR(base) ((base) + 0x190UL)
#define SOC_DDR_PACK_ACPHYRSVDC_ADDR(base) ((base) + 0x0194UL)
#define SOC_DDR_PACK_ACPHYRSVDS_ADDR(base) ((base) + 0x0198UL)
#define SOC_DDR_PACK_SWMRRDATA_ADDR(base) ((base) + 0x019CUL)
#define SOC_DDR_PACK_WCKCTRL0_ADDR(base) ((base) + 0x1A0UL)
#define SOC_DDR_PACK_WCKCTRL1_ADDR(base) ((base) + 0x1A4UL)
#define SOC_DDR_PACK_DEVMODECFG_ADDR(base) ((base) + 0x01A8UL)
#define SOC_DDR_PACK_LPCTRL3_ADDR(base) ((base) + 0x01ACUL)
#define SOC_DDR_PACK_WCKCTRL2_ADDR(base) ((base) + 0x01B0UL)
#define SOC_DDR_PACK_CATBDLBOUND_ADDR(base) ((base) + 0x01B4UL)
#define SOC_DDR_PACK_CATSWAPINDEX_ADDR(base) ((base) + 0x01B8UL)
#define SOC_DDR_PACK_CATSWAPSEL_ADDR(base) ((base) + 0x01BCUL)
#define SOC_DDR_PACK_CATTIMER0_ADDR(base) ((base) + 0x01C0UL)
#define SOC_DDR_PACK_CATTIMER1_ADDR(base) ((base) + 0x01C4UL)
#define SOC_DDR_PACK_CATCONFIG_ADDR(base) ((base) + 0x01C8UL)
#define SOC_DDR_PACK_CATRESULT_ADDR(base) ((base) + 0x01CCUL)
#define SOC_DDR_PACK_PHYDQRESULT_ADDR(base) ((base) + 0x01D0UL)
#define SOC_DDR_PACK_ADDRPHBOUND_ADDR(base) ((base) + 0x01D4UL)
#define SOC_DDR_PACK_SWCATPATTERN_P_ADDR(base) ((base) + 0x01D8UL)
#define SOC_DDR_PACK_PACKDEBUG1_ADDR(base) ((base) + 0x01DCUL)
#define SOC_DDR_PACK_MRS_SEQ_PROG_ADDR(base) ((base) + 0x01E0UL)
#define SOC_DDR_PACK_LPCTRL_ADDR(base) ((base) + 0x01E4UL)
#define SOC_DDR_PACK_TRAINCTRL12_ADDR(base) ((base) + 0x01E8UL)
#define SOC_DDR_PACK_CATCONFIG1_ADDR(base) ((base) + 0x01ECUL)
#define SOC_DDR_PACK_AHVREFT_STATUS_ADDR(base) ((base) + 0x1F0UL)
#define SOC_DDR_PACK_ADVREF_STATUS_ADDR(base) ((base) + 0x1F4UL)
#define SOC_DDR_PACK_DLYMEASCTRL1_ADDR(base) ((base) + 0x1F8UL)
#define SOC_DDR_PACK_DFIMISCCTRL_ADDR(base) ((base) + 0x1FCUL)
#define SOC_DDR_PACK_DXNBISTCTRL_ADDR(base,n) ((base) + 0x200UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNBISTSTS_ADDR(base,n) ((base) + 0x204UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNCTRL_ADDR(base,n) ((base) + 0x208UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWECCBDL_ADDR(base,m,n) ((base) + 0x20CUL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNOEBDL_ADDR(base,m,n) ((base) + 0x228UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQSDLY_ADDR(base,n) ((base) + 0x22CUL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQSDLY_ADDR(base,m,n) ((base) + 0x230UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQDLY_ADDR(base,m,n) ((base) + 0x234UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWLSL_ADDR(base,m,n) ((base) + 0x238UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNGDS_ADDR(base,m,n) ((base) + 0x23CUL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQSGDLY_ADDR(base,m,n) ((base) + 0x240UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQNLB0_ADDR(base,n) ((base) + 0x244UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQSDLYSUB_ADDR(base,n) ((base) + 0x248UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDBOUND_ADDR(base,n) ((base) + 0x250UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWRBOUND_ADDR(base,n) ((base) + 0x254UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQNLB1_ADDR(base,n) ((base) + 0x25CUL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXDEBUG0_ADDR(base,n) ((base) + 0x268UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXDEBUG1_ADDR(base,n) ((base) + 0x26CUL + (n) * 0x80UL)
#define SOC_DDR_PACK_DVREFT_STATUS_ADDR(base,n) ((base) + 0x270UL + (n) * 0x80UL)
#define SOC_DDR_PACK_HVREFT_STATUS_ADDR(base,m,n) ((base) + 0x274UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNTRACKSTATUS_ADDR(base,m,n,l) ((base) + 0x278UL + (l) * 0x800UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_VREFT_BOUND_ADDR(base,n) ((base) + 0x27CUL + (n) * 0x80UL)
#define SOC_DDR_PACK_PLLSTATUS_ADDR(base) ((base) + 0x00ACUL)
#define SOC_DDR_PACK_BISTCTRL1_ADDR(base) ((base) + 0x00F0UL)
#define SOC_DDR_PACK_DETPATTERN1_ADDR(base) ((base) + 0x00CCUL)
#define SOC_DDR_PACK_APB_WR_MASK_INFO_ADDR(base) ((base) + 0x130UL)
#define SOC_DDR_PACK_REGMUXBYP_ADDR(base) ((base) + 0xF00UL)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_ADDR(base) ((base) + 0x300UL)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_ADDR(base) ((base) + 0x304UL)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_ADDR(base) ((base) + 0x310UL)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_ADDR(base) ((base) + 0x314UL)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_ADDR(base) ((base) + 0x318UL)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_ADDR(base) ((base) + 0x31CUL)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_ADDR(base) ((base) + 0x320UL)
#define SOC_DDR_PACK_DXNWDQNBDL0_ADDR(base,m,n) ((base) + 0x330UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQNBDL1_ADDR(base,m,n) ((base) + 0x334UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQNBDL2_ADDR(base,m,n) ((base) + 0x338UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQNBDL3_ADDR(base,m,n) ((base) + 0x33CUL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQNBDL4_ADDR(base,m,n) ((base) + 0x340UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQNBDL5_ADDR(base,m,n) ((base) + 0x344UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQNBDL6_ADDR(base,m,n) ((base) + 0x348UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQNBDL7_ADDR(base,m,n) ((base) + 0x34CUL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNWDQNBDL8_ADDR(base,m,n) ((base) + 0x350UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQNBDL0_ADDR(base,m,n,l) ((base) + 0x354UL + (l) * 0x800UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQNBDL1_ADDR(base,m,n,l) ((base) + 0x358UL + (l) * 0x800UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQNBDL2_ADDR(base,m,n,l) ((base) + 0x35CUL + (l) * 0x800UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQNBDL3_ADDR(base,m,n,l) ((base) + 0x360UL + (l) * 0x800UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQNBDL4_ADDR(base,m,n,l) ((base) + 0x364UL + (l) * 0x800UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQNBDL5_ADDR(base,m,n,l) ((base) + 0x368UL + (l) * 0x800UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQNBDL6_ADDR(base,m,n,l) ((base) + 0x36CUL + (l) * 0x800UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQNBDL7_ADDR(base,m,n,l) ((base) + 0x370UL + (l) * 0x800UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_DXNRDQNBDL8_ADDR(base,m,n,l) ((base) + 0x374UL + (l) * 0x800UL + (m) * 0x400UL + (n) * 0x80UL)
#define SOC_DDR_PACK_ACADDRBDL0_ADDR(base) ((base) + 0x378UL)
#define SOC_DDR_PACK_ACADDRBDL1_ADDR(base) ((base) + 0x37CUL)
#define SOC_DDR_PACK_ACADDRBDL2_ADDR(base) ((base) + 0x380UL)
#define SOC_DDR_PACK_ACADDRBDL3_ADDR(base) ((base) + 0x384UL)
#define SOC_DDR_PACK_ACADDRBDL4_ADDR(base) ((base) + 0x388UL)
#define SOC_DDR_PACK_ACADDRBDL5_ADDR(base) ((base) + 0x38CUL)
#define SOC_DDR_PACK_ACADDRBDL6_ADDR(base) ((base) + 0x390UL)
#define SOC_DDR_PACK_ACADDRBDL7_ADDR(base) ((base) + 0x394UL)
#define SOC_DDR_PACK_ACCS0BDL_ADDR(base) ((base) + 0x398UL)
#define SOC_DDR_PACK_ACCS1BDL_ADDR(base) ((base) + 0x39CUL)
#define SOC_DDR_PACK_ACCKE0BDL_ADDR(base) ((base) + 0x3A0UL)
#define SOC_DDR_PACK_ACCKE1BDL_ADDR(base) ((base) + 0x3A4UL)
#define SOC_DDR_PACK_WCKCTRL3_ADDR(base) ((base) + 0x3A8UL)
#define SOC_DDR_PACK_GATEDBYP_ADDR(base) ((base) + 0x3ACUL)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_ADDR(base) ((base) + 0x400UL)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_ADDR(base) ((base) + 0x404UL)
#define SOC_DDR_PACK_CFG_BHS_ACK_DLY_ADDR(base) ((base) + 0x408UL)
#define SOC_DDR_PACK_T_BHS_STATUS_ADDR(base) ((base) + 0x40CUL)
#define SOC_DDR_PACK_T_BHS_ON_B0_V0_ADDR(base) ((base) + 0x410UL)
#define SOC_DDR_PACK_T_BHS_ON_B0_V1_ADDR(base) ((base) + 0x414UL)
#define SOC_DDR_PACK_T_BHS_ON_B0_V2_ADDR(base) ((base) + 0x418UL)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_ADDR(base) ((base) + 0x41CUL)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_ADDR(base) ((base) + 0x420UL)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_ADDR(base) ((base) + 0x424UL)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG2_ADDR(base) ((base) + 0x428UL)
#define SOC_DDR_PACK_DRAMTIMER6_ADDR(base) ((base) + 0x42CUL)
#define SOC_DDR_PACK_T_BHS_ON_B1_V0_ADDR(base) ((base) + 0x430UL)
#define SOC_DDR_PACK_T_BHS_ON_B1_V1_ADDR(base) ((base) + 0x434UL)
#define SOC_DDR_PACK_T_BHS_ON_B1_V2_ADDR(base) ((base) + 0x438UL)
#define SOC_DDR_PACK_T_BHS_ON_MAX_MIN_ADDR(base) ((base) + 0x43CUL)
#define SOC_DDR_PACK_CFG_BHS_DLY1_ADDR(base) ((base) + 0x440UL)
#define SOC_DDR_PACK_CFG_BHS_DLY2_ADDR(base) ((base) + 0x444UL)
#define SOC_DDR_PACK_TRACKING_LATCH_EXT_ADDR(base) ((base) + 0x448UL)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG3_ADDR(base) ((base) + 0x44CUL)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG4_ADDR(base) ((base) + 0x450UL)
#define SOC_DDR_PACK_DRAMTIMER7_ADDR(base) ((base) + 0x454UL)
#define SOC_DDR_PACK_DLM_TOP_CTRL_ADDR(base) ((base) + 0x458UL)
#define SOC_DDR_PACK_DLM_TOP_DATAOUT_ADDR(base) ((base) + 0x45CUL)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_ADDR(base) ((base) + 0x460UL)
#define SOC_DDR_PACK_DLM_RESULT_THRESHOLD_SWIFT_TRK_ADDR(base) ((base) + 0x464UL)
#define SOC_DDR_PACK_DLM_RESULT_NEW_SWIFT_TRK_ADDR(base) ((base) + 0x468UL)
#define SOC_DDR_PACK_DLM_RESULT_OLD_SWIFT_TRK_ADDR(base) ((base) + 0x46CUL)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_ADDR(base) ((base) + 0x470UL)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_ADDR(base) ((base) + 0x474UL)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_ADDR(base) ((base) + 0x478UL)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_ADDR(base) ((base) + 0x47CUL)
#define SOC_DDR_PACK_SWIFT_TRK_STAT_ADDR(base) ((base) + 0x480UL)
#define SOC_DDR_PACK_SWIFT_TRK_DBG_OUT_ADDR(base) ((base) + 0x484UL)
#define SOC_DDR_PACK_PACK_TO_UA_SIG_ADDR(base) ((base) + 0x488UL)
#define SOC_DDR_PACK_NEW_RETRAIN_CFG_ADDR(base) ((base) + 0x48CUL)
#define SOC_DDR_PACK_CK_DELAY_CFG_ADDR(base) ((base) + 0x490UL)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_ADDR(base) ((base) + 0x494UL)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_ADDR(base,m,n) ((base) + 0x4A0UL + (m) * 0x8UL + (n) * 0x4UL)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ST_FROM_LAST_ADDR(base) ((base) + 0x4B0UL)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ND_FROM_LAST_ADDR(base) ((base) + 0x4B4UL)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_3RD_FROM_LAST_ADDR(base) ((base) + 0x4B8UL)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_4TH_FROM_LAST_ADDR(base) ((base) + 0x4BCUL)
#else
#define SOC_DDR_PACK_REVISION_ADDR(base) (base)
#define SOC_DDR_PACK_PHYINITCTRL_ADDR(base) ((base) + 0x004)
#define SOC_DDR_PACK_PHYINITSTATUS_ADDR(base) ((base) + 0x008)
#define SOC_DDR_PACK_PHYCLKGATED_ADDR(base) ((base) + 0x000C)
#define SOC_DDR_PACK_PHYTIMER0_ADDR(base) ((base) + 0x010)
#define SOC_DDR_PACK_PHYTIMER1_ADDR(base) ((base) + 0x014)
#define SOC_DDR_PACK_PLLCTRL_ADDR(base) ((base) + 0x018)
#define SOC_DDR_PACK_PLLTIMER_ADDR(base) ((base) + 0x01C)
#define SOC_DDR_PACK_DLYMEASCTRL_ADDR(base) ((base) + 0x020)
#define SOC_DDR_PACK_IMPCTRL_ADDR(base) ((base) + 0x024)
#define SOC_DDR_PACK_IMPSTATUS_ADDR(base) ((base) + 0x028)
#define SOC_DDR_PACK_DRAMCFG_ADDR(base) ((base) + 0x02C)
#define SOC_DDR_PACK_DRAMTIMER0_ADDR(base) ((base) + 0x030)
#define SOC_DDR_PACK_DRAMTIMER1_ADDR(base) ((base) + 0x034)
#define SOC_DDR_PACK_DRAMTIMER2_ADDR(base) ((base) + 0x038)
#define SOC_DDR_PACK_DRAMTIMER3_ADDR(base) ((base) + 0x03C)
#define SOC_DDR_PACK_DRAMTIMER4_ADDR(base) ((base) + 0x040)
#define SOC_DDR_PACK_ODTCR_ADDR(base) ((base) + 0x044)
#define SOC_DDR_PACK_TRAINCTRL0_ADDR(base) ((base) + 0x048)
#define SOC_DDR_PACK_RANKEN_ADDR(base) ((base) + 0x04C)
#define SOC_DDR_PACK_TRAINMADDR_ADDR(base) ((base) + 0x0050)
#define SOC_DDR_PACK_BISTCTRL_ADDR(base) ((base) + 0x0054)
#define SOC_DDR_PACK_BISTDATA0_ADDR(base) ((base) + 0x0058)
#define SOC_DDR_PACK_BISTDATA1_ADDR(base) ((base) + 0x005C)
#define SOC_DDR_PACK_BISTSTATUS_ADDR(base) ((base) + 0x0060)
#define SOC_DDR_PACK_MODEREG01_ADDR(base) ((base) + 0x0064)
#define SOC_DDR_PACK_MODEREG23_ADDR(base) ((base) + 0x0068)
#define SOC_DDR_PACK_DETPATTERN_ADDR(base) ((base) + 0x006C)
#define SOC_DDR_PACK_MISC_ADDR(base) ((base) + 0x0070)
#define SOC_DDR_PACK_RNK2RNK_ADDR(base) ((base) + 0x0074)
#define SOC_DDR_PACK_PHYCTRL0_ADDR(base) ((base) + 0x0078)
#define SOC_DDR_PACK_PHYDBG_ADDR(base) ((base) + 0x007C)
#define SOC_DDR_PACK_RETCTRL0_ADDR(base) ((base) + 0x0080)
#define SOC_DDR_PACK_DMSEL_ADDR(base) ((base) + 0x0084)
#define SOC_DDR_PACK_TRAINCTRL8_ADDR(base) ((base) + 0x0088)
#define SOC_DDR_PACK_LPCTRL2_ADDR(base) ((base) + 0x008C)
#define SOC_DDR_PACK_TRAINCTRL9_ADDR(base) ((base) + 0x0090)
#define SOC_DDR_PACK_TRAINCTRL10_ADDR(base) ((base) + 0x094)
#define SOC_DDR_PACK_PHYPLLCTRL_AC_ADDR(base) ((base) + 0x0098)
#define SOC_DDR_PACK_PHYPLLCTRL_DX_ADDR(base) ((base) + 0x009C)
#define SOC_DDR_PACK_SWTMODE_ADDR(base) ((base) + 0x00A0)
#define SOC_DDR_PACK_SWTWLDQS_ADDR(base) ((base) + 0x00A4)
#define SOC_DDR_PACK_SWTRLT_ADDR(base) ((base) + 0x00A8)
#define SOC_DDR_PACK_PHYRSCTRL_ADDR(base) ((base) + 0x0B0)
#define SOC_DDR_PACK_BISTCTRL2_ADDR(base) ((base) + 0x00B4)
#define SOC_DDR_PACK_TRAINMADDRTG1_ADDR(base) ((base) + 0x00B8)
#define SOC_DDR_PACK_DRAMTIMER5_ADDR(base) ((base) + 0x0BC)
#define SOC_DDR_PACK_VREFTCTRL_ADDR(base) ((base) + 0x00C0)
#define SOC_DDR_PACK_DVRFTCTRL_ADDR(base) ((base) + 0x00C4)
#define SOC_DDR_PACK_HVRFTCTRL_ADDR(base) ((base) + 0x00C8)
#define SOC_DDR_PACK_TRAINCTRL1_ADDR(base) ((base) + 0x00D0)
#define SOC_DDR_PACK_TRAINCTRL2_ADDR(base) ((base) + 0x00D4)
#define SOC_DDR_PACK_REGBANKCTRL_ADDR(base) ((base) + 0x00D8)
#define SOC_DDR_PACK_TRAINCTRL3_ADDR(base) ((base) + 0x00DC)
#define SOC_DDR_PACK_MODEREG45_ADDR(base) ((base) + 0x00E0)
#define SOC_DDR_PACK_MODEREG67_ADDR(base) ((base) + 0x00E4)
#define SOC_DDR_PACK_TRAINCTRL6_ADDR(base) ((base) + 0x0E8)
#define SOC_DDR_PACK_DETPATINDEX_ADDR(base) ((base) + 0x00EC)
#define SOC_DDR_PACK_TRAINSTEP0_ADDR(base) ((base) + 0x00F4)
#define SOC_DDR_PACK_TRAINSTEP1_ADDR(base) ((base) + 0x00F8)
#define SOC_DDR_PACK_TRAINSTEP2_ADDR(base) ((base) + 0x00FC)
#define SOC_DDR_PACK_ACBISTCTRL0_ADDR(base) ((base) + 0x100)
#define SOC_DDR_PACK_ACBISTCTRL1_ADDR(base) ((base) + 0x104)
#define SOC_DDR_PACK_ACBISTSTS0_ADDR(base) ((base) + 0x108)
#define SOC_DDR_PACK_ACBISTSTS1_ADDR(base) ((base) + 0x10C)
#define SOC_DDR_PACK_WDXBOUND_DFS_ADDR(base) ((base) + 0x110)
#define SOC_DDR_PACK_TRAINCTRL4_ADDR(base) ((base) + 0x114)
#define SOC_DDR_PACK_TRAINCTRL5_ADDR(base) ((base) + 0x118)
#define SOC_DDR_PACK_TRAINCTRL7_ADDR(base) ((base) + 0x11C)
#define SOC_DDR_PACK_ACCMDBDL0_ADDR(base) ((base) + 0x120)
#define SOC_DDR_PACK_IMPOFFSET_ADDR(base) ((base) + 0x124)
#define SOC_DDR_PACK_ACCMDBDL5_ADDR(base) ((base) + 0x134)
#define SOC_DDR_PACK_ACCMDBDL6_ADDR(base) ((base) + 0x138)
#define SOC_DDR_PACK_ACCMDBDL7_ADDR(base) ((base) + 0x13C)
#define SOC_DDR_PACK_ACADDRBDL8_ADDR(base) ((base) + 0x160)
#define SOC_DDR_PACK_ACADDRBDL9_ADDR(base) ((base) + 0x164)
#define SOC_DDR_PACK_ACBISTCTRL2_ADDR(base) ((base) + 0x168)
#define SOC_DDR_PACK_PLLJTMT_ADDR(base) ((base) + 0x16C)
#define SOC_DDR_PACK_IMP_CTRL1_ADDR(base) ((base) + 0x170)
#define SOC_DDR_PACK_IMP_STATUS1_ADDR(base) ((base) + 0x174)
#define SOC_DDR_PACK_IMP_OUT_ADDR(base) ((base) + 0x178)
#define SOC_DDR_PACK_TRAINCTRL11_ADDR(base) ((base) + 0x017C)
#define SOC_DDR_PACK_FASTGDSRESULT0_ADDR(base) ((base) + 0x0180)
#define SOC_DDR_PACK_FASTGDSRESULT1_ADDR(base) ((base) + 0x0184)
#define SOC_DDR_PACK_FASTGTRESULT_ADDR(base) ((base) + 0x0188)
#define SOC_DDR_PACK_TRKDBG_ADDR(base) ((base) + 0x18C)
#define SOC_DDR_PACK_PACKDEBUG_ADDR(base) ((base) + 0x190)
#define SOC_DDR_PACK_ACPHYRSVDC_ADDR(base) ((base) + 0x0194)
#define SOC_DDR_PACK_ACPHYRSVDS_ADDR(base) ((base) + 0x0198)
#define SOC_DDR_PACK_SWMRRDATA_ADDR(base) ((base) + 0x019C)
#define SOC_DDR_PACK_WCKCTRL0_ADDR(base) ((base) + 0x1A0)
#define SOC_DDR_PACK_WCKCTRL1_ADDR(base) ((base) + 0x1A4)
#define SOC_DDR_PACK_DEVMODECFG_ADDR(base) ((base) + 0x01A8)
#define SOC_DDR_PACK_LPCTRL3_ADDR(base) ((base) + 0x01AC)
#define SOC_DDR_PACK_WCKCTRL2_ADDR(base) ((base) + 0x01B0)
#define SOC_DDR_PACK_CATBDLBOUND_ADDR(base) ((base) + 0x01B4)
#define SOC_DDR_PACK_CATSWAPINDEX_ADDR(base) ((base) + 0x01B8)
#define SOC_DDR_PACK_CATSWAPSEL_ADDR(base) ((base) + 0x01BC)
#define SOC_DDR_PACK_CATTIMER0_ADDR(base) ((base) + 0x01C0)
#define SOC_DDR_PACK_CATTIMER1_ADDR(base) ((base) + 0x01C4)
#define SOC_DDR_PACK_CATCONFIG_ADDR(base) ((base) + 0x01C8)
#define SOC_DDR_PACK_CATRESULT_ADDR(base) ((base) + 0x01CC)
#define SOC_DDR_PACK_PHYDQRESULT_ADDR(base) ((base) + 0x01D0)
#define SOC_DDR_PACK_ADDRPHBOUND_ADDR(base) ((base) + 0x01D4)
#define SOC_DDR_PACK_SWCATPATTERN_P_ADDR(base) ((base) + 0x01D8)
#define SOC_DDR_PACK_PACKDEBUG1_ADDR(base) ((base) + 0x01DC)
#define SOC_DDR_PACK_MRS_SEQ_PROG_ADDR(base) ((base) + 0x01E0)
#define SOC_DDR_PACK_LPCTRL_ADDR(base) ((base) + 0x01E4)
#define SOC_DDR_PACK_TRAINCTRL12_ADDR(base) ((base) + 0x01E8)
#define SOC_DDR_PACK_CATCONFIG1_ADDR(base) ((base) + 0x01EC)
#define SOC_DDR_PACK_AHVREFT_STATUS_ADDR(base) ((base) + 0x1F0)
#define SOC_DDR_PACK_ADVREF_STATUS_ADDR(base) ((base) + 0x1F4)
#define SOC_DDR_PACK_DLYMEASCTRL1_ADDR(base) ((base) + 0x1F8)
#define SOC_DDR_PACK_DFIMISCCTRL_ADDR(base) ((base) + 0x1FC)
#define SOC_DDR_PACK_DXNBISTCTRL_ADDR(base,n) ((base) + 0x200 + (n) * 0x80)
#define SOC_DDR_PACK_DXNBISTSTS_ADDR(base,n) ((base) + 0x204 + (n) * 0x80)
#define SOC_DDR_PACK_DXNCTRL_ADDR(base,n) ((base) + 0x208 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWECCBDL_ADDR(base,m,n) ((base) + 0x20C + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNOEBDL_ADDR(base,m,n) ((base) + 0x228 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQSDLY_ADDR(base,n) ((base) + 0x22C + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQSDLY_ADDR(base,m,n) ((base) + 0x230 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQDLY_ADDR(base,m,n) ((base) + 0x234 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWLSL_ADDR(base,m,n) ((base) + 0x238 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNGDS_ADDR(base,m,n) ((base) + 0x23C + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQSGDLY_ADDR(base,m,n) ((base) + 0x240 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQNLB0_ADDR(base,n) ((base) + 0x244 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQSDLYSUB_ADDR(base,n) ((base) + 0x248 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDBOUND_ADDR(base,n) ((base) + 0x250 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWRBOUND_ADDR(base,n) ((base) + 0x254 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQNLB1_ADDR(base,n) ((base) + 0x25C + (n) * 0x80)
#define SOC_DDR_PACK_DXDEBUG0_ADDR(base,n) ((base) + 0x268 + (n) * 0x80)
#define SOC_DDR_PACK_DXDEBUG1_ADDR(base,n) ((base) + 0x26C + (n) * 0x80)
#define SOC_DDR_PACK_DVREFT_STATUS_ADDR(base,n) ((base) + 0x270 + (n) * 0x80)
#define SOC_DDR_PACK_HVREFT_STATUS_ADDR(base,m,n) ((base) + 0x274 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNTRACKSTATUS_ADDR(base,m,n,l) ((base) + 0x278 + (l) * 0x800 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_VREFT_BOUND_ADDR(base,n) ((base) + 0x27C + (n) * 0x80)
#define SOC_DDR_PACK_PLLSTATUS_ADDR(base) ((base) + 0x00AC)
#define SOC_DDR_PACK_BISTCTRL1_ADDR(base) ((base) + 0x00F0)
#define SOC_DDR_PACK_DETPATTERN1_ADDR(base) ((base) + 0x00CC)
#define SOC_DDR_PACK_APB_WR_MASK_INFO_ADDR(base) ((base) + 0x130)
#define SOC_DDR_PACK_REGMUXBYP_ADDR(base) ((base) + 0xF00)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_ADDR(base) ((base) + 0x300)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_ADDR(base) ((base) + 0x304)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_ADDR(base) ((base) + 0x310)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_ADDR(base) ((base) + 0x314)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_ADDR(base) ((base) + 0x318)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_ADDR(base) ((base) + 0x31C)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_ADDR(base) ((base) + 0x320)
#define SOC_DDR_PACK_DXNWDQNBDL0_ADDR(base,m,n) ((base) + 0x330 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQNBDL1_ADDR(base,m,n) ((base) + 0x334 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQNBDL2_ADDR(base,m,n) ((base) + 0x338 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQNBDL3_ADDR(base,m,n) ((base) + 0x33C + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQNBDL4_ADDR(base,m,n) ((base) + 0x340 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQNBDL5_ADDR(base,m,n) ((base) + 0x344 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQNBDL6_ADDR(base,m,n) ((base) + 0x348 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQNBDL7_ADDR(base,m,n) ((base) + 0x34C + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNWDQNBDL8_ADDR(base,m,n) ((base) + 0x350 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQNBDL0_ADDR(base,m,n,l) ((base) + 0x354 + (l) * 0x800 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQNBDL1_ADDR(base,m,n,l) ((base) + 0x358 + (l) * 0x800 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQNBDL2_ADDR(base,m,n,l) ((base) + 0x35C + (l) * 0x800 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQNBDL3_ADDR(base,m,n,l) ((base) + 0x360 + (l) * 0x800 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQNBDL4_ADDR(base,m,n,l) ((base) + 0x364 + (l) * 0x800 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQNBDL5_ADDR(base,m,n,l) ((base) + 0x368 + (l) * 0x800 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQNBDL6_ADDR(base,m,n,l) ((base) + 0x36C + (l) * 0x800 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQNBDL7_ADDR(base,m,n,l) ((base) + 0x370 + (l) * 0x800 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_DXNRDQNBDL8_ADDR(base,m,n,l) ((base) + 0x374 + (l) * 0x800 + (m) * 0x400 + (n) * 0x80)
#define SOC_DDR_PACK_ACADDRBDL0_ADDR(base) ((base) + 0x378)
#define SOC_DDR_PACK_ACADDRBDL1_ADDR(base) ((base) + 0x37C)
#define SOC_DDR_PACK_ACADDRBDL2_ADDR(base) ((base) + 0x380)
#define SOC_DDR_PACK_ACADDRBDL3_ADDR(base) ((base) + 0x384)
#define SOC_DDR_PACK_ACADDRBDL4_ADDR(base) ((base) + 0x388)
#define SOC_DDR_PACK_ACADDRBDL5_ADDR(base) ((base) + 0x38C)
#define SOC_DDR_PACK_ACADDRBDL6_ADDR(base) ((base) + 0x390)
#define SOC_DDR_PACK_ACADDRBDL7_ADDR(base) ((base) + 0x394)
#define SOC_DDR_PACK_ACCS0BDL_ADDR(base) ((base) + 0x398)
#define SOC_DDR_PACK_ACCS1BDL_ADDR(base) ((base) + 0x39C)
#define SOC_DDR_PACK_ACCKE0BDL_ADDR(base) ((base) + 0x3A0)
#define SOC_DDR_PACK_ACCKE1BDL_ADDR(base) ((base) + 0x3A4)
#define SOC_DDR_PACK_WCKCTRL3_ADDR(base) ((base) + 0x3A8)
#define SOC_DDR_PACK_GATEDBYP_ADDR(base) ((base) + 0x3AC)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_ADDR(base) ((base) + 0x400)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_ADDR(base) ((base) + 0x404)
#define SOC_DDR_PACK_CFG_BHS_ACK_DLY_ADDR(base) ((base) + 0x408)
#define SOC_DDR_PACK_T_BHS_STATUS_ADDR(base) ((base) + 0x40C)
#define SOC_DDR_PACK_T_BHS_ON_B0_V0_ADDR(base) ((base) + 0x410)
#define SOC_DDR_PACK_T_BHS_ON_B0_V1_ADDR(base) ((base) + 0x414)
#define SOC_DDR_PACK_T_BHS_ON_B0_V2_ADDR(base) ((base) + 0x418)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_ADDR(base) ((base) + 0x41C)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_ADDR(base) ((base) + 0x420)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_ADDR(base) ((base) + 0x424)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG2_ADDR(base) ((base) + 0x428)
#define SOC_DDR_PACK_DRAMTIMER6_ADDR(base) ((base) + 0x42C)
#define SOC_DDR_PACK_T_BHS_ON_B1_V0_ADDR(base) ((base) + 0x430)
#define SOC_DDR_PACK_T_BHS_ON_B1_V1_ADDR(base) ((base) + 0x434)
#define SOC_DDR_PACK_T_BHS_ON_B1_V2_ADDR(base) ((base) + 0x438)
#define SOC_DDR_PACK_T_BHS_ON_MAX_MIN_ADDR(base) ((base) + 0x43C)
#define SOC_DDR_PACK_CFG_BHS_DLY1_ADDR(base) ((base) + 0x440)
#define SOC_DDR_PACK_CFG_BHS_DLY2_ADDR(base) ((base) + 0x444)
#define SOC_DDR_PACK_TRACKING_LATCH_EXT_ADDR(base) ((base) + 0x448)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG3_ADDR(base) ((base) + 0x44C)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG4_ADDR(base) ((base) + 0x450)
#define SOC_DDR_PACK_DRAMTIMER7_ADDR(base) ((base) + 0x454)
#define SOC_DDR_PACK_DLM_TOP_CTRL_ADDR(base) ((base) + 0x458)
#define SOC_DDR_PACK_DLM_TOP_DATAOUT_ADDR(base) ((base) + 0x45C)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_ADDR(base) ((base) + 0x460)
#define SOC_DDR_PACK_DLM_RESULT_THRESHOLD_SWIFT_TRK_ADDR(base) ((base) + 0x464)
#define SOC_DDR_PACK_DLM_RESULT_NEW_SWIFT_TRK_ADDR(base) ((base) + 0x468)
#define SOC_DDR_PACK_DLM_RESULT_OLD_SWIFT_TRK_ADDR(base) ((base) + 0x46C)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_ADDR(base) ((base) + 0x470)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_ADDR(base) ((base) + 0x474)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_ADDR(base) ((base) + 0x478)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_ADDR(base) ((base) + 0x47C)
#define SOC_DDR_PACK_SWIFT_TRK_STAT_ADDR(base) ((base) + 0x480)
#define SOC_DDR_PACK_SWIFT_TRK_DBG_OUT_ADDR(base) ((base) + 0x484)
#define SOC_DDR_PACK_PACK_TO_UA_SIG_ADDR(base) ((base) + 0x488)
#define SOC_DDR_PACK_NEW_RETRAIN_CFG_ADDR(base) ((base) + 0x48C)
#define SOC_DDR_PACK_CK_DELAY_CFG_ADDR(base) ((base) + 0x490)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_ADDR(base) ((base) + 0x494)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_ADDR(base,m,n) ((base) + 0x4A0 + (m) * 0x8 + (n) * 0x4)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ST_FROM_LAST_ADDR(base) ((base) + 0x4B0)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ND_FROM_LAST_ADDR(base) ((base) + 0x4B4)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_3RD_FROM_LAST_ADDR(base) ((base) + 0x4B8)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_4TH_FROM_LAST_ADDR(base) ((base) + 0x4BC)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_PACK_UC_TRCTRL_ADDR(base) (base)
#define SOC_DDR_PACK_UC_TROPCTRL_ADDR(base) ((base) + 0x004UL)
#define SOC_DDR_PACK_UC_DTRSTSP_ADDR(base) ((base) + 0x008UL)
#define SOC_DDR_PACK_UC_TRSTATUS_ADDR(base) ((base) + 0x00CUL)
#define SOC_DDR_PACK_UC_CMDQCTRL_ADDR(base) ((base) + 0x010UL)
#define SOC_DDR_PACK_UC_CMP_RESBLST_ADDR(base) ((base) + 0x0014UL)
#define SOC_DDR_PACK_UC_APB_CAS_ADDR(base) ((base) + 0x020UL)
#define SOC_DDR_PACK_UC_APB_WDATA_ADDR(base) ((base) + 0x024UL)
#define SOC_DDR_PACK_UC_APB_RDATA_ADDR(base) ((base) + 0x028UL)
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_ADDR(base) ((base) + 0x030UL)
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_ADDR(base) ((base) + 0x034UL)
#define SOC_DDR_PACK_UC_CSRBDL_AUC_ADDR(base) ((base) + 0x038UL)
#define SOC_DDR_PACK_UC_WDQPHAUC_ADDR(base) ((base) + 0x040UL)
#define SOC_DDR_PACK_UC_WDQSPHAUC_ADDR(base) ((base) + 0x048UL)
#define SOC_DDR_PACK_UC_WDQSBDLAUC_ADDR(base) ((base) + 0x04CUL)
#define SOC_DDR_PACK_UC_WDLYOP_ADDR(base) ((base) + 0x050UL)
#define SOC_DDR_PACK_UC_DERT_STEP_ADDR(base) ((base) + 0x060UL)
#define SOC_DDR_PACK_UC_DERT_CFG_ADDR(base) ((base) + 0x064UL)
#define SOC_DDR_PACK_UC_DERT_INFO_ADDR(base) ((base) + 0x068UL)
#define SOC_DDR_PACK_UC_DERT_DBG_ADDR(base) ((base) + 0x06CUL)
#define SOC_DDR_PACK_UC_RDQSAUC_ADDR(base) ((base) + 0x080UL)
#define SOC_DDR_PACK_UC_RDQSGTXAUC_ADDR(base) ((base) + 0x084UL)
#define SOC_DDR_PACK_UC_RDQSGPHAUC_ADDR(base) ((base) + 0x088UL)
#define SOC_DDR_PACK_UC_RDQSGBDLAUC_ADDR(base) ((base) + 0x08CUL)
#define SOC_DDR_PACK_UC_RGDSAUC_ADDR(base) ((base) + 0x090UL)
#define SOC_DDR_PACK_UC_RDLYOP_ADDR(base) ((base) + 0x094UL)
#define SOC_DDR_PACK_UCSWTMODE_ADDR(base) ((base) + 0x0A0UL)
#define SOC_DDR_PACK_UCSWTWLDQS_ADDR(base) ((base) + 0x0A4UL)
#define SOC_DDR_PACK_UC_SWTRLT_ADDR(base) ((base) + 0x0A8UL)
#define SOC_DDR_PACK_UCSWMRRDATA_ADDR(base) ((base) + 0x0ACUL)
#define SOC_DDR_PACK_UCCATCONFIG_ADDR(base) ((base) + 0x0B0UL)
#define SOC_DDR_PACK_UCCATRESULT_ADDR(base) ((base) + 0x0B4UL)
#define SOC_DDR_PACK_UCPHYDQRESULT_ADDR(base) ((base) + 0x0B8UL)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_ADDR(base) ((base) + 0x0BCUL)
#define SOC_DDR_PACK_UCFASTGDSRLT0_ADDR(base) ((base) + 0x0C4UL)
#define SOC_DDR_PACK_UCFASTGDSRLT1_ADDR(base) ((base) + 0x0C8UL)
#define SOC_DDR_PACK_UCFASTGTRLT_ADDR(base) ((base) + 0x0CCUL)
#define SOC_DDR_PACK_UCTRKDBG_RDQS_ADDR(base) ((base) + 0x0D0UL)
#define SOC_DDR_PACK_UCTRKDBG_RDQSG0_ADDR(base) ((base) + 0x0D4UL)
#define SOC_DDR_PACK_UCTRKDBG_RDQSG1_ADDR(base) ((base) + 0x0D8UL)
#define SOC_DDR_PACK_UCDBG_PHYSTOP_ADDR(base) ((base) + 0x0DCUL)
#define SOC_DDR_PACK_UCDBG_PERBIT0_ADDR(base) ((base) + 0x0E0UL)
#define SOC_DDR_PACK_UCDBG_PERBIT1_ADDR(base) ((base) + 0x0E4UL)
#define SOC_DDR_PACK_UCDBG_PERBIT2_ADDR(base) ((base) + 0x0E8UL)
#define SOC_DDR_PACK_UCDBG_PERBIT3_ADDR(base) ((base) + 0x0ECUL)
#define SOC_DDR_PACK_UCDBG_PERBIT4_ADDR(base) ((base) + 0x0F0UL)
#define SOC_DDR_PACK_UCDBG_PERBIT5_ADDR(base) ((base) + 0x0F4UL)
#define SOC_DDR_PACK_UCDBG_PERBIT6_ADDR(base) ((base) + 0x0F8UL)
#define SOC_DDR_PACK_UCDBG_PERBIT7_ADDR(base) ((base) + 0x0FCUL)
#define SOC_DDR_PACK_UC_WDQNAUC_ADDR(base,n) ((base) + 0x100UL + (n) * 0x80UL)
#define SOC_DDR_PACK_UC_RDQNAUC_ADDR(base,n) ((base) + 0x104UL + (n) * 0x80UL)
#define SOC_DDR_PACK_UC_DTRSTS_ADDR(base,n) ((base) + 0x108UL + (n) * 0x80UL)
#define SOC_DDR_PACK_UC_WDQNAUC2_ADDR(base,n) ((base) + 0x10CUL + (n) * 0x80UL)
#define SOC_DDR_PACK_UC_RDQNAUC2_ADDR(base,n) ((base) + 0x110UL + (n) * 0x80UL)
#else
#define SOC_DDR_PACK_UC_TRCTRL_ADDR(base) (base)
#define SOC_DDR_PACK_UC_TROPCTRL_ADDR(base) ((base) + 0x004)
#define SOC_DDR_PACK_UC_DTRSTSP_ADDR(base) ((base) + 0x008)
#define SOC_DDR_PACK_UC_TRSTATUS_ADDR(base) ((base) + 0x00C)
#define SOC_DDR_PACK_UC_CMDQCTRL_ADDR(base) ((base) + 0x010)
#define SOC_DDR_PACK_UC_CMP_RESBLST_ADDR(base) ((base) + 0x0014)
#define SOC_DDR_PACK_UC_APB_CAS_ADDR(base) ((base) + 0x020)
#define SOC_DDR_PACK_UC_APB_WDATA_ADDR(base) ((base) + 0x024)
#define SOC_DDR_PACK_UC_APB_RDATA_ADDR(base) ((base) + 0x028)
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_ADDR(base) ((base) + 0x030)
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_ADDR(base) ((base) + 0x034)
#define SOC_DDR_PACK_UC_CSRBDL_AUC_ADDR(base) ((base) + 0x038)
#define SOC_DDR_PACK_UC_WDQPHAUC_ADDR(base) ((base) + 0x040)
#define SOC_DDR_PACK_UC_WDQSPHAUC_ADDR(base) ((base) + 0x048)
#define SOC_DDR_PACK_UC_WDQSBDLAUC_ADDR(base) ((base) + 0x04C)
#define SOC_DDR_PACK_UC_WDLYOP_ADDR(base) ((base) + 0x050)
#define SOC_DDR_PACK_UC_DERT_STEP_ADDR(base) ((base) + 0x060)
#define SOC_DDR_PACK_UC_DERT_CFG_ADDR(base) ((base) + 0x064)
#define SOC_DDR_PACK_UC_DERT_INFO_ADDR(base) ((base) + 0x068)
#define SOC_DDR_PACK_UC_DERT_DBG_ADDR(base) ((base) + 0x06C)
#define SOC_DDR_PACK_UC_RDQSAUC_ADDR(base) ((base) + 0x080)
#define SOC_DDR_PACK_UC_RDQSGTXAUC_ADDR(base) ((base) + 0x084)
#define SOC_DDR_PACK_UC_RDQSGPHAUC_ADDR(base) ((base) + 0x088)
#define SOC_DDR_PACK_UC_RDQSGBDLAUC_ADDR(base) ((base) + 0x08C)
#define SOC_DDR_PACK_UC_RGDSAUC_ADDR(base) ((base) + 0x090)
#define SOC_DDR_PACK_UC_RDLYOP_ADDR(base) ((base) + 0x094)
#define SOC_DDR_PACK_UCSWTMODE_ADDR(base) ((base) + 0x0A0)
#define SOC_DDR_PACK_UCSWTWLDQS_ADDR(base) ((base) + 0x0A4)
#define SOC_DDR_PACK_UC_SWTRLT_ADDR(base) ((base) + 0x0A8)
#define SOC_DDR_PACK_UCSWMRRDATA_ADDR(base) ((base) + 0x0AC)
#define SOC_DDR_PACK_UCCATCONFIG_ADDR(base) ((base) + 0x0B0)
#define SOC_DDR_PACK_UCCATRESULT_ADDR(base) ((base) + 0x0B4)
#define SOC_DDR_PACK_UCPHYDQRESULT_ADDR(base) ((base) + 0x0B8)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_ADDR(base) ((base) + 0x0BC)
#define SOC_DDR_PACK_UCFASTGDSRLT0_ADDR(base) ((base) + 0x0C4)
#define SOC_DDR_PACK_UCFASTGDSRLT1_ADDR(base) ((base) + 0x0C8)
#define SOC_DDR_PACK_UCFASTGTRLT_ADDR(base) ((base) + 0x0CC)
#define SOC_DDR_PACK_UCTRKDBG_RDQS_ADDR(base) ((base) + 0x0D0)
#define SOC_DDR_PACK_UCTRKDBG_RDQSG0_ADDR(base) ((base) + 0x0D4)
#define SOC_DDR_PACK_UCTRKDBG_RDQSG1_ADDR(base) ((base) + 0x0D8)
#define SOC_DDR_PACK_UCDBG_PHYSTOP_ADDR(base) ((base) + 0x0DC)
#define SOC_DDR_PACK_UCDBG_PERBIT0_ADDR(base) ((base) + 0x0E0)
#define SOC_DDR_PACK_UCDBG_PERBIT1_ADDR(base) ((base) + 0x0E4)
#define SOC_DDR_PACK_UCDBG_PERBIT2_ADDR(base) ((base) + 0x0E8)
#define SOC_DDR_PACK_UCDBG_PERBIT3_ADDR(base) ((base) + 0x0EC)
#define SOC_DDR_PACK_UCDBG_PERBIT4_ADDR(base) ((base) + 0x0F0)
#define SOC_DDR_PACK_UCDBG_PERBIT5_ADDR(base) ((base) + 0x0F4)
#define SOC_DDR_PACK_UCDBG_PERBIT6_ADDR(base) ((base) + 0x0F8)
#define SOC_DDR_PACK_UCDBG_PERBIT7_ADDR(base) ((base) + 0x0FC)
#define SOC_DDR_PACK_UC_WDQNAUC_ADDR(base,n) ((base) + 0x100 + (n) * 0x80)
#define SOC_DDR_PACK_UC_RDQNAUC_ADDR(base,n) ((base) + 0x104 + (n) * 0x80)
#define SOC_DDR_PACK_UC_DTRSTS_ADDR(base,n) ((base) + 0x108 + (n) * 0x80)
#define SOC_DDR_PACK_UC_WDQNAUC2_ADDR(base,n) ((base) + 0x10C + (n) * 0x80)
#define SOC_DDR_PACK_UC_RDQNAUC2_ADDR(base,n) ((base) + 0x110 + (n) * 0x80)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int minor : 8;
        unsigned int major : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PACK_REVISION_UNION;
#endif
#define SOC_DDR_PACK_REVISION_minor_START (0)
#define SOC_DDR_PACK_REVISION_minor_END (7)
#define SOC_DDR_PACK_REVISION_major_START (8)
#define SOC_DDR_PACK_REVISION_major_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int init_en : 1;
        unsigned int pll_init_en : 1;
        unsigned int dlymeas_en : 1;
        unsigned int zcal_en : 1;
        unsigned int wl_en : 1;
        unsigned int gt_en : 1;
        unsigned int gdst_en : 1;
        unsigned int wl2_en : 1;
        unsigned int rdet_en : 1;
        unsigned int wdet_en : 1;
        unsigned int dram_init_en : 1;
        unsigned int cat_en : 1;
        unsigned int dram_rst : 1;
        unsigned int phy_rst : 1;
        unsigned int pack_rst : 1;
        unsigned int phyconn_rst : 1;
        unsigned int dvreft_en : 1;
        unsigned int hvreft_en : 1;
        unsigned int dxdvrefs_en : 1;
        unsigned int acdvreft_en : 1;
        unsigned int achvreft_en : 1;
        unsigned int acdvrefs_en : 1;
        unsigned int cst_en : 1;
        unsigned int jtmt_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int sw_q_rst : 1;
        unsigned int reserved_3 : 2;
        unsigned int pic_phyupd_req : 1;
        unsigned int ctl_cke_bypass : 1;
    } reg;
} SOC_DDR_PACK_PHYINITCTRL_UNION;
#endif
#define SOC_DDR_PACK_PHYINITCTRL_init_en_START (0)
#define SOC_DDR_PACK_PHYINITCTRL_init_en_END (0)
#define SOC_DDR_PACK_PHYINITCTRL_pll_init_en_START (1)
#define SOC_DDR_PACK_PHYINITCTRL_pll_init_en_END (1)
#define SOC_DDR_PACK_PHYINITCTRL_dlymeas_en_START (2)
#define SOC_DDR_PACK_PHYINITCTRL_dlymeas_en_END (2)
#define SOC_DDR_PACK_PHYINITCTRL_zcal_en_START (3)
#define SOC_DDR_PACK_PHYINITCTRL_zcal_en_END (3)
#define SOC_DDR_PACK_PHYINITCTRL_wl_en_START (4)
#define SOC_DDR_PACK_PHYINITCTRL_wl_en_END (4)
#define SOC_DDR_PACK_PHYINITCTRL_gt_en_START (5)
#define SOC_DDR_PACK_PHYINITCTRL_gt_en_END (5)
#define SOC_DDR_PACK_PHYINITCTRL_gdst_en_START (6)
#define SOC_DDR_PACK_PHYINITCTRL_gdst_en_END (6)
#define SOC_DDR_PACK_PHYINITCTRL_wl2_en_START (7)
#define SOC_DDR_PACK_PHYINITCTRL_wl2_en_END (7)
#define SOC_DDR_PACK_PHYINITCTRL_rdet_en_START (8)
#define SOC_DDR_PACK_PHYINITCTRL_rdet_en_END (8)
#define SOC_DDR_PACK_PHYINITCTRL_wdet_en_START (9)
#define SOC_DDR_PACK_PHYINITCTRL_wdet_en_END (9)
#define SOC_DDR_PACK_PHYINITCTRL_dram_init_en_START (10)
#define SOC_DDR_PACK_PHYINITCTRL_dram_init_en_END (10)
#define SOC_DDR_PACK_PHYINITCTRL_cat_en_START (11)
#define SOC_DDR_PACK_PHYINITCTRL_cat_en_END (11)
#define SOC_DDR_PACK_PHYINITCTRL_dram_rst_START (12)
#define SOC_DDR_PACK_PHYINITCTRL_dram_rst_END (12)
#define SOC_DDR_PACK_PHYINITCTRL_phy_rst_START (13)
#define SOC_DDR_PACK_PHYINITCTRL_phy_rst_END (13)
#define SOC_DDR_PACK_PHYINITCTRL_pack_rst_START (14)
#define SOC_DDR_PACK_PHYINITCTRL_pack_rst_END (14)
#define SOC_DDR_PACK_PHYINITCTRL_phyconn_rst_START (15)
#define SOC_DDR_PACK_PHYINITCTRL_phyconn_rst_END (15)
#define SOC_DDR_PACK_PHYINITCTRL_dvreft_en_START (16)
#define SOC_DDR_PACK_PHYINITCTRL_dvreft_en_END (16)
#define SOC_DDR_PACK_PHYINITCTRL_hvreft_en_START (17)
#define SOC_DDR_PACK_PHYINITCTRL_hvreft_en_END (17)
#define SOC_DDR_PACK_PHYINITCTRL_dxdvrefs_en_START (18)
#define SOC_DDR_PACK_PHYINITCTRL_dxdvrefs_en_END (18)
#define SOC_DDR_PACK_PHYINITCTRL_acdvreft_en_START (19)
#define SOC_DDR_PACK_PHYINITCTRL_acdvreft_en_END (19)
#define SOC_DDR_PACK_PHYINITCTRL_achvreft_en_START (20)
#define SOC_DDR_PACK_PHYINITCTRL_achvreft_en_END (20)
#define SOC_DDR_PACK_PHYINITCTRL_acdvrefs_en_START (21)
#define SOC_DDR_PACK_PHYINITCTRL_acdvrefs_en_END (21)
#define SOC_DDR_PACK_PHYINITCTRL_cst_en_START (22)
#define SOC_DDR_PACK_PHYINITCTRL_cst_en_END (22)
#define SOC_DDR_PACK_PHYINITCTRL_jtmt_en_START (23)
#define SOC_DDR_PACK_PHYINITCTRL_jtmt_en_END (23)
#define SOC_DDR_PACK_PHYINITCTRL_sw_q_rst_START (27)
#define SOC_DDR_PACK_PHYINITCTRL_sw_q_rst_END (27)
#define SOC_DDR_PACK_PHYINITCTRL_pic_phyupd_req_START (30)
#define SOC_DDR_PACK_PHYINITCTRL_pic_phyupd_req_END (30)
#define SOC_DDR_PACK_PHYINITCTRL_ctl_cke_bypass_START (31)
#define SOC_DDR_PACK_PHYINITCTRL_ctl_cke_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wl2wdet_err : 1;
        unsigned int pll_lock_err : 1;
        unsigned int dlymeas_err : 1;
        unsigned int zcal_err : 1;
        unsigned int wl_err : 1;
        unsigned int gt_err : 1;
        unsigned int gdst_err : 1;
        unsigned int wl2_err : 1;
        unsigned int rdet_err : 1;
        unsigned int wdet_err : 1;
        unsigned int cat_err : 1;
        unsigned int fst_rdet_wrg : 1;
        unsigned int fst_rdet_err : 1;
        unsigned int wdert_wrg : 1;
        unsigned int wdert_err : 1;
        unsigned int reserved_0 : 7;
        unsigned int cst_err : 1;
        unsigned int reserved_1 : 5;
        unsigned int zcal_idle : 1;
        unsigned int dfi_phyupd_ack : 1;
        unsigned int dfi_phyupd_req : 1;
        unsigned int retrain_active : 1;
    } reg;
} SOC_DDR_PACK_PHYINITSTATUS_UNION;
#endif
#define SOC_DDR_PACK_PHYINITSTATUS_wl2wdet_err_START (0)
#define SOC_DDR_PACK_PHYINITSTATUS_wl2wdet_err_END (0)
#define SOC_DDR_PACK_PHYINITSTATUS_pll_lock_err_START (1)
#define SOC_DDR_PACK_PHYINITSTATUS_pll_lock_err_END (1)
#define SOC_DDR_PACK_PHYINITSTATUS_dlymeas_err_START (2)
#define SOC_DDR_PACK_PHYINITSTATUS_dlymeas_err_END (2)
#define SOC_DDR_PACK_PHYINITSTATUS_zcal_err_START (3)
#define SOC_DDR_PACK_PHYINITSTATUS_zcal_err_END (3)
#define SOC_DDR_PACK_PHYINITSTATUS_wl_err_START (4)
#define SOC_DDR_PACK_PHYINITSTATUS_wl_err_END (4)
#define SOC_DDR_PACK_PHYINITSTATUS_gt_err_START (5)
#define SOC_DDR_PACK_PHYINITSTATUS_gt_err_END (5)
#define SOC_DDR_PACK_PHYINITSTATUS_gdst_err_START (6)
#define SOC_DDR_PACK_PHYINITSTATUS_gdst_err_END (6)
#define SOC_DDR_PACK_PHYINITSTATUS_wl2_err_START (7)
#define SOC_DDR_PACK_PHYINITSTATUS_wl2_err_END (7)
#define SOC_DDR_PACK_PHYINITSTATUS_rdet_err_START (8)
#define SOC_DDR_PACK_PHYINITSTATUS_rdet_err_END (8)
#define SOC_DDR_PACK_PHYINITSTATUS_wdet_err_START (9)
#define SOC_DDR_PACK_PHYINITSTATUS_wdet_err_END (9)
#define SOC_DDR_PACK_PHYINITSTATUS_cat_err_START (10)
#define SOC_DDR_PACK_PHYINITSTATUS_cat_err_END (10)
#define SOC_DDR_PACK_PHYINITSTATUS_fst_rdet_wrg_START (11)
#define SOC_DDR_PACK_PHYINITSTATUS_fst_rdet_wrg_END (11)
#define SOC_DDR_PACK_PHYINITSTATUS_fst_rdet_err_START (12)
#define SOC_DDR_PACK_PHYINITSTATUS_fst_rdet_err_END (12)
#define SOC_DDR_PACK_PHYINITSTATUS_wdert_wrg_START (13)
#define SOC_DDR_PACK_PHYINITSTATUS_wdert_wrg_END (13)
#define SOC_DDR_PACK_PHYINITSTATUS_wdert_err_START (14)
#define SOC_DDR_PACK_PHYINITSTATUS_wdert_err_END (14)
#define SOC_DDR_PACK_PHYINITSTATUS_cst_err_START (22)
#define SOC_DDR_PACK_PHYINITSTATUS_cst_err_END (22)
#define SOC_DDR_PACK_PHYINITSTATUS_zcal_idle_START (28)
#define SOC_DDR_PACK_PHYINITSTATUS_zcal_idle_END (28)
#define SOC_DDR_PACK_PHYINITSTATUS_dfi_phyupd_ack_START (29)
#define SOC_DDR_PACK_PHYINITSTATUS_dfi_phyupd_ack_END (29)
#define SOC_DDR_PACK_PHYINITSTATUS_dfi_phyupd_req_START (30)
#define SOC_DDR_PACK_PHYINITSTATUS_dfi_phyupd_req_END (30)
#define SOC_DDR_PACK_PHYINITSTATUS_retrain_active_START (31)
#define SOC_DDR_PACK_PHYINITSTATUS_retrain_active_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dx_phy_clkgated : 4;
        unsigned int reserved_0 : 4;
        unsigned int ac_phy_clkgated : 1;
        unsigned int ck_phy_clkgated : 4;
        unsigned int dx_phgated_en : 1;
        unsigned int dx_phclkgated : 1;
        unsigned int dx_phgated_men : 1;
        unsigned int cfg_tx_gcnt : 8;
        unsigned int cfg_ca_gcnt : 4;
        unsigned int reserved_1 : 1;
        unsigned int cfg_dlymeas_gated : 1;
        unsigned int cfg_gcken_ca_rs : 1;
        unsigned int byp_pll_lock : 1;
    } reg;
} SOC_DDR_PACK_PHYCLKGATED_UNION;
#endif
#define SOC_DDR_PACK_PHYCLKGATED_dx_phy_clkgated_START (0)
#define SOC_DDR_PACK_PHYCLKGATED_dx_phy_clkgated_END (3)
#define SOC_DDR_PACK_PHYCLKGATED_ac_phy_clkgated_START (8)
#define SOC_DDR_PACK_PHYCLKGATED_ac_phy_clkgated_END (8)
#define SOC_DDR_PACK_PHYCLKGATED_ck_phy_clkgated_START (9)
#define SOC_DDR_PACK_PHYCLKGATED_ck_phy_clkgated_END (12)
#define SOC_DDR_PACK_PHYCLKGATED_dx_phgated_en_START (13)
#define SOC_DDR_PACK_PHYCLKGATED_dx_phgated_en_END (13)
#define SOC_DDR_PACK_PHYCLKGATED_dx_phclkgated_START (14)
#define SOC_DDR_PACK_PHYCLKGATED_dx_phclkgated_END (14)
#define SOC_DDR_PACK_PHYCLKGATED_dx_phgated_men_START (15)
#define SOC_DDR_PACK_PHYCLKGATED_dx_phgated_men_END (15)
#define SOC_DDR_PACK_PHYCLKGATED_cfg_tx_gcnt_START (16)
#define SOC_DDR_PACK_PHYCLKGATED_cfg_tx_gcnt_END (23)
#define SOC_DDR_PACK_PHYCLKGATED_cfg_ca_gcnt_START (24)
#define SOC_DDR_PACK_PHYCLKGATED_cfg_ca_gcnt_END (27)
#define SOC_DDR_PACK_PHYCLKGATED_cfg_dlymeas_gated_START (29)
#define SOC_DDR_PACK_PHYCLKGATED_cfg_dlymeas_gated_END (29)
#define SOC_DDR_PACK_PHYCLKGATED_cfg_gcken_ca_rs_START (30)
#define SOC_DDR_PACK_PHYCLKGATED_cfg_gcken_ca_rs_END (30)
#define SOC_DDR_PACK_PHYCLKGATED_byp_pll_lock_START (31)
#define SOC_DDR_PACK_PHYCLKGATED_byp_pll_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_dram_reset : 8;
        unsigned int reserved : 4;
        unsigned int t_dram_cke_high : 20;
    } reg;
} SOC_DDR_PACK_PHYTIMER0_UNION;
#endif
#define SOC_DDR_PACK_PHYTIMER0_t_dram_reset_START (0)
#define SOC_DDR_PACK_PHYTIMER0_t_dram_reset_END (7)
#define SOC_DDR_PACK_PHYTIMER0_t_dram_cke_high_START (12)
#define SOC_DDR_PACK_PHYTIMER0_t_dram_cke_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_dram_cke_low : 20;
        unsigned int reserved : 8;
        unsigned int tckelck : 4;
    } reg;
} SOC_DDR_PACK_PHYTIMER1_UNION;
#endif
#define SOC_DDR_PACK_PHYTIMER1_t_dram_cke_low_START (0)
#define SOC_DDR_PACK_PHYTIMER1_t_dram_cke_low_END (19)
#define SOC_DDR_PACK_PHYTIMER1_tckelck_START (28)
#define SOC_DDR_PACK_PHYTIMER1_tckelck_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_pwdn : 3;
        unsigned int reserved_0 : 13;
        unsigned int lv3_pllpd_deassert_time : 4;
        unsigned int reserved_1 : 4;
        unsigned int dx_pll_powerdown_23 : 2;
        unsigned int reserved_2 : 2;
        unsigned int dx_pll_powerdown_47 : 4;
    } reg;
} SOC_DDR_PACK_PLLCTRL_UNION;
#endif
#define SOC_DDR_PACK_PLLCTRL_pll_pwdn_START (0)
#define SOC_DDR_PACK_PLLCTRL_pll_pwdn_END (2)
#define SOC_DDR_PACK_PLLCTRL_lv3_pllpd_deassert_time_START (16)
#define SOC_DDR_PACK_PLLCTRL_lv3_pllpd_deassert_time_END (19)
#define SOC_DDR_PACK_PLLCTRL_dx_pll_powerdown_23_START (24)
#define SOC_DDR_PACK_PLLCTRL_dx_pll_powerdown_23_END (25)
#define SOC_DDR_PACK_PLLCTRL_dx_pll_powerdown_47_START (28)
#define SOC_DDR_PACK_PLLCTRL_dx_pll_powerdown_47_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_pll_rst : 8;
        unsigned int reserved : 8;
        unsigned int t_pll_lock : 16;
    } reg;
} SOC_DDR_PACK_PLLTIMER_UNION;
#endif
#define SOC_DDR_PACK_PLLTIMER_t_pll_rst_START (0)
#define SOC_DDR_PACK_PLLTIMER_t_pll_rst_END (7)
#define SOC_DDR_PACK_PLLTIMER_t_pll_lock_START (16)
#define SOC_DDR_PACK_PLLTIMER_t_pll_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dly_meas_type : 1;
        unsigned int dly_track_type : 1;
        unsigned int dlytrack_dqsgth : 2;
        unsigned int dynamic_dqsgen : 1;
        unsigned int dynamic_dqsen : 1;
        unsigned int dly_meas_type_2T : 2;
        unsigned int dly_track_limit : 7;
        unsigned int dynamic_dqsg_ph_only : 1;
        unsigned int dynamic_dqsg_ph_dis : 1;
        unsigned int dynamic_dqs_cyc_dis : 1;
        unsigned int dynamic_dqsbdl30_dis : 1;
        unsigned int cfg_dyn_track_upt_mode : 1;
        unsigned int dlytrack_dqsth : 2;
        unsigned int dlytrack_dqsg_tap : 2;
        unsigned int dlytrack_dqs_tap : 2;
        unsigned int dlytrack_cyc_tap : 4;
        unsigned int rdqsg_mondly_type : 2;
    } reg;
} SOC_DDR_PACK_DLYMEASCTRL_UNION;
#endif
#define SOC_DDR_PACK_DLYMEASCTRL_dly_meas_type_START (0)
#define SOC_DDR_PACK_DLYMEASCTRL_dly_meas_type_END (0)
#define SOC_DDR_PACK_DLYMEASCTRL_dly_track_type_START (1)
#define SOC_DDR_PACK_DLYMEASCTRL_dly_track_type_END (1)
#define SOC_DDR_PACK_DLYMEASCTRL_dlytrack_dqsgth_START (2)
#define SOC_DDR_PACK_DLYMEASCTRL_dlytrack_dqsgth_END (3)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqsgen_START (4)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqsgen_END (4)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqsen_START (5)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqsen_END (5)
#define SOC_DDR_PACK_DLYMEASCTRL_dly_meas_type_2T_START (6)
#define SOC_DDR_PACK_DLYMEASCTRL_dly_meas_type_2T_END (7)
#define SOC_DDR_PACK_DLYMEASCTRL_dly_track_limit_START (8)
#define SOC_DDR_PACK_DLYMEASCTRL_dly_track_limit_END (14)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqsg_ph_only_START (15)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqsg_ph_only_END (15)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqsg_ph_dis_START (16)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqsg_ph_dis_END (16)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqs_cyc_dis_START (17)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqs_cyc_dis_END (17)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqsbdl30_dis_START (18)
#define SOC_DDR_PACK_DLYMEASCTRL_dynamic_dqsbdl30_dis_END (18)
#define SOC_DDR_PACK_DLYMEASCTRL_cfg_dyn_track_upt_mode_START (19)
#define SOC_DDR_PACK_DLYMEASCTRL_cfg_dyn_track_upt_mode_END (19)
#define SOC_DDR_PACK_DLYMEASCTRL_dlytrack_dqsth_START (20)
#define SOC_DDR_PACK_DLYMEASCTRL_dlytrack_dqsth_END (21)
#define SOC_DDR_PACK_DLYMEASCTRL_dlytrack_dqsg_tap_START (22)
#define SOC_DDR_PACK_DLYMEASCTRL_dlytrack_dqsg_tap_END (23)
#define SOC_DDR_PACK_DLYMEASCTRL_dlytrack_dqs_tap_START (24)
#define SOC_DDR_PACK_DLYMEASCTRL_dlytrack_dqs_tap_END (25)
#define SOC_DDR_PACK_DLYMEASCTRL_dlytrack_cyc_tap_START (26)
#define SOC_DDR_PACK_DLYMEASCTRL_dlytrack_cyc_tap_END (29)
#define SOC_DDR_PACK_DLYMEASCTRL_rdqsg_mondly_type_START (30)
#define SOC_DDR_PACK_DLYMEASCTRL_rdqsg_mondly_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int zcomp_rsp_dly : 6;
        unsigned int tzcomp_upddly : 6;
        unsigned int zcomp_num : 4;
        unsigned int zcalrt_range : 8;
        unsigned int zcal_result_sel : 1;
        unsigned int zcal_nlatch_inv : 1;
        unsigned int zcal_platch_inv : 1;
        unsigned int zcal_pnsequence : 1;
        unsigned int zcal_errstopup : 1;
        unsigned int zcalrt_updckelh_dis : 1;
        unsigned int zcalrt_en : 1;
        unsigned int zcfuzzy_en : 1;
    } reg;
} SOC_DDR_PACK_IMPCTRL_UNION;
#endif
#define SOC_DDR_PACK_IMPCTRL_zcomp_rsp_dly_START (0)
#define SOC_DDR_PACK_IMPCTRL_zcomp_rsp_dly_END (5)
#define SOC_DDR_PACK_IMPCTRL_tzcomp_upddly_START (6)
#define SOC_DDR_PACK_IMPCTRL_tzcomp_upddly_END (11)
#define SOC_DDR_PACK_IMPCTRL_zcomp_num_START (12)
#define SOC_DDR_PACK_IMPCTRL_zcomp_num_END (15)
#define SOC_DDR_PACK_IMPCTRL_zcalrt_range_START (16)
#define SOC_DDR_PACK_IMPCTRL_zcalrt_range_END (23)
#define SOC_DDR_PACK_IMPCTRL_zcal_result_sel_START (24)
#define SOC_DDR_PACK_IMPCTRL_zcal_result_sel_END (24)
#define SOC_DDR_PACK_IMPCTRL_zcal_nlatch_inv_START (25)
#define SOC_DDR_PACK_IMPCTRL_zcal_nlatch_inv_END (25)
#define SOC_DDR_PACK_IMPCTRL_zcal_platch_inv_START (26)
#define SOC_DDR_PACK_IMPCTRL_zcal_platch_inv_END (26)
#define SOC_DDR_PACK_IMPCTRL_zcal_pnsequence_START (27)
#define SOC_DDR_PACK_IMPCTRL_zcal_pnsequence_END (27)
#define SOC_DDR_PACK_IMPCTRL_zcal_errstopup_START (28)
#define SOC_DDR_PACK_IMPCTRL_zcal_errstopup_END (28)
#define SOC_DDR_PACK_IMPCTRL_zcalrt_updckelh_dis_START (29)
#define SOC_DDR_PACK_IMPCTRL_zcalrt_updckelh_dis_END (29)
#define SOC_DDR_PACK_IMPCTRL_zcalrt_en_START (30)
#define SOC_DDR_PACK_IMPCTRL_zcalrt_en_END (30)
#define SOC_DDR_PACK_IMPCTRL_zcfuzzy_en_START (31)
#define SOC_DDR_PACK_IMPCTRL_zcfuzzy_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int zcode_ndrv : 6;
        unsigned int swrt_ndrv_update : 1;
        unsigned int ndrv_cal_result : 1;
        unsigned int zcode_ndrv_cal : 7;
        unsigned int swrt_pdrv_update : 1;
        unsigned int zcode_pdrv : 7;
        unsigned int pdrv_cal_result : 1;
        unsigned int zcode_pdrv_cal : 8;
    } reg;
} SOC_DDR_PACK_IMPSTATUS_UNION;
#endif
#define SOC_DDR_PACK_IMPSTATUS_zcode_ndrv_START (0)
#define SOC_DDR_PACK_IMPSTATUS_zcode_ndrv_END (5)
#define SOC_DDR_PACK_IMPSTATUS_swrt_ndrv_update_START (6)
#define SOC_DDR_PACK_IMPSTATUS_swrt_ndrv_update_END (6)
#define SOC_DDR_PACK_IMPSTATUS_ndrv_cal_result_START (7)
#define SOC_DDR_PACK_IMPSTATUS_ndrv_cal_result_END (7)
#define SOC_DDR_PACK_IMPSTATUS_zcode_ndrv_cal_START (8)
#define SOC_DDR_PACK_IMPSTATUS_zcode_ndrv_cal_END (14)
#define SOC_DDR_PACK_IMPSTATUS_swrt_pdrv_update_START (15)
#define SOC_DDR_PACK_IMPSTATUS_swrt_pdrv_update_END (15)
#define SOC_DDR_PACK_IMPSTATUS_zcode_pdrv_START (16)
#define SOC_DDR_PACK_IMPSTATUS_zcode_pdrv_END (22)
#define SOC_DDR_PACK_IMPSTATUS_pdrv_cal_result_START (23)
#define SOC_DDR_PACK_IMPSTATUS_pdrv_cal_result_END (23)
#define SOC_DDR_PACK_IMPSTATUS_zcode_pdrv_cal_START (24)
#define SOC_DDR_PACK_IMPSTATUS_zcode_pdrv_cal_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dram_type : 3;
        unsigned int dram_type_exd : 1;
        unsigned int nosra : 1;
        unsigned int ma2t : 1;
        unsigned int maddr_mir : 1;
        unsigned int lpddr23_mrw11_en : 1;
        unsigned int lpddr23_pre_en : 1;
        unsigned int lpddr23_mrw1617_en : 1;
        unsigned int lpddr23_zqc_en : 1;
        unsigned int lpddr23_mrw_rst_ca3t : 1;
        unsigned int lpddr23_early_cat_en : 1;
        unsigned int ddr4par_en : 1;
        unsigned int mrs_seq_prog_en : 1;
        unsigned int lpddr5_blen : 1;
        unsigned int cfg_tppd : 3;
        unsigned int reserved : 4;
        unsigned int cfg_rfm_en : 1;
        unsigned int zqc_latch_only : 1;
        unsigned int lp5_pdex_dis : 1;
        unsigned int zqc_ranken : 2;
        unsigned int cfg_lp4_R17en : 2;
        unsigned int cfg_lp4_R18en : 2;
    } reg;
} SOC_DDR_PACK_DRAMCFG_UNION;
#endif
#define SOC_DDR_PACK_DRAMCFG_dram_type_START (0)
#define SOC_DDR_PACK_DRAMCFG_dram_type_END (2)
#define SOC_DDR_PACK_DRAMCFG_dram_type_exd_START (3)
#define SOC_DDR_PACK_DRAMCFG_dram_type_exd_END (3)
#define SOC_DDR_PACK_DRAMCFG_nosra_START (4)
#define SOC_DDR_PACK_DRAMCFG_nosra_END (4)
#define SOC_DDR_PACK_DRAMCFG_ma2t_START (5)
#define SOC_DDR_PACK_DRAMCFG_ma2t_END (5)
#define SOC_DDR_PACK_DRAMCFG_maddr_mir_START (6)
#define SOC_DDR_PACK_DRAMCFG_maddr_mir_END (6)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_mrw11_en_START (7)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_mrw11_en_END (7)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_pre_en_START (8)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_pre_en_END (8)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_mrw1617_en_START (9)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_mrw1617_en_END (9)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_zqc_en_START (10)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_zqc_en_END (10)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_mrw_rst_ca3t_START (11)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_mrw_rst_ca3t_END (11)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_early_cat_en_START (12)
#define SOC_DDR_PACK_DRAMCFG_lpddr23_early_cat_en_END (12)
#define SOC_DDR_PACK_DRAMCFG_ddr4par_en_START (13)
#define SOC_DDR_PACK_DRAMCFG_ddr4par_en_END (13)
#define SOC_DDR_PACK_DRAMCFG_mrs_seq_prog_en_START (14)
#define SOC_DDR_PACK_DRAMCFG_mrs_seq_prog_en_END (14)
#define SOC_DDR_PACK_DRAMCFG_lpddr5_blen_START (15)
#define SOC_DDR_PACK_DRAMCFG_lpddr5_blen_END (15)
#define SOC_DDR_PACK_DRAMCFG_cfg_tppd_START (16)
#define SOC_DDR_PACK_DRAMCFG_cfg_tppd_END (18)
#define SOC_DDR_PACK_DRAMCFG_cfg_rfm_en_START (23)
#define SOC_DDR_PACK_DRAMCFG_cfg_rfm_en_END (23)
#define SOC_DDR_PACK_DRAMCFG_zqc_latch_only_START (24)
#define SOC_DDR_PACK_DRAMCFG_zqc_latch_only_END (24)
#define SOC_DDR_PACK_DRAMCFG_lp5_pdex_dis_START (25)
#define SOC_DDR_PACK_DRAMCFG_lp5_pdex_dis_END (25)
#define SOC_DDR_PACK_DRAMCFG_zqc_ranken_START (26)
#define SOC_DDR_PACK_DRAMCFG_zqc_ranken_END (27)
#define SOC_DDR_PACK_DRAMCFG_cfg_lp4_R17en_START (28)
#define SOC_DDR_PACK_DRAMCFG_cfg_lp4_R17en_END (29)
#define SOC_DDR_PACK_DRAMCFG_cfg_lp4_R18en_START (30)
#define SOC_DDR_PACK_DRAMCFG_cfg_lp4_R18en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_rtp : 4;
        unsigned int t_wtr : 4;
        unsigned int t_rp : 4;
        unsigned int t_rcd : 4;
        unsigned int t_ras : 6;
        unsigned int t_rrd : 4;
        unsigned int t_rc : 6;
    } reg;
} SOC_DDR_PACK_DRAMTIMER0_UNION;
#endif
#define SOC_DDR_PACK_DRAMTIMER0_t_rtp_START (0)
#define SOC_DDR_PACK_DRAMTIMER0_t_rtp_END (3)
#define SOC_DDR_PACK_DRAMTIMER0_t_wtr_START (4)
#define SOC_DDR_PACK_DRAMTIMER0_t_wtr_END (7)
#define SOC_DDR_PACK_DRAMTIMER0_t_rp_START (8)
#define SOC_DDR_PACK_DRAMTIMER0_t_rp_END (11)
#define SOC_DDR_PACK_DRAMTIMER0_t_rcd_START (12)
#define SOC_DDR_PACK_DRAMTIMER0_t_rcd_END (15)
#define SOC_DDR_PACK_DRAMTIMER0_t_ras_START (16)
#define SOC_DDR_PACK_DRAMTIMER0_t_ras_END (21)
#define SOC_DDR_PACK_DRAMTIMER0_t_rrd_START (22)
#define SOC_DDR_PACK_DRAMTIMER0_t_rrd_END (25)
#define SOC_DDR_PACK_DRAMTIMER0_t_rc_START (26)
#define SOC_DDR_PACK_DRAMTIMER0_t_rc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_mrd : 4;
        unsigned int t_mod : 6;
        unsigned int t_faw : 6;
        unsigned int t_rfc : 9;
        unsigned int t_rtw : 7;
    } reg;
} SOC_DDR_PACK_DRAMTIMER1_UNION;
#endif
#define SOC_DDR_PACK_DRAMTIMER1_t_mrd_START (0)
#define SOC_DDR_PACK_DRAMTIMER1_t_mrd_END (3)
#define SOC_DDR_PACK_DRAMTIMER1_t_mod_START (4)
#define SOC_DDR_PACK_DRAMTIMER1_t_mod_END (9)
#define SOC_DDR_PACK_DRAMTIMER1_t_faw_START (10)
#define SOC_DDR_PACK_DRAMTIMER1_t_faw_END (15)
#define SOC_DDR_PACK_DRAMTIMER1_t_rfc_START (16)
#define SOC_DDR_PACK_DRAMTIMER1_t_rfc_END (24)
#define SOC_DDR_PACK_DRAMTIMER1_t_rtw_START (25)
#define SOC_DDR_PACK_DRAMTIMER1_t_rtw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_xs : 10;
        unsigned int t_xp : 5;
        unsigned int reserved_0: 1;
        unsigned int t_cke : 4;
        unsigned int t_dllk : 10;
        unsigned int reserved_1: 1;
        unsigned int t_ccd : 1;
    } reg;
} SOC_DDR_PACK_DRAMTIMER2_UNION;
#endif
#define SOC_DDR_PACK_DRAMTIMER2_t_xs_START (0)
#define SOC_DDR_PACK_DRAMTIMER2_t_xs_END (9)
#define SOC_DDR_PACK_DRAMTIMER2_t_xp_START (10)
#define SOC_DDR_PACK_DRAMTIMER2_t_xp_END (14)
#define SOC_DDR_PACK_DRAMTIMER2_t_cke_START (16)
#define SOC_DDR_PACK_DRAMTIMER2_t_cke_END (19)
#define SOC_DDR_PACK_DRAMTIMER2_t_dllk_START (20)
#define SOC_DDR_PACK_DRAMTIMER2_t_dllk_END (29)
#define SOC_DDR_PACK_DRAMTIMER2_t_ccd_START (31)
#define SOC_DDR_PACK_DRAMTIMER2_t_ccd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_zcal : 10;
        unsigned int t_init5 : 14;
        unsigned int tdshtrain : 4;
        unsigned int t_wr : 4;
    } reg;
} SOC_DDR_PACK_DRAMTIMER3_UNION;
#endif
#define SOC_DDR_PACK_DRAMTIMER3_t_zcal_START (0)
#define SOC_DDR_PACK_DRAMTIMER3_t_zcal_END (9)
#define SOC_DDR_PACK_DRAMTIMER3_t_init5_START (10)
#define SOC_DDR_PACK_DRAMTIMER3_t_init5_END (23)
#define SOC_DDR_PACK_DRAMTIMER3_tdshtrain_START (24)
#define SOC_DDR_PACK_DRAMTIMER3_tdshtrain_END (27)
#define SOC_DDR_PACK_DRAMTIMER3_t_wr_START (28)
#define SOC_DDR_PACK_DRAMTIMER3_t_wr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_wlmrd : 6;
        unsigned int t_wr_ext : 1;
        unsigned int t_wlo : 5;
        unsigned int t_odt : 4;
        unsigned int t_ccd_s : 4;
        unsigned int t_vref : 3;
        unsigned int reserved : 1;
        unsigned int t_odton : 4;
        unsigned int t_ccd_ddr4 : 4;
    } reg;
} SOC_DDR_PACK_DRAMTIMER4_UNION;
#endif
#define SOC_DDR_PACK_DRAMTIMER4_t_wlmrd_START (0)
#define SOC_DDR_PACK_DRAMTIMER4_t_wlmrd_END (5)
#define SOC_DDR_PACK_DRAMTIMER4_t_wr_ext_START (6)
#define SOC_DDR_PACK_DRAMTIMER4_t_wr_ext_END (6)
#define SOC_DDR_PACK_DRAMTIMER4_t_wlo_START (7)
#define SOC_DDR_PACK_DRAMTIMER4_t_wlo_END (11)
#define SOC_DDR_PACK_DRAMTIMER4_t_odt_START (12)
#define SOC_DDR_PACK_DRAMTIMER4_t_odt_END (15)
#define SOC_DDR_PACK_DRAMTIMER4_t_ccd_s_START (16)
#define SOC_DDR_PACK_DRAMTIMER4_t_ccd_s_END (19)
#define SOC_DDR_PACK_DRAMTIMER4_t_vref_START (20)
#define SOC_DDR_PACK_DRAMTIMER4_t_vref_END (22)
#define SOC_DDR_PACK_DRAMTIMER4_t_odton_START (24)
#define SOC_DDR_PACK_DRAMTIMER4_t_odton_END (27)
#define SOC_DDR_PACK_DRAMTIMER4_t_ccd_ddr4_START (28)
#define SOC_DDR_PACK_DRAMTIMER4_t_ccd_ddr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wodt_rank0 : 4;
        unsigned int wodt_rank1 : 4;
        unsigned int wodt_rank2 : 4;
        unsigned int wodt_rank3 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PACK_ODTCR_UNION;
#endif
#define SOC_DDR_PACK_ODTCR_wodt_rank0_START (0)
#define SOC_DDR_PACK_ODTCR_wodt_rank0_END (3)
#define SOC_DDR_PACK_ODTCR_wodt_rank1_START (4)
#define SOC_DDR_PACK_ODTCR_wodt_rank1_END (7)
#define SOC_DDR_PACK_ODTCR_wodt_rank2_START (8)
#define SOC_DDR_PACK_ODTCR_wodt_rank2_END (11)
#define SOC_DDR_PACK_ODTCR_wodt_rank3_START (12)
#define SOC_DDR_PACK_ODTCR_wodt_rank3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtr_rank : 4;
        unsigned int dqsgsl_mrgn : 8;
        unsigned int busy_en_cnt : 4;
        unsigned int wl_ph_delta : 6;
        unsigned int gtfback_en : 1;
        unsigned int gdsrten : 1;
        unsigned int gtdsdly : 6;
        unsigned int dtrerrstop : 1;
        unsigned int detskipeyop : 1;
    } reg;
} SOC_DDR_PACK_TRAINCTRL0_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL0_dtr_rank_START (0)
#define SOC_DDR_PACK_TRAINCTRL0_dtr_rank_END (3)
#define SOC_DDR_PACK_TRAINCTRL0_dqsgsl_mrgn_START (4)
#define SOC_DDR_PACK_TRAINCTRL0_dqsgsl_mrgn_END (11)
#define SOC_DDR_PACK_TRAINCTRL0_busy_en_cnt_START (12)
#define SOC_DDR_PACK_TRAINCTRL0_busy_en_cnt_END (15)
#define SOC_DDR_PACK_TRAINCTRL0_wl_ph_delta_START (16)
#define SOC_DDR_PACK_TRAINCTRL0_wl_ph_delta_END (21)
#define SOC_DDR_PACK_TRAINCTRL0_gtfback_en_START (22)
#define SOC_DDR_PACK_TRAINCTRL0_gtfback_en_END (22)
#define SOC_DDR_PACK_TRAINCTRL0_gdsrten_START (23)
#define SOC_DDR_PACK_TRAINCTRL0_gdsrten_END (23)
#define SOC_DDR_PACK_TRAINCTRL0_gtdsdly_START (24)
#define SOC_DDR_PACK_TRAINCTRL0_gtdsdly_END (29)
#define SOC_DDR_PACK_TRAINCTRL0_dtrerrstop_START (30)
#define SOC_DDR_PACK_TRAINCTRL0_dtrerrstop_END (30)
#define SOC_DDR_PACK_TRAINCTRL0_detskipeyop_START (31)
#define SOC_DDR_PACK_TRAINCTRL0_detskipeyop_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rank_en : 16;
        unsigned int dtbank : 3;
        unsigned int reserved_0 : 1;
        unsigned int dtbankgrp : 3;
        unsigned int reserved_1 : 1;
        unsigned int dtbank_tg1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int dtbankgrp_tg1 : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_DDR_PACK_RANKEN_UNION;
#endif
#define SOC_DDR_PACK_RANKEN_rank_en_START (0)
#define SOC_DDR_PACK_RANKEN_rank_en_END (15)
#define SOC_DDR_PACK_RANKEN_dtbank_START (16)
#define SOC_DDR_PACK_RANKEN_dtbank_END (18)
#define SOC_DDR_PACK_RANKEN_dtbankgrp_START (20)
#define SOC_DDR_PACK_RANKEN_dtbankgrp_END (22)
#define SOC_DDR_PACK_RANKEN_dtbank_tg1_START (24)
#define SOC_DDR_PACK_RANKEN_dtbank_tg1_END (26)
#define SOC_DDR_PACK_RANKEN_dtbankgrp_tg1_START (28)
#define SOC_DDR_PACK_RANKEN_dtbankgrp_tg1_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtcol : 12;
        unsigned int dtrow : 20;
    } reg;
} SOC_DDR_PACK_TRAINMADDR_UNION;
#endif
#define SOC_DDR_PACK_TRAINMADDR_dtcol_START (0)
#define SOC_DDR_PACK_TRAINMADDR_dtcol_END (11)
#define SOC_DDR_PACK_TRAINMADDR_dtrow_START (12)
#define SOC_DDR_PACK_TRAINMADDR_dtrow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bist_op : 2;
        unsigned int reserved_0 : 1;
        unsigned int dxlpbk_wlmode : 1;
        unsigned int bist_mode : 3;
        unsigned int reserved_1 : 1;
        unsigned int bist_pat : 3;
        unsigned int sso_bist_cnt : 3;
        unsigned int rnk_sw_op : 1;
        unsigned int dfi_phyupd_disable : 1;
        unsigned int bist_fail_stop : 8;
        unsigned int rnk_sw_mode : 1;
        unsigned int brst_cnt : 7;
    } reg;
} SOC_DDR_PACK_BISTCTRL_UNION;
#endif
#define SOC_DDR_PACK_BISTCTRL_bist_op_START (0)
#define SOC_DDR_PACK_BISTCTRL_bist_op_END (1)
#define SOC_DDR_PACK_BISTCTRL_dxlpbk_wlmode_START (3)
#define SOC_DDR_PACK_BISTCTRL_dxlpbk_wlmode_END (3)
#define SOC_DDR_PACK_BISTCTRL_bist_mode_START (4)
#define SOC_DDR_PACK_BISTCTRL_bist_mode_END (6)
#define SOC_DDR_PACK_BISTCTRL_bist_pat_START (8)
#define SOC_DDR_PACK_BISTCTRL_bist_pat_END (10)
#define SOC_DDR_PACK_BISTCTRL_sso_bist_cnt_START (11)
#define SOC_DDR_PACK_BISTCTRL_sso_bist_cnt_END (13)
#define SOC_DDR_PACK_BISTCTRL_rnk_sw_op_START (14)
#define SOC_DDR_PACK_BISTCTRL_rnk_sw_op_END (14)
#define SOC_DDR_PACK_BISTCTRL_dfi_phyupd_disable_START (15)
#define SOC_DDR_PACK_BISTCTRL_dfi_phyupd_disable_END (15)
#define SOC_DDR_PACK_BISTCTRL_bist_fail_stop_START (16)
#define SOC_DDR_PACK_BISTCTRL_bist_fail_stop_END (23)
#define SOC_DDR_PACK_BISTCTRL_rnk_sw_mode_START (24)
#define SOC_DDR_PACK_BISTCTRL_rnk_sw_mode_END (24)
#define SOC_DDR_PACK_BISTCTRL_brst_cnt_START (25)
#define SOC_DDR_PACK_BISTCTRL_brst_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bist_data_b0 : 8;
        unsigned int bist_data_b1 : 8;
        unsigned int bist_data_b2 : 8;
        unsigned int bist_data_b3 : 8;
    } reg;
} SOC_DDR_PACK_BISTDATA0_UNION;
#endif
#define SOC_DDR_PACK_BISTDATA0_bist_data_b0_START (0)
#define SOC_DDR_PACK_BISTDATA0_bist_data_b0_END (7)
#define SOC_DDR_PACK_BISTDATA0_bist_data_b1_START (8)
#define SOC_DDR_PACK_BISTDATA0_bist_data_b1_END (15)
#define SOC_DDR_PACK_BISTDATA0_bist_data_b2_START (16)
#define SOC_DDR_PACK_BISTDATA0_bist_data_b2_END (23)
#define SOC_DDR_PACK_BISTDATA0_bist_data_b3_START (24)
#define SOC_DDR_PACK_BISTDATA0_bist_data_b3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bist_data_b4 : 8;
        unsigned int bist_data_b5 : 8;
        unsigned int bist_data_b6 : 8;
        unsigned int bist_data_b7 : 8;
    } reg;
} SOC_DDR_PACK_BISTDATA1_UNION;
#endif
#define SOC_DDR_PACK_BISTDATA1_bist_data_b4_START (0)
#define SOC_DDR_PACK_BISTDATA1_bist_data_b4_END (7)
#define SOC_DDR_PACK_BISTDATA1_bist_data_b5_START (8)
#define SOC_DDR_PACK_BISTDATA1_bist_data_b5_END (15)
#define SOC_DDR_PACK_BISTDATA1_bist_data_b6_START (16)
#define SOC_DDR_PACK_BISTDATA1_bist_data_b6_END (23)
#define SOC_DDR_PACK_BISTDATA1_bist_data_b7_START (24)
#define SOC_DDR_PACK_BISTDATA1_bist_data_b7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bist_done : 1;
        unsigned int bist_acerr : 1;
        unsigned int bist_dxerr : 1;
        unsigned int ac_lpbk_dvalid_no_come : 1;
        unsigned int dx_lpbk_dvalid_no_come : 1;
        unsigned int reserved_0 : 3;
        unsigned int bstpatext_f : 3;
        unsigned int reserved_1 : 1;
        unsigned int bstpatext_e : 3;
        unsigned int reserved_2 : 1;
        unsigned int bstpatext_d : 3;
        unsigned int reserved_3 : 1;
        unsigned int bstpatext_c : 3;
        unsigned int reserved_4 : 1;
        unsigned int bstpatext_b : 3;
        unsigned int reserved_5 : 1;
        unsigned int bstpatext_a : 3;
        unsigned int reserved_6 : 1;
    } reg;
} SOC_DDR_PACK_BISTSTATUS_UNION;
#endif
#define SOC_DDR_PACK_BISTSTATUS_bist_done_START (0)
#define SOC_DDR_PACK_BISTSTATUS_bist_done_END (0)
#define SOC_DDR_PACK_BISTSTATUS_bist_acerr_START (1)
#define SOC_DDR_PACK_BISTSTATUS_bist_acerr_END (1)
#define SOC_DDR_PACK_BISTSTATUS_bist_dxerr_START (2)
#define SOC_DDR_PACK_BISTSTATUS_bist_dxerr_END (2)
#define SOC_DDR_PACK_BISTSTATUS_ac_lpbk_dvalid_no_come_START (3)
#define SOC_DDR_PACK_BISTSTATUS_ac_lpbk_dvalid_no_come_END (3)
#define SOC_DDR_PACK_BISTSTATUS_dx_lpbk_dvalid_no_come_START (4)
#define SOC_DDR_PACK_BISTSTATUS_dx_lpbk_dvalid_no_come_END (4)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_f_START (8)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_f_END (10)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_e_START (12)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_e_END (14)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_d_START (16)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_d_END (18)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_c_START (20)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_c_END (22)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_b_START (24)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_b_END (26)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_a_START (28)
#define SOC_DDR_PACK_BISTSTATUS_bstpatext_a_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mr0 : 16;
        unsigned int mr1 : 16;
    } reg;
} SOC_DDR_PACK_MODEREG01_UNION;
#endif
#define SOC_DDR_PACK_MODEREG01_mr0_START (0)
#define SOC_DDR_PACK_MODEREG01_mr0_END (15)
#define SOC_DDR_PACK_MODEREG01_mr1_START (16)
#define SOC_DDR_PACK_MODEREG01_mr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mr2 : 16;
        unsigned int mr3 : 16;
    } reg;
} SOC_DDR_PACK_MODEREG23_UNION;
#endif
#define SOC_DDR_PACK_MODEREG23_mr2_START (0)
#define SOC_DDR_PACK_MODEREG23_mr2_END (15)
#define SOC_DDR_PACK_MODEREG23_mr3_START (16)
#define SOC_DDR_PACK_MODEREG23_mr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int det_pat_pat : 32;
    } reg;
} SOC_DDR_PACK_DETPATTERN_UNION;
#endif
#define SOC_DDR_PACK_DETPATTERN_det_pat_pat_START (0)
#define SOC_DDR_PACK_DETPATTERN_det_pat_pat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_wl : 8;
        unsigned int cfg_rl : 8;
        unsigned int scramb_en : 1;
        unsigned int addr_toggle : 1;
        unsigned int addr_delay : 1;
        unsigned int cfg_dlyupd : 1;
        unsigned int swap_en : 3;
        unsigned int ba_addr_scramb_en_lp4_r : 1;
        unsigned int cfg_dev_mode : 1;
        unsigned int swapdm_en : 2;
        unsigned int swapwl_en : 3;
        unsigned int cfg_cov_ac : 1;
        unsigned int cfg_serdes_rx_en : 1;
    } reg;
} SOC_DDR_PACK_MISC_UNION;
#endif
#define SOC_DDR_PACK_MISC_cfg_wl_START (0)
#define SOC_DDR_PACK_MISC_cfg_wl_END (7)
#define SOC_DDR_PACK_MISC_cfg_rl_START (8)
#define SOC_DDR_PACK_MISC_cfg_rl_END (15)
#define SOC_DDR_PACK_MISC_scramb_en_START (16)
#define SOC_DDR_PACK_MISC_scramb_en_END (16)
#define SOC_DDR_PACK_MISC_addr_toggle_START (17)
#define SOC_DDR_PACK_MISC_addr_toggle_END (17)
#define SOC_DDR_PACK_MISC_addr_delay_START (18)
#define SOC_DDR_PACK_MISC_addr_delay_END (18)
#define SOC_DDR_PACK_MISC_cfg_dlyupd_START (19)
#define SOC_DDR_PACK_MISC_cfg_dlyupd_END (19)
#define SOC_DDR_PACK_MISC_swap_en_START (20)
#define SOC_DDR_PACK_MISC_swap_en_END (22)
#define SOC_DDR_PACK_MISC_ba_addr_scramb_en_lp4_r_START (23)
#define SOC_DDR_PACK_MISC_ba_addr_scramb_en_lp4_r_END (23)
#define SOC_DDR_PACK_MISC_cfg_dev_mode_START (24)
#define SOC_DDR_PACK_MISC_cfg_dev_mode_END (24)
#define SOC_DDR_PACK_MISC_swapdm_en_START (25)
#define SOC_DDR_PACK_MISC_swapdm_en_END (26)
#define SOC_DDR_PACK_MISC_swapwl_en_START (27)
#define SOC_DDR_PACK_MISC_swapwl_en_END (29)
#define SOC_DDR_PACK_MISC_cfg_cov_ac_START (30)
#define SOC_DDR_PACK_MISC_cfg_cov_ac_END (30)
#define SOC_DDR_PACK_MISC_cfg_serdes_rx_en_START (31)
#define SOC_DDR_PACK_MISC_cfg_serdes_rx_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trnkwtw : 5;
        unsigned int trnkrtr : 5;
        unsigned int trnkrtw : 5;
        unsigned int trnkwtr : 5;
        unsigned int reserved_0: 7;
        unsigned int trnkx2 : 1;
        unsigned int reserved_1: 1;
        unsigned int dfi2iomap : 3;
    } reg;
} SOC_DDR_PACK_RNK2RNK_UNION;
#endif
#define SOC_DDR_PACK_RNK2RNK_trnkwtw_START (0)
#define SOC_DDR_PACK_RNK2RNK_trnkwtw_END (4)
#define SOC_DDR_PACK_RNK2RNK_trnkrtr_START (5)
#define SOC_DDR_PACK_RNK2RNK_trnkrtr_END (9)
#define SOC_DDR_PACK_RNK2RNK_trnkrtw_START (10)
#define SOC_DDR_PACK_RNK2RNK_trnkrtw_END (14)
#define SOC_DDR_PACK_RNK2RNK_trnkwtr_START (15)
#define SOC_DDR_PACK_RNK2RNK_trnkwtr_END (19)
#define SOC_DDR_PACK_RNK2RNK_trnkx2_START (27)
#define SOC_DDR_PACK_RNK2RNK_trnkx2_END (27)
#define SOC_DDR_PACK_RNK2RNK_dfi2iomap_START (29)
#define SOC_DDR_PACK_RNK2RNK_dfi2iomap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb2apb_en : 1;
        unsigned int reg_sel_dficlk_rx : 1;
        unsigned int sel_pos_rx : 1;
        unsigned int lp_ck_sel : 2;
        unsigned int reserved_0 : 2;
        unsigned int cmdoen : 1;
        unsigned int ckoen : 3;
        unsigned int ckeoen : 1;
        unsigned int csoen : 1;
        unsigned int resetoen : 1;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_DDR_PACK_PHYCTRL0_UNION;
#endif
#define SOC_DDR_PACK_PHYCTRL0_apb2apb_en_START (0)
#define SOC_DDR_PACK_PHYCTRL0_apb2apb_en_END (0)
#define SOC_DDR_PACK_PHYCTRL0_reg_sel_dficlk_rx_START (1)
#define SOC_DDR_PACK_PHYCTRL0_reg_sel_dficlk_rx_END (1)
#define SOC_DDR_PACK_PHYCTRL0_sel_pos_rx_START (2)
#define SOC_DDR_PACK_PHYCTRL0_sel_pos_rx_END (2)
#define SOC_DDR_PACK_PHYCTRL0_lp_ck_sel_START (3)
#define SOC_DDR_PACK_PHYCTRL0_lp_ck_sel_END (4)
#define SOC_DDR_PACK_PHYCTRL0_cmdoen_START (7)
#define SOC_DDR_PACK_PHYCTRL0_cmdoen_END (7)
#define SOC_DDR_PACK_PHYCTRL0_ckoen_START (8)
#define SOC_DDR_PACK_PHYCTRL0_ckoen_END (10)
#define SOC_DDR_PACK_PHYCTRL0_ckeoen_START (11)
#define SOC_DDR_PACK_PHYCTRL0_ckeoen_END (11)
#define SOC_DDR_PACK_PHYCTRL0_csoen_START (12)
#define SOC_DDR_PACK_PHYCTRL0_csoen_END (12)
#define SOC_DDR_PACK_PHYCTRL0_resetoen_START (13)
#define SOC_DDR_PACK_PHYCTRL0_resetoen_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dqs_gated_error_r : 8;
        unsigned int dqs_gated_error : 8;
        unsigned int dqsb_gated_error_r : 8;
        unsigned int dqsb_gated_error : 8;
    } reg;
} SOC_DDR_PACK_PHYDBG_UNION;
#endif
#define SOC_DDR_PACK_PHYDBG_dqs_gated_error_r_START (0)
#define SOC_DDR_PACK_PHYDBG_dqs_gated_error_r_END (7)
#define SOC_DDR_PACK_PHYDBG_dqs_gated_error_START (8)
#define SOC_DDR_PACK_PHYDBG_dqs_gated_error_END (15)
#define SOC_DDR_PACK_PHYDBG_dqsb_gated_error_r_START (16)
#define SOC_DDR_PACK_PHYDBG_dqsb_gated_error_r_END (23)
#define SOC_DDR_PACK_PHYDBG_dqsb_gated_error_START (24)
#define SOC_DDR_PACK_PHYDBG_dqsb_gated_error_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyupd_resp : 13;
        unsigned int retrain_en : 1;
        unsigned int gtrten : 1;
        unsigned int rderten : 1;
        unsigned int retrain_thrd : 16;
    } reg;
} SOC_DDR_PACK_RETCTRL0_UNION;
#endif
#define SOC_DDR_PACK_RETCTRL0_phyupd_resp_START (0)
#define SOC_DDR_PACK_RETCTRL0_phyupd_resp_END (12)
#define SOC_DDR_PACK_RETCTRL0_retrain_en_START (13)
#define SOC_DDR_PACK_RETCTRL0_retrain_en_END (13)
#define SOC_DDR_PACK_RETCTRL0_gtrten_START (14)
#define SOC_DDR_PACK_RETCTRL0_gtrten_END (14)
#define SOC_DDR_PACK_RETCTRL0_rderten_START (15)
#define SOC_DDR_PACK_RETCTRL0_rderten_END (15)
#define SOC_DDR_PACK_RETCTRL0_retrain_thrd_START (16)
#define SOC_DDR_PACK_RETCTRL0_retrain_thrd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dxctl_dmswap_sel : 4;
        unsigned int rt_onebyone : 1;
        unsigned int fast_wl2_en : 1;
        unsigned int wlpulsecnt : 2;
        unsigned int tphy_wrdata : 1;
        unsigned int ddr4_dm_inv_en : 1;
        unsigned int wlpulsecnt_exd : 3;
        unsigned int phystop_en : 1;
        unsigned int phyupd_type_nopre : 2;
        unsigned int phyupd_type_pre : 2;
        unsigned int packdbgout : 1;
        unsigned int pllphhalfbdlen : 1;
        unsigned int pllphsel : 2;
        unsigned int wlexitmode : 1;
        unsigned int bl32atonthefly : 1;
        unsigned int swapdfibyte_en : 3;
        unsigned int swapaddr_en : 3;
        unsigned int tphy_wrdata_ext : 2;
    } reg;
} SOC_DDR_PACK_DMSEL_UNION;
#endif
#define SOC_DDR_PACK_DMSEL_dxctl_dmswap_sel_START (0)
#define SOC_DDR_PACK_DMSEL_dxctl_dmswap_sel_END (3)
#define SOC_DDR_PACK_DMSEL_rt_onebyone_START (4)
#define SOC_DDR_PACK_DMSEL_rt_onebyone_END (4)
#define SOC_DDR_PACK_DMSEL_fast_wl2_en_START (5)
#define SOC_DDR_PACK_DMSEL_fast_wl2_en_END (5)
#define SOC_DDR_PACK_DMSEL_wlpulsecnt_START (6)
#define SOC_DDR_PACK_DMSEL_wlpulsecnt_END (7)
#define SOC_DDR_PACK_DMSEL_tphy_wrdata_START (8)
#define SOC_DDR_PACK_DMSEL_tphy_wrdata_END (8)
#define SOC_DDR_PACK_DMSEL_ddr4_dm_inv_en_START (9)
#define SOC_DDR_PACK_DMSEL_ddr4_dm_inv_en_END (9)
#define SOC_DDR_PACK_DMSEL_wlpulsecnt_exd_START (10)
#define SOC_DDR_PACK_DMSEL_wlpulsecnt_exd_END (12)
#define SOC_DDR_PACK_DMSEL_phystop_en_START (13)
#define SOC_DDR_PACK_DMSEL_phystop_en_END (13)
#define SOC_DDR_PACK_DMSEL_phyupd_type_nopre_START (14)
#define SOC_DDR_PACK_DMSEL_phyupd_type_nopre_END (15)
#define SOC_DDR_PACK_DMSEL_phyupd_type_pre_START (16)
#define SOC_DDR_PACK_DMSEL_phyupd_type_pre_END (17)
#define SOC_DDR_PACK_DMSEL_packdbgout_START (18)
#define SOC_DDR_PACK_DMSEL_packdbgout_END (18)
#define SOC_DDR_PACK_DMSEL_pllphhalfbdlen_START (19)
#define SOC_DDR_PACK_DMSEL_pllphhalfbdlen_END (19)
#define SOC_DDR_PACK_DMSEL_pllphsel_START (20)
#define SOC_DDR_PACK_DMSEL_pllphsel_END (21)
#define SOC_DDR_PACK_DMSEL_wlexitmode_START (22)
#define SOC_DDR_PACK_DMSEL_wlexitmode_END (22)
#define SOC_DDR_PACK_DMSEL_bl32atonthefly_START (23)
#define SOC_DDR_PACK_DMSEL_bl32atonthefly_END (23)
#define SOC_DDR_PACK_DMSEL_swapdfibyte_en_START (24)
#define SOC_DDR_PACK_DMSEL_swapdfibyte_en_END (26)
#define SOC_DDR_PACK_DMSEL_swapaddr_en_START (27)
#define SOC_DDR_PACK_DMSEL_swapaddr_en_END (29)
#define SOC_DDR_PACK_DMSEL_tphy_wrdata_ext_START (30)
#define SOC_DDR_PACK_DMSEL_tphy_wrdata_ext_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trainctl_donewait : 3;
        unsigned int nomrs4rdet : 1;
        unsigned int nopre4wl : 1;
        unsigned int radix3sel : 2;
        unsigned int reserved : 1;
        unsigned int wdert_shift_step : 6;
        unsigned int lpbk_gt_rden_type : 1;
        unsigned int gtrt_ph_reload_type : 1;
        unsigned int empty_time : 4;
        unsigned int cdgc_done_cnt : 4;
        unsigned int det_rstpost_time : 4;
        unsigned int det_sstrstphy_time : 4;
    } reg;
} SOC_DDR_PACK_TRAINCTRL8_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL8_trainctl_donewait_START (0)
#define SOC_DDR_PACK_TRAINCTRL8_trainctl_donewait_END (2)
#define SOC_DDR_PACK_TRAINCTRL8_nomrs4rdet_START (3)
#define SOC_DDR_PACK_TRAINCTRL8_nomrs4rdet_END (3)
#define SOC_DDR_PACK_TRAINCTRL8_nopre4wl_START (4)
#define SOC_DDR_PACK_TRAINCTRL8_nopre4wl_END (4)
#define SOC_DDR_PACK_TRAINCTRL8_radix3sel_START (5)
#define SOC_DDR_PACK_TRAINCTRL8_radix3sel_END (6)
#define SOC_DDR_PACK_TRAINCTRL8_wdert_shift_step_START (8)
#define SOC_DDR_PACK_TRAINCTRL8_wdert_shift_step_END (13)
#define SOC_DDR_PACK_TRAINCTRL8_lpbk_gt_rden_type_START (14)
#define SOC_DDR_PACK_TRAINCTRL8_lpbk_gt_rden_type_END (14)
#define SOC_DDR_PACK_TRAINCTRL8_gtrt_ph_reload_type_START (15)
#define SOC_DDR_PACK_TRAINCTRL8_gtrt_ph_reload_type_END (15)
#define SOC_DDR_PACK_TRAINCTRL8_empty_time_START (16)
#define SOC_DDR_PACK_TRAINCTRL8_empty_time_END (19)
#define SOC_DDR_PACK_TRAINCTRL8_cdgc_done_cnt_START (20)
#define SOC_DDR_PACK_TRAINCTRL8_cdgc_done_cnt_END (23)
#define SOC_DDR_PACK_TRAINCTRL8_det_rstpost_time_START (24)
#define SOC_DDR_PACK_TRAINCTRL8_det_rstpost_time_END (27)
#define SOC_DDR_PACK_TRAINCTRL8_det_sstrstphy_time_START (28)
#define SOC_DDR_PACK_TRAINCTRL8_det_sstrstphy_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mc_wrcmd_xgated_en : 1;
        unsigned int WCKgated_phy_hw_en : 1;
        unsigned int RXgated_phy_hw_en : 1;
        unsigned int TXgated_phy_hw_en : 1;
        unsigned int Xgated_dig_pstmrg : 4;
        unsigned int Xgated_dig_premrg : 4;
        unsigned int RXgated_phy_pstmrg : 4;
        unsigned int RXgated_phy_premrg : 4;
        unsigned int TXgated_phy_pstmrg : 4;
        unsigned int TXgated_phy_premrg : 5;
        unsigned int Xgated_dig_hw_en : 1;
        unsigned int Xgated_dig_legacy : 1;
        unsigned int Xgated_phy_legacy : 1;
    } reg;
} SOC_DDR_PACK_LPCTRL2_UNION;
#endif
#define SOC_DDR_PACK_LPCTRL2_mc_wrcmd_xgated_en_START (0)
#define SOC_DDR_PACK_LPCTRL2_mc_wrcmd_xgated_en_END (0)
#define SOC_DDR_PACK_LPCTRL2_WCKgated_phy_hw_en_START (1)
#define SOC_DDR_PACK_LPCTRL2_WCKgated_phy_hw_en_END (1)
#define SOC_DDR_PACK_LPCTRL2_RXgated_phy_hw_en_START (2)
#define SOC_DDR_PACK_LPCTRL2_RXgated_phy_hw_en_END (2)
#define SOC_DDR_PACK_LPCTRL2_TXgated_phy_hw_en_START (3)
#define SOC_DDR_PACK_LPCTRL2_TXgated_phy_hw_en_END (3)
#define SOC_DDR_PACK_LPCTRL2_Xgated_dig_pstmrg_START (4)
#define SOC_DDR_PACK_LPCTRL2_Xgated_dig_pstmrg_END (7)
#define SOC_DDR_PACK_LPCTRL2_Xgated_dig_premrg_START (8)
#define SOC_DDR_PACK_LPCTRL2_Xgated_dig_premrg_END (11)
#define SOC_DDR_PACK_LPCTRL2_RXgated_phy_pstmrg_START (12)
#define SOC_DDR_PACK_LPCTRL2_RXgated_phy_pstmrg_END (15)
#define SOC_DDR_PACK_LPCTRL2_RXgated_phy_premrg_START (16)
#define SOC_DDR_PACK_LPCTRL2_RXgated_phy_premrg_END (19)
#define SOC_DDR_PACK_LPCTRL2_TXgated_phy_pstmrg_START (20)
#define SOC_DDR_PACK_LPCTRL2_TXgated_phy_pstmrg_END (23)
#define SOC_DDR_PACK_LPCTRL2_TXgated_phy_premrg_START (24)
#define SOC_DDR_PACK_LPCTRL2_TXgated_phy_premrg_END (28)
#define SOC_DDR_PACK_LPCTRL2_Xgated_dig_hw_en_START (29)
#define SOC_DDR_PACK_LPCTRL2_Xgated_dig_hw_en_END (29)
#define SOC_DDR_PACK_LPCTRL2_Xgated_dig_legacy_START (30)
#define SOC_DDR_PACK_LPCTRL2_Xgated_dig_legacy_END (30)
#define SOC_DDR_PACK_LPCTRL2_Xgated_phy_legacy_START (31)
#define SOC_DDR_PACK_LPCTRL2_Xgated_phy_legacy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gds_margin_sel : 3;
        unsigned int byp_gate : 1;
        unsigned int dbi_in_pipe_en : 1;
        unsigned int cfg_gds_max_7 : 1;
        unsigned int alu_done_cyc : 1;
        unsigned int reserved_0 : 1;
        unsigned int one_phase_code : 6;
        unsigned int reserved_1 : 1;
        unsigned int rt_ehandle_en : 1;
        unsigned int wdert_check_step : 6;
        unsigned int wdert_bdl_shift_step : 2;
        unsigned int row_react_period_offset : 2;
        unsigned int wdert_bdl_check_step : 2;
        unsigned int train_reset_time : 4;
    } reg;
} SOC_DDR_PACK_TRAINCTRL9_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL9_gds_margin_sel_START (0)
#define SOC_DDR_PACK_TRAINCTRL9_gds_margin_sel_END (2)
#define SOC_DDR_PACK_TRAINCTRL9_byp_gate_START (3)
#define SOC_DDR_PACK_TRAINCTRL9_byp_gate_END (3)
#define SOC_DDR_PACK_TRAINCTRL9_dbi_in_pipe_en_START (4)
#define SOC_DDR_PACK_TRAINCTRL9_dbi_in_pipe_en_END (4)
#define SOC_DDR_PACK_TRAINCTRL9_cfg_gds_max_7_START (5)
#define SOC_DDR_PACK_TRAINCTRL9_cfg_gds_max_7_END (5)
#define SOC_DDR_PACK_TRAINCTRL9_alu_done_cyc_START (6)
#define SOC_DDR_PACK_TRAINCTRL9_alu_done_cyc_END (6)
#define SOC_DDR_PACK_TRAINCTRL9_one_phase_code_START (8)
#define SOC_DDR_PACK_TRAINCTRL9_one_phase_code_END (13)
#define SOC_DDR_PACK_TRAINCTRL9_rt_ehandle_en_START (15)
#define SOC_DDR_PACK_TRAINCTRL9_rt_ehandle_en_END (15)
#define SOC_DDR_PACK_TRAINCTRL9_wdert_check_step_START (16)
#define SOC_DDR_PACK_TRAINCTRL9_wdert_check_step_END (21)
#define SOC_DDR_PACK_TRAINCTRL9_wdert_bdl_shift_step_START (22)
#define SOC_DDR_PACK_TRAINCTRL9_wdert_bdl_shift_step_END (23)
#define SOC_DDR_PACK_TRAINCTRL9_row_react_period_offset_START (24)
#define SOC_DDR_PACK_TRAINCTRL9_row_react_period_offset_END (25)
#define SOC_DDR_PACK_TRAINCTRL9_wdert_bdl_check_step_START (26)
#define SOC_DDR_PACK_TRAINCTRL9_wdert_bdl_check_step_END (27)
#define SOC_DDR_PACK_TRAINCTRL9_train_reset_time_START (28)
#define SOC_DDR_PACK_TRAINCTRL9_train_reset_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dqsgrt_shft : 6;
        unsigned int reserved_0 : 2;
        unsigned int dqsgrt_chk : 6;
        unsigned int reserved_1 : 2;
        unsigned int dyn_dqsgbdl_trans : 8;
        unsigned int wdet_trysamp_num : 3;
        unsigned int reserved_2 : 1;
        unsigned int rdet_trysamp_num : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_DDR_PACK_TRAINCTRL10_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL10_dqsgrt_shft_START (0)
#define SOC_DDR_PACK_TRAINCTRL10_dqsgrt_shft_END (5)
#define SOC_DDR_PACK_TRAINCTRL10_dqsgrt_chk_START (8)
#define SOC_DDR_PACK_TRAINCTRL10_dqsgrt_chk_END (13)
#define SOC_DDR_PACK_TRAINCTRL10_dyn_dqsgbdl_trans_START (16)
#define SOC_DDR_PACK_TRAINCTRL10_dyn_dqsgbdl_trans_END (23)
#define SOC_DDR_PACK_TRAINCTRL10_wdet_trysamp_num_START (24)
#define SOC_DDR_PACK_TRAINCTRL10_wdet_trysamp_num_END (26)
#define SOC_DDR_PACK_TRAINCTRL10_rdet_trysamp_num_START (28)
#define SOC_DDR_PACK_TRAINCTRL10_rdet_trysamp_num_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lock_timer_latch : 24;
        unsigned int reserved_0 : 4;
        unsigned int pll_init_ac_dis : 1;
        unsigned int pll_init_dx_dis : 1;
        unsigned int reserved_1 : 1;
        unsigned int ac_pll_lock : 1;
    } reg;
} SOC_DDR_PACK_PHYPLLCTRL_AC_UNION;
#endif
#define SOC_DDR_PACK_PHYPLLCTRL_AC_lock_timer_latch_START (0)
#define SOC_DDR_PACK_PHYPLLCTRL_AC_lock_timer_latch_END (23)
#define SOC_DDR_PACK_PHYPLLCTRL_AC_pll_init_ac_dis_START (28)
#define SOC_DDR_PACK_PHYPLLCTRL_AC_pll_init_ac_dis_END (28)
#define SOC_DDR_PACK_PHYPLLCTRL_AC_pll_init_dx_dis_START (29)
#define SOC_DDR_PACK_PHYPLLCTRL_AC_pll_init_dx_dis_END (29)
#define SOC_DDR_PACK_PHYPLLCTRL_AC_ac_pll_lock_START (31)
#define SOC_DDR_PACK_PHYPLLCTRL_AC_ac_pll_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dx_pll_test : 16;
        unsigned int reserved : 14;
        unsigned int dx_pll_lock : 2;
    } reg;
} SOC_DDR_PACK_PHYPLLCTRL_DX_UNION;
#endif
#define SOC_DDR_PACK_PHYPLLCTRL_DX_dx_pll_test_START (0)
#define SOC_DDR_PACK_PHYPLLCTRL_DX_dx_pll_test_END (15)
#define SOC_DDR_PACK_PHYPLLCTRL_DX_dx_pll_lock_START (30)
#define SOC_DDR_PACK_PHYPLLCTRL_DX_dx_pll_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_wlmode : 1;
        unsigned int sw_gtmode : 1;
        unsigned int reserved_0 : 2;
        unsigned int sw_wlmodeb : 8;
        unsigned int reserved_1 : 4;
        unsigned int sw_dxctl_ie_dq : 8;
        unsigned int sw_dxctl_ie_dq_mode : 1;
        unsigned int reserved_2 : 1;
        unsigned int swop_prewrite : 1;
        unsigned int swop_rdtest : 1;
        unsigned int sw_rdfifo_push_block : 1;
        unsigned int sw_dvalid_block : 1;
        unsigned int sw_csgated : 1;
        unsigned int wl_wdqs_gated : 1;
    } reg;
} SOC_DDR_PACK_SWTMODE_UNION;
#endif
#define SOC_DDR_PACK_SWTMODE_sw_wlmode_START (0)
#define SOC_DDR_PACK_SWTMODE_sw_wlmode_END (0)
#define SOC_DDR_PACK_SWTMODE_sw_gtmode_START (1)
#define SOC_DDR_PACK_SWTMODE_sw_gtmode_END (1)
#define SOC_DDR_PACK_SWTMODE_sw_wlmodeb_START (4)
#define SOC_DDR_PACK_SWTMODE_sw_wlmodeb_END (11)
#define SOC_DDR_PACK_SWTMODE_sw_dxctl_ie_dq_START (16)
#define SOC_DDR_PACK_SWTMODE_sw_dxctl_ie_dq_END (23)
#define SOC_DDR_PACK_SWTMODE_sw_dxctl_ie_dq_mode_START (24)
#define SOC_DDR_PACK_SWTMODE_sw_dxctl_ie_dq_mode_END (24)
#define SOC_DDR_PACK_SWTMODE_swop_prewrite_START (26)
#define SOC_DDR_PACK_SWTMODE_swop_prewrite_END (26)
#define SOC_DDR_PACK_SWTMODE_swop_rdtest_START (27)
#define SOC_DDR_PACK_SWTMODE_swop_rdtest_END (27)
#define SOC_DDR_PACK_SWTMODE_sw_rdfifo_push_block_START (28)
#define SOC_DDR_PACK_SWTMODE_sw_rdfifo_push_block_END (28)
#define SOC_DDR_PACK_SWTMODE_sw_dvalid_block_START (29)
#define SOC_DDR_PACK_SWTMODE_sw_dvalid_block_END (29)
#define SOC_DDR_PACK_SWTMODE_sw_csgated_START (30)
#define SOC_DDR_PACK_SWTMODE_sw_csgated_END (30)
#define SOC_DDR_PACK_SWTMODE_wl_wdqs_gated_START (31)
#define SOC_DDR_PACK_SWTMODE_wl_wdqs_gated_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_wl_dqs : 1;
        unsigned int reserved : 2;
        unsigned int sw_mrw_format : 1;
        unsigned int sw_mrw_cs : 2;
        unsigned int sw_mrw_rw : 1;
        unsigned int sw_mrw_req : 1;
        unsigned int sw_mrw_ma : 8;
        unsigned int sw_mrw_op : 16;
    } reg;
} SOC_DDR_PACK_SWTWLDQS_UNION;
#endif
#define SOC_DDR_PACK_SWTWLDQS_sw_wl_dqs_START (0)
#define SOC_DDR_PACK_SWTWLDQS_sw_wl_dqs_END (0)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_format_START (3)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_format_END (3)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_cs_START (4)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_cs_END (5)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_rw_START (6)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_rw_END (6)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_req_START (7)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_req_END (7)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_ma_START (8)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_ma_END (15)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_op_START (16)
#define SOC_DDR_PACK_SWTWLDQS_sw_mrw_op_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wl_dq_result : 8;
        unsigned int gt_result : 8;
        unsigned int gds_result : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_PACK_SWTRLT_UNION;
#endif
#define SOC_DDR_PACK_SWTRLT_wl_dq_result_START (0)
#define SOC_DDR_PACK_SWTRLT_wl_dq_result_END (7)
#define SOC_DDR_PACK_SWTRLT_gt_result_START (8)
#define SOC_DDR_PACK_SWTRLT_gt_result_END (15)
#define SOC_DDR_PACK_SWTRLT_gds_result_START (16)
#define SOC_DDR_PACK_SWTRLT_gds_result_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rs_rstcont_passthrough : 4;
        unsigned int reserved_0 : 2;
        unsigned int rs_rst_passthrough : 4;
        unsigned int reserved_1 : 2;
        unsigned int rs_passthrough : 4;
        unsigned int reserved_2 : 2;
        unsigned int rs_rs_passthrough : 4;
        unsigned int reserved_3 : 6;
        unsigned int rsneg_rstcont_passthrough : 1;
        unsigned int rsneg_rst_passthrough : 1;
        unsigned int rsneg_passthrough : 1;
        unsigned int rx_rsneg_passthrough : 1;
    } reg;
} SOC_DDR_PACK_PHYRSCTRL_UNION;
#endif
#define SOC_DDR_PACK_PHYRSCTRL_rs_rstcont_passthrough_START (0)
#define SOC_DDR_PACK_PHYRSCTRL_rs_rstcont_passthrough_END (3)
#define SOC_DDR_PACK_PHYRSCTRL_rs_rst_passthrough_START (6)
#define SOC_DDR_PACK_PHYRSCTRL_rs_rst_passthrough_END (9)
#define SOC_DDR_PACK_PHYRSCTRL_rs_passthrough_START (12)
#define SOC_DDR_PACK_PHYRSCTRL_rs_passthrough_END (15)
#define SOC_DDR_PACK_PHYRSCTRL_rs_rs_passthrough_START (18)
#define SOC_DDR_PACK_PHYRSCTRL_rs_rs_passthrough_END (21)
#define SOC_DDR_PACK_PHYRSCTRL_rsneg_rstcont_passthrough_START (28)
#define SOC_DDR_PACK_PHYRSCTRL_rsneg_rstcont_passthrough_END (28)
#define SOC_DDR_PACK_PHYRSCTRL_rsneg_rst_passthrough_START (29)
#define SOC_DDR_PACK_PHYRSCTRL_rsneg_rst_passthrough_END (29)
#define SOC_DDR_PACK_PHYRSCTRL_rsneg_passthrough_START (30)
#define SOC_DDR_PACK_PHYRSCTRL_rsneg_passthrough_END (30)
#define SOC_DDR_PACK_PHYRSCTRL_rx_rsneg_passthrough_START (31)
#define SOC_DDR_PACK_PHYRSCTRL_rx_rsneg_passthrough_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int final_scan_col_cnt_r : 12;
        unsigned int final_scan_row_cnt_r : 20;
    } reg;
} SOC_DDR_PACK_BISTCTRL2_UNION;
#endif
#define SOC_DDR_PACK_BISTCTRL2_final_scan_col_cnt_r_START (0)
#define SOC_DDR_PACK_BISTCTRL2_final_scan_col_cnt_r_END (11)
#define SOC_DDR_PACK_BISTCTRL2_final_scan_row_cnt_r_START (12)
#define SOC_DDR_PACK_BISTCTRL2_final_scan_row_cnt_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtcol_tg1 : 12;
        unsigned int dtrow_tg1 : 20;
    } reg;
} SOC_DDR_PACK_TRAINMADDRTG1_UNION;
#endif
#define SOC_DDR_PACK_TRAINMADDRTG1_dtcol_tg1_START (0)
#define SOC_DDR_PACK_TRAINMADDRTG1_dtcol_tg1_END (11)
#define SOC_DDR_PACK_TRAINMADDRTG1_dtrow_tg1_START (12)
#define SOC_DDR_PACK_TRAINMADDRTG1_dtrow_tg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_wl : 8;
        unsigned int t_odton_h : 4;
        unsigned int t_ccd_s_lp5 : 4;
        unsigned int t_rl : 8;
        unsigned int t_ccd_x_lp5 : 4;
        unsigned int tcsh : 3;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_PACK_DRAMTIMER5_UNION;
#endif
#define SOC_DDR_PACK_DRAMTIMER5_t_wl_START (0)
#define SOC_DDR_PACK_DRAMTIMER5_t_wl_END (7)
#define SOC_DDR_PACK_DRAMTIMER5_t_odton_h_START (8)
#define SOC_DDR_PACK_DRAMTIMER5_t_odton_h_END (11)
#define SOC_DDR_PACK_DRAMTIMER5_t_ccd_s_lp5_START (12)
#define SOC_DDR_PACK_DRAMTIMER5_t_ccd_s_lp5_END (15)
#define SOC_DDR_PACK_DRAMTIMER5_t_rl_START (16)
#define SOC_DDR_PACK_DRAMTIMER5_t_rl_END (23)
#define SOC_DDR_PACK_DRAMTIMER5_t_ccd_x_lp5_START (24)
#define SOC_DDR_PACK_DRAMTIMER5_t_ccd_x_lp5_END (27)
#define SOC_DDR_PACK_DRAMTIMER5_tcsh_START (28)
#define SOC_DDR_PACK_DRAMTIMER5_tcsh_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vreft_bist_runtime : 8;
        unsigned int vreft_dlyupwait : 4;
        unsigned int vreft_hor_update : 1;
        unsigned int DCC_en : 1;
        unsigned int vreft_method2 : 1;
        unsigned int vreft_dborg : 1;
        unsigned int vreft_bist_pass_cnt : 5;
        unsigned int vreft_no_dec : 1;
        unsigned int vreft_3_direction : 1;
        unsigned int vrefrt : 1;
        unsigned int vref_track_en : 1;
        unsigned int check_ok_cond : 1;
        unsigned int vref_track_method : 1;
        unsigned int vreft_dummy_reg : 2;
        unsigned int t_vref_host : 3;
    } reg;
} SOC_DDR_PACK_VREFTCTRL_UNION;
#endif
#define SOC_DDR_PACK_VREFTCTRL_vreft_bist_runtime_START (0)
#define SOC_DDR_PACK_VREFTCTRL_vreft_bist_runtime_END (7)
#define SOC_DDR_PACK_VREFTCTRL_vreft_dlyupwait_START (8)
#define SOC_DDR_PACK_VREFTCTRL_vreft_dlyupwait_END (11)
#define SOC_DDR_PACK_VREFTCTRL_vreft_hor_update_START (12)
#define SOC_DDR_PACK_VREFTCTRL_vreft_hor_update_END (12)
#define SOC_DDR_PACK_VREFTCTRL_DCC_en_START (13)
#define SOC_DDR_PACK_VREFTCTRL_DCC_en_END (13)
#define SOC_DDR_PACK_VREFTCTRL_vreft_method2_START (14)
#define SOC_DDR_PACK_VREFTCTRL_vreft_method2_END (14)
#define SOC_DDR_PACK_VREFTCTRL_vreft_dborg_START (15)
#define SOC_DDR_PACK_VREFTCTRL_vreft_dborg_END (15)
#define SOC_DDR_PACK_VREFTCTRL_vreft_bist_pass_cnt_START (16)
#define SOC_DDR_PACK_VREFTCTRL_vreft_bist_pass_cnt_END (20)
#define SOC_DDR_PACK_VREFTCTRL_vreft_no_dec_START (21)
#define SOC_DDR_PACK_VREFTCTRL_vreft_no_dec_END (21)
#define SOC_DDR_PACK_VREFTCTRL_vreft_3_direction_START (22)
#define SOC_DDR_PACK_VREFTCTRL_vreft_3_direction_END (22)
#define SOC_DDR_PACK_VREFTCTRL_vrefrt_START (23)
#define SOC_DDR_PACK_VREFTCTRL_vrefrt_END (23)
#define SOC_DDR_PACK_VREFTCTRL_vref_track_en_START (24)
#define SOC_DDR_PACK_VREFTCTRL_vref_track_en_END (24)
#define SOC_DDR_PACK_VREFTCTRL_check_ok_cond_START (25)
#define SOC_DDR_PACK_VREFTCTRL_check_ok_cond_END (25)
#define SOC_DDR_PACK_VREFTCTRL_vref_track_method_START (26)
#define SOC_DDR_PACK_VREFTCTRL_vref_track_method_END (26)
#define SOC_DDR_PACK_VREFTCTRL_vreft_dummy_reg_START (27)
#define SOC_DDR_PACK_VREFTCTRL_vreft_dummy_reg_END (28)
#define SOC_DDR_PACK_VREFTCTRL_t_vref_host_START (29)
#define SOC_DDR_PACK_VREFTCTRL_t_vref_host_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvreft_maxv : 7;
        unsigned int reserved_0 : 1;
        unsigned int dvreft_minv : 7;
        unsigned int reserved_1 : 1;
        unsigned int dvreft_step : 6;
        unsigned int reserved_2 : 2;
        unsigned int dvreft_hckpts : 6;
        unsigned int reserved_3 : 1;
        unsigned int pdaen : 1;
    } reg;
} SOC_DDR_PACK_DVRFTCTRL_UNION;
#endif
#define SOC_DDR_PACK_DVRFTCTRL_dvreft_maxv_START (0)
#define SOC_DDR_PACK_DVRFTCTRL_dvreft_maxv_END (6)
#define SOC_DDR_PACK_DVRFTCTRL_dvreft_minv_START (8)
#define SOC_DDR_PACK_DVRFTCTRL_dvreft_minv_END (14)
#define SOC_DDR_PACK_DVRFTCTRL_dvreft_step_START (16)
#define SOC_DDR_PACK_DVRFTCTRL_dvreft_step_END (21)
#define SOC_DDR_PACK_DVRFTCTRL_dvreft_hckpts_START (24)
#define SOC_DDR_PACK_DVRFTCTRL_dvreft_hckpts_END (29)
#define SOC_DDR_PACK_DVRFTCTRL_pdaen_START (31)
#define SOC_DDR_PACK_DVRFTCTRL_pdaen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hvreft_maxv : 7;
        unsigned int reserved_0 : 1;
        unsigned int hvreft_minv : 7;
        unsigned int reserved_1 : 1;
        unsigned int hvreft_step : 6;
        unsigned int hvreft_hckpts : 6;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_DDR_PACK_HVRFTCTRL_UNION;
#endif
#define SOC_DDR_PACK_HVRFTCTRL_hvreft_maxv_START (0)
#define SOC_DDR_PACK_HVRFTCTRL_hvreft_maxv_END (6)
#define SOC_DDR_PACK_HVRFTCTRL_hvreft_minv_START (8)
#define SOC_DDR_PACK_HVRFTCTRL_hvreft_minv_END (14)
#define SOC_DDR_PACK_HVRFTCTRL_hvreft_step_START (16)
#define SOC_DDR_PACK_HVRFTCTRL_hvreft_step_END (21)
#define SOC_DDR_PACK_HVRFTCTRL_hvreft_hckpts_START (22)
#define SOC_DDR_PACK_HVRFTCTRL_hvreft_hckpts_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdet_samp_num : 8;
        unsigned int cfg_fast_rdet_cnt : 3;
        unsigned int wdet_ct_dqs_en : 1;
        unsigned int wrdet_av_en : 1;
        unsigned int wdet_rbs_en : 1;
        unsigned int wdet_ds_en : 1;
        unsigned int wdet_lbs_en : 1;
        unsigned int rdet_samp_num : 8;
        unsigned int cfg_wdert_hyp_mode_sel : 1;
        unsigned int fast_rdet_en : 1;
        unsigned int rdet_dq_evenodd_en : 1;
        unsigned int rdet_ct_dqs_en : 1;
        unsigned int rdet_av_en : 1;
        unsigned int rdet_rbs_en : 1;
        unsigned int rdet_ds_en : 1;
        unsigned int rdet_lbs_en : 1;
    } reg;
} SOC_DDR_PACK_TRAINCTRL1_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL1_wdet_samp_num_START (0)
#define SOC_DDR_PACK_TRAINCTRL1_wdet_samp_num_END (7)
#define SOC_DDR_PACK_TRAINCTRL1_cfg_fast_rdet_cnt_START (8)
#define SOC_DDR_PACK_TRAINCTRL1_cfg_fast_rdet_cnt_END (10)
#define SOC_DDR_PACK_TRAINCTRL1_wdet_ct_dqs_en_START (11)
#define SOC_DDR_PACK_TRAINCTRL1_wdet_ct_dqs_en_END (11)
#define SOC_DDR_PACK_TRAINCTRL1_wrdet_av_en_START (12)
#define SOC_DDR_PACK_TRAINCTRL1_wrdet_av_en_END (12)
#define SOC_DDR_PACK_TRAINCTRL1_wdet_rbs_en_START (13)
#define SOC_DDR_PACK_TRAINCTRL1_wdet_rbs_en_END (13)
#define SOC_DDR_PACK_TRAINCTRL1_wdet_ds_en_START (14)
#define SOC_DDR_PACK_TRAINCTRL1_wdet_ds_en_END (14)
#define SOC_DDR_PACK_TRAINCTRL1_wdet_lbs_en_START (15)
#define SOC_DDR_PACK_TRAINCTRL1_wdet_lbs_en_END (15)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_samp_num_START (16)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_samp_num_END (23)
#define SOC_DDR_PACK_TRAINCTRL1_cfg_wdert_hyp_mode_sel_START (24)
#define SOC_DDR_PACK_TRAINCTRL1_cfg_wdert_hyp_mode_sel_END (24)
#define SOC_DDR_PACK_TRAINCTRL1_fast_rdet_en_START (25)
#define SOC_DDR_PACK_TRAINCTRL1_fast_rdet_en_END (25)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_dq_evenodd_en_START (26)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_dq_evenodd_en_END (26)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_ct_dqs_en_START (27)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_ct_dqs_en_END (27)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_av_en_START (28)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_av_en_END (28)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_rbs_en_START (29)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_rbs_en_END (29)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_ds_en_START (30)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_ds_en_END (30)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_lbs_en_START (31)
#define SOC_DDR_PACK_TRAINCTRL1_rdet_lbs_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mrr_pat_A : 8;
        unsigned int mrr_pat_B : 8;
        unsigned int mrr_pat_mask : 8;
        unsigned int rbound_sfal_en : 1;
        unsigned int fast_gt_en : 1;
        unsigned int fast_gdst_en : 1;
        unsigned int mrr_bl4 : 1;
        unsigned int mrr_pat_order : 3;
        unsigned int rdet_method_sel : 1;
    } reg;
} SOC_DDR_PACK_TRAINCTRL2_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL2_mrr_pat_A_START (0)
#define SOC_DDR_PACK_TRAINCTRL2_mrr_pat_A_END (7)
#define SOC_DDR_PACK_TRAINCTRL2_mrr_pat_B_START (8)
#define SOC_DDR_PACK_TRAINCTRL2_mrr_pat_B_END (15)
#define SOC_DDR_PACK_TRAINCTRL2_mrr_pat_mask_START (16)
#define SOC_DDR_PACK_TRAINCTRL2_mrr_pat_mask_END (23)
#define SOC_DDR_PACK_TRAINCTRL2_rbound_sfal_en_START (24)
#define SOC_DDR_PACK_TRAINCTRL2_rbound_sfal_en_END (24)
#define SOC_DDR_PACK_TRAINCTRL2_fast_gt_en_START (25)
#define SOC_DDR_PACK_TRAINCTRL2_fast_gt_en_END (25)
#define SOC_DDR_PACK_TRAINCTRL2_fast_gdst_en_START (26)
#define SOC_DDR_PACK_TRAINCTRL2_fast_gdst_en_END (26)
#define SOC_DDR_PACK_TRAINCTRL2_mrr_bl4_START (27)
#define SOC_DDR_PACK_TRAINCTRL2_mrr_bl4_END (27)
#define SOC_DDR_PACK_TRAINCTRL2_mrr_pat_order_START (28)
#define SOC_DDR_PACK_TRAINCTRL2_mrr_pat_order_END (30)
#define SOC_DDR_PACK_TRAINCTRL2_rdet_method_sel_START (31)
#define SOC_DDR_PACK_TRAINCTRL2_rdet_method_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wr_sel : 2;
        unsigned int op_sel : 2;
        unsigned int sync_src_sel : 2;
        unsigned int sync_tar_sel : 2;
        unsigned int shadow_sync_en : 1;
        unsigned int hw_opsel_seq : 1;
        unsigned int hw_opsel_mode_en : 1;
        unsigned int hw_op_sel : 2;
        unsigned int rs_cg_byp : 1;
        unsigned int cfg_gt_cnt : 4;
        unsigned int mc_opsel_chg_done : 1;
        unsigned int cke_pd_byp : 1;
        unsigned int cfg_cke_pd_cnt : 4;
        unsigned int hw_opsel_hsk_byp : 1;
        unsigned int reserved : 6;
        unsigned int opsel_chg : 1;
    } reg;
} SOC_DDR_PACK_REGBANKCTRL_UNION;
#endif
#define SOC_DDR_PACK_REGBANKCTRL_wr_sel_START (0)
#define SOC_DDR_PACK_REGBANKCTRL_wr_sel_END (1)
#define SOC_DDR_PACK_REGBANKCTRL_op_sel_START (2)
#define SOC_DDR_PACK_REGBANKCTRL_op_sel_END (3)
#define SOC_DDR_PACK_REGBANKCTRL_sync_src_sel_START (4)
#define SOC_DDR_PACK_REGBANKCTRL_sync_src_sel_END (5)
#define SOC_DDR_PACK_REGBANKCTRL_sync_tar_sel_START (6)
#define SOC_DDR_PACK_REGBANKCTRL_sync_tar_sel_END (7)
#define SOC_DDR_PACK_REGBANKCTRL_shadow_sync_en_START (8)
#define SOC_DDR_PACK_REGBANKCTRL_shadow_sync_en_END (8)
#define SOC_DDR_PACK_REGBANKCTRL_hw_opsel_seq_START (9)
#define SOC_DDR_PACK_REGBANKCTRL_hw_opsel_seq_END (9)
#define SOC_DDR_PACK_REGBANKCTRL_hw_opsel_mode_en_START (10)
#define SOC_DDR_PACK_REGBANKCTRL_hw_opsel_mode_en_END (10)
#define SOC_DDR_PACK_REGBANKCTRL_hw_op_sel_START (11)
#define SOC_DDR_PACK_REGBANKCTRL_hw_op_sel_END (12)
#define SOC_DDR_PACK_REGBANKCTRL_rs_cg_byp_START (13)
#define SOC_DDR_PACK_REGBANKCTRL_rs_cg_byp_END (13)
#define SOC_DDR_PACK_REGBANKCTRL_cfg_gt_cnt_START (14)
#define SOC_DDR_PACK_REGBANKCTRL_cfg_gt_cnt_END (17)
#define SOC_DDR_PACK_REGBANKCTRL_mc_opsel_chg_done_START (18)
#define SOC_DDR_PACK_REGBANKCTRL_mc_opsel_chg_done_END (18)
#define SOC_DDR_PACK_REGBANKCTRL_cke_pd_byp_START (19)
#define SOC_DDR_PACK_REGBANKCTRL_cke_pd_byp_END (19)
#define SOC_DDR_PACK_REGBANKCTRL_cfg_cke_pd_cnt_START (20)
#define SOC_DDR_PACK_REGBANKCTRL_cfg_cke_pd_cnt_END (23)
#define SOC_DDR_PACK_REGBANKCTRL_hw_opsel_hsk_byp_START (24)
#define SOC_DDR_PACK_REGBANKCTRL_hw_opsel_hsk_byp_END (24)
#define SOC_DDR_PACK_REGBANKCTRL_opsel_chg_START (31)
#define SOC_DDR_PACK_REGBANKCTRL_opsel_chg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_wlresult_inv : 1;
        unsigned int cfg_msp_train_active : 1;
        unsigned int cfg_msp_train_en : 1;
        unsigned int rg_msp2xratio : 1;
        unsigned int cfg_internal_mcu_sel : 1;
        unsigned int det_bist_method_en : 1;
        unsigned int wdet_dbi_en : 1;
        unsigned int cfg_wdet2pat_en : 1;
        unsigned int chk_step_adj : 1;
        unsigned int chk_step_margin : 1;
        unsigned int mpcfifo_only_read_repeat : 1;
        unsigned int rdert_mpcfifo : 1;
        unsigned int wderten : 1;
        unsigned int wdet_rank_en : 1;
        unsigned int wrenrkswen : 1;
        unsigned int nopre4wrdet : 1;
        unsigned int gdsrt_backtap : 3;
        unsigned int rdet_rank_en : 1;
        unsigned int rdet_dbi_en : 1;
        unsigned int cat_pat_toggle_en : 1;
        unsigned int rpt_mode_en : 1;
        unsigned int wdet_method_sel : 1;
        unsigned int fast_gt_cnt : 5;
        unsigned int cfg_upd_scandq_en : 1;
        unsigned int rdet_fcomp_en : 1;
        unsigned int exd_gtres_en : 1;
    } reg;
} SOC_DDR_PACK_TRAINCTRL3_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL3_cfg_wlresult_inv_START (0)
#define SOC_DDR_PACK_TRAINCTRL3_cfg_wlresult_inv_END (0)
#define SOC_DDR_PACK_TRAINCTRL3_cfg_msp_train_active_START (1)
#define SOC_DDR_PACK_TRAINCTRL3_cfg_msp_train_active_END (1)
#define SOC_DDR_PACK_TRAINCTRL3_cfg_msp_train_en_START (2)
#define SOC_DDR_PACK_TRAINCTRL3_cfg_msp_train_en_END (2)
#define SOC_DDR_PACK_TRAINCTRL3_rg_msp2xratio_START (3)
#define SOC_DDR_PACK_TRAINCTRL3_rg_msp2xratio_END (3)
#define SOC_DDR_PACK_TRAINCTRL3_cfg_internal_mcu_sel_START (4)
#define SOC_DDR_PACK_TRAINCTRL3_cfg_internal_mcu_sel_END (4)
#define SOC_DDR_PACK_TRAINCTRL3_det_bist_method_en_START (5)
#define SOC_DDR_PACK_TRAINCTRL3_det_bist_method_en_END (5)
#define SOC_DDR_PACK_TRAINCTRL3_wdet_dbi_en_START (6)
#define SOC_DDR_PACK_TRAINCTRL3_wdet_dbi_en_END (6)
#define SOC_DDR_PACK_TRAINCTRL3_cfg_wdet2pat_en_START (7)
#define SOC_DDR_PACK_TRAINCTRL3_cfg_wdet2pat_en_END (7)
#define SOC_DDR_PACK_TRAINCTRL3_chk_step_adj_START (8)
#define SOC_DDR_PACK_TRAINCTRL3_chk_step_adj_END (8)
#define SOC_DDR_PACK_TRAINCTRL3_chk_step_margin_START (9)
#define SOC_DDR_PACK_TRAINCTRL3_chk_step_margin_END (9)
#define SOC_DDR_PACK_TRAINCTRL3_mpcfifo_only_read_repeat_START (10)
#define SOC_DDR_PACK_TRAINCTRL3_mpcfifo_only_read_repeat_END (10)
#define SOC_DDR_PACK_TRAINCTRL3_rdert_mpcfifo_START (11)
#define SOC_DDR_PACK_TRAINCTRL3_rdert_mpcfifo_END (11)
#define SOC_DDR_PACK_TRAINCTRL3_wderten_START (12)
#define SOC_DDR_PACK_TRAINCTRL3_wderten_END (12)
#define SOC_DDR_PACK_TRAINCTRL3_wdet_rank_en_START (13)
#define SOC_DDR_PACK_TRAINCTRL3_wdet_rank_en_END (13)
#define SOC_DDR_PACK_TRAINCTRL3_wrenrkswen_START (14)
#define SOC_DDR_PACK_TRAINCTRL3_wrenrkswen_END (14)
#define SOC_DDR_PACK_TRAINCTRL3_nopre4wrdet_START (15)
#define SOC_DDR_PACK_TRAINCTRL3_nopre4wrdet_END (15)
#define SOC_DDR_PACK_TRAINCTRL3_gdsrt_backtap_START (16)
#define SOC_DDR_PACK_TRAINCTRL3_gdsrt_backtap_END (18)
#define SOC_DDR_PACK_TRAINCTRL3_rdet_rank_en_START (19)
#define SOC_DDR_PACK_TRAINCTRL3_rdet_rank_en_END (19)
#define SOC_DDR_PACK_TRAINCTRL3_rdet_dbi_en_START (20)
#define SOC_DDR_PACK_TRAINCTRL3_rdet_dbi_en_END (20)
#define SOC_DDR_PACK_TRAINCTRL3_cat_pat_toggle_en_START (21)
#define SOC_DDR_PACK_TRAINCTRL3_cat_pat_toggle_en_END (21)
#define SOC_DDR_PACK_TRAINCTRL3_rpt_mode_en_START (22)
#define SOC_DDR_PACK_TRAINCTRL3_rpt_mode_en_END (22)
#define SOC_DDR_PACK_TRAINCTRL3_wdet_method_sel_START (23)
#define SOC_DDR_PACK_TRAINCTRL3_wdet_method_sel_END (23)
#define SOC_DDR_PACK_TRAINCTRL3_fast_gt_cnt_START (24)
#define SOC_DDR_PACK_TRAINCTRL3_fast_gt_cnt_END (28)
#define SOC_DDR_PACK_TRAINCTRL3_cfg_upd_scandq_en_START (29)
#define SOC_DDR_PACK_TRAINCTRL3_cfg_upd_scandq_en_END (29)
#define SOC_DDR_PACK_TRAINCTRL3_rdet_fcomp_en_START (30)
#define SOC_DDR_PACK_TRAINCTRL3_rdet_fcomp_en_END (30)
#define SOC_DDR_PACK_TRAINCTRL3_exd_gtres_en_START (31)
#define SOC_DDR_PACK_TRAINCTRL3_exd_gtres_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mr4 : 16;
        unsigned int mr5 : 16;
    } reg;
} SOC_DDR_PACK_MODEREG45_UNION;
#endif
#define SOC_DDR_PACK_MODEREG45_mr4_START (0)
#define SOC_DDR_PACK_MODEREG45_mr4_END (15)
#define SOC_DDR_PACK_MODEREG45_mr5_START (16)
#define SOC_DDR_PACK_MODEREG45_mr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mr6 : 16;
        unsigned int mr7 : 16;
    } reg;
} SOC_DDR_PACK_MODEREG67_UNION;
#endif
#define SOC_DDR_PACK_MODEREG67_mr6_START (0)
#define SOC_DDR_PACK_MODEREG67_mr6_END (15)
#define SOC_DDR_PACK_MODEREG67_mr7_START (16)
#define SOC_DDR_PACK_MODEREG67_mr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyupdtimer : 16;
        unsigned int cfg_reg_sync_cnt : 4;
        unsigned int cat_re_deskew_en : 1;
        unsigned int det_re_deskew_en : 1;
        unsigned int half_ph_bdl_en : 1;
        unsigned int bdlcarry_done : 1;
        unsigned int row_react_period : 8;
    } reg;
} SOC_DDR_PACK_TRAINCTRL6_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL6_phyupdtimer_START (0)
#define SOC_DDR_PACK_TRAINCTRL6_phyupdtimer_END (15)
#define SOC_DDR_PACK_TRAINCTRL6_cfg_reg_sync_cnt_START (16)
#define SOC_DDR_PACK_TRAINCTRL6_cfg_reg_sync_cnt_END (19)
#define SOC_DDR_PACK_TRAINCTRL6_cat_re_deskew_en_START (20)
#define SOC_DDR_PACK_TRAINCTRL6_cat_re_deskew_en_END (20)
#define SOC_DDR_PACK_TRAINCTRL6_det_re_deskew_en_START (21)
#define SOC_DDR_PACK_TRAINCTRL6_det_re_deskew_en_END (21)
#define SOC_DDR_PACK_TRAINCTRL6_half_ph_bdl_en_START (22)
#define SOC_DDR_PACK_TRAINCTRL6_half_ph_bdl_en_END (22)
#define SOC_DDR_PACK_TRAINCTRL6_bdlcarry_done_START (23)
#define SOC_DDR_PACK_TRAINCTRL6_bdlcarry_done_END (23)
#define SOC_DDR_PACK_TRAINCTRL6_row_react_period_START (24)
#define SOC_DDR_PACK_TRAINCTRL6_row_react_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int det_pat_index : 4;
        unsigned int det_pat_alt_index : 3;
        unsigned int det_pat_alt_enable : 1;
        unsigned int det_pat_dir : 2;
        unsigned int reserved_0 : 6;
        unsigned int cfg_zqcal_rsv : 5;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_DDR_PACK_DETPATINDEX_UNION;
#endif
#define SOC_DDR_PACK_DETPATINDEX_det_pat_index_START (0)
#define SOC_DDR_PACK_DETPATINDEX_det_pat_index_END (3)
#define SOC_DDR_PACK_DETPATINDEX_det_pat_alt_index_START (4)
#define SOC_DDR_PACK_DETPATINDEX_det_pat_alt_index_END (6)
#define SOC_DDR_PACK_DETPATINDEX_det_pat_alt_enable_START (7)
#define SOC_DDR_PACK_DETPATINDEX_det_pat_alt_enable_END (7)
#define SOC_DDR_PACK_DETPATINDEX_det_pat_dir_START (8)
#define SOC_DDR_PACK_DETPATINDEX_det_pat_dir_END (9)
#define SOC_DDR_PACK_DETPATINDEX_cfg_zqcal_rsv_START (16)
#define SOC_DDR_PACK_DETPATINDEX_cfg_zqcal_rsv_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdet_ph_fine_step : 3;
        unsigned int reserved_0 : 1;
        unsigned int cat_ph_fine_step : 3;
        unsigned int reserved_1 : 1;
        unsigned int gt_ph_fine_step : 3;
        unsigned int reserved_2 : 1;
        unsigned int wl_ph_fine_step : 3;
        unsigned int reserved_3 : 1;
        unsigned int gt_bdl_step : 4;
        unsigned int gt_ph_step : 4;
        unsigned int wl_bdl_step : 4;
        unsigned int wl_ph_step : 4;
    } reg;
} SOC_DDR_PACK_TRAINSTEP0_UNION;
#endif
#define SOC_DDR_PACK_TRAINSTEP0_wdet_ph_fine_step_START (0)
#define SOC_DDR_PACK_TRAINSTEP0_wdet_ph_fine_step_END (2)
#define SOC_DDR_PACK_TRAINSTEP0_cat_ph_fine_step_START (4)
#define SOC_DDR_PACK_TRAINSTEP0_cat_ph_fine_step_END (6)
#define SOC_DDR_PACK_TRAINSTEP0_gt_ph_fine_step_START (8)
#define SOC_DDR_PACK_TRAINSTEP0_gt_ph_fine_step_END (10)
#define SOC_DDR_PACK_TRAINSTEP0_wl_ph_fine_step_START (12)
#define SOC_DDR_PACK_TRAINSTEP0_wl_ph_fine_step_END (14)
#define SOC_DDR_PACK_TRAINSTEP0_gt_bdl_step_START (16)
#define SOC_DDR_PACK_TRAINSTEP0_gt_bdl_step_END (19)
#define SOC_DDR_PACK_TRAINSTEP0_gt_ph_step_START (20)
#define SOC_DDR_PACK_TRAINSTEP0_gt_ph_step_END (23)
#define SOC_DDR_PACK_TRAINSTEP0_wl_bdl_step_START (24)
#define SOC_DDR_PACK_TRAINSTEP0_wl_bdl_step_END (27)
#define SOC_DDR_PACK_TRAINSTEP0_wl_ph_step_START (28)
#define SOC_DDR_PACK_TRAINSTEP0_wl_ph_step_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cat_bdl_step : 4;
        unsigned int cat_ph_step : 4;
        unsigned int cat_lb_backtap : 5;
        unsigned int reserved_0 : 3;
        unsigned int cat_rb_backtap : 5;
        unsigned int reserved_1 : 1;
        unsigned int cat_open_bdl_jstep : 4;
        unsigned int cat_open_ph_jstep : 5;
        unsigned int cat_eye_open_jump_en : 1;
    } reg;
} SOC_DDR_PACK_TRAINSTEP1_UNION;
#endif
#define SOC_DDR_PACK_TRAINSTEP1_cat_bdl_step_START (0)
#define SOC_DDR_PACK_TRAINSTEP1_cat_bdl_step_END (3)
#define SOC_DDR_PACK_TRAINSTEP1_cat_ph_step_START (4)
#define SOC_DDR_PACK_TRAINSTEP1_cat_ph_step_END (7)
#define SOC_DDR_PACK_TRAINSTEP1_cat_lb_backtap_START (8)
#define SOC_DDR_PACK_TRAINSTEP1_cat_lb_backtap_END (12)
#define SOC_DDR_PACK_TRAINSTEP1_cat_rb_backtap_START (16)
#define SOC_DDR_PACK_TRAINSTEP1_cat_rb_backtap_END (20)
#define SOC_DDR_PACK_TRAINSTEP1_cat_open_bdl_jstep_START (22)
#define SOC_DDR_PACK_TRAINSTEP1_cat_open_bdl_jstep_END (25)
#define SOC_DDR_PACK_TRAINSTEP1_cat_open_ph_jstep_START (26)
#define SOC_DDR_PACK_TRAINSTEP1_cat_open_ph_jstep_END (30)
#define SOC_DDR_PACK_TRAINSTEP1_cat_eye_open_jump_en_START (31)
#define SOC_DDR_PACK_TRAINSTEP1_cat_eye_open_jump_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdet_bdl_step : 4;
        unsigned int wdet_ph_step : 4;
        unsigned int wdet_lb_backtap : 5;
        unsigned int reserved_0 : 3;
        unsigned int wdet_rb_backtap : 5;
        unsigned int reserved_1 : 1;
        unsigned int wdet_open_bdl_jstep : 4;
        unsigned int wdet_open_ph_jstep : 5;
        unsigned int det_eye_open_jump_en : 1;
    } reg;
} SOC_DDR_PACK_TRAINSTEP2_UNION;
#endif
#define SOC_DDR_PACK_TRAINSTEP2_wdet_bdl_step_START (0)
#define SOC_DDR_PACK_TRAINSTEP2_wdet_bdl_step_END (3)
#define SOC_DDR_PACK_TRAINSTEP2_wdet_ph_step_START (4)
#define SOC_DDR_PACK_TRAINSTEP2_wdet_ph_step_END (7)
#define SOC_DDR_PACK_TRAINSTEP2_wdet_lb_backtap_START (8)
#define SOC_DDR_PACK_TRAINSTEP2_wdet_lb_backtap_END (12)
#define SOC_DDR_PACK_TRAINSTEP2_wdet_rb_backtap_START (16)
#define SOC_DDR_PACK_TRAINSTEP2_wdet_rb_backtap_END (20)
#define SOC_DDR_PACK_TRAINSTEP2_wdet_open_bdl_jstep_START (22)
#define SOC_DDR_PACK_TRAINSTEP2_wdet_open_bdl_jstep_END (25)
#define SOC_DDR_PACK_TRAINSTEP2_wdet_open_ph_jstep_START (26)
#define SOC_DDR_PACK_TRAINSTEP2_wdet_open_ph_jstep_END (30)
#define SOC_DDR_PACK_TRAINSTEP2_det_eye_open_jump_en_START (31)
#define SOC_DDR_PACK_TRAINSTEP2_det_eye_open_jump_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_cmp_mask : 16;
        unsigned int ba_cmp_mask : 3;
        unsigned int we_cmp_mask : 1;
        unsigned int cas_cmp_mask : 1;
        unsigned int ras_cmp_mask : 1;
        unsigned int cs_cmp_mask : 4;
        unsigned int rst_cmp_mask : 1;
        unsigned int acbist_en : 1;
        unsigned int aclpbk_tg : 1;
        unsigned int ac_rdffsel : 3;
    } reg;
} SOC_DDR_PACK_ACBISTCTRL0_UNION;
#endif
#define SOC_DDR_PACK_ACBISTCTRL0_addr_cmp_mask_START (0)
#define SOC_DDR_PACK_ACBISTCTRL0_addr_cmp_mask_END (15)
#define SOC_DDR_PACK_ACBISTCTRL0_ba_cmp_mask_START (16)
#define SOC_DDR_PACK_ACBISTCTRL0_ba_cmp_mask_END (18)
#define SOC_DDR_PACK_ACBISTCTRL0_we_cmp_mask_START (19)
#define SOC_DDR_PACK_ACBISTCTRL0_we_cmp_mask_END (19)
#define SOC_DDR_PACK_ACBISTCTRL0_cas_cmp_mask_START (20)
#define SOC_DDR_PACK_ACBISTCTRL0_cas_cmp_mask_END (20)
#define SOC_DDR_PACK_ACBISTCTRL0_ras_cmp_mask_START (21)
#define SOC_DDR_PACK_ACBISTCTRL0_ras_cmp_mask_END (21)
#define SOC_DDR_PACK_ACBISTCTRL0_cs_cmp_mask_START (22)
#define SOC_DDR_PACK_ACBISTCTRL0_cs_cmp_mask_END (25)
#define SOC_DDR_PACK_ACBISTCTRL0_rst_cmp_mask_START (26)
#define SOC_DDR_PACK_ACBISTCTRL0_rst_cmp_mask_END (26)
#define SOC_DDR_PACK_ACBISTCTRL0_acbist_en_START (27)
#define SOC_DDR_PACK_ACBISTCTRL0_acbist_en_END (27)
#define SOC_DDR_PACK_ACBISTCTRL0_aclpbk_tg_START (28)
#define SOC_DDR_PACK_ACBISTCTRL0_aclpbk_tg_END (28)
#define SOC_DDR_PACK_ACBISTCTRL0_ac_rdffsel_START (29)
#define SOC_DDR_PACK_ACBISTCTRL0_ac_rdffsel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int odt_cmp_mask : 4;
        unsigned int cke_cmp_mask : 4;
        unsigned int ac_lfsr_seed : 8;
        unsigned int par_cmp_mask : 1;
        unsigned int bg1_cmp_mask : 1;
        unsigned int act_cmp_mask : 1;
        unsigned int prbs_mode : 1;
        unsigned int addro_fp : 1;
        unsigned int cso_fp : 1;
        unsigned int ckeo_fp : 1;
        unsigned int cso_cmp_msk : 4;
        unsigned int ckeo_cmp_msk : 4;
        unsigned int cso_cke0_p1_cmp_msk : 1;
    } reg;
} SOC_DDR_PACK_ACBISTCTRL1_UNION;
#endif
#define SOC_DDR_PACK_ACBISTCTRL1_odt_cmp_mask_START (0)
#define SOC_DDR_PACK_ACBISTCTRL1_odt_cmp_mask_END (3)
#define SOC_DDR_PACK_ACBISTCTRL1_cke_cmp_mask_START (4)
#define SOC_DDR_PACK_ACBISTCTRL1_cke_cmp_mask_END (7)
#define SOC_DDR_PACK_ACBISTCTRL1_ac_lfsr_seed_START (8)
#define SOC_DDR_PACK_ACBISTCTRL1_ac_lfsr_seed_END (15)
#define SOC_DDR_PACK_ACBISTCTRL1_par_cmp_mask_START (16)
#define SOC_DDR_PACK_ACBISTCTRL1_par_cmp_mask_END (16)
#define SOC_DDR_PACK_ACBISTCTRL1_bg1_cmp_mask_START (17)
#define SOC_DDR_PACK_ACBISTCTRL1_bg1_cmp_mask_END (17)
#define SOC_DDR_PACK_ACBISTCTRL1_act_cmp_mask_START (18)
#define SOC_DDR_PACK_ACBISTCTRL1_act_cmp_mask_END (18)
#define SOC_DDR_PACK_ACBISTCTRL1_prbs_mode_START (19)
#define SOC_DDR_PACK_ACBISTCTRL1_prbs_mode_END (19)
#define SOC_DDR_PACK_ACBISTCTRL1_addro_fp_START (20)
#define SOC_DDR_PACK_ACBISTCTRL1_addro_fp_END (20)
#define SOC_DDR_PACK_ACBISTCTRL1_cso_fp_START (21)
#define SOC_DDR_PACK_ACBISTCTRL1_cso_fp_END (21)
#define SOC_DDR_PACK_ACBISTCTRL1_ckeo_fp_START (22)
#define SOC_DDR_PACK_ACBISTCTRL1_ckeo_fp_END (22)
#define SOC_DDR_PACK_ACBISTCTRL1_cso_cmp_msk_START (23)
#define SOC_DDR_PACK_ACBISTCTRL1_cso_cmp_msk_END (26)
#define SOC_DDR_PACK_ACBISTCTRL1_ckeo_cmp_msk_START (27)
#define SOC_DDR_PACK_ACBISTCTRL1_ckeo_cmp_msk_END (30)
#define SOC_DDR_PACK_ACBISTCTRL1_cso_cke0_p1_cmp_msk_START (31)
#define SOC_DDR_PACK_ACBISTCTRL1_cso_cke0_p1_cmp_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_e_bist_err : 16;
        unsigned int ba_bist_err : 3;
        unsigned int we_bist_err : 1;
        unsigned int cas_bist_err : 1;
        unsigned int ras_bist_err : 1;
        unsigned int cs_e_bist_err : 4;
        unsigned int rst_bist_err : 1;
        unsigned int par_bist_err : 1;
        unsigned int bg1_bist_err : 1;
        unsigned int act_bist_err : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_PACK_ACBISTSTS0_UNION;
#endif
#define SOC_DDR_PACK_ACBISTSTS0_addr_e_bist_err_START (0)
#define SOC_DDR_PACK_ACBISTSTS0_addr_e_bist_err_END (15)
#define SOC_DDR_PACK_ACBISTSTS0_ba_bist_err_START (16)
#define SOC_DDR_PACK_ACBISTSTS0_ba_bist_err_END (18)
#define SOC_DDR_PACK_ACBISTSTS0_we_bist_err_START (19)
#define SOC_DDR_PACK_ACBISTSTS0_we_bist_err_END (19)
#define SOC_DDR_PACK_ACBISTSTS0_cas_bist_err_START (20)
#define SOC_DDR_PACK_ACBISTSTS0_cas_bist_err_END (20)
#define SOC_DDR_PACK_ACBISTSTS0_ras_bist_err_START (21)
#define SOC_DDR_PACK_ACBISTSTS0_ras_bist_err_END (21)
#define SOC_DDR_PACK_ACBISTSTS0_cs_e_bist_err_START (22)
#define SOC_DDR_PACK_ACBISTSTS0_cs_e_bist_err_END (25)
#define SOC_DDR_PACK_ACBISTSTS0_rst_bist_err_START (26)
#define SOC_DDR_PACK_ACBISTSTS0_rst_bist_err_END (26)
#define SOC_DDR_PACK_ACBISTSTS0_par_bist_err_START (27)
#define SOC_DDR_PACK_ACBISTSTS0_par_bist_err_END (27)
#define SOC_DDR_PACK_ACBISTSTS0_bg1_bist_err_START (28)
#define SOC_DDR_PACK_ACBISTSTS0_bg1_bist_err_END (28)
#define SOC_DDR_PACK_ACBISTSTS0_act_bist_err_START (29)
#define SOC_DDR_PACK_ACBISTSTS0_act_bist_err_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int odt_bist_err : 4;
        unsigned int cke_e_bist_err : 4;
        unsigned int cs_o_bist_err : 4;
        unsigned int cke_o_bist_err : 4;
        unsigned int addr_o_bist_err : 16;
    } reg;
} SOC_DDR_PACK_ACBISTSTS1_UNION;
#endif
#define SOC_DDR_PACK_ACBISTSTS1_odt_bist_err_START (0)
#define SOC_DDR_PACK_ACBISTSTS1_odt_bist_err_END (3)
#define SOC_DDR_PACK_ACBISTSTS1_cke_e_bist_err_START (4)
#define SOC_DDR_PACK_ACBISTSTS1_cke_e_bist_err_END (7)
#define SOC_DDR_PACK_ACBISTSTS1_cs_o_bist_err_START (8)
#define SOC_DDR_PACK_ACBISTSTS1_cs_o_bist_err_END (11)
#define SOC_DDR_PACK_ACBISTSTS1_cke_o_bist_err_START (12)
#define SOC_DDR_PACK_ACBISTSTS1_cke_o_bist_err_END (15)
#define SOC_DDR_PACK_ACBISTSTS1_addr_o_bist_err_START (16)
#define SOC_DDR_PACK_ACBISTSTS1_addr_o_bist_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdqphase_left_bytelane0 : 8;
        unsigned int wdqphase_left_bytelane1 : 8;
        unsigned int wdq0bdl_left_bytelane0 : 8;
        unsigned int wdq0bdl_left_bytelane1 : 8;
    } reg;
} SOC_DDR_PACK_WDXBOUND_DFS_UNION;
#endif
#define SOC_DDR_PACK_WDXBOUND_DFS_wdqphase_left_bytelane0_START (0)
#define SOC_DDR_PACK_WDXBOUND_DFS_wdqphase_left_bytelane0_END (7)
#define SOC_DDR_PACK_WDXBOUND_DFS_wdqphase_left_bytelane1_START (8)
#define SOC_DDR_PACK_WDXBOUND_DFS_wdqphase_left_bytelane1_END (15)
#define SOC_DDR_PACK_WDXBOUND_DFS_wdq0bdl_left_bytelane0_START (16)
#define SOC_DDR_PACK_WDXBOUND_DFS_wdq0bdl_left_bytelane0_END (23)
#define SOC_DDR_PACK_WDXBOUND_DFS_wdq0bdl_left_bytelane1_START (24)
#define SOC_DDR_PACK_WDXBOUND_DFS_wdq0bdl_left_bytelane1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rg_msp4xratio : 1;
        unsigned int gtfback_inf_clr_en : 1;
        unsigned int gt_90BDL_step_en : 1;
        unsigned int gt_BPT_step_en : 1;
        unsigned int dqsg_track_limit : 7;
        unsigned int rdert_bdl_mode : 1;
        unsigned int rdet_lb_backtap : 4;
        unsigned int rdet_rb_backtap : 9;
        unsigned int IsBypMode : 1;
        unsigned int rdert_comp_en : 1;
        unsigned int fast_shift_step : 2;
        unsigned int fast_check_step : 2;
        unsigned int rdet_dq_rank_en : 1;
    } reg;
} SOC_DDR_PACK_TRAINCTRL4_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL4_rg_msp4xratio_START (0)
#define SOC_DDR_PACK_TRAINCTRL4_rg_msp4xratio_END (0)
#define SOC_DDR_PACK_TRAINCTRL4_gtfback_inf_clr_en_START (1)
#define SOC_DDR_PACK_TRAINCTRL4_gtfback_inf_clr_en_END (1)
#define SOC_DDR_PACK_TRAINCTRL4_gt_90BDL_step_en_START (2)
#define SOC_DDR_PACK_TRAINCTRL4_gt_90BDL_step_en_END (2)
#define SOC_DDR_PACK_TRAINCTRL4_gt_BPT_step_en_START (3)
#define SOC_DDR_PACK_TRAINCTRL4_gt_BPT_step_en_END (3)
#define SOC_DDR_PACK_TRAINCTRL4_dqsg_track_limit_START (4)
#define SOC_DDR_PACK_TRAINCTRL4_dqsg_track_limit_END (10)
#define SOC_DDR_PACK_TRAINCTRL4_rdert_bdl_mode_START (11)
#define SOC_DDR_PACK_TRAINCTRL4_rdert_bdl_mode_END (11)
#define SOC_DDR_PACK_TRAINCTRL4_rdet_lb_backtap_START (12)
#define SOC_DDR_PACK_TRAINCTRL4_rdet_lb_backtap_END (15)
#define SOC_DDR_PACK_TRAINCTRL4_rdet_rb_backtap_START (16)
#define SOC_DDR_PACK_TRAINCTRL4_rdet_rb_backtap_END (24)
#define SOC_DDR_PACK_TRAINCTRL4_IsBypMode_START (25)
#define SOC_DDR_PACK_TRAINCTRL4_IsBypMode_END (25)
#define SOC_DDR_PACK_TRAINCTRL4_rdert_comp_en_START (26)
#define SOC_DDR_PACK_TRAINCTRL4_rdert_comp_en_END (26)
#define SOC_DDR_PACK_TRAINCTRL4_fast_shift_step_START (27)
#define SOC_DDR_PACK_TRAINCTRL4_fast_shift_step_END (28)
#define SOC_DDR_PACK_TRAINCTRL4_fast_check_step_START (29)
#define SOC_DDR_PACK_TRAINCTRL4_fast_check_step_END (30)
#define SOC_DDR_PACK_TRAINCTRL4_rdet_dq_rank_en_START (31)
#define SOC_DDR_PACK_TRAINCTRL4_rdet_dq_rank_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlym_dummyrd_cnt : 4;
        unsigned int rdet_bdl_step : 2;
        unsigned int rdet_ph_step : 2;
        unsigned int rdet_open_jstep : 4;
        unsigned int tdvalid_wt : 5;
        unsigned int tdvalid_pol_en : 1;
        unsigned int wldqsen : 1;
        unsigned int trainctl_nopostpre : 1;
        unsigned int wdet_mpc_cnt : 4;
        unsigned int cal_alt_num : 3;
        unsigned int dmyrd_onetime : 3;
        unsigned int reserved : 1;
        unsigned int wdert_bdl_mode : 1;
    } reg;
} SOC_DDR_PACK_TRAINCTRL5_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL5_dlym_dummyrd_cnt_START (0)
#define SOC_DDR_PACK_TRAINCTRL5_dlym_dummyrd_cnt_END (3)
#define SOC_DDR_PACK_TRAINCTRL5_rdet_bdl_step_START (4)
#define SOC_DDR_PACK_TRAINCTRL5_rdet_bdl_step_END (5)
#define SOC_DDR_PACK_TRAINCTRL5_rdet_ph_step_START (6)
#define SOC_DDR_PACK_TRAINCTRL5_rdet_ph_step_END (7)
#define SOC_DDR_PACK_TRAINCTRL5_rdet_open_jstep_START (8)
#define SOC_DDR_PACK_TRAINCTRL5_rdet_open_jstep_END (11)
#define SOC_DDR_PACK_TRAINCTRL5_tdvalid_wt_START (12)
#define SOC_DDR_PACK_TRAINCTRL5_tdvalid_wt_END (16)
#define SOC_DDR_PACK_TRAINCTRL5_tdvalid_pol_en_START (17)
#define SOC_DDR_PACK_TRAINCTRL5_tdvalid_pol_en_END (17)
#define SOC_DDR_PACK_TRAINCTRL5_wldqsen_START (18)
#define SOC_DDR_PACK_TRAINCTRL5_wldqsen_END (18)
#define SOC_DDR_PACK_TRAINCTRL5_trainctl_nopostpre_START (19)
#define SOC_DDR_PACK_TRAINCTRL5_trainctl_nopostpre_END (19)
#define SOC_DDR_PACK_TRAINCTRL5_wdet_mpc_cnt_START (20)
#define SOC_DDR_PACK_TRAINCTRL5_wdet_mpc_cnt_END (23)
#define SOC_DDR_PACK_TRAINCTRL5_cal_alt_num_START (24)
#define SOC_DDR_PACK_TRAINCTRL5_cal_alt_num_END (26)
#define SOC_DDR_PACK_TRAINCTRL5_dmyrd_onetime_START (27)
#define SOC_DDR_PACK_TRAINCTRL5_dmyrd_onetime_END (29)
#define SOC_DDR_PACK_TRAINCTRL5_wdert_bdl_mode_START (31)
#define SOC_DDR_PACK_TRAINCTRL5_wdert_bdl_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mr0_cl_m2 : 4;
        unsigned int dlymeas_upd_rdqsbdl_en : 1;
        unsigned int wlsyncrank_en : 1;
        unsigned int gt_rdbi_handle_en : 1;
        unsigned int gdsrt_mrank_en : 1;
        unsigned int cfg_rl_rdbi_off : 4;
        unsigned int fast_dqsgsl_mrgn : 8;
        unsigned int dlymeas_update_async_mode : 1;
        unsigned int wl_wren_one_rank_handle : 1;
        unsigned int wdqsX_just_one_rank : 1;
        unsigned int dynatrk_rdqsg_ph_step_sel : 1;
        unsigned int dynatrk_rdqsg_cnt_clr_en : 1;
        unsigned int dynatrk_rdqs_cnt_clr_en : 1;
        unsigned int fast_gt_step_sel : 1;
        unsigned int wl_wdqdmbdl_dis : 1;
        unsigned int gds_2rank_en : 1;
        unsigned int trainctl_gtrnowait : 1;
        unsigned int rpt_nomrs : 1;
        unsigned int info_full_tccd_sel : 1;
    } reg;
} SOC_DDR_PACK_TRAINCTRL7_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL7_mr0_cl_m2_START (0)
#define SOC_DDR_PACK_TRAINCTRL7_mr0_cl_m2_END (3)
#define SOC_DDR_PACK_TRAINCTRL7_dlymeas_upd_rdqsbdl_en_START (4)
#define SOC_DDR_PACK_TRAINCTRL7_dlymeas_upd_rdqsbdl_en_END (4)
#define SOC_DDR_PACK_TRAINCTRL7_wlsyncrank_en_START (5)
#define SOC_DDR_PACK_TRAINCTRL7_wlsyncrank_en_END (5)
#define SOC_DDR_PACK_TRAINCTRL7_gt_rdbi_handle_en_START (6)
#define SOC_DDR_PACK_TRAINCTRL7_gt_rdbi_handle_en_END (6)
#define SOC_DDR_PACK_TRAINCTRL7_gdsrt_mrank_en_START (7)
#define SOC_DDR_PACK_TRAINCTRL7_gdsrt_mrank_en_END (7)
#define SOC_DDR_PACK_TRAINCTRL7_cfg_rl_rdbi_off_START (8)
#define SOC_DDR_PACK_TRAINCTRL7_cfg_rl_rdbi_off_END (11)
#define SOC_DDR_PACK_TRAINCTRL7_fast_dqsgsl_mrgn_START (12)
#define SOC_DDR_PACK_TRAINCTRL7_fast_dqsgsl_mrgn_END (19)
#define SOC_DDR_PACK_TRAINCTRL7_dlymeas_update_async_mode_START (20)
#define SOC_DDR_PACK_TRAINCTRL7_dlymeas_update_async_mode_END (20)
#define SOC_DDR_PACK_TRAINCTRL7_wl_wren_one_rank_handle_START (21)
#define SOC_DDR_PACK_TRAINCTRL7_wl_wren_one_rank_handle_END (21)
#define SOC_DDR_PACK_TRAINCTRL7_wdqsX_just_one_rank_START (22)
#define SOC_DDR_PACK_TRAINCTRL7_wdqsX_just_one_rank_END (22)
#define SOC_DDR_PACK_TRAINCTRL7_dynatrk_rdqsg_ph_step_sel_START (23)
#define SOC_DDR_PACK_TRAINCTRL7_dynatrk_rdqsg_ph_step_sel_END (23)
#define SOC_DDR_PACK_TRAINCTRL7_dynatrk_rdqsg_cnt_clr_en_START (24)
#define SOC_DDR_PACK_TRAINCTRL7_dynatrk_rdqsg_cnt_clr_en_END (24)
#define SOC_DDR_PACK_TRAINCTRL7_dynatrk_rdqs_cnt_clr_en_START (25)
#define SOC_DDR_PACK_TRAINCTRL7_dynatrk_rdqs_cnt_clr_en_END (25)
#define SOC_DDR_PACK_TRAINCTRL7_fast_gt_step_sel_START (26)
#define SOC_DDR_PACK_TRAINCTRL7_fast_gt_step_sel_END (26)
#define SOC_DDR_PACK_TRAINCTRL7_wl_wdqdmbdl_dis_START (27)
#define SOC_DDR_PACK_TRAINCTRL7_wl_wdqdmbdl_dis_END (27)
#define SOC_DDR_PACK_TRAINCTRL7_gds_2rank_en_START (28)
#define SOC_DDR_PACK_TRAINCTRL7_gds_2rank_en_END (28)
#define SOC_DDR_PACK_TRAINCTRL7_trainctl_gtrnowait_START (29)
#define SOC_DDR_PACK_TRAINCTRL7_trainctl_gtrnowait_END (29)
#define SOC_DDR_PACK_TRAINCTRL7_rpt_nomrs_START (30)
#define SOC_DDR_PACK_TRAINCTRL7_rpt_nomrs_END (30)
#define SOC_DDR_PACK_TRAINCTRL7_info_full_tccd_sel_START (31)
#define SOC_DDR_PACK_TRAINCTRL7_info_full_tccd_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd1tph_right : 8;
        unsigned int cmd1tph_left : 8;
        unsigned int cmd1tph : 8;
        unsigned int cmd1tph_a_ori : 8;
    } reg;
} SOC_DDR_PACK_ACCMDBDL0_UNION;
#endif
#define SOC_DDR_PACK_ACCMDBDL0_cmd1tph_right_START (0)
#define SOC_DDR_PACK_ACCMDBDL0_cmd1tph_right_END (7)
#define SOC_DDR_PACK_ACCMDBDL0_cmd1tph_left_START (8)
#define SOC_DDR_PACK_ACCMDBDL0_cmd1tph_left_END (15)
#define SOC_DDR_PACK_ACCMDBDL0_cmd1tph_START (16)
#define SOC_DDR_PACK_ACCMDBDL0_cmd1tph_END (23)
#define SOC_DDR_PACK_ACCMDBDL0_cmd1tph_a_ori_START (24)
#define SOC_DDR_PACK_ACCMDBDL0_cmd1tph_a_ori_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int zcal_noffset_en : 1;
        unsigned int zcal_poffset_en : 1;
        unsigned int zcal_nadd : 1;
        unsigned int zcal_padd : 1;
        unsigned int zlat_noffset_en : 1;
        unsigned int zlat_poffset_en : 1;
        unsigned int zlat_nadd : 1;
        unsigned int zlat_padd : 1;
        unsigned int zcal_noffset : 4;
        unsigned int zcal_poffset : 4;
        unsigned int zlat_noffset : 4;
        unsigned int zlat_poffset : 4;
        unsigned int zcal_regout_sel : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_PACK_IMPOFFSET_UNION;
#endif
#define SOC_DDR_PACK_IMPOFFSET_zcal_noffset_en_START (0)
#define SOC_DDR_PACK_IMPOFFSET_zcal_noffset_en_END (0)
#define SOC_DDR_PACK_IMPOFFSET_zcal_poffset_en_START (1)
#define SOC_DDR_PACK_IMPOFFSET_zcal_poffset_en_END (1)
#define SOC_DDR_PACK_IMPOFFSET_zcal_nadd_START (2)
#define SOC_DDR_PACK_IMPOFFSET_zcal_nadd_END (2)
#define SOC_DDR_PACK_IMPOFFSET_zcal_padd_START (3)
#define SOC_DDR_PACK_IMPOFFSET_zcal_padd_END (3)
#define SOC_DDR_PACK_IMPOFFSET_zlat_noffset_en_START (4)
#define SOC_DDR_PACK_IMPOFFSET_zlat_noffset_en_END (4)
#define SOC_DDR_PACK_IMPOFFSET_zlat_poffset_en_START (5)
#define SOC_DDR_PACK_IMPOFFSET_zlat_poffset_en_END (5)
#define SOC_DDR_PACK_IMPOFFSET_zlat_nadd_START (6)
#define SOC_DDR_PACK_IMPOFFSET_zlat_nadd_END (6)
#define SOC_DDR_PACK_IMPOFFSET_zlat_padd_START (7)
#define SOC_DDR_PACK_IMPOFFSET_zlat_padd_END (7)
#define SOC_DDR_PACK_IMPOFFSET_zcal_noffset_START (8)
#define SOC_DDR_PACK_IMPOFFSET_zcal_noffset_END (11)
#define SOC_DDR_PACK_IMPOFFSET_zcal_poffset_START (12)
#define SOC_DDR_PACK_IMPOFFSET_zcal_poffset_END (15)
#define SOC_DDR_PACK_IMPOFFSET_zlat_noffset_START (16)
#define SOC_DDR_PACK_IMPOFFSET_zlat_noffset_END (19)
#define SOC_DDR_PACK_IMPOFFSET_zlat_poffset_START (20)
#define SOC_DDR_PACK_IMPOFFSET_zlat_poffset_END (23)
#define SOC_DDR_PACK_IMPOFFSET_zcal_regout_sel_START (24)
#define SOC_DDR_PACK_IMPOFFSET_zcal_regout_sel_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_msp430_ctrl0 : 32;
    } reg;
} SOC_DDR_PACK_ACCMDBDL5_UNION;
#endif
#define SOC_DDR_PACK_ACCMDBDL5_reg_msp430_ctrl0_START (0)
#define SOC_DDR_PACK_ACCMDBDL5_reg_msp430_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int we_bdl : 10;
        unsigned int reserved_0: 6;
        unsigned int cas_bdl : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_DDR_PACK_ACCMDBDL6_UNION;
#endif
#define SOC_DDR_PACK_ACCMDBDL6_we_bdl_START (0)
#define SOC_DDR_PACK_ACCMDBDL6_we_bdl_END (9)
#define SOC_DDR_PACK_ACCMDBDL6_cas_bdl_START (16)
#define SOC_DDR_PACK_ACCMDBDL6_cas_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ras_bdl : 10;
        unsigned int reserved_0 : 6;
        unsigned int resetn_bdl : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_PACK_ACCMDBDL7_UNION;
#endif
#define SOC_DDR_PACK_ACCMDBDL7_ras_bdl_START (0)
#define SOC_DDR_PACK_ACCMDBDL7_ras_bdl_END (9)
#define SOC_DDR_PACK_ACCMDBDL7_resetn_bdl_START (16)
#define SOC_DDR_PACK_ACCMDBDL7_resetn_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ba0_bdl : 10;
        unsigned int reserved_0: 6;
        unsigned int ba1_bdl : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_DDR_PACK_ACADDRBDL8_UNION;
#endif
#define SOC_DDR_PACK_ACADDRBDL8_ba0_bdl_START (0)
#define SOC_DDR_PACK_ACADDRBDL8_ba0_bdl_END (9)
#define SOC_DDR_PACK_ACADDRBDL8_ba1_bdl_START (16)
#define SOC_DDR_PACK_ACADDRBDL8_ba1_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ba2_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACADDRBDL9_UNION;
#endif
#define SOC_DDR_PACK_ACADDRBDL9_ba2_bdl_START (0)
#define SOC_DDR_PACK_ACADDRBDL9_ba2_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_lpbk_data_sl : 2;
        unsigned int cfg_prbs_mode : 1;
        unsigned int ac_rdffsel_ext : 1;
        unsigned int reserved : 26;
        unsigned int aclpbk_cmdlp_mode : 1;
        unsigned int acbst_odd_main_msk : 1;
    } reg;
} SOC_DDR_PACK_ACBISTCTRL2_UNION;
#endif
#define SOC_DDR_PACK_ACBISTCTRL2_ac_lpbk_data_sl_START (0)
#define SOC_DDR_PACK_ACBISTCTRL2_ac_lpbk_data_sl_END (1)
#define SOC_DDR_PACK_ACBISTCTRL2_cfg_prbs_mode_START (2)
#define SOC_DDR_PACK_ACBISTCTRL2_cfg_prbs_mode_END (2)
#define SOC_DDR_PACK_ACBISTCTRL2_ac_rdffsel_ext_START (3)
#define SOC_DDR_PACK_ACBISTCTRL2_ac_rdffsel_ext_END (3)
#define SOC_DDR_PACK_ACBISTCTRL2_aclpbk_cmdlp_mode_START (30)
#define SOC_DDR_PACK_ACBISTCTRL2_aclpbk_cmdlp_mode_END (30)
#define SOC_DDR_PACK_ACBISTCTRL2_acbst_odd_main_msk_START (31)
#define SOC_DDR_PACK_ACBISTCTRL2_acbst_odd_main_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int jtmt_period : 6;
        unsigned int jtmt_err : 1;
        unsigned int jtmt_loop_en : 1;
        unsigned int jtmt_period_limit : 6;
        unsigned int jtmt_period_latch : 1;
        unsigned int reserved_0 : 1;
        unsigned int cfg_pll_test_mode : 8;
        unsigned int jtmt_clkbdl_ub : 5;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DDR_PACK_PLLJTMT_UNION;
#endif
#define SOC_DDR_PACK_PLLJTMT_jtmt_period_START (0)
#define SOC_DDR_PACK_PLLJTMT_jtmt_period_END (5)
#define SOC_DDR_PACK_PLLJTMT_jtmt_err_START (6)
#define SOC_DDR_PACK_PLLJTMT_jtmt_err_END (6)
#define SOC_DDR_PACK_PLLJTMT_jtmt_loop_en_START (7)
#define SOC_DDR_PACK_PLLJTMT_jtmt_loop_en_END (7)
#define SOC_DDR_PACK_PLLJTMT_jtmt_period_limit_START (8)
#define SOC_DDR_PACK_PLLJTMT_jtmt_period_limit_END (13)
#define SOC_DDR_PACK_PLLJTMT_jtmt_period_latch_START (14)
#define SOC_DDR_PACK_PLLJTMT_jtmt_period_latch_END (14)
#define SOC_DDR_PACK_PLLJTMT_cfg_pll_test_mode_START (16)
#define SOC_DDR_PACK_PLLJTMT_cfg_pll_test_mode_END (23)
#define SOC_DDR_PACK_PLLJTMT_jtmt_clkbdl_ub_START (24)
#define SOC_DDR_PACK_PLLJTMT_jtmt_clkbdl_ub_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_vddq_cal_mode : 3;
        unsigned int dx_vddq_cal_mode : 3;
        unsigned int sw_zq_mode : 3;
        unsigned int sw_ac_zq_sel : 1;
        unsigned int sw_zq_dx_out_en : 1;
        unsigned int sw_zq_ac_out_en : 1;
        unsigned int sw_zq_select : 1;
        unsigned int sw_zq_enable : 1;
        unsigned int sw_zq_reset : 1;
        unsigned int sw_zqcal_en : 1;
        unsigned int zcal_sel : 1;
        unsigned int zcal_tie_lsb : 1;
        unsigned int zcal_ndrv_regsel : 1;
        unsigned int zcal_pdrv_regsel : 1;
        unsigned int acctl_ndrv_regsel : 1;
        unsigned int acctl_pdrv_regsel : 1;
        unsigned int ac_vddq_cal_en : 1;
        unsigned int cfg_pdrv_msb_dummy : 1;
        unsigned int zcal_en_count : 4;
        unsigned int cfg_tzcomp_prep : 3;
        unsigned int zcomp_result : 1;
    } reg;
} SOC_DDR_PACK_IMP_CTRL1_UNION;
#endif
#define SOC_DDR_PACK_IMP_CTRL1_ac_vddq_cal_mode_START (0)
#define SOC_DDR_PACK_IMP_CTRL1_ac_vddq_cal_mode_END (2)
#define SOC_DDR_PACK_IMP_CTRL1_dx_vddq_cal_mode_START (3)
#define SOC_DDR_PACK_IMP_CTRL1_dx_vddq_cal_mode_END (5)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_mode_START (6)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_mode_END (8)
#define SOC_DDR_PACK_IMP_CTRL1_sw_ac_zq_sel_START (9)
#define SOC_DDR_PACK_IMP_CTRL1_sw_ac_zq_sel_END (9)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_dx_out_en_START (10)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_dx_out_en_END (10)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_ac_out_en_START (11)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_ac_out_en_END (11)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_select_START (12)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_select_END (12)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_enable_START (13)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_enable_END (13)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_reset_START (14)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zq_reset_END (14)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zqcal_en_START (15)
#define SOC_DDR_PACK_IMP_CTRL1_sw_zqcal_en_END (15)
#define SOC_DDR_PACK_IMP_CTRL1_zcal_sel_START (16)
#define SOC_DDR_PACK_IMP_CTRL1_zcal_sel_END (16)
#define SOC_DDR_PACK_IMP_CTRL1_zcal_tie_lsb_START (17)
#define SOC_DDR_PACK_IMP_CTRL1_zcal_tie_lsb_END (17)
#define SOC_DDR_PACK_IMP_CTRL1_zcal_ndrv_regsel_START (18)
#define SOC_DDR_PACK_IMP_CTRL1_zcal_ndrv_regsel_END (18)
#define SOC_DDR_PACK_IMP_CTRL1_zcal_pdrv_regsel_START (19)
#define SOC_DDR_PACK_IMP_CTRL1_zcal_pdrv_regsel_END (19)
#define SOC_DDR_PACK_IMP_CTRL1_acctl_ndrv_regsel_START (20)
#define SOC_DDR_PACK_IMP_CTRL1_acctl_ndrv_regsel_END (20)
#define SOC_DDR_PACK_IMP_CTRL1_acctl_pdrv_regsel_START (21)
#define SOC_DDR_PACK_IMP_CTRL1_acctl_pdrv_regsel_END (21)
#define SOC_DDR_PACK_IMP_CTRL1_ac_vddq_cal_en_START (22)
#define SOC_DDR_PACK_IMP_CTRL1_ac_vddq_cal_en_END (22)
#define SOC_DDR_PACK_IMP_CTRL1_cfg_pdrv_msb_dummy_START (23)
#define SOC_DDR_PACK_IMP_CTRL1_cfg_pdrv_msb_dummy_END (23)
#define SOC_DDR_PACK_IMP_CTRL1_zcal_en_count_START (24)
#define SOC_DDR_PACK_IMP_CTRL1_zcal_en_count_END (27)
#define SOC_DDR_PACK_IMP_CTRL1_cfg_tzcomp_prep_START (28)
#define SOC_DDR_PACK_IMP_CTRL1_cfg_tzcomp_prep_END (30)
#define SOC_DDR_PACK_IMP_CTRL1_zcomp_result_START (31)
#define SOC_DDR_PACK_IMP_CTRL1_zcomp_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acctl_ndrv_cal : 7;
        unsigned int reserved_0 : 1;
        unsigned int acctl_pdrv_cal : 8;
        unsigned int acctl_ndrv_latch : 6;
        unsigned int reserved_1 : 2;
        unsigned int acctl_pdrv_latch : 7;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_DDR_PACK_IMP_STATUS1_UNION;
#endif
#define SOC_DDR_PACK_IMP_STATUS1_acctl_ndrv_cal_START (0)
#define SOC_DDR_PACK_IMP_STATUS1_acctl_ndrv_cal_END (6)
#define SOC_DDR_PACK_IMP_STATUS1_acctl_pdrv_cal_START (8)
#define SOC_DDR_PACK_IMP_STATUS1_acctl_pdrv_cal_END (15)
#define SOC_DDR_PACK_IMP_STATUS1_acctl_ndrv_latch_START (16)
#define SOC_DDR_PACK_IMP_STATUS1_acctl_ndrv_latch_END (21)
#define SOC_DDR_PACK_IMP_STATUS1_acctl_pdrv_latch_START (24)
#define SOC_DDR_PACK_IMP_STATUS1_acctl_pdrv_latch_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ioctl_dx_ndrv_out : 6;
        unsigned int reserved_0 : 2;
        unsigned int ioctl_dx_pdrv_out : 7;
        unsigned int reserved_1 : 1;
        unsigned int ioctl_ac_ndrv_out : 6;
        unsigned int reserved_2 : 2;
        unsigned int ioctl_ac_pdrv_out : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_DDR_PACK_IMP_OUT_UNION;
#endif
#define SOC_DDR_PACK_IMP_OUT_ioctl_dx_ndrv_out_START (0)
#define SOC_DDR_PACK_IMP_OUT_ioctl_dx_ndrv_out_END (5)
#define SOC_DDR_PACK_IMP_OUT_ioctl_dx_pdrv_out_START (8)
#define SOC_DDR_PACK_IMP_OUT_ioctl_dx_pdrv_out_END (14)
#define SOC_DDR_PACK_IMP_OUT_ioctl_ac_ndrv_out_START (16)
#define SOC_DDR_PACK_IMP_OUT_ioctl_ac_ndrv_out_END (21)
#define SOC_DDR_PACK_IMP_OUT_ioctl_ac_pdrv_out_START (24)
#define SOC_DDR_PACK_IMP_OUT_ioctl_ac_pdrv_out_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rpat_cnt_num : 6;
        unsigned int fast_gt_autorank : 1;
        unsigned int fast_gds_autorank : 1;
        unsigned int wpat_cnt_num : 6;
        unsigned int fast_gds_max_ranks : 1;
        unsigned int cfg_wecct_en : 1;
        unsigned int rpat_cnt_num_open : 6;
        unsigned int fast_gds_ingt_mode : 1;
        unsigned int fast_gt_smart_mode : 1;
        unsigned int wpat_cnt_num_open : 6;
        unsigned int rwtest_read_en : 1;
        unsigned int rwtest_write_en : 1;
    } reg;
} SOC_DDR_PACK_TRAINCTRL11_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL11_rpat_cnt_num_START (0)
#define SOC_DDR_PACK_TRAINCTRL11_rpat_cnt_num_END (5)
#define SOC_DDR_PACK_TRAINCTRL11_fast_gt_autorank_START (6)
#define SOC_DDR_PACK_TRAINCTRL11_fast_gt_autorank_END (6)
#define SOC_DDR_PACK_TRAINCTRL11_fast_gds_autorank_START (7)
#define SOC_DDR_PACK_TRAINCTRL11_fast_gds_autorank_END (7)
#define SOC_DDR_PACK_TRAINCTRL11_wpat_cnt_num_START (8)
#define SOC_DDR_PACK_TRAINCTRL11_wpat_cnt_num_END (13)
#define SOC_DDR_PACK_TRAINCTRL11_fast_gds_max_ranks_START (14)
#define SOC_DDR_PACK_TRAINCTRL11_fast_gds_max_ranks_END (14)
#define SOC_DDR_PACK_TRAINCTRL11_cfg_wecct_en_START (15)
#define SOC_DDR_PACK_TRAINCTRL11_cfg_wecct_en_END (15)
#define SOC_DDR_PACK_TRAINCTRL11_rpat_cnt_num_open_START (16)
#define SOC_DDR_PACK_TRAINCTRL11_rpat_cnt_num_open_END (21)
#define SOC_DDR_PACK_TRAINCTRL11_fast_gds_ingt_mode_START (22)
#define SOC_DDR_PACK_TRAINCTRL11_fast_gds_ingt_mode_END (22)
#define SOC_DDR_PACK_TRAINCTRL11_fast_gt_smart_mode_START (23)
#define SOC_DDR_PACK_TRAINCTRL11_fast_gt_smart_mode_END (23)
#define SOC_DDR_PACK_TRAINCTRL11_wpat_cnt_num_open_START (24)
#define SOC_DDR_PACK_TRAINCTRL11_wpat_cnt_num_open_END (29)
#define SOC_DDR_PACK_TRAINCTRL11_rwtest_read_en_START (30)
#define SOC_DDR_PACK_TRAINCTRL11_rwtest_read_en_END (30)
#define SOC_DDR_PACK_TRAINCTRL11_rwtest_write_en_START (31)
#define SOC_DDR_PACK_TRAINCTRL11_rwtest_write_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_gds_result : 32;
    } reg;
} SOC_DDR_PACK_FASTGDSRESULT0_UNION;
#endif
#define SOC_DDR_PACK_FASTGDSRESULT0_fast_gds_result_START (0)
#define SOC_DDR_PACK_FASTGDSRESULT0_fast_gds_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_gds_result : 32;
    } reg;
} SOC_DDR_PACK_FASTGDSRESULT1_UNION;
#endif
#define SOC_DDR_PACK_FASTGDSRESULT1_fast_gds_result_START (0)
#define SOC_DDR_PACK_FASTGDSRESULT1_fast_gds_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_gt_decgress : 8;
        unsigned int fast_gt_incgress : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PACK_FASTGTRESULT_UNION;
#endif
#define SOC_DDR_PACK_FASTGTRESULT_fast_gt_decgress_START (0)
#define SOC_DDR_PACK_FASTGTRESULT_fast_gt_decgress_END (7)
#define SOC_DDR_PACK_FASTGTRESULT_fast_gt_incgress_START (8)
#define SOC_DDR_PACK_FASTGTRESULT_fast_gt_incgress_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_rdata : 32;
    } reg;
} SOC_DDR_PACK_TRKDBG_UNION;
#endif
#define SOC_DDR_PACK_TRKDBG_trkdbg_rdata_START (0)
#define SOC_DDR_PACK_TRKDBG_trkdbg_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int det_err_state : 8;
        unsigned int cat_err_state : 6;
        unsigned int status_lowpri_peek : 1;
        unsigned int err_state_peek : 1;
        unsigned int cdgc_cmpres : 9;
        unsigned int packcnt_clr : 1;
        unsigned int dxndqnlb_sel : 2;
        unsigned int cdgc_cmpres_sel : 3;
        unsigned int bound_info_clr_en : 1;
    } reg;
} SOC_DDR_PACK_PACKDEBUG_UNION;
#endif
#define SOC_DDR_PACK_PACKDEBUG_det_err_state_START (0)
#define SOC_DDR_PACK_PACKDEBUG_det_err_state_END (7)
#define SOC_DDR_PACK_PACKDEBUG_cat_err_state_START (8)
#define SOC_DDR_PACK_PACKDEBUG_cat_err_state_END (13)
#define SOC_DDR_PACK_PACKDEBUG_status_lowpri_peek_START (14)
#define SOC_DDR_PACK_PACKDEBUG_status_lowpri_peek_END (14)
#define SOC_DDR_PACK_PACKDEBUG_err_state_peek_START (15)
#define SOC_DDR_PACK_PACKDEBUG_err_state_peek_END (15)
#define SOC_DDR_PACK_PACKDEBUG_cdgc_cmpres_START (16)
#define SOC_DDR_PACK_PACKDEBUG_cdgc_cmpres_END (24)
#define SOC_DDR_PACK_PACKDEBUG_packcnt_clr_START (25)
#define SOC_DDR_PACK_PACKDEBUG_packcnt_clr_END (25)
#define SOC_DDR_PACK_PACKDEBUG_dxndqnlb_sel_START (26)
#define SOC_DDR_PACK_PACKDEBUG_dxndqnlb_sel_END (27)
#define SOC_DDR_PACK_PACKDEBUG_cdgc_cmpres_sel_START (28)
#define SOC_DDR_PACK_PACKDEBUG_cdgc_cmpres_sel_END (30)
#define SOC_DDR_PACK_PACKDEBUG_bound_info_clr_en_START (31)
#define SOC_DDR_PACK_PACKDEBUG_bound_info_clr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_wdet_en : 1;
        unsigned int ph_mask_en : 1;
        unsigned int wdet_lb_ctdone_stop : 1;
        unsigned int rdet_lb_ctdone_stop : 1;
        unsigned int wdet_byp_mode : 1;
        unsigned int non_odt_mode_en : 1;
        unsigned int trkdbg_ro_sel : 4;
        unsigned int dyn_track_trans_en : 1;
        unsigned int mc_eff_blk_dis : 1;
        unsigned int ac_rsv_control_13_12 : 2;
        unsigned int pack_mc_sel_dis : 1;
        unsigned int ac_rsv_control_15 : 1;
        unsigned int wdet_ave_comp_en : 1;
        unsigned int wdet_rb2nd_fine_en : 1;
        unsigned int apb_err_type : 1;
        unsigned int wopen_ovflow_handle : 1;
        unsigned int lp4_mrw_sp_dec_en : 1;
        unsigned int acctl_drv_sel : 1;
        unsigned int cat_eyeopen_fclr_en : 1;
        unsigned int wl_mode_tx_gated_en : 1;
        unsigned int non_odt_ndrv : 6;
        unsigned int phyupdtimer_clr_en : 1;
        unsigned int aclpbkmode_exd_en : 1;
    } reg;
} SOC_DDR_PACK_ACPHYRSVDC_UNION;
#endif
#define SOC_DDR_PACK_ACPHYRSVDC_fast_wdet_en_START (0)
#define SOC_DDR_PACK_ACPHYRSVDC_fast_wdet_en_END (0)
#define SOC_DDR_PACK_ACPHYRSVDC_ph_mask_en_START (1)
#define SOC_DDR_PACK_ACPHYRSVDC_ph_mask_en_END (1)
#define SOC_DDR_PACK_ACPHYRSVDC_wdet_lb_ctdone_stop_START (2)
#define SOC_DDR_PACK_ACPHYRSVDC_wdet_lb_ctdone_stop_END (2)
#define SOC_DDR_PACK_ACPHYRSVDC_rdet_lb_ctdone_stop_START (3)
#define SOC_DDR_PACK_ACPHYRSVDC_rdet_lb_ctdone_stop_END (3)
#define SOC_DDR_PACK_ACPHYRSVDC_wdet_byp_mode_START (4)
#define SOC_DDR_PACK_ACPHYRSVDC_wdet_byp_mode_END (4)
#define SOC_DDR_PACK_ACPHYRSVDC_non_odt_mode_en_START (5)
#define SOC_DDR_PACK_ACPHYRSVDC_non_odt_mode_en_END (5)
#define SOC_DDR_PACK_ACPHYRSVDC_trkdbg_ro_sel_START (6)
#define SOC_DDR_PACK_ACPHYRSVDC_trkdbg_ro_sel_END (9)
#define SOC_DDR_PACK_ACPHYRSVDC_dyn_track_trans_en_START (10)
#define SOC_DDR_PACK_ACPHYRSVDC_dyn_track_trans_en_END (10)
#define SOC_DDR_PACK_ACPHYRSVDC_mc_eff_blk_dis_START (11)
#define SOC_DDR_PACK_ACPHYRSVDC_mc_eff_blk_dis_END (11)
#define SOC_DDR_PACK_ACPHYRSVDC_ac_rsv_control_13_12_START (12)
#define SOC_DDR_PACK_ACPHYRSVDC_ac_rsv_control_13_12_END (13)
#define SOC_DDR_PACK_ACPHYRSVDC_pack_mc_sel_dis_START (14)
#define SOC_DDR_PACK_ACPHYRSVDC_pack_mc_sel_dis_END (14)
#define SOC_DDR_PACK_ACPHYRSVDC_ac_rsv_control_15_START (15)
#define SOC_DDR_PACK_ACPHYRSVDC_ac_rsv_control_15_END (15)
#define SOC_DDR_PACK_ACPHYRSVDC_wdet_ave_comp_en_START (16)
#define SOC_DDR_PACK_ACPHYRSVDC_wdet_ave_comp_en_END (16)
#define SOC_DDR_PACK_ACPHYRSVDC_wdet_rb2nd_fine_en_START (17)
#define SOC_DDR_PACK_ACPHYRSVDC_wdet_rb2nd_fine_en_END (17)
#define SOC_DDR_PACK_ACPHYRSVDC_apb_err_type_START (18)
#define SOC_DDR_PACK_ACPHYRSVDC_apb_err_type_END (18)
#define SOC_DDR_PACK_ACPHYRSVDC_wopen_ovflow_handle_START (19)
#define SOC_DDR_PACK_ACPHYRSVDC_wopen_ovflow_handle_END (19)
#define SOC_DDR_PACK_ACPHYRSVDC_lp4_mrw_sp_dec_en_START (20)
#define SOC_DDR_PACK_ACPHYRSVDC_lp4_mrw_sp_dec_en_END (20)
#define SOC_DDR_PACK_ACPHYRSVDC_acctl_drv_sel_START (21)
#define SOC_DDR_PACK_ACPHYRSVDC_acctl_drv_sel_END (21)
#define SOC_DDR_PACK_ACPHYRSVDC_cat_eyeopen_fclr_en_START (22)
#define SOC_DDR_PACK_ACPHYRSVDC_cat_eyeopen_fclr_en_END (22)
#define SOC_DDR_PACK_ACPHYRSVDC_wl_mode_tx_gated_en_START (23)
#define SOC_DDR_PACK_ACPHYRSVDC_wl_mode_tx_gated_en_END (23)
#define SOC_DDR_PACK_ACPHYRSVDC_non_odt_ndrv_START (24)
#define SOC_DDR_PACK_ACPHYRSVDC_non_odt_ndrv_END (29)
#define SOC_DDR_PACK_ACPHYRSVDC_phyupdtimer_clr_en_START (30)
#define SOC_DDR_PACK_ACPHYRSVDC_phyupdtimer_clr_en_END (30)
#define SOC_DDR_PACK_ACPHYRSVDC_aclpbkmode_exd_en_START (31)
#define SOC_DDR_PACK_ACPHYRSVDC_aclpbkmode_exd_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_msp430_ctrl1 : 32;
    } reg;
} SOC_DDR_PACK_ACPHYRSVDS_UNION;
#endif
#define SOC_DDR_PACK_ACPHYRSVDS_reg_msp430_ctrl1_START (0)
#define SOC_DDR_PACK_ACPHYRSVDS_reg_msp430_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_mrr_data_selected : 16;
        unsigned int reserved_0 : 8;
        unsigned int sw_mrr_data_byte_sel : 3;
        unsigned int reserved_1 : 1;
        unsigned int sw_mrr_data_burst_sel : 2;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_DDR_PACK_SWMRRDATA_UNION;
#endif
#define SOC_DDR_PACK_SWMRRDATA_sw_mrr_data_selected_START (0)
#define SOC_DDR_PACK_SWMRRDATA_sw_mrr_data_selected_END (15)
#define SOC_DDR_PACK_SWMRRDATA_sw_mrr_data_byte_sel_START (24)
#define SOC_DDR_PACK_SWMRRDATA_sw_mrr_data_byte_sel_END (26)
#define SOC_DDR_PACK_SWMRRDATA_sw_mrr_data_burst_sel_START (28)
#define SOC_DDR_PACK_SWMRRDATA_sw_mrr_data_burst_sel_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tWCKENL_RD : 8;
        unsigned int tWCKENL_WR : 8;
        unsigned int tWCKENL_FS : 8;
        unsigned int reserved : 1;
        unsigned int wckenrkswen_type : 1;
        unsigned int wckenrkswen : 1;
        unsigned int wck_free_run : 1;
        unsigned int ctl_wck_bypass : 1;
        unsigned int wcksync_mode : 1;
        unsigned int wck2ck_ratio2 : 1;
        unsigned int bl32_bubble : 1;
    } reg;
} SOC_DDR_PACK_WCKCTRL0_UNION;
#endif
#define SOC_DDR_PACK_WCKCTRL0_tWCKENL_RD_START (0)
#define SOC_DDR_PACK_WCKCTRL0_tWCKENL_RD_END (7)
#define SOC_DDR_PACK_WCKCTRL0_tWCKENL_WR_START (8)
#define SOC_DDR_PACK_WCKCTRL0_tWCKENL_WR_END (15)
#define SOC_DDR_PACK_WCKCTRL0_tWCKENL_FS_START (16)
#define SOC_DDR_PACK_WCKCTRL0_tWCKENL_FS_END (23)
#define SOC_DDR_PACK_WCKCTRL0_wckenrkswen_type_START (25)
#define SOC_DDR_PACK_WCKCTRL0_wckenrkswen_type_END (25)
#define SOC_DDR_PACK_WCKCTRL0_wckenrkswen_START (26)
#define SOC_DDR_PACK_WCKCTRL0_wckenrkswen_END (26)
#define SOC_DDR_PACK_WCKCTRL0_wck_free_run_START (27)
#define SOC_DDR_PACK_WCKCTRL0_wck_free_run_END (27)
#define SOC_DDR_PACK_WCKCTRL0_ctl_wck_bypass_START (28)
#define SOC_DDR_PACK_WCKCTRL0_ctl_wck_bypass_END (28)
#define SOC_DDR_PACK_WCKCTRL0_wcksync_mode_START (29)
#define SOC_DDR_PACK_WCKCTRL0_wcksync_mode_END (29)
#define SOC_DDR_PACK_WCKCTRL0_wck2ck_ratio2_START (30)
#define SOC_DDR_PACK_WCKCTRL0_wck2ck_ratio2_END (30)
#define SOC_DDR_PACK_WCKCTRL0_bl32_bubble_START (31)
#define SOC_DDR_PACK_WCKCTRL0_bl32_bubble_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tWCKPRE_TG_RD : 8;
        unsigned int tWCKPRE_TG_WR : 8;
        unsigned int tWCKPRE_Static : 8;
        unsigned int tWCKPST_IND : 2;
        unsigned int reserved : 1;
        unsigned int WCK_offset : 5;
    } reg;
} SOC_DDR_PACK_WCKCTRL1_UNION;
#endif
#define SOC_DDR_PACK_WCKCTRL1_tWCKPRE_TG_RD_START (0)
#define SOC_DDR_PACK_WCKCTRL1_tWCKPRE_TG_RD_END (7)
#define SOC_DDR_PACK_WCKCTRL1_tWCKPRE_TG_WR_START (8)
#define SOC_DDR_PACK_WCKCTRL1_tWCKPRE_TG_WR_END (15)
#define SOC_DDR_PACK_WCKCTRL1_tWCKPRE_Static_START (16)
#define SOC_DDR_PACK_WCKCTRL1_tWCKPRE_Static_END (23)
#define SOC_DDR_PACK_WCKCTRL1_tWCKPST_IND_START (24)
#define SOC_DDR_PACK_WCKCTRL1_tWCKPST_IND_END (25)
#define SOC_DDR_PACK_WCKCTRL1_WCK_offset_START (27)
#define SOC_DDR_PACK_WCKCTRL1_WCK_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 15;
        unsigned int gt_trace_busy : 1;
        unsigned int gt_trace_en : 1;
        unsigned int gt_trace_go : 1;
        unsigned int devmode_dbg_ptr : 4;
        unsigned int devmode_dbg_wen : 1;
        unsigned int devmode_rw_switch : 1;
        unsigned int devmode_dir_ptr : 8;
    } reg;
} SOC_DDR_PACK_DEVMODECFG_UNION;
#endif
#define SOC_DDR_PACK_DEVMODECFG_gt_trace_busy_START (15)
#define SOC_DDR_PACK_DEVMODECFG_gt_trace_busy_END (15)
#define SOC_DDR_PACK_DEVMODECFG_gt_trace_en_START (16)
#define SOC_DDR_PACK_DEVMODECFG_gt_trace_en_END (16)
#define SOC_DDR_PACK_DEVMODECFG_gt_trace_go_START (17)
#define SOC_DDR_PACK_DEVMODECFG_gt_trace_go_END (17)
#define SOC_DDR_PACK_DEVMODECFG_devmode_dbg_ptr_START (18)
#define SOC_DDR_PACK_DEVMODECFG_devmode_dbg_ptr_END (21)
#define SOC_DDR_PACK_DEVMODECFG_devmode_dbg_wen_START (22)
#define SOC_DDR_PACK_DEVMODECFG_devmode_dbg_wen_END (22)
#define SOC_DDR_PACK_DEVMODECFG_devmode_rw_switch_START (23)
#define SOC_DDR_PACK_DEVMODECFG_devmode_rw_switch_END (23)
#define SOC_DDR_PACK_DEVMODECFG_devmode_dir_ptr_START (24)
#define SOC_DDR_PACK_DEVMODECFG_devmode_dir_ptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gcken_jtmt : 1;
        unsigned int gcken_phyinit : 1;
        unsigned int gcken_aref : 1;
        unsigned int gcken_reg_sync_upd : 1;
        unsigned int gcken_dly_mng : 1;
        unsigned int gckdis_mc : 1;
        unsigned int gcken_rdaligh : 1;
        unsigned int lp_phy_gcken_ext_cnt : 3;
        unsigned int reserved_0 : 1;
        unsigned int phy_clkg_oe_tsys_dis : 1;
        unsigned int WCKgated_dig_hw_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int devmode_dbg_data : 18;
    } reg;
} SOC_DDR_PACK_LPCTRL3_UNION;
#endif
#define SOC_DDR_PACK_LPCTRL3_gcken_jtmt_START (0)
#define SOC_DDR_PACK_LPCTRL3_gcken_jtmt_END (0)
#define SOC_DDR_PACK_LPCTRL3_gcken_phyinit_START (1)
#define SOC_DDR_PACK_LPCTRL3_gcken_phyinit_END (1)
#define SOC_DDR_PACK_LPCTRL3_gcken_aref_START (2)
#define SOC_DDR_PACK_LPCTRL3_gcken_aref_END (2)
#define SOC_DDR_PACK_LPCTRL3_gcken_reg_sync_upd_START (3)
#define SOC_DDR_PACK_LPCTRL3_gcken_reg_sync_upd_END (3)
#define SOC_DDR_PACK_LPCTRL3_gcken_dly_mng_START (4)
#define SOC_DDR_PACK_LPCTRL3_gcken_dly_mng_END (4)
#define SOC_DDR_PACK_LPCTRL3_gckdis_mc_START (5)
#define SOC_DDR_PACK_LPCTRL3_gckdis_mc_END (5)
#define SOC_DDR_PACK_LPCTRL3_gcken_rdaligh_START (6)
#define SOC_DDR_PACK_LPCTRL3_gcken_rdaligh_END (6)
#define SOC_DDR_PACK_LPCTRL3_lp_phy_gcken_ext_cnt_START (7)
#define SOC_DDR_PACK_LPCTRL3_lp_phy_gcken_ext_cnt_END (9)
#define SOC_DDR_PACK_LPCTRL3_phy_clkg_oe_tsys_dis_START (11)
#define SOC_DDR_PACK_LPCTRL3_phy_clkg_oe_tsys_dis_END (11)
#define SOC_DDR_PACK_LPCTRL3_WCKgated_dig_hw_en_START (12)
#define SOC_DDR_PACK_LPCTRL3_WCKgated_dig_hw_en_END (12)
#define SOC_DDR_PACK_LPCTRL3_devmode_dbg_data_START (14)
#define SOC_DDR_PACK_LPCTRL3_devmode_dbg_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pst_forb_cas_cnt : 3;
        unsigned int reserved_0 : 1;
        unsigned int pre_forb_cas_cnt : 3;
        unsigned int reserved_1 : 1;
        unsigned int cfg_ckdata_tick_sel : 1;
        unsigned int wck_is_sync : 1;
        unsigned int reserved_2 : 2;
        unsigned int bstpatsel_ext_fixdq : 4;
        unsigned int bstpat_ext_csi_1st_sel : 2;
        unsigned int bstpat_ext_crosstalk : 1;
        unsigned int bstpat_ext_walking : 1;
        unsigned int bstpat_ext_csi_2nd_sel : 3;
        unsigned int reserved_3 : 1;
        unsigned int bstpat_ext_period : 2;
        unsigned int reserved_4 : 1;
        unsigned int bstpatsel_ext : 1;
        unsigned int cfg_zqcal_rsv_3rd : 4;
    } reg;
} SOC_DDR_PACK_WCKCTRL2_UNION;
#endif
#define SOC_DDR_PACK_WCKCTRL2_pst_forb_cas_cnt_START (0)
#define SOC_DDR_PACK_WCKCTRL2_pst_forb_cas_cnt_END (2)
#define SOC_DDR_PACK_WCKCTRL2_pre_forb_cas_cnt_START (4)
#define SOC_DDR_PACK_WCKCTRL2_pre_forb_cas_cnt_END (6)
#define SOC_DDR_PACK_WCKCTRL2_cfg_ckdata_tick_sel_START (8)
#define SOC_DDR_PACK_WCKCTRL2_cfg_ckdata_tick_sel_END (8)
#define SOC_DDR_PACK_WCKCTRL2_wck_is_sync_START (9)
#define SOC_DDR_PACK_WCKCTRL2_wck_is_sync_END (9)
#define SOC_DDR_PACK_WCKCTRL2_bstpatsel_ext_fixdq_START (12)
#define SOC_DDR_PACK_WCKCTRL2_bstpatsel_ext_fixdq_END (15)
#define SOC_DDR_PACK_WCKCTRL2_bstpat_ext_csi_1st_sel_START (16)
#define SOC_DDR_PACK_WCKCTRL2_bstpat_ext_csi_1st_sel_END (17)
#define SOC_DDR_PACK_WCKCTRL2_bstpat_ext_crosstalk_START (18)
#define SOC_DDR_PACK_WCKCTRL2_bstpat_ext_crosstalk_END (18)
#define SOC_DDR_PACK_WCKCTRL2_bstpat_ext_walking_START (19)
#define SOC_DDR_PACK_WCKCTRL2_bstpat_ext_walking_END (19)
#define SOC_DDR_PACK_WCKCTRL2_bstpat_ext_csi_2nd_sel_START (20)
#define SOC_DDR_PACK_WCKCTRL2_bstpat_ext_csi_2nd_sel_END (22)
#define SOC_DDR_PACK_WCKCTRL2_bstpat_ext_period_START (24)
#define SOC_DDR_PACK_WCKCTRL2_bstpat_ext_period_END (25)
#define SOC_DDR_PACK_WCKCTRL2_bstpatsel_ext_START (27)
#define SOC_DDR_PACK_WCKCTRL2_bstpatsel_ext_END (27)
#define SOC_DDR_PACK_WCKCTRL2_cfg_zqcal_rsv_3rd_START (28)
#define SOC_DDR_PACK_WCKCTRL2_cfg_zqcal_rsv_3rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addrbdl_a_right : 10;
        unsigned int reserved_0 : 2;
        unsigned int addrbdl_bound_sel : 4;
        unsigned int addrbdl_a_left : 10;
        unsigned int reserved_1 : 5;
        unsigned int cat_ave_comp_flag : 1;
    } reg;
} SOC_DDR_PACK_CATBDLBOUND_UNION;
#endif
#define SOC_DDR_PACK_CATBDLBOUND_addrbdl_a_right_START (0)
#define SOC_DDR_PACK_CATBDLBOUND_addrbdl_a_right_END (9)
#define SOC_DDR_PACK_CATBDLBOUND_addrbdl_bound_sel_START (12)
#define SOC_DDR_PACK_CATBDLBOUND_addrbdl_bound_sel_END (15)
#define SOC_DDR_PACK_CATBDLBOUND_addrbdl_a_left_START (16)
#define SOC_DDR_PACK_CATBDLBOUND_addrbdl_a_left_END (25)
#define SOC_DDR_PACK_CATBDLBOUND_cat_ave_comp_flag_START (31)
#define SOC_DDR_PACK_CATBDLBOUND_cat_ave_comp_flag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cat_swap_index : 4;
        unsigned int reserved_0 : 8;
        unsigned int cfg_enh_exit_mrop : 8;
        unsigned int cfg_enh_entr_mrop : 8;
        unsigned int reserved_1 : 3;
        unsigned int cat_swap_legacy : 1;
    } reg;
} SOC_DDR_PACK_CATSWAPINDEX_UNION;
#endif
#define SOC_DDR_PACK_CATSWAPINDEX_cat_swap_index_START (0)
#define SOC_DDR_PACK_CATSWAPINDEX_cat_swap_index_END (3)
#define SOC_DDR_PACK_CATSWAPINDEX_cfg_enh_exit_mrop_START (12)
#define SOC_DDR_PACK_CATSWAPINDEX_cfg_enh_exit_mrop_END (19)
#define SOC_DDR_PACK_CATSWAPINDEX_cfg_enh_entr_mrop_START (20)
#define SOC_DDR_PACK_CATSWAPINDEX_cfg_enh_entr_mrop_END (27)
#define SOC_DDR_PACK_CATSWAPINDEX_cat_swap_legacy_START (31)
#define SOC_DDR_PACK_CATSWAPINDEX_cat_swap_legacy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cat_swap_sel : 32;
    } reg;
} SOC_DDR_PACK_CATSWAPSEL_UNION;
#endif
#define SOC_DDR_PACK_CATSWAPSEL_cat_swap_sel_START (0)
#define SOC_DDR_PACK_CATSWAPSEL_cat_swap_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcackel : 6;
        unsigned int tcacd_exd : 2;
        unsigned int tcaent : 8;
        unsigned int tcacd : 8;
        unsigned int tcackeh : 6;
        unsigned int tcackel_ext : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_PACK_CATTIMER0_UNION;
#endif
#define SOC_DDR_PACK_CATTIMER0_tcackel_START (0)
#define SOC_DDR_PACK_CATTIMER0_tcackel_END (5)
#define SOC_DDR_PACK_CATTIMER0_tcacd_exd_START (6)
#define SOC_DDR_PACK_CATTIMER0_tcacd_exd_END (7)
#define SOC_DDR_PACK_CATTIMER0_tcaent_START (8)
#define SOC_DDR_PACK_CATTIMER0_tcaent_END (15)
#define SOC_DDR_PACK_CATTIMER0_tcacd_START (16)
#define SOC_DDR_PACK_CATTIMER0_tcacd_END (23)
#define SOC_DDR_PACK_CATTIMER0_tcackeh_START (24)
#define SOC_DDR_PACK_CATTIMER0_tcackeh_END (29)
#define SOC_DDR_PACK_CATTIMER0_tcackel_ext_START (30)
#define SOC_DDR_PACK_CATTIMER0_tcackel_ext_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcaext : 8;
        unsigned int tmrz : 6;
        unsigned int reserved_0: 2;
        unsigned int tadr : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_DDR_PACK_CATTIMER1_UNION;
#endif
#define SOC_DDR_PACK_CATTIMER1_tcaext_START (0)
#define SOC_DDR_PACK_CATTIMER1_tcaext_END (7)
#define SOC_DDR_PACK_CATTIMER1_tmrz_START (8)
#define SOC_DDR_PACK_CATTIMER1_tmrz_END (13)
#define SOC_DDR_PACK_CATTIMER1_tadr_START (16)
#define SOC_DDR_PACK_CATTIMER1_tadr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ca_samp_num_bdl : 8;
        unsigned int ca_samp_num_ph : 8;
        unsigned int sw_cat_eyet : 1;
        unsigned int cat_openeye_en : 1;
        unsigned int cat_cat_phydq_sel : 1;
        unsigned int cat_restore_en : 1;
        unsigned int cat_ave_comp_en : 1;
        unsigned int cat_rb2nd_fine_en : 1;
        unsigned int sw_cst_mode : 1;
        unsigned int reserved : 1;
        unsigned int sw_cat_mrw42 : 1;
        unsigned int sw_cat_mrw48 : 1;
        unsigned int sw_cat_mrw41 : 1;
        unsigned int sw_cat_strobe : 1;
        unsigned int sw_cat_cke_high : 1;
        unsigned int sw_cat_cke_low : 1;
        unsigned int sw_cat_dqvalid : 1;
        unsigned int sw_cat_en : 1;
    } reg;
} SOC_DDR_PACK_CATCONFIG_UNION;
#endif
#define SOC_DDR_PACK_CATCONFIG_ca_samp_num_bdl_START (0)
#define SOC_DDR_PACK_CATCONFIG_ca_samp_num_bdl_END (7)
#define SOC_DDR_PACK_CATCONFIG_ca_samp_num_ph_START (8)
#define SOC_DDR_PACK_CATCONFIG_ca_samp_num_ph_END (15)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_eyet_START (16)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_eyet_END (16)
#define SOC_DDR_PACK_CATCONFIG_cat_openeye_en_START (17)
#define SOC_DDR_PACK_CATCONFIG_cat_openeye_en_END (17)
#define SOC_DDR_PACK_CATCONFIG_cat_cat_phydq_sel_START (18)
#define SOC_DDR_PACK_CATCONFIG_cat_cat_phydq_sel_END (18)
#define SOC_DDR_PACK_CATCONFIG_cat_restore_en_START (19)
#define SOC_DDR_PACK_CATCONFIG_cat_restore_en_END (19)
#define SOC_DDR_PACK_CATCONFIG_cat_ave_comp_en_START (20)
#define SOC_DDR_PACK_CATCONFIG_cat_ave_comp_en_END (20)
#define SOC_DDR_PACK_CATCONFIG_cat_rb2nd_fine_en_START (21)
#define SOC_DDR_PACK_CATCONFIG_cat_rb2nd_fine_en_END (21)
#define SOC_DDR_PACK_CATCONFIG_sw_cst_mode_START (22)
#define SOC_DDR_PACK_CATCONFIG_sw_cst_mode_END (22)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_mrw42_START (24)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_mrw42_END (24)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_mrw48_START (25)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_mrw48_END (25)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_mrw41_START (26)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_mrw41_END (26)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_strobe_START (27)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_strobe_END (27)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_cke_high_START (28)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_cke_high_END (28)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_cke_low_START (29)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_cke_low_END (29)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_dqvalid_START (30)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_dqvalid_END (30)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_en_START (31)
#define SOC_DDR_PACK_CATCONFIG_sw_cat_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cat_result : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PACK_CATRESULT_UNION;
#endif
#define SOC_DDR_PACK_CATRESULT_cat_result_START (0)
#define SOC_DDR_PACK_CATRESULT_cat_result_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_dq_result : 32;
    } reg;
} SOC_DDR_PACK_PHYDQRESULT_UNION;
#endif
#define SOC_DDR_PACK_PHYDQRESULT_phy_dq_result_START (0)
#define SOC_DDR_PACK_PHYDQRESULT_phy_dq_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addrph_a_right : 8;
        unsigned int addrph_a_left : 8;
        unsigned int addrph_a : 8;
        unsigned int addrph_a_ori : 8;
    } reg;
} SOC_DDR_PACK_ADDRPHBOUND_UNION;
#endif
#define SOC_DDR_PACK_ADDRPHBOUND_addrph_a_right_START (0)
#define SOC_DDR_PACK_ADDRPHBOUND_addrph_a_right_END (7)
#define SOC_DDR_PACK_ADDRPHBOUND_addrph_a_left_START (8)
#define SOC_DDR_PACK_ADDRPHBOUND_addrph_a_left_END (15)
#define SOC_DDR_PACK_ADDRPHBOUND_addrph_a_START (16)
#define SOC_DDR_PACK_ADDRPHBOUND_addrph_a_END (23)
#define SOC_DDR_PACK_ADDRPHBOUND_addrph_a_ori_START (24)
#define SOC_DDR_PACK_ADDRPHBOUND_addrph_a_ori_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_cat_pat_p : 10;
        unsigned int sw_cat_pat_alt_indx : 6;
        unsigned int sw_cat_pat_n : 10;
        unsigned int reserved : 3;
        unsigned int sw_cat_pat_alt_auto : 1;
        unsigned int sw_cat_pat_alt_en : 1;
        unsigned int cfg_cat_wck_tg_mask : 1;
    } reg;
} SOC_DDR_PACK_SWCATPATTERN_P_UNION;
#endif
#define SOC_DDR_PACK_SWCATPATTERN_P_sw_cat_pat_p_START (0)
#define SOC_DDR_PACK_SWCATPATTERN_P_sw_cat_pat_p_END (9)
#define SOC_DDR_PACK_SWCATPATTERN_P_sw_cat_pat_alt_indx_START (10)
#define SOC_DDR_PACK_SWCATPATTERN_P_sw_cat_pat_alt_indx_END (15)
#define SOC_DDR_PACK_SWCATPATTERN_P_sw_cat_pat_n_START (16)
#define SOC_DDR_PACK_SWCATPATTERN_P_sw_cat_pat_n_END (25)
#define SOC_DDR_PACK_SWCATPATTERN_P_sw_cat_pat_alt_auto_START (29)
#define SOC_DDR_PACK_SWCATPATTERN_P_sw_cat_pat_alt_auto_END (29)
#define SOC_DDR_PACK_SWCATPATTERN_P_sw_cat_pat_alt_en_START (30)
#define SOC_DDR_PACK_SWCATPATTERN_P_sw_cat_pat_alt_en_END (30)
#define SOC_DDR_PACK_SWCATPATTERN_P_cfg_cat_wck_tg_mask_START (31)
#define SOC_DDR_PACK_SWCATPATTERN_P_cfg_cat_wck_tg_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int packdbg1_info : 28;
        unsigned int packdbg1_sel : 4;
    } reg;
} SOC_DDR_PACK_PACKDEBUG1_UNION;
#endif
#define SOC_DDR_PACK_PACKDEBUG1_packdbg1_info_START (0)
#define SOC_DDR_PACK_PACKDEBUG1_packdbg1_info_END (27)
#define SOC_DDR_PACK_PACKDEBUG1_packdbg1_sel_START (28)
#define SOC_DDR_PACK_PACKDEBUG1_packdbg1_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mrs_seq_prog : 32;
    } reg;
} SOC_DDR_PACK_MRS_SEQ_PROG_UNION;
#endif
#define SOC_DDR_PACK_MRS_SEQ_PROG_mrs_seq_prog_START (0)
#define SOC_DDR_PACK_MRS_SEQ_PROG_mrs_seq_prog_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_dram_clk_enable : 4;
        unsigned int t_dram_clk_disable : 4;
        unsigned int t_wakeup_thrd_lv3 : 4;
        unsigned int t_resp : 4;
        unsigned int lp_pll_powerdown_disable : 1;
        unsigned int lp_dx_phy_phgated_disable : 1;
        unsigned int lp_dx_phy_clkgated_disable : 1;
        unsigned int lp_ac_phy_clkgated_disable : 1;
        unsigned int lp_cmdoen_disable : 1;
        unsigned int t_wakeup_thrd_lv2 : 4;
        unsigned int gcken_dxbist : 1;
        unsigned int gcken_acbist : 1;
        unsigned int gcken_retrain : 1;
        unsigned int gcken_dtrain : 1;
        unsigned int gcken_dinit : 1;
        unsigned int gcken_dfi_main : 1;
        unsigned int gcken_auto_en : 1;
    } reg;
} SOC_DDR_PACK_LPCTRL_UNION;
#endif
#define SOC_DDR_PACK_LPCTRL_t_dram_clk_enable_START (0)
#define SOC_DDR_PACK_LPCTRL_t_dram_clk_enable_END (3)
#define SOC_DDR_PACK_LPCTRL_t_dram_clk_disable_START (4)
#define SOC_DDR_PACK_LPCTRL_t_dram_clk_disable_END (7)
#define SOC_DDR_PACK_LPCTRL_t_wakeup_thrd_lv3_START (8)
#define SOC_DDR_PACK_LPCTRL_t_wakeup_thrd_lv3_END (11)
#define SOC_DDR_PACK_LPCTRL_t_resp_START (12)
#define SOC_DDR_PACK_LPCTRL_t_resp_END (15)
#define SOC_DDR_PACK_LPCTRL_lp_pll_powerdown_disable_START (16)
#define SOC_DDR_PACK_LPCTRL_lp_pll_powerdown_disable_END (16)
#define SOC_DDR_PACK_LPCTRL_lp_dx_phy_phgated_disable_START (17)
#define SOC_DDR_PACK_LPCTRL_lp_dx_phy_phgated_disable_END (17)
#define SOC_DDR_PACK_LPCTRL_lp_dx_phy_clkgated_disable_START (18)
#define SOC_DDR_PACK_LPCTRL_lp_dx_phy_clkgated_disable_END (18)
#define SOC_DDR_PACK_LPCTRL_lp_ac_phy_clkgated_disable_START (19)
#define SOC_DDR_PACK_LPCTRL_lp_ac_phy_clkgated_disable_END (19)
#define SOC_DDR_PACK_LPCTRL_lp_cmdoen_disable_START (20)
#define SOC_DDR_PACK_LPCTRL_lp_cmdoen_disable_END (20)
#define SOC_DDR_PACK_LPCTRL_t_wakeup_thrd_lv2_START (21)
#define SOC_DDR_PACK_LPCTRL_t_wakeup_thrd_lv2_END (24)
#define SOC_DDR_PACK_LPCTRL_gcken_dxbist_START (25)
#define SOC_DDR_PACK_LPCTRL_gcken_dxbist_END (25)
#define SOC_DDR_PACK_LPCTRL_gcken_acbist_START (26)
#define SOC_DDR_PACK_LPCTRL_gcken_acbist_END (26)
#define SOC_DDR_PACK_LPCTRL_gcken_retrain_START (27)
#define SOC_DDR_PACK_LPCTRL_gcken_retrain_END (27)
#define SOC_DDR_PACK_LPCTRL_gcken_dtrain_START (28)
#define SOC_DDR_PACK_LPCTRL_gcken_dtrain_END (28)
#define SOC_DDR_PACK_LPCTRL_gcken_dinit_START (29)
#define SOC_DDR_PACK_LPCTRL_gcken_dinit_END (29)
#define SOC_DDR_PACK_LPCTRL_gcken_dfi_main_START (30)
#define SOC_DDR_PACK_LPCTRL_gcken_dfi_main_END (30)
#define SOC_DDR_PACK_LPCTRL_gcken_auto_en_START (31)
#define SOC_DDR_PACK_LPCTRL_gcken_auto_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wl_falledge_ph_jstep_r : 5;
        unsigned int wl_falledge_ph_step_r : 5;
        unsigned int wl_falledge_bdl_jstep_r : 8;
        unsigned int cfg_wetwl2_en_r : 1;
        unsigned int wl_falledge_overflow_en_r : 1;
        unsigned int cfg_wetwl2_dqs_sel_r : 4;
        unsigned int cfg_wetwl2_bdl_en_r : 1;
        unsigned int cfg_wren_dq_vmask_dis : 1;
        unsigned int reserved : 2;
        unsigned int cat_av_en : 1;
        unsigned int cat_rbs_en : 1;
        unsigned int cat_ds_en : 1;
        unsigned int cat_lbs_en : 1;
    } reg;
} SOC_DDR_PACK_TRAINCTRL12_UNION;
#endif
#define SOC_DDR_PACK_TRAINCTRL12_wl_falledge_ph_jstep_r_START (0)
#define SOC_DDR_PACK_TRAINCTRL12_wl_falledge_ph_jstep_r_END (4)
#define SOC_DDR_PACK_TRAINCTRL12_wl_falledge_ph_step_r_START (5)
#define SOC_DDR_PACK_TRAINCTRL12_wl_falledge_ph_step_r_END (9)
#define SOC_DDR_PACK_TRAINCTRL12_wl_falledge_bdl_jstep_r_START (10)
#define SOC_DDR_PACK_TRAINCTRL12_wl_falledge_bdl_jstep_r_END (17)
#define SOC_DDR_PACK_TRAINCTRL12_cfg_wetwl2_en_r_START (18)
#define SOC_DDR_PACK_TRAINCTRL12_cfg_wetwl2_en_r_END (18)
#define SOC_DDR_PACK_TRAINCTRL12_wl_falledge_overflow_en_r_START (19)
#define SOC_DDR_PACK_TRAINCTRL12_wl_falledge_overflow_en_r_END (19)
#define SOC_DDR_PACK_TRAINCTRL12_cfg_wetwl2_dqs_sel_r_START (20)
#define SOC_DDR_PACK_TRAINCTRL12_cfg_wetwl2_dqs_sel_r_END (23)
#define SOC_DDR_PACK_TRAINCTRL12_cfg_wetwl2_bdl_en_r_START (24)
#define SOC_DDR_PACK_TRAINCTRL12_cfg_wetwl2_bdl_en_r_END (24)
#define SOC_DDR_PACK_TRAINCTRL12_cfg_wren_dq_vmask_dis_START (25)
#define SOC_DDR_PACK_TRAINCTRL12_cfg_wren_dq_vmask_dis_END (25)
#define SOC_DDR_PACK_TRAINCTRL12_cat_av_en_START (28)
#define SOC_DDR_PACK_TRAINCTRL12_cat_av_en_END (28)
#define SOC_DDR_PACK_TRAINCTRL12_cat_rbs_en_START (29)
#define SOC_DDR_PACK_TRAINCTRL12_cat_rbs_en_END (29)
#define SOC_DDR_PACK_TRAINCTRL12_cat_ds_en_START (30)
#define SOC_DDR_PACK_TRAINCTRL12_cat_ds_en_END (30)
#define SOC_DDR_PACK_TRAINCTRL12_cat_lbs_en_START (31)
#define SOC_DDR_PACK_TRAINCTRL12_cat_lbs_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cst_halfTpulse_mrgn : 5;
        unsigned int reserved_0 : 2;
        unsigned int cbt_csgated_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int cbt_dq_latch_mode : 2;
        unsigned int lp4_cbt_mode_type : 2;
        unsigned int reserved_2 : 2;
        unsigned int wl_mode_dq_pd_en : 1;
        unsigned int wl_mode_dq_pd_sel : 1;
        unsigned int reserved_3 : 1;
        unsigned int fast_wl2_cmp_dis : 1;
        unsigned int cst_ph_method : 1;
        unsigned int cst_halfTpulse_post : 1;
        unsigned int nopre4cat : 1;
        unsigned int cfg_cat_scanca_en : 1;
        unsigned int lp4_cbt_vrefset_sel : 2;
        unsigned int reserved_4 : 1;
        unsigned int lp4_cbt_dqx8_sel : 1;
        unsigned int cat_fulltime_tg_en : 1;
        unsigned int phydq_latch_en : 1;
        unsigned int cst_capat_extend_en : 1;
        unsigned int cst_halfTpulse_en : 1;
    } reg;
} SOC_DDR_PACK_CATCONFIG1_UNION;
#endif
#define SOC_DDR_PACK_CATCONFIG1_cst_halfTpulse_mrgn_START (0)
#define SOC_DDR_PACK_CATCONFIG1_cst_halfTpulse_mrgn_END (4)
#define SOC_DDR_PACK_CATCONFIG1_cbt_csgated_en_START (7)
#define SOC_DDR_PACK_CATCONFIG1_cbt_csgated_en_END (7)
#define SOC_DDR_PACK_CATCONFIG1_cbt_dq_latch_mode_START (10)
#define SOC_DDR_PACK_CATCONFIG1_cbt_dq_latch_mode_END (11)
#define SOC_DDR_PACK_CATCONFIG1_lp4_cbt_mode_type_START (12)
#define SOC_DDR_PACK_CATCONFIG1_lp4_cbt_mode_type_END (13)
#define SOC_DDR_PACK_CATCONFIG1_wl_mode_dq_pd_en_START (16)
#define SOC_DDR_PACK_CATCONFIG1_wl_mode_dq_pd_en_END (16)
#define SOC_DDR_PACK_CATCONFIG1_wl_mode_dq_pd_sel_START (17)
#define SOC_DDR_PACK_CATCONFIG1_wl_mode_dq_pd_sel_END (17)
#define SOC_DDR_PACK_CATCONFIG1_fast_wl2_cmp_dis_START (19)
#define SOC_DDR_PACK_CATCONFIG1_fast_wl2_cmp_dis_END (19)
#define SOC_DDR_PACK_CATCONFIG1_cst_ph_method_START (20)
#define SOC_DDR_PACK_CATCONFIG1_cst_ph_method_END (20)
#define SOC_DDR_PACK_CATCONFIG1_cst_halfTpulse_post_START (21)
#define SOC_DDR_PACK_CATCONFIG1_cst_halfTpulse_post_END (21)
#define SOC_DDR_PACK_CATCONFIG1_nopre4cat_START (22)
#define SOC_DDR_PACK_CATCONFIG1_nopre4cat_END (22)
#define SOC_DDR_PACK_CATCONFIG1_cfg_cat_scanca_en_START (23)
#define SOC_DDR_PACK_CATCONFIG1_cfg_cat_scanca_en_END (23)
#define SOC_DDR_PACK_CATCONFIG1_lp4_cbt_vrefset_sel_START (24)
#define SOC_DDR_PACK_CATCONFIG1_lp4_cbt_vrefset_sel_END (25)
#define SOC_DDR_PACK_CATCONFIG1_lp4_cbt_dqx8_sel_START (27)
#define SOC_DDR_PACK_CATCONFIG1_lp4_cbt_dqx8_sel_END (27)
#define SOC_DDR_PACK_CATCONFIG1_cat_fulltime_tg_en_START (28)
#define SOC_DDR_PACK_CATCONFIG1_cat_fulltime_tg_en_END (28)
#define SOC_DDR_PACK_CATCONFIG1_phydq_latch_en_START (29)
#define SOC_DDR_PACK_CATCONFIG1_phydq_latch_en_END (29)
#define SOC_DDR_PACK_CATCONFIG1_cst_capat_extend_en_START (30)
#define SOC_DDR_PACK_CATCONFIG1_cst_capat_extend_en_END (30)
#define SOC_DDR_PACK_CATCONFIG1_cst_halfTpulse_en_START (31)
#define SOC_DDR_PACK_CATCONFIG1_cst_halfTpulse_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vrftres_ahvref : 7;
        unsigned int vrftres_ahvref_lb : 7;
        unsigned int vrftres_ahvref_ub : 7;
        unsigned int reserved : 11;
    } reg;
} SOC_DDR_PACK_AHVREFT_STATUS_UNION;
#endif
#define SOC_DDR_PACK_AHVREFT_STATUS_vrftres_ahvref_START (0)
#define SOC_DDR_PACK_AHVREFT_STATUS_vrftres_ahvref_END (6)
#define SOC_DDR_PACK_AHVREFT_STATUS_vrftres_ahvref_lb_START (7)
#define SOC_DDR_PACK_AHVREFT_STATUS_vrftres_ahvref_lb_END (13)
#define SOC_DDR_PACK_AHVREFT_STATUS_vrftres_ahvref_ub_START (14)
#define SOC_DDR_PACK_AHVREFT_STATUS_vrftres_ahvref_ub_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_vrftres_dvref : 7;
        unsigned int reserved_0 : 1;
        unsigned int ac_vrftres_dvref_lb : 7;
        unsigned int reserved_1 : 1;
        unsigned int ac_vrftres_dvref_ub : 7;
        unsigned int reserved_2 : 6;
        unsigned int cfg_dvrefs_dq_type : 1;
        unsigned int cfg_dvrefs_nopre : 1;
        unsigned int ac_vreftres_set_type : 1;
    } reg;
} SOC_DDR_PACK_ADVREF_STATUS_UNION;
#endif
#define SOC_DDR_PACK_ADVREF_STATUS_ac_vrftres_dvref_START (0)
#define SOC_DDR_PACK_ADVREF_STATUS_ac_vrftres_dvref_END (6)
#define SOC_DDR_PACK_ADVREF_STATUS_ac_vrftres_dvref_lb_START (8)
#define SOC_DDR_PACK_ADVREF_STATUS_ac_vrftres_dvref_lb_END (14)
#define SOC_DDR_PACK_ADVREF_STATUS_ac_vrftres_dvref_ub_START (16)
#define SOC_DDR_PACK_ADVREF_STATUS_ac_vrftres_dvref_ub_END (22)
#define SOC_DDR_PACK_ADVREF_STATUS_cfg_dvrefs_dq_type_START (29)
#define SOC_DDR_PACK_ADVREF_STATUS_cfg_dvrefs_dq_type_END (29)
#define SOC_DDR_PACK_ADVREF_STATUS_cfg_dvrefs_nopre_START (30)
#define SOC_DDR_PACK_ADVREF_STATUS_cfg_dvrefs_nopre_END (30)
#define SOC_DDR_PACK_ADVREF_STATUS_ac_vreftres_set_type_START (31)
#define SOC_DDR_PACK_ADVREF_STATUS_ac_vreftres_set_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perbit_track_limit_r : 7;
        unsigned int reserved : 11;
        unsigned int auto_track_sw_en : 1;
        unsigned int phy_autoref_en : 1;
        unsigned int perbit_hipri_en_r : 1;
        unsigned int perbit_lowpri_en_r : 1;
        unsigned int perbit_flag_clr_r : 1;
        unsigned int dynatrk_perbit_cnt_clr_en_r : 1;
        unsigned int dlytrack_perbit_tap_r : 2;
        unsigned int perbit_track_model_sel_r : 1;
        unsigned int perbit_PN_track_en_r : 1;
        unsigned int dynamic_perbit_en_r : 1;
        unsigned int dynamic_dqsg_pri_en_r : 1;
        unsigned int dynamic_dqsg_hipri_en_r : 1;
        unsigned int dlytrack_dqsg_method_sel_r : 1;
    } reg;
} SOC_DDR_PACK_DLYMEASCTRL1_UNION;
#endif
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_track_limit_r_START (0)
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_track_limit_r_END (6)
#define SOC_DDR_PACK_DLYMEASCTRL1_auto_track_sw_en_START (18)
#define SOC_DDR_PACK_DLYMEASCTRL1_auto_track_sw_en_END (18)
#define SOC_DDR_PACK_DLYMEASCTRL1_phy_autoref_en_START (19)
#define SOC_DDR_PACK_DLYMEASCTRL1_phy_autoref_en_END (19)
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_hipri_en_r_START (20)
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_hipri_en_r_END (20)
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_lowpri_en_r_START (21)
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_lowpri_en_r_END (21)
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_flag_clr_r_START (22)
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_flag_clr_r_END (22)
#define SOC_DDR_PACK_DLYMEASCTRL1_dynatrk_perbit_cnt_clr_en_r_START (23)
#define SOC_DDR_PACK_DLYMEASCTRL1_dynatrk_perbit_cnt_clr_en_r_END (23)
#define SOC_DDR_PACK_DLYMEASCTRL1_dlytrack_perbit_tap_r_START (24)
#define SOC_DDR_PACK_DLYMEASCTRL1_dlytrack_perbit_tap_r_END (25)
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_track_model_sel_r_START (26)
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_track_model_sel_r_END (26)
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_PN_track_en_r_START (27)
#define SOC_DDR_PACK_DLYMEASCTRL1_perbit_PN_track_en_r_END (27)
#define SOC_DDR_PACK_DLYMEASCTRL1_dynamic_perbit_en_r_START (28)
#define SOC_DDR_PACK_DLYMEASCTRL1_dynamic_perbit_en_r_END (28)
#define SOC_DDR_PACK_DLYMEASCTRL1_dynamic_dqsg_pri_en_r_START (29)
#define SOC_DDR_PACK_DLYMEASCTRL1_dynamic_dqsg_pri_en_r_END (29)
#define SOC_DDR_PACK_DLYMEASCTRL1_dynamic_dqsg_hipri_en_r_START (30)
#define SOC_DDR_PACK_DLYMEASCTRL1_dynamic_dqsg_hipri_en_r_END (30)
#define SOC_DDR_PACK_DLYMEASCTRL1_dlytrack_dqsg_method_sel_r_START (31)
#define SOC_DDR_PACK_DLYMEASCTRL1_dlytrack_dqsg_method_sel_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_lpwakeup_fg : 5;
        unsigned int dfi_adrbits_sel_ddr4 : 1;
        unsigned int lp_csoen_disable : 1;
        unsigned int pack1t4_phy1t2_trans_en : 1;
        unsigned int cfg_rx_gcnt : 8;
        unsigned int reserved_0 : 4;
        unsigned int tlp_lv2_OE_resume : 4;
        unsigned int pack1t2_phy1t1_trans_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int rt_dis_ack : 1;
        unsigned int rt_dis_req : 1;
        unsigned int reserved_2 : 2;
        unsigned int gcken_apb_ctrlreg : 1;
        unsigned int gcken_apb_auto_en : 1;
    } reg;
} SOC_DDR_PACK_DFIMISCCTRL_UNION;
#endif
#define SOC_DDR_PACK_DFIMISCCTRL_t_lpwakeup_fg_START (0)
#define SOC_DDR_PACK_DFIMISCCTRL_t_lpwakeup_fg_END (4)
#define SOC_DDR_PACK_DFIMISCCTRL_dfi_adrbits_sel_ddr4_START (5)
#define SOC_DDR_PACK_DFIMISCCTRL_dfi_adrbits_sel_ddr4_END (5)
#define SOC_DDR_PACK_DFIMISCCTRL_lp_csoen_disable_START (6)
#define SOC_DDR_PACK_DFIMISCCTRL_lp_csoen_disable_END (6)
#define SOC_DDR_PACK_DFIMISCCTRL_pack1t4_phy1t2_trans_en_START (7)
#define SOC_DDR_PACK_DFIMISCCTRL_pack1t4_phy1t2_trans_en_END (7)
#define SOC_DDR_PACK_DFIMISCCTRL_cfg_rx_gcnt_START (8)
#define SOC_DDR_PACK_DFIMISCCTRL_cfg_rx_gcnt_END (15)
#define SOC_DDR_PACK_DFIMISCCTRL_tlp_lv2_OE_resume_START (20)
#define SOC_DDR_PACK_DFIMISCCTRL_tlp_lv2_OE_resume_END (23)
#define SOC_DDR_PACK_DFIMISCCTRL_pack1t2_phy1t1_trans_en_START (24)
#define SOC_DDR_PACK_DFIMISCCTRL_pack1t2_phy1t1_trans_en_END (24)
#define SOC_DDR_PACK_DFIMISCCTRL_rt_dis_ack_START (26)
#define SOC_DDR_PACK_DFIMISCCTRL_rt_dis_ack_END (26)
#define SOC_DDR_PACK_DFIMISCCTRL_rt_dis_req_START (27)
#define SOC_DDR_PACK_DFIMISCCTRL_rt_dis_req_END (27)
#define SOC_DDR_PACK_DFIMISCCTRL_gcken_apb_ctrlreg_START (30)
#define SOC_DDR_PACK_DFIMISCCTRL_gcken_apb_ctrlreg_END (30)
#define SOC_DDR_PACK_DFIMISCCTRL_gcken_apb_auto_en_START (31)
#define SOC_DDR_PACK_DFIMISCCTRL_gcken_apb_auto_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bist_en : 1;
        unsigned int prbs_inv_lsb : 7;
        unsigned int dq_cmp_mask : 8;
        unsigned int dqm_cmp_mask : 1;
        unsigned int prbs_mode : 2;
        unsigned int prbs_inv_msb : 2;
        unsigned int reserved : 3;
        unsigned int lfsr_seed : 8;
    } reg;
} SOC_DDR_PACK_DXNBISTCTRL_UNION;
#endif
#define SOC_DDR_PACK_DXNBISTCTRL_bist_en_START (0)
#define SOC_DDR_PACK_DXNBISTCTRL_bist_en_END (0)
#define SOC_DDR_PACK_DXNBISTCTRL_prbs_inv_lsb_START (1)
#define SOC_DDR_PACK_DXNBISTCTRL_prbs_inv_lsb_END (7)
#define SOC_DDR_PACK_DXNBISTCTRL_dq_cmp_mask_START (8)
#define SOC_DDR_PACK_DXNBISTCTRL_dq_cmp_mask_END (15)
#define SOC_DDR_PACK_DXNBISTCTRL_dqm_cmp_mask_START (16)
#define SOC_DDR_PACK_DXNBISTCTRL_dqm_cmp_mask_END (16)
#define SOC_DDR_PACK_DXNBISTCTRL_prbs_mode_START (17)
#define SOC_DDR_PACK_DXNBISTCTRL_prbs_mode_END (18)
#define SOC_DDR_PACK_DXNBISTCTRL_prbs_inv_msb_START (19)
#define SOC_DDR_PACK_DXNBISTCTRL_prbs_inv_msb_END (20)
#define SOC_DDR_PACK_DXNBISTCTRL_lfsr_seed_START (24)
#define SOC_DDR_PACK_DXNBISTCTRL_lfsr_seed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dq_cmp_rerr : 8;
        unsigned int dq_cmp_ferr : 8;
        unsigned int dqm_cmp_rerr : 1;
        unsigned int dqm_cmp_ferr : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_PACK_DXNBISTSTS_UNION;
#endif
#define SOC_DDR_PACK_DXNBISTSTS_dq_cmp_rerr_START (0)
#define SOC_DDR_PACK_DXNBISTSTS_dq_cmp_rerr_END (7)
#define SOC_DDR_PACK_DXNBISTSTS_dq_cmp_ferr_START (8)
#define SOC_DDR_PACK_DXNBISTSTS_dq_cmp_ferr_END (15)
#define SOC_DDR_PACK_DXNBISTSTS_dqm_cmp_rerr_START (16)
#define SOC_DDR_PACK_DXNBISTSTS_dqm_cmp_rerr_END (16)
#define SOC_DDR_PACK_DXNBISTSTS_dqm_cmp_ferr_START (17)
#define SOC_DDR_PACK_DXNBISTSTS_dqm_cmp_ferr_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bl_dis : 1;
        unsigned int dm_dis : 1;
        unsigned int reserved_0 : 3;
        unsigned int underflow_dqs : 1;
        unsigned int overflow_dqs : 1;
        unsigned int gck_dbi_autoen : 1;
        unsigned int dbi_write_mode : 2;
        unsigned int dbi_read_en : 2;
        unsigned int dbi_write_en : 2;
        unsigned int dbi_polarity : 1;
        unsigned int wdbi_mask_en : 1;
        unsigned int wdbi_mask_data : 8;
        unsigned int wl_falledge_adj_en_r : 1;
        unsigned int wl_falledge_pre_bdl_r : 1;
        unsigned int wl_rise_edge_r : 1;
        unsigned int wl_fall_edge_r : 1;
        unsigned int wetwl2_done_r : 1;
        unsigned int wetwl2_dbchk_err_r : 1;
        unsigned int wetwl2_err_r : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_DDR_PACK_DXNCTRL_UNION;
#endif
#define SOC_DDR_PACK_DXNCTRL_bl_dis_START (0)
#define SOC_DDR_PACK_DXNCTRL_bl_dis_END (0)
#define SOC_DDR_PACK_DXNCTRL_dm_dis_START (1)
#define SOC_DDR_PACK_DXNCTRL_dm_dis_END (1)
#define SOC_DDR_PACK_DXNCTRL_underflow_dqs_START (5)
#define SOC_DDR_PACK_DXNCTRL_underflow_dqs_END (5)
#define SOC_DDR_PACK_DXNCTRL_overflow_dqs_START (6)
#define SOC_DDR_PACK_DXNCTRL_overflow_dqs_END (6)
#define SOC_DDR_PACK_DXNCTRL_gck_dbi_autoen_START (7)
#define SOC_DDR_PACK_DXNCTRL_gck_dbi_autoen_END (7)
#define SOC_DDR_PACK_DXNCTRL_dbi_write_mode_START (8)
#define SOC_DDR_PACK_DXNCTRL_dbi_write_mode_END (9)
#define SOC_DDR_PACK_DXNCTRL_dbi_read_en_START (10)
#define SOC_DDR_PACK_DXNCTRL_dbi_read_en_END (11)
#define SOC_DDR_PACK_DXNCTRL_dbi_write_en_START (12)
#define SOC_DDR_PACK_DXNCTRL_dbi_write_en_END (13)
#define SOC_DDR_PACK_DXNCTRL_dbi_polarity_START (14)
#define SOC_DDR_PACK_DXNCTRL_dbi_polarity_END (14)
#define SOC_DDR_PACK_DXNCTRL_wdbi_mask_en_START (15)
#define SOC_DDR_PACK_DXNCTRL_wdbi_mask_en_END (15)
#define SOC_DDR_PACK_DXNCTRL_wdbi_mask_data_START (16)
#define SOC_DDR_PACK_DXNCTRL_wdbi_mask_data_END (23)
#define SOC_DDR_PACK_DXNCTRL_wl_falledge_adj_en_r_START (24)
#define SOC_DDR_PACK_DXNCTRL_wl_falledge_adj_en_r_END (24)
#define SOC_DDR_PACK_DXNCTRL_wl_falledge_pre_bdl_r_START (25)
#define SOC_DDR_PACK_DXNCTRL_wl_falledge_pre_bdl_r_END (25)
#define SOC_DDR_PACK_DXNCTRL_wl_rise_edge_r_START (26)
#define SOC_DDR_PACK_DXNCTRL_wl_rise_edge_r_END (26)
#define SOC_DDR_PACK_DXNCTRL_wl_fall_edge_r_START (27)
#define SOC_DDR_PACK_DXNCTRL_wl_fall_edge_r_END (27)
#define SOC_DDR_PACK_DXNCTRL_wetwl2_done_r_START (28)
#define SOC_DDR_PACK_DXNCTRL_wetwl2_done_r_END (28)
#define SOC_DDR_PACK_DXNCTRL_wetwl2_dbchk_err_r_START (29)
#define SOC_DDR_PACK_DXNCTRL_wetwl2_dbchk_err_r_END (29)
#define SOC_DDR_PACK_DXNCTRL_wetwl2_err_r_START (30)
#define SOC_DDR_PACK_DXNCTRL_wetwl2_err_r_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int weccbdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNWECCBDL_UNION;
#endif
#define SOC_DDR_PACK_DXNWECCBDL_weccbdl_START (0)
#define SOC_DDR_PACK_DXNWECCBDL_weccbdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int oen_bdl : 10;
        unsigned int reserved_0 : 6;
        unsigned int wdqsoe_bdl : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_PACK_DXNOEBDL_UNION;
#endif
#define SOC_DDR_PACK_DXNOEBDL_oen_bdl_START (0)
#define SOC_DDR_PACK_DXNOEBDL_oen_bdl_END (9)
#define SOC_DDR_PACK_DXNOEBDL_wdqsoe_bdl_START (16)
#define SOC_DDR_PACK_DXNOEBDL_wdqsoe_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdqsbdl : 10;
        unsigned int reserved_0: 6;
        unsigned int rdqscyc : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_DDR_PACK_DXNRDQSDLY_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQSDLY_rdqsbdl_START (0)
#define SOC_DDR_PACK_DXNRDQSDLY_rdqsbdl_END (9)
#define SOC_DDR_PACK_DXNRDQSDLY_rdqscyc_START (16)
#define SOC_DDR_PACK_DXNRDQSDLY_rdqscyc_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdqsbdl : 8;
        unsigned int wdqsphase : 6;
        unsigned int reserved : 16;
        unsigned int wdqsbdl_msb : 2;
    } reg;
} SOC_DDR_PACK_DXNWDQSDLY_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQSDLY_wdqsbdl_START (0)
#define SOC_DDR_PACK_DXNWDQSDLY_wdqsbdl_END (7)
#define SOC_DDR_PACK_DXNWDQSDLY_wdqsphase_START (8)
#define SOC_DDR_PACK_DXNWDQSDLY_wdqsphase_END (13)
#define SOC_DDR_PACK_DXNWDQSDLY_wdqsbdl_msb_START (30)
#define SOC_DDR_PACK_DXNWDQSDLY_wdqsbdl_msb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int wdqphase : 8;
        unsigned int reserved_1: 16;
    } reg;
} SOC_DDR_PACK_DXNWDQDLY_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQDLY_wdqphase_START (8)
#define SOC_DDR_PACK_DXNWDQDLY_wdqphase_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int wlsl : 2;
        unsigned int reserved_1: 14;
    } reg;
} SOC_DDR_PACK_DXNWLSL_UNION;
#endif
#define SOC_DDR_PACK_DXNWLSL_wlsl_START (16)
#define SOC_DDR_PACK_DXNWLSL_wlsl_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gds : 5;
        unsigned int reserved_0 : 11;
        unsigned int org_rdqsgph : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_PACK_DXNGDS_UNION;
#endif
#define SOC_DDR_PACK_DXNGDS_gds_START (0)
#define SOC_DDR_PACK_DXNGDS_gds_END (4)
#define SOC_DDR_PACK_DXNGDS_org_rdqsgph_START (16)
#define SOC_DDR_PACK_DXNGDS_org_rdqsgph_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdqsgbdl : 8;
        unsigned int reserved_0 : 1;
        unsigned int rdqsgphase : 10;
        unsigned int rdqsgbdl_msb : 2;
        unsigned int reserved_1 : 1;
        unsigned int rdqsgtxbdl_msb : 2;
        unsigned int rdqsgtxbdl : 8;
    } reg;
} SOC_DDR_PACK_DXNRDQSGDLY_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQSGDLY_rdqsgbdl_START (0)
#define SOC_DDR_PACK_DXNRDQSGDLY_rdqsgbdl_END (7)
#define SOC_DDR_PACK_DXNRDQSGDLY_rdqsgphase_START (9)
#define SOC_DDR_PACK_DXNRDQSGDLY_rdqsgphase_END (18)
#define SOC_DDR_PACK_DXNRDQSGDLY_rdqsgbdl_msb_START (19)
#define SOC_DDR_PACK_DXNRDQSGDLY_rdqsgbdl_msb_END (20)
#define SOC_DDR_PACK_DXNRDQSGDLY_rdqsgtxbdl_msb_START (22)
#define SOC_DDR_PACK_DXNRDQSGDLY_rdqsgtxbdl_msb_END (23)
#define SOC_DDR_PACK_DXNRDQSGDLY_rdqsgtxbdl_START (24)
#define SOC_DDR_PACK_DXNRDQSGDLY_rdqsgtxbdl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq0bdl_left : 8;
        unsigned int wdq1bdl_left : 8;
        unsigned int wdq2bdl_left : 8;
        unsigned int wdq3bdl_left : 8;
    } reg;
} SOC_DDR_PACK_DXNWDQNLB0_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQNLB0_wdq0bdl_left_START (0)
#define SOC_DDR_PACK_DXNWDQNLB0_wdq0bdl_left_END (7)
#define SOC_DDR_PACK_DXNWDQNLB0_wdq1bdl_left_START (8)
#define SOC_DDR_PACK_DXNWDQNLB0_wdq1bdl_left_END (15)
#define SOC_DDR_PACK_DXNWDQNLB0_wdq2bdl_left_START (16)
#define SOC_DDR_PACK_DXNWDQNLB0_wdq2bdl_left_END (23)
#define SOC_DDR_PACK_DXNWDQNLB0_wdq3bdl_left_START (24)
#define SOC_DDR_PACK_DXNWDQNLB0_wdq3bdl_left_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdqsbdl30 : 10;
        unsigned int reserved_0 : 6;
        unsigned int bdl_mondly : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_PACK_DXNRDQSDLYSUB_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQSDLYSUB_rdqsbdl30_START (0)
#define SOC_DDR_PACK_DXNRDQSDLYSUB_rdqsbdl30_END (9)
#define SOC_DDR_PACK_DXNRDQSDLYSUB_bdl_mondly_START (16)
#define SOC_DDR_PACK_DXNRDQSDLYSUB_bdl_mondly_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdqsbdl_right : 10;
        unsigned int reserved_0 : 6;
        unsigned int rdqsbdl_left : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_PACK_DXNRDBOUND_UNION;
#endif
#define SOC_DDR_PACK_DXNRDBOUND_rdqsbdl_right_START (0)
#define SOC_DDR_PACK_DXNRDBOUND_rdqsbdl_right_END (9)
#define SOC_DDR_PACK_DXNRDBOUND_rdqsbdl_left_START (16)
#define SOC_DDR_PACK_DXNRDBOUND_rdqsbdl_left_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdqphase_right : 8;
        unsigned int reserved_0 : 4;
        unsigned int wdet_ave_comp_flag : 1;
        unsigned int reserved_1 : 3;
        unsigned int wdqphase_left : 8;
        unsigned int wdq0bdl_left : 8;
    } reg;
} SOC_DDR_PACK_DXNWRBOUND_UNION;
#endif
#define SOC_DDR_PACK_DXNWRBOUND_wdqphase_right_START (0)
#define SOC_DDR_PACK_DXNWRBOUND_wdqphase_right_END (7)
#define SOC_DDR_PACK_DXNWRBOUND_wdet_ave_comp_flag_START (12)
#define SOC_DDR_PACK_DXNWRBOUND_wdet_ave_comp_flag_END (12)
#define SOC_DDR_PACK_DXNWRBOUND_wdqphase_left_START (16)
#define SOC_DDR_PACK_DXNWRBOUND_wdqphase_left_END (23)
#define SOC_DDR_PACK_DXNWRBOUND_wdq0bdl_left_START (24)
#define SOC_DDR_PACK_DXNWRBOUND_wdq0bdl_left_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq4bdl_left : 8;
        unsigned int wdq5bdl_left : 8;
        unsigned int wdq6bdl_left : 8;
        unsigned int wdq7bdl_left : 8;
    } reg;
} SOC_DDR_PACK_DXNWDQNLB1_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQNLB1_wdq4bdl_left_START (0)
#define SOC_DDR_PACK_DXNWDQNLB1_wdq4bdl_left_END (7)
#define SOC_DDR_PACK_DXNWDQNLB1_wdq5bdl_left_START (8)
#define SOC_DDR_PACK_DXNWDQNLB1_wdq5bdl_left_END (15)
#define SOC_DDR_PACK_DXNWDQNLB1_wdq6bdl_left_START (16)
#define SOC_DDR_PACK_DXNWDQNLB1_wdq6bdl_left_END (23)
#define SOC_DDR_PACK_DXNWDQNLB1_wdq7bdl_left_START (24)
#define SOC_DDR_PACK_DXNWDQNLB1_wdq7bdl_left_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdmbdl_msb_left : 16;
        unsigned int dqs0_gold : 16;
    } reg;
} SOC_DDR_PACK_DXDEBUG0_UNION;
#endif
#define SOC_DDR_PACK_DXDEBUG0_wdmbdl_msb_left_START (0)
#define SOC_DDR_PACK_DXDEBUG0_wdmbdl_msb_left_END (15)
#define SOC_DDR_PACK_DXDEBUG0_dqs0_gold_START (16)
#define SOC_DDR_PACK_DXDEBUG0_dqs0_gold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dqs0b : 16;
        unsigned int dqs0 : 16;
    } reg;
} SOC_DDR_PACK_DXDEBUG1_UNION;
#endif
#define SOC_DDR_PACK_DXDEBUG1_dqs0b_START (0)
#define SOC_DDR_PACK_DXDEBUG1_dqs0b_END (15)
#define SOC_DDR_PACK_DXDEBUG1_dqs0_START (16)
#define SOC_DDR_PACK_DXDEBUG1_dqs0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vrftres_dvref : 7;
        unsigned int reserved_0 : 1;
        unsigned int vrftres_dvref_lb : 7;
        unsigned int reserved_1 : 1;
        unsigned int vrftres_dvref_ub : 7;
        unsigned int reserved_2 : 1;
        unsigned int wdmbdl_left : 8;
    } reg;
} SOC_DDR_PACK_DVREFT_STATUS_UNION;
#endif
#define SOC_DDR_PACK_DVREFT_STATUS_vrftres_dvref_START (0)
#define SOC_DDR_PACK_DVREFT_STATUS_vrftres_dvref_END (6)
#define SOC_DDR_PACK_DVREFT_STATUS_vrftres_dvref_lb_START (8)
#define SOC_DDR_PACK_DVREFT_STATUS_vrftres_dvref_lb_END (14)
#define SOC_DDR_PACK_DVREFT_STATUS_vrftres_dvref_ub_START (16)
#define SOC_DDR_PACK_DVREFT_STATUS_vrftres_dvref_ub_END (22)
#define SOC_DDR_PACK_DVREFT_STATUS_wdmbdl_left_START (24)
#define SOC_DDR_PACK_DVREFT_STATUS_wdmbdl_left_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vrftres_hvref : 7;
        unsigned int vrftres_hvref_lb : 7;
        unsigned int vrftres_dvref_ub : 7;
        unsigned int reserved : 11;
    } reg;
} SOC_DDR_PACK_HVREFT_STATUS_UNION;
#endif
#define SOC_DDR_PACK_HVREFT_STATUS_vrftres_hvref_START (0)
#define SOC_DDR_PACK_HVREFT_STATUS_vrftres_hvref_END (6)
#define SOC_DDR_PACK_HVREFT_STATUS_vrftres_hvref_lb_START (7)
#define SOC_DDR_PACK_HVREFT_STATUS_vrftres_hvref_lb_END (13)
#define SOC_DDR_PACK_HVREFT_STATUS_vrftres_dvref_ub_START (14)
#define SOC_DDR_PACK_HVREFT_STATUS_vrftres_dvref_ub_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int underflow_dq : 8;
        unsigned int overflow_dq : 8;
        unsigned int underflow_dm : 1;
        unsigned int overflow_dm : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_PACK_DXNTRACKSTATUS_UNION;
#endif
#define SOC_DDR_PACK_DXNTRACKSTATUS_underflow_dq_START (0)
#define SOC_DDR_PACK_DXNTRACKSTATUS_underflow_dq_END (7)
#define SOC_DDR_PACK_DXNTRACKSTATUS_overflow_dq_START (8)
#define SOC_DDR_PACK_DXNTRACKSTATUS_overflow_dq_END (15)
#define SOC_DDR_PACK_DXNTRACKSTATUS_underflow_dm_START (16)
#define SOC_DDR_PACK_DXNTRACKSTATUS_underflow_dm_END (16)
#define SOC_DDR_PACK_DXNTRACKSTATUS_overflow_dm_START (17)
#define SOC_DDR_PACK_DXNTRACKSTATUS_overflow_dm_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vreft_bist_rb : 10;
        unsigned int reserved_0 : 6;
        unsigned int vreft_bist_lb : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_PACK_VREFT_BOUND_UNION;
#endif
#define SOC_DDR_PACK_VREFT_BOUND_vreft_bist_rb_START (0)
#define SOC_DDR_PACK_VREFT_BOUND_vreft_bist_rb_END (9)
#define SOC_DDR_PACK_VREFT_BOUND_vreft_bist_lb_START (16)
#define SOC_DDR_PACK_VREFT_BOUND_vreft_bist_lb_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_lock_err_th : 4;
        unsigned int pll_lock_err_en : 1;
        unsigned int pll_lock_err_clr : 1;
        unsigned int pll_lock_err_cnt_r : 4;
        unsigned int bgdlymeas_int_en : 1;
        unsigned int dvalid_err_int_en : 1;
        unsigned int gate_err_int_en : 1;
        unsigned int gate_err_int_clr : 1;
        unsigned int gate_err_int_type : 1;
        unsigned int jtmt_error_int_en : 1;
        unsigned int wdert_err_int_en : 1;
        unsigned int pll_lock_lp_err_en : 1;
        unsigned int dfi_sel_err_en : 1;
        unsigned int dfi_sel_err_clr : 1;
        unsigned int zcal_err_int_en : 1;
        unsigned int reserved : 2;
        unsigned int zcal_err_int : 1;
        unsigned int bgdlymeas_int : 1;
        unsigned int dvalid_err_int : 1;
        unsigned int jtmt_error_int : 1;
        unsigned int pll_unlock_int_lp : 1;
        unsigned int dfi_sel_err_int : 1;
        unsigned int wdert_err_int : 1;
        unsigned int gate_err_int : 1;
        unsigned int pll_unlock_int : 1;
    } reg;
} SOC_DDR_PACK_PLLSTATUS_UNION;
#endif
#define SOC_DDR_PACK_PLLSTATUS_pll_lock_err_th_START (0)
#define SOC_DDR_PACK_PLLSTATUS_pll_lock_err_th_END (3)
#define SOC_DDR_PACK_PLLSTATUS_pll_lock_err_en_START (4)
#define SOC_DDR_PACK_PLLSTATUS_pll_lock_err_en_END (4)
#define SOC_DDR_PACK_PLLSTATUS_pll_lock_err_clr_START (5)
#define SOC_DDR_PACK_PLLSTATUS_pll_lock_err_clr_END (5)
#define SOC_DDR_PACK_PLLSTATUS_pll_lock_err_cnt_r_START (6)
#define SOC_DDR_PACK_PLLSTATUS_pll_lock_err_cnt_r_END (9)
#define SOC_DDR_PACK_PLLSTATUS_bgdlymeas_int_en_START (10)
#define SOC_DDR_PACK_PLLSTATUS_bgdlymeas_int_en_END (10)
#define SOC_DDR_PACK_PLLSTATUS_dvalid_err_int_en_START (11)
#define SOC_DDR_PACK_PLLSTATUS_dvalid_err_int_en_END (11)
#define SOC_DDR_PACK_PLLSTATUS_gate_err_int_en_START (12)
#define SOC_DDR_PACK_PLLSTATUS_gate_err_int_en_END (12)
#define SOC_DDR_PACK_PLLSTATUS_gate_err_int_clr_START (13)
#define SOC_DDR_PACK_PLLSTATUS_gate_err_int_clr_END (13)
#define SOC_DDR_PACK_PLLSTATUS_gate_err_int_type_START (14)
#define SOC_DDR_PACK_PLLSTATUS_gate_err_int_type_END (14)
#define SOC_DDR_PACK_PLLSTATUS_jtmt_error_int_en_START (15)
#define SOC_DDR_PACK_PLLSTATUS_jtmt_error_int_en_END (15)
#define SOC_DDR_PACK_PLLSTATUS_wdert_err_int_en_START (16)
#define SOC_DDR_PACK_PLLSTATUS_wdert_err_int_en_END (16)
#define SOC_DDR_PACK_PLLSTATUS_pll_lock_lp_err_en_START (17)
#define SOC_DDR_PACK_PLLSTATUS_pll_lock_lp_err_en_END (17)
#define SOC_DDR_PACK_PLLSTATUS_dfi_sel_err_en_START (18)
#define SOC_DDR_PACK_PLLSTATUS_dfi_sel_err_en_END (18)
#define SOC_DDR_PACK_PLLSTATUS_dfi_sel_err_clr_START (19)
#define SOC_DDR_PACK_PLLSTATUS_dfi_sel_err_clr_END (19)
#define SOC_DDR_PACK_PLLSTATUS_zcal_err_int_en_START (20)
#define SOC_DDR_PACK_PLLSTATUS_zcal_err_int_en_END (20)
#define SOC_DDR_PACK_PLLSTATUS_zcal_err_int_START (23)
#define SOC_DDR_PACK_PLLSTATUS_zcal_err_int_END (23)
#define SOC_DDR_PACK_PLLSTATUS_bgdlymeas_int_START (24)
#define SOC_DDR_PACK_PLLSTATUS_bgdlymeas_int_END (24)
#define SOC_DDR_PACK_PLLSTATUS_dvalid_err_int_START (25)
#define SOC_DDR_PACK_PLLSTATUS_dvalid_err_int_END (25)
#define SOC_DDR_PACK_PLLSTATUS_jtmt_error_int_START (26)
#define SOC_DDR_PACK_PLLSTATUS_jtmt_error_int_END (26)
#define SOC_DDR_PACK_PLLSTATUS_pll_unlock_int_lp_START (27)
#define SOC_DDR_PACK_PLLSTATUS_pll_unlock_int_lp_END (27)
#define SOC_DDR_PACK_PLLSTATUS_dfi_sel_err_int_START (28)
#define SOC_DDR_PACK_PLLSTATUS_dfi_sel_err_int_END (28)
#define SOC_DDR_PACK_PLLSTATUS_wdert_err_int_START (29)
#define SOC_DDR_PACK_PLLSTATUS_wdert_err_int_END (29)
#define SOC_DDR_PACK_PLLSTATUS_gate_err_int_START (30)
#define SOC_DDR_PACK_PLLSTATUS_gate_err_int_END (30)
#define SOC_DDR_PACK_PLLSTATUS_pll_unlock_int_START (31)
#define SOC_DDR_PACK_PLLSTATUS_pll_unlock_int_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpc_en_r : 1;
        unsigned int bstpatsel_dm_r : 3;
        unsigned int bstdat_dm_r : 2;
        unsigned int mpc_type_r : 1;
        unsigned int mpc_num_prewrite_r : 3;
        unsigned int mem_scan_test_en_r : 1;
        unsigned int bist_idle_insert_en_r : 1;
        unsigned int idle_start_bound_r : 7;
        unsigned int prbs4_pat_shift_mode : 3;
        unsigned int mpc_fifo_max_dp_ind : 2;
        unsigned int bstdat_indx : 2;
        unsigned int reserved : 1;
        unsigned int mem_scan_once_r : 1;
        unsigned int dxlpbk_cmpdis_cnt : 4;
    } reg;
} SOC_DDR_PACK_BISTCTRL1_UNION;
#endif
#define SOC_DDR_PACK_BISTCTRL1_mpc_en_r_START (0)
#define SOC_DDR_PACK_BISTCTRL1_mpc_en_r_END (0)
#define SOC_DDR_PACK_BISTCTRL1_bstpatsel_dm_r_START (1)
#define SOC_DDR_PACK_BISTCTRL1_bstpatsel_dm_r_END (3)
#define SOC_DDR_PACK_BISTCTRL1_bstdat_dm_r_START (4)
#define SOC_DDR_PACK_BISTCTRL1_bstdat_dm_r_END (5)
#define SOC_DDR_PACK_BISTCTRL1_mpc_type_r_START (6)
#define SOC_DDR_PACK_BISTCTRL1_mpc_type_r_END (6)
#define SOC_DDR_PACK_BISTCTRL1_mpc_num_prewrite_r_START (7)
#define SOC_DDR_PACK_BISTCTRL1_mpc_num_prewrite_r_END (9)
#define SOC_DDR_PACK_BISTCTRL1_mem_scan_test_en_r_START (10)
#define SOC_DDR_PACK_BISTCTRL1_mem_scan_test_en_r_END (10)
#define SOC_DDR_PACK_BISTCTRL1_bist_idle_insert_en_r_START (11)
#define SOC_DDR_PACK_BISTCTRL1_bist_idle_insert_en_r_END (11)
#define SOC_DDR_PACK_BISTCTRL1_idle_start_bound_r_START (12)
#define SOC_DDR_PACK_BISTCTRL1_idle_start_bound_r_END (18)
#define SOC_DDR_PACK_BISTCTRL1_prbs4_pat_shift_mode_START (19)
#define SOC_DDR_PACK_BISTCTRL1_prbs4_pat_shift_mode_END (21)
#define SOC_DDR_PACK_BISTCTRL1_mpc_fifo_max_dp_ind_START (22)
#define SOC_DDR_PACK_BISTCTRL1_mpc_fifo_max_dp_ind_END (23)
#define SOC_DDR_PACK_BISTCTRL1_bstdat_indx_START (24)
#define SOC_DDR_PACK_BISTCTRL1_bstdat_indx_END (25)
#define SOC_DDR_PACK_BISTCTRL1_mem_scan_once_r_START (27)
#define SOC_DDR_PACK_BISTCTRL1_mem_scan_once_r_END (27)
#define SOC_DDR_PACK_BISTCTRL1_dxlpbk_cmpdis_cnt_START (28)
#define SOC_DDR_PACK_BISTCTRL1_dxlpbk_cmpdis_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int det_pat_alt : 32;
    } reg;
} SOC_DDR_PACK_DETPATTERN1_UNION;
#endif
#define SOC_DDR_PACK_DETPATTERN1_det_pat_alt_START (0)
#define SOC_DDR_PACK_DETPATTERN1_det_pat_alt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mask_pattern : 4;
        unsigned int addr : 13;
        unsigned int err_req_cnt : 15;
    } reg;
} SOC_DDR_PACK_APB_WR_MASK_INFO_UNION;
#endif
#define SOC_DDR_PACK_APB_WR_MASK_INFO_mask_pattern_START (0)
#define SOC_DDR_PACK_APB_WR_MASK_INFO_mask_pattern_END (3)
#define SOC_DDR_PACK_APB_WR_MASK_INFO_addr_START (4)
#define SOC_DDR_PACK_APB_WR_MASK_INFO_addr_END (16)
#define SOC_DDR_PACK_APB_WR_MASK_INFO_err_req_cnt_START (17)
#define SOC_DDR_PACK_APB_WR_MASK_INFO_err_req_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mux_1p3_byp : 1;
        unsigned int mux_1p5_byp : 1;
        unsigned int mux_1p6_byp : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_PACK_REGMUXBYP_UNION;
#endif
#define SOC_DDR_PACK_REGMUXBYP_mux_1p3_byp_START (0)
#define SOC_DDR_PACK_REGMUXBYP_mux_1p3_byp_END (0)
#define SOC_DDR_PACK_REGMUXBYP_mux_1p5_byp_START (1)
#define SOC_DDR_PACK_REGMUXBYP_mux_1p5_byp_END (1)
#define SOC_DDR_PACK_REGMUXBYP_mux_1p6_byp_START (2)
#define SOC_DDR_PACK_REGMUXBYP_mux_1p6_byp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_swap_ca0 : 4;
        unsigned int addr_swap_ca1 : 4;
        unsigned int addr_swap_ca2 : 4;
        unsigned int addr_swap_ca3 : 4;
        unsigned int addr_swap_ca4 : 4;
        unsigned int addr_swap_ca5 : 4;
        unsigned int addr_swap_ca6 : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_UNION;
#endif
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca0_START (0)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca0_END (3)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca1_START (4)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca1_END (7)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca2_START (8)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca2_END (11)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca3_START (12)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca3_END (15)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca4_START (16)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca4_END (19)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca5_START (20)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca5_END (23)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca6_START (24)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_0_addr_swap_ca6_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_swap_cs0 : 4;
        unsigned int addr_swap_cs1 : 4;
        unsigned int addr_swap_cke0 : 4;
        unsigned int addr_swap_cke1 : 4;
        unsigned int addr_swap_oen_cs_to_ca : 7;
        unsigned int addr_swap_oen_ca_to_cs : 2;
        unsigned int addr_swap_oen_cs_to_cke : 2;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_UNION;
#endif
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_cs0_START (0)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_cs0_END (3)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_cs1_START (4)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_cs1_END (7)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_cke0_START (8)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_cke0_END (11)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_cke1_START (12)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_cke1_END (15)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_oen_cs_to_ca_START (16)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_oen_cs_to_ca_END (22)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_oen_ca_to_cs_START (23)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_oen_ca_to_cs_END (24)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_oen_cs_to_cke_START (25)
#define SOC_DDR_PACK_CFG_ADDR_SWAP_SOFT_1_addr_swap_oen_cs_to_cke_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data_merge_swap_dq0 : 4;
        unsigned int data_merge_swap_dq1 : 4;
        unsigned int data_merge_swap_dq2 : 4;
        unsigned int data_merge_swap_dq3 : 4;
        unsigned int data_merge_swap_dq4 : 4;
        unsigned int data_merge_swap_dq5 : 4;
        unsigned int data_merge_swap_dq6 : 4;
        unsigned int data_merge_swap_dq7 : 4;
    } reg;
} SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_UNION;
#endif
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq0_START (0)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq0_END (3)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq1_START (4)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq1_END (7)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq2_START (8)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq2_END (11)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq3_START (12)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq3_END (15)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq4_START (16)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq4_END (19)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq5_START (20)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq5_END (23)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq6_START (24)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq6_END (27)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq7_START (28)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_0_data_merge_swap_dq7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data_merge_swap_dq8 : 4;
        unsigned int data_merge_swap_dq9 : 4;
        unsigned int data_merge_swap_dq10 : 4;
        unsigned int data_merge_swap_dq11 : 4;
        unsigned int data_merge_swap_dq12 : 4;
        unsigned int data_merge_swap_dq13 : 4;
        unsigned int data_merge_swap_dq14 : 4;
        unsigned int data_merge_swap_dq15 : 4;
    } reg;
} SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_UNION;
#endif
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq8_START (0)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq8_END (3)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq9_START (4)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq9_END (7)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq10_START (8)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq10_END (11)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq11_START (12)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq11_END (15)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq12_START (16)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq12_END (19)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq13_START (20)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq13_END (23)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq14_START (24)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq14_END (27)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq15_START (28)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_1_data_merge_swap_dq15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data_merge_deswap_dq0 : 4;
        unsigned int data_merge_deswap_dq1 : 4;
        unsigned int data_merge_deswap_dq2 : 4;
        unsigned int data_merge_deswap_dq3 : 4;
        unsigned int data_merge_deswap_dq4 : 4;
        unsigned int data_merge_deswap_dq5 : 4;
        unsigned int data_merge_deswap_dq6 : 4;
        unsigned int data_merge_deswap_dq7 : 4;
    } reg;
} SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_UNION;
#endif
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq0_START (0)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq0_END (3)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq1_START (4)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq1_END (7)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq2_START (8)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq2_END (11)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq3_START (12)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq3_END (15)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq4_START (16)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq4_END (19)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq5_START (20)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq5_END (23)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq6_START (24)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq6_END (27)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq7_START (28)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_0_data_merge_deswap_dq7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data_merge_deswap_dq8 : 4;
        unsigned int data_merge_deswap_dq9 : 4;
        unsigned int data_merge_deswap_dq10 : 4;
        unsigned int data_merge_deswap_dq11 : 4;
        unsigned int data_merge_deswap_dq12 : 4;
        unsigned int data_merge_deswap_dq13 : 4;
        unsigned int data_merge_deswap_dq14 : 4;
        unsigned int data_merge_deswap_dq15 : 4;
    } reg;
} SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_UNION;
#endif
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq8_START (0)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq8_END (3)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq9_START (4)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq9_END (7)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq10_START (8)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq10_END (11)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq11_START (12)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq11_END (15)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq12_START (16)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq12_END (19)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq13_START (20)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq13_END (23)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq14_START (24)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq14_END (27)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq15_START (28)
#define SOC_DDR_PACK_CFG_DATA_MERGE_DESWAP_SOFT_1_data_merge_deswap_dq15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data_merge_swap_dm0 : 4;
        unsigned int data_merge_swap_dm1 : 4;
        unsigned int data_merge_deswap_dm0 : 4;
        unsigned int data_merge_deswap_dm1 : 4;
        unsigned int byte_swap_en : 1;
        unsigned int wlrl_byte_swap_en : 1;
        unsigned int cbt_ctrl_byte_swap_en : 1;
        unsigned int iocfg_dx_io_ref_swap_bypass : 1;
        unsigned int iocfg_rg_xrank_swap_bypass : 1;
        unsigned int iocfg_da_offset_swap_bypass : 1;
        unsigned int iocfg_dx_io_eq_swap_bypass : 1;
        unsigned int iocfg_da_laggingedge_swap_bypass : 1;
        unsigned int iocfg_rg_dcc_swap_bypass : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_UNION;
#endif
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_data_merge_swap_dm0_START (0)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_data_merge_swap_dm0_END (3)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_data_merge_swap_dm1_START (4)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_data_merge_swap_dm1_END (7)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_data_merge_deswap_dm0_START (8)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_data_merge_deswap_dm0_END (11)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_data_merge_deswap_dm1_START (12)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_data_merge_deswap_dm1_END (15)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_byte_swap_en_START (16)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_byte_swap_en_END (16)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_wlrl_byte_swap_en_START (17)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_wlrl_byte_swap_en_END (17)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_cbt_ctrl_byte_swap_en_START (18)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_cbt_ctrl_byte_swap_en_END (18)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_dx_io_ref_swap_bypass_START (19)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_dx_io_ref_swap_bypass_END (19)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_rg_xrank_swap_bypass_START (20)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_rg_xrank_swap_bypass_END (20)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_da_offset_swap_bypass_START (21)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_da_offset_swap_bypass_END (21)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_dx_io_eq_swap_bypass_START (22)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_dx_io_eq_swap_bypass_END (22)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_da_laggingedge_swap_bypass_START (23)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_da_laggingedge_swap_bypass_END (23)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_rg_dcc_swap_bypass_START (24)
#define SOC_DDR_PACK_CFG_DATA_MERGE_SWAP_SOFT_2_iocfg_rg_dcc_swap_bypass_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq0bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNWDQNBDL0_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQNBDL0_wdq0bdl_START (0)
#define SOC_DDR_PACK_DXNWDQNBDL0_wdq0bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq1bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNWDQNBDL1_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQNBDL1_wdq1bdl_START (0)
#define SOC_DDR_PACK_DXNWDQNBDL1_wdq1bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq2bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNWDQNBDL2_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQNBDL2_wdq2bdl_START (0)
#define SOC_DDR_PACK_DXNWDQNBDL2_wdq2bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq3bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNWDQNBDL3_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQNBDL3_wdq3bdl_START (0)
#define SOC_DDR_PACK_DXNWDQNBDL3_wdq3bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq4bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNWDQNBDL4_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQNBDL4_wdq4bdl_START (0)
#define SOC_DDR_PACK_DXNWDQNBDL4_wdq4bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq5bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNWDQNBDL5_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQNBDL5_wdq5bdl_START (0)
#define SOC_DDR_PACK_DXNWDQNBDL5_wdq5bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq6bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNWDQNBDL6_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQNBDL6_wdq6bdl_START (0)
#define SOC_DDR_PACK_DXNWDQNBDL6_wdq6bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq7bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNWDQNBDL7_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQNBDL7_wdq7bdl_START (0)
#define SOC_DDR_PACK_DXNWDQNBDL7_wdq7bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdmbdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNWDQNBDL8_UNION;
#endif
#define SOC_DDR_PACK_DXNWDQNBDL8_wdmbdl_START (0)
#define SOC_DDR_PACK_DXNWDQNBDL8_wdmbdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdq0bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNRDQNBDL0_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQNBDL0_rdq0bdl_START (0)
#define SOC_DDR_PACK_DXNRDQNBDL0_rdq0bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdq1bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNRDQNBDL1_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQNBDL1_rdq1bdl_START (0)
#define SOC_DDR_PACK_DXNRDQNBDL1_rdq1bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdq2bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNRDQNBDL2_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQNBDL2_rdq2bdl_START (0)
#define SOC_DDR_PACK_DXNRDQNBDL2_rdq2bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdq3bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNRDQNBDL3_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQNBDL3_rdq3bdl_START (0)
#define SOC_DDR_PACK_DXNRDQNBDL3_rdq3bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdq4bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNRDQNBDL4_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQNBDL4_rdq4bdl_START (0)
#define SOC_DDR_PACK_DXNRDQNBDL4_rdq4bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdq5bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNRDQNBDL5_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQNBDL5_rdq5bdl_START (0)
#define SOC_DDR_PACK_DXNRDQNBDL5_rdq5bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdq6bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNRDQNBDL6_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQNBDL6_rdq6bdl_START (0)
#define SOC_DDR_PACK_DXNRDQNBDL6_rdq6bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdq7bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNRDQNBDL7_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQNBDL7_rdq7bdl_START (0)
#define SOC_DDR_PACK_DXNRDQNBDL7_rdq7bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdmbdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DXNRDQNBDL8_UNION;
#endif
#define SOC_DDR_PACK_DXNRDQNBDL8_rdmbdl_START (0)
#define SOC_DDR_PACK_DXNRDQNBDL8_rdmbdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr0_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACADDRBDL0_UNION;
#endif
#define SOC_DDR_PACK_ACADDRBDL0_addr0_bdl_START (0)
#define SOC_DDR_PACK_ACADDRBDL0_addr0_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr1_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACADDRBDL1_UNION;
#endif
#define SOC_DDR_PACK_ACADDRBDL1_addr1_bdl_START (0)
#define SOC_DDR_PACK_ACADDRBDL1_addr1_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr2_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACADDRBDL2_UNION;
#endif
#define SOC_DDR_PACK_ACADDRBDL2_addr2_bdl_START (0)
#define SOC_DDR_PACK_ACADDRBDL2_addr2_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr3_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACADDRBDL3_UNION;
#endif
#define SOC_DDR_PACK_ACADDRBDL3_addr3_bdl_START (0)
#define SOC_DDR_PACK_ACADDRBDL3_addr3_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr4_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACADDRBDL4_UNION;
#endif
#define SOC_DDR_PACK_ACADDRBDL4_addr4_bdl_START (0)
#define SOC_DDR_PACK_ACADDRBDL4_addr4_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr5_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACADDRBDL5_UNION;
#endif
#define SOC_DDR_PACK_ACADDRBDL5_addr5_bdl_START (0)
#define SOC_DDR_PACK_ACADDRBDL5_addr5_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr6_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACADDRBDL6_UNION;
#endif
#define SOC_DDR_PACK_ACADDRBDL6_addr6_bdl_START (0)
#define SOC_DDR_PACK_ACADDRBDL6_addr6_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr7_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACADDRBDL7_UNION;
#endif
#define SOC_DDR_PACK_ACADDRBDL7_addr7_bdl_START (0)
#define SOC_DDR_PACK_ACADDRBDL7_addr7_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs0_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACCS0BDL_UNION;
#endif
#define SOC_DDR_PACK_ACCS0BDL_cs0_bdl_START (0)
#define SOC_DDR_PACK_ACCS0BDL_cs0_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs1_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACCS1BDL_UNION;
#endif
#define SOC_DDR_PACK_ACCS1BDL_cs1_bdl_START (0)
#define SOC_DDR_PACK_ACCS1BDL_cs1_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cke0_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACCKE0BDL_UNION;
#endif
#define SOC_DDR_PACK_ACCKE0BDL_cke0_bdl_START (0)
#define SOC_DDR_PACK_ACCKE0BDL_cke0_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cke1_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_ACCKE1BDL_UNION;
#endif
#define SOC_DDR_PACK_ACCKE1BDL_cke1_bdl_START (0)
#define SOC_DDR_PACK_ACCKE1BDL_cke1_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tWCKENL_WR_GE1 : 1;
        unsigned int tWCKENL_RD_GE1 : 1;
        unsigned int tWCKENL_FS_GE1 : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_PACK_WCKCTRL3_UNION;
#endif
#define SOC_DDR_PACK_WCKCTRL3_tWCKENL_WR_GE1_START (0)
#define SOC_DDR_PACK_WCKCTRL3_tWCKENL_WR_GE1_END (0)
#define SOC_DDR_PACK_WCKCTRL3_tWCKENL_RD_GE1_START (1)
#define SOC_DDR_PACK_WCKCTRL3_tWCKENL_RD_GE1_END (1)
#define SOC_DDR_PACK_WCKCTRL3_tWCKENL_FS_GE1_START (2)
#define SOC_DDR_PACK_WCKCTRL3_tWCKENL_FS_GE1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gated_byp : 1;
        unsigned int wck_gated_cs_byp : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_PACK_GATEDBYP_UNION;
#endif
#define SOC_DDR_PACK_GATEDBYP_gated_byp_START (0)
#define SOC_DDR_PACK_GATEDBYP_gated_byp_END (0)
#define SOC_DDR_PACK_GATEDBYP_wck_gated_cs_byp_START (1)
#define SOC_DDR_PACK_GATEDBYP_wck_gated_cs_byp_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bhs_clk_auto_gate_en : 1;
        unsigned int bhs_req_glitch_free_n : 1;
        unsigned int bhs_ack_h_mode : 1;
        unsigned int bhs_ack_l_mode : 1;
        unsigned int bhs_func_en : 1;
        unsigned int t_bhs_en : 1;
        unsigned int bhs_sw_mode : 1;
        unsigned int bhs_dis_req_t : 1;
        unsigned int dfi_bhs_dis_ack_t : 1;
        unsigned int bhs_req_ack_sel : 2;
        unsigned int dfi_bhs_req_sel : 2;
        unsigned int bhs_busy_en : 1;
        unsigned int bhs_ack_bit_sel : 4;
        unsigned int bhs_iso_mode : 1;
        unsigned int bhs_iso_t : 1;
        unsigned int bhs_8x_ckgn_t : 1;
        unsigned int bhs_tx_rx_en_t : 1;
        unsigned int bhs_req_neg_en : 1;
        unsigned int bhs_iso_neg_en : 1;
        unsigned int bhs_8x_ckgn_neg_en : 1;
        unsigned int bhs_tx_rx_neg_en : 1;
        unsigned int bhs_req_mode : 1;
        unsigned int bhs_iso_glitch_free_n : 1;
        unsigned int bhs_8xckgn_glitch_free : 1;
        unsigned int bhs_txrx_en_glitch_free : 1;
        unsigned int bhs_ctrl0_resv0 : 1;
        unsigned int bhs_int_msk : 1;
    } reg;
} SOC_DDR_PACK_CFG_BHS_CTRL0_UNION;
#endif
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_clk_auto_gate_en_START (0)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_clk_auto_gate_en_END (0)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_req_glitch_free_n_START (1)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_req_glitch_free_n_END (1)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_ack_h_mode_START (2)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_ack_h_mode_END (2)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_ack_l_mode_START (3)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_ack_l_mode_END (3)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_func_en_START (4)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_func_en_END (4)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_t_bhs_en_START (5)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_t_bhs_en_END (5)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_sw_mode_START (6)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_sw_mode_END (6)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_dis_req_t_START (7)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_dis_req_t_END (7)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_dfi_bhs_dis_ack_t_START (8)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_dfi_bhs_dis_ack_t_END (8)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_req_ack_sel_START (9)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_req_ack_sel_END (10)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_dfi_bhs_req_sel_START (11)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_dfi_bhs_req_sel_END (12)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_busy_en_START (13)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_busy_en_END (13)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_ack_bit_sel_START (14)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_ack_bit_sel_END (17)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_iso_mode_START (18)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_iso_mode_END (18)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_iso_t_START (19)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_iso_t_END (19)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_8x_ckgn_t_START (20)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_8x_ckgn_t_END (20)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_tx_rx_en_t_START (21)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_tx_rx_en_t_END (21)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_req_neg_en_START (22)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_req_neg_en_END (22)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_iso_neg_en_START (23)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_iso_neg_en_END (23)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_8x_ckgn_neg_en_START (24)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_8x_ckgn_neg_en_END (24)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_tx_rx_neg_en_START (25)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_tx_rx_neg_en_END (25)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_req_mode_START (26)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_req_mode_END (26)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_iso_glitch_free_n_START (27)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_iso_glitch_free_n_END (27)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_8xckgn_glitch_free_START (28)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_8xckgn_glitch_free_END (28)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_txrx_en_glitch_free_START (29)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_txrx_en_glitch_free_END (29)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_ctrl0_resv0_START (30)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_ctrl0_resv0_END (30)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_int_msk_START (31)
#define SOC_DDR_PACK_CFG_BHS_CTRL0_bhs_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bhs_ack_h_cnt_chken : 1;
        unsigned int bhs_ack_h_cnt_clr : 1;
        unsigned int bhs_ack_l_cnt_chken : 1;
        unsigned int bhs_ack_l_cnt_clr : 1;
        unsigned int dfi_bhs_req_pos_chken : 1;
        unsigned int dfi_bhs_req_pos_clr : 1;
        unsigned int dfi_bhs_ack_pos_chken : 1;
        unsigned int dfi_bhs_ack_pos_clr : 1;
        unsigned int dfi_bhs_req_neg_chken : 1;
        unsigned int dfi_bhs_req_neg_clr : 1;
        unsigned int dfi_bhs_ack_neg_chken : 1;
        unsigned int dfi_bhs_ack_neg_clr : 1;
        unsigned int bhs_req_pos_chken : 1;
        unsigned int bhs_req_pos_clr : 1;
        unsigned int bhs_ack_pos_chken : 1;
        unsigned int bhs_ack_pos_clr : 1;
        unsigned int bhs_req_neg_chken : 1;
        unsigned int bhs_req_neg_clr : 1;
        unsigned int bhs_ack_neg_chken : 1;
        unsigned int bhs_ack_neg_clr : 1;
        unsigned int bhs_ack_low_chken : 1;
        unsigned int bhs_ack_low_clr : 1;
        unsigned int dfi_bhs_req_b01_chken : 1;
        unsigned int dfi_bhs_req_b01_clr : 1;
        unsigned int bhs_req_b01_chken : 1;
        unsigned int bhs_req_b01_clr : 1;
        unsigned int clk_bhs_req_gate_en : 1;
        unsigned int clk_t_bhs_on_gate_en : 1;
        unsigned int bhs_ctrl1_resv0 : 4;
    } reg;
} SOC_DDR_PACK_CFG_BHS_CTRL1_UNION;
#endif
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_h_cnt_chken_START (0)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_h_cnt_chken_END (0)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_h_cnt_clr_START (1)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_h_cnt_clr_END (1)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_l_cnt_chken_START (2)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_l_cnt_chken_END (2)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_l_cnt_clr_START (3)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_l_cnt_clr_END (3)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_pos_chken_START (4)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_pos_chken_END (4)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_pos_clr_START (5)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_pos_clr_END (5)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_ack_pos_chken_START (6)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_ack_pos_chken_END (6)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_ack_pos_clr_START (7)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_ack_pos_clr_END (7)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_neg_chken_START (8)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_neg_chken_END (8)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_neg_clr_START (9)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_neg_clr_END (9)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_ack_neg_chken_START (10)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_ack_neg_chken_END (10)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_ack_neg_clr_START (11)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_ack_neg_clr_END (11)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_pos_chken_START (12)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_pos_chken_END (12)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_pos_clr_START (13)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_pos_clr_END (13)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_pos_chken_START (14)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_pos_chken_END (14)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_pos_clr_START (15)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_pos_clr_END (15)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_neg_chken_START (16)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_neg_chken_END (16)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_neg_clr_START (17)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_neg_clr_END (17)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_neg_chken_START (18)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_neg_chken_END (18)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_neg_clr_START (19)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_neg_clr_END (19)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_low_chken_START (20)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_low_chken_END (20)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_low_clr_START (21)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ack_low_clr_END (21)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_b01_chken_START (22)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_b01_chken_END (22)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_b01_clr_START (23)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_dfi_bhs_req_b01_clr_END (23)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_b01_chken_START (24)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_b01_chken_END (24)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_b01_clr_START (25)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_req_b01_clr_END (25)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_clk_bhs_req_gate_en_START (26)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_clk_bhs_req_gate_en_END (26)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_clk_t_bhs_on_gate_en_START (27)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_clk_t_bhs_on_gate_en_END (27)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ctrl1_resv0_START (28)
#define SOC_DDR_PACK_CFG_BHS_CTRL1_bhs_ctrl1_resv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfi_bhs_dis_ack_pos_dly : 8;
        unsigned int dfi_bhs_dis_ack_neg_dly : 8;
        unsigned int bhs_iso_neg_dly : 8;
        unsigned int bhs_req_pos_dly : 8;
    } reg;
} SOC_DDR_PACK_CFG_BHS_ACK_DLY_UNION;
#endif
#define SOC_DDR_PACK_CFG_BHS_ACK_DLY_dfi_bhs_dis_ack_pos_dly_START (0)
#define SOC_DDR_PACK_CFG_BHS_ACK_DLY_dfi_bhs_dis_ack_pos_dly_END (7)
#define SOC_DDR_PACK_CFG_BHS_ACK_DLY_dfi_bhs_dis_ack_neg_dly_START (8)
#define SOC_DDR_PACK_CFG_BHS_ACK_DLY_dfi_bhs_dis_ack_neg_dly_END (15)
#define SOC_DDR_PACK_CFG_BHS_ACK_DLY_bhs_iso_neg_dly_START (16)
#define SOC_DDR_PACK_CFG_BHS_ACK_DLY_bhs_iso_neg_dly_END (23)
#define SOC_DDR_PACK_CFG_BHS_ACK_DLY_bhs_req_pos_dly_START (24)
#define SOC_DDR_PACK_CFG_BHS_ACK_DLY_bhs_req_pos_dly_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfi_bhs_dis_req : 1;
        unsigned int dfi_bhs_dis_ack : 1;
        unsigned int bhs_dis_req : 1;
        unsigned int h_all_bit_pwroff_ack : 1;
        unsigned int l_all_bit_pwron_ack : 1;
        unsigned int t_bhs_on_finish_all : 1;
        unsigned int err_bhs_ack_h_cnt : 1;
        unsigned int err_bhs_ack_l_cnt : 1;
        unsigned int err_dfi_bhs_req_pos : 1;
        unsigned int err_dfi_bhs_ack_pos : 1;
        unsigned int err_dfi_bhs_req_neg : 1;
        unsigned int err_dfi_bhs_ack_neg : 1;
        unsigned int err_bhs_req_pos_phy : 1;
        unsigned int err_bhs_ack_pos_phy : 1;
        unsigned int err_bhs_req_neg_phy : 1;
        unsigned int err_bhs_ack_neg_phy : 1;
        unsigned int err_bhs_ack_low : 1;
        unsigned int err_dfi_bhs_req_b01 : 1;
        unsigned int bhs_busy : 1;
        unsigned int bhs_iso : 1;
        unsigned int err_bhs_req_b01 : 1;
        unsigned int bhs_cnt_busy : 1;
        unsigned int reserved : 4;
        unsigned int efuse_info : 5;
        unsigned int bhs_error : 1;
    } reg;
} SOC_DDR_PACK_T_BHS_STATUS_UNION;
#endif
#define SOC_DDR_PACK_T_BHS_STATUS_dfi_bhs_dis_req_START (0)
#define SOC_DDR_PACK_T_BHS_STATUS_dfi_bhs_dis_req_END (0)
#define SOC_DDR_PACK_T_BHS_STATUS_dfi_bhs_dis_ack_START (1)
#define SOC_DDR_PACK_T_BHS_STATUS_dfi_bhs_dis_ack_END (1)
#define SOC_DDR_PACK_T_BHS_STATUS_bhs_dis_req_START (2)
#define SOC_DDR_PACK_T_BHS_STATUS_bhs_dis_req_END (2)
#define SOC_DDR_PACK_T_BHS_STATUS_h_all_bit_pwroff_ack_START (3)
#define SOC_DDR_PACK_T_BHS_STATUS_h_all_bit_pwroff_ack_END (3)
#define SOC_DDR_PACK_T_BHS_STATUS_l_all_bit_pwron_ack_START (4)
#define SOC_DDR_PACK_T_BHS_STATUS_l_all_bit_pwron_ack_END (4)
#define SOC_DDR_PACK_T_BHS_STATUS_t_bhs_on_finish_all_START (5)
#define SOC_DDR_PACK_T_BHS_STATUS_t_bhs_on_finish_all_END (5)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_ack_h_cnt_START (6)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_ack_h_cnt_END (6)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_ack_l_cnt_START (7)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_ack_l_cnt_END (7)
#define SOC_DDR_PACK_T_BHS_STATUS_err_dfi_bhs_req_pos_START (8)
#define SOC_DDR_PACK_T_BHS_STATUS_err_dfi_bhs_req_pos_END (8)
#define SOC_DDR_PACK_T_BHS_STATUS_err_dfi_bhs_ack_pos_START (9)
#define SOC_DDR_PACK_T_BHS_STATUS_err_dfi_bhs_ack_pos_END (9)
#define SOC_DDR_PACK_T_BHS_STATUS_err_dfi_bhs_req_neg_START (10)
#define SOC_DDR_PACK_T_BHS_STATUS_err_dfi_bhs_req_neg_END (10)
#define SOC_DDR_PACK_T_BHS_STATUS_err_dfi_bhs_ack_neg_START (11)
#define SOC_DDR_PACK_T_BHS_STATUS_err_dfi_bhs_ack_neg_END (11)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_req_pos_phy_START (12)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_req_pos_phy_END (12)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_ack_pos_phy_START (13)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_ack_pos_phy_END (13)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_req_neg_phy_START (14)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_req_neg_phy_END (14)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_ack_neg_phy_START (15)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_ack_neg_phy_END (15)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_ack_low_START (16)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_ack_low_END (16)
#define SOC_DDR_PACK_T_BHS_STATUS_err_dfi_bhs_req_b01_START (17)
#define SOC_DDR_PACK_T_BHS_STATUS_err_dfi_bhs_req_b01_END (17)
#define SOC_DDR_PACK_T_BHS_STATUS_bhs_busy_START (18)
#define SOC_DDR_PACK_T_BHS_STATUS_bhs_busy_END (18)
#define SOC_DDR_PACK_T_BHS_STATUS_bhs_iso_START (19)
#define SOC_DDR_PACK_T_BHS_STATUS_bhs_iso_END (19)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_req_b01_START (20)
#define SOC_DDR_PACK_T_BHS_STATUS_err_bhs_req_b01_END (20)
#define SOC_DDR_PACK_T_BHS_STATUS_bhs_cnt_busy_START (21)
#define SOC_DDR_PACK_T_BHS_STATUS_bhs_cnt_busy_END (21)
#define SOC_DDR_PACK_T_BHS_STATUS_efuse_info_START (26)
#define SOC_DDR_PACK_T_BHS_STATUS_efuse_info_END (30)
#define SOC_DDR_PACK_T_BHS_STATUS_bhs_error_START (31)
#define SOC_DDR_PACK_T_BHS_STATUS_bhs_error_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_bhs_on_b00 : 8;
        unsigned int t_bhs_on_b01 : 8;
        unsigned int t_bhs_on_b02 : 8;
        unsigned int t_bhs_on_b03 : 8;
    } reg;
} SOC_DDR_PACK_T_BHS_ON_B0_V0_UNION;
#endif
#define SOC_DDR_PACK_T_BHS_ON_B0_V0_t_bhs_on_b00_START (0)
#define SOC_DDR_PACK_T_BHS_ON_B0_V0_t_bhs_on_b00_END (7)
#define SOC_DDR_PACK_T_BHS_ON_B0_V0_t_bhs_on_b01_START (8)
#define SOC_DDR_PACK_T_BHS_ON_B0_V0_t_bhs_on_b01_END (15)
#define SOC_DDR_PACK_T_BHS_ON_B0_V0_t_bhs_on_b02_START (16)
#define SOC_DDR_PACK_T_BHS_ON_B0_V0_t_bhs_on_b02_END (23)
#define SOC_DDR_PACK_T_BHS_ON_B0_V0_t_bhs_on_b03_START (24)
#define SOC_DDR_PACK_T_BHS_ON_B0_V0_t_bhs_on_b03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_bhs_on_b04 : 8;
        unsigned int t_bhs_on_b05 : 8;
        unsigned int t_bhs_on_b06 : 8;
        unsigned int t_bhs_on_b07 : 8;
    } reg;
} SOC_DDR_PACK_T_BHS_ON_B0_V1_UNION;
#endif
#define SOC_DDR_PACK_T_BHS_ON_B0_V1_t_bhs_on_b04_START (0)
#define SOC_DDR_PACK_T_BHS_ON_B0_V1_t_bhs_on_b04_END (7)
#define SOC_DDR_PACK_T_BHS_ON_B0_V1_t_bhs_on_b05_START (8)
#define SOC_DDR_PACK_T_BHS_ON_B0_V1_t_bhs_on_b05_END (15)
#define SOC_DDR_PACK_T_BHS_ON_B0_V1_t_bhs_on_b06_START (16)
#define SOC_DDR_PACK_T_BHS_ON_B0_V1_t_bhs_on_b06_END (23)
#define SOC_DDR_PACK_T_BHS_ON_B0_V1_t_bhs_on_b07_START (24)
#define SOC_DDR_PACK_T_BHS_ON_B0_V1_t_bhs_on_b07_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_bhs_on_b08 : 8;
        unsigned int t_bhs_on_b09 : 8;
        unsigned int t_bhs_on_b0a : 8;
        unsigned int t_bhs_on_b0b : 8;
    } reg;
} SOC_DDR_PACK_T_BHS_ON_B0_V2_UNION;
#endif
#define SOC_DDR_PACK_T_BHS_ON_B0_V2_t_bhs_on_b08_START (0)
#define SOC_DDR_PACK_T_BHS_ON_B0_V2_t_bhs_on_b08_END (7)
#define SOC_DDR_PACK_T_BHS_ON_B0_V2_t_bhs_on_b09_START (8)
#define SOC_DDR_PACK_T_BHS_ON_B0_V2_t_bhs_on_b09_END (15)
#define SOC_DDR_PACK_T_BHS_ON_B0_V2_t_bhs_on_b0a_START (16)
#define SOC_DDR_PACK_T_BHS_ON_B0_V2_t_bhs_on_b0a_END (23)
#define SOC_DDR_PACK_T_BHS_ON_B0_V2_t_bhs_on_b0b_START (24)
#define SOC_DDR_PACK_T_BHS_ON_B0_V2_t_bhs_on_b0b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_wren_dq_rank_delay : 2;
        unsigned int cfg_bpg_cbt : 1;
        unsigned int cfg_bpg_lpbk_dx : 1;
        unsigned int cfg_bpg_lpbk_ac : 1;
        unsigned int cfg_byte_lpbk_dx0_to_dx1 : 1;
        unsigned int cfg_byte_lpbk_dx1_to_dx0 : 1;
        unsigned int cfg_bpg_dfitrans_off : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_PACK_HIPACK_BPG_CFG_UNION;
#endif
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_wren_dq_rank_delay_START (0)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_wren_dq_rank_delay_END (1)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_bpg_cbt_START (2)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_bpg_cbt_END (2)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_bpg_lpbk_dx_START (3)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_bpg_lpbk_dx_END (3)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_bpg_lpbk_ac_START (4)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_bpg_lpbk_ac_END (4)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_byte_lpbk_dx0_to_dx1_START (5)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_byte_lpbk_dx0_to_dx1_END (5)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_byte_lpbk_dx1_to_dx0_START (6)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_byte_lpbk_dx1_to_dx0_END (6)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_bpg_dfitrans_off_START (7)
#define SOC_DDR_PACK_HIPACK_BPG_CFG_cfg_bpg_dfitrans_off_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_plldis_timer0 : 22;
        unsigned int icfg_plldis_clksw_sel_keep : 1;
        unsigned int icfg_plldis_auto_gt_bypass : 1;
        unsigned int icfg_plldis_bypass : 1;
        unsigned int icfg_plldis_lp_ack_0_mask : 1;
        unsigned int icfg_plldis_lp_ack_1_mask : 1;
        unsigned int icfg_plldis_rst_flow_bypass : 1;
        unsigned int icfg_gt_clk_pack_plldis : 1;
        unsigned int icfg_ip_rst_pack_plldis : 1;
        unsigned int icfg_plldis_b_soft_ctrl : 1;
        unsigned int icfg_plldis_a_soft_ctrl : 1;
    } reg;
} SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_UNION;
#endif
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_timer0_START (0)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_timer0_END (21)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_clksw_sel_keep_START (22)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_clksw_sel_keep_END (22)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_auto_gt_bypass_START (23)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_auto_gt_bypass_END (23)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_bypass_START (24)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_bypass_END (24)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_lp_ack_0_mask_START (25)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_lp_ack_0_mask_END (25)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_lp_ack_1_mask_START (26)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_lp_ack_1_mask_END (26)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_rst_flow_bypass_START (27)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_rst_flow_bypass_END (27)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_gt_clk_pack_plldis_START (28)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_gt_clk_pack_plldis_END (28)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_ip_rst_pack_plldis_START (29)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_ip_rst_pack_plldis_END (29)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_b_soft_ctrl_START (30)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_b_soft_ctrl_END (30)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_a_soft_ctrl_START (31)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG0_icfg_plldis_a_soft_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_plldis_timer1_clksw_sys : 8;
        unsigned int icfg_plldis_timer1_clksw_dfi : 8;
        unsigned int icfg_plla_pllb_sel : 1;
        unsigned int icfg_plldis_clksw_ctrl_bypass : 1;
        unsigned int icfg_bhs_busy_to_plldis_mask : 1;
        unsigned int icfg_clk_sw_busy_sel : 1;
        unsigned int icfg_plla_pllb_sel_en : 1;
        unsigned int plldis_st_busy : 1;
        unsigned int pllb_ad_kband_compete : 1;
        unsigned int pllb_lp_req : 1;
        unsigned int plla_ad_kband_compete : 1;
        unsigned int plla_lp_req : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_UNION;
#endif
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_plldis_timer1_clksw_sys_START (0)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_plldis_timer1_clksw_sys_END (7)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_plldis_timer1_clksw_dfi_START (8)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_plldis_timer1_clksw_dfi_END (15)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_plla_pllb_sel_START (16)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_plla_pllb_sel_END (16)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_plldis_clksw_ctrl_bypass_START (17)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_plldis_clksw_ctrl_bypass_END (17)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_bhs_busy_to_plldis_mask_START (18)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_bhs_busy_to_plldis_mask_END (18)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_clk_sw_busy_sel_START (19)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_clk_sw_busy_sel_END (19)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_plla_pllb_sel_en_START (20)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_icfg_plla_pllb_sel_en_END (20)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_plldis_st_busy_START (21)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_plldis_st_busy_END (21)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_pllb_ad_kband_compete_START (22)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_pllb_ad_kband_compete_END (22)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_pllb_lp_req_START (23)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_pllb_lp_req_END (23)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_plla_ad_kband_compete_START (24)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_plla_ad_kband_compete_END (24)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_plla_lp_req_START (25)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG1_plla_lp_req_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_plldis_timer2_pllon : 8;
        unsigned int icfg_plldis_timer2_plldis : 8;
        unsigned int icfg_plldis_timer2_rst_sync : 8;
        unsigned int icfg_plldis_timer2_gck_sync : 8;
    } reg;
} SOC_DDR_PACK_HIPACK_PLLDIS_CFG2_UNION;
#endif
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG2_icfg_plldis_timer2_pllon_START (0)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG2_icfg_plldis_timer2_pllon_END (7)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG2_icfg_plldis_timer2_plldis_START (8)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG2_icfg_plldis_timer2_plldis_END (15)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG2_icfg_plldis_timer2_rst_sync_START (16)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG2_icfg_plldis_timer2_rst_sync_END (23)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG2_icfg_plldis_timer2_gck_sync_START (24)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG2_icfg_plldis_timer2_gck_sync_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_rtp_ext : 1;
        unsigned int t_wtr_ext : 1;
        unsigned int t_rp_ext : 7;
        unsigned int t_rcd_ext : 3;
        unsigned int t_ras_ext : 2;
        unsigned int t_rc_ext : 6;
        unsigned int t_rfc_ext : 3;
        unsigned int t_faw_ext : 2;
        unsigned int t_init5_ext : 2;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_PACK_DRAMTIMER6_UNION;
#endif
#define SOC_DDR_PACK_DRAMTIMER6_t_rtp_ext_START (0)
#define SOC_DDR_PACK_DRAMTIMER6_t_rtp_ext_END (0)
#define SOC_DDR_PACK_DRAMTIMER6_t_wtr_ext_START (1)
#define SOC_DDR_PACK_DRAMTIMER6_t_wtr_ext_END (1)
#define SOC_DDR_PACK_DRAMTIMER6_t_rp_ext_START (2)
#define SOC_DDR_PACK_DRAMTIMER6_t_rp_ext_END (8)
#define SOC_DDR_PACK_DRAMTIMER6_t_rcd_ext_START (9)
#define SOC_DDR_PACK_DRAMTIMER6_t_rcd_ext_END (11)
#define SOC_DDR_PACK_DRAMTIMER6_t_ras_ext_START (12)
#define SOC_DDR_PACK_DRAMTIMER6_t_ras_ext_END (13)
#define SOC_DDR_PACK_DRAMTIMER6_t_rc_ext_START (14)
#define SOC_DDR_PACK_DRAMTIMER6_t_rc_ext_END (19)
#define SOC_DDR_PACK_DRAMTIMER6_t_rfc_ext_START (20)
#define SOC_DDR_PACK_DRAMTIMER6_t_rfc_ext_END (22)
#define SOC_DDR_PACK_DRAMTIMER6_t_faw_ext_START (23)
#define SOC_DDR_PACK_DRAMTIMER6_t_faw_ext_END (24)
#define SOC_DDR_PACK_DRAMTIMER6_t_init5_ext_START (25)
#define SOC_DDR_PACK_DRAMTIMER6_t_init5_ext_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_bhs_on_b10 : 8;
        unsigned int t_bhs_on_b11 : 8;
        unsigned int t_bhs_on_b12 : 8;
        unsigned int t_bhs_on_b13 : 8;
    } reg;
} SOC_DDR_PACK_T_BHS_ON_B1_V0_UNION;
#endif
#define SOC_DDR_PACK_T_BHS_ON_B1_V0_t_bhs_on_b10_START (0)
#define SOC_DDR_PACK_T_BHS_ON_B1_V0_t_bhs_on_b10_END (7)
#define SOC_DDR_PACK_T_BHS_ON_B1_V0_t_bhs_on_b11_START (8)
#define SOC_DDR_PACK_T_BHS_ON_B1_V0_t_bhs_on_b11_END (15)
#define SOC_DDR_PACK_T_BHS_ON_B1_V0_t_bhs_on_b12_START (16)
#define SOC_DDR_PACK_T_BHS_ON_B1_V0_t_bhs_on_b12_END (23)
#define SOC_DDR_PACK_T_BHS_ON_B1_V0_t_bhs_on_b13_START (24)
#define SOC_DDR_PACK_T_BHS_ON_B1_V0_t_bhs_on_b13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_bhs_on_b14 : 8;
        unsigned int t_bhs_on_b15 : 8;
        unsigned int t_bhs_on_b16 : 8;
        unsigned int t_bhs_on_b17 : 8;
    } reg;
} SOC_DDR_PACK_T_BHS_ON_B1_V1_UNION;
#endif
#define SOC_DDR_PACK_T_BHS_ON_B1_V1_t_bhs_on_b14_START (0)
#define SOC_DDR_PACK_T_BHS_ON_B1_V1_t_bhs_on_b14_END (7)
#define SOC_DDR_PACK_T_BHS_ON_B1_V1_t_bhs_on_b15_START (8)
#define SOC_DDR_PACK_T_BHS_ON_B1_V1_t_bhs_on_b15_END (15)
#define SOC_DDR_PACK_T_BHS_ON_B1_V1_t_bhs_on_b16_START (16)
#define SOC_DDR_PACK_T_BHS_ON_B1_V1_t_bhs_on_b16_END (23)
#define SOC_DDR_PACK_T_BHS_ON_B1_V1_t_bhs_on_b17_START (24)
#define SOC_DDR_PACK_T_BHS_ON_B1_V1_t_bhs_on_b17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_bhs_on_b18 : 8;
        unsigned int t_bhs_on_b19 : 8;
        unsigned int t_bhs_on_b1a : 8;
        unsigned int t_bhs_on_b1b : 8;
    } reg;
} SOC_DDR_PACK_T_BHS_ON_B1_V2_UNION;
#endif
#define SOC_DDR_PACK_T_BHS_ON_B1_V2_t_bhs_on_b18_START (0)
#define SOC_DDR_PACK_T_BHS_ON_B1_V2_t_bhs_on_b18_END (7)
#define SOC_DDR_PACK_T_BHS_ON_B1_V2_t_bhs_on_b19_START (8)
#define SOC_DDR_PACK_T_BHS_ON_B1_V2_t_bhs_on_b19_END (15)
#define SOC_DDR_PACK_T_BHS_ON_B1_V2_t_bhs_on_b1a_START (16)
#define SOC_DDR_PACK_T_BHS_ON_B1_V2_t_bhs_on_b1a_END (23)
#define SOC_DDR_PACK_T_BHS_ON_B1_V2_t_bhs_on_b1b_START (24)
#define SOC_DDR_PACK_T_BHS_ON_B1_V2_t_bhs_on_b1b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_bhs_on_max : 8;
        unsigned int t_bhs_on_min : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PACK_T_BHS_ON_MAX_MIN_UNION;
#endif
#define SOC_DDR_PACK_T_BHS_ON_MAX_MIN_t_bhs_on_max_START (0)
#define SOC_DDR_PACK_T_BHS_ON_MAX_MIN_t_bhs_on_max_END (7)
#define SOC_DDR_PACK_T_BHS_ON_MAX_MIN_t_bhs_on_min_START (8)
#define SOC_DDR_PACK_T_BHS_ON_MAX_MIN_t_bhs_on_min_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bhs_txrx_en_neg_dly : 8;
        unsigned int bhs_txrx_en_pos_dly : 8;
        unsigned int bhs_8x_ckgn_pos_dly : 8;
        unsigned int bhs_dly1_resv0 : 8;
    } reg;
} SOC_DDR_PACK_CFG_BHS_DLY1_UNION;
#endif
#define SOC_DDR_PACK_CFG_BHS_DLY1_bhs_txrx_en_neg_dly_START (0)
#define SOC_DDR_PACK_CFG_BHS_DLY1_bhs_txrx_en_neg_dly_END (7)
#define SOC_DDR_PACK_CFG_BHS_DLY1_bhs_txrx_en_pos_dly_START (8)
#define SOC_DDR_PACK_CFG_BHS_DLY1_bhs_txrx_en_pos_dly_END (15)
#define SOC_DDR_PACK_CFG_BHS_DLY1_bhs_8x_ckgn_pos_dly_START (16)
#define SOC_DDR_PACK_CFG_BHS_DLY1_bhs_8x_ckgn_pos_dly_END (23)
#define SOC_DDR_PACK_CFG_BHS_DLY1_bhs_dly1_resv0_START (24)
#define SOC_DDR_PACK_CFG_BHS_DLY1_bhs_dly1_resv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bhs_dly2_resv0 : 8;
        unsigned int bhs_dly2_resv1 : 8;
        unsigned int bhs_dly2_resv2 : 8;
        unsigned int bhs_dly2_resv3 : 8;
    } reg;
} SOC_DDR_PACK_CFG_BHS_DLY2_UNION;
#endif
#define SOC_DDR_PACK_CFG_BHS_DLY2_bhs_dly2_resv0_START (0)
#define SOC_DDR_PACK_CFG_BHS_DLY2_bhs_dly2_resv0_END (7)
#define SOC_DDR_PACK_CFG_BHS_DLY2_bhs_dly2_resv1_START (8)
#define SOC_DDR_PACK_CFG_BHS_DLY2_bhs_dly2_resv1_END (15)
#define SOC_DDR_PACK_CFG_BHS_DLY2_bhs_dly2_resv2_START (16)
#define SOC_DDR_PACK_CFG_BHS_DLY2_bhs_dly2_resv2_END (23)
#define SOC_DDR_PACK_CFG_BHS_DLY2_bhs_dly2_resv3_START (24)
#define SOC_DDR_PACK_CFG_BHS_DLY2_bhs_dly2_resv3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tracking_timer_cfg : 8;
        unsigned int tracking_latch_bypass : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_PACK_TRACKING_LATCH_EXT_UNION;
#endif
#define SOC_DDR_PACK_TRACKING_LATCH_EXT_tracking_timer_cfg_START (0)
#define SOC_DDR_PACK_TRACKING_LATCH_EXT_tracking_timer_cfg_END (7)
#define SOC_DDR_PACK_TRACKING_LATCH_EXT_tracking_latch_bypass_START (8)
#define SOC_DDR_PACK_TRACKING_LATCH_EXT_tracking_latch_bypass_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_plldis_spread_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_PACK_HIPACK_PLLDIS_CFG3_UNION;
#endif
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG3_icfg_plldis_spread_cnt_START (0)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG3_icfg_plldis_spread_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int srefpd_plldis_acc_cnt : 32;
    } reg;
} SOC_DDR_PACK_HIPACK_PLLDIS_CFG4_UNION;
#endif
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG4_srefpd_plldis_acc_cnt_START (0)
#define SOC_DDR_PACK_HIPACK_PLLDIS_CFG4_srefpd_plldis_acc_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_ccd_s_ext : 2;
        unsigned int t_ccd_s_lp5_ext : 2;
        unsigned int t_ccd_x_lp5_ext : 2;
        unsigned int t_ccd_ddr4_ext : 2;
        unsigned int t_rrd_ext : 1;
        unsigned int t_cke_ext : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_DRAMTIMER7_UNION;
#endif
#define SOC_DDR_PACK_DRAMTIMER7_t_ccd_s_ext_START (0)
#define SOC_DDR_PACK_DRAMTIMER7_t_ccd_s_ext_END (1)
#define SOC_DDR_PACK_DRAMTIMER7_t_ccd_s_lp5_ext_START (2)
#define SOC_DDR_PACK_DRAMTIMER7_t_ccd_s_lp5_ext_END (3)
#define SOC_DDR_PACK_DRAMTIMER7_t_ccd_x_lp5_ext_START (4)
#define SOC_DDR_PACK_DRAMTIMER7_t_ccd_x_lp5_ext_END (5)
#define SOC_DDR_PACK_DRAMTIMER7_t_ccd_ddr4_ext_START (6)
#define SOC_DDR_PACK_DRAMTIMER7_t_ccd_ddr4_ext_END (7)
#define SOC_DDR_PACK_DRAMTIMER7_t_rrd_ext_START (8)
#define SOC_DDR_PACK_DRAMTIMER7_t_rrd_ext_END (8)
#define SOC_DDR_PACK_DRAMTIMER7_t_cke_ext_START (9)
#define SOC_DDR_PACK_DRAMTIMER7_t_cke_ext_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlm_swift_trk_en_new_old_auto_update_apbauto_n : 1;
        unsigned int dlm_da_bdl_tst_en_clr_en : 1;
        unsigned int ip_rst_dlm : 1;
        unsigned int dlm_cnt_en_sync : 1;
        unsigned int dlm_da_dlm_div : 4;
        unsigned int dlm_da_bdl_bin_code : 10;
        unsigned int dlm_da_bdl_tst_en : 1;
        unsigned int dlm_da_rdqs_tst_en : 1;
        unsigned int dlm_cnt_en : 1;
        unsigned int dlm_cnt_num : 11;
    } reg;
} SOC_DDR_PACK_DLM_TOP_CTRL_UNION;
#endif
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_swift_trk_en_new_old_auto_update_apbauto_n_START (0)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_swift_trk_en_new_old_auto_update_apbauto_n_END (0)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_da_bdl_tst_en_clr_en_START (1)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_da_bdl_tst_en_clr_en_END (1)
#define SOC_DDR_PACK_DLM_TOP_CTRL_ip_rst_dlm_START (2)
#define SOC_DDR_PACK_DLM_TOP_CTRL_ip_rst_dlm_END (2)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_cnt_en_sync_START (3)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_cnt_en_sync_END (3)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_da_dlm_div_START (4)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_da_dlm_div_END (7)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_da_bdl_bin_code_START (8)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_da_bdl_bin_code_END (17)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_da_bdl_tst_en_START (18)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_da_bdl_tst_en_END (18)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_da_rdqs_tst_en_START (19)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_da_rdqs_tst_en_END (19)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_cnt_en_START (20)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_cnt_en_END (20)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_cnt_num_START (21)
#define SOC_DDR_PACK_DLM_TOP_CTRL_dlm_cnt_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlm_cout : 17;
        unsigned int dlm_cout_done : 1;
        unsigned int ad_dlm_ck_en : 1;
        unsigned int dlm_rdet_track_bdl_thermo_code : 12;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_PACK_DLM_TOP_DATAOUT_UNION;
#endif
#define SOC_DDR_PACK_DLM_TOP_DATAOUT_dlm_cout_START (0)
#define SOC_DDR_PACK_DLM_TOP_DATAOUT_dlm_cout_END (16)
#define SOC_DDR_PACK_DLM_TOP_DATAOUT_dlm_cout_done_START (17)
#define SOC_DDR_PACK_DLM_TOP_DATAOUT_dlm_cout_done_END (17)
#define SOC_DDR_PACK_DLM_TOP_DATAOUT_ad_dlm_ck_en_START (18)
#define SOC_DDR_PACK_DLM_TOP_DATAOUT_ad_dlm_ck_en_END (18)
#define SOC_DDR_PACK_DLM_TOP_DATAOUT_dlm_rdet_track_bdl_thermo_code_START (19)
#define SOC_DDR_PACK_DLM_TOP_DATAOUT_dlm_rdet_track_bdl_thermo_code_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlm_cyc_len : 16;
        unsigned int dlm_cyc_en : 1;
        unsigned int dlm_swift_trk_en_new_old_auto_update : 1;
        unsigned int first_dlm_update_req_clr_th_rd_n : 1;
        unsigned int first_dlm_result_old_from_new_in_swift_trk : 1;
        unsigned int dlm_result_clr : 1;
        unsigned int less_than_low_threshold_clr_irq_en : 1;
        unsigned int reserved : 2;
        unsigned int dlm_update_req_swift_trk_cnt : 8;
    } reg;
} SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_UNION;
#endif
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_dlm_cyc_len_START (0)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_dlm_cyc_len_END (15)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_dlm_cyc_en_START (16)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_dlm_cyc_en_END (16)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_dlm_swift_trk_en_new_old_auto_update_START (17)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_dlm_swift_trk_en_new_old_auto_update_END (17)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_first_dlm_update_req_clr_th_rd_n_START (18)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_first_dlm_update_req_clr_th_rd_n_END (18)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_first_dlm_result_old_from_new_in_swift_trk_START (19)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_first_dlm_result_old_from_new_in_swift_trk_END (19)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_dlm_result_clr_START (20)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_dlm_result_clr_END (20)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_less_than_low_threshold_clr_irq_en_START (21)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_less_than_low_threshold_clr_irq_en_END (21)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_dlm_update_req_swift_trk_cnt_START (24)
#define SOC_DDR_PACK_DLM_SWIFT_TRK_CTRL_dlm_update_req_swift_trk_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlm_result_threshold : 17;
        unsigned int first_dlm_exam_done_in_swift_trk : 1;
        unsigned int reserved_0 : 2;
        unsigned int dlm_result_low_threshold : 8;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_PACK_DLM_RESULT_THRESHOLD_SWIFT_TRK_UNION;
#endif
#define SOC_DDR_PACK_DLM_RESULT_THRESHOLD_SWIFT_TRK_dlm_result_threshold_START (0)
#define SOC_DDR_PACK_DLM_RESULT_THRESHOLD_SWIFT_TRK_dlm_result_threshold_END (16)
#define SOC_DDR_PACK_DLM_RESULT_THRESHOLD_SWIFT_TRK_first_dlm_exam_done_in_swift_trk_START (17)
#define SOC_DDR_PACK_DLM_RESULT_THRESHOLD_SWIFT_TRK_first_dlm_exam_done_in_swift_trk_END (17)
#define SOC_DDR_PACK_DLM_RESULT_THRESHOLD_SWIFT_TRK_dlm_result_low_threshold_START (20)
#define SOC_DDR_PACK_DLM_RESULT_THRESHOLD_SWIFT_TRK_dlm_result_low_threshold_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlm_result_new : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_DDR_PACK_DLM_RESULT_NEW_SWIFT_TRK_UNION;
#endif
#define SOC_DDR_PACK_DLM_RESULT_NEW_SWIFT_TRK_dlm_result_new_START (0)
#define SOC_DDR_PACK_DLM_RESULT_NEW_SWIFT_TRK_dlm_result_new_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlm_result_old : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_DDR_PACK_DLM_RESULT_OLD_SWIFT_TRK_UNION;
#endif
#define SOC_DDR_PACK_DLM_RESULT_OLD_SWIFT_TRK_dlm_result_old_START (0)
#define SOC_DDR_PACK_DLM_RESULT_OLD_SWIFT_TRK_dlm_result_old_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swift_trk_en : 1;
        unsigned int swift_trk_soft_rst : 1;
        unsigned int swift_trk_gt_rdet_rst_req : 1;
        unsigned int swift_trk_phy_upd_req : 1;
        unsigned int swift_trk_phy_upd_done : 1;
        unsigned int swift_trk_bdl_upd_req : 1;
        unsigned int swift_trk_sw_pd_entry_req : 1;
        unsigned int swift_trk_sw_pd_exit_req : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_UNION;
#endif
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_en_START (0)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_en_END (0)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_soft_rst_START (1)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_soft_rst_END (1)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_gt_rdet_rst_req_START (2)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_gt_rdet_rst_req_END (2)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_phy_upd_req_START (3)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_phy_upd_req_END (3)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_phy_upd_done_START (4)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_phy_upd_done_END (4)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_bdl_upd_req_START (5)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_bdl_upd_req_END (5)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_sw_pd_entry_req_START (6)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_sw_pd_entry_req_END (6)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_sw_pd_exit_req_START (7)
#define SOC_DDR_PACK_SWIFT_TRK_DYN_CFG_swift_trk_sw_pd_exit_req_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swift_trk_req_auto_clr_en : 1;
        unsigned int swift_trk_gt_latch_en : 1;
        unsigned int swift_trk_gt_latch_delay : 2;
        unsigned int swift_trk_gt_filter_win : 4;
        unsigned int swift_trk_gt_filter_mode : 1;
        unsigned int swift_trk_gt_valid_bypass : 1;
        unsigned int swift_trk_dig_rst_en : 1;
        unsigned int swift_trk_rst_wait_time : 5;
        unsigned int swift_trk_dbg_sel : 3;
        unsigned int swift_trk_pd_pack_sel_en : 1;
        unsigned int swift_trk_dfx_en : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_DDR_PACK_SWIFT_TRK_ST_CFG_UNION;
#endif
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_req_auto_clr_en_START (0)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_req_auto_clr_en_END (0)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_gt_latch_en_START (1)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_gt_latch_en_END (1)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_gt_latch_delay_START (2)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_gt_latch_delay_END (3)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_gt_filter_win_START (4)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_gt_filter_win_END (7)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_gt_filter_mode_START (8)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_gt_filter_mode_END (8)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_gt_valid_bypass_START (9)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_gt_valid_bypass_END (9)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_dig_rst_en_START (10)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_dig_rst_en_END (10)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_rst_wait_time_START (11)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_rst_wait_time_END (15)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_dbg_sel_START (16)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_dbg_sel_END (18)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_pd_pack_sel_en_START (19)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_pd_pack_sel_en_END (19)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_dfx_en_START (20)
#define SOC_DDR_PACK_SWIFT_TRK_ST_CFG_swift_trk_dfx_en_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swift_trk_gt_upd_req : 4;
        unsigned int swift_trk_rdet_upd_req : 4;
        unsigned int swift_trk_dlm_upd_req : 1;
        unsigned int swift_trk_gt_upd_req_or : 1;
        unsigned int swift_trk_rdet_upd_req_or : 1;
        unsigned int swift_trk_bdl_upd_err_int : 1;
        unsigned int swift_trk_bdl_upd_ovf_int : 1;
        unsigned int swift_trk_bdl_upd_noact_int : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_UNION;
#endif
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_gt_upd_req_START (0)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_gt_upd_req_END (3)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_rdet_upd_req_START (4)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_rdet_upd_req_END (7)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_dlm_upd_req_START (8)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_dlm_upd_req_END (8)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_gt_upd_req_or_START (9)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_gt_upd_req_or_END (9)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_rdet_upd_req_or_START (10)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_rdet_upd_req_or_END (10)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_bdl_upd_err_int_START (11)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_bdl_upd_err_int_END (11)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_bdl_upd_ovf_int_START (12)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_bdl_upd_ovf_int_END (12)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_bdl_upd_noact_int_START (13)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_swift_trk_bdl_upd_noact_int_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swift_trk_gt_upd_req_en : 4;
        unsigned int swift_trk_rdet_upd_req_en : 4;
        unsigned int swift_trk_dlm_req_en : 1;
        unsigned int swift_trk_bdl_upd_err_int_en : 1;
        unsigned int swift_trk_bdl_upd_ovf_int_en : 1;
        unsigned int swift_trk_bdl_upd_noact_int_en : 1;
        unsigned int swift_trk_err_int_clr : 1;
        unsigned int swift_trk_dfx_clr : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_UNION;
#endif
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_gt_upd_req_en_START (0)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_gt_upd_req_en_END (3)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_rdet_upd_req_en_START (4)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_rdet_upd_req_en_END (7)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_dlm_req_en_START (8)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_dlm_req_en_END (8)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_bdl_upd_err_int_en_START (9)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_bdl_upd_err_int_en_END (9)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_bdl_upd_ovf_int_en_START (10)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_bdl_upd_ovf_int_en_END (10)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_bdl_upd_noact_int_en_START (11)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_bdl_upd_noact_int_en_END (11)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_err_int_clr_START (12)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_err_int_clr_END (12)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_dfx_clr_START (13)
#define SOC_DDR_PACK_SWIFT_TRK_UPD_REQ_EN_swift_trk_dfx_clr_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swift_trk_gt_inc : 4;
        unsigned int swift_trk_gt_dec : 4;
        unsigned int swift_trk_rdet_inc : 4;
        unsigned int swift_trk_rdet_dec : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PACK_SWIFT_TRK_STAT_UNION;
#endif
#define SOC_DDR_PACK_SWIFT_TRK_STAT_swift_trk_gt_inc_START (0)
#define SOC_DDR_PACK_SWIFT_TRK_STAT_swift_trk_gt_inc_END (3)
#define SOC_DDR_PACK_SWIFT_TRK_STAT_swift_trk_gt_dec_START (4)
#define SOC_DDR_PACK_SWIFT_TRK_STAT_swift_trk_gt_dec_END (7)
#define SOC_DDR_PACK_SWIFT_TRK_STAT_swift_trk_rdet_inc_START (8)
#define SOC_DDR_PACK_SWIFT_TRK_STAT_swift_trk_rdet_inc_END (11)
#define SOC_DDR_PACK_SWIFT_TRK_STAT_swift_trk_rdet_dec_START (12)
#define SOC_DDR_PACK_SWIFT_TRK_STAT_swift_trk_rdet_dec_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swift_trk_dbg_out : 32;
    } reg;
} SOC_DDR_PACK_SWIFT_TRK_DBG_OUT_UNION;
#endif
#define SOC_DDR_PACK_SWIFT_TRK_DBG_OUT_swift_trk_dbg_out_START (0)
#define SOC_DDR_PACK_SWIFT_TRK_DBG_OUT_swift_trk_dbg_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pack_to_UA_sig : 32;
    } reg;
} SOC_DDR_PACK_PACK_TO_UA_SIG_UNION;
#endif
#define SOC_DDR_PACK_PACK_TO_UA_SIG_pack_to_UA_sig_START (0)
#define SOC_DDR_PACK_PACK_TO_UA_SIG_pack_to_UA_sig_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int retrain_time_th : 20;
        unsigned int retrain_post_sref_en : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_DDR_PACK_NEW_RETRAIN_CFG_UNION;
#endif
#define SOC_DDR_PACK_NEW_RETRAIN_CFG_retrain_time_th_START (0)
#define SOC_DDR_PACK_NEW_RETRAIN_CFG_retrain_time_th_END (19)
#define SOC_DDR_PACK_NEW_RETRAIN_CFG_retrain_post_sref_en_START (20)
#define SOC_DDR_PACK_NEW_RETRAIN_CFG_retrain_post_sref_en_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ck_bdl : 10;
        unsigned int ck_phase : 3;
        unsigned int reserved_0 : 3;
        unsigned int rdqsbdl180 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_PACK_CK_DELAY_CFG_UNION;
#endif
#define SOC_DDR_PACK_CK_DELAY_CFG_ck_bdl_START (0)
#define SOC_DDR_PACK_CK_DELAY_CFG_ck_bdl_END (9)
#define SOC_DDR_PACK_CK_DELAY_CFG_ck_phase_START (10)
#define SOC_DDR_PACK_CK_DELAY_CFG_ck_phase_END (12)
#define SOC_DDR_PACK_CK_DELAY_CFG_rdqsbdl180_START (16)
#define SOC_DDR_PACK_CK_DELAY_CFG_rdqsbdl180_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swift_trk_addrbdl_upd_mask : 1;
        unsigned int swift_trk_csbdl_upd_mask : 1;
        unsigned int swift_trk_ckebdl_upd_mask : 1;
        unsigned int swift_trk_ckbdl_upd_mask : 1;
        unsigned int swift_trk_bdl2ph_weccbdl_en : 1;
        unsigned int swift_trk_bdl2ph_wdmbdl_en : 1;
        unsigned int swift_trk_bdl2ph_dqsoebdl_en : 1;
        unsigned int swift_trk_bdl2ph_dqoebdl_en : 1;
        unsigned int swift_trk_bdl2ph_addr6bdl_en : 1;
        unsigned int swift_trk_bdl2ph_addr7bdl_en : 1;
        unsigned int swift_trk_bdl2ph_en : 1;
        unsigned int swift_trk_upd_time : 5;
        unsigned int swift_trk_upd_thr : 8;
        unsigned int swift_trk_rdqsbdl180_upd_mask : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_UNION;
#endif
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_addrbdl_upd_mask_START (0)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_addrbdl_upd_mask_END (0)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_csbdl_upd_mask_START (1)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_csbdl_upd_mask_END (1)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_ckebdl_upd_mask_START (2)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_ckebdl_upd_mask_END (2)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_ckbdl_upd_mask_START (3)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_ckbdl_upd_mask_END (3)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_weccbdl_en_START (4)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_weccbdl_en_END (4)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_wdmbdl_en_START (5)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_wdmbdl_en_END (5)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_dqsoebdl_en_START (6)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_dqsoebdl_en_END (6)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_dqoebdl_en_START (7)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_dqoebdl_en_END (7)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_addr6bdl_en_START (8)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_addr6bdl_en_END (8)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_addr7bdl_en_START (9)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_addr7bdl_en_END (9)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_en_START (10)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_bdl2ph_en_END (10)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_upd_time_START (11)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_upd_time_END (15)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_upd_thr_START (16)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_upd_thr_END (23)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_rdqsbdl180_upd_mask_START (24)
#define SOC_DDR_PACK_SWIFT_TRK_BDL_UPD_CFG_swift_trk_rdqsbdl180_upd_mask_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swift_trk_rdqnbdl_upd_mask : 1;
        unsigned int swift_trk_rdmbdl_upd_mask : 1;
        unsigned int swift_trk_weccbdl_upd_mask : 1;
        unsigned int swift_trk_wdqnbdl_upd_mask : 1;
        unsigned int swift_trk_wdmbdl_upd_mask : 1;
        unsigned int swift_trk_wdqsbdl_upd_mask : 1;
        unsigned int swift_trk_wdqsoebdl_upd_mask : 1;
        unsigned int swift_trk_oenbdl_upd_mask : 1;
        unsigned int swift_trk_rdqsgtxbdl_upd_mask : 1;
        unsigned int swift_trk_rdqsgbdl_upd_mask : 1;
        unsigned int swift_trk_rdqsbdl_upd_mask : 1;
        unsigned int swift_trk_rdqscyc_upd_mask : 1;
        unsigned int swift_trk_rdqsbdl30_upd_mask : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_UNION;
#endif
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqnbdl_upd_mask_START (0)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqnbdl_upd_mask_END (0)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdmbdl_upd_mask_START (1)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdmbdl_upd_mask_END (1)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_weccbdl_upd_mask_START (2)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_weccbdl_upd_mask_END (2)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_wdqnbdl_upd_mask_START (3)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_wdqnbdl_upd_mask_END (3)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_wdmbdl_upd_mask_START (4)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_wdmbdl_upd_mask_END (4)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_wdqsbdl_upd_mask_START (5)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_wdqsbdl_upd_mask_END (5)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_wdqsoebdl_upd_mask_START (6)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_wdqsoebdl_upd_mask_END (6)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_oenbdl_upd_mask_START (7)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_oenbdl_upd_mask_END (7)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqsgtxbdl_upd_mask_START (8)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqsgtxbdl_upd_mask_END (8)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqsgbdl_upd_mask_START (9)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqsgbdl_upd_mask_END (9)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqsbdl_upd_mask_START (10)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqsbdl_upd_mask_END (10)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqscyc_upd_mask_START (11)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqscyc_upd_mask_END (11)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqsbdl30_upd_mask_START (12)
#define SOC_DDR_PACK_SWIFT_TRK_CFG_PERBYTE_swift_trk_rdqsbdl30_upd_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlm_result_old_swift_trk_dfx_1st_from_last : 16;
        unsigned int dlm_result_new_swift_trk_dfx_1st_from_last : 16;
    } reg;
} SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ST_FROM_LAST_UNION;
#endif
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ST_FROM_LAST_dlm_result_old_swift_trk_dfx_1st_from_last_START (0)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ST_FROM_LAST_dlm_result_old_swift_trk_dfx_1st_from_last_END (15)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ST_FROM_LAST_dlm_result_new_swift_trk_dfx_1st_from_last_START (16)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ST_FROM_LAST_dlm_result_new_swift_trk_dfx_1st_from_last_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlm_result_old_swift_trk_dfx_2nd_from_last : 16;
        unsigned int dlm_result_new_swift_trk_dfx_2nd_from_last : 16;
    } reg;
} SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ND_FROM_LAST_UNION;
#endif
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ND_FROM_LAST_dlm_result_old_swift_trk_dfx_2nd_from_last_START (0)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ND_FROM_LAST_dlm_result_old_swift_trk_dfx_2nd_from_last_END (15)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ND_FROM_LAST_dlm_result_new_swift_trk_dfx_2nd_from_last_START (16)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_1ND_FROM_LAST_dlm_result_new_swift_trk_dfx_2nd_from_last_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlm_result_old_swift_trk_dfx_3rd_from_last : 16;
        unsigned int dlm_result_new_swift_trk_dfx_3rd_from_last : 16;
    } reg;
} SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_3RD_FROM_LAST_UNION;
#endif
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_3RD_FROM_LAST_dlm_result_old_swift_trk_dfx_3rd_from_last_START (0)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_3RD_FROM_LAST_dlm_result_old_swift_trk_dfx_3rd_from_last_END (15)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_3RD_FROM_LAST_dlm_result_new_swift_trk_dfx_3rd_from_last_START (16)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_3RD_FROM_LAST_dlm_result_new_swift_trk_dfx_3rd_from_last_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlm_result_old_swift_trk_dfx_4th_from_last : 16;
        unsigned int dlm_result_new_swift_trk_dfx_4th_from_last : 16;
    } reg;
} SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_4TH_FROM_LAST_UNION;
#endif
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_4TH_FROM_LAST_dlm_result_old_swift_trk_dfx_4th_from_last_START (0)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_4TH_FROM_LAST_dlm_result_old_swift_trk_dfx_4th_from_last_END (15)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_4TH_FROM_LAST_dlm_result_new_swift_trk_dfx_4th_from_last_START (16)
#define SOC_DDR_PACK_DLM_RESULT_NEW_OLD_SWIFT_TRK_DFX_4TH_FROM_LAST_dlm_result_new_swift_trk_dfx_4th_from_last_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uc_mode_en : 1;
        unsigned int uc_regif_wst : 1;
        unsigned int uc_rt_populate : 2;
        unsigned int uc_rw_pte_en : 1;
        unsigned int uc_mode_en_bg : 1;
        unsigned int reserved_0 : 1;
        unsigned int carry_status_type : 1;
        unsigned int phycnt_rst_type : 1;
        unsigned int blcmpres_blen : 1;
        unsigned int blcmpres_wrap_latch : 1;
        unsigned int reserved_1 : 1;
        unsigned int blcmpres_idx : 5;
        unsigned int reserved_2 : 2;
        unsigned int blcmpres_clr : 1;
        unsigned int status_lowpri_peek : 1;
        unsigned int trkdbg_ctl_aref_active : 1;
        unsigned int trkdbg_dlymeas_gated : 1;
        unsigned int reserved_3 : 1;
        unsigned int trkdbg_dyna_hiprirdqsgen : 1;
        unsigned int trkdbg_dyna_prirdqsgen : 1;
        unsigned int trkdbg_dyna_rdqsgen : 1;
        unsigned int trkdbg_dyna_rdqsen : 1;
        unsigned int trkdbg_rdqsg_get : 1;
        unsigned int trkdbg_rdqs_get : 1;
        unsigned int pte_phyupd_req : 1;
        unsigned int uc_rowact_type : 1;
    } reg;
} SOC_DDR_PACK_UC_TRCTRL_UNION;
#endif
#define SOC_DDR_PACK_UC_TRCTRL_uc_mode_en_START (0)
#define SOC_DDR_PACK_UC_TRCTRL_uc_mode_en_END (0)
#define SOC_DDR_PACK_UC_TRCTRL_uc_regif_wst_START (1)
#define SOC_DDR_PACK_UC_TRCTRL_uc_regif_wst_END (1)
#define SOC_DDR_PACK_UC_TRCTRL_uc_rt_populate_START (2)
#define SOC_DDR_PACK_UC_TRCTRL_uc_rt_populate_END (3)
#define SOC_DDR_PACK_UC_TRCTRL_uc_rw_pte_en_START (4)
#define SOC_DDR_PACK_UC_TRCTRL_uc_rw_pte_en_END (4)
#define SOC_DDR_PACK_UC_TRCTRL_uc_mode_en_bg_START (5)
#define SOC_DDR_PACK_UC_TRCTRL_uc_mode_en_bg_END (5)
#define SOC_DDR_PACK_UC_TRCTRL_carry_status_type_START (7)
#define SOC_DDR_PACK_UC_TRCTRL_carry_status_type_END (7)
#define SOC_DDR_PACK_UC_TRCTRL_phycnt_rst_type_START (8)
#define SOC_DDR_PACK_UC_TRCTRL_phycnt_rst_type_END (8)
#define SOC_DDR_PACK_UC_TRCTRL_blcmpres_blen_START (9)
#define SOC_DDR_PACK_UC_TRCTRL_blcmpres_blen_END (9)
#define SOC_DDR_PACK_UC_TRCTRL_blcmpres_wrap_latch_START (10)
#define SOC_DDR_PACK_UC_TRCTRL_blcmpres_wrap_latch_END (10)
#define SOC_DDR_PACK_UC_TRCTRL_blcmpres_idx_START (12)
#define SOC_DDR_PACK_UC_TRCTRL_blcmpres_idx_END (16)
#define SOC_DDR_PACK_UC_TRCTRL_blcmpres_clr_START (19)
#define SOC_DDR_PACK_UC_TRCTRL_blcmpres_clr_END (19)
#define SOC_DDR_PACK_UC_TRCTRL_status_lowpri_peek_START (20)
#define SOC_DDR_PACK_UC_TRCTRL_status_lowpri_peek_END (20)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_ctl_aref_active_START (21)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_ctl_aref_active_END (21)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_dlymeas_gated_START (22)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_dlymeas_gated_END (22)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_dyna_hiprirdqsgen_START (24)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_dyna_hiprirdqsgen_END (24)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_dyna_prirdqsgen_START (25)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_dyna_prirdqsgen_END (25)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_dyna_rdqsgen_START (26)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_dyna_rdqsgen_END (26)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_dyna_rdqsen_START (27)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_dyna_rdqsen_END (27)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_rdqsg_get_START (28)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_rdqsg_get_END (28)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_rdqs_get_START (29)
#define SOC_DDR_PACK_UC_TRCTRL_trkdbg_rdqs_get_END (29)
#define SOC_DDR_PACK_UC_TRCTRL_pte_phyupd_req_START (30)
#define SOC_DDR_PACK_UC_TRCTRL_pte_phyupd_req_END (30)
#define SOC_DDR_PACK_UC_TRCTRL_uc_rowact_type_START (31)
#define SOC_DDR_PACK_UC_TRCTRL_uc_rowact_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int detop_active : 1;
        unsigned int detop_preca : 1;
        unsigned int reserved_0 : 2;
        unsigned int detop_prewrite : 1;
        unsigned int detop_rdtest : 1;
        unsigned int detop_rwtest : 1;
        unsigned int detop_preca_post : 1;
        unsigned int detop_rdert : 1;
        unsigned int detop_wdert : 1;
        unsigned int reserved_1 : 6;
        unsigned int phycnt_rst : 1;
        unsigned int wl2op_active : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_DDR_PACK_UC_TROPCTRL_UNION;
#endif
#define SOC_DDR_PACK_UC_TROPCTRL_detop_active_START (0)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_active_END (0)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_preca_START (1)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_preca_END (1)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_prewrite_START (4)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_prewrite_END (4)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_rdtest_START (5)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_rdtest_END (5)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_rwtest_START (6)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_rwtest_END (6)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_preca_post_START (7)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_preca_post_END (7)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_rdert_START (8)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_rdert_END (8)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_wdert_START (9)
#define SOC_DDR_PACK_UC_TROPCTRL_detop_wdert_END (9)
#define SOC_DDR_PACK_UC_TROPCTRL_phycnt_rst_START (16)
#define SOC_DDR_PACK_UC_TROPCTRL_phycnt_rst_END (16)
#define SOC_DDR_PACK_UC_TROPCTRL_wl2op_active_START (17)
#define SOC_DDR_PACK_UC_TROPCTRL_wl2op_active_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtrain_active : 1;
        unsigned int reserved : 14;
        unsigned int comb_cary_status : 1;
        unsigned int det_all_passed : 4;
        unsigned int det_any_passed : 4;
        unsigned int det_all_failed : 4;
        unsigned int det_any_failed : 4;
    } reg;
} SOC_DDR_PACK_UC_DTRSTSP_UNION;
#endif
#define SOC_DDR_PACK_UC_DTRSTSP_dtrain_active_START (0)
#define SOC_DDR_PACK_UC_DTRSTSP_dtrain_active_END (0)
#define SOC_DDR_PACK_UC_DTRSTSP_comb_cary_status_START (15)
#define SOC_DDR_PACK_UC_DTRSTSP_comb_cary_status_END (15)
#define SOC_DDR_PACK_UC_DTRSTSP_det_all_passed_START (16)
#define SOC_DDR_PACK_UC_DTRSTSP_det_all_passed_END (19)
#define SOC_DDR_PACK_UC_DTRSTSP_det_any_passed_START (20)
#define SOC_DDR_PACK_UC_DTRSTSP_det_any_passed_END (23)
#define SOC_DDR_PACK_UC_DTRSTSP_det_all_failed_START (24)
#define SOC_DDR_PACK_UC_DTRSTSP_det_all_failed_END (27)
#define SOC_DDR_PACK_UC_DTRSTSP_det_any_failed_START (28)
#define SOC_DDR_PACK_UC_DTRSTSP_det_any_failed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uc_rtactive : 2;
        unsigned int reserved : 28;
        unsigned int pd_in_retrain : 1;
        unsigned int uc_int_msk : 1;
    } reg;
} SOC_DDR_PACK_UC_TRSTATUS_UNION;
#endif
#define SOC_DDR_PACK_UC_TRSTATUS_uc_rtactive_START (0)
#define SOC_DDR_PACK_UC_TRSTATUS_uc_rtactive_END (1)
#define SOC_DDR_PACK_UC_TRSTATUS_pd_in_retrain_START (30)
#define SOC_DDR_PACK_UC_TRSTATUS_pd_in_retrain_END (30)
#define SOC_DDR_PACK_UC_TRSTATUS_uc_int_msk_START (31)
#define SOC_DDR_PACK_UC_TRSTATUS_uc_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_byp_mode : 1;
        unsigned int cmdq_flush : 1;
        unsigned int reserved_0 : 2;
        unsigned int cmdq_rd_flush_mode : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_DDR_PACK_UC_CMDQCTRL_UNION;
#endif
#define SOC_DDR_PACK_UC_CMDQCTRL_cmdq_byp_mode_START (0)
#define SOC_DDR_PACK_UC_CMDQCTRL_cmdq_byp_mode_END (0)
#define SOC_DDR_PACK_UC_CMDQCTRL_cmdq_flush_START (1)
#define SOC_DDR_PACK_UC_CMDQCTRL_cmdq_flush_END (1)
#define SOC_DDR_PACK_UC_CMDQCTRL_cmdq_rd_flush_mode_START (4)
#define SOC_DDR_PACK_UC_CMDQCTRL_cmdq_rd_flush_mode_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int blcmpres0 : 9;
        unsigned int blcmpres1 : 9;
        unsigned int reserved : 13;
        unsigned int blcmpres_shot : 1;
    } reg;
} SOC_DDR_PACK_UC_CMP_RESBLST_UNION;
#endif
#define SOC_DDR_PACK_UC_CMP_RESBLST_blcmpres0_START (0)
#define SOC_DDR_PACK_UC_CMP_RESBLST_blcmpres0_END (8)
#define SOC_DDR_PACK_UC_CMP_RESBLST_blcmpres1_START (9)
#define SOC_DDR_PACK_UC_CMP_RESBLST_blcmpres1_END (17)
#define SOC_DDR_PACK_UC_CMP_RESBLST_blcmpres_shot_START (31)
#define SOC_DDR_PACK_UC_CMP_RESBLST_blcmpres_shot_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_done_bit : 1;
        unsigned int pte_regrdy : 1;
        unsigned int reseved : 14;
        unsigned int apb_paddr : 15;
        unsigned int apb_write : 1;
    } reg;
} SOC_DDR_PACK_UC_APB_CAS_UNION;
#endif
#define SOC_DDR_PACK_UC_APB_CAS_apb_done_bit_START (0)
#define SOC_DDR_PACK_UC_APB_CAS_apb_done_bit_END (0)
#define SOC_DDR_PACK_UC_APB_CAS_pte_regrdy_START (1)
#define SOC_DDR_PACK_UC_APB_CAS_pte_regrdy_END (1)
#define SOC_DDR_PACK_UC_APB_CAS_reseved_START (2)
#define SOC_DDR_PACK_UC_APB_CAS_reseved_END (15)
#define SOC_DDR_PACK_UC_APB_CAS_apb_paddr_START (16)
#define SOC_DDR_PACK_UC_APB_CAS_apb_paddr_END (30)
#define SOC_DDR_PACK_UC_APB_CAS_apb_write_START (31)
#define SOC_DDR_PACK_UC_APB_CAS_apb_write_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_wdata : 32;
    } reg;
} SOC_DDR_PACK_UC_APB_WDATA_UNION;
#endif
#define SOC_DDR_PACK_UC_APB_WDATA_apb_wdata_START (0)
#define SOC_DDR_PACK_UC_APB_WDATA_apb_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_rdata : 32;
    } reg;
} SOC_DDR_PACK_UC_APB_RDATA_UNION;
#endif
#define SOC_DDR_PACK_UC_APB_RDATA_apb_rdata_START (0)
#define SOC_DDR_PACK_UC_APB_RDATA_apb_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 8;
        unsigned int reserved_0 : 4;
        unsigned int carry_status : 2;
        unsigned int reserved_1 : 6;
        unsigned int phase_sel : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_DDR_PACK_UC_ADDRPH_A_AUC_UNION;
#endif
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_src_sel_START (3)
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_src_sel_END (3)
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_alu_operand_END (11)
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_carry_status_START (16)
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_carry_status_END (17)
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_phase_sel_START (24)
#define SOC_DDR_PACK_UC_ADDRPH_A_AUC_phase_sel_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved : 2;
        unsigned int carry_status : 8;
        unsigned int addrbdl_a_sel : 8;
    } reg;
} SOC_DDR_PACK_UC_ADDRBDL_A_AUC_UNION;
#endif
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_src_sel_START (3)
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_src_sel_END (3)
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_alu_operand_END (13)
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_carry_status_START (16)
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_carry_status_END (23)
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_addrbdl_a_sel_START (24)
#define SOC_DDR_PACK_UC_ADDRBDL_A_AUC_addrbdl_a_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_0 : 2;
        unsigned int carry_status : 2;
        unsigned int reserved_1 : 6;
        unsigned int csbdl_sel : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_DDR_PACK_UC_CSRBDL_AUC_UNION;
#endif
#define SOC_DDR_PACK_UC_CSRBDL_AUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_CSRBDL_AUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_CSRBDL_AUC_src_sel_START (3)
#define SOC_DDR_PACK_UC_CSRBDL_AUC_src_sel_END (3)
#define SOC_DDR_PACK_UC_CSRBDL_AUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_CSRBDL_AUC_alu_operand_END (13)
#define SOC_DDR_PACK_UC_CSRBDL_AUC_carry_status_START (16)
#define SOC_DDR_PACK_UC_CSRBDL_AUC_carry_status_END (17)
#define SOC_DDR_PACK_UC_CSRBDL_AUC_csbdl_sel_START (24)
#define SOC_DDR_PACK_UC_CSRBDL_AUC_csbdl_sel_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 8;
        unsigned int reserved : 4;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PACK_UC_WDQPHAUC_UNION;
#endif
#define SOC_DDR_PACK_UC_WDQPHAUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_WDQPHAUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_WDQPHAUC_src_sel_START (3)
#define SOC_DDR_PACK_UC_WDQPHAUC_src_sel_END (3)
#define SOC_DDR_PACK_UC_WDQPHAUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_WDQPHAUC_alu_operand_END (11)
#define SOC_DDR_PACK_UC_WDQPHAUC_carry_status_START (16)
#define SOC_DDR_PACK_UC_WDQPHAUC_carry_status_END (23)
#define SOC_DDR_PACK_UC_WDQPHAUC_data8_sel_START (24)
#define SOC_DDR_PACK_UC_WDQPHAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 6;
        unsigned int reserved_1 : 6;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PACK_UC_WDQSPHAUC_UNION;
#endif
#define SOC_DDR_PACK_UC_WDQSPHAUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_WDQSPHAUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_WDQSPHAUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_WDQSPHAUC_alu_operand_END (9)
#define SOC_DDR_PACK_UC_WDQSPHAUC_carry_status_START (16)
#define SOC_DDR_PACK_UC_WDQSPHAUC_carry_status_END (23)
#define SOC_DDR_PACK_UC_WDQSPHAUC_data8_sel_START (24)
#define SOC_DDR_PACK_UC_WDQSPHAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PACK_UC_WDQSBDLAUC_UNION;
#endif
#define SOC_DDR_PACK_UC_WDQSBDLAUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_WDQSBDLAUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_WDQSBDLAUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_WDQSBDLAUC_alu_operand_END (13)
#define SOC_DDR_PACK_UC_WDQSBDLAUC_carry_status_START (16)
#define SOC_DDR_PACK_UC_WDQSBDLAUC_carry_status_END (23)
#define SOC_DDR_PACK_UC_WDQSBDLAUC_data8_sel_START (24)
#define SOC_DDR_PACK_UC_WDQSBDLAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdly_store : 1;
        unsigned int reserved_0 : 19;
        unsigned int acdly_store : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_DDR_PACK_UC_WDLYOP_UNION;
#endif
#define SOC_DDR_PACK_UC_WDLYOP_wdly_store_START (0)
#define SOC_DDR_PACK_UC_WDLYOP_wdly_store_END (0)
#define SOC_DDR_PACK_UC_WDLYOP_acdly_store_START (20)
#define SOC_DDR_PACK_UC_WDLYOP_acdly_store_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rdert_check_step : 8;
        unsigned int cfg_rdert_shift_step : 8;
        unsigned int cfg_wdert_check_step : 8;
        unsigned int cfg_wdert_shift_step : 8;
    } reg;
} SOC_DDR_PACK_UC_DERT_STEP_UNION;
#endif
#define SOC_DDR_PACK_UC_DERT_STEP_cfg_rdert_check_step_START (0)
#define SOC_DDR_PACK_UC_DERT_STEP_cfg_rdert_check_step_END (7)
#define SOC_DDR_PACK_UC_DERT_STEP_cfg_rdert_shift_step_START (8)
#define SOC_DDR_PACK_UC_DERT_STEP_cfg_rdert_shift_step_END (15)
#define SOC_DDR_PACK_UC_DERT_STEP_cfg_wdert_check_step_START (16)
#define SOC_DDR_PACK_UC_DERT_STEP_cfg_wdert_check_step_END (23)
#define SOC_DDR_PACK_UC_DERT_STEP_cfg_wdert_shift_step_START (24)
#define SOC_DDR_PACK_UC_DERT_STEP_cfg_wdert_shift_step_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dert_rwtest_num : 4;
        unsigned int cfg_dert_retrain_num : 4;
        unsigned int cfg_dert_bdl_wait_time : 4;
        unsigned int cfg_dert_error_idx : 4;
        unsigned int cfg_dert_dbimod_en : 1;
        unsigned int cfg_dert_rank_en : 1;
        unsigned int cfg_dert_rwtest_sel : 1;
        unsigned int cfg_dert_step_sel : 1;
        unsigned int cfg_dert_rdqs_shift_en : 1;
        unsigned int reserved : 7;
        unsigned int cfg_dert_mrw_wait_time : 4;
    } reg;
} SOC_DDR_PACK_UC_DERT_CFG_UNION;
#endif
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_rwtest_num_START (0)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_rwtest_num_END (3)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_retrain_num_START (4)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_retrain_num_END (7)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_bdl_wait_time_START (8)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_bdl_wait_time_END (11)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_error_idx_START (12)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_error_idx_END (15)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_dbimod_en_START (16)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_dbimod_en_END (16)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_rank_en_START (17)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_rank_en_END (17)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_rwtest_sel_START (18)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_rwtest_sel_END (18)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_step_sel_START (19)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_step_sel_END (19)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_rdqs_shift_en_START (20)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_rdqs_shift_en_END (20)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_mrw_wait_time_START (28)
#define SOC_DDR_PACK_UC_DERT_CFG_cfg_dert_mrw_wait_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdert_error : 1;
        unsigned int wdert_error : 1;
        unsigned int dert_error_info : 24;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_PACK_UC_DERT_INFO_UNION;
#endif
#define SOC_DDR_PACK_UC_DERT_INFO_rdert_error_START (0)
#define SOC_DDR_PACK_UC_DERT_INFO_rdert_error_END (0)
#define SOC_DDR_PACK_UC_DERT_INFO_wdert_error_START (1)
#define SOC_DDR_PACK_UC_DERT_INFO_wdert_error_END (1)
#define SOC_DDR_PACK_UC_DERT_INFO_dert_error_info_START (2)
#define SOC_DDR_PACK_UC_DERT_INFO_dert_error_info_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dert_debug_info : 32;
    } reg;
} SOC_DDR_PACK_UC_DERT_DBG_UNION;
#endif
#define SOC_DDR_PACK_UC_DERT_DBG_dert_debug_info_START (0)
#define SOC_DDR_PACK_UC_DERT_DBG_dert_debug_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PACK_UC_RDQSAUC_UNION;
#endif
#define SOC_DDR_PACK_UC_RDQSAUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_RDQSAUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_RDQSAUC_src_sel_START (3)
#define SOC_DDR_PACK_UC_RDQSAUC_src_sel_END (3)
#define SOC_DDR_PACK_UC_RDQSAUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_RDQSAUC_alu_operand_END (13)
#define SOC_DDR_PACK_UC_RDQSAUC_carry_status_START (16)
#define SOC_DDR_PACK_UC_RDQSAUC_carry_status_END (23)
#define SOC_DDR_PACK_UC_RDQSAUC_data8_sel_START (24)
#define SOC_DDR_PACK_UC_RDQSAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PACK_UC_RDQSGTXAUC_UNION;
#endif
#define SOC_DDR_PACK_UC_RDQSGTXAUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_RDQSGTXAUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_RDQSGTXAUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_RDQSGTXAUC_alu_operand_END (13)
#define SOC_DDR_PACK_UC_RDQSGTXAUC_carry_status_START (16)
#define SOC_DDR_PACK_UC_RDQSGTXAUC_carry_status_END (23)
#define SOC_DDR_PACK_UC_RDQSGTXAUC_data8_sel_START (24)
#define SOC_DDR_PACK_UC_RDQSGTXAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PACK_UC_RDQSGPHAUC_UNION;
#endif
#define SOC_DDR_PACK_UC_RDQSGPHAUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_RDQSGPHAUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_RDQSGPHAUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_RDQSGPHAUC_alu_operand_END (13)
#define SOC_DDR_PACK_UC_RDQSGPHAUC_carry_status_START (16)
#define SOC_DDR_PACK_UC_RDQSGPHAUC_carry_status_END (23)
#define SOC_DDR_PACK_UC_RDQSGPHAUC_data8_sel_START (24)
#define SOC_DDR_PACK_UC_RDQSGPHAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PACK_UC_RDQSGBDLAUC_UNION;
#endif
#define SOC_DDR_PACK_UC_RDQSGBDLAUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_RDQSGBDLAUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_RDQSGBDLAUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_RDQSGBDLAUC_alu_operand_END (13)
#define SOC_DDR_PACK_UC_RDQSGBDLAUC_carry_status_START (16)
#define SOC_DDR_PACK_UC_RDQSGBDLAUC_carry_status_END (23)
#define SOC_DDR_PACK_UC_RDQSGBDLAUC_data8_sel_START (24)
#define SOC_DDR_PACK_UC_RDQSGBDLAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 5;
        unsigned int reserved_1 : 7;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PACK_UC_RGDSAUC_UNION;
#endif
#define SOC_DDR_PACK_UC_RGDSAUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_RGDSAUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_RGDSAUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_RGDSAUC_alu_operand_END (8)
#define SOC_DDR_PACK_UC_RGDSAUC_carry_status_START (16)
#define SOC_DDR_PACK_UC_RGDSAUC_carry_status_END (23)
#define SOC_DDR_PACK_UC_RGDSAUC_data8_sel_START (24)
#define SOC_DDR_PACK_UC_RGDSAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdly_store : 1;
        unsigned int reserved : 15;
        unsigned int operandz : 16;
    } reg;
} SOC_DDR_PACK_UC_RDLYOP_UNION;
#endif
#define SOC_DDR_PACK_UC_RDLYOP_rdly_store_START (0)
#define SOC_DDR_PACK_UC_RDLYOP_rdly_store_END (0)
#define SOC_DDR_PACK_UC_RDLYOP_operandz_START (16)
#define SOC_DDR_PACK_UC_RDLYOP_operandz_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_wlmode : 1;
        unsigned int sw_gtmode : 1;
        unsigned int reserved_0 : 2;
        unsigned int sw_wlmodeb : 8;
        unsigned int reserved_1 : 4;
        unsigned int sw_dxctl_ie_dq : 8;
        unsigned int sw_dxctl_ie_dq_mode : 1;
        unsigned int reserved_2 : 3;
        unsigned int sw_rdfifo_push_block : 1;
        unsigned int sw_dvalid_block : 1;
        unsigned int sw_csgated : 1;
        unsigned int wl_wdqs_gated : 1;
    } reg;
} SOC_DDR_PACK_UCSWTMODE_UNION;
#endif
#define SOC_DDR_PACK_UCSWTMODE_sw_wlmode_START (0)
#define SOC_DDR_PACK_UCSWTMODE_sw_wlmode_END (0)
#define SOC_DDR_PACK_UCSWTMODE_sw_gtmode_START (1)
#define SOC_DDR_PACK_UCSWTMODE_sw_gtmode_END (1)
#define SOC_DDR_PACK_UCSWTMODE_sw_wlmodeb_START (4)
#define SOC_DDR_PACK_UCSWTMODE_sw_wlmodeb_END (11)
#define SOC_DDR_PACK_UCSWTMODE_sw_dxctl_ie_dq_START (16)
#define SOC_DDR_PACK_UCSWTMODE_sw_dxctl_ie_dq_END (23)
#define SOC_DDR_PACK_UCSWTMODE_sw_dxctl_ie_dq_mode_START (24)
#define SOC_DDR_PACK_UCSWTMODE_sw_dxctl_ie_dq_mode_END (24)
#define SOC_DDR_PACK_UCSWTMODE_sw_rdfifo_push_block_START (28)
#define SOC_DDR_PACK_UCSWTMODE_sw_rdfifo_push_block_END (28)
#define SOC_DDR_PACK_UCSWTMODE_sw_dvalid_block_START (29)
#define SOC_DDR_PACK_UCSWTMODE_sw_dvalid_block_END (29)
#define SOC_DDR_PACK_UCSWTMODE_sw_csgated_START (30)
#define SOC_DDR_PACK_UCSWTMODE_sw_csgated_END (30)
#define SOC_DDR_PACK_UCSWTMODE_wl_wdqs_gated_START (31)
#define SOC_DDR_PACK_UCSWTMODE_wl_wdqs_gated_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_wl_dqs : 1;
        unsigned int reserved : 2;
        unsigned int sw_mrw_format : 1;
        unsigned int sw_mrw_cs : 2;
        unsigned int sw_mrw_rw : 1;
        unsigned int sw_mrw_req : 1;
        unsigned int sw_mrw_ma : 8;
        unsigned int sw_mrw_op : 16;
    } reg;
} SOC_DDR_PACK_UCSWTWLDQS_UNION;
#endif
#define SOC_DDR_PACK_UCSWTWLDQS_sw_wl_dqs_START (0)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_wl_dqs_END (0)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_format_START (3)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_format_END (3)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_cs_START (4)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_cs_END (5)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_rw_START (6)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_rw_END (6)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_req_START (7)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_req_END (7)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_ma_START (8)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_ma_END (15)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_op_START (16)
#define SOC_DDR_PACK_UCSWTWLDQS_sw_mrw_op_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wl_dq_result : 8;
        unsigned int gt_result : 8;
        unsigned int gds_result : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_PACK_UC_SWTRLT_UNION;
#endif
#define SOC_DDR_PACK_UC_SWTRLT_wl_dq_result_START (0)
#define SOC_DDR_PACK_UC_SWTRLT_wl_dq_result_END (7)
#define SOC_DDR_PACK_UC_SWTRLT_gt_result_START (8)
#define SOC_DDR_PACK_UC_SWTRLT_gt_result_END (15)
#define SOC_DDR_PACK_UC_SWTRLT_gds_result_START (16)
#define SOC_DDR_PACK_UC_SWTRLT_gds_result_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_mrr_data_selected : 16;
        unsigned int reserved_0 : 3;
        unsigned int sw_cas_off_type : 1;
        unsigned int sw_cas_cs : 2;
        unsigned int sw_cas_off_req : 1;
        unsigned int sw_cas_fs_req : 1;
        unsigned int sw_mrr_data_byte_sel : 3;
        unsigned int reserved_1 : 1;
        unsigned int sw_mrr_data_burst_sel : 2;
        unsigned int sw_enhrdqs_exit_req : 1;
        unsigned int sw_enhrdqs_entry_req : 1;
    } reg;
} SOC_DDR_PACK_UCSWMRRDATA_UNION;
#endif
#define SOC_DDR_PACK_UCSWMRRDATA_sw_mrr_data_selected_START (0)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_mrr_data_selected_END (15)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_cas_off_type_START (19)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_cas_off_type_END (19)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_cas_cs_START (20)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_cas_cs_END (21)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_cas_off_req_START (22)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_cas_off_req_END (22)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_cas_fs_req_START (23)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_cas_fs_req_END (23)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_mrr_data_byte_sel_START (24)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_mrr_data_byte_sel_END (26)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_mrr_data_burst_sel_START (28)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_mrr_data_burst_sel_END (29)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_enhrdqs_exit_req_START (30)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_enhrdqs_exit_req_END (30)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_enhrdqs_entry_req_START (31)
#define SOC_DDR_PACK_UCSWMRRDATA_sw_enhrdqs_entry_req_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 16;
        unsigned int sw_cat_eyet : 1;
        unsigned int reserved_1 : 5;
        unsigned int sw_cst_mode : 1;
        unsigned int reserved_2 : 1;
        unsigned int sw_cat_mrw42 : 1;
        unsigned int sw_cat_mrw48 : 1;
        unsigned int sw_cat_mrw41 : 1;
        unsigned int sw_cat_strobe : 1;
        unsigned int sw_cat_cke_high : 1;
        unsigned int sw_cat_cke_low : 1;
        unsigned int sw_cat_dqvalid : 1;
        unsigned int sw_cat_en : 1;
    } reg;
} SOC_DDR_PACK_UCCATCONFIG_UNION;
#endif
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_eyet_START (16)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_eyet_END (16)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cst_mode_START (22)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cst_mode_END (22)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_mrw42_START (24)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_mrw42_END (24)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_mrw48_START (25)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_mrw48_END (25)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_mrw41_START (26)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_mrw41_END (26)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_strobe_START (27)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_strobe_END (27)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_cke_high_START (28)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_cke_high_END (28)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_cke_low_START (29)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_cke_low_END (29)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_dqvalid_START (30)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_dqvalid_END (30)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_en_START (31)
#define SOC_DDR_PACK_UCCATCONFIG_sw_cat_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cat_result : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PACK_UCCATRESULT_UNION;
#endif
#define SOC_DDR_PACK_UCCATRESULT_cat_result_START (0)
#define SOC_DDR_PACK_UCCATRESULT_cat_result_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_dq_result : 32;
    } reg;
} SOC_DDR_PACK_UCPHYDQRESULT_UNION;
#endif
#define SOC_DDR_PACK_UCPHYDQRESULT_phy_dq_result_START (0)
#define SOC_DDR_PACK_UCPHYDQRESULT_phy_dq_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uc_sw_cat_pat_p : 10;
        unsigned int uc_sw_cat_pat_alt_indx : 6;
        unsigned int uc_sw_cat_pat_n : 10;
        unsigned int reserved : 3;
        unsigned int uc_sw_cat_pat_alt_auto : 1;
        unsigned int uc_sw_cat_pat_alt_en : 1;
        unsigned int uc_cat_wck_tg_mask : 1;
    } reg;
} SOC_DDR_PACK_UCSWCATPATTERN_P_UNION;
#endif
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_sw_cat_pat_p_START (0)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_sw_cat_pat_p_END (9)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_indx_START (10)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_indx_END (15)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_sw_cat_pat_n_START (16)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_sw_cat_pat_n_END (25)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_auto_START (29)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_auto_END (29)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_en_START (30)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_en_END (30)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_cat_wck_tg_mask_START (31)
#define SOC_DDR_PACK_UCSWCATPATTERN_P_uc_cat_wck_tg_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_gds_result : 32;
    } reg;
} SOC_DDR_PACK_UCFASTGDSRLT0_UNION;
#endif
#define SOC_DDR_PACK_UCFASTGDSRLT0_fast_gds_result_START (0)
#define SOC_DDR_PACK_UCFASTGDSRLT0_fast_gds_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_gds_result : 32;
    } reg;
} SOC_DDR_PACK_UCFASTGDSRLT1_UNION;
#endif
#define SOC_DDR_PACK_UCFASTGDSRLT1_fast_gds_result_START (0)
#define SOC_DDR_PACK_UCFASTGDSRLT1_fast_gds_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_gt_decgress : 8;
        unsigned int fast_gt_incgress : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PACK_UCFASTGTRLT_UNION;
#endif
#define SOC_DDR_PACK_UCFASTGTRLT_fast_gt_decgress_START (0)
#define SOC_DDR_PACK_UCFASTGTRLT_fast_gt_decgress_END (7)
#define SOC_DDR_PACK_UCFASTGTRLT_fast_gt_incgress_START (8)
#define SOC_DDR_PACK_UCFASTGTRLT_fast_gt_incgress_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_rdqs_status : 16;
        unsigned int trkdbg_rdqs_pristatus : 16;
    } reg;
} SOC_DDR_PACK_UCTRKDBG_RDQS_UNION;
#endif
#define SOC_DDR_PACK_UCTRKDBG_RDQS_trkdbg_rdqs_status_START (0)
#define SOC_DDR_PACK_UCTRKDBG_RDQS_trkdbg_rdqs_status_END (15)
#define SOC_DDR_PACK_UCTRKDBG_RDQS_trkdbg_rdqs_pristatus_START (16)
#define SOC_DDR_PACK_UCTRKDBG_RDQS_trkdbg_rdqs_pristatus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_rdqsg_status : 32;
    } reg;
} SOC_DDR_PACK_UCTRKDBG_RDQSG0_UNION;
#endif
#define SOC_DDR_PACK_UCTRKDBG_RDQSG0_trkdbg_rdqsg_status_START (0)
#define SOC_DDR_PACK_UCTRKDBG_RDQSG0_trkdbg_rdqsg_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_rdqsg_status_ph : 32;
    } reg;
} SOC_DDR_PACK_UCTRKDBG_RDQSG1_UNION;
#endif
#define SOC_DDR_PACK_UCTRKDBG_RDQSG1_trkdbg_rdqsg_status_ph_START (0)
#define SOC_DDR_PACK_UCTRKDBG_RDQSG1_trkdbg_rdqsg_status_ph_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_dqsg_stop : 8;
        unsigned int phy_dqs_stop : 8;
        unsigned int trkdbg_vref_status : 16;
    } reg;
} SOC_DDR_PACK_UCDBG_PHYSTOP_UNION;
#endif
#define SOC_DDR_PACK_UCDBG_PHYSTOP_phy_dqsg_stop_START (0)
#define SOC_DDR_PACK_UCDBG_PHYSTOP_phy_dqsg_stop_END (7)
#define SOC_DDR_PACK_UCDBG_PHYSTOP_phy_dqs_stop_START (8)
#define SOC_DDR_PACK_UCDBG_PHYSTOP_phy_dqs_stop_END (15)
#define SOC_DDR_PACK_UCDBG_PHYSTOP_trkdbg_vref_status_START (16)
#define SOC_DDR_PACK_UCDBG_PHYSTOP_trkdbg_vref_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dm_rdata : 32;
    } reg;
} SOC_DDR_PACK_UCDBG_PERBIT0_UNION;
#endif
#define SOC_DDR_PACK_UCDBG_PERBIT0_trkdbg_perbit_dm_rdata_START (0)
#define SOC_DDR_PACK_UCDBG_PERBIT0_trkdbg_perbit_dm_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata1 : 32;
    } reg;
} SOC_DDR_PACK_UCDBG_PERBIT1_UNION;
#endif
#define SOC_DDR_PACK_UCDBG_PERBIT1_trkdbg_perbit_dq_rdata1_START (0)
#define SOC_DDR_PACK_UCDBG_PERBIT1_trkdbg_perbit_dq_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata2 : 32;
    } reg;
} SOC_DDR_PACK_UCDBG_PERBIT2_UNION;
#endif
#define SOC_DDR_PACK_UCDBG_PERBIT2_trkdbg_perbit_dq_rdata2_START (0)
#define SOC_DDR_PACK_UCDBG_PERBIT2_trkdbg_perbit_dq_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata3 : 32;
    } reg;
} SOC_DDR_PACK_UCDBG_PERBIT3_UNION;
#endif
#define SOC_DDR_PACK_UCDBG_PERBIT3_trkdbg_perbit_dq_rdata3_START (0)
#define SOC_DDR_PACK_UCDBG_PERBIT3_trkdbg_perbit_dq_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata4 : 32;
    } reg;
} SOC_DDR_PACK_UCDBG_PERBIT4_UNION;
#endif
#define SOC_DDR_PACK_UCDBG_PERBIT4_trkdbg_perbit_dq_rdata4_START (0)
#define SOC_DDR_PACK_UCDBG_PERBIT4_trkdbg_perbit_dq_rdata4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dm_rdata1 : 32;
    } reg;
} SOC_DDR_PACK_UCDBG_PERBIT5_UNION;
#endif
#define SOC_DDR_PACK_UCDBG_PERBIT5_trkdbg_perbit_dm_rdata1_START (0)
#define SOC_DDR_PACK_UCDBG_PERBIT5_trkdbg_perbit_dm_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata5 : 32;
    } reg;
} SOC_DDR_PACK_UCDBG_PERBIT6_UNION;
#endif
#define SOC_DDR_PACK_UCDBG_PERBIT6_trkdbg_perbit_dq_rdata5_START (0)
#define SOC_DDR_PACK_UCDBG_PERBIT6_trkdbg_perbit_dq_rdata5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata6 : 32;
    } reg;
} SOC_DDR_PACK_UCDBG_PERBIT7_UNION;
#endif
#define SOC_DDR_PACK_UCDBG_PERBIT7_trkdbg_perbit_dq_rdata6_START (0)
#define SOC_DDR_PACK_UCDBG_PERBIT7_trkdbg_perbit_dq_rdata6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int wdm_carry : 1;
        unsigned int wdm_sel : 1;
        unsigned int wecc_sel : 1;
        unsigned int reserved : 7;
        unsigned int wdqn_sel : 8;
    } reg;
} SOC_DDR_PACK_UC_WDQNAUC_UNION;
#endif
#define SOC_DDR_PACK_UC_WDQNAUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_WDQNAUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_WDQNAUC_src_sel_START (3)
#define SOC_DDR_PACK_UC_WDQNAUC_src_sel_END (3)
#define SOC_DDR_PACK_UC_WDQNAUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_WDQNAUC_alu_operand_END (13)
#define SOC_DDR_PACK_UC_WDQNAUC_wdm_carry_START (14)
#define SOC_DDR_PACK_UC_WDQNAUC_wdm_carry_END (14)
#define SOC_DDR_PACK_UC_WDQNAUC_wdm_sel_START (15)
#define SOC_DDR_PACK_UC_WDQNAUC_wdm_sel_END (15)
#define SOC_DDR_PACK_UC_WDQNAUC_wecc_sel_START (16)
#define SOC_DDR_PACK_UC_WDQNAUC_wecc_sel_END (16)
#define SOC_DDR_PACK_UC_WDQNAUC_wdqn_sel_START (24)
#define SOC_DDR_PACK_UC_WDQNAUC_wdqn_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int even_odd : 1;
        unsigned int rdbi_sel : 1;
        unsigned int reserved : 8;
        unsigned int rdqn_sel : 8;
    } reg;
} SOC_DDR_PACK_UC_RDQNAUC_UNION;
#endif
#define SOC_DDR_PACK_UC_RDQNAUC_alu_operator_START (0)
#define SOC_DDR_PACK_UC_RDQNAUC_alu_operator_END (2)
#define SOC_DDR_PACK_UC_RDQNAUC_src_sel_START (3)
#define SOC_DDR_PACK_UC_RDQNAUC_src_sel_END (3)
#define SOC_DDR_PACK_UC_RDQNAUC_alu_operand_START (4)
#define SOC_DDR_PACK_UC_RDQNAUC_alu_operand_END (13)
#define SOC_DDR_PACK_UC_RDQNAUC_even_odd_START (14)
#define SOC_DDR_PACK_UC_RDQNAUC_even_odd_END (14)
#define SOC_DDR_PACK_UC_RDQNAUC_rdbi_sel_START (15)
#define SOC_DDR_PACK_UC_RDQNAUC_rdbi_sel_END (15)
#define SOC_DDR_PACK_UC_RDQNAUC_rdqn_sel_START (24)
#define SOC_DDR_PACK_UC_RDQNAUC_rdqn_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtrain_active : 1;
        unsigned int dm_cmpres_even : 1;
        unsigned int dm_cmpres_odd : 1;
        unsigned int dm_cmpres : 1;
        unsigned int dq_cmpres_even : 8;
        unsigned int dq_cmpres_odd : 8;
        unsigned int cmpres : 8;
        unsigned int det_all_passed : 1;
        unsigned int det_any_passed : 1;
        unsigned int det_all_failed : 1;
        unsigned int det_any_failed : 1;
    } reg;
} SOC_DDR_PACK_UC_DTRSTS_UNION;
#endif
#define SOC_DDR_PACK_UC_DTRSTS_dtrain_active_START (0)
#define SOC_DDR_PACK_UC_DTRSTS_dtrain_active_END (0)
#define SOC_DDR_PACK_UC_DTRSTS_dm_cmpres_even_START (1)
#define SOC_DDR_PACK_UC_DTRSTS_dm_cmpres_even_END (1)
#define SOC_DDR_PACK_UC_DTRSTS_dm_cmpres_odd_START (2)
#define SOC_DDR_PACK_UC_DTRSTS_dm_cmpres_odd_END (2)
#define SOC_DDR_PACK_UC_DTRSTS_dm_cmpres_START (3)
#define SOC_DDR_PACK_UC_DTRSTS_dm_cmpres_END (3)
#define SOC_DDR_PACK_UC_DTRSTS_dq_cmpres_even_START (4)
#define SOC_DDR_PACK_UC_DTRSTS_dq_cmpres_even_END (11)
#define SOC_DDR_PACK_UC_DTRSTS_dq_cmpres_odd_START (12)
#define SOC_DDR_PACK_UC_DTRSTS_dq_cmpres_odd_END (19)
#define SOC_DDR_PACK_UC_DTRSTS_cmpres_START (20)
#define SOC_DDR_PACK_UC_DTRSTS_cmpres_END (27)
#define SOC_DDR_PACK_UC_DTRSTS_det_all_passed_START (28)
#define SOC_DDR_PACK_UC_DTRSTS_det_all_passed_END (28)
#define SOC_DDR_PACK_UC_DTRSTS_det_any_passed_START (29)
#define SOC_DDR_PACK_UC_DTRSTS_det_any_passed_END (29)
#define SOC_DDR_PACK_UC_DTRSTS_det_all_failed_START (30)
#define SOC_DDR_PACK_UC_DTRSTS_det_all_failed_END (30)
#define SOC_DDR_PACK_UC_DTRSTS_det_any_failed_START (31)
#define SOC_DDR_PACK_UC_DTRSTS_det_any_failed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq_carry : 8;
        unsigned int wdbi_carry : 1;
        unsigned int wecc_carry : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PACK_UC_WDQNAUC2_UNION;
#endif
#define SOC_DDR_PACK_UC_WDQNAUC2_wdq_carry_START (0)
#define SOC_DDR_PACK_UC_WDQNAUC2_wdq_carry_END (7)
#define SOC_DDR_PACK_UC_WDQNAUC2_wdbi_carry_START (8)
#define SOC_DDR_PACK_UC_WDQNAUC2_wdbi_carry_END (8)
#define SOC_DDR_PACK_UC_WDQNAUC2_wecc_carry_START (9)
#define SOC_DDR_PACK_UC_WDQNAUC2_wecc_carry_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdq_carry : 8;
        unsigned int rdbi_carry : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_PACK_UC_RDQNAUC2_UNION;
#endif
#define SOC_DDR_PACK_UC_RDQNAUC2_rdq_carry_START (0)
#define SOC_DDR_PACK_UC_RDQNAUC2_rdq_carry_END (7)
#define SOC_DDR_PACK_UC_RDQNAUC2_rdbi_carry_START (8)
#define SOC_DDR_PACK_UC_RDQNAUC2_rdbi_carry_END (8)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
